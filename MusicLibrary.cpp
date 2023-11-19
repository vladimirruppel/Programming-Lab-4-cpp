#include "MusicLibrary.h"
#include <string>

MusicLibrary::MusicLibrary(std::vector<AudioFile> audioFileArray, std::vector<Playlist> playlistArray)
{
    this->audioFileArray = audioFileArray;
    this->playlistArray = playlistArray;
}

AudioFile& MusicLibrary::createAudioFile()
{
    std::cout << "Создание карточки трека" << std::endl;

    std::string fileName, artistName, trackName;
    int duration, releaseYear;

    std::cout << "Введите наименование файла: ";
    std::getline(std::cin, fileName);
    std::cout << "Введите имя артиста: ";
    std::getline(std::cin, artistName);
    std::cout << "Введите название трека: ";
    std::getline(std::cin, trackName);
    std::cout << "Введите длительность трека (в с): ";
    std::cin >> duration;
    std::cout << "Введите год выхода трека: ";
    std::cin >> releaseYear;

    AudioFile* audioFile = new AudioFile(fileName, artistName, trackName, duration, releaseYear);
    std::cout << "Трек создан" << std::endl;

    audioFileArray.push_back(*audioFile);
    return *audioFile;
}

Playlist& MusicLibrary::createPlaylist()
{
    std::cout << "Создание плейлиста" << std::endl;

    std::string playlistName;
    std::vector<AudioFile> list;

    std::cout << "Введите название плейлиста: ";
    std::getline(std::cin, playlistName);

    bool quit = 0;
    do {
        std::cout << "Добавление трека в плейлист" << std::endl;
        std::cout << "1. Добавить трек из библиотеки" << std::endl;
        std::cout << "2. Создать карточку трека и добавить его в плейлист" << std::endl;
        std::cout << "0. Завершить добавление треков (невозможно, если не был добавлен хотя бы 1 трек в плейлист)" << std::endl;

        int answer;
        do {
            std::cout << "Выбор (0-2): ";
            std::cin >> answer;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
        } while (answer < 0 || answer > 2);

        switch (answer) {
        case 0: // заврешение
            std::cout << "Создаем плейлист..." << std::endl;
            quit = true;
            break;
        case 1: { // добавление трека из библиотеки
            std::cout << "Добавление трека из библиотеки" << std::endl;

            int audioFileArraySize = audioFileArray.size();
            if (audioFileArraySize == 0)
                std::cout << "Невозможно добавить трек из библиотеки: список треков пуст" << std::endl;
            else {
                printAudioFileArray();

                do {
                    std::cout << "Выбранный трек: ";
                    std::cin >> answer;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера ввода
                } while (answer < 1 || answer > audioFileArraySize);

                AudioFile& chosenTrack = audioFileArray[answer - 1];
                list.push_back(chosenTrack);
                std::cout << "Выбранный трек добавлен" << std::endl;
            }
        } break;
        case 2: // создание трека
            AudioFile & createdAudioFile = createAudioFile();
            list.push_back(createdAudioFile);
            std::cout << "Созданный трек добавлен в плейлист" << std::endl;
            break;
        }
    } while (!quit);

    Playlist playlist(playlistName, list);
    playlistArray.push_back(playlist);
    return playlist;
}

int MusicLibrary::printAudioFileArray()
{
    int arraySize = audioFileArray.size();

    if (arraySize == 0)
        std::cout << "Список треков пуст" << std::endl;
    else {
        std::cout << "Список треков: " << std::endl;

        for (int i = 0; i < arraySize; i++) {
            AudioFile& currTrack = audioFileArray[i];
            std::cout << (i + 1) << ". "; currTrack.shortOutput();
        }
    }

    return arraySize;
}

int MusicLibrary::printPlaylistArray()
{
    int arraySize = playlistArray.size();

    if (arraySize == 0)
        std::cout << "Список плейлистов пуст" << std::endl;
    else {
        std::cout << "Список плейлистов: " << std::endl;

        for (int i = 0; i < arraySize; i++) {
            Playlist& currPlaylist = playlistArray[i];
            std::cout << (i + 1) << ". " << currPlaylist.getPlaylistName()
                << " - " << currPlaylist.getListSize() << " треков" << std::endl;
        }
    }

    return arraySize;
}

std::vector<AudioFile> MusicLibrary::getAudioFileArray()
{
    return audioFileArray;
}

int MusicLibrary::getPlaylistArraySize()
{
    return playlistArray.size();
}

Playlist& MusicLibrary::getPlaylistByIndex(int index)
{
    return playlistArray[index];
}

MusicLibrary::~MusicLibrary()
{
    for (int i = 0; i < audioFileArray.size(); i++) {
        delete& audioFileArray[i];
    }
}