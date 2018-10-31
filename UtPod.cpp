//DOCUMENT HERE

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Song.h"
#include "UtPod.h"

using namespace std;

	UtPod::UtPod() {
		memSize = MAX_MEMORY;
		songs = NULL;
	}
	
	UtPod::UtPod(int size) {
		if ((size > MAX_MEMORY) || (size <= 0)) {
			memSize = MAX_MEMORY;
		} else {
			memSize = size;
		}
		songs = NULL;
	}
	
	int UtPod::addSong(Song const &s) {
		if (getRemainingMemory() == 0) {
			return NO_MEMORY;
		}
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
		if (songs->s == s) {	//If we removing head
			if (songs->next == NULL) {	//If head is only thing in list
				del = songs;
				songs = NULL;
				delete(del);
				return SUCCESS;
			}else {
				del = songs;
				songs = songs->next;
				delete(del);
				return SUCCESS;
			}
		}
		SongNode *temp = new SongNode;
		temp = songs;
		while ((!(temp->next->s == s)) && (temp != NULL)) {	//Finding removal song that is not head
			temp = temp->next;
		}
		if (temp == NULL) {	// Song not found in list
			return NOT_FOUND;
		}
		del = temp->next;
		temp->next = temp->next->next;	
		delete(del);
		temp = NULL;
		delete(temp);
		return SUCCESS;
	}//removeSong
	
	void UtPod::shuffle() {
		if (songs->next == NULL) {	//No need to shuffle 1 thing
			return;
		}
	}//shuffle
	
	void UtPod::showSongList() {
		SongNode *temp = new SongNode;
		temp = songs;
		while (temp != NULL) {
			//printf ("(temp->s).getName)\n", "%s");
			cout << (temp->s).getName() << ", " << (temp->s).getArtist() << ", " << (temp->s).getMemSize() << endl;
			temp = temp->next;
		}
		delete(temp);
	}//showSongList
	
	void UtPod::sortSongList() {
		int songSize = 0;
		SongNode *temp;
		SongNode *holder;
		temp = songs;
		while (temp != NULL) {
			songSize++;
			temp = temp->next;
		}
		for (int i=0; i < songSize; i++) {
			temp = songs;
			holder = NULL;
			for(int j = 0; j < songSize-1; j++) {
				holder = temp;
				temp = temp->next;
				if (holder->s > temp->s) {
					Song transfer;
					transfer = temp->s;
					temp->s = holder->s;
					holder->s = transfer;
				}
			}
		}	
	
	temp = NULL;
	holder = NULL;
	delete(temp);
	delete(holder);
	
	}//sortSongList
	
	void UtPod::clearMemory() {
		SongNode *temp;
		SongNode *del = new SongNode;
		temp = songs;
		while (temp != NULL) {
			del = temp;
			temp = temp->next;
			delete(del);
		}
		songs = NULL;
		temp = NULL;
		delete(temp);
	
	}//clearMemory
	
	
	int UtPod::getRemainingMemory() {
		int remainingMem = memSize;
		SongNode *temp = new SongNode;
		temp = songs;
		while (temp != NULL) {
			remainingMem -= (temp->s).getMemSize();
			temp = temp->next;
		}
		
		temp = NULL;
		delete(temp);
		return remainingMem;
	}//getRemainingMemory
	
	UtPod::~UtPod() {
		//Destructor
	}
	
	
	
	
	
	
	