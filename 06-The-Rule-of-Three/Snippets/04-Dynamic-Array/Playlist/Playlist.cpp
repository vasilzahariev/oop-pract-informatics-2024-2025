#include "Playlist.h"

#include <iostream>
#include <cassert>
#include <cstring>

Playlist::Playlist(std::size_t initialCapacity) {
    this->resize(initialCapacity);
}

Playlist::Playlist(const Playlist& other) {
    this->copyData(other);
}

Playlist& Playlist::operator=(const Playlist& other) {
    if (this != &other) {
        this->deleteData();
        this->copyData(other);
    }

    return *this;
}

Playlist::~Playlist() {
    this->deleteData();
}

std::size_t Playlist::numberOfSongs() const {
    return this->m_size;
}

std::uint64_t Playlist::getPlaylistLength() const {
    std::uint64_t totalLength{ 0 };

    for (std::size_t songIndex{ 0 }; songIndex < this->m_size; ++songIndex) {
        totalLength += this->m_songs[songIndex].getDurationInSeconds();
    }

    return totalLength;
}

void Playlist::addSong(const Song& song) {
    if (this->m_size == this->m_capacity) {
        this->resize(this->m_capacity * 2);
    }

    this->m_songs[this->m_size++] = song;
}

void Playlist::removeSong(std::size_t indexToRemove) {
    if (indexToRemove >= this->m_size) {
        std::cout << "Index out of bounds!" << std::endl;

        return;
    }

    for (std::size_t songIndex{ indexToRemove }; songIndex < this->m_size - 1; ++songIndex) {
        this->m_songs[songIndex] = this->m_songs[songIndex + 1];
    }

    --this->m_size;
}

void Playlist::removeSong(const char* songName) {
    for (std::size_t songIndex{ 0 }; songIndex < this->m_size; ++songIndex) {
        if (strcmp(this->m_songs[songIndex].getName(), songName) == 0) {
            this->removeSong(songIndex);

            return;
        }
    }

    std::cout << "Song not found!" << std::endl;
}

// Важно: Ако реда на елементите в масива не ни интересува, можем да заменим
// последния елемент с изтривания. По този начин не е нужно да преместваме
// елементите в масива. Примерен код:
/*

void Playlist::removeSong(const char* songName) {
    for (std::size_t i{ 0 }; i < this->m_size; ++i) {
        if (this->m_songs[i].getName() == songName) {
            this->m_songs[i] = this->m_songs[this->m_size - 1];

            --this->m_size;

            return;
        }
    }

    std::cout << "Song not found!" << std::endl;
}

*/

void Playlist::printPlaylist() const {
    for (std::size_t songIndex{ 0 }; songIndex < this->m_size; ++songIndex) {
        std::cout << "Song #" << songIndex + 1 << ":" << std::endl;

        this->m_songs[songIndex].print();

        std::cout << "------------------------" << std::endl;
    }
}

void Playlist::copyData(const Playlist& other) {
    if (this->m_songs) {
        this->deleteData();
    }

    this->m_songs = new (std::nothrow) Song[other.m_capacity];

    assert(this->m_songs != nullptr && "Memory allocation failed for playlist!");

    for (std::size_t songIndex{ 0 }; songIndex < other.m_size; ++songIndex) {
        this->m_songs[songIndex] = other.m_songs[songIndex];
    }

    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
}

void Playlist::resize(std::size_t newCapacity) {
    if (newCapacity <= this->m_size) {
        newCapacity = this->m_size + 1;
    }

    Song* blockOfMemmory{ new (std::nothrow) Song[newCapacity] };

    assert(blockOfMemmory != nullptr && "Memory allocation failed for playlist!");

    for (std::size_t songIndex{ 0 }; songIndex < this->m_size; ++songIndex) {
        blockOfMemmory[songIndex] = this->m_songs[songIndex];
    }

    delete[] this->m_songs;
    this->m_songs = blockOfMemmory;
    this->m_capacity = newCapacity;
}

void Playlist::deleteData() {
    delete[] this->m_songs;
    this->m_songs = nullptr;

    this->m_size = 0;
    this->m_capacity = 0;
}
