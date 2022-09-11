#include <algorithm> // for any_of
#include <string>    // for string manip.
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <time.h>

using namespace std;

class playerStats
{
    // variables
public:
    int Strength, Dexterity, Intelligence, Charisma, MaxHealth, CurrHealth;
    string Choice;

public:
    void Generate()
    {
        // Roll or re-rolls the stats
        // Doesn't take any arguments

        srand(time(NULL));

        // all 3-18
        Strength = (rand() % 18) + 3;
        Dexterity = (rand() % 18) + 3;
        Intelligence = (rand() % 18) + 3;
        Charisma = (rand() % 18) + 3;

        // health is 3-8
        MaxHealth = (rand() % 8) + 3;
        CurrHealth = MaxHealth;
    };

    // Stat Printing Functions
public:
    void PrintAll()
    {
        // Prints current stats in it's current state

        // used for fail-safe
        int statsArr[5] = {Strength, Dexterity, Intelligence, Charisma, MaxHealth};

        // Ex: 2/5 is 0.4 or 40% of the bar (4/10)
        int healthBarPercent = ((float)CurrHealth / (float)MaxHealth) * 10;

        // any_of will check if any of the stats are 0 (which they shouldn't be)
        any_of(statsArr, statsArr + 5, [](int x)
               { return x == 0; })
            ? cout << "An Error Occured. Stats are not initialized" << endl
            :
            // ascii stats table
            cout
                << string(20, '_') << "\n"
                << " : Strength: " << Strength
                << "\n | Dexterity: " << Dexterity
                << "\n | Intelligence: " << Intelligence
                << "\n | Charisma: " << Charisma
                << "\n : Health"
                << "(" << CurrHealth << "/" << MaxHealth << "): "
                << string(healthBarPercent, (char)254u) << string((10 - healthBarPercent), 'x')
                << "\n"
                << string(20, '_') << "\n"
                << endl;
    }

public:
    void PrintHealth()
    {
        // Ex: 2/5 is 0.4 or 40% of the bar (4/10)
        int healthBarPercent = ((float)CurrHealth / (float)MaxHealth) * 10;

        // I found that the program breaks if I do string(-int, char)
        // So health = 0 if dmg > health so that it won't break.
        if (healthBarPercent < 0) healthBarPercent = 0;
    
        // ascii health bar
        cout
            << string(20, '_') << "\n"
            << ": Health"
            << "(" << CurrHealth << "/" << MaxHealth << "): "
            << string(healthBarPercent, (char)254u) << string((10 - healthBarPercent), 'x')
            << "\n"
            << string(20, '_') << "\n"
            << endl;
    }

    // general functions
public:
    int rollDie(int rangeStart, int rangeEnd)
    {
        // picks a number ranging from rangeStart to rangeEnd
        return ((rand() % rangeEnd) + rangeStart);
    }

public:
    string chooseOpt()
    {
        // Lowercase input -> Uppercase so that it's accepted.
        cin >> Choice;
        transform(Choice.begin(), Choice.end(), Choice.begin(), ::toupper);

        return Choice;
    }

public:
    string chooseOptLoop() {
        // This is just for the assignment
        // if I were to loop through the string it would look like this
        cin >> Choice;

        for (int i = 0; i < Choice.size(); ++i) {
            Choice[i] = toupper(Choice[i]);
        }

        return Choice;
    }
};
