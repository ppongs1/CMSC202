/********************************************                                                               ** File: Troop.cpp                                                                                         *** Project: CMSC 202 Project 2, Fall 2017                                                                  *** Author: Pearl Pongsuppat                                                                                *** Date:  October  19, 2017                                                                                *** Section: 04                                                                                             *** E-mail: ppongs1@umbc.edu                                                                                *** This file contains the program that builds a new troop and 
** allows the player to attack the troop. 
*********************************************/
#include "Troop.h"

// Name: Troop() - Overloaded constructor
// Desc - Used to build a new troop
// Preconditions - Requires name, health, damage, target, and isFlying (from file)
// Postconditions - Creates a new troop
Troop::Troop(string name, int health, int damage, string target, bool isFlying){

  m_health = health;
  m_name = name;
  m_damage = damage;
  m_target = target;
  m_isFlying = isFlying;

}

// Name: GetName()
// Desc - Getter for troop name
// Preconditions - Troop exists
// Postconditions - Returns the name of the troop
string Troop::GetName(){
  
  return m_name;
}

// Name: SetName(string)
// Desc - Allows the user to change the name of the troop
// Preconditions - Troop exists
// Postconditions - Sets name of troop

void Troop::SetName(string name){
  
  m_name = name;

}


// Name: GetHealth()
// Desc - Getter for troop health
// Preconditions - Troop exists
// Postconditions - Returns the health of the troop

int Troop::GetHealth(){

  return (m_health);

}
  // Name: SetName(int)
  // Desc - Allows the user to change the health of the troop
  // Preconditions - Troop exists
  // Postconditions - Sets health of troop
void Troop::SetHealth(int health){
  
  m_health = health;

}

  // Name: GetDamage()
  // Desc - Getter for troop name
  // Preconditions - Troop exists
  // Postconditions - Returns the damage of the troop

int Troop::GetDamage(){
  
   
  return(m_damage);
}

// Name: GetTarget()
// Desc - Getter for troop target ("Both" can attack ground + air)
//                                ("Ground" can ONLY attack ground)
// Preconditions - Troop exists
// Postconditions - Returns what the troop can target

string Troop::GetTarget(){
  
  return(m_target);
}


// Name: GetIsFlying()
// Desc - Getter for troop flying (1 is flying and only things with target both)
//                                (0 is not flying)
// Preconditions - Troop exists
// Postconditions - Returns if the troop is flying
bool Troop::GetIsFlying(){
  
  return(m_isFlying);
}


// Name: AttackTroop(Troop&)
// Desc - Allows the user to attack an enemy troop
// Checks to see if 1. Attacking troop can attack "both" or "ground"
//                  2. If the target is flying or not.
//                  3. Updates health of target (current health - damage)
// Preconditions - Troops exist
// Postconditions - Health of target is updated

void Troop::AttackTroop(Troop& attackplayer){
  
  //Checks conditions for a troop that can attack on ground.
  //If the player being attacked cannot fly then damage can occur.
  //If the player being attacked can fly then the ground troop cannot
  //attack that player. 

  if (m_target == "Ground") {

    if(attackplayer.GetIsFlying() == 0){
      cout << m_name << " attacks " << attackplayer.GetName() << " on the  ground! " << endl;
      cout << endl;

      //Updates health of the player      
      attackplayer.m_health = attackplayer.GetHealth() - m_damage;

      if (attackplayer.m_health > 0){
	cout << "Damage occurring " << m_damage << endl;
	cout << endl;
       
      }
      else{
	cout << attackplayer.GetName() << " dies" << endl;
	cout << endl;
      }
    }
    else if (attackplayer.GetIsFlying() == 1){
      cout << m_name << " cannot attack  " << attackplayer.GetName() << endl;
      cout << endl;
    }

  }

  //If the troop can attack both in the air and on the ground, then damage
  //can occur for players that can't fly and those that do.
    
  if (m_target == "Both"){
    
    if(attackplayer.GetIsFlying() == 0 || attackplayer.GetIsFlying() == 1){

      cout << m_name << " attacks "<< attackplayer.GetName() << " on  air/ground! " << endl;
      cout << endl;

      //updates health of the attacked player
      attackplayer.m_health = attackplayer.GetHealth() - m_damage;

      if (attackplayer.m_health > 0){
	cout << "\nDamage occurring " << m_damage << endl;
	cout << endl;
      }

      else{
	cout << attackplayer.GetName() << " dies" << endl;
	cout << endl;
      }
    
    }
  }
}


