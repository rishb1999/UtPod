//SONG.h

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

	string getName();

	void setName(string const newName);

	string getArtist();

	void setArtist(string const newArtist);

	int getMemSize();

	void setMemSize(int const newSize);
	
	bool operator >(Song const &rhs);
 
	bool operator ==(Song const &rhs);

      ~Song();
 
};




