/*****************************************                                                                        File: Cipher.cpp                                                                                             
Name: Pearl Pongsuppat                                                                                            
Date: 11/02/2017                                                                                                  
Section: 04                                                                                                       
E-mail: ppongs1@umbc.edu                                                                                          
Project: CMSC 202 Project 3, Fall 2017                                                                            ****************************************** */
#include "CipherString.h"
#include "Cipher.h"

// Name: Cipher(char) - Overloaded constructor for Caesar cipher
// Preconditions - Caesar cipher is defined
// Postconditions - Constructor for the Caesar cipher (sets m_mode to CAESAR)
Cipher::Cipher(char cipherword){

  m_cipherString = NULL;
  m_mode = CAESAR;
  m_caesar_key = cipherword;
  
  
}



// Name: Cipher(string) - Overloaded constructor for Vigenere cipher
// Preconditions - Vigenere cipher is defined
// Postconditions - Constructor for the Vigenere cipher (sets m_mode to VIGENERE
Cipher::Cipher(string cipherword){
  
  m_cipherString = NULL;
  m_mode = VIGENERE;

  m_vig_key = cipherword;


}
    // Name: Cipher() - Overloaded constructor for Vigenere cipher
    // Preconditions - Ong Cipher is defined
    // Postconditions - Constructor for the Ong cipher (sets m_mode to ONG)
Cipher::Cipher(){

  m_cipherString = NULL;
  m_mode = ONG;
  

}

Cipher::~Cipher(){
  
  delete m_cipherString;

}


// Name: setPlainText
// Preconditions - File with text is available (in current directory)
// Postconditions - Stores file text in m_cipherString
void Cipher::setPlainText(string filename){

  const char *charfile = filename.c_str();
  cout << charfile << endl;
  m_cipherString = new CipherString(charfile);

}


// Name: encrypt
// Preconditions - m_cipherString populated
// Postconditions - Calls correct encryption function based on the cipher chosen
void Cipher::encrypt(){

  
  switch(m_mode){
  case 1:
    {
      
      m_cipherString->encryptCaesar(m_caesar_key);

    break;}
  
  case 2:
    {
       m_cipherString->encryptOng();

       break;
    }
    
  case 3:
    {
      m_cipherString->encryptVigenere(m_vig_key);

      break;
    }

  }
}
// Name: decrypt
// Preconditions - m_cipherString populated and encrypted
// Postconditions - Calls correct decryption function based on the cipher chosen
void Cipher::decrypt(){

  switch(m_mode){

  case 1:
    { m_cipherString->decryptCaesar(m_caesar_key);
      break;
    }

  case 2:
    { m_cipherString->decryptOng();
      break;
    }

  case 3:
    { m_cipherString->decryptVigenere(m_vig_key);
      break;}
  }

}

// Name: changeKey
// Preconditions - key exists
// Postconditions - Key is updated
void Cipher::changeKey(string){}


// Name: printString
// Preconditions - m_cipherString populated
// Postconditions - Outputs the value of m_cipherString
void Cipher::printString(){

  cout << *m_cipherString << endl;

  
}



