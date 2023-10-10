#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "+----------------------------------------+" << endl;
    cout << "|      Computer Science and Engineering   |" << endl;
    cout << "|       CSCE 1030 - Computer Science I    |" << endl;
    cout << "| Section:002003--Jeffrey Jackson--jj0861 |" << endl;
    cout << "|         JeffreyJackson3@my.unt.edu      |" << endl;
    cout << "|              Section:002,003            |" << endl;
    cout << "+----------------------------------------+" << endl;

    int points = 100; // Starting Points
    enum choices      // Menu Choices
    {
        displayLeft = 1,
        displayRight = 2,
        guess = 3,
        change = 4,
        exit = 5,
        guessBounds = 6
    };
    string playerName;               // Player Name
    bool playerNameCheck = false;    // Player Name Validity boolean
    while (playerNameCheck == false) // Player Name Validity Check
    {
        cout << "Player Name(up to 16 letters max!): ";
        getline(cin, playerName);
        for (auto x : playerName)
        {
            if (isalpha(x) == false && isspace(x) == false)
            {
                cout << "That name contains characters other than letters or spaces!" << endl;
                playerNameCheck = false;
                break;
            }
            else
            {
                playerNameCheck = true;
            }
        }
        if (playerName.length() > 16)
        {
            cout << "That name is too long!" << endl;
            playerNameCheck = false;
        }
    }
    for (auto &x : playerName) // Player Name Lowercase-ification #im not sure theres a word for that
    {
        x = tolower(x);
    };
    cout << "Welcome to my guessing game " << playerName << "!" << endl;
    cout << "The final goal is to guess the two boundary numbers!" << endl;
    cout << "You can guess the boundaries at any time but it will cost you 20 points!" << endl;
    cout << "by making guesses you can narrow down the boundaries and make it easier to guess the boundaries!" << endl;
    cout << "But beware! a guess outside the boundaries will cost you 5 points a guess within will gain you 5 more" << endl;
    // Generating Random Number
    srand(time(0));                         // Setting the seed to the current time
    int lowerBoundary = rand() % 100 + 100; // Lower Boundary is 1 lower to insure no infinite loop and it cant be 200 the max
    int upperBoundary = rand() % 101 + 100;
    lowerBoundary = rand() % 100 + 100; // Setting again to try to change the seed I noticed the first values were always the same
    upperBoundary = rand() % 101 + 100; // This seems to create enough variety to make it seem random
    while (upperBoundary <= lowerBoundary)
    {
        upperBoundary = rand() % 101 + 100;
    }
    int NumberOne = -1;
    int NumberTwo = -1;
    /*  cout << "+----------|----------|----------+" << endl
            << "|          "
            << NumberOne << "         " << NumberTwo << "         |" << endl
            << "+----------|----------|----------+" << endl;
   */
    ////////////////////////////////////////////////////////////////////////////////////////////////
    /*Remember to make spaces adjustments to account for digit changes of Number one and or two */ /*Too much hassle nevermind*/
    int menuChoice = 0;
    int correctGuesses = 5;
    int incorrectGuesses = 5;
    int rememberLastNum = 0;
    // The Game Loop
    while (menuChoice != 5)
    {
        cout << "+----------|----------|----------+" << endl
             << "|          "
             << NumberOne << "         " << NumberTwo << "         |" << endl
             << "+----------|----------|----------+" << endl;
        cout << "You have " << points << " points." << endl;
        cout << "1. Reveal the left boundary" << endl;
        cout << "2. Reveal the right boundary" << endl;
        cout << "3. Guess the number" << endl;
        cout << "4. Change the boundaries" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Guess the boundaries" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;
        switch (menuChoice)
        {
        case displayLeft:
            if (NumberTwo != -1)
            {
                cout << "You have already revealed the right boundary!" << endl;
                break;
            }
            else
            {
                NumberOne = lowerBoundary;
                cout << "The left boundary has been revealed " << endl;
                cout << "A correct guess is only worth 1 point, get it wrong it will cost you 10!" << endl;
                correctGuesses = 1;
                incorrectGuesses = 10;
                break;
            }
        case displayRight:
            if (NumberOne != -1)
            {
                cout << "You have already revealed the left boundary!" << endl;
                break;
            }
            else
            {

                NumberTwo = upperBoundary;
                cout << "The right boundary has been revealed " << endl;
                cout << "A correct guess is only worth 1 point, get it wrong it will cost you 10!" << endl;
                correctGuesses = 1;
                incorrectGuesses = 10;
                break;
            }
        case guess:
            int guess;
            cout << "Enter your guess: ";
            rememberLastNum = guess;
            cin >> guess;
            if (guess == rememberLastNum)
            {
                cout << "Hey! You just guessed that number!" << endl;
                break;
            }
            if (guess <= lowerBoundary || guess >= upperBoundary)
            {
                cout << "That guess is outside the boundaries!" << endl;
                points -= incorrectGuesses;
                if (points <= 0)
                {
                    cout << "You have run out of points! Game Over!" << endl;
                    menuChoice = 5;
                    break;
                }
            }
            else
            {
                cout << "You guessed within the boundaries" << endl;
                points += correctGuesses;
                cout << "You have " << points << " points." << endl;
            }
            break;
        case change:
            lowerBoundary = rand() % 100 + 100;
            upperBoundary = rand() % 101 + 100;
            NumberOne = -1;
            NumberTwo = -1;
            while (upperBoundary <= lowerBoundary)
            {
                upperBoundary = rand() % 101 + 100;
            }
            cout << "The bounds have been shuffled at the cost of 1 point" << endl;
            points -= 1;
            cout << "You have " << points << " points." << endl;
            if (points <= 0)
            {
                cout << "You have run out of points! Game Over!" << endl;
                menuChoice = 5;
                break;
            }
            break;
        case exit:
            cout << "Thanks for playing " << playerName << "!" << endl;
            cout << "You ended with " << points << " points!" << endl;
            break;
        case guessBounds:
            int guess1, guess2;
            cout << "Enter your guess for the lower boundary: ";
            cin >> guess1;
            cout << endl;
            cout << "Enter your guess for the upper boundary: ";
            cin >> guess2;
            if (guess1 == lowerBoundary && guess2 == upperBoundary)
            {
                cout << "You guessed correctly!" << endl;
                cout << " Conragats! You guessed the boundaries with " << points << " points remaining" << endl;
                menuChoice = 5;
                if (NumberOne != -1 || NumberTwo != -1)
                {
                    cout << "Next time try to guess the boundaries without revealing one!" << endl;
                }
                else
                {
                    cout << "Without revealing a boundary! You really beat the odds" << endl;
                }
                break;
            }
            else
            {
                cout << "You guessed incorrectly!" << endl;
                points -= 20;
                cout << "You have " << points << " points." << endl;
                if (points <= 0)
                {
                    cout << "You have run out of points! Game Over!" << endl;
                    menuChoice = 5;
                    break;
                }
            }
            break;
        default:
            cout << "That is not a valid choice!" << endl;
            menuChoice = 0;
            break;
        }
    }
}