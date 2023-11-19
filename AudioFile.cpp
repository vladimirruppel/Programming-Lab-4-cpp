#include "AudioFile.h"

int AudioFile::totalAudioFiles = 0;

AudioFile::AudioFile(const std::string& fileName, const std::string& artistName, const std::string& trackName, int duration, int releaseYear) {
    this->fileName = fileName;
    this->artistName = artistName;
    this->trackName = trackName;
    this->duration = duration;
    this->releaseYear = releaseYear;
    
    totalAudioFiles++;
}

void AudioFile::output(bool isLong) const
{
    if (isLong) { // ������� ������
        std::cout << "�������� �����: " << trackName << std::endl;
        std::cout << "�����������: " << artistName << std::endl;
        std::cout << "��� �����: " << fileName << std::endl;
        std::cout << "������������ (� �): " << duration << std::endl;
        std::cout << "��� ������: " << releaseYear << std::endl;
    }
    else { // �������� ������
        std::cout << artistName << " - " << trackName << ", "
            << duration << "s" << ", " << releaseYear << " - " << fileName << std::endl;
    }
}

void AudioFile::shortOutput()
{
    output(false);
}

void AudioFile::setTrackName(const std::string trackName)
{
    this->trackName = trackName;
}

int AudioFile::getTotalAudioFiles()
{
    return totalAudioFiles;
}

std::string AudioFile::getArtistName()
{
    return artistName;
}

std::string AudioFile::getTrackName()
{
    return trackName;
}

int AudioFile::getDuration()
{
    return duration;
}

int AudioFile::getReleaseYear()
{
    return releaseYear;
}

void printAudioFileInfo(const AudioFile& audioFile)
{
    std::cout << "File Name: " << audioFile.fileName << "\n";
    std::cout << "Artist Name: " << audioFile.artistName << "\n";
    std::cout << "Track Name: " << audioFile.trackName << "\n";
    std::cout << "Duration: " << audioFile.duration << " s\n";
    std::cout << "Release Year: " << audioFile.releaseYear << "\n";
}
