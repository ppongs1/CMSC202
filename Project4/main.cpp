/*****************************************                                              ** File:    main.cpp                                                                   ** Project: BattleShip, Fall 2017                                                      ** Author:  Pearl Pongsuppat                                                           ** Date:    11/07/17                                                                   ** Section: 04                                                                         ** E-mail:  ppongs1@umbc.edu                                                           **                                                                                     **   This file contains the header file of the Computer class                         
 **   this class is a child of Player and  outlines what                                **   a CPU or AI player can do in the game of battleship.                              **                                                                                             
 ***********************************************/

#include <iostream>
#include "Computer.h"
#include "User.h"
#include "Grid.h"
#include "Player.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

  //Checks if file has loaded in correctly.
  if(argv[1] > 0 && argv[2] >0){

    cout << "Message Loaded" << endl;
  } else{
    cout << "No text file loaded - try make run1" << endl;
    return 0;
  }


  //Create a vector of Player objects 
  vector <Player*> battle;

  //Allocates new memory for a player pointer object for computer and user.
  Player *comp = new Computer(argv[1]);

  Player *user = new User(argv[2]);
  
  //Adds my objects to my vector.   
  battle.push_back(comp);
  
  battle.push_back(user);

  //Prints board for computer and user.
  battle[0]->printBoard();
  
  battle[1]->printBoard();

  //Continues to run the game while 
  while(battle[0]->hasLost() == false && battle[1]->hasLost() == false){

    battle[1]->makeMove(battle[0]->getGrid());

    battle[0]->printBoard();
    
    battle[0]->makeMove(battle[1]->getGrid());

    battle[1]->printBoard();
  
  }
  //Delete dynamically allocated objects. 

  delete comp;
  delete user;
}
