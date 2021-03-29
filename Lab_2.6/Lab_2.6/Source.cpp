//////////////
// Source.cpp
//////////////

#include "Time.h"

using namespace std;

int main()
{
	Time s1;
	cout << "Time : " << Time::getCounter() << endl;
	cout << "Time::Triad : " << Time::Triad::getCounter() << endl;

	Time::Triad m1;
	cout << "Time::Triad +1 : " << Time::Triad::getCounter() << endl;
	{
		Time s4(11, 19, 55);
		cout << "Time local : " << Time::getCounter() << endl;
		cout << "Time::Triad local : " << Time::Triad::getCounter() << endl;
		Time::Triad m1;
		cout << "Time::Triad local +1 : " << Time::Triad::getCounter() << endl;
	}
	cout << "Time : " << Time::getCounter() << endl;
	cout << "Time::Triad : " << Time::Triad::getCounter() << endl;

    Time::Triad t1, t2;

    t1.Read();
    t2.Read();
    t1.Display();

    cout << t2.toString() << endl;

    if (t1.h1(t2))
    {
        cout << "t1 < t2" << endl;
    }
    else if (t1.m1(t2))
    {
        cout << "t1 = t2" << endl;
    }
    else
    {
        cout << "t1 > t2" << endl;
    }

    Time d1, d2;

    d1.Init(t1);
    d2.Init(t2);
    d1.Display();

    cout << d2.toString() << endl;

    if (d1.h1(d2))
    {
        cout << "d1 < d2" << endl;
    }
    else if (d1.m1(d2))
    {
        cout << "d1 = d2" << endl;
    }
    else
    {
        cout << "d1 > d2" << endl;
    }

	return 0;
}