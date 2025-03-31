#include <iostream>
#include <iomanip>
using namespace std;


char ValidateSex(const int &PROMPT_SIZE)
{

    char sex;
    bool invalidSex;
    do

    {
        cout << "Please enter the candidate's information (enter 'X' to exit)."
                "\n";
        cout << setw(PROMPT_SIZE) << "Sex: ";
        if (!(cin.get(sex)))
        {
            cin.clear();
        }

        invalidSex = sex != 'x' && sex != 'X' &&
                       sex != 'f' && sex != 'F' &&
                       sex != 'm' && sex != 'M';

        if (invalidSex)
        {
            cout << "\nERROR: INVALID sex - Please Input M/F\n";
        }

        cin.ignore(10000, '\n');

    }while (invalidSex);

    return sex;


}
