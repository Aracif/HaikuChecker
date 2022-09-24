#include "pch.h"
#include <iostream>
#include <fstream>
#include "Poem.h"
using namespace std;

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    
    string filename = "";
    vector<string> poemLines;
    ifstream myfile;
    Poem poem;
    //main loop
    while (filename != "q") {
        cout << "Enter a path to the poem text file you would like to read or q to quit ";
        cin >> filename;
        cout << "\n";
        
        myfile.open(filename);
        if (myfile.is_open()) {
            //Read line by line then strip punctation and store result
            string line;
            while (getline(myfile, line))
            {
                line.erase(std::remove_if(line.begin(), line.end(), ::ispunct), line.end());
                poemLines.push_back(line);
                cout << line + "\n";
            }
            poem = Poem( poemLines );
            cout << "\n";
            poem.isHaiku();
            cout << "\n";
            //cout << poem.getPoemLines()[1].c_str();
        }
        else {
            printf("Unable to open %s try a path to an existing .txt file.\n", filename.c_str());

        }


    }
}
