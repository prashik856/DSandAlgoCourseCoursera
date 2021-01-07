#include<bits/stdc++.h>
using namespace std;

int main(){
    // Initialize strings using char pointers
    char *colour[4] = {
        "Hello",
        "My",
        "Name",
        "is"
    };

    // Initialize strings using 2d arrays
    char colors[4][10] = {
        "Hello",
        "My",
        "Name",
        "is"
    };

    // Using stl string
    string colour1[4] = {
        "Hello",
        "My",
        "Name",
        "is"
    };

    // Using the vector class
    vector<string> colour2 {"Hello",
        "My",
        "Name",
        "is"};


    // Using array class
    array<string, 4> colour3{"Hello",
        "My",
        "Name",
        "is"};

    

    string str;
    // Get input using method
    getline(cin, str);
    // pushback to enter a character
    str.push_back('a');
    // pop the last element
    str.pop_back();
    // Get size of string
    str.size();
    // Get a substring from a position of given size.
    int position = 1;
    int sizeOfSubstring = 5;
    str.substr(position, sizeOfSubstring);
    // Start pointer of string
    str.begin();
    // End of string
    str.end();
    // Empty string
    str.empty();
    // Erase string/ substring/ character from string
    str.erase(str.begin());
    str.erase(str.begin(), str.begin() + 1);
    str.erase(position, sizeOfSubstring);
    // Insert into string
    str.insert(str.begin() + 3, 'T');

    return 0;
}