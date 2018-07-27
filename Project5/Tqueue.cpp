#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int size(); //Returns size of queue
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****

//Name: Tqueue - Default Constructor                                                                   
//Precondition: None (Must be templated)                                                               
//Postcondition: Creates a queue using dynamic array 
template <class T, int N>
Tqueue<T,N>::Tqueue(){

  m_front = 0;
  m_back = 0;
  m_data = new T [N];

}

//Name: Copy Constructor                                                                               
//Precondition: Existing Tqueue                                                                        
//Postcondition: Copies an existing Tqueue 
template <class T, int N>
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ){

  //Makes a copy of an existing instance of an object

  m_data = new T[N];

  m_front = 0;

  m_back = N;

  for(int i = 0; i < N; i++){
    
    m_data[i] = x.m_data[i];
  }
}

//Name: Destructor                                                                                     
//Precondition: Existing Tqueue                                                                        
//Postcondition: Destructs existing Tqueue                                                             
//Destructor  
template <class T, int N>
Tqueue<T,N>::~Tqueue(){

  delete [] m_data;
  m_data = NULL;

}

//Name: enqueue                                                                                        
//Precondition: Existing Tqueue                                                                        
//Postcondition: Adds item to back of queue  
template <class T, int N>
void Tqueue<T,N>::enqueue(T data){

  m_data[m_back] = data;

  m_back++;

}

//Name: dequeue                                                                                        
//Precondition: Existing Tqueue                                                                        
//Postcondition: Removes item from front of queue   
template <class T, int N>
void Tqueue<T,N>::dequeue(T & queueMusic){

  queueMusic = m_data[m_front];
  
  m_front++;

}

//Name: queueFront                                                                                     
//Precondition: Existing Tqueue                                                                        
//Postcondition: Retrieve front (does not remove it)   
template <class T, int N>
void Tqueue<T,N>::queueFront(T & queueData){

  queueData = m_data[m_front];

}

//Name: isEmpty                                                                                        
//Precondition: Existing Tqueue                                                                        
//Postcondition: Returns 1 if queue is empty else 0  
template <class T, int N>
int Tqueue<T,N>::isEmpty(){

  int queueSize;

  queueSize = size();
  
  //Returns empty
  if(queueSize == 0){

    return 1;
  }
  
 
  else{
    
    return 0; 
  }
}

//Name: isFull                                                                                         
//Precondition: Existing Tqueue                                                                        
//Postcondition: Returns 1 if queue is full else 0   
template <class T, int N>
int Tqueue<T,N>::isFull(){

  int queueSize2;

  queueSize2 = size();

  //Returns full
  if(queueSize2 == N){

    return 1;
  }

  else{

    return 0;
  }
}

//Name: size                                                                                           
//Precondition: Existing Tqueue                                                                        
//Postcondition: Returns size of queue 
template <class T, int N>
int Tqueue<T,N>::size(){

  int queueSize = 0;

  if(m_front > m_back){
    
    queueSize = m_front - m_back;
  }
  
  else{

    queueSize = m_back - m_front;
  }
  return queueSize; 
}

//Name: Overloaded assignment operator                                                                 
//Precondition: Existing Tqueue                                                                        
//Postcondition: Sets one Tqueue to same as a second Tqueue using = 
template <class T, int N>
Tqueue<T,N> & Tqueue<T,N>::operator=( Tqueue<T,N> y){

  //Allows you to assign one object to another

  m_data = new T[N];

  m_front = 0;

  m_back = N;

  for(int i = 0; i < N; i++){

    m_data[i] = y.m_data[i];
  }
  
  //pointer to the current object
  return *this;
}

//Name: Overloaded [] operator                                                                         
//Precondition: Existing Tqueue                                                                        
//Postcondition: Returns object from Tqueue using [] 
template <class T, int N>
T&Tqueue<T,N>::operator[] (int x){

  return m_data[x];

}

#endif
