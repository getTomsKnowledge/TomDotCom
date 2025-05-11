#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "Primorials_15.h"

#define MAX_RANDOM_NUMBER 0x7fffffff
#define UNSIGNINT64_MAX 0x7fffffffffffffff

int main(){
  // DECLARATIONS:
  bool heads = false;
  bool isEven = false;
  uint64_t n = 0;

  // Seed rand with current time
  srand(time(NULL));
  // Generate random number
  double randomRemainder = rand()/(double)RAND_MAX;
  printf("%f\n", randomRemainder);
  if (randomRemainder > 0.5){
    heads = true;
  }
  n = (randomRemainder*(UNSIGNINT64_MAX));
  if (heads) {
    n += 1;
  }
  printf("%" PRIu64 "\n", n);

  // Even?
  short lsb = n & 0x1;
  if (lsb == 0){
    isEven = true;
  }
  if (isEven){
    printf("Even\n");
    return 0;
  } else {
    printf("Odd\n");
  }

  //Big?
  short msb = 0;
  bool isBig = false;
  for (int i = 0; i < 10; i++){
    msb = n >> 63 - i;
    if (msb == 1){
      isBig = true;
      printf("Big\n");;
    }
  }
  if (!isBig){
    printf("Small\n");
  }

  //Primorial?
  bool isPrimorial = false;
  uint64_t primArray[16];
  primArray[0] = P0;
  primArray[1] = P1;
  primArray[2] = P2;
  primArray[3] = P3;
  primArray[4] = P4;
  primArray[5] = P5;
  primArray[6] = P6;
  primArray[7] = P7;
  primArray[8] = P8;
  primArray[9] = P9;
  primArray[10] = P10;
  primArray[11] = P11;
  primArray[12] = P12;
  primArray[13] = P13;
  primArray[14] = P14;
  primArray[15] = P15;

  int pLimit = 0;
  //printf("The largest primorial in this program is P15, or %" PRIu64 ".\n",primArray[15]);

  if (isBig) {
    for (int i = 14; i < 16; i++){
      if (n == primArray[i]){
        isPrimorial = true;
        printf("Big Primorial\n");
      } else {
        if (n < primArray[i]){
          pLimit = i;
          printf("Less than P%d , greater than P%d.\n", i, i-1);
        } else if (i == 15) {
          pLimit = 16;
          printf("Less than P16, Greater than P15.\n");
        }
      }
    }
  } else {
    for (int i = 0; i < 13; i++){
      if (n == primArray[i]){
        isPrimorial = true;
        printf("Small Primorial\n");
      } else {
        if (n < primArray[i]){
          pLimit = i;
          printf("Less than P%d , greater than P%d.\n", i, i-1);
          break;
        } else if (i == 12) {
          pLimit = 13;
          printf("Less than P13, Greater than P12.\n");
          break;
        }
      }
    }
  }

  //Maximum number of possible factors?
  int twoArray[16];
  twoArray[0] = P0_LOG2;
  twoArray[1] = P1_LOG2;
  twoArray[2] = P2_LOG2;
  twoArray[3] = P3_LOG2;
  twoArray[4] = P4_LOG2;
  twoArray[5] = P5_LOG2;
  twoArray[6] = P6_LOG2;
  twoArray[7] = P7_LOG2;
  twoArray[8] = P8_LOG2;
  twoArray[9] = P9_LOG2;
  twoArray[10] = P10_LOG2;
  twoArray[11] = P11_LOG2;
  twoArray[12] = P12_LOG2;
  twoArray[13] = P13_LOG2;
  twoArray[14] = P14_LOG2;
  twoArray[15] = P15_LOG2;


  bool tooBig = false;
  int maxFactors = 0;
  if (pLimit < 16){
    maxFactors = twoArray[pLimit];
  } else {
    tooBig = true;
    maxFactors = twoArray[15];
  }

  printf("\n\nMaximum number of factors is %d.\n\n", maxFactors);

  //Check for two factors:
  //n ~ p*q
  //y^2 - yx - n = 0; y(y - x) = n --> if n has square root, y is 0;
  //for n = 7, x = 1 and y = 6;
  //for n = 10, {(9,10), (5,3)} --> {(10,1), (5,2)}
  //Getting into quadratic formula: y = x/2 + sqrt(x^2 - 4*(-n))/2
  // x - y = p, y = q
  double determinant;
  double decimal;
  uint64_t x = 0;
  uint64_t y = 0;
  uint64_t p = 1;
  uint64_t q = 1;
  uint64_t lowerBound = (uint64_t)floor((sqrt((double)n)))/2;
  uint64_t upperBound = (uint64_t)ceil(n/2);
  uint64_t testFactors = 0;
  for(uint64_t i = lowerBound; i < upperBound; i++){
    x = i;
    determinant = sqrt((double)(x*x) + 4*(double)n);
    decimal = determinant - (int)determinant;
    if (decimal == 0) {
      y = (uint64_t)(((double)x + determinant)/2);
      testFactors = y * (y - x);
      if(n == testFactors){
        p = y - x; //lesser factor
        q = y; //greater factor
        break;
    }
  }
  }
  printf("p is %ld and q is %ld .\n\n", p, q);





  return 0;
}
