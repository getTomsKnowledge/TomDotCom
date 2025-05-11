#include <stdint.h>

#ifndef PRIMORIALS_15_H
#define PRIMORIALS_15_H

const uint64_t P0  = 1;                        //1
const uint64_t P1  = 2;                        //1*2
const uint64_t P2  = 6;                        //1*2*3
const uint64_t P3  = 30;                       //1*2*3*5
const uint64_t P4  = 210;                      //1*2*3*5*7
const uint64_t P5  = 2310;                     //1*2*3*5*7*11
const uint64_t P6  = 30030;                    //1*2*3*5*7*11*13
const uint64_t P7  = 510510;                   //1*2*3*5*7*11*13*17
const uint64_t P8  = 9699690;                  //1*2*3*5*7*11*13*17*19
const uint64_t P9  = 223092870;                //1*2*3*5*7*11*13*17*19*23
const uint64_t P10 = 6469693230;               //1*2*3*5*7*11*13*17*19*23*29
const uint64_t P11 = 200560490130;             //1*2*3*5*7*11*13*17*19*23*29*31
const uint64_t P12 = 7420738134810;            //1*2*3*5*7*11*13*17*19*23*29*31*37
const uint64_t P13 = 304250263527210;          //1*2*3*5*7*11*13*17*19*23*29*31*37*41
const uint64_t P14 = 13082761331670030;        //1*2*3*5*7*11*13*17*19*23*29*31*37*41*43
const uint64_t P15 = 614889782588491410;       //1*2*3*5*7*11*13*17*19*23*29*31*37*41*43*47

const int P0_LOG2  = 0;  //floor(log2(P0))
const int P1_LOG2  = 1;  //floor(log2(P1))...
const int P2_LOG2  = 2;  //...
const int P3_LOG2  = 4;
const int P4_LOG2  = 7;
const int P5_LOG2  = 11;
const int P6_LOG2  = 14;
const int P7_LOG2  = 18;
const int P8_LOG2  = 23;
const int P9_LOG2  = 27;
const int P10_LOG2 = 32;
const int P11_LOG2 = 37;
const int P12_LOG2 = 42;
const int P13_LOG2 = 48;
const int P14_LOG2 = 53;
const int P15_LOG2 = 59;

#endif
