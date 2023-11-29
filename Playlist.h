#pragma once
#include <iostream>
#include <vector>
#include "AudioFile.h"

class Playlist {
private:
    std::string playlistName;
    std::vector<AudioFile> list;
public:
    Playlist(const std::string& playlistName);
    Playlist(const std::string& playlistName, std::vector<AudioFile> list);

    void output(bool isLong = true);
    void add(const AudioFile& elem);
    void remove(int index);

    std::string& getPlaylistName();
    int getListSize();
    AudioFile& getElement(int index);

    void setPlaylistName(const std::string& newPlaylistName);

    Playlist operator+(const AudioFile& audio) const; // добавление трека в плейлист с помощью "+"
};