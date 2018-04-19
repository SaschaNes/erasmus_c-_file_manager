/* Author: Sascha Nesterovic
	   Stefan Zivotic

   Date:   2018-04-15

   Addition:
	   C++ File Manager
			    */

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void printCopy() {
	cout << "____________________________________" << endl;
	cout << "Copyright (C) 2018 Sascha Nesterovic" << endl;
	cout << "	  (C) 2018 Stefan Zivotic   " << endl;
	cout << "____________________________________" <<endl;
}

void printMenu() {
	cout << endl;
	cout << "C++ Minimal File Manager" << endl;
	cout << "***********************************" << endl;
	cout << "1 Create file" << endl;
	cout << "2 Create folder" << endl;
	cout << "3 Rename file/folder" << endl;
	cout << "4 Delete file/folder" << endl;
	cout << "9 Quit File Manager" <<endl;
	cout << "***********************************" << endl;
}

char input(char in) {
	cout << "Insert your choice from the list above: ";
	cin >> in;
	return in;
}

char createFile(char name) {
	char make = 'touch ' + name;
	static_cast<const char>(make);
	system(make);
}

char createFolder(char name) {
	char make = 'mkdir ' + name;
	static_cast<const char>(make);
	system(make);
}

char rename(char nO, char nN) {
	char make = 'mv ' + nO + nN;
	static_cast<const char>(make);
	system(make);
}

char remove(char nameDel) {
	char del = 'rm -R ' + nameDel;
	static_cast<const char>(del);
	system(del);
}

void whatToDo(char in) {
	cout << endl;
	cout << endl;
	char name;
	switch(in) {
		case '1':
			cout << "Type in your filename: ";
			cin >> name;
			createFile(name);
			break;
		case '2':
			cout << "Type in your foldername: ";
			cin >> name;
			createFolder(name);
			break;
		case '3':
			char nameOld;
			cout << "Type your old folder-/filename: ";
			cin >> nameOld;
			char nameNew;
			cout << "Type in your new folder-/filename: ";
			cin >> nameNew;
			rename(nameOld,nameNew);
			break;
		case '4':
			char nameDel;
			cout << "Type your folder-/filename you want to delete: ";
			cin >> nameDel;
			remove(nameDel);
			break;
		case '9':
			return 1;
		default:
			cout << "Invalid option!";
			input(in);
			whatToDo(input);
	}
}


int main() {
	printCopy();
	printMenu();
	char wahl;
	input(wahl);
	whatToDo(wahl);
}
