#ifndef __STUDENT__HEADER__INCLUDED__
#define __STUDENT__HEADER__INCLUDED__

#include <string>
#include <fstream>

using std::string;
using std::istream;
using std::ostream;

struct Student
{
	string name;
	string subject;
	string date;
	unsigned short age;
	unsigned short grade;

	friend ostream& operator<<(ostream& out, const Student& data)
	{
		out << data.name << ',' << data.age << ',' << data.subject
			<< ',' << data.grade << ',' << data.date << '\n';
		return out;
	}

	friend istream& operator>>(istream& in, Student& data)
	{
		string age, grade;

		getline(in, data.name, ',');
		getline(in, age, ',');
		data.age = stoi(age);
		getline(in, data.subject, ',');
		getline(in, grade, ',');
		data.grade = stoi(grade);
		getline(in, data.date, '\n');
		return in;
	}

};



#endif // !__STUDENT__HEADER__INCLUDED__
