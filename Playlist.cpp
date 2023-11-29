#include "Playlist.h"

Playlist::Playlist(const std::string& playlistName)
{
    this->playlistName = playlistName;
}

Playlist::Playlist(const std::string& playlistName, std::vector<AudioFile> list)
{
    this->playlistName = playlistName;
    this->list = list;
}

void Playlist::output(bool isLong)
{
    std::cout << "Плейлист \"" << playlistName << "\"" << std::endl;

    int listLength = list.size();
    for (int i = 0; i < listLength; i++) {
        std::cout << i + 1 << ". ";
        list[i].output(isLong);
    }
}

void Playlist::add(const AudioFile& elem)
{
    list.push_back(elem);
}

void Playlist::remove(const int index)
{
    if (index >= 0 && index < list.size()) {
        list.erase(list.begin() + index);
    }
}

std::string& Playlist::getPlaylistName()
{
    return playlistName;
}

int Playlist::getListSize()
{
    return list.size();
}

AudioFile& Playlist::getElement(int index)
{
    return list[index];
}

void Playlist::setPlaylistName(const std::string& newPlaylistName)
{
    playlistName = newPlaylistName;
}

// возвращается новый плейлист, где по сравнению со старым будет добавлен приплюсованный трек
Playlist Playlist::operator+(const AudioFile& track) const
{
    Playlist result = *this;
    result.add(track);
    return result;
}
