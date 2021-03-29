//////////////
// Time.h
//////////////

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Time
{
private:
	static int counter;
public:
	class Triad
	{
		int first;
		int second;
		int third;
		static int counter;
	public:
		int getFirst() const { return first; }
		int getSecond() const { return second; }
		int getThird() const { return third; }

		bool setFirst(int);
		bool setSecond(int);
		bool setThird(int);

		void Init(int firstValue, int secondValue, int thirdValue);
		void Display() const;
		void Read();
		const string toString();

		Triad();
		Triad(const int first, const int second, const int third);
		Triad(const Triad& m);
		~Triad(void);

		Triad& operator = (const Triad& m);

		friend ostream& operator << (ostream& out, const Triad& m);
		friend istream& operator >> (istream& in, Triad& m);

		operator string () const;

		Triad& operator ++ ();
		Triad& operator -- ();
		Triad operator ++ (int);
		Triad operator -- (int);

		bool h1(Triad t) const;
		bool h2(Triad t) const;
		bool m1(Triad t) const;
		bool m2(Triad t) const;
		bool s1(Triad t) const;
		bool s2(Triad t) const;

		double check();

		static int getCounter();
	};
	Triad getTriad() const { return t; }

	void setTriad(Triad tValue) { t = tValue; }

	void Init(Triad t);
	void Display() const;
	void Read();
	const string toString();

	Time(const int first = 0, const int second = 0, const int third = 0);
	Time(const Time& s);
	~Time(void);

	Time& operator = (const Time& s);

	friend ostream& operator << (ostream& out, const Time& s);
	friend istream& operator >> (istream& in, Time& s);

	operator string () const;

	Time& operator ++ ();
	Time& operator -- ();
	Time operator ++ (int);
	Time operator -- (int);

	bool h1(Time d) const;
	bool h2(Time d) const;
	bool m1(Time d) const;
	bool m2(Time d) const;
	bool s1(Time d) const;
	bool s2(Time d) const;

	static int getCounter();
private:
	Triad t;
};

