// MartinHongFinalExam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include "MyDate.h"
#include "Student.h"
#include "Score.h"
#include <map>
#include <iterator>



using namespace std;

void myfunction(MyDate & date) {  // function:
	std::cout << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
}

bool isOdd(MyDate n) {
	return (n.getDay() % 2) != 0;
}

int main()
{
	//QUESTION1
	vector<MyDate> dates;

	MyDate mydate1(2012, 12, 12);
	MyDate mydate2(2013, 12, 31);
	MyDate mydate3(2012, 10, 12);
	MyDate mydate4(2013, 6, 18);
	MyDate mydate5(2013, 4, 30);
	MyDate mydate6(2012, 9, 25);

	dates.push_back(mydate1);
	dates.push_back(mydate2);
	dates.push_back(mydate3);
	dates.push_back(mydate4);
	dates.push_back(mydate5);
	dates.push_back(mydate6);

	std::cout << "unsorted dates:" << endl;
	for_each(dates.begin(), dates.end(), myfunction);

	//sorting according to day
	std::sort(dates.begin(), dates.end());
	std::cout << "sorted dates:" << endl;
	for_each(dates.begin(), dates.end(), myfunction);

	//count odd numbers
	int n = count_if(dates.begin(), dates.end(), isOdd);
	cout << "Number of odd dates= " << n << endl;











	//QUESTION 4
	Student s1("Mona", "Chrome", 1);
	Student s2("Shagga", "Dellic", 2);
	Student s3("Sim", "Carder", 3);

	map<int, Student> students;
	students[1] = s1;
	students[2] = s2;
	students[3] = s3;

	vector<Score> scores;
	scores.push_back(Score(60, 1));
	scores.push_back(Score(90, 2));
	scores.push_back(Score(75, 3));
	scores.push_back(Score(90, 1));
	scores.push_back(Score(95, 2));
	scores.push_back(Score(85, 3));
	scores.push_back(Score(85, 1));
	scores.push_back(Score(80, 2));
	scores.push_back(Score(90, 3));
	scores.push_back(Score(60, 1));
	scores.push_back(Score(85, 2));
	scores.push_back(Score(70, 3));

	for (auto it = scores.begin(); it != scores.end(); it++) {
		students[it->getNum()].addScore(it->getScore());
	}

	//calculate average
	cout << "Student 1 avg: " << students[1].getAvg() << endl;
	cout << "Student 2 avg: " << students[2].getAvg() << endl;
	cout << "Student 3 avg: " << students[3].getAvg() << endl;

	//calculate min
	cout << "Student 1 min: " << students[1].getMin() << endl;
	cout << "Student 2 min: " << students[2].getMin() << endl;
	cout << "Student 3 min: " << students[3].getMin() << endl;

	//calculate max
	cout << "Student 1 max: " << students[1].getMax() << endl;
	cout << "Student 2 max: " << students[2].getMax() << endl;
	cout << "Student 3 max: " << students[3].getMax() << endl;

	return 0;
}

