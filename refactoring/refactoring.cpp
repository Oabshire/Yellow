#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Human {
public:
	Human(const string & name, const string& job)
		:Name(name),
		Job(job) {}

	string GetName() const {
		return Name;
	}
	string GetJob() const {
		return Job;
	}

	virtual void Walk(const string& destination) const = 0;

protected:
	const string Name;
	const string Job;
};

class Student : public Human{
public:

	Student(const string& name, const string& favouriteSong) 
		:Human(name,"Student"),
		FavouriteSong(favouriteSong){
	}
	

	void Learn() const {
		cout << "Student: " << Name << " learns" << endl;
	}

	void Walk(const string& destination) const override {
		cout << "Student: " << Name << " walks to: " << destination << endl;
		SingSong();
	}

	void SingSong() const {
		cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
	}

public:
	const string FavouriteSong;
};


class Teacher : public Human {
public:

	Teacher(const string& name, const string& subject) 
		:Human(name,"Teacher"),
		Subject(subject){
	}

	void Teach() const {
		cout << "Teacher: " << Name << " teaches: " << Subject << endl;
	}

	 void Walk(const string& destination) const override {
		cout << "Teacher: " << Name << " walks to: " << destination << endl;
	}

private:
	const string Subject;
};


class Policeman : public Human{
public:
	Policeman(const string & name)
		:Human(name, "Policeman") {
	}

	void Check (const Human & person) const {
		cout << "Policeman: " << Name << " checks" << person.GetJob()<<"."<< person.GetJob()<<"'s name is: " << person.GetName ()<< endl;
	}

	void Walk(const string& destination) const override {
		cout << "Policeman: " << Name << " walks to: " << destination << endl;
	}
};


void VisitPlaces(const Human & person, vector<string> places) {
	for (auto p : places) {
		person.Walk(p);
	}
}



int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	system("pause");
	return 0;
}
