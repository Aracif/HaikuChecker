#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Poem
{
	private:
		vector<string> poemLines;
	public:
		Poem();
		Poem(vector<string> newPoemLines);
		~Poem();

		//accessors
		vector<string> getPoemLines();

		//mutators

		bool isHaiku();
};


