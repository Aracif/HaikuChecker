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
    vector<int> syllablesInEachLine = findSyllablesInLine();
    printResultsReport(syllablesInEachLine);
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

vector<int> Poem::findSyllablesInLine() {
    vector<int> syllablesInEachLine;
    
    for (int i = 0; i < poemLines.size(); i++) {
        int totalSyllablesInLine = 0;
        vector<string> words = split(poemLines[i], ' ');
        for (int y = 0; y < words.size(); y++) {
            totalSyllablesInLine += findSyllablesInWord(words[y]);
        }
        syllablesInEachLine.push_back(totalSyllablesInLine);
    }
    return syllablesInEachLine;
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

void Poem::printResultsReport(vector<int> syllablesInEachLine) {
    int failures = 0;
    if (syllablesInEachLine.size()!=3) {
        failures++;
        printf("haikus are 3 lines, this poem is %i lines.", syllablesInEachLine.size());
    }
    if (syllablesInEachLine[0] != 5) {
        failures++;
        printf("Traditionally, the first line of a haiku is 5 syllables. This poem is %i syllables.\n", syllablesInEachLine[0]);
    }    
    if (syllablesInEachLine[1]!=7) {
        failures++;
        printf("Traditionally, the second line of a haiku is 7 syllables. This poem is %i syllables.\n", syllablesInEachLine[1]);
    }    
    if (syllablesInEachLine[2] != 5) {
        failures++;
        printf("Traditionally, the third line of a haiku is 5 syllables. This poem is %i syllables.\n", syllablesInEachLine[2]);
    }
    if (failures==0) {
        cout << "Valid haiku\n";
    }
    else {
        printf("\t%i total errors\n", failures);
    }
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