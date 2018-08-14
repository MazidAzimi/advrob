#include <iostream>
#include <vector>
#include <string.h>
#include "math.h"


using namespace std;

/* motion probabilities are set as global variables
 * motionMoveProb: probability of moving one step forward
 * 		0.7 ---> move one step forward
 * 		0.3 ---> move two steps forward
 * motionStayProb: probability of keeping the robot where it is
 * 		1.0 ---> do not move
 * 		0.0 ---> robot is moved */
double motionMoveProb[] = { 0.7, 0.3 };
double motionStayProb[] = { 1.0, 0.0 };

/* observation probability given a door or not a door
 * 		0.8 ---> observe a door given there is a door
 * 		0.2 ---> observe no door given there is a door
 * 		0.9 ---> observe no door given there is no door
 * 		0.1 ---> observe a door given there is no door*/
double obsDoorProb[] = { 0.8, 0.2 };
double obsNotDoorProb[] = { 0.9, 0.1 };





//-----------------USEFUL FUNCTIONS-----------------//
//get Array size
template<typename T, int size>
int arraysize(T(&)[size]){return size;}

//Prints an Array
template<typename A> void printarray (A arg[],int arraylength) {
	for ( int n = 0; n < arraylength; n ++)
		cout << arg[n] << ", ";
	cout << "\n";
}

//Prints an Vector Array
template<typename A> void printvector(vector<A> arg) {
	for (int n = 0; n < arg.size(); n ++)
		cout << arg[n] << ", ";
	cout << "\n";
}

//Vector Sum Function
template<typename A> double vectorsum(vector<A> arg) {
  double sum = 0;
  for (int n = 0; n < arg.size(); n ++)
  	sum += arg[n];
  return sum;
}
//---------------------------------------------------//






/* Calculate motion probability
 * 		prePosiiton ---> the previous robot position
 * 		curPosition ---> the current robot position
 * 		control     ---> input control method: staying or moving */
double motionProb( int prePosition, int curPosition, bool control ) {
	double prob = 0;
	/* QUESTION 3 HERE */


	return prob;
}


/* Calculate observation probability */
double obsProb( bool obser, int position ) {
	double prob = 0;
	bool isDoor;
	/* QUESTION 4 HERE */


	return prob;
}

/* Update our belief */
vector<double> bayesFilter( vector<double> preBelief, bool control, bool observation ) {
	vector<double> curBelief;
	curBelief.resize( preBelief.size() );
	/* QUESTION 5 HERE */
	/* Hint: First implement the prediction step (Equation (3) in the notes) */
	/* 	 Then implement the update step (Equation (4) in the notes) */



	return curBelief;

}






/*--------------------------MAIN FUNCTION---------------------------*/
int main(int argc, char *argv[]) {
	vector<double> initBelief;
	int num = 20;
	initBelief.resize( num );
	// initialize the prior belief
	/* QUESTION 1 & 2 HERE */



	cout << "************  Q1 & Q2 **************************\n";
	cout << "The initialized probabilities are:\n";
	printvector( initBelief );
	cout << endl;





	/* Q3
	 * 		Calculate the probability given previous position,
	 * 		current position and control input
	 * 		Motion probability is given in motionMoveProb and
	 * 		motionStayProb */

	/* Testing your motionProb(...) function */
	int prePosition = 3, curPosition = 5;
	bool control = true;
	double mProb = motionProb( prePosition, curPosition, control );
	cout << "************  Q3 **************************\n";
	cout << "The motion probability is " << mProb << "\n";
	cout << endl;






	/* Q4
	 * 		Calculate the probability given observation and
	 * 		current position
	 * 		Observation probability is given in isDoorProb
	 * 		and noDoorProb */
	/* Testing your obsProb(...) function */
	bool observation = true;
	int position = 4;
	double oProb = obsProb( observation, position );
	cout << "************  Q4 **************************\n";
	cout << "The observation probability is " << oProb << "\n";
	cout << endl;




	/* Q5
	 * Testing your bayesFilter(...) function */
	vector<double> curBelief;
	curBelief = bayesFilter( initBelief, control, observation );
	cout << "************  Q5 **************************\n";
	cout << "Updated probabilities: \n";
	printvector( curBelief );
	cout << endl;




	/* Q6 HERE */
	/* Just call the bayesFilter(...) function 4 times according to the given
	   sequence of control inputs and observations */
	/* HINT: Look at Q5 Testing code */

	return(0);
}
