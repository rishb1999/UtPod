//SONG.CPP
//RISH is here


#include "Song.h"

using namespace std;

   Song::Song() {
      name = "";
      artist = "";
	  memory = 0;
   }

   Song::Song(string const songName, string const songArtist, int const memSize) {
      name = songName;
      artist = songArtist;
      memory = memSize;
   }
   

   
	string Song::getName() const {
		return name;
	}

	void Song::setName(string const newName) {
		name = newName;
	}
	

	string Song::getArtist() const {
		return artist;
	}

	void Song::setArtist(string const newArtist) {
		artist = newArtist;
	}

	int Song::getMemSize() const {
		return memory;
	}

	void Song::setMemSize(int const newSize) {
		memory = newSize;
	}
    

   bool Song::operator >(Song const &rhs) {
      return (name > rhs.name);
   }
   
   bool Song::operator ==(Song const &rhs) {
      return (name == rhs.name &&
              artist == rhs.artist &&
              memory == rhs.memory);
   }

   
   Song::~Song() {
		//Destructor
   }
   
   
   
   