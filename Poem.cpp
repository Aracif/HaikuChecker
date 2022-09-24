#include "pch.h"
#include "Poem.h"
#include <iostream>
#include <vector>

Poem::Poem(vector<string> newPoemLines) {
	poemLines = newPoemLines;
}

bool Poem::isHaiku() {
	return true;
}

vector<string> Poem::getPoemLines() {
	return poemLines;
}