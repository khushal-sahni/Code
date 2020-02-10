#include <iostream>
using namespace std;
struct petrolPump{
  int petrol;
  int distance;
};

int tour(petrolPump p[],int n){
  int fuel = p[0].petrol;
  int distance = fuel-(p[0].distance);
  int i = 1,startingPoint = 0, count = 0;
  if(n == 1) return 0;
  while(count < 2){
    if(i == 0) count++;
    if(i == startingPoint && distance >= 0) return i;
    if(distance < 0){
      startingPoint = i;
      fuel = p[i].petrol;
      distance = fuel-(p[i].distance);
    }
    else{
      distance += p[i].petrol;
      distance -= p[i].distance;
    }
    i++;
    if(i == n) i = 0;
  }
  return -1;
}
