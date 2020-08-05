#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

double * getBesselArray(int x, double * J){
  for (int i = 8; i >= 0; i--){
    J[i] = (2 * (i+1) * J[i+1] / x) - J[i+2];
  }
  return J;
}


int main(){

  double * J1 = malloc(sizeof(double) * SIZE);
  J1[10] = 0.00000000026306, J1[9] = 0.0000000052492;

  double * J5 = malloc(sizeof(double) * SIZE);
  J5[10] = 0.0014678, J5[9] = 0.0055202;

  double * J50 = malloc(sizeof(double) * SIZE);
  J50[10] = -0.11384, J50[9] = -0.027192;

  J1 = getBesselArray(1, J1);
  J5 = getBesselArray(5, J5);
  J50 = getBesselArray(50, J50);

  printf("J_0(1) = %f\n", J1[0]);
  printf("J_0(5) = %f\n", J5[0]);
  printf("J_0(50) = %f\n", J50[0]);

  // // Diagnosing where J1 goes awry
  //
  // for(int i = 0; i < SIZE; i++){
  //   printf("J_%d(1) = %f\n", i, J1[i]);
  // }

  free(J1); free(J5); free(J50);

  return 0;
}


// Absolute values = 2.6306151237e-10 0.0014678026473   -0.11384784915
// Calculated values = 560.553310     0.001585          -0.113845
// Absolute error = 560.55331000026   0.000117            0.00000284915
// Relative error = 2.1308e08         0.079               2.5026e-05
