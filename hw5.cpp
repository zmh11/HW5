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