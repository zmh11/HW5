#include <iostream>
#include <vector>
#include <string>
#include "hw5.h"

/***
 * Swap (vector int a , int b)
 *  temp =  vector[a];
 *  vector[a] = vector[b]
 *  vector[b] = temp 
 **/
void Swap(std::vector<std::string> &vec, int a, int b){
  std::string temp = vec[a];
  vec[a] = vec[b];
  vec[b] = temp;
  }

/***
 * bubble sort (vector)
 * for ( k = 0 k< vector_size -1 k++ )
 *  for( i = k+1 k<vector_size i++)
 *    if( vector[k].compare(vector[i]) > 0)
 *      swap (vector, k, i)
 ***/ 
void BubbleSort(std::vector<std::string> &vec){
  for( int k = 0; k < vec.size()-1; k++ ){
    for( int i = k+1; i < vec.size(); i++ )
    {
      if( vec[k].compare(vec[i]) > 0 ) 
        Swap( vec, k, i);
    }
  }
} 

/***
 * insertion sort( vector, int n) 
 * 
 * int i, k, key
 * for(i = 1 i<n i++){
 *  key=vector[i]
 *  k = i -1
 *  while (j>=0 && vector[k] > k){
 *    vector[i+1]= vector[k]
 *    k = k-1}
 *    vector[k+1] = key}
 **/
void InsertionSort_helper(std::vector<int>& v, int size){
  if( size <= 1 )
    return;
  InsertionSort_helper(v, size-1);
  int end = v[size - 1];
  int move = size - 2;

  while ( move >= 0 && end < v[move] ){
    v[move + 1] = v[move];
    move--;
  }
  v[move + 1] = end;  
}
void InsertionSort(std::vector<int>& v){
  InsertionSort_helper(v, v.size());
}

/***
 * Merge (vector, int l, int m, int r)
 *  create a sub vector of vector[1-m]
 *  create a sub vector of vector[m+1-r]
 *  
 *  recombine sub arrays looking comparing first
 *  value in each
 *  place the smallest value of the two back into Vector
 *  
 *  place any remaning in subvectors at end of vector
 *  
 **/
void Merge(std::vector<std::string> &vec, int l, int m, int r){
  int ls = m - l + 1;
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

  while( right < rs && left < ls ){
    if( tempLeft[left].compare(tempRight[right] ) <= 0){
      vec[place] = tempLeft[left];
      left++;
    }
    else {
      vec[place] = tempRight[right];
      right++;
    }
    place++;
    }

  while( left < ls ){
    vec[place] = tempLeft[left];
    left++;
    place++;
    }

    while( right < rs ){
    vec[place] = tempRight[right];
    right++;
    place++;
    }
  }

/***
 * MergeSort helper(vector, int l, int r)
 * if ( l<r ){
 *  MergeSort helper(vector,  l,  middle)
 *  MergeSort helper(vector,  middle+1,  r)
 *  Mearge (vector,  l,  middle, r)
 * }
 **/
void MergeSort_helper(std::vector<std::string> &vec, int l, int r){
  if ( l<r ){
    int middle = l + (r-l)/2; 
    MergeSort_helper(vec,  l,  middle);
    MergeSort_helper(vec, middle+1,r);
    Merge(vec, l, middle, r);
  }
}

/***
 * merge sort (vector)
 *  MergeSort_helper(vector, 0, vector.size()-1)
 **/
void MergeSort(std::vector<std::string> &vec){
  MergeSort_helper(vec, 0, vec.size()-1);
}