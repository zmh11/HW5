#include <iostream>
#include <vector>
#include <string>
#include "hw5.h"

/***
 * 
 **/
void swap(std::vector<std::string> &vec, int a, int b){
  std::string temp = vec[a];
  vec[a] = vec[b];
  vec[b] = temp;
  }
void BubbleSort(std::vector<std::string> &vec){
  for( int i = 0; i < vec.size(); i++ )
    for( int k = 0; k < vec.size()-i; k++ ){
      if( vec[i].compare(vec[k]) ){
        swap(vec, i, k);
      }
    }
} 