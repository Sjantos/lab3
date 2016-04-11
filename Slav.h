#pragma once
#include <string>
#include <vector>

enum myenum
{
	women=0,
	men=1
};

using namespace std;

class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;

	string _name;
	int _id;

public:
	Slav();

	static int counter() { return _counter; }
	
	string name() { return _name; }
	int id() { return _id; }

	string description();

	myenum menwomen();;
};
