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
    if (control==true){
        if ((curPosition-prePosition == 1)||(curPosition ==1) && (prePosition == 20) )
            prob = motionMoveProb[0];
        else if ((curPosition-prePosition == 2)||(curPosition ==2) && (prePosition == 20)||(curPosition ==1) && (prePosition == 19) )
            prob = motionMoveProb[1];
        else
            prob = 0;
    }
    else {
        if (curPosition==prePosition)
            prob = motionStayProb[0];
        else
            prob = motionStayProb[1];
    }

	return prob;
}


/* Calculate observation probability */
double obsProb( bool obser, int position ) {
	double prob = 0;
    bool isDoor;

	/* QUESTION 4 HERE */

    if ((position == 3) || (position == 5) || (position == 8)){
        if (obser == true)
            prob = obsDoorProb[0];
        else
            prob = obsDoorProb[1];
    }
     else {
        if (obser == true)
            prob = obsNotDoorProb[1];
        else
            prob = obsNotDoorProb[0];

    }


	return prob;
}

/* Update our belief */
vector<double> bayesFilter( vector<double> preBelief, bool control, bool observation ) {
    vector<double> curBelief;
    vector<double> currBelief;

    double normalizer = 0;

	curBelief.resize( preBelief.size() );
    currBelief.resize( preBelief.size() );
	/* QUESTION 5 HERE */
	/* Hint: First implement the prediction step (Equation (3) in the notes) */
	/* 	 Then implement the update step (Equation (4) in the notes) */

    int num = curBelief.size();

    //  PREDICTION
    for (int k = 0; k<num; k++){
        curBelief[k] = 0;
        for (int i = 0; i<num; i++){
        double motion_prob =  motionProb(i+1,k+1,control);
        curBelief[k] += preBelief[k] *  motion_prob;
        }
    }

    //  UPDATING
    for (int k = 0; k<num; k++){
        currBelief[k] = 0;
        for (int i = 0; i<num; i++){

            normalizer += obsProb(observation,i+1)*curBelief[i];

        }
        currBelief[k] = (1./normalizer)*obsProb(observation,k+1)*curBelief[k];
    normalizer=0;
    }

    return currBelief;

}






/*--------------------------MAIN FUNCTION---------------------------*/
int main(int argc, char *argv[]) {
	vector<double> initBelief;
	int num = 20;
	initBelief.resize( num );
	// initialize the prior belief
	/* QUESTION 1 & 2 HERE */

    for(int i = 0; i<num; i++)
        initBelief[i]=1./20;




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
    int position = 5;
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
    vector<double> curBelief1, curBelief2, curBelief3, curBelief4;
    curBelief1 = bayesFilter( initBelief, 0, 1);
    curBelief2 = bayesFilter( curBelief1, 1, 0);
    curBelief3 = bayesFilter( curBelief2, 1, 1);
    curBelief4 = bayesFilter( curBelief3, 1, 1);

    cout << "************  Q6 **************************\n";
    cout << "Updated probabilities of curBelief1(u=0,z=1): \n";
    printvector( curBelief1 );
    cout << endl;

    cout << "Updated probabilities of curBelief2(u=0,z=1): \n";
    printvector( curBelief2 );
    cout << endl;

    cout << "Updated probabilities of curBelief3(u=0,z=1): \n";
    printvector( curBelief3 );
    cout << endl;

    cout << "Updated probabilities of curBelief4(u=0,z=1): \n";
    printvector( curBelief4 );
    cout << endl;

    double sum = 0;

    for(int i=0; i<20; i++){
        sum += curBelief1[i];
    }
    cout << sum<< endl;

	return(0);
}
