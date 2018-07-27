/*****************************************
** File:    User.cpp
** Project: BattleShip, Fall 2017
** Author:  Pearl Pongsuppat
** Date:    11/07/17
** Section: N/A
** E-mail:  ppongs1@gl.umbc.edu
**
**   This file contains the header file of the User class 
**   this class is a child of Player and  outlines what
**   a human user can do in the game of battleship.
**
***********************************************/

#include "User.h"
#include "Grid.h"
#include "Player.h"
 
// Name: User (Default Constructor)
// Preconditions - None
// Postconditions - None
User::User():Player(){

}
  // Name: User (Overloaded Constructor)
  // Preconditions - None
  // Postconditions - None
User::User(string file):Player(file){
}

// Name: makeMove(grid)
// Preconditions - None
// Postconditions - Checks if move (x,y) hits or misses (or if already checked)

void User::makeMove(Grid* grid){

  int col,row, move;
  
  //Asks the user for their coordinates and reprompts them if 
  //they put an invalid number.

  do{
  cout << "Enter square to attack " << endl;
  cout << "Enter x (column) : " << endl;
  cin >> col;
  cout << "Enter y (row) : " << endl;
  cin >> row;
  }while(col < 0 || col > 9 || row < 0 || row > 9);

  
  //Checks to see if that spot has already been hit
  while(grid->alreadyTried(col,row)){
                                                                                             cout << "You have already selected this coordinate. " << endl;                           do{                                                                                  
      cout << "Enter square to attack " << endl;                                         
      cout << "Enter x (column) : " << endl;                                             
      cin >> col;                                                                        
      cout << "Enter y (row) : " << endl;                                                
      cin >> row;                                                                        
    }while(col < 0 || col > 9 || row < 0 || row > 9); 
  }

  move = grid->attack(col,row);

  if(move == 2){

    cout << "You Missed." << endl;
    
  }
  
  if(move == 3){

    cout << "You hit." << endl;
  }
  
}
// Name: printBoard
// Preconditions - User's grid exists
// Postconditions - Displays the users grid
void User::printBoard(){

  //Prints the board

  cout << "************** USER **************" << endl;
  string game = m_grid->print(false);
  cout << game << endl;
    
}

