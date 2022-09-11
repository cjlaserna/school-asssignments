// headers
#include "proj_1.h"

using namespace std;

int main()
{
    // initialize vars
    playerStats player;
    int dice, playerAttempts;

    // I didn't loop through inputs to make it capitalized,
    // but I made the function for it and tested it.
    // cout << player.chooseOptLoop(); 


    // GAME ROLL STATS
    do
    {
        player.Generate();
        player.PrintAll();

        cout << "These are your stats"
                "\nWhat would you like to do?"
                "\nBEGIN, REROLL, or ANY to QUIT"
             << endl;

        player.chooseOpt();

    } while (player.Choice == "REROLL");

    // quit program on ANY key
    if (player.Choice != "BEGIN")
    {
        return 0;
    }

    // GAME START
    cout << string(20, '-') << "\nYou are standing in front of the gate to a large mysterious mansion.The gates rusted lock seems ready to fall off."
                               "\n\nMaybe if you bashed the gate hard enough, you could get through it. Or, you could try to climb over the gate."
         << endl;

    playerAttempts = 0;

    do {
        cout << "\nWould you like to CLIMB or BASH the gate? ";
        player.chooseOpt();

        if (player.Choice != "CLIMB" && player.Choice != "BASH"){
            playerAttempts += 1;
            cout << "Attempt " << playerAttempts << ": I'm sorry I did not understand that response. Please try again." << endl;
        } else {
            break;
        }
    } while (playerAttempts < 3);

    if (player.Choice == "CLIMB")
    {
        dice = player.rollDie(1, 20);
        cout << "[ You rolled a " << dice << " against a Dex of " << player.Dexterity << " ]" << endl;

        if (dice <= player.Dexterity)
        {
            cout << string(20, '-')
                 << "\nSuccess."
                 << "\nYou carefully climb over the old rusted gate."
                 << "\n\nYou land safely on your feet inside the grounds of the mysterious mansion."
                 << endl;
        }
        else
        {
            dice = player.rollDie(1, 4);
            player.CurrHealth -= dice;
            player.PrintHealth();

            cout << "Fail."
                 << "\nAs you make your way over the rusted gate, the finial you are using for support snaps and you land hard on the ground below."
                 << "\n\nYou take ["
                 << dice
                 << "] damage and are a little shaken. " << endl;

            if (player.CurrHealth <= 0)
            {
                cout << "You Fainted From Exhaustion." << endl;
                return 0;
            }
            else
            {
                cout
                    << "\n\nNevertheless, you have made it inside the grounds of the mysterious mansion."
                    << endl;
            }
        }
    }
    else if (player.Choice == "BASH")
    {
        dice = player.rollDie(1, 20);
        cout << "[ You rolled a " << dice << " against a Str of " << player.Strength << " ]" << endl;

        if (dice <= player.Strength)
        {
            cout << string(20, '-')
                 << "\nSuccess."
                 << "\nYou put all your weight into a massive assault on the gate."
                 << "\nAs you suspected, the lock was not up to the challenge and gave way easily."
                 << "\nYou hear a large thud as the gate crashes open."
                 << "\n\nYou have made it inside the grounds of the mysterious mansion."
                 << endl;
        }
        else
        {
            dice = player.rollDie(1, 4);
            player.CurrHealth -= dice;
            player.PrintHealth();

            cout << "You put all your weight into a massive assault on the gate."
                 << "\nAt first, the lock resists your attack, and the collision with the gate bites into your shoulder."
                 << "\n\nYou take ["
                 << dice
                 << "] damage." << endl;

            if (player.CurrHealth <= 0)
            {
                cout << "You Fainted From Exhaustion." << endl;
                return 0;
            }
            else
            {
                cout
                    << "\n\nAfter a moment's hesitation, the lock gives, and the gate swings open with a thud. You have made it inside the grounds of the mysterious mansion."
                    << endl;
            }
        }
    }

    // GAME END
    cout << string(20, '_')
         << "\nThank you for playing our demo. We hope you have enjoyed it." << endl;
    
    cin >> player.Choice;
    return 0;
};