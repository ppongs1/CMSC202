/*                                                                                       Name: Pearl Pongsuppat                                                                   File: MusicPlayer.cpp                                                                    Section: 04                                                                              E-mail: ppongs1@umbc.edu                                                                                                                                                         
*/

#include "Song.h"
#include "MusicPlayer.h"

//Name: Song - Default Constructor
//Precondition: None
//Postcondition: Creates a default song
Song::Song(){


}

//Name: Song - Overloaded Constructor
//Precondition: Requires title, artist, year and rank
//Postcondition: Creates a song based on passed parameters

Song::Song(string title, string artist, int year, int rank ){

  m_title = title;
  m_artist = artist;
  m_year = year;
  m_rank = rank;


}

//Name: Mutators and Accessors
//Precondition: None
//Postcondition: Sets and Gets private member variables
string Song::getTitle()const{

  return m_title;
  
} // return title

string Song::getArtist()const{

  return m_artist; 

} 

int Song::getYear()const{

  return m_year;

} 

int Song::getRank()const{

  return m_rank;
} // return rank (1-100 from that year) 

void Song::setTitle(string title){

  m_title = title;

}

void Song::setArtist(string artist){

  m_artist = artist;

}

void Song::setYear(int year){

  m_year = year; 
}

void Song::setRank(int rank){

  m_rank = rank;
}



