/*****************************************
** File:    Computer.h
** Project: BattleShip, Fall 2017
** Author:  Pearl Pongsuppat
** Date:    11/07/17
** Section: 04
** E-mail:  ppongs1@umbc.edu
**
**   This file contains the header file of the Computer class 
**   this class is a child of Player and  outlines what
**   a CPU or AI player can do in the game of battleship.
**
***********************************************/

#include "Computer.h"

const int SIZE_GRID = 10; 
const int PART_ONE = 4;
const int PART_VERTICAL = 3;
const int HIT_MOVE = 3;
const int MISS_MOVE = 2;
const int PART_VERTICAL2 = 2;
const int BOARD_BOUNDS = 9;

Computer::Computer(){

}
// Name: Computer (Overloaded Constructor)
// Preconditions - None
// Postconditions - Creates computer player with file name

Computer::Computer(string file): Player(file){

  m_lastMove = PART_ONE;

}
// Name: makeMove()
// Preconditions - grid is already created
// Postconditions - Makes an educated guess for next place to fire for computer
// **This function should be more thoughtful than just two random numbers**
void Computer::makeMove(Grid* grid){
      
  //If the computer has not hit a ship yet, then it will keep randomly
  //attacking until they hit one.
 
  int move; 

  //First randomly selects a coordinate to check if there is a ship.
  if(m_lastMove == PART_ONE){

    srand(time(NULL));
  
    m_xCenter = rand() % SIZE_GRID;

    m_yCenter = rand() % SIZE_GRID;

    move = grid->attack(m_xCenter,m_yCenter);
  
    //If the computer misses then it will reset to picking random coordinates
    if(move == MISS_MOVE){

      cout << "Computer Missed." << endl;
      
      m_lastMove = PART_ONE; 
      
    }
    
    //If the computer hits a ship then it will next check for ships that are placed up vertically.
    else{

      cout << "Computer Hit Something!" << endl;

      m_xLast = m_xCenter;

      m_yLast = m_yCenter;
      
      m_xOriginal = m_xCenter;
      
      m_yOriginal = m_yCenter;

      m_lastMove = PART_VERTICAL;

    }

  }

  else{

    //Checks vertically up

    if(m_lastMove == PART_VERTICAL && m_yCenter > 0) 
      
      {
      	//Send in the coordinates for the next coordinate up to attack

	move = grid->attack(m_xCenter,(m_yCenter-1));
       
	//If the move is a hit, then proceed in that direction and continue
	//checking up.
	if(move == HIT_MOVE){
	
	  cout << "Computer hit something!" << endl;
	
	  m_yCenter = m_yLast-1;
	  m_yLast = m_yCenter;
	  m_lastMove = move;
	}
      
	else{
	  
	  //If the move misses then the computer will now check vertically down.
	  //Also resets the coordinates to the original hit.
	  cout << "Computer Missed!" << endl;

	  m_lastMove = PART_VERTICAL2;

	  m_prevMove = MISS_MOVE;

	  m_yCenter = m_yOriginal;

	  m_yLast = m_yOriginal;

	}
		  
      }

    //Checks vertically down.
    else if(m_lastMove == PART_VERTICAL2 && m_yCenter < BOARD_BOUNDS){
      
      move = grid->attack(m_xCenter,(m_yCenter+1));
      
      if(move == HIT_MOVE){
		
	cout << "Computer hit something!" << endl;

	m_yCenter = m_yLast+1;

	m_yLast = m_yCenter;

	m_lastMove = PART_VERTICAL2;

	m_prevMove = move;

      }
      
      //If it does not hit vertically up or vertically down, then check horizontal spaces
      else{

	cout << "Computer Missed." << endl;

	m_lastMove = 1;

	m_yCenter = m_yOriginal;

	m_yLast = m_yOriginal;

	
	//If the the previous move was a hit and it checked for space vertically up
	//and if the move just generated was a miss then we have checked for all vertical
	//positions and we reset our coordinates to random values and go back to 
	//random checking.
	if(m_prevMove == HIT_MOVE && move == MISS_MOVE){
	
	  m_lastMove = PART_ONE;

	}
	
      }
     
    }
    
    //Checks horizontally to the left
    else if(m_lastMove == 1 && m_xCenter > 0){

      move = grid->attack((m_xCenter-1),m_yCenter);
      
      //If its a hit check the next left space
      
      if(move == HIT_MOVE){
	
	cout << "Computer hit something!" << endl;

	m_xCenter = m_xLast-1;

	m_xLast = m_xCenter;
	
	m_lastMove = 1;
	
      }
      
      //If it misses horizontally to the left then check to the right 

      else{

	cout << " Computer missed." << endl;
	
	m_lastMove = 0;

	m_xCenter = m_xOriginal;

	m_xLast = m_xOriginal;

      }

    }

    //Checks to the right and makes sure it is in bounds
        
    else if (m_lastMove == 0 && m_xCenter < BOARD_BOUNDS){

      move = grid->attack((m_xCenter+1),m_yCenter);
      
      if(move == HIT_MOVE){
	
	cout << "Computer hit something!" << endl;

	m_xCenter = (m_xLast+1);
       
	m_xLast = m_xCenter;
       
        m_lastMove = 0;
	
      }
    
      //At this point we have checked for all positions possible from the center. 
      else{

	cout << "Computer Missed. " << endl;

	m_xCenter = 0;
	m_yCenter = 0;

	m_lastMove = PART_ONE;
	
      }
    }
    
  }

}


// Name: printBoard
// Preconditions - Board exists
// Postconditions - Prints the computer's board
void Computer::printBoard(){

  cout << "********** COMPUTER **************" << endl;
  string game = m_grid->print(true);
  cout << game << endl;
}  



