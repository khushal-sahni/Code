#include <iostream>
using namespace std;
#include <utility>

void swim(int arr[], int i){
  while(i > 0 && arr[i]>arr[(i-1)/2]){
    swap(arr[i],arr[(i-1)/2]);
    i = (i-1)/2;
  }
}

void sink(int arr[], int n, int i){
  while((2*i + 1) < n){
    int j = 2*i + 1;
    if(j < n-1 && arr[j] < arr[j+1]) j++;
    if(arr[i] < arr[j]) swap(arr[i],arr[j]);
    i = j;
  }
}

void heapify(int arr[], int n, int i)  {
  sink(arr,n,i);
}

void buildHeap(int arr[], int n)  {
    for(int i = 1; i < n; i++) swim(arr,i);
}

void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
  int arr[] = {4,1,3,9,7};
  heapSort(arr,5);
  for(int i = 0; i < 5; i++) cout << arr[i] << " ";
}
