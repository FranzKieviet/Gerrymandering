#include <iostream>
using namespace std; 
#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1

//Mapmaking Info:
const int ROWS=5;
const int COLS=4;

const int NUMP=4;  //Number of voters/precincts per district
const int NUMD=5;   //Number of districts per map
const int MARGIN=1; //How much do you want extra?

const int OPTIMALSCORE=NUMP / 2 + MARGIN;
 
#endif