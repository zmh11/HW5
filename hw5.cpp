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

/***
 * 
 **/
void Merge(std::vector<std::string> &vec, int l, int m, int r){
  int ls = m -l + 1;
  int rs = r - m;

  std::string tempLeft[ls];
  std::string tempRight[rs];

  for(int k = 0; k < ls; k++)
    tempLeft[k] = vec[l+k];

  for (int k = 0; k < rs; k++)
    tempRight[k] = vec[m+1+k];
  
  int right = 0;
  int left = 0;
  int place = l;

  while( right < rs && left < ls){
    if( tempLeft[left].compare(tempRight[right]) <= 0){
      vec[place] = tempLeft[left];
      left++;
    }
    else {
      vec[place] = tempRight[right];
      right++;
    }
    place++;
    }

  while( left < ls){
    vec[place] = tempLeft[left];
    left++;
    place++;
    }

    while( right < rs){
    vec[place] = tempRight[right];
    right++;
    place++;
    }
  }

void MergeSort_helper(std::vector<std::string> &vec, int l, int r){
  if ( l<r ){
    int middle = l + (r-l)/2; 
    MergeSort_helper(vec,  l,  middle);
    MergeSort_helper(vec, middle+1,r);
    Merge(vec, l, middle, r);
  }
}
void MergeSort(std::vector<std::string> &vec){
  MergeSort_helper(vec, 0, vec.size()-1);
}