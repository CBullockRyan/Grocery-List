#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Items.h"
using namespace std;

class List{
	public:
		int ctr=0;
		int size=4;
		double total;
		Items *all = new Items[size];
		int run();
	private:
		Items fillItem();
		void addItem();
		void removeItem();
		void printMenu();
		void MoveUp(int index);
		void printList();
		bool checkSize();
		void doubleAll();
};

#endif