#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#define NOMINMAX
#include <Windows.h>
#include "AuditionsNumber.h"
#include "AudioFile.h"
#include "Playlist.h"
#include "AudioPlayer.h"
#include "AudioCollection.h"
#include "MusicLibrary.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MusicLibrary lib; // библиотека треков
    AudioPlayer player; // аудиоплеер

    AudioFile* af1 = new AudioFile("file1.mp3", "Kanye West", "Ni**as in Paris", 203, 2011);
    printf("Всего треков: %d\n", AudioFile::getTotalAudioFiles());
    puts("");

    printAudioFileInfo(*af1);
    puts("");

    Playlist pl1("new playlist");
    AudioFile af2("file2.mp3", "ALBLAK 52", "Thank's God", 121, 2023);
    pl1 = pl1 + af2;
    pl1.output(false);
    puts("");

    AuditionsNumber an{};
    std::cout << "Количество прослушиваний: " << an.getCount() << std::endl;
    an++;
    std::cout << "Количество прослушиваний: " << an.getCount() << std::endl;

    // меню
    int quit = 0;

    while (!quit) {
        std::cout << "Список команд" << std::endl;
        std::cout << "1. Создать аудиофайл" << std::endl;
        std::cout << "2. Создать плейлист" << std::endl;
        std::cout << "3. Вывести список созданных треков" << std::endl;
        std::cout << "4. Вывести список созданных плейлистов" << std::endl;
        std::cout << "5. Поиск треков по имени исполнителя" << std::endl;
        std::cout << "6. Поиск треков по году выхода" << std::endl;
        std::cout << "7. Редактировать плейлист" << std::endl;
        std::cout << "8. Аудиоплеер" << std::endl;
        std::cout << "0. Выход" << std::endl;

        int command;
        do {
            std::cout << "Введите команду: ";
            std::cin >> command;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
        } while (command < 0 || command > 8);

        switch (command) {
        case 0:
            std::cout << "Выход..." << std::endl;
            quit = 1;
            break;
        case 1:
            std::cout << "Создать аудиофайл" << std::endl;
            lib.createAudioFile();
            break;
        case 2:
            std::cout << "Создать плейлист" << std::endl;
            lib.createPlaylist();
            break;
        case 3:
            std::cout << "Вывести список созданных треков" << std::endl;
            lib.printAudioFileArray();
            break;
        case 4:
            std::cout << "Вывести список созданных плейлистов" << std::endl;
            lib.printPlaylistArray();
            break;
        case 5: {
            std::cout << "Поиск треков по имени исполнителя" << std::endl;

            std::string artistName;
            std::cout << "Введите имя исполнителя: ";
            std::getline(std::cin, artistName);

            AudioCollection collection(lib.getAudioFileArray());
            collection.searchAndPrintByArtistName(artistName);
        } break;
        case 6: {
            std::cout << "Поиск треков по году выхода" << std::endl;

            int releaseYear;
            std::cout << "Введите год выхода: ";
            std::cin >> releaseYear;

            AudioCollection collection(lib.getAudioFileArray());
            collection.searchAndPrintByReleaseYear(releaseYear);
        } break;
        case 7: {
            std::cout << "Редактировать плейлист" << std::endl;

            if (lib.getPlaylistArraySize() == 0) {
                std::cout << "Редактирование плейлиста невозможно: нет плейлистов в библиотеке" << std::endl;
                break;
            }

            lib.printPlaylistArray();

            int playlistNumber;
            do {
                std::cout << "Введите номер плейлиста: ";
                std::cin >> playlistNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
            } while (playlistNumber < 1 || playlistNumber > lib.getPlaylistArraySize());

            Playlist& chosenPlaylist = lib.getPlaylistByIndex(playlistNumber - 1);

            int answer;
            do {
                do {
                    std::cout << "Меню работы с плейлистом" << std::endl;
                    std::cout << "1. Изменение названия плейлиста" << std::endl;
                    std::cout << "2. Добавление трека в плейлист" << std::endl;
                    std::cout << "3. Удаление трека из плейлиста" << std::endl;
                    std::cout << "4. Вывод списка треков плейлиста" << std::endl;
                    std::cout << "0. Завершить редактирование плейлиста" << std::endl;

                    std::cout << "Введите команду: ";
                    std::cin >> answer;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
                } while (answer < 0 || answer > 4);

                switch (answer) {
                case 0:
                    std::cout << "Завершение работы по редактированию плейлиста" << std::endl;
                    break;
                case 1: {
                    std::cout << "Изменение названия плейлиста" << std::endl;

                    std::string newPlaylistName;
                    std::cout << "Введите новое название плейлиста: ";
                    std::getline(std::cin, newPlaylistName);

                    chosenPlaylist.setPlaylistName(newPlaylistName);
                    std::cout << "Название плейлиста изменено на \"" << newPlaylistName << "\"" << std::endl;
                } break;
                case 2: {
                    std::cout << "Добавление трека в плейлист" << std::endl;

                    AudioFile& createdAudioFile = lib.createAudioFile();
                    chosenPlaylist.add(createdAudioFile);

                    std::cout << "Трек добавлен в плейлист" << std::endl;
                } break;
                case 3: {
                    std::cout << "Удаление трека из плейлиста" << std::endl;

                    chosenPlaylist.output(false);

                    int chosenTrackNumber;
                    do {
                        std::cout << "Введите номер трека для удаления: ";
                        std::cin >> chosenTrackNumber;
                    } while (chosenTrackNumber < 1 || chosenTrackNumber > chosenPlaylist.getListSize());

                    chosenPlaylist.remove(chosenTrackNumber - 1);
                    std::cout << "Выбранный трек удален из плейлиста" << std::endl;
                } break;
                case 4:
                    std::cout << "Вывод списка треков плейлиста" << std::endl;

                    chosenPlaylist.output(false);
                    break;
                }
            } while (answer != 0);

        } break;
        case 8: {
            int answer;
            do {
                do {
                    bool isPlaying = player.getIsPlayingStatus();
                    bool isPlaylistAssigned = player.getIsPlaylistAssignedStatus();

                    std::cout << "Аудиоплеер" << std::endl;
                    if (isPlaylistAssigned) {
                        if (isPlaying)
                            std::cout << "Статус: играет" << std::endl;
                        else
                            std::cout << "Статус: не играет" << std::endl;
                        std::cout << "Текущий трек: " << player.getCurrentTrack().getTrackName() << ". ";
                        std::cout << "Исполнитель: " << player.getCurrentTrack().getArtistName() << std::endl;
                    }
                    else
                        std::cout << "Статус: плейлист не определен" << std::endl;

                    std::cout << "Меню управления аудиоплеером" << std::endl;
                    std::cout << "1. Назначить плейлист" << std::endl;
                    std::cout << "2. Play/Pause" << std::endl;
                    std::cout << "3. Следующий трек" << std::endl;
                    std::cout << "4. Предыдущий трек" << std::endl;
                    std::cout << "0. Выход в главное меню" << std::endl;

                    std::cout << "Введите команду: ";
                    std::cin >> answer;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
                } while (answer < 0 || answer > 4);

                switch (answer) {
                case 0:
                    std::cout << "Возвращение к меню..." << std::endl;
                    break;
                case 1: {
                    std::cout << "Назначить плейлист" << std::endl;

                    if (lib.getPlaylistArraySize() == 0) {
                        std::cout << "Ошибка: нет плейлистов в библиотеке" << std::endl;
                        break;
                    }

                    lib.printPlaylistArray();

                    int playlistNumber;
                    do {
                        std::cout << "Введите номер плейлиста: ";
                        std::cin >> playlistNumber;
                    } while (playlistNumber < 1 || playlistNumber > lib.getPlaylistArraySize());

                    Playlist& chosenPlaylist = lib.getPlaylistByIndex(playlistNumber - 1);
                    player.setPlaylist(&chosenPlaylist);
                    std::cout << "Выбранный плейлист назначен" << std::endl;
                } break;
                case 2: {
                    std::cout << "Изменить статус проигрывания" << std::endl;

                    player.toggle();
                    std::cout << "Статус изменен" << std::endl;
                } break;
                case 3: {
                    std::cout << "Следующий трек" << std::endl;

                    player.next();
                    std::cout << "Трек в плеере изменен" << std::endl;
                } break;
                case 4: {
                    std::cout << "Предыдущий трек" << std::endl;

                    player.previous();
                    std::cout << "Трек в плеере изменен" << std::endl;
                } break;
                }
            } while (answer != 0);
        } break;
        }
    }
}