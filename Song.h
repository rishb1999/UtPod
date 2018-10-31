//SONG.h
#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;


class Song
{
   private:
      string name;
	  string artist;
	  int memory;
      
   public:
   
    Song();

	Song(string const songName, string const songArtist, int const memSize);

	string getName() const;

	void setName(string const newName);

	string getArtist() const;

	void setArtist(string const newArtist);

	int getMemSize() const;

	void setMemSize(int const newSize);
	
	bool operator >(Song const &rhs);
 
	bool operator ==(Song const &rhs);

      ~Song();
 
};

#endif


