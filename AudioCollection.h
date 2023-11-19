#pragma once
#include <vector>
#include "AudioFile.h"

class AudioCollection {
private:
    std::vector<AudioFile> list;
public:
    AudioCollection(std::vector<AudioFile> list = std::vector<AudioFile>());

    void add(const AudioFile& elem);
    void remove(int index);

    std::vector<AudioFile> searchByArtistName(const std::string& artistName);
    std::vector<AudioFile> searchByReleaseYear(int releaseYear);

    void printSearchResults(const std::vector<AudioFile>& results);
    void searchAndPrintByArtistName(const std::string& artistName);
    void searchAndPrintByReleaseYear(int releaseYear);

    void printStats();
};