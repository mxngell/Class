#include <iostream>
#include <string>
#include <locale>
#include <regex>

//#define DEBUG

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
			name = a;
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
	void setISBN(string isbn) {
		if (isbn == "" or isbn == " ") {
			cout << "Invalid param";
		}
		else {
			ISBN = isbn;
		}
	}
	string getIzd() {
		return Izd;
	};
	void setIzd(string izd) {
		Izd = izd;
	}
	int getPubCount() {
		return PubCount;
	};
	void setPubCount(int pCount) {
		if (pCount < 0 or pCount > 100) {
			cout << "Invalid param";
		}
		else {
			PubCount = pCount;
		}
	}
	string getAuthor() {
		return Author;
	};
	void setAuthor(string auth) {
		if (auth == "" or auth == " ") {
			cout << "Invalid param";
		}
		else {
			Author = auth;
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
	void setISBN(string isbn) {
		if (isbn == "" or isbn == " ") {
			cout << "Invalid param";
		}
		else {
			ISBN = isbn;
		}
	}
	string getIzd() {
		return Izd;
	};
	void setIzd(string izd) {
		Izd = izd;
	}
	int getPubCount() {
		return PubCount;
	};
	void setPubCount(int pCount) {
		if (pCount < 0 or pCount > 1000) {
			cout << "Invalid param";
		}
		else {
			PubCount = pCount;
		}
	}
	string getAuthor() {
		return Author;
	};
	void setAuthor(string auth) {
		Author = auth;
	}
	int getTom() {
		return Tom;
	};
	void setTom(int tom) {
		if (tom < 0 or tom > 10) {
			cout << "Invalid param";
		}
		else {
			Tom = tom;
		}
	}
	int getNumber() {
		return Number;
	};
	void setNumber(int num) {
		Number = num;
	}
	bool getScoups() {
		return Scoups;
	};
	void setScoups(bool scoups) {
		Scoups = scoups;
	}
	bool getWoS() {
		return WoS;
	};
	void setWoS(bool wos) {
		WoS = wos;
	}
	bool getRINC() {
		return RINC;
	};
	void setRINC(bool rinc) {
		RINC = rinc;
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
	void setAuthor(string auth) {
		if (auth == "" or auth == " ") {
			cout << "Invalid param";
		}
		else {
			Author = auth;
		}
	}
	int getPstart() {
		return Pstart;
	};
	void setPstart(int pStart) {
		Pstart = pStart;
	}
	int getPend() {
		return Pend;
	};
	void setPend(int pEnd) {
		Pend = pEnd;
	}
	bool getStatus() {
		return Status;
	};
	void setStatus(bool status) {
			Status = status;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	Publication test;

#ifdef DEBUG
	testPublicationSetYear(test);
#endif

	cerr << test.setName("Малик") << endl;
}