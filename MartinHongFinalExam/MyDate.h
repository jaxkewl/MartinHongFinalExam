#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class MyDate
{

private:
	int year = 0;
	int month = 0;
	int day = 0;
	string rawStr = "";

public:
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }

	MyDate(const int & y, const int & m, const int & d);
	~MyDate();

	//brute force, better to have a weighting algorithm
	bool operator<(const MyDate &rhs) const
	{
		if (year > rhs.getYear())
		{
			return true;
		}
		else if (year < rhs.getYear())
		{
			return false;
		}
		else
		{
			if (month > rhs.getMonth())
			{
				return true;
			}
			else if (month < rhs.getMonth())
			{
				return false;
			}
			else
			{
				return day > getDay();
			}
		}

	}

	friend ostream &operator<<(ostream &output, const MyDate &myDate) {
		output << myDate.month << "/" << myDate.day << "/" << myDate.year;
		return output;
	}

	friend istream &operator >> (istream  &input, MyDate &myDate) {
		//string rawStr;
		input >> myDate.rawStr;

		// 04/08/1979
		string mm = myDate.rawStr.substr(0, 2);
		string dd = myDate.rawStr.substr(3, 2);
		string yyyy = myDate.rawStr.substr(6, 4);
		istringstream convert(mm);
		convert >> myDate.month;
		istringstream convert2(dd);
		convert2 >> myDate.day;
		istringstream convert3(yyyy);
		convert3 >> myDate.year;
		return input;
	}
};