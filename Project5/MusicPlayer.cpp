/*
Name: Pearl Pongsuppat
File: MusicPlayer.cpp
Section: 04
E-mail: ppongs1@umbc.edu


 */

#include <cstdlib>
#include "MusicPlayer.h"

const int MIN_YEAR = 1983;

MusicPlayer::MusicPlayer(){

}

//Name: MusicPlayer - Overloaded Constructor
//Precondition: None
//Postcondition: Creates a new MusicPlayer and passes the music filename
MusicPlayer::MusicPlayer(string filename){

  LoadCatalog(filename);


}
  //Name: ~MusicPlayer - Destructor
  //Precondition: None
  //Postcondition: Creates a new MusicPlayer
MusicPlayer::~MusicPlayer(){

  for(int i = 0; i < int(m_songCatalog.size()); i++){

    delete m_songCatalog[i];
  }
}

//Name: LoadCatalog(string filename)
//Precondition: Requires filename
//Postcondition: Loads the file into the m_songCatalog (as songs)
void MusicPlayer::LoadCatalog(string filename){
  
  ifstream inputstream;

  string rank,song,artist,year;

  int rank2,year2;

  //Opens file and retrieves the rank, song, artist, and year
  inputstream.open(filename.c_str());

  if(inputstream.is_open()){

    while(getline(inputstream, rank, ',')){

	  getline(inputstream,song,',');

	  getline(inputstream, artist, ',');                                                                     
	  getline(inputstream, year);                                                                            
	  if (inputstream.peek() == '\n'){                                                                       
	    inputstream.ignore(); 	    
	  }
	  
	  rank2 = atoi(rank.c_str());

	  year2 = atoi(year.c_str());

	  Song *newSong = new Song(song, artist, year2, rank2);

	  m_songCatalog.push_back(newSong);
    	  	  
    }

    inputstream.close();

    }

  }

//Name: MainMenu
//Precondition: None
//Postcondition: Manages the application and the menu
void MusicPlayer::MainMenu(){
  
  int userChoice;

  //Asks the user to select from the main menu options 

  do{
  cout<< "What would you like to do? " << endl;

  cout<< "1. Display Songs by Year " << '\n' << "2. Add Song " << '\n' << "3. Display Playlist. " 
      << '\n' << "4. Quit " << endl;

  cin >> userChoice;

  }while(userChoice < 1 || userChoice > 4);

  switch(userChoice){

  case 1:
    
    { DisplaySongs();
      break; }
    
  case 2:
    {AddSong(); 
      break;}
  
  case 3:
    {DisplayPlaylist();

      break;}
   
  case 4:
    {
    cout << "Thank you for using the UMBC Music Player. " << endl;
    return;}
    
  }
}

//Name: DisplaySongs
//Precondition: User enters year (1983-2013)
//Postcondition: Lists all songs (numbered) for that year
void MusicPlayer::DisplaySongs(){
  
  int year;

  //Displays the top songs for the year that the user selected

  do{
    cout << "Which year would you like to display ? (1983 - 2013)" << endl;
    
    cin >> year;

  }while(year < 1983 || year > 2013);

  cout << "*********" << year << "*********" <<endl;

  for (int i = 0; i < int(m_songCatalog.size()); i++){
    
    if(m_songCatalog[i]->getYear() == year){

      cout << i+1 << '.' << m_songCatalog[i]->getTitle() << 

      " by " << m_songCatalog[i]->getArtist()<<endl;
    }
  }
  MainMenu();
      
}

//Name: AddSong
//Precondition: m_songCatalog is populated
//Postcondition: Displays the current list and adds a song (by year)
//               to the m_playList
void MusicPlayer::AddSong(){

  int year, songNum, checkEmpty, checkFull;

  //Checks if the playlist is empty
  checkEmpty = m_playList.isEmpty();
  
  checkFull = m_playList.isFull();
  
  if(checkEmpty == 1){
    
    cout << "********* Current Playlist is Empty ********* " << endl;
  }

  //If the playlist is not full then the user can continue to add songs
  if(checkFull != 1){
    cout << "Choose which songs you would like to add to the playlist. " << endl;

    do{

      cout << "Which year would you like to display ? (1983 - 2013)" << endl;

      cin >> year;

    }while(year < 1983 || year > 2013);

    cout << "****************" << year << "****************" << endl;
    
    for (int i = 0; i < int(m_songCatalog.size()); i++){

      if(m_songCatalog[i]->getYear() == year){

	cout << i+1 << '.' << m_songCatalog[i]->getTitle() <<

	  " by " << m_songCatalog[i]->getArtist()<<endl;
      
      }

    }
  
  cout << endl;

  
  cout << "Enter the number of the song you would like to add: " << endl;

  cin>>songNum;
  
  m_playList.enqueue(*m_songCatalog[songNum-1]);
  
  }
  
  //If the playlist is full then the user cannot add anymore songs and is reprompted with
  //the main menu

  else{
    
    cout << "The current play list is full. " << endl;
  }
  MainMenu();

}

//Name: DisplayPlaylist
//Precondition: None (can be empty)
//Postcondition: Displays the playlist
void MusicPlayer::DisplayPlaylist(){

  //Displays the users current playlist

  for(int i = 0; i < m_playList.size(); i++){

    cout << i+1 << ". " << m_playList[i].getTitle() << " by " << m_playList[i].getArtist() <<

      " from " << m_playList[i].getYear() << endl;
  }

  MainMenu();
}




