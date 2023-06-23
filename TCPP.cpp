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
//void teacher :: CreateMark(student* x, int y, string c, string l) {
//	new mark(x, y, c, l);
//}

class decan {
public:
	decan();
	void CheckMarks();
	void DeleteStudent();
	friend int Aut();
};

class group {
public:
	bool operator==(const group& other) { return this->name_ == other.name_; }
	group(string name) { name_ = name; }
	string name() const noexcept {
		return name_;
	}
	void add_student(student_t student) {
		if (contains_student(student)) throw runtime_error("Student is already in the group");
		students_.push_back(student);
	}

	void remove_student(const shared_ptr<student>& student) {
		for (auto it = students_.begin(); it != students_.end(); it++) {
			if (it->get()->mail() == student->mail()) {
				students_.erase(it);
				return;
			}
		}
		throw runtime_error("There isn't this student in the group");
	}

	bool contains_student(const student_t& student) {
		for (int i = 0; i < students_.size(); i++) {
			if (students_[i]->mail() == student->mail()) {
				return true;
			}
		}
		return false;
	}
private:
	vector<student_t> students_;
	string name_;
};
using group_t = shared_ptr<group>;

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

	const vector<shared_ptr<task>>& get_task() const {
		return tasks_;
	}

	void add_task(task t) {
		tasks_.push_back(make_shared<task>(t));
	}
private:
	string name_;
	teacher* teacher_;
	vector<shared_ptr<group>> groups_;
	vector<shared_ptr<task>> tasks_;
};

class mark {
	student_t student_;
	int value_;
	task* task_;
public:
	mark(student_t student, int value, task* task) {
		student_ = student; value_ = value; task_ = task;
	}
	const student_t& student() const noexcept {
		return student_;
	}
	int value() const noexcept {
		return value_;
	}
};

class stream {
public:
	stream(string name) { name_ = name; }
	bool operator==(const stream& other) { return this->name_ == other.name_; }
	string name() const noexcept {
		return name_;
	}
	void add_group(group_t group) {
		if (contains_group(group)) throw runtime_error("Group is already in the stream");
		groups_.push_back(group);
	}

	void remove_group(const shared_ptr<group>& group) {
		for (auto it = groups_.begin(); it != groups_.end(); it++) {
			if (it->get()->name() == group->name()) {
				groups_.erase(it);
				return;
			}
		}
		throw runtime_error("There isn't this group in the stream");
	}

	bool contains_group(const group_t& group) {
		for (int i = 0; i < groups_.size(); i++) {
			if (groups_[i]->name() == group->name()) {
				return true;
			}
		}
		return false;
	}
private:
	vector<group_t> groups_;
	string name_;
};

int main() {

}