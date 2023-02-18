#include <iostream>
#include <string>
#include <locale>
#include <regex>

#define DEBUG

using namespace std;


class Publication {
private:
	string name;
	int year;
public:
	int setName(string a) {
		int error{ 0 };
		smatch m;
		if (regex_search(a, m, regex("^[А-Я]{1}[а-я]{1,30}$"))){
			error = 0;
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


	int setYear(int curYear) {
		int error{ 0 };
		if (curYear < 1 || curYear > 2023 ) {
			error = -1;
		}
		else {
			year = curYear;
		}
		return error;
	}
};

//METHODTEST
void testPublicationSetYear(Publication obj) {
	//0 1 2024 -1 2021
	int curYear{ 1 };
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = 0;
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = 2024;
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = -1;
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = 2021;
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}
}

class Book : public Publication {
private:
	string ISBN;
	string Izd;
	int PubCount;
	string Author;
public:
	string getISBN() {
		return ISBN;
	};
	void setISBN(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			ISBN = a;
		}
	}
	string getIzd() {
		return Izd;
	};
	void setIzd(string a) {
		Izd = a;
	}
	int getPubCount() {
		return PubCount;
	};
	void setPubCount(int a) {
		if (a < 0 or a > 100) {
			cout << "Invalid param";
		}
		else {
			PubCount = a;
		}
	}
	string getAuthor() {
		return Author;
	};
	void setAuthor(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			Author = a;
		}
	}
};


class Magazine : public Publication {
private:
	string ISBN;
	string Izd;
	int PubCount;
	string Author;
	int Tom;
	int Number;
	bool Scoups;
	bool WoS;
	bool RINC;
public:
	string getISBN() {
		return ISBN;
	};
	void setISBN(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			ISBN = a;
		}
	}
	string getIzd() {
		return Izd;
	};
	void setIzd(string a) {
		
		Izd = a;
	}
	int getPubCount() {
		return PubCount;
	};
	void setPubCount(int a) {
		if (a < 0 or a > 1000) {
			cout << "Invalid param";
		}
		else {
			PubCount = a;
		}
	}
	string getAuthor() {
		return Author;
	};
	void setAuthor(string b) {
		Author = b;
	}
	int getTom() {
		return Tom;
	};
	void setTom(int a) {
		if (a < 0 or a > 10) {
			cout << "Invalid param";
		}
		else {
			Tom = a;
		}
	}
	int getNumber() {
		return Number;
	};
	void setNumber(int a) {
		Number = a;
	}
	bool getScoups() {
		return Scoups;
	};
	void setScoups(bool a) {
		Scoups = a;
	}
	bool getWoS() {
		return WoS;
	};
	void setWoS(bool a) {
		WoS = a;
	}
	bool getRINC() {
		return RINC;
	};
	void setRINC(bool a) {
		RINC = a;
	}
};

class Article : public Magazine {
private:
	string Author;
	int Pstart;
	int Pend;
	bool Status;
public:
	string getAuthor() {
		return Author;
	};
	void setAuthor(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			Author = a;
		}
	}
	int getPstart() {
		return Pstart;
	};
	void setPstart(int a) {
		Pstart = a;
	}
	int getPend() {
		return Pend;
	};
	void setPend(int a) {
		Pend = a;
	}
	bool getStatus() {
		return Status;
	};
	void setStatus(bool a) {
			Status = a;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	Publication test;

#ifdef DEBUG
	testPublicationSetYear(test);
#endif
	cerr << test.setName("Малик");
}