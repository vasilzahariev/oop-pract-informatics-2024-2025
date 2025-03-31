#include <iostream>

#include "Song/Song.h"
#include "Playlist/Playlist.h"

int main() {
    Playlist playlist{};

    playlist.addSong(Song{"Off the Grid", "Kanye West", "Donda", 339});
    playlist.addSong(Song{"family ties", "Baby Keem feat. Kendrick Lamar", "Melodic Blues", 252});
    playlist.addSong(Song{"THANK GOD", "Travis Scott", "UTOPIA", 185});

    std::cout << "Total duration: " << playlist.getPlaylistLength() << " seconds" << std::endl;
    playlist.printPlaylist();

    playlist.removeSong("family ties");
    std::cout << "Total duration after removing a song: " << playlist.getPlaylistLength() << " seconds" << std::endl;
    playlist.printPlaylist();

    return 0;
}
