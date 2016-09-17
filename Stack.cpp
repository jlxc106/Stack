//Stack.cpp
//Written by Jay Lim
//September 15, 2016

#include <stdio.h>
#include <iostream>
#include "Stack.h"

using namespace std;

/*
The Stack is a Last-In, First-Out(LIFO)
type data structure
*/

template <typename T> class Stack{
public:
	int size;
	node<T> *top;
	node<T> *temp;

	//default constructor
	Stack(){
		size=0;
		top = NULL;
	}
	
	//destructor
	~Stack(){
		if(top -> back != NULL)
		{
			temp = top ->back;
			delete top;
			top = temp;
		}
		delete top;
		top = NULL;	
	}
	
	/*
	Function: push
	Parameters: User input variable T.
	Description: Adds a new node with variable T to the top of the stack.
		Updates the pointer top and establishes a connection between 
		the old top and new top node.
	Returns: void
	*/
	void push(T unit){
		if(size==0)
		{
			top = new node<T>;
			top ->back = NULL;
			top ->front = NULL;
			top -> nodeData = unit;
			
		}
		else
		{
			top -> front = new node<T>;
			//temporarily store current top as temp
			temp = top;
			top -> front -> nodeData = unit;
			top = top ->front;
			top -> back = temp;
		}
		size++;
//cout<< "POP! size: " <<size <<" top: " << top << " top's back: " << top->back<< " top's front: " << top-> front<<" top's Data: " << top->nodeData << endl;
	}

	/*
	Function: pop
	Parameters: void
	Description: Removes the node at the top of the stack. Updates the pointer
		top and deletes the old 
	Returns: void
	*/
	void pop(){
		if(size!=0)
		{
			temp = top;
			top = temp -> back;
			temp -> back = NULL;
			delete temp;
			top ->front = NULL;
			temp = NULL;
			size--;
//cout<< "POP! size: " <<size <<" top: " << top << " top's back: " << top->back<< " top's front: " << top-> front<<" top's Data: " << top->nodeData << endl;
		}
	}

	/*
	Function: search
	Parameters: User input variable key
	Description: Iterates through the stack using a temp pointer to search
		for a node with data value of key.
	Returns: pointer to queried node
	*/
	node<T> *search(T key){
		temp = top;
		for(int j =0; j < size; j++)		
		{
			if(temp -> nodeData == key)
			{
				return temp;
			}
			else temp = temp -> back;
		}
	}

	/*
	Function: empty
	Parameters: void
	Description: Returns true if Stack is empty, false if Stack has an element.
	Returns: bool
	*/
	bool empty(){
		if(size == 0)
			return true;
		return false;
	}

	/*
	Function: totalSize()
	Parameters: void
	Description: returns the size of the stack
	Returns: int size of the stack
	*/
	int totalSize(){
		return size;
	}
	
	/*
	Function: top_Stack
	Parameters: void
	Description: Returns the pointer to the top of the stack
	Returns: pointer to the node at top of the stack
	*/

	node<T> *top_Stack(){
		return top;
	}
};


int main()
{
	Stack<int> s;
	for(int i = 0; i < 10; i++)
	{
		s.push(i);
	}
	s.pop();
	s.search(0);
}

