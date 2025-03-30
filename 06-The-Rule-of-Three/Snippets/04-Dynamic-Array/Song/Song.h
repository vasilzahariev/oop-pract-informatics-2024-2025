#pragma once

#include <cstdint>

class Song {
public:
    Song();
    Song(const char* name, const char* artist, const char* album, std::uint16_t durationInSeconds);
    Song(const Song& other);
    Song& operator=(const Song& other);
    ~Song();

    void setName(const char* name);
    const char* getName() const;

    void setArtist(const char* artist);
    const char* getArtist() const;

    void setAlbum(const char* album);
    const char* getAlbum() const;

    void setDurationInSeconds(std::uint16_t durationInSeconds);
    std::uint16_t getDurationInSeconds() const;

    void print() const;

private:
    char* m_name{ nullptr };
    char* m_artist{ nullptr };
    char* m_album{ nullptr };
    std::uint16_t m_durationInSeconds{ 0 }; // in seconds

private:
    void copyData(const Song& other);
    void deleteData();
};
