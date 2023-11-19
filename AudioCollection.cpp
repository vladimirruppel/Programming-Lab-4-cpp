#include "AudioCollection.h"

AudioCollection::AudioCollection(std::vector<AudioFile> list)
{
    this->list = list;
}

void AudioCollection::add(const AudioFile& elem)
{
    list.push_back(elem);
}

void AudioCollection::remove(int index)
{
    if (index >= 0 && index < list.size()) {
        list.erase(list.begin() + index);
    }
}

std::vector<AudioFile> AudioCollection::searchByArtistName(const std::string& artistName)
{
    std::vector<AudioFile> result = std::vector<AudioFile>();

    int listSize = list.size();
    for (int i = 0; i < listSize; i++) {
        AudioFile& currTrack = list[i];
        if (currTrack.getArtistName() == artistName)
            result.push_back(currTrack);
    }

    return result;
}

std::vector<AudioFile> AudioCollection::searchByReleaseYear(int releaseYear)
{
    std::vector<AudioFile> result = std::vector<AudioFile>();

    int listSize = list.size();
    for (int i = 0; i < listSize; i++) {
        AudioFile& currTrack = list[i];
        if (currTrack.getReleaseYear() == releaseYear)
            result.push_back(currTrack);
    }

    return result;
}

void AudioCollection::printSearchResults(const std::vector<AudioFile>& results)
{
    int resultsCount = results.size();

    if (resultsCount == 0) {
        std::cout << "Ничего не найдено" << std::endl;
        return;
    }

    std::cout << "Результаты поиска" << std::endl;
    for (int i = 0; i < resultsCount; i++) {
        const AudioFile& currAudioFile = results[i];
        std::cout << (i + 1) << ". ";
        currAudioFile.output(false);
    }
}

void AudioCollection::searchAndPrintByArtistName(const std::string& artistName)
{
    std::vector<AudioFile> results = searchByArtistName(artistName);
    printSearchResults(results);
}

void AudioCollection::searchAndPrintByReleaseYear(int releaseYear)
{
    std::vector<AudioFile> results = searchByReleaseYear(releaseYear);
    printSearchResults(results);
}

void AudioCollection::printStats()
{
    int tracksCount = list.size(); // количество треков
    int fullDuration = 0; // длительность всех треков в коллекции
    for (int i = 0; i < tracksCount; i++) {
        AudioFile& file = list[i];
        fullDuration += file.getDuration();
    }
    double averageDuration = (double)fullDuration / tracksCount; // средняя длительность

    std::cout << "Количество треков: " << tracksCount << std::endl;
    std::cout << "Полная длительность треков: " << fullDuration << std::endl;
    std::cout << "Средняя длительность трека: " << averageDuration << std::endl;
}