#pragma once
#include <iostream>
#include "Playlist.h"

class AudioPlayer {
private:
    bool isPlaylistAssigned = false;
    bool isPlaying = false;
    Playlist* currPlaylist;
    int trackIndexInPlaylist;
public:
    AudioPlayer();
    AudioPlayer(Playlist* currPlaylist, int trackIndexInPlaylist = 0);

    void play();
    void pause();
    bool toggle();
    AudioFile& next();
    AudioFile& previous();

    AudioFile& getCurrentTrack();
    bool getIsPlaylistAssignedStatus();
    bool getIsPlayingStatus();

    void setPlaylist(Playlist* newPlaylist);
};