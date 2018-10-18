/*
    Date: 10/10/2017
    Author: Mehmet Oguz Ongel
    
    Description: Spell checking program that compares words in a file 
                 to their correct spellings in a file called dictionary.txt
*/


#include <iostream>
#include <string>
#include <fstream>

#include "DLinkedBag.h"

using namespace std;

const int SIZE = 9;

/*
    Compares the given linked list of words to an array of words
    then displays the misspelled words
    @parameters dictionary, array, file_name
*/
void compareWords(DLinkedBag<string>& dictionary, string array[], string file_name);

int main()
{
    DLinkedBag<string> dictionary;
    ifstream file;
    ifstream correctWords;
    string fileName;

    // Export the correctly spelled words from a file
    string words[SIZE];
    correctWords.open("dictionary.txt");
    for(int i = 0; i < SIZE; i++)
        correctWords >> words[i];
    
    // Add the words to a doubly linked list
    for(int i = 0; i < SIZE; i++)
        dictionary.add(words[i]);

    // Get the input from a file that is entered by the user
    cout << "Enter the name of the file that contains words to check" << endl;
    cin >> fileName;
    cout << endl;

    string inputWords[SIZE]; // array for the input words from the file
    file.open(fileName.c_str());
    if(file.is_open()) {
        for (int i = 0; i < SIZE; i++)
            file >> inputWords[i];

        compareWords(dictionary, inputWords, fileName);

        cout << "Thanks for using the spell checker system." << endl << endl;
    }
    else
        cout << "File not found!" << endl;



    return 0;
}

// Implementation of compareWords function
void compareWords(DLinkedBag<string>& dictionary, string array[], string file_name) {

    vector<string> incorrectWords;

    for(int i = 0; i < SIZE; i++) {
        if(!dictionary.contains(array[i])) {
            // add to the list of incorrect words
            incorrectWords.push_back(array[i]);
        }
    }

    cout << "The following words in the file " << file_name << " are not spelled correctly:" << endl;
    for(int i = 0; i < incorrectWords.size(); i++) {
        cout << incorrectWords[i] << endl;
    }
    cout << endl;
}
