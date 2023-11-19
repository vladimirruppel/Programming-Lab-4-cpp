#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
    : currPlaylist(currPlaylist), trackIndexInPlaylist(trackIndexInPlaylist)
{
    isPlaylistAssigned = false;
}

AudioPlayer::AudioPlayer(Playlist* currPlaylist, int trackIndexInPlaylist)
    : currPlaylist(currPlaylist), trackIndexInPlaylist(trackIndexInPlaylist)
{
    this->currPlaylist = currPlaylist;
    this->isPlaylistAssigned = true;
    this->trackIndexInPlaylist = trackIndexInPlaylist;
}

void AudioPlayer::play()
{
    isPlaying = true;
}

void AudioPlayer::pause()
{
    isPlaying = false;
}

bool AudioPlayer::toggle()
{
    isPlaying = !isPlaying;
    return isPlaying;
}

AudioFile& AudioPlayer::next()
{
    if (trackIndexInPlaylist + 1 < currPlaylist->getListSize())
        trackIndexInPlaylist++;
    return getCurrentTrack();
}

AudioFile& AudioPlayer::previous()
{
    if (trackIndexInPlaylist > 0)
        trackIndexInPlaylist--;
    return getCurrentTrack();
}

void AudioPlayer::setPlaylist(Playlist* newPlaylist)
{
    currPlaylist = newPlaylist;
    isPlaylistAssigned = true;
}

AudioFile& AudioPlayer::getCurrentTrack()
{
    return currPlaylist->getElement(trackIndexInPlaylist);
}

bool AudioPlayer::getIsPlaylistAssignedStatus()
{
    return isPlaylistAssigned;
}

bool AudioPlayer::getIsPlayingStatus()
{
    return isPlaying;
}