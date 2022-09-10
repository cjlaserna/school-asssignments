#include <algorithm> // for any_of
#include <string>    // for easier string manip.
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class playerStats
{
public:
    int Strength, Dexterity, Intelligence, Charisma, MaxHealth, CurrHealth;

public:
    void Generate()
    {
        // Roll or re-rolls the stats
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

public:
    void Print()
    {
        // prints current stats in it's current state
        // strength, dexterity, intelligence, charisma, maxhealth and curr health needs to be defined

        int statsArr[5] = {Strength, Dexterity, Intelligence, Charisma, MaxHealth}; // used for fail-safe
        int healthBarPercent = (CurrHealth / MaxHealth) * 10;                       // Ex: 2/5 is 0.4 or 40% of the bar (4/10)

        // any_of will check if any of the stats are 0 (which they shouldn't be)
        any_of(statsArr, statsArr + 5, [](int x)
               { return x == 0; })
            ? cout << "An Error Occured. Stats are not initialized" << endl
            :
            // print ascii stats table
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
};