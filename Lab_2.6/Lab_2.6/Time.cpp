//////////////
// Time.cpp
//////////////

#include "Time.h"
#include <sstream>

using namespace std;

///////////////
/// class Time

int Time::counter = 0;

void Time::Init(Triad dValue)
{
	setTriad(dValue);
}

void Time::Display() const
{
	t.Display();
}

void Time::Read()
{
	Triad tValue;

	tValue.Read();

	Init(tValue);
}

const string Time::toString()
{
	stringstream sout;

	sout << t.toString();

	return sout.str();
}

Time::Time(const int first, const int second, const int third)
	: t(first, second, third)
{
	Time::counter++;
}

Time::Time(const Time& s)
{
	t = s.t;
	Time::counter++;
}

Time::~Time(void)
{
	Time::counter--;
}

Time& Time::operator = (const Time& s)
{
	t = s.t;

	return *this;
}

Time::operator string () const
{
	stringstream ss;
	ss << "t = " << t << endl;

	return ss.str();
}

ostream& operator << (ostream& out, const Time& s)
{
	out << string(s);

	return out;
}

istream& operator >> (istream& in, Time& s)
{
	cout << endl;
	cout << "t = ? "; in >> s.t;

	return in;
}

Time& Time::operator ++ ()
{
	++t;
	return*this;
}

Time& Time::operator -- ()
{
	--t;
	return*this;
}

Time Time::operator ++ (int)
{
	Time s(*this);
	t++;
	return*this;
}

Time Time::operator -- (int)
{
	Time s(*this);
	t--;
	return*this;
}

bool Time::h1(Time d) const
{
	return t.h1(d.getTriad());
}

bool Time::h2(Time d) const
{
	return t.h2(d.getTriad());
}

bool Time::m1(Time d) const
{
	return t.m1(d.getTriad());
}

bool Time::m2(Time d) const
{
	return t.m2(d.getTriad());
}

bool Time::s1(Time d) const
{
	return t.s1(d.getTriad());
}

bool Time::s2(Time d) const
{
	return t.s2(d.getTriad());
}

int Time::getCounter()
{
	return Time::counter;
}

///////////////
/// class Triad

int Time::Triad::counter = 0;

bool Time::Triad::setFirst(int value)
{
    if (value > -1 && value < 24)
    {
        first = value;
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::Triad::setSecond(int value)
{
    if (value > -1 && value < 60)
    {
        second = value;
        return true;
    }
    else
    {
        return false;
    }
}

bool Time::Triad::setThird(int value)
{
    if (value > -1 && value < 60)
    {
        third = value;
        return true;
    }
    else
    {
        return false;
    }
}

void Time::Triad::Init(int firstValue, int secondValue, int thirdValue)
{
    setFirst(firstValue);
    setSecond(secondValue);
    setThird(thirdValue);
}

void Time::Triad::Display() const
{
    cout << first << "." << second << "." << third << endl;
}

void Time::Triad::Read()
{
    int firstValue;
    int secondValue;
    int thirdValue;

    cout << "Enter triad " << endl << endl;
    cout << "first =  "; cin >> firstValue;
    cout << "second =  "; cin >> secondValue;
    cout << "third =  "; cin >> thirdValue;

    Init(firstValue, secondValue, thirdValue);
}

const string Time::Triad::toString()
{
    stringstream sout;

    sout << first << "." << second << "." << third;

    return sout.str();
}

Time::Triad::Triad()
    : first(0), second(0), third(0)
{
    Time::Triad::counter++;
}

Time::Triad::Triad(const int first, const int second, const int third)
    : first(first), second(second), third(third)
{
    Time::Triad::counter++;
}

Time::Triad::Triad(const Triad& m)
    : first(m.first), second(m.second), third(m.third)
{
    Time::Triad::counter++;
}

Time::Triad::~Triad(void)
{
    Time::Triad::counter--;
}

Time::Triad& Time::Triad::operator = (const Time::Triad& m)
{
    this->first = m.first;
    this->second = m.second;
    this->third = m.third;

    return *this;
}

Time::Triad::operator string () const
{
    stringstream ss;
    ss << endl;
    ss << "first = " << first << endl;
    ss << "second = " << second << endl;
    ss << "third = " << third << endl;

    return ss.str();
}

ostream& operator << (ostream& out, const Time::Triad& m)
{
    out << string(m);
    return out;
}

istream& operator >> (istream& in, Time::Triad& m)
{
    int first;
    int second;
    int third;

    cout << endl;
    cout << "first = ? "; in >> first;
    cout << "second = ? "; in >> second;
    cout << "third = ? "; in >> third;

    m.setFirst(first);
    m.setSecond(second);
    m.setThird(third);

    return in;
}

Time::Triad& Time::Triad::operator ++ ()
{
    ++first;
    ++second;
    ++third;
    return *this;
}

Time::Triad& Time::Triad::operator -- ()
{
    --first;
    --second;
    --third;
    return *this;
}

Time::Triad Time::Triad::operator ++ (int)
{
    Triad t(*this);
    first++;
    second++;
    third++;
    return t;
}

Time::Triad Time::Triad::operator -- (int)
{
    Triad t(*this);
    first--;
    second--;
    third--;
    return t;
}

bool Time::Triad::h1(Triad t) const
{
    if (first < t.first)
    {
        return true;
    }
    if (first > t.first)
    {
        return false;
    }

    if (second < t.second)
    {
        return true;
    }
    if (second > t.second)
    {
        return false;
    }

    if (third < t.third)
    {
        return true;
    }
    if (third > t.third)
    {
        return false;
    }

    return false;
}
bool Time::Triad::h2(Triad t) const
{
    if (first < t.first)
    {
        return true;
    }
    if (first > t.first)
    {
        return false;
    }

    if (second < t.second)
    {
        return true;
    }
    if (second > t.second)
    {
        return false;
    }

    if (third < t.third)
    {
        return true;
    }
    if (third > t.third)
    {
        return false;
    }

    return true;
}
bool Time::Triad::m1(Triad t) const
{
    if ((first == t.first) && (second == t.second) && (third == t.third))
    {
        return true;
    }

    return false;
}
bool Time::Triad::m2(Triad t) const
{
    if ((first == t.first) && (second == t.second) && (third == t.third))
    {
        return false;
    }

    return true;
}
bool Time::Triad::s1(Triad t) const
{
    if (first < t.first)
    {
        return false;
    }
    if (first > t.first)
    {
        return true;
    }

    if (second < t.second)
    {
        return false;
    }
    if (second > t.second)
    {
        return true;
    }

    if (third < t.third)
    {
        return false;
    }
    if (third > t.third)
    {
        return true;
    }

    return false;
}
bool Time::Triad::s2(Triad t) const
{
    if (first < t.first)
    {
        return false;
    }
    if (first > t.first)
    {
        return true;
    }

    if (second < t.second)
    {
        return false;
    }
    if (second > t.second)
    {
        return true;
    }

    if (third < t.third)
    {
        return false;
    }
    if (third > t.third)
    {
        return true;
    }

    return true;
}

double Time::Triad::check()
{
    return first > second;
}

int Time::Triad::getCounter()
{
    return Time::Triad::counter;
}