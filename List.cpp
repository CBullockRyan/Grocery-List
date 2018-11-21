/*********************************************************************  
** Program Filename: List.cpp 
** Author: Cassidy Bullock    
** Date: 6/29/2016  
** Description: This contains the source code for the class List which
**				runs the operations for creating a grocery list
** Input: none
** Output:  none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "List.h"
#include "Items.h"

using namespace std;

/*********************************************************************  
** Function: checkSize  
** Description: checks the max size of the array against how many items
**				are already in the array 
** Parameters: none
** Pre-Conditions: ctr and size must be defined 
** Post-Conditions: returns true when the counter is the same as the size
**					as the array 
*********************************************************************/
bool List::checkSize(){
	if(ctr==size){
		return 1;
	}
	else
		return 0;
}

/*********************************************************************  
** Function: doubleAll
** Description: if the array is too small to hold another item, the
**				array size will be doubled
** Parameters:  none
** Pre-Conditions: the checkSize must have returned true 
** Post-Conditions: the array size will be doubled 
*********************************************************************/
void List::doubleAll(){
	bool increase;
	Items *temp_all;
	int temp_size=2*size;
	increase=checkSize();
	if(increase==1){
		temp_all= new Items[temp_size];
		for(int i=0; i<size; i++){
			temp_all[i]=all[i];
		}
		delete[] all;
		all=temp_all;
		size=temp_size;
	}
}

/*********************************************************************  
** Function:  run
** Description:  the public function which other files can access that
**				runs all all the functions in this class. Keeps everything
**				operating smoothly
** Parameters:  none
** Pre-Conditions:  must be called	
** Post-Conditions:  takes user inputs and calls relevant functions
*********************************************************************/
int List::run(){
	int option=0;
	while(option!=4){
		doubleAll();
		printMenu();
		cin>>option;
		if(option!=1 && option!=2 && option!=3 && option!=4){
			while(option!=1 && option!=2 && option!=3 && option!=4){
				cout<<"Please enter a number."<<endl;
				cin.clear();
				cin.ignore();
				cin>>option;
			}
		}
		if(option==1){
			addItem();
		}
		else if(option==2){
			removeItem();
		}
		else if(option==3){
			printList();
		}
	}
}

/*********************************************************************  
** Function:  printMenu
** Description:  prints out the menu options for the user and calculates
**				the total price
** Parameters:  none
** Pre-Conditions:  user must not have selected quit previously
** Post-Conditions:  prints menu
*********************************************************************/
void List::printMenu(){
	cout<<endl<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"This is the Grocery List Menu. Would you like to"<<endl;
	cout<<"1. Add an item"<<endl;
	cout<<"2. Remove an item"<<endl;
	cout<<"3. Print the list"<<endl;
	cout<<"4. Quit"<<endl;
	total=0;
	for(int i=0; i<400; i++){
		total=total+all[i].subtotal;
	}
	cout<<"The total price of this shopping trip is $"<<total<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl<<endl;
}

/*********************************************************************  
** Function:  MoveUp
** Description: moves all of the items in the array up one from a certain spot 
** Parameters:  int index
** Pre-Conditions: needs to know the index where an item got deleted  
** Post-Conditions:  moves everything to fill the gap
*********************************************************************/
void List::MoveUp(int index){
	ctr--;
	int i;
	for(i=index;i<(size-1);i++){
		all[i]=all[i+1];
		
	}
}

/*********************************************************************  
** Function:  printList
** Description:  prints every item in the array with its properties
** Parameters:  none
** Pre-Conditions:  there must be items in the array
** Post-Conditions: prints the list 
*********************************************************************/
void List::printList(){
	cout<<"The items on your list are:"<<endl;
	for(int i=0; i<ctr; i++){
		cout<<all[i].amount<<' '<<all[i].unit<<" of "<<all[i].name<<" for $"<<all[i].price<<" each"<<endl;
		cout<<"Therefore $"<<all[i].subtotal<<" for "<<all[i].name<<endl;
	}
	cout<<"The total cost is $"<<total<<endl;
}

/*********************************************************************  
** Function:  removeItem
** Description:  asks the user what item to remove then searches for it
**				and takes it out
** Parameters:  none
** Pre-Conditions:  there must be something to remove
** Post-Conditions:  that item will no longer be in the array
*********************************************************************/
void List::removeItem(){
	string temp;
	cout<<"What would you like to remove? ";
	cin>>temp;
	for(int i=0; i<size; ++i){
		if(temp==all[i].name){
			MoveUp(i);
		}
	}
}

/*********************************************************************  
** Function:  fillItem
** Description:  asks the user for the information about the item
** Parameters:  none
** Pre-Conditions: user must have requested to add an item 
** Post-Conditions:  information for the new item is returned
*********************************************************************/
Items List::fillItem(){
	Items next;
	cout<<"What is your next item? ";
	cin.ignore();
	getline(cin,next.name);
	cout<<"What unit is this item? (ounce, can, pound, etc) ";
	cin>>next.unit;
	cout<<"How many "<<next.unit<<" of "<<next.name<<" do you need? ";
	cin>>next.amount;
	cout<<"What is the price of 1 "<<next.unit<<" of "<<next.name<<"? ";
	cin>>next.price;
	next.subtotal=next.price*next.amount;
	return next;
}

/*********************************************************************  
** Function:  addItem
** Description:  adds a new item to the array
** Parameters: none 
** Pre-Conditions:  there must be room in the array
** Post-Conditions:  the new item will be added to the array
*********************************************************************/
void List::addItem(){
	all[ctr]=fillItem();
	ctr++;
}
