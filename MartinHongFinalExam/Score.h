#pragma once
class Score
{
private:
	int score;
	int num;
public:
	Score(const int & s, const int & n) : num(n), score(s) {};
	~Score();
	int getNum() const { return num; }
	int getScore() const { return score; }
};

