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
    
    Song s1("Aeatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl; //in c: printf("result = %d\n",result);
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Ceatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Deatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Eeatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
	
	t.sortSongList();
    
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
	
	t.clearMemory();
	cout << "memory = " << t.getRemainingMemory() << endl;
	
	
    

}