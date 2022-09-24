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
    vector<int> syllablesInEachLine;
    
    for (int i = 0; i < poemLines.size(); i++) {
        int totalSyllablesInLine = 0;
        vector<string> words = split(poemLines[i], ' ');
        for (int y = 0; y < words.size(); y++) {
            totalSyllablesInLine += findSyllablesInWord(words[y]);
        }
        syllablesInEachLine.push_back(totalSyllablesInLine);
    }
    return 777;
}

//Core logic for determining syllable count
int Poem::findSyllablesInWord(string word) {
    int syllables = 0;
    for (int i = 0; i < word.size(); i++) {
        char currentLetter = tolower(word[i]);
        char nextLetter = tolower(word[i+1]);
        //Arrived at last char
        if (i+1>=word.size()) {
            //Rule 3 - A “Y” that appears at the end of a word is also a vowel.
            if (currentLetter == 'y') {
                syllables++;
            }
            //Rule 4 - An “E” at the end of a word is “silent” and not a vowel 
            //if the word contains another vowel.
            else if (currentLetter == 'e' && syllables==0) {
                syllables++;
            }
            //Rule 1 - A vowel – A, E, I, O, or U – corresponds to a syllable in 
            //the word
            else if (currentLetter != 'e' && isVowel(currentLetter)) {
                syllables++;
            }
        }
        else {
            //Rule 1 && Rule 2
            //A vowel – A, E, I, O, or U – corresponds to a syllable in the word.
            //As an exception to (1), any pair of consecutive vowels only counts 
            //as one syllable, not two.
            if (isVowel(currentLetter) && !isVowel(nextLetter)) {
                syllables++;
            }
        }
    }
    printf("[SYLL_COUNT] %s has %i syllables\n", word.c_str(), syllables);
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