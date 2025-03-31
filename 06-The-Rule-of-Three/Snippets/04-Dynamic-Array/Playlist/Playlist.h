#pragma once

#include <cstddef>

#include "../Song/Song.h"

class Playlist {
public:
    Playlist(std::size_t intialCapacity = 4);
    Playlist(const Playlist& other);
    Playlist& operator=(const Playlist& other);
    ~Playlist();

    std::size_t numberOfSongs() const;
    std::uint64_t getPlaylistLength() const;

    void addSong(const Song& song);
    void removeSong(std::size_t index);
    void removeSong(const char* songName);

    void printPlaylist() const;

private:
    Song* m_songs{ nullptr };
    std::size_t m_size{ 0 };
    std::size_t m_capacity{ 0 };
    
    void copyData(const Playlist& other);
    void resize(std::size_t newCapacity);
    void deleteData();
};
