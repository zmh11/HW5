#include <iostream>
#include <vector>
#include <string>
#include "hw5.h"

/***
 * 
 **/
void Swap(std::vector<std::string> &vec, int a, int b){
  std::string temp = vec[a];
  vec[a] = vec[b];
  vec[b] = temp;
  }
void BubbleSort(std::vector<std::string> &vec){
  for( int k = 0; k < vec.size()-1; k++){
    for( int i = k+1; i < vec.size(); i++)
    {
      if( vec[k].compare(vec[i]) > 0) 
        Swap( vec, k, i);
    }
  }
} 

/***
 * 
 **/
void InsertionSort_helper(std::vector<int>& v, int size){
  if(size <= 1)
    return;
  InsertionSort_helper(v, size-1);
  int end = v[size - 1];
  int move = size - 2;

  while (move >= 0 && end < v[move]){
    v[move + 1] = v[move];
    move--;
  }
  v[move + 1] = end;

  
}
void InsertionSort(std::vector<int>& v){
  InsertionSort_helper(v, v.size());
}