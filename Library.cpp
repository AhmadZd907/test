#include<iostream>
using namespace std;

int bookids[100];
char booktitles[100][50];
char bookauthors[100][50];
bool isborrowed[100];
int bookcount = 0;

void addbook() {
	cout << " enter the booke id :";
	cin >> bookids[bookcount];

	cout << "enter the book title(no spaces) :";
	cin >> booktitles[bookcount];

	cout << "enter the book author (no spaces):";
	cin >> bookauthors[bookcount];

	isborrowed[bookcount] = false;

	cout << "book added successfully.\n";

	bookcount++;
}

void dispalybook() {
	if (bookcount == 0) {
		cout << "no books are available in the library.\n";
		return;
	}
	cout << "\n===book list ===\n";
	for (int i = 0; i < bookcount; i++) {
		cout << "ID:" << bookids[i]
		     << ", title: " << booktitles[i]
		     << ", author: " << bookauthors[i]
		     << ", status:" << (isborrowed[i] ? "borrowed" : "available") << "\n";
	}
	cout << "===============\n";
}

void borrowbook() {
	cout << "enter the book id to borrow: ";
	int id;
	cin >> id;
	for (int i = 0; i < bookcount; i++) {
		if (bookids[i] == id) {
			if (isborrowed[i]) {
				cout << "this book is alraedy borrowed.\n";
				return;
			}
			isborrowed[i] = true;
			cout << "book borrowed successfully.\n";
			return;
		}
	}
	cout << "no book found with the enterd id.\n";
}

void returnbook() {
	cout << "enter the book id to return: ";
	int id;
	cin >> id;
	for (int i = 0; i < bookcount; i++) {
		if (bookids[i] == id) {
			if (!isborrowed[i]) {
				cout << "this book was not borrowed.\n";
				return;
			}
			isborrowed[i] = false;
			cout << "book returned successfully.\n";
			return;
		}
	}
	cout << "no book found with the enterd id.\n";
}

void menu() {
	while (true) {
		cout << "\n == lidrary management systen ==\n";
		cout << "1. add a new book\n";
		cout << "2. display all books\n";
		cout << "3. boorow a book\n";
		cout << "4. return a book\n";
		cout << "5.exit\n";
		cout << "enter yoyr choice:";

		int choice;
		cin >> choice;
		switch (choice) {
			case 1:
				addbook();
				 break;
			case 2:
				dispalybook();
				 break;
			case 3:
				borrowbook();
			  	break;
			case 4:
				returnbook();
			  	break;
			case 5:
				 cout << "goodbye!\n";
				 return;
			default:
				cout << "invalid choice. please try again. \n";
			 }  
}    
}     
int main() {
	menu();
	return 0;
}     