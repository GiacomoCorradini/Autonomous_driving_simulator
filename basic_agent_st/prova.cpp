#include <stdio.h>
#include <algorithm>
#include <array>

using namespace std;

int main(){

  double a_saturate = 3;
  double req_acc = -5;
  double acc;

  double m1[6] = {1,2,3,4,5,6};
  double m2[6] = {0,0,0,0,0,0};

  if(req_acc >= 0) acc = std::min(req_acc, a_saturate);
  else acc = std::max(req_acc, -a_saturate);

  printf("%f\n",acc);

  acc = std::min(std::max(req_acc, -a_saturate), a_saturate);

  printf("%f\n",acc);

  std::copy(std::begin(m1),std::end(m1),std::begin(m2));

  for(int i = 0; i < 6; i++){
    printf("%f\n",m2[i]);
    static int inter = 0;
    printf("%d\n", inter++);
  }



}