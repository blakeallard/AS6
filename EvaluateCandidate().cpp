#include <iostream>
using namespace std;


void EvaluateCandidate(bool acceptableHeight , bool acceptableWeight ,
                                               int &acceptedCount)
{
    if (acceptableHeight && acceptableWeight)
    {
        cout << "This candidate has been ACCEPTED!\n\n\n";
        acceptedCount ++;
    }

    else if (acceptableWeight)
    {
        cout << "This candidate has been rejected based on the HEIGHT "
                "requirements.\n\n\n";
    }

    else if (acceptableHeight)
    {
        cout << "This candidate has been rejected based on the WEIGHT "
                "requirements.\n\n\n";
    }

    else
    {
        cout << "This candidate has been rejected based on the HEIGHT and "
                "WEIGHT requirements.\n\n\n";
    }
}
