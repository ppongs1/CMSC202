/*****************************************
** File:    Grid.cpp
** Project: BattleShip, Spring 2017
** Author:  Pearl Pongsuppat
** Date:    11/7/17
** Section: N/A
** E-mail:  ppongs1@gl.umbc.edu
**
**   This file contains the class header of the Grid class
**   this class is resposible for keeping track of all
**   spaces on the board and their current state
**
***********************************************/

#include "Grid.h"
#include <fstream>
#include <iomanip>
  
const int SET_GRID = 3;
const int SET_GRID2 = 2;
const int SET_GRID3 = 4;
// Name: Grid() Default Constructor
// Preconditions - 
// Postconditions - Constructor for the grid
Grid::Grid(){
  
  for(int i = 0; i < SIZE; i++){

    for(int j = 0; j < SIZE; j++){
      
      m_grid[i][j] = EMPTY;
    }

  }
      
      } 

// Name: Grid (file name) - Overloaded Constructor
// Preconditions - Have file name with valid input
// Postconditions - Constructor to build grid with ship locations from file
Grid::Grid(string file){

  int length, col, row;
  char orientation;
  ifstream inputstream;


  inputstream.open(file.c_str());

  //First creates an array filled with 0's
  if(inputstream.is_open()){
    
    for(int i = 0; i < SIZE; i++){

      for(int j = 0; j < SIZE; j++){

	m_grid[i][j] = EMPTY;
      }

    }
    //Loads in the ships onto the board
    while(inputstream >> length >> col >> row >> orientation){

      //If the orientation is vertical then the ships will be loaded in accordingly
      if(orientation == 'V'){

	for(int i = row; i < row+length; i++){

	  m_grid[i][col] = OCCUPIED;

	}
      }
      //If the orientation is horizontal then the ships will be loaded accordingly
      if(orientation == 'H'){

	for(int i = col; i < col+length; i++){

	  m_grid[row][i] = OCCUPIED;
	  
	}

      }
    }
  }
  
}

// Name: alreadyTried(int, int)
// Preconditions - Have a grid with data
// Postconditions - Returns true if location has already been checked (returned MISS)
bool Grid::alreadyTried(int x, int y){

  if(m_grid[y][x] == MISS){

    return true;
      
      }

  else
    
    return false;
    
    
}



// Name: isMiss(int, int)
// Preconditions - Have a grid with data
// Postconditions - Returns true if a location is not occupied
bool Grid::isMiss(int x, int y){
  
  if(m_grid[y][x] != OCCUPIED){
    
    return true;
  }
  
  else{
    
    return false;
  }
}

// Name: attack(int, int)
// Preconditions - Have a grid with data
// Postconditions - Returns integer based on result also checks if occupied
int Grid::attack(int x, int y){

  int move;
  move = alreadyTried(x,y);
  if(m_grid[y][x] == OCCUPIED && m_grid[y][x] != HIT){

    m_grid[y][x] = HIT;
    return(HIT);

  }
  else if(m_grid[y][x] == EMPTY){

    m_grid[y][x] = MISS;
    return(MISS);
  
  }
  else{

    return(MISS);
  }
      
}


// Name: noOccupiedLeft()
// Preconditions - Have a grid with data
// Postconditions - Returns true if no cells in grid have a value of 1 (checks win)
bool Grid::noOccupiedLeft(){

  
  for (int i = 0; i < SIZE; i++){

    for (int j = 0; j < SIZE; j++){

      if (m_grid[i][j] == OCCUPIED){

	return(false);
	
      }
    }

  }
   
  return true;

}

// Name: print(bool)
// Preconditions - Have a grid with data
// Postconditions - Prints the grid - parameter toggles if ships are hidden or not

string Grid::print(bool hideShips){
  
  stringstream battle;

  //Prints out the first row for x coordinates 0-9
  battle << setw(SET_GRID3);
  for (int i = 0; i < SIZE; i++){                                                                               
    battle << ' ' << setw(SET_GRID2)<< i;
    
  }

  battle << endl;
  battle << setw(SET_GRID);

  //Prints the board and check each integer value. Prints out 
  //a '.', '#'. 'X', or 'O' depending on which integer is set 

  for(int i = 0; i < SIZE; i++){
        
    battle <<  i;
    battle << ' ' << setw(SET_GRID2);
    
    for(int j = 0; j < SIZE; j++){
      
      if(m_grid[i][j] == EMPTY){

	battle << '.' << setw(SET_GRID);
	
      }
      if(m_grid[i][j] == OCCUPIED){
	
	//If printing out the computer's ship then hide the ships and
	//output a period
	if(hideShips == true){
	  
	  battle << '.' << setw(SET_GRID);
	  
	}
	//If dealing with the user's computer then print out a '#' representing
	//the ships.
	else if(hideShips == false){
	  
	  battle << '#' << setw(SET_GRID);
	}
	
      }
      
      //After attacking if the user or computer misses, then change the period
      //to a 'O'
      if(m_grid[i][j] == MISS){
	
	battle << 'O'<< setw(SET_GRID);

      }
      
      //If the user or computer hits, then a 'X' will be outputted 
      if(m_grid[i][j] == HIT){
	
	battle << 'X' << setw(SET_GRID);
      }
    }
    
    battle << endl;
      
  }
  
    return(battle.str());
    
}
