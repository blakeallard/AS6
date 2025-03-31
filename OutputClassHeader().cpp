#include <iostream>
#include <iomanip>
using namespace std;

/*******************************************************************************
 * CONSTANTS
 * -----------------------------------------------------------------------------
 * OUTPUT - USED FOR CLASS HEADING
 * -----------------------------------------------------------------------------
 * PROGRAMMER      : Programmer's Name
 * CLASS           : Student's Course
 * SECTION         : Class Day / Times
 * EXR/ASN/LAB_NUM : Exercise/Assignment/Lab #
 * EX/ASN/LAB_NAME : Title of the Exercise/Assignment/Lab
 ******************************************************************************/

//OUTPUT - used for class heading
const char PROGRAMMER[] = "Blake Allard";
const char CLASS[]      = "CS1A";
const char SECTION[]    = "M/W 8am";
const char ASN_NUM[]    = "6";
const char ASN_NAME[]   = "Military Academy";


void OutputClassHeader()
{
    cout <<  left;
    cout <<  "******************************************************\n";
    cout <<  "*  PROGRAMMED BY :  "<< PROGRAMMER                     << "\n";
    cout <<  "*  "      << setw(14)<< "CLASS"   << ":  " << CLASS    << "\n";
    cout <<  "*  "      << setw(14)<< "SECTION" << ":  " << SECTION  << "\n";
    cout <<  "*  ASSIGNMENT #" << setw(2) << ASN_NUM   << ":  " << ASN_NAME <<
            "\n";
    cout <<  "******************************************************\n\n";
    cout <<  right;
}
