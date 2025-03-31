#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int ValidateIntInput(int minValue , int maxValue , const int &PROMPT_SIZE ,
                                                   string prompt1 ,
                                                   string errPrompt ,
                                                   string invalidprmpt)
{
    int  intInput;
    bool validInput;

    validInput = true;

    do
    {
        cout << setw(PROMPT_SIZE) << prompt1;
        if (!(cin >> intInput))
        {
            cin.clear();

            cout << errPrompt;
        }

        else if (intInput < minValue || intInput > maxValue)
        {
            cout << invalidprmpt;
            cout << minValue << " and " << maxValue << endl;
        }
        else
        {
            validInput = false;
        }

        cin.ignore(10000, '\n');

    }while(validInput);

    return intInput;
}
