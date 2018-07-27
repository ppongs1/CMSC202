/********************************************                                                               
 ** File: proj2.cpp                                                                                         
 ** Project: CMSC 202 Project 2, Fall 2017                                                                  
 ** Author: Pearl Pongsuppat                                                                                
 ** Date:  October  19, 2017                                                                                
 ** Section: 04                                                                                             
 ** E-mail: ppongs1@umbc.edu                 
 ** Description: This file contains main() and 
 ** begins CLASH UMBC by creating a newTrooper object                                                        **********************************************/

#include <iostream>
#include "Game.h"
#include "Troop.h"

using namespace std;


int main(){

  // Call game class and creates a newTrooper object 
  
  Game newTrooper;
  newTrooper.LoadTroops(); //Loads the troops
  newTrooper.RandomizeTeam(); //Randomizes the team
  newTrooper.DisplayTroops(); //Displays the teams
  newTrooper.StartGame(); //Begins the game

  return 0;
}
