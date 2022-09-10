// libraries
#include <iostream>
#include <stdlib.h>
#include <time.h>

// headers
#include "proj_1.h"

using namespace std;

int main()
{
    // initialize player and seed random
    string playerChoice;
    playerStats player;
    srand(time(NULL));
    
    do
    {
        // this will repeat as long as the user rerolls
        player.Generate();
        player.Print();

        cout << "These are your stats"
                "\nWhat would you like to do?"
                "\nBEGIN, REROLL, or ANY to QUIT"
             << endl;
        cin >> playerChoice;
    } while (playerChoice == "REROLL");

    // quit program on ANY key
    if (playerChoice != "BEGIN")
    {
        return 0;
    }

    // start of game
    cout << "You are standing in front of the gate to a large mysterious mansion.The gates rusted lock seems ready to fall off."
            "\n\nMaybe if you bashedmk the gate hard enough, you could get through it. Or, you could try to climb over the gate."
            "\n\nWould you like to CLIMB or BASH the gate? "
         << endl;

    cin >> playerChoice;
};