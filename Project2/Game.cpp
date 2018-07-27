/********************************************                                                               ** File: Game.cpp                                                                                           ** Project: CMSC 202 Project 2, Fall 2017                                                                   ** Author: Pearl Pongsuppat                                                                                 ** Date:  October 19, 2017                                                                                  ** Section: 04                                                                                              ** E-mail: ppongs1@umbc.edu                                                                                 **                                                                                                          ** This file contains the program that runs the CLASH UMBC Game                                             *********************************************/

#include "Game.h"
#include <fstream>


Game::Game() {
  
  cout << "What is your name? " << endl;

  getline(cin, m_name);

  while(m_max < 2 || m_max > 5){
    cout << "How many troops would you like? (2-5): " << endl;
    cin>> m_max;
  }
  m_curPlayer = 1;
  m_curTroop = 0;

}//Default Constructor


// Name: LoadTroops
// Desc - Loads each troop into m_troop from file
// Preconditions - Requires file with valid troop data
// Postconditions - m_troop is populated with Troop objects

void Game::LoadTroops(){
  
  int health, damage;
  string name;
  string target;
  bool isFlying;

  ifstream inputstream;

  // Reads in the project file and loads the project 
  inputstream.open(PROJ2_TROOPS.c_str());
  if(inputstream.is_open()){
    while(inputstream >> name)

      {
	inputstream >> health >> damage >> target >> isFlying;
	    
	Troop newTrooper(name, health, damage, target, isFlying);

	m_troop.push_back(newTrooper);

      }
    inputstream.close();
  }
  
}

// Name: RandomizeTeam
// Desc - Randomly chooses a troop and puts it on a team
// Preconditions - m_troop is populated
// Postconditions - m_player and m_computer is populated

void Game::RandomizeTeam(){

  // initialize random seed
  srand(time(NULL));
  int rand1;
  int rand2;

  // Gets a random number in the range of 0 to the size of the
  // troop vector. Uses that number as an index to retrieve a troop
  // from the vector and add it to the respected teams.

  for(int i = 0; i < m_max; i++){
    rand1 = rand() % m_troop.size();

    m_player.push_back(m_troop.at(rand1));
    
    rand2 = rand() % m_troop.size();
    
    m_computer.push_back(m_troop.at(rand2));

  }

}  


// Name: StartGame()
// Desc - Manages the game itself including win conditions continually
//         calling the main menu 
// Preconditions - Both players have teams with troops
// Postconditions - Continually checks to see if player/computer has troops
void Game::StartGame(){
  

  if (m_player.size() > 0 && m_computer.size() > 0){

    MainMenu();

  }

}

// Name: DisplayTroops()
// Desc - Displays the current teams (both user and computer)
// Preconditions - Players have a team with troops
// Postconditions - Displays a numbered list of troops 
void Game::DisplayTroops(){

  //Iterates through player and computer vector and displays the 
  //corresponding troops on both teams. 

  cout << "Both teams have been populated." << endl;
  cout << "***************************" << endl;
  
  cout << m_name << "'s Team" << endl;
  for(int i = 0; i < (int)m_player.size(); i++){
    cout << i+1 << "." <<  m_player[i].GetName() << "\t" <<  m_player[i].GetHealth()<< endl;

  }
  
   
  cout << "***************************" << endl;
  cout << endl;
  cout << "Computer's Team" << endl;
  for(int i = 0; i < (int)m_computer.size(); i++){
    cout << i+1 << "." << m_computer[i].GetName()<< "\t" <<  m_computer[i].GetHealth() <<  endl;

  }
  cout << "***************************" << endl;
  cout << endl;
    
}


