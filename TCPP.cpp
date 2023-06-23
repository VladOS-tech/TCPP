#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class user {
	string name_;
	string surname_;
	string patronymic_;
	string mail_;
	string password_;
public:
	user(string name, string surname, string patronymic, string mail, string password) {
		name_ = name; 
		surname_ = surname;
		patronymic_ = patronymic;
		mail_ = mail;
		password_ = password;
	}
	string name() const noexcept { return name_; }
	string surname() const noexcept { return surname_; }
	string patronymic() const noexcept { return patronymic_; }
	string mail() const noexcept { return mail_; }
	bool validatePassword(string password) const noexcept { return password_ == password; }
};

class student: public user {
public:
	student(string name, string surname, string patronymic, string mail, string password) : user(name, surname, patronymic, mail, password) {}
	void CheckMarks();
	void CheckAtt();
};
using student_t = shared_ptr<student>;

class date {
	int day, month, year;
public:
	date(int x, int y, int z) {
		if (y > 0 && y < 13) month = y;
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

class subject {
public:
	subject(string name, teacher* teacher) { name_ = name; teacher_ = teacher; }
	void add_group(shared_ptr<group> group) {
		if (contains_group(group)) throw runtime_error("Group is already in the subject");
		groups_.push_back(group);
	}

	void remove_group(const shared_ptr<group>& group) {
		for (auto it = groups_.begin(); it != groups_.end(); it++) {
			if (**it == *group) {
				groups_.erase(it);
				return;
			}
		}
		throw runtime_error("There isn't this group in the subject");
	}
	bool contains_group(const shared_ptr<group>& group) {
		for (int i = 0; i < groups_.size(); i++) {
			if (*groups_[i] == *group) {
				return true;
			}
		}
		return false;
	}
private:
	string name_;
	teacher* teacher_;
	vector<shared_ptr<group>> groups_;
};

class task {
public:
	enum type_t {
		LABWORK, TEST, HOMEWORK, PRACTIC, EXAM  
	};
	task(string name, type_t type) { name_ = name; type_ = type; }
	type_t type() const noexcept { return type_; }
	string name() const noexcept { return name_; }
private:
	string name_;
	type_t type_;
};

class group {
	vector<student_t> students;
public:
	bool operator==(const group& other);
	group();
};

class stream {
	group* arr;
public:
	stream();
};

int main() {

}