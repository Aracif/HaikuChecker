#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

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
		bool isVowel(char c);
		int findSyllablesInLine();
		int findSyllablesInWord(string word);

		template <typename Out>

		void split(const string& s, char delim, Out result);

		vector<string> split(const string& s, char delim);
};


