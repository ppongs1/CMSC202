/*****************************************
File: CipherString.cpp
Name: Pearl Pongsuppat
Date: 11/02/2017
Section: 04
E-mail: ppongs1@umbc.edu
Project: CMSC 202 Project 3, Fall 2017

****************************************** */
#include "CipherString.h"
#include "Node.h"

using namespace std;

const int ALPHA_LET = 26;
const int WHITE_SPACE = 32;

// Name: CipherString - default constructor
// Preconditions  - None
// Postconditions - Creates a new CipherString
CipherString::CipherString(){

  m_head = NULL;
  
  m_size = 0;  

}


// Name: CipherString - overloaded constructor
// Preconditions - None
// Postconditions - Creates a new CipherString (using char*)
CipherString::CipherString(const char* charfile){


  m_head = NULL;
  
  m_size = 0; 
  
  loadMessage(charfile);
}


// Name: ~CipherString - destructor
// Preconditions - None
// Postconditions - Destroys CipherString
CipherString::~CipherString(){

  Node *temp = m_head;
  
  while(m_head != NULL){
    temp = m_head;
    
    m_head = m_head->getNext();
    delete temp;
  }
  
  delete m_head;
  m_head = NULL;
  temp = NULL;
}


// Name: loadMessage
// Preconditions - File (with text in it) is passed to function
// Postconditions - Opens file and loads one character at a time into the linked list
void CipherString::loadMessage(const char* filename){


  string cipherchar;
  
  ifstream inputstream;
  inputstream.open(filename);
  
  if(inputstream.is_open()){
    while(getline(inputstream, cipherchar)){

      for(int i = 0; i < int(cipherchar.size()) ; i++){

	addCharacter(cipherchar[i]);
	
      }
      
    }

  }
}  
    

// Name: addCharacter
// Preconditions - Linked list exists
// Postconditions - Adds character to end of linked list
void CipherString::addCharacter(char cipherchar){

  
  if(m_head == NULL){
    
    //Creates the first node in my link list
    m_head = new Node (cipherchar);
    
    m_size = 1;

  }

  else{

    //Sets current node to be your head node
    Node *curr = m_head;
  
    //checks to see if current node points to anything, if not move to the next
    // node
    while(curr->getNext()!= NULL){ 
      
      curr = curr->getNext();
    }
        
    curr->setNext(new Node(cipherchar));
      
    m_size++;
    }

}

// Name: encryptOng
// Preconditions - Linked list exists
// Postconditions - For each consonent, adds a node with "o", adds a node with "n"
// adds a node with "g". Every "letter" is separated with a "-" and each word is
// seperated by a space.
void CipherString::encryptOng(){
   
  Node *curr = m_head; //Creates a node POINTER that points at the first node of the link list
  
  Node *temp = curr->getNext(); //Creates a pointer that points to the pointer of curr

  while(temp != NULL){
  
    //Goes through my link list and checks for consonants. If the character is 
    // a consonant then add ONG
    if(curr->getChar() != 'a' && curr->getChar() != 'e' &&
       curr->getChar() != 'o' && curr->getChar() != 'i' &&
       curr->getChar() != 'u' && curr->getChar() != 'A' &&
       curr->getChar() != 'E' && curr->getChar() != 'I' &&
       curr->getChar() != 'O' && curr->getChar() != 'U' && 
       curr->getChar() != ' ' && curr->getNext()->getChar() != WHITE_SPACE)

      {

	Node *currO = new Node('o');
	Node *currN = new Node('n');
	Node *currG = new Node('g');
	Node *hyphen = new Node ('-');


	curr->setNext(currO);
      
	curr = curr->getNext();

	curr->setNext(currN);
      
	curr = curr->getNext();

	curr->setNext(currG);
	
	curr = curr->getNext();

	// If temp, which is pointing to the next node after curr
	// is not a white space then add a hyphen.

	if(temp->getChar() != ' ')
	  {
	  
	    curr->setNext(hyphen);

	    curr = curr->getNext();

	    hyphen->setNext(temp);
		
	  }

      } 

    else{
      
      //If the character is a vowel then it will add a hyphen after it. Also 
      //checks to see the character after it is not a white space. If it is a white
      //space then the hyphen will not be added.

      if(curr->getChar() != ' ' && temp->getChar() != ' '){
	
	Node *hyphen = new Node ('-');
	curr->setNext(hyphen);
	hyphen->setNext(temp);
      }
      
    }
    //Resets where the curr node is to go back through the loop. 
    //moves temp to point to the next node.

    curr = temp;
    temp = curr->getNext();

  }

  for(curr = m_head; curr != NULL; curr = curr->getNext()){

    cout << curr->getChar();
  }

}


