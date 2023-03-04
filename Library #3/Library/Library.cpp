#include <iostream>
#include <string>
#include <locale>
#include <regex>


#define TESTINGFUNC

using namespace std;


class Library {
private: 
	string name;
public:
	int SetName(string newName) {
		int error{ 0 };
		smatch n;
		if (regex_search(newName, n, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			name = newName;
			error = 0;
		}
		else {
			error = -1;
		}
		return error;
	}
	string getName() {
		return name;
	}
};

class Reader{
private:
	string name;
	string surname;
	bool sex;
	//1 = male; 0 = female
public:
	int setSurname(string newSurname) {
		smatch n;
		int error{ 0 };
		if (regex_search(newSurname, n, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			surname = newSurname;
			error = 0;
		}
		else {
			error = -1;
		}
		return error;
	}
	string getSurname() {
		return surname;
	}

	int setName(string newName) {
		smatch n;
		int error{ 0 };
		if (regex_search(newName, n, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			name = newName;
			error = 0;
		}
		else {
			error = -1;
		}
		return error;
	}
	string getName() {
		return name;
	}

	int setSex(bool curSex) {
		sex = curSex;
		return 0;
	}
	bool getSex() {
		return sex;
	}
};

class ReaderCard {
private:
	string readerSurname;
	int debt;
public:
	int setReaderSurname(string newSurname) {
		readerSurname = newSurname;
		return 0;
	}
	string getReaderSurname() {
		return readerSurname;
	}

	int setDebt(int newDebt) {
		int error{ 0 };
		if (newDebt < 1 || newDebt > 100) {
			error = -1;
		}
		else {
			debt = newDebt;
		}
		return error;
	}
	int getDebt() {
		return debt;
	}
};

class Publication {
private:
	string name;
	int year;
	int pubCount;
	string Author;
public:

	int setAuthor(string auth) {
		int error{ 0 };
		if (auth == "" or auth == " ") {
			error = -1;
		}
		else {
			Author = auth;
		}
		return error;
	}

	string getAuthor() {
		return Author;
	}

	int setName(string newName) {
		int error{ 0 };
		smatch m;
		if (regex_search(newName, m, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			error = 0;
			name = newName;
		}
		else {
			error = -1;
		}
		return error;
	}

	string getName() {
		return name;
	};


	int getYear() {
		return year;
	};


	int setYear(int newYear) {
		int error{ 0 };
		if (newYear < 1 || newYear > 2023) {
			error = -1;
		}
		else {
			year = newYear;
		}
		return error;
	}

	int getPubCount() {
		return pubCount;
	};
	int setPubCount(int pCount) {
		int error{ 0 };
		if (pCount < 0 or pCount > 100) {
			error = -1;
		}
		else {
			pubCount = pCount;
		}
		return error;
	}
};

class Book : public Publication {
private:
	string ISBN;
public:
	string getISBN() {
		return ISBN;
	};

	int setISBN(string isbn) {
		int error{ 0 };
		smatch n;
		if (regex_search(isbn, n, regex("^[0-9]{3}-[0-9]{1}-[0-9]{2,7}-[0-9]{2}-[0-9]{1}$"))) {
			error = 0;
			ISBN = isbn;
		}
		else {
			error = -1;
		}
		return error;
	}

};



class Newspaper: public Publication {
private:
	int number;
public:
	int setNumber(double number) {
		int error{ 0 };
		if (number < 1 or number > 10) {
			error = -1;
		}
		else {
			number = number;
		}
		return error;
	}

	int getNunmber() {
		return number;
	}
};


class Magazine: public Publication {
private: 
	int number;
	string ISSN;
public:
	int setNumber(int number) {
		int error{ 0 };
		if (number < 1 or number > 10) {
			error = -1;
		}
		else {
			number = number;
		}
		return error;
	}

	int getNunmber() {
		return number;
	}

	string getISSN() {
		return ISSN;
	};

	int setISSN(string issn) {
		int error{ 0 };
		smatch n;
		if (regex_search(issn, n, regex("^[0-9]{3}-[0-9]{1}-[0-9]{2,7}-[0-9]{2}-[0-9]{1}$"))) {
			error = 0;
			ISSN = issn;
		}
		else {
			error = -1;
		}
		return error;
	}
};

class Sbornik: public Publication{
private:
	string ISBN;
public:
	string getISBN() {
		return ISBN;
	};

	int setISBN(string isbn) {
		int error{ 0 };
		smatch n;
		if (regex_search(isbn, n, regex("^[0-9]{3}-[0-9]{1}-[0-9]{2,7}-[0-9]{2}-[0-9]{1}$"))) {
			error = 0;
			ISBN = isbn;
		}
		else {
			error = -1;
		}
		return error;
	}
};

//TESTING METHOD
void testNewspaperSetNumber(Newspaper obj) {
	//1 0 5 -1 2.3
	double curNumber{ 1 };
	if (obj.setNumber(curNumber) == 0) {
		cerr << "Test " << curNumber << " success!" << endl;
	}
	else {
		cerr << "Test " << curNumber << " failed!" << endl;
	}

	curNumber = 0;
	if (obj.setNumber(curNumber) == -1) {
		cerr << "Test " << curNumber << " success!" << endl;
	}
	else {
		cerr << "Test " << curNumber << " failed!" << endl;
	}

	curNumber = 5;
	if (obj.setNumber(curNumber) == 0) {
		cerr << "Test " << curNumber << " success!" << endl;
	}
	else {
		cerr << "Test " << curNumber << " failed!" << endl;
	}

	curNumber = -1;
	if (obj.setNumber(curNumber) == -1) {
		cerr << "Test " << curNumber << " success!" << endl;
	}
	else {
		cerr << "Test " << curNumber << " failed!" << endl;
	}

	curNumber = 2.3;
	if (obj.setNumber(curNumber) == -1) {
		cerr << "Test " << curNumber << " success!" << endl;
	}
	else {
		cerr << "Test " << curNumber << " failed!" << endl;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	Newspaper test;

#ifdef TESTINGFUNC
	testNewspaperSetNumber(test);
#endif
	
}													