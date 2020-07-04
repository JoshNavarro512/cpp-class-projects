// This program sorts a playlist by artist

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Playlist
{
	string artistName;
	string songName;
	
};

// Function Prototypes
void getPlaylistData(struct Playlist, NUM_SONGS);
void sortplaylist(Playlist playlistEntry[], NUM_SONGS);
void showPlaylist(const Playlist playlistEntry[], NUM_SONGS);


//const int NUM_SONGS = 10;

int main()
{
	const int NUM_SONGS = 10;

	Playlist playlistEntry[NUM_SONGS];
	
	getPlaylistData(playlistEntry[]);
	
	showPlaylist(playlistEntry[]);
	
	return 0;
}

void getPlaylistData(struct Playlist &songData)
{
		// Get name of artist and song
	for (int i=0; i < NUM_SONGS; i++)
	{
	cout << "What is the name of the artist: " << endl ;
	getline (cin, songData[i].artistName);
	
	cout << "What is the name of the song: " << endl ;
	getline (cin, songData[i].songName);
	}
}

void sortplaylist(Playlist playlistEntry[], NUM_SONGS)
{
		string startScan, minIndex, minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for(int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
      }
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	
}

void showPlaylist(const playlistEntry[], NUM_SONGS)
{
	// Display the playlist 
	for (int i=0; i < NUM_SONGS; i++)
	{
	cout << endl;
	cout << endl;
	cout << "		Playlist		" << endl;
	cout << "	Artist		Title		" << endl;
	cout << "=============================" << endl;
	cout << songData[i].artistName << "		"<< songData[i].songName << endl;
	}
	
}

