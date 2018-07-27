/*****************************************
** File:    Player.h
** Project: BattleShip, Spring 2017
** Author:  Pearl Pongsuppat
** Date:    11/07/17
** Section: 04
** E-mail:  ppongs1@umbc.edu
**
**   This file contains the header file of the Player class 
**	 this class outlines the basics of what a player in
**   a game of battleship can do.
**
***********************************************/

#include "Grid.h"
#include "Player.h"

  // Name: Player (Default Constructor)
  // Preconditions - None
  // Postconditions - Constructor that builds a new grid
Player::Player(){

  m_grid = NULL;

}
  // Name: Player (Overloaded Constructor)
  // Preconditions - File exists
  // Postconditions - Constructor that builds a new grid based on a file
Player::Player(string file){

 
  m_grid = new Grid(file); 


}

// Name: ~Player (Destructor)
// Preconditions - Player was dynamically allocated
// Postconditions - Deletes dynamically allocated player 
Player::~Player(){
  
  delete m_grid;
  m_grid = NULL;

}

// Name: hasLost()
// Preconditions - Grid is populated
// Postconditions - Checks to see if there are any "occupied" spaces left in grid
bool Player::hasLost(){

  return(m_grid->noOccupiedLeft());
  
}

// Name: getGrid()
// Preconditions - Grid exists
// Postconditions - Returns a Grid pointer
Grid* Player::getGrid(){
 

  return(m_grid);
}

  // Name: printBoard()
  // Preconditions - Grid exists
  // Postconditions - Prints current grid with ships not hidden
void Player::printBoard(){

  

}


