/*********************************************************************  
** Program Filename: main_grocery.cpp 
** Author: Cassidy Bullock    
** Date: 6/29/2016  
** Description: This program allows the user to create a grocery list 
** 				where they can add items, remove items, print the list
** Input: none
** Output:  none
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include "Items.h"
#include "List.h"

using namespace std;

int main(){
	List grocery;
	grocery.run();
	return 0;
}