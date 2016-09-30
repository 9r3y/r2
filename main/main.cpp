// A simple program that computes the square root of a number
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include "R2Config.h"
using namespace std;

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[]) {

	string str = "佛恩爱狗";
	wchar_t c = '风';
	cout << str;
//  if (argc < 2) {
//    fprintf(stdout, "%s Version %d.%d\n", argv[0], R2_VERSION_MAJOR,
//            R2_VERSION_MINOR);
//    fprintf(stdout, "Usage: %s number\n", argv[0]);
//    return 1;
//  }
//
//  double inputValue = atof(argv[1]);
//  double outputValue = 0;
//
//  if (inputValue >= 0) {
//#ifdef USE_MYMATH
//    outputValue = mysqrt(inputValue);
//#else
//    outputValue = sqrt(inputValue);
//#endif
//  }
//
//  fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
	return 0;
}
