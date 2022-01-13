#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

struct Student
{
	string name;
	int score;

	bool operator< (const Student& s) 
	{
		return score != s.score ? score > s.score : name < s.name;
	}

	friend ostream& operator<< (ostream& os, const Student& s)
	{
		os << "Student: " << s.name << "; Score: " << s.score << endl;
		return os;
	}
};

#endif // !STUDENT_H