// Name: decryptOng
// Preconditions - Linked list exists
// Postconditions - For each consonent, adds a node with "o", adds a node with "n"
// adds a node with "g". Every "letter" is separated with a "-" and each word is
// seperated by a space
void CipherString::decryptOng(){

  Node *curr = m_head; //Creates a node POINTER that points at the first node of the link list  

  while(curr->getNext() != NULL){

    //Checks for consonants and whitespace. If the character is, then delete the next three nodes.
    if(curr->getChar() != 'a' && curr->getChar() != 'e' &&
       curr->getChar() != 'o' && curr->getChar() != 'i' &&
       curr->getChar() != 'u' && curr->getChar() != 'A' &&
       curr->getChar() != 'E' && curr->getChar() != 'I' &&
       curr->getChar() != 'O' && curr->getChar() != 'U' &&
       curr->getChar() != ' ' && curr->getNext()->getChar() != WHITE_SPACE)
      {

	Node *temp1 = curr->getNext();
	Node *temp2 = temp1->getNext();
	Node *temp3 = temp2->getNext();
	Node *temp4 = temp3->getNext();
	
	delete temp1;
	delete temp2;
	delete temp3;
	
	curr->setNext(temp4->getNext());
	
	delete temp4;
	
      }
    
    else{

      //if the character is vowel then check if the next character is a dash
      // if it is then link curr to the node after the dash and then delete the
      // node that contains the dash.
      Node *temp1 = curr->getNext();

      if(temp1->getChar() == '-'){
		
	curr->setNext(temp1->getNext());

	delete temp1;

      } 
      	
    }
    curr = curr->getNext();
    
  }
  for(curr = m_head; curr != NULL; curr = curr->getNext()){

    cout << curr->getChar();
  }
}


