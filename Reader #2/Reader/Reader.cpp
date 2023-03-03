#include <iostream>
#include <string>
#include <locale>
#include <regex>


#define TESTINGFUNC

using namespace std;

class Human {
private:
	string imagination;
	bool sex;
	string name;
public:
	int setSex(bool curSex) {
		sex = curSex;
		return 0;
	}
	bool getSex() {
		return sex;
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

	int setImagination(string curImagination) {
		imagination = curImagination;
		return 0;
	}
	string getImagination() {
		return imagination;
	}
};

class Book {
private:
	string author;
	string ISBN;
	string name;
public:
	int setAuthor(string auth) {
		int error{ 0 };
		if (auth == "" or auth == " ") {
			error = -1;
		}
		else {
			author = auth;
		}
		return error;
	}

	string getAuthor() {
		return author;
	}

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
};


class Proisvedenie {
private:
	string author;
	string name;
public:
	int setAuthor(string auth) {
		int error{ 0 };
		if (auth == "" or auth == " ") {
			error = -1;
		}
		else {
			author = auth;
		}
		return error;
	}

	string getAuthor() {
		return author;
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

};

//TESTING METHOD
void testBookSetISBN(Book obj) {
	string curISBN{ "123-21-321-33" };
	if (obj.setISBN(curISBN) == 0) {
		cerr << "Test " << curISBN << " success!" << endl;
	}
	else {
		cerr << "Test " << curISBN << " failed!" << endl;
	}
	curISBN = "1233-2211-3321";
	if (obj.setISBN(curISBN) == 0) {
		cerr << "Test " << curISBN << " success!" << endl;
	}
	else {
		cerr << "Test " << curISBN << " failed!" << endl;
	}
	curISBN = "623-2-332-23-1";
	if (obj.setISBN(curISBN) == 0) {
		cerr << "Test " << curISBN << " success!" << endl;
	}
	else {
		cerr << "Test " << curISBN << " failed!" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	
#ifdef TESTINGFUNC
	Book test;
	testBookSetISBN(test);
#endif
	return 0;
}