#include "MusicLibrary.h"
#include <string>

MusicLibrary::MusicLibrary(std::vector<AudioFile> audioFileArray, std::vector<Playlist> playlistArray)
{
    this->audioFileArray = audioFileArray;
    this->playlistArray = playlistArray;
}

AudioFile& MusicLibrary::createAudioFile()
{
    std::cout << "�������� �������� �����" << std::endl;

    std::string fileName, artistName, trackName;
    int duration, releaseYear;

    std::cout << "������� ������������ �����: ";
    std::getline(std::cin, fileName);
    std::cout << "������� ��� �������: ";
    std::getline(std::cin, artistName);
    std::cout << "������� �������� �����: ";
    std::getline(std::cin, trackName);
    std::cout << "������� ������������ ����� (� �): ";
    std::cin >> duration;
    std::cout << "������� ��� ������ �����: ";
    std::cin >> releaseYear;

    AudioFile* audioFile = new AudioFile(fileName, artistName, trackName, duration, releaseYear);
    std::cout << "���� ������" << std::endl;

    audioFileArray.push_back(*audioFile);
    return *audioFile;
}

Playlist& MusicLibrary::createPlaylist()
{
    std::cout << "�������� ���������" << std::endl;

    std::string playlistName;
    std::vector<AudioFile> list;

    std::cout << "������� �������� ���������: ";
    std::getline(std::cin, playlistName);

    bool quit = 0;
    do {
        std::cout << "���������� ����� � ��������" << std::endl;
        std::cout << "1. �������� ���� �� ����������" << std::endl;
        std::cout << "2. ������� �������� ����� � �������� ��� � ��������" << std::endl;
        std::cout << "0. ��������� ���������� ������ (����������, ���� �� ��� �������� ���� �� 1 ���� � ��������)" << std::endl;

        int answer;
        do {
            std::cout << "����� (0-2): ";
            std::cin >> answer;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
        } while (answer < 0 || answer > 2);

        switch (answer) {
        case 0: // ����������
            std::cout << "������� ��������..." << std::endl;
            quit = true;
            break;
        case 1: { // ���������� ����� �� ����������
            std::cout << "���������� ����� �� ����������" << std::endl;

            int audioFileArraySize = audioFileArray.size();
            if (audioFileArraySize == 0)
                std::cout << "���������� �������� ���� �� ����������: ������ ������ ����" << std::endl;
            else {
                printAudioFileArray();

                do {
                    std::cout << "��������� ����: ";
                    std::cin >> answer;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
                } while (answer < 1 || answer > audioFileArraySize);

                AudioFile& chosenTrack = audioFileArray[answer - 1];
                list.push_back(chosenTrack);
                std::cout << "��������� ���� ��������" << std::endl;
            }
        } break;
        case 2: // �������� �����
            AudioFile & createdAudioFile = createAudioFile();
            list.push_back(createdAudioFile);
            std::cout << "��������� ���� �������� � ��������" << std::endl;
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
        std::cout << "������ ������ ����" << std::endl;
    else {
        std::cout << "������ ������: " << std::endl;

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
        std::cout << "������ ���������� ����" << std::endl;
    else {
        std::cout << "������ ����������: " << std::endl;

        for (int i = 0; i < arraySize; i++) {
            Playlist& currPlaylist = playlistArray[i];
            std::cout << (i + 1) << ". " << currPlaylist.getPlaylistName()
                << " - " << currPlaylist.getListSize() << " ������" << std::endl;
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