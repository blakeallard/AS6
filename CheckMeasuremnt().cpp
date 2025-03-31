#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


bool CheckMeasurement(char sex , int  intInput , const int MIN_RANGE_M ,
                                                 const int MAX_RANGE_M ,
                                                 const int MIN_RANGE_F ,
                                                 const int MAX_RANGE_F)
{
    return ((sex  == sex || sex == sex)
            && intInput >= MIN_RANGE_M && intInput <= MAX_RANGE_M) ||
            ((sex == sex || sex == sex)
            && intInput >= MIN_RANGE_F && intInput <= MAX_RANGE_F);
}