// Name: encryptCaesar
// Preconditions - Linked list exists
// Postconditions - Shifts each character "right" by the int provided. 
// See project document for additional details.
void CipherString::encryptCaesar(int shift){
  
  Node *curr = m_head;

  for(int i = 0; i < m_size; i++){

    //This case checks if the character is lower case
    if(islower(curr->getChar())){
  
      //Changes the character value for the word being ciphered from 0-25 by
      //subtracting it from 97 (the ASCII value for 'a'). Adds it to the integer
      //given by the user and mods it by 26. Adds it back to the offset.

      curr->setChar(char((((curr->getChar()-'a')+shift)%ALPHA_LET)+'a'));
      
      curr = curr->getNext();
    }
    
    //Checks the condition for an upper case character. Does the same thing
    //above except the character is now being subtracted by 65 (the ASCII
    //value for 'A')
 
    else if(isupper(curr->getChar())){

    curr->setChar(char((((curr->getChar()-'A')+shift)%ALPHA_LET)+'A'));
    
    curr = curr->getNext();
    
    }      

    //Moves to the next node is there is a white space
    else if(curr->getChar() == ' '){
      
      curr = curr->getNext();
    }
  }
  for(curr = m_head; curr != NULL; curr = curr->getNext()){

    cout << curr->getChar();
  }
}   
        

      
// Name: decryptCaesar
// Preconditions - Linked list exists
// Postconditions - Shifts each character "left" by the int provided.
// See project document for additional details.
void CipherString::decryptCaesar(int shift){
  
  int number;
  Node *curr = m_head;
  for(int i = 0; i < m_size; i++){
    
    //Checks for lower case. Subtracts the character from the ASCII value for 'a' 
    // subtracts that value from the integer the user inputs and mods by 26.
    if(islower(curr->getChar())){

      number = ((curr->getChar()-'a')-shift)%ALPHA_LET;

      if(number < 0){

	number = number + 26;
      }
      curr->setChar(char((number+'a')));

      curr = curr->getNext();

    }
    //Checks for upper case. Subtracts the character from ASCII value for 'A'
    //Then subtracts that value from the shift integer the user inputs.
    else if(isupper(curr->getChar())){

      curr->setChar(char((((curr->getChar()-'A')-shift)%26)+'A'));

      curr = curr->getNext();

    }
    //Moves to the next node if there is a whitespace.
    else if(curr->getChar() == ' '){

      curr = curr->getNext();
    }

  }

  for(curr = m_head; curr != NULL; curr = curr->getNext()){

    cout << curr->getChar();

  }
}
// Name: encryptVigenere
// Preconditions - Linked list exists
// Postconditions - Shifts each character by the character (in string) provided.
// See project document for additional details.
void CipherString::encryptVigenere(string key){
 
  const char *keyname = key.c_str();

  int number;
  
  Node *curr = m_head;

  for(int i = 0; i < m_size; i++){

    //Checks for lower case. Subtracts the the cipherword and keyword
    //from the ASCII value for 'a'. Adds them together (off by 1 so add 1) 
    //mod by 26 and set that value as the character value.

    if(islower(curr->getChar())){
      
      number = ((curr->getChar()-'a') + (keyname[i]-'a') + 1) % ALPHA_LET;
                  
      curr->setChar(char(number+'a'));
      
      curr = curr->getNext();
      
    }
    
    //Checks for lower case. Subtracts the the cipherword and keyword                                                  //from the ASCII value for 'a'. Adds them together (off by 1 so add 1)                                             //mod by 26 and set that value as the character value. 
    else if(isupper(curr->getChar())){
      number = ((curr->getChar()-'A') + (keyname[i]-'a') + 1)%ALPHA_LET;

      curr->setChar(char(number+'A'));

      curr = curr->getNext();
    }
    
    //moves to the next node.
    else if(curr->getChar() == ' '){

      curr = curr->getNext();
    }
  }

  for(curr = m_head; curr != NULL; curr = curr->getNext()){

    cout << curr->getChar();
  }
  
}



// Name: decryptVigenere
// Preconditions - Linked list exists
// Postconditions - Shifts each character by the character (in string) provided
// See project document for additional details.
void CipherString::decryptVigenere(string key){

  const char *keyname = key.c_str();
  int number;
 
  Node *curr = m_head;

  for(int i = 0; i < m_size; i++){
    
    if(islower(curr->getChar())){
     
      // Changes the letter so that they are in the range from 0-25
      // and subtracts the cipherword and keyword. Subtracts one from that value
      // and mod by 26.

      number = ((curr->getChar()-'a') - (keyname[i]-'a') - 1)%ALPHA_LET;
      
      //Checks if the number is negative or not. If the number is negative
      //mod 26 will not work.

      if(number < 0){
	number = number +26;
      }

      //Adds it back to the offset to get the value of the character
      curr->setChar(char(number+'a'));                                                                                                 
      curr = curr->getNext();
    } 

    //Case for if the character is upper case. Same as for lower
    //except now the cipherword is being subtracted by 65 instead of 97
    else if(isupper(curr->getChar())){
     
      number = ((curr->getChar()-'A') - (keyname[i]-'a') - 1)%ALPHA_LET;

      if(number < 0){

        number = number +ALPHA_LET;

      }
      curr->setChar(char(number+'a'));

      curr = curr->getNext();
      
    }

    //Moves to the next node
    else if(curr->getChar() == ' '){

      curr = curr->getNext();
    }
    
    for(curr = m_head; curr != NULL; curr = curr->getNext()){

      cout << curr->getChar();
    }

  }
 
}
           
// Name: getSize
// Preconditions - Linked list exists
// Postconditions - Return size of structure
int CipherString::getSize(){

  return m_size;

}
  
// Name: operator<< (overloaded insertion operator)
// Preconditions - Linked list exists
// Postconditions - Iterates over the linked list and prints each char in each node
// In this case, friend means that it is accessible outside the class (like public)
ostream& operator <<(ostream& os, const CipherString& cipherword){

  Node *temp = cipherword.m_head;

  for(temp = cipherword.m_head; temp != NULL; temp = temp->getNext()){

    os << temp->getChar();

  }

  return os;
}


