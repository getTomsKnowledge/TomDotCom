
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

int main(){
//Test:

  //Check for two factors:
  //n ~ p*q
  //y^2 - yx - n = 0; y(y - x) = n --> if n has square root, y is 0;
  //for n = 7, x = 1 and y = 6;
  //for n = 10, {(9,10), (5,3)} --> {(10,1), (5,2)}
  //Getting into quadratic formula: y = x/2 + sqrt(x^2 - 4*(-n))/2
  // x - y = p, y = q
  uint64_t n = 105;
  uint64_t x = 0;
  uint64_t y = 0;
  uint64_t p = 1;
  uint64_t q = 1;
  uint64_t lowerBound = (uint64_t)floor((sqrt((double)n)))/2;
  uint64_t upperBound = (uint64_t)ceil(n/2);
  uint64_t testFactors = 0;
  for(uint64_t i = lowerBound; i < upperBound; i++){
    x = i;
    y = (uint64_t)(((double)x + (sqrt((double)(x*x) + 4*((double)n))))/2);
    if (x == 16){
      printf("x is %ld and y is %ld .\n\n", x, y);
    }
    testFactors = y * (y - x);
    if(n == testFactors){
      p = y - x; //lesser factor
      q = y; //greater factor
      break;
    }
  }

  printf("p is %ld and q is %ld .\n\n", p, q);
  printf("test factor: x %ld , y %ld , testFactors %ld ", x , y , testFactors );
  return 0;
}
