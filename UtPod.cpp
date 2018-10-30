//DOCUMENT HERE

#include <ctime>
#include <string>
#include <cstdlib>
#include "Song.h"

using namespace std;

	UtPod::UtPod() {
		memSize = MAX_MEMORY;
		currentMem = 0;
		tail = songs;
	}
	
	UtPod::UtPod(int size) {
		if(size > MAX_MEMORY || size <=0) {
			memSize = MAX_MEMORY;
		} else {
			memSize = size;
		}
		tail = songs;
		currentMem = 0;
	}
	
	int UtPod::addSong(Song const &s) {
	
			if(currentMem +s.getMemSize() > memSize) {
				return NO_MEMORY;
			}
			currentMem+=s.getMemSize();
			SongNode *temp = new SongNode;
			temp->s = s;
			if(songs == NULL) {
				temp->prev = NULL;
				songs = temp;
				tail = temp;
			} else {
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
			}//else
			return SUCCESS;
	}//addSong
	
	int UtPod::removeSong (Song const &s) {
	
		if(currentMem == 0) {
			return NO_MEMORY;
		}
		if(songs == tail) { songs = NULL; tail = NULL; return SUCCESS; }
		SongNode *delHead = new SongNode;
		if(songs->s == s) {
			songs->next->prev = NULL;
			delHead = songs;
			songs = songs->next;
			delete(delHead);
			currentMem -= s.getMemSize();
			return SUCCESS;
		}
	
		SongNode *temp = new SongNode;
		temp = songs;
		
		while(temp != tail) {
			if(temp->s == s) {
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				delete(temp);
				currentMem-=s.getMemSize();
				return SUCCESS:
			} else{
				temp = temp->next;
			}
		}//while
		SongNode *delTail = new SongNode;
		if(tail->s == s) {
			tail->prev->next = NULL;
			delTail = tail;
			tail = tail->prev;
			delete(delTail);
			currentMem -= s.getMemSize();
			return SUCCESS;
		}
		
		return NOT_FOUND;
	}//removeSong
	
	void UtPod::shuffle() {
	
	
	}//shuffle
	
	void UtPod::showSongList() {
	
	
	}//showSongList
	
	void UtPod::sortSongList() {
	
	
	}//sortSongList
	
	void clearMemory() {
	
	
	}//clearMemory
	
	int getRemainingMemory() {
		return memSize - currentMem;
	}//getRemainingMemory
	
	UtPod::~UtPod() {
		//Destructor
	}
	
	
	
	
	
	
	