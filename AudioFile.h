#pragma once
#include <iostream>
#include "AuditionsNumber.h"

class AudioFile;
void printAudioFileInfo(const AudioFile& audioFile);

class AudioFile {
private:
    std::string fileName;
    std::string artistName;
    std::string trackName;
    int duration;
    int releaseYear;

    AuditionsNumber auditionsNumber;

    static int totalAudioFiles;
public:
    AudioFile(
        const std::string& fileName = "имя_файла.mp3",
        const std::string& artistName = "Имя Артиста",
        const std::string& trackName = "Название трека",
        int duration = 0,
        int releaseYear = 1999
    );
    
    friend void printAudioFileInfo(const AudioFile& audioFile);

    void output(bool isLong = true) const;
    void shortOutput();
    static int getTotalAudioFiles();

    void setTrackName(const std::string trackName);

    std::string getArtistName();
    std::string getTrackName();
    int getDuration();
    int getReleaseYear();
};