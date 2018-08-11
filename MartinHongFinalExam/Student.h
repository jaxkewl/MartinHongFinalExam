#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student
{
private:
	string first;
	string last;
	int num;
	vector<int> scores;
public:
	Student() {};
	Student(const string & f, const string & l, const int & n) : first(f), last(l), num(n) {};
	~Student();
	string getFirst() const { return first; }
	string getLast() const { return last; }
	int getNum() const { return num; }
	void addScore(const int & s)
	{
		scores.push_back(s);
	}
	int getAvg() {
		double total = accumulate(scores.begin(), scores.end(), 0.0);
		if (scores.size() > 0)
		{
			return total / scores.size();
		}
		return 0.0;
	}

	int getMax()
	{
		auto biggest = std::max_element(std::begin(scores), std::end(scores));
		return *biggest;
	}

	int getMin()
	{
		auto smallest = std::min_element(std::begin(scores), std::end(scores));
		return *smallest;
	}
};

