/********************************************
 ** File: proj1.cpp
 ** Project: CMSC 202 Project 1, Fall 2017
 ** Author: Pearl Pongsuppat
 ** Date:  September 19, 2017
 ** Section: 04 
 ** E-mail: ppongs1@umbc.edu
 **
 ** This file contains the program 
*********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const char* FILE_NAME = "proj1_items.txt";
const char* OUT_FILE = "proj1_output.txt";
const int NUM_ITEMS = 10; 
const int NUM_COLS = 2;
const int NUM_ORDERS = 3;
const double TAX_RATE = .06;
const int SET_SPACE = 10;
const int SET_LARGE = 25;
const int SET_SMALL = 5;

// Function name: mainMenu
// Pre-condition: Prompts the user with menu options
// Post-condition: Returns their option and passes it to menuChoice()         
int mainMenu();

// Function name: menuChoice                                                                                  // Pre-condition: Prompt's the user with the main menu options.                                               // Post- condition: Loads in text file to display menu and executes menu options                                                                                                      
void menuChoice(int);

// Function name: loadTable
// Pre-condition: Accepts two arrays as parameters, one to store the names of the food as strings,
// and another that stores the prices as doubles.
// Post-condition: Reads in the textfile and stores the contents into respected 
// arrays.
void loadTable(double[],string[]);

// Function name: manageOrder
// Pre-Condition: Contains the 2D array of the user's food order as well as the 
// arrays for the food names and food prices.
// Post-Condition: Prints out the user's order by iterating through the arrays. Calculates
// subtotal, tax, and overall total. Opens a separate textfile to write and save the receipt 
void manageOrder(double[][NUM_COLS],double[],string[]);


int main(){
  
  int userChoice = mainMenu();

  menuChoice(userChoice);
  
  return 0;
    }

int mainMenu(){
  
  int userNum;
  cout << "Welcome to the True Grit Snack Bar" << endl;
  cout << "What would you like to do?\n"<< "1. New Order\n" << "2. View Receipts\n"<< "3. Exit"<<endl;
  cin>> userNum;

  while(userNum < 0 || userNum > NUM_ORDERS){				
    cout << "Sorry that is invalid\n" << "What would you like to do?\n"<< "1. New Order\n" << "2. View Receipts\n"<< "3. Exit"<<endl;
    cin >> userNum;
  }
  return userNum;
}

void menuChoice(int userChoice){

  
  string foodName[NUM_ITEMS];
  double foodPrice[NUM_ITEMS];
  double foodOrder[NUM_ORDERS][NUM_COLS];
  string addMore;
  int j = 0;

  loadTable(foodPrice,foodName);

  switch(userChoice){
  case 1:

    do{
      // Displays the menu to the menu to the user

      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);

      cout << setw(SET_SPACE) << "Number " << setw(SET_LARGE) << "Item " << setw(SET_SPACE) << "Price" << endl;
      for(int i = 0; i < NUM_ITEMS; i++){
	cout << setw(SET_SPACE) << i+1 << setw(SET_LARGE) << foodName[i] << setw(7) << "$"<<foodPrice[i] << endl;                }
	
	// Asks the user which food item they want to purchase and the quantity of the item.
	// Stores information into 2D array.
        // Validates that the user has chosen an item between 1-10 
	
	cout << "What would you like to buy?" << endl;
	cin >> foodOrder[j][0];

	if (foodOrder[j][0] > 0 && foodOrder[j][0] <= NUM_ITEMS){ 
	  do{
	  cout << "How many would you like to buy?" << endl;
       	  cin >> foodOrder[j][1];

	  }while(foodOrder[j][1] < 0);

	  if (j < NUM_COLS){
	  cout << "Do you want to add more items? (y/n): " << endl;
	  cin >> addMore;
	  }
	  j++;
	}
      
    }while(addMore != "n" && j < NUM_ORDERS);
    
    manageOrder(foodOrder,foodPrice,foodName);
    
    break;
    
  case 2:
    {  
      // Reads in receipt from text file. 
      
      string myline;
      ifstream myinputstream;
      myinputstream.open(OUT_FILE);
      while(getline(myinputstream,myline)) {
	cout << myline << endl;
      }
        
      myinputstream.close();
      int usernum = mainMenu();
      menuChoice(usernum);
      break;
    }
  case 3:
    {
      // Exits program 

      cout << "Thank you for using True Grit Snack Bar" << endl;
      break; 
    }
  }	  
}		  

void loadTable(double foodPrice[], string foodName[]){
  
  // Opens project 1 textfile and reads through each line to store the food item
  // in foodName[] and prices into foodPrice[]. 
  ifstream inputstream;
  inputstream.open(FILE_NAME);
  
  for(int i = 0; i < NUM_ITEMS;i++){
    getline(inputstream,foodName[i],',');
    inputstream >> foodPrice[i];
    if (inputstream.peek() == '\n')
      inputstream.ignore();
  }
  inputstream.close();
}		  

void manageOrder(double foodOrder[][NUM_COLS], double foodPrice[],
		 string foodName[]){
   
  double subtotal = 0;
  double tax;
  double total;
  int index;
  ofstream outFile(OUT_FILE);
  
  // Opens file to store receipt information
  if(outFile.is_open()) {
  cout << "Your order: " << endl;
  outFile << "Your Order: " << '\n';

  cout << setw(SET_SMALL) << "QNTY " << setw(SET_LARGE) << "Item" << setw(SET_SPACE) << "Price." << endl;
  outFile << setw(SET_SMALL) << "QNTY " << setw(SET_LARGE) << "Item" << setw(SET_SPACE) << "Price."<< '\n';

  // Iterates through 2D array and outputs the quanitity, food item, and price 
  // Also stores information into separate text file

  outFile.setf(ios::fixed);
  outFile.setf(ios::showpoint);
  outFile.precision(2);

     for(int j = 0; j < NUM_ORDERS; j++){
       index = foodOrder[j][0];
       if(index > 0){
	 cout << setw(SET_SMALL) << foodOrder[j][1] << setw(SET_LARGE) << foodName[index - 1] <<
	   setw(8) << "$"<< foodPrice[index - 1] << endl;

	 outFile << setw(SET_SMALL) << foodOrder[j][1] << setw(SET_LARGE) << foodName[index - 1] <<
	   setw(SET_SPACE) << "$"<< foodPrice[index - 1] << '\n';

	 subtotal = subtotal + (foodOrder[j][1] * foodPrice[index-1]);    
       }
    }
  }
  
  // Calculates and outputs subtotal, tax, and total to interface and file.
  tax = subtotal * TAX_RATE;
  total = subtotal + tax;
  
  
  cout << "Subtotal: $" << subtotal << endl;
  outFile << "Subtotal: $" << subtotal << '\n';

  cout << "Tax: $" << tax << endl;
  outFile << "Tax: $" << tax << '\n';

  cout << "Total: $" << total << endl;
  outFile << "Total: $" << total << '\n';

  cout << "Receipt written." << endl;
  outFile << "Receipt written." << '\n';

  outFile.close();
 
  int usernum = mainMenu();
  menuChoice(usernum);
}


										      
