#include <iostream>
using namespace std;

class student {
public:
	student();
	void CheckMarks();
	void CheckAtt();
};

class date {
	int day, mounth, year;
public:
	date(int x, int y, int z) {
		if (y > 0 && y < 13) mounth = y;
		if (z >= 2023 && z <= 2024) year = z;
		if (((y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) && x <= 31) || ((y == 4 || y == 6 || y == 9 || y == 11) && x <= 30) || (y == 2 && x <= 28)) day = x;
	}
};

class mark {
	student* student_;
	int value;
	string control, lesson;
public:
	mark(student* x, int y, string c, string l) {
		student_ = x; value = y; control = c; lesson = l;
	}
};

class att {
	student* student_;
	string lesson;
};

class teacher {
public:
	teacher();
	void CreateMark(student* x, int y, string c, string l);
	void CreateAtt();
	friend int Auth();
};
void teacher :: CreateMark(student* x, int y, string c, string l) {
	new mark(x, y, c, l);
}
class decan {
public:
	decan();
	void CheckMarks();
	void DeleteStudent();
	friend int Aut();
};

class lesson {
	string name;
public:
	lesson();
};

class group {
	student* arr;
public:
	group();
};

class stream {
	group* arr;
public:
	stream();
};

int main() {

}