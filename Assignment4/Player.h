// File Name: Player.h
//
// Author: Josh Navarro
// Date: 10/19/2018
//
// Description: 
// 

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;




class Player {
private:
	
	int const NUM_SONGS = 1000;
	
    struct Song 
	{
    	string band,
    		   title,
    		   length;
    		   
    	float  size;
	};
	
	song songArray[NUM_SONGS];
	
	
public:
    
    bool addSong( string band, string title, string length, float size );
    
    bool removeSong( string band, string title);
    
    void displaySongInfo(string band, string title);
    
    void displaySongsByLength();
    
    void deviceInfo();
    
};

#endif
