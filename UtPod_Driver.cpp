/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Snow Halation", "Muse", 60);	//Add 1 song and show list
    int result = t.addSong(s1);
    cout << "add result = " << result << endl; //in c: printf("result = %d\n",result);
    
    t.showSongList();
          
    Song s2("Girls Like You", "Maroon 5", 55);	//Add another song and show list
    result = t.addSong(s2);
    cout << "add result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Congratulations", "Post Malone", 23);	//Add 3 more songs and sort and then show list
    result = t.addSong(s3);
    cout << "add result = " << result << endl;
       
    Song s4("Wonder Zone", "Muse", 60);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;
       
    Song s5("Better Now", "Post Malone", 32);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
	
	t.sortSongList();
    
    t.showSongList();
    
    result = t.removeSong(s2);		//Remove 2 songs and show
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);	//Remove 2 more songs
    cout << "delete result = " << result << endl; 
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
	
	Song s6("This is a Huge Song", "Me", 511);	//Should not be able to add this song
	result = t.addSong(s6);
	cout << "add result = " << result << endl;
    
    t.showSongList();	//Should show 1 song(s5)
    
    result = t.addSong(s5);	//Add another s5 and show it along with remaining memory
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
	
	t.clearMemory();	//Clear the List and show no memory
	cout << "memory = " << t.getRemainingMemory() << endl;
	
	result = t.addSong(s1);	//Add 1 song
	cout << "result = " << result << endl;
	
	result = t.removeSong(s1);
	cout << "delete result = " << result << endl;		//Removing only thing in list
	
	t.showSongList();	//Should be empty
	
	result = t.removeSong(s2);	//Removing something NOT in the list
	cout << "delete result = " << result << endl;
	
	result = t.addSong(s5);							//Lets add 3 songs
    cout << "add result = " << result << endl;
	
	result = t.addSong(s4);
    cout << "add result = " << result << endl;
	
	result = t.addSong(s2);
    cout << "add result = " << result << endl;
	
	result = t.removeSong(s5);	//Remove first added song
	cout << "delete result = " << result << endl
	
    t.showSongList();	//Shows 2 songs and then its remaining memory
    cout << "memory = " << t.getRemainingMemory() << endl;
	
	result = t.addSong(s4);	//Add s4 two more times
    cout << "add result = " << result << endl;
	
	result = t.addSong(s4);
    cout << "add result = " << result << endl;
	
	t.showSongList();	//Should have s4 3 times
	
	t.sortSongList();	//Sort with 3 s4s in the list
	
	t.clearMemory();
}