#include "Song.h"

#include <iostream>
#include <cassert>
#include <cstring>

Song::Song() {}

Song::Song(const char* name, const char* artist, const char* album, std::uint16_t durationInSeconds)
    : m_durationInSeconds{ durationInSeconds } {
    this->setName(name);
    this->setArtist(artist);
    this->setAlbum(album);
}

Song::Song(const Song& other) {
    this->copyData(other);
}

Song& Song::operator=(const Song& other) {
    if (this != &other) {
        this->deleteData();
        this->copyData(other);
    }
    return *this;
}

Song::~Song() {
    this->deleteData();
}

void Song::setName(const char* name) {
    if (name == nullptr) {
        return;
    }

    delete[] this->m_name;

    this->m_name = new (std::nothrow) char[strlen(name) + 1];

    assert(this->m_name != nullptr && "Memory allocation failed for song name!");

    strcpy(this->m_name, name);
}

const char* Song::getName() const {
    return this->m_name;
}

void Song::setArtist(const char* artist) {
    if (artist == nullptr) {
        return;
    }

    delete[] this->m_artist;

    this->m_artist = new (std::nothrow) char[strlen(artist) + 1];

    assert(this->m_artist != nullptr && "Memory allocation failed for song artist!");

    strcpy(this->m_artist, artist);
}

const char* Song::getArtist() const {
    return this->m_artist;
}

void Song::setAlbum(const char* album) {
    if (album == nullptr) {
        return;
    }

    delete[] this->m_album;

    this->m_album = new (std::nothrow) char[strlen(album) + 1];

    assert(this->m_album != nullptr && "Memory allocation failed for song album!");

    strcpy(this->m_album, album);
}

const char* Song::getAlbum() const {
    return this->m_album;
}

void Song::setDurationInSeconds(std::uint16_t durationInSeconds) {
    this->m_durationInSeconds = durationInSeconds;
}

std::uint16_t Song::getDurationInSeconds() const {
    return this->m_durationInSeconds;
}

void Song::print() const {
    std::cout << "Song Name: " << this->m_name << std::endl
              << "Artist: " << this->m_artist << std::endl
              << "Album: " << this->m_album << std::endl
              << "Duration: " << this->m_durationInSeconds << " seconds" << std::endl;
}

void Song::copyData(const Song& other) {
    this->setName(other.m_name);
    this->setArtist(other.m_artist);
    this->setAlbum(other.m_album);
    this->setDurationInSeconds(other.m_durationInSeconds);
}

void Song::deleteData() {
    delete[] this->m_name;
    this->m_name = nullptr;

    delete[] this->m_artist;
    this->m_artist = nullptr;

    delete[] this->m_album;
    this->m_album = nullptr;

    this->m_durationInSeconds = 0;
}
