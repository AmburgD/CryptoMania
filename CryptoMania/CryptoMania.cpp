// CryptoMania: A game for learning cryptography. Crack the code to improve your score. 3 wrong attemps and its game over!
// Written by Dax Amburgy and Anthony Middleton
//

#include <iostream>
#include <random>
#include <string>


using namespace std;

void a1z26();
void atbash();

//global variables for the game part
int score = 0;
int strikes = 0;

int main()
{

    cout << "CryptoMania" << endl;
    cout << "What level of difficulty? Please enter one number 1(Decryption) or 2(Encryption)?" << endl;
    int level = 0;
    int codeSelector;
    
    bool input = false;
    while (!input) {
        cin >> level;

        if (level == 1) {
            cout << "You picked Decryption" << endl;
            while (score != 3 || strikes != 3) {
                codeSelector = rand() % 3;
                
                if (codeSelector == 1) {
                    a1z26();

                }
                if (codeSelector == 2) {
                    atbash();
                }
                
            }
            if (score == 3) {
                cout << "You WIN!" << endl;

            }
            else if (strikes == 3) {
                cout << "You LOSE!" << endl;
            }
            input = true;
        }
        else if (level == 2) {
            cout << "You picked Encryption" << endl;
            while (score <= 3 || strikes <= 3) {
                int codeSelector = rand() % 2;
                if (codeSelector == 1) {

                    
                }
                if (codeSelector == 2) {
                    
                }
                
            }
            input = true;
        }
        else {
            cout << "That is not an option, please try again!" << endl;
        }
    }
   
}

void a1z26()
{
    //list of random phrases to crack
    string randomPhrase[1] = {"hello world"};

    cout << "Crack the following az126 code!" << endl;

    //integer to select a phrase
    int phraseSelector = rand() % 1;
    string selectedPhrase = randomPhrase[phraseSelector];
    string swappedPhrase = "";

    //Swap the Characters for Integers
    for (char currentChar : selectedPhrase) {
        if (isalpha(currentChar)) {
            // Convert uppercase letters to their corresponding position in the alphabet
            if (isupper(currentChar)) {
                int position = currentChar - 'A' + 1;
                swappedPhrase += to_string(position) + " ";
            }
            // Convert lowercase letters to their corresponding position in the alphabet
            else if (islower(currentChar)) {
                int position = currentChar - 'a' + 1;
                swappedPhrase += to_string(position) + " ";
            }
        }
        else {
            // Non-alphabet characters are preserved as is
            swappedPhrase += currentChar;
        }
    }
    cout << swappedPhrase << endl;
    string guess;
    bool round = true;
    cout << "Type the encoded message here: ";
    while (round) {
        cin >> guess;
        if (guess == selectedPhrase) {
            cout << "You got a point! Here is the next code:" << endl;
            score++;
            round = false;
        }
        else {
            if (strikes == 3) {
                round = false;
            }
            else {
                cout << "Uh oh! That is strike #" << strikes << "!" << endl;
                strikes++;
            }
            
        }
    }
}

void atbash()
{
    //list of random phrases to crack
    string randomPhrase[1] = { "hello world" };

    cout << "Crack the following atbash code!" << endl;

    //integer to select a phrase
    int phraseSelector = rand() % 1;
    string selectedPhrase = randomPhrase[phraseSelector];
    string swappedPhrase = "";
    for (char currentChar : selectedPhrase) {
        if (isalpha(currentChar)) {
            char encodedChar;
            if (isupper(currentChar)) {
                encodedChar = 'Z' - (currentChar - 'A');
            }
            else {
                encodedChar = 'z' - (currentChar - 'a');
            }
            swappedPhrase += encodedChar;
        }
        else {
            // Non-alphabet characters are preserved as is
            swappedPhrase += currentChar;
        }
    }
    cout << swappedPhrase << endl;
    string guess;
    bool round = true;
    cout << "Type the encoded message here: ";
    while (round) {
        cin >> guess;
        if (guess == selectedPhrase) {
            cout << "You got a point! Here is the next code:" << endl;
            score++;
            round = false;
        }
        else {
            if (strikes == 3) {
                round = false;
            }
            else {
                cout << "Uh oh! That is strike #" << strikes << "!" << endl;
                strikes++;
            }

        }
    }
}
