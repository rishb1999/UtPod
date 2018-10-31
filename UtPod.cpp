//DOCUMENT HERE

#include <ctime>
#include <string>
#include <cstdlib>
#include "Song.h"

using namespace std;

	UtPod::UtPod() {
		memSize = MAX_MEMORY;
	}
	
	UtPod::UtPod(int size) {
		if ((size > MAX_MEMORY) || (size <= 0)) {
			memSize = MAX_MEMORY;
		} else {
			memSize = size;
		}
	}
	
	int UtPod::addSong(Song const &s) {
		if (memSize == MAX_MEMORY) {
			return NO_MEMORY;
		}
		memSize += s.getMemSize();
		SongNode *temp = new SongNode;
		temp->s = s;
		if (songs == NULL){
			songs = temp;
		} else {
			temp->next = songs;
			songs = temp;
		}
		return SUCCESS;
		
		
	
			/*if(currentMem +s.getMemSize() > memSize) {
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
			return SUCCESS; */
	}//addSong
	
	int UtPod::removeSong (Song const &s) {
		if (memSize == 0) {
			return NO_MEMORY;
		}
		SongNode *del = new SongNode;
		del->s = s;
		if (del->s == songs->s) {	//If we removing head
			if (song->next == NULL) {	//If head is only thing in list
				songs = NULL;
				delete(del);
				memSize -=s.getMemSize();
				return SUCCESS;
			}else {
				songs = songs->next;
				delete(del);
				memSize -= s.getMemSize();
				return SUCCESS;
			}
		}
		SongNode *temp = new SongNode;
		temp = songs;
		while ((del->s != temp->next->s) && (temp != NULL)) {	//Finding removal song that is not head
			temp = temp->next;
		}
		if (temp == NULL) {	// Song not found in list
			return NOT_FOUND;
		}
		temp->next = temp->next->next;	
		del = temp->next;
		delete(del);
		memSize -= s.getMemSize();
		return SUCCESS;
	
		/*if(currentMem == 0) {
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
		
		return NOT_FOUND;*/
	}//removeSong
	
	void UtPod::shuffle() {
	if (song->next == NULL) {	//No need to shuffle 1 thing
		return;
	}
	
	}//shuffle
	
	void UtPod::showSongList() {
		SongNode *temp = new SongNode;
		temp = song;
		while (temp != NULL) {
			printf ("(temp->s).getName)\n", "%s");
			temp = temp->next;
		}
	}//showSongList
	
	void UtPod::sortSongList() {
	int songSize = 0;
	SongNode *temp = new SongNode;
	SongNode *holder = new SongNode;
	temp = song;
	while (temp != NULL) {
		songSize++;
		temp = temp->next;
	}
	for (int i=0; i < songSize; i++) {
		temp = song;
		while (temp->next != NULL) {
			if (temp->s >= temp->next->s) {
				holder = temp->next;
				temp->next = temp->next->next;
				holder->next = temp;
			}
			temp = temp->next;
		}
	}
	
	}//sortSongList
	
	void clearMemory() {
	SongNode *temp = new SongNode;
	SongNode *del = new SongNode;
	temp = song;
	while (temp != NULL) {
		del = temp;
		temp = temp->next;
		delete(del);
		memSize -= s.getMemSize();
	}
	
	}//clearMemory
	
	int getTotalMemory() {
		int totalMem = 0;
		SongNode *temp = new SongNode;
		temp = song;
		while (temp != NULL) {
			totalMem+=s.getMemSize();
			temp = temp->next;
		}
		return totalMem;
	}//getTotalMemory
	
	int getRemainingMemory() {
		int remainingMem = 512;
		SongNode *temp = new SongNode;
		temp = song;
		while (temp != NULL) {
			remainingMem -= s.getMemSize();
			temp -> temp->next;
		}
		return remainingMem;
	}//getRemainingMemory
	
	UtPod::~UtPod() {
		//Destructor
	}
	
	
	
	
	
	
	