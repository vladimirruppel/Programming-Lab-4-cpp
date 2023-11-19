#pragma once
#include "Playlist.h"

class MusicLibrary {
private:
    std::vector<AudioFile> audioFileArray;
    std::vector<Playlist> playlistArray;
public:
    MusicLibrary(std::vector<AudioFile> audioFileArray = std::vector<AudioFile>(), std::vector<Playlist> playlistArray = std::vector<Playlist>());

    AudioFile& createAudioFile();
    Playlist& createPlaylist();

    int printAudioFileArray();
    int printPlaylistArray();

    std::vector<AudioFile> getAudioFileArray();
    int getPlaylistArraySize();
    Playlist& getPlaylistByIndex(int index);

    ~MusicLibrary();
};