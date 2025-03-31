/*******************************************************************************
 * AUTHOR     : Blake Allard
 * STUDENT ID : 358888
 * ASN #6     : Military Academy
 * CLASS      : CS1A
 * SECTION    : MW 8am
 * DUE DATE   : 11/18/24
 ******************************************************************************/

#include <iostream>    /* cout, cin           */
#include <iomanip>     /* setw                */
#include <string>      /* string              */
using namespace std;

    /***************************************************************************
     * PROGRAM DESCRIPTION
     * -------------------------------------------------------------------------
     * This program will determine the acceptance of a male or female candidate
     * based on the candidate's height & weight
     * -------------------------------------------------------------------------
     * INPUT: the user will input the candidate's sex, height & weight.
     *
     * OUTPUT (in loop): based on the candidates eligibility the program will
     *                   output:
     *
     *     - "This candidate has been ACCEPTED!"
     *     - "This candidate has been rejected based on the HEIGHT requirement."
     *     - "This candidate has been rejected based on the WEIGHT requirement."
     *     - "This candidate has been rejected based on the HEIGHT and WEIGHT "
     *       "requirements."
     *
     * PROCESSING: the program will determine if the candidate is accepted based
     *             on each candidate's height & weight requirements.
     *
     * Example Input/Output:
     *
     * Please enter the candidate’s information (enter ‘X’ to exit).
     * Sex: m
     * Height: 80
     * Weight: 130
     *
     * This candidate has been ACCEPTED!
     **************************************************************************/

	/***************************************************************************
	 * FUNCTION PROTOTYPES:
	 *--------------------------------------------------------------------------
	 *  - OutputClassHeader: outputs class information
	 *  - ValidateSex      : error checks invalid characters/invalid numbers
	 *  - ValidateIntInput : error checks for invalid characters/invalid numbers
	 *  - CalculatePercent : calculates a percentage
	 *  - ValidateIntRange : checks if a number is within a specified integer
	 *                       range dependent upon the specific character entered
	 **************************************************************************/

	void OutputClassHeader();

	char ValidateSex(const int &PROMPT_SIZE);

	int  ValidateIntInput (int minValue , int maxValue , const int &PROMPT_SIZE
			                                           , string prompt1
			                                           , string errPrmpt
				                                       , string invalidPrmpt);

	bool CheckMeasurement (char charInput        , int intInput ,
						   const int MIN_RANGE_A , const int MAX_RANGE_A ,
						   const int MIN_RANGE_B , const int MAX_RANGE_B);

	void EvaluateCandidate(bool acceptableHeight , bool acceptableWeight ,
                           int  &acceptedCount);


