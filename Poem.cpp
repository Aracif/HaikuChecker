#include "pch.h"
#include "Poem.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

Poem::~Poem() {

}

Poem::Poem() {

}

Poem::Poem(vector<string> newPoemLines) {
	poemLines = newPoemLines;
}

bool Poem::isHaiku() {
    findSyllablesInLine();
	return true;
}

vector<string> Poem::getPoemLines() {
	return poemLines;
}

bool Poem::isVowel(char c) {
    switch (tolower(c))
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

int Poem::findSyllablesInLine() {
    int totalSyllables = 0;
    for (int i = 0; i < poemLines.size(); i++) {
        vector<string> words = split(poemLines[i], ' ');
        for (int y = 0; y < words.size(); y++) {
            findSyllablesInWord(words[y]);
        }
    }
    return totalSyllables;
}

int Poem::findSyllablesInWord(string word) {
    int syllables = 0;
    for (int i = 0; i < word.size(); i++) {
        //Arrived at last char
        if (i+1>=word.size()) {

        }
        else {
            if (isVowel(word[i]) && !isVowel(word[i+1])) {
                syllables++;
            }
        }
    }
    printf("%s has %i syllables", word.c_str(), syllables);
    return syllables;
}

template <typename Out>
void Poem::split(const string& s, char delim, Out result) {
    istringstream iss(s);
    string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

vector<string> Poem::split(const string& s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}