// Name: ChangeTroop()
// Desc - Allows the user to change current troop
// Preconditions - Players have troops and have not lost
// Postconditions - Displays a numbered list of troops and m_curTroop is updated
void Game::ChangeTroop(){
  
  //Allows player to change their current troop to attack with.

  while(m_curTroop < 1 || m_curTroop > m_max){
    
    DisplayTeam();

    cout << "What troop do you want to use? " << endl;

    cin >> m_curTroop;
  
  }
  cout << "***************************" << endl;

  m_curTroop -= 1;
  
  MainMenu();

}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - Players have a team with troops
// Postconditions - Displays a numbered list of troops
void Game::MainMenu(){
  
  int userChoice;

  //Asks the user to select an option from the menu
  //Reprompts them if they choose an invalid option

  while(userChoice > 4 || userChoice < 1){

    cout << "What would you like to do? " << endl;
    cout << "1. Display Team" << endl;
    cout << "2. Change Current Troop" << endl;
    cout << "3. Attack!" << endl;
    cout << "4. Exit. " << endl;
    cout << endl;
    cin >> userChoice;

  }
  
  switch(userChoice){

  case 1:
    
      DisplayTeams();
      break;
    
  case 2:
    
      ChangeTroop();
      break;
    

  case 3:
    
      Attack();
      break;
    
  }

}

// Name: DisplayTeams()
// Preconditions - m_player/m_computer have a team with troops
// Postconditions - Displays a numbered list of troops
void Game::DisplayTeams(){
  
  
  cout << "***************************" << endl;
  cout << m_name << "'s Team" << endl;
  for(int i = 0; i < (int)m_player.size(); i++){
    cout << i+1 << "." <<  m_player[i].GetName() << "\t" << m_player[i].GetHealth()<< endl;
  }

  cout << "***************************" << endl;
  cout << endl;
  cout << "Computer's Team" << endl;
  for(int i = 0; i < (int)m_computer.size(); i++){
    cout << i+1 << "." << m_computer[i].GetName()<< "\t" <<  m_computer[i].GetHealth() <<  endl;
  }
  cout << "***************************" << endl;
  cout << endl;

  StartGame();
}  

// Name: DisplayTeam()
// Preconditions - Player and Computer both have troops left
// Postconditions - Displays a numbered menu
void Game::DisplayTeam(){
  
  cout << "***************************" << endl;
  cout << m_name << "'s Team" << endl;
  for(int i = 0; i < (int)m_player.size(); i++){
    cout << i+1 << "." <<  m_player[i].GetName() << "\t" << m_player[i].GetHealth()<< endl;}
  
  cout << "***************************" << endl;
  cout << endl;
}


// Name: Attack()
// Preconditions - Player and Computer both have troops left
// Postconditions - Depending on whose turn it is, calls attacks
void Game::Attack(){

  //If m_curPlayer % 2 = 1, this indicates that it is the player's turn to attack first
  //and then switches to the computer for attacking. After each attack,
  //if the troop is killed then they are removed from their vector. 

  if(m_curPlayer %  2 == 1){

    m_player[m_curTroop].AttackTroop(m_computer[0]);

    if(m_computer[0].GetHealth() <= 0){
    
      m_computer.erase(m_computer.begin());

    }
    
    else{
      m_computer[0].AttackTroop(m_player[m_curTroop]);
      
      if (m_player[m_curTroop].GetHealth() <= 0){

	m_player.erase(m_player.begin()+m_curTroop);

	m_curTroop = 0;
      }
    }
  }

  //Switch turns. If m_curPlayer % 2 = 0 this indicates that the computer attacks
  //first followed by the player. Removes the troop if health is below zero.  
  if(m_curPlayer % 2 == 0){

    m_computer[0].AttackTroop(m_player[m_curTroop]);

    if(m_player[m_curTroop].GetHealth() <= 0){

      m_player.erase(m_player.begin()+m_curTroop);

      m_curTroop = 0;
    }
    else{
      m_player[m_curTroop].AttackTroop(m_computer[0]);
      
      if(m_computer[0].GetHealth() <= 0){

	m_computer.erase(m_computer.begin());
      }
    }
  }

  //Updates the value of m_curPlayer to allow switching of turns and calls DisplayTeams
  if (m_player.size() > 0 && m_computer.size() > 0){
    m_curPlayer++;
    DisplayTeams();
  }

  //Checks win conditions.
  else if (m_player.size() == 0){
    cout << "The computer wins!" << endl;
  }

  else if (m_computer.size() == 0){
    cout << "You win!" << endl;
  }
}




  
  

