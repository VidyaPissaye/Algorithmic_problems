/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 21, 2013, 4:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
void swap(int & x, int & y) {

    int temp = y;
    y = x;
    x = temp;
}

int partition(vector<int> & in_arr, int p, int r) {
    
    int x = in_arr[r];
    
    int i = p-1;
    for(int j = p; j<r; j++) {
        if(in_arr[j] < x) {
            i++;   
            swap(in_arr[i], in_arr[j]);
        }
    }
    
    swap(in_arr[r], in_arr[i+1]);
    
    return(i+1);
}

int randomized_partition(vector<int> & in_arr, int p, int r) {
    srand(time(NULL));
    int pivotidx = p + rand() % (r-p+1);
    swap(in_arr[r], in_arr[pivotidx]);
    
    return(partition(in_arr, p, r));
    
}

int ith_smallest(vector<int> & in_arr, int p, int r, int i) {
        
    if(p == r) {
        return in_arr[p];
    }
    else {
        int pivot = randomized_partition(in_arr, p, r);
        int k = (pivot-p)+1;
        if(i == k){
            return(in_arr[pivot]);
        }
        else if(i < k) {
            return(ith_smallest(in_arr, p, pivot-1, i));
        }
        else {
            return(ith_smallest(in_arr, pivot+1, r, i-k));
        }
    }
}
        
int main(int argc, char** argv) {

    vector<int> input_array;
    int element = 0, number = 0;
    
    cout << "Enter the number of elements in the array" << endl;
    cin >> number;
    
    cout << "Enter the numbers" << endl;
    for(int i=0; i<number; i++){
        cin >> element;
        input_array.push_back(element);
    }
    
    int i = number - 3;
    
    int ith_smallest_elem = ith_smallest(input_array, 0, number-1, i);
    
    cout << "The ith smallest element is: " << ith_smallest_elem << endl;
}

