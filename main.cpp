#include "pch.h"
#include <iostream>
using namespace std;

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    //printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
    
    string filename = "";
    while (filename != "q") {
        cout << "Enter a path to the poem text file you would like to read or q to quit";

    }
}