int main()
{

	/***************************************************************************
	* CONSTANTS
	* --------------------------------------------------------------------------
	* FORMATTING - USED FOR PROMPT COLUM LENGTH
	* --------------------------------------------------------------------------
	* PROMPT_SIZE : used for setting prompt column length size
	* --------------------------------------------------------------------------
	* PROCESSING - USED FOR MIN/MAX VALID INPUT & BOUNDARY VALUES TO ERROR CHECK
	* --------------------------------------------------------------------------
	* M_MIN_RANGE_1        - MINIMUM VALID HEIGHT FOR MEN
	* M_MAX_RANGE_1        - MAXIMUM VALID HEIGHT FOR MEN
	* F_MIN_RANGE_2        - MINIMUM VALID HEIGHT FOR WOMEN
	* F_MAX_RANGE_2        - MAXIMUM VALID HEIGHT FOR WOMEN
	* M_MIN_RANGE_3        - MINIMUM VALID WEIGHT FOR MEN
	* M_MAX_RANGE_3        - MAXIMUM VALID WEIGHT FOR MEN
	* F_MIN_RANGE_4        - MINIMUM VALID WEIGHT FOR WOMEN
	* F_MAX_RANGE_4        - MAXIMUM VALID WEIGHT FOR WOMEN
	*---------------------------------------------------------------------------
	* INVALID_MIN_HEIGHT   - INVALID MINIMUM HEIGHT
	* INVALID_MAX_HEIGHT   - INVALID MAXIMUM HEIGHT
	* INVALID_MIN_WEIGHT   - INVALID MINIMUM WEIGHT
	* INVALID_MAX_WEIGHT   - INVALID MAXIMUM WEIGHT
	***************************************************************************/

	//CONSTANTS - column width size
	const int PROMPT_SIZE = 9;

	//CONSTANTS - min/max ranges that determine acceptance per category
	const int M_MIN_RANGE_1  = 65;
	const int M_MAX_RANGE_1  = 80;
	const int F_MIN_RANGE_2  = 62;
	const int F_MAX_RANGE_2  = 75;
	const int M_MIN_RANGE_3  = 130;
	const int M_MAX_RANGE_3  = 250;
	const int F_MIN_RANGE_4  = 110;
	const int F_MAX_RANGE_4  = 185;

	//CONSTANTS - boundary values for invalid input
	const int INVALID_MIN_HEIGHT = 24;
	const int INVALID_MAX_HEIGHT = 110;
	const int INVALID_MIN_WEIGHT = 50;
	const int INVALID_MAX_WEIGHT = 1400;

	/***************************************************************************
	 * VARIABLES -
	 **************************************************************************/

	char   sex;                   // IN   & CALC - sex of candidate
	int    height;                // IN   & CALC - candidates height
	int    weight;                // IN   & CALC - candidate's weight
	double percent;               // CALC & OUT  - % of accepted candidates
	bool   acceptableHeight;      //      & CALC - min/max height requirements
	bool   acceptableWeight;      //      & CALC - min/max weight requirements

	/***************************************************************************
     * INITIALIZATIONS -
     **************************************************************************/

	int totalCandidates = 0;      //      & CALC - total candidates evaluated
	int acceptedCount   = 0;      // CALC & OUT  - number of accepted candidates

	/***************************************************************************
	 * OUTPUT - class heading
	 **************************************************************************/

	OutputClassHeader();

	/***************************************************************************
	 * INPUT - prompt the user for the candidate's sex, height & weight
	 * -------------------------------------------------------------------------
	 * EXAMPLE:
	 *         Please enter the candidate’s information (enter ‘X’ to exit).
     *         Sex:    m
     *         Height: 80
     *         Weight: 130
	 **************************************************************************/

	cout << left;


	sex = ValidateSex(PROMPT_SIZE);

	/***************************************************************************
	 * PROCESSING - validates sex and validates height & weight applicability
	 **************************************************************************/

	while (sex != 'x' && sex != 'X')
	{

		height = ValidateIntInput(INVALID_MIN_HEIGHT,
				                  INVALID_MAX_HEIGHT, PROMPT_SIZE,
                                  "Height: " , "\nINVALID! MUST BE A NUMBER!\n",
								  "\nINVALID! Please enter a height between ");

		weight = ValidateIntInput(INVALID_MIN_WEIGHT,
				                  INVALID_MAX_WEIGHT, PROMPT_SIZE,
                                  "Weight: " , "\nINVALID! MUST BE A NUMBER!\n",
								  "\nINVALID! Please enter a weight between ");

		cout << endl;


		//INCREMENT - increment total candidates count
		++totalCandidates;


		acceptableHeight = CheckMeasurement(sex , height ,
                                           M_MIN_RANGE_1 , M_MAX_RANGE_1 ,
                                           F_MIN_RANGE_2 , F_MAX_RANGE_2);

		acceptableWeight = CheckMeasurement(sex , weight ,
                                            M_MIN_RANGE_3 , M_MAX_RANGE_3 ,
										    F_MIN_RANGE_4 , F_MAX_RANGE_4);

		EvaluateCandidate(acceptableHeight, acceptableWeight, acceptedCount);



		sex = ValidateSex(PROMPT_SIZE);


	} //...end while (sex != 'x')


	/***************************************************************************
	* OUTPUT - output the # of candidates accepted & the percentage of accepted
	*--------------------------------------------------------------------------
	* EXAMPLE:
	*          3 candidate(s) accepted!
    *          That’s 33%!
	***************************************************************************/


	//PROCESSING  - output # of candidates accepted & total percentage accepted
	if (totalCandidates > 0)
	{

		percent = double(totalCandidates) / acceptedCount * 100;

		cout << endl;

		cout << setprecision(0) << fixed;

		cout << acceptedCount << " candidate(s) accepted!\n";
		cout << "That's "     << percent << "%!\n\n\n";

		cout << right;
	}

	return 0;

} //... end int main()
