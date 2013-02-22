/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 21, 2013, 2:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

void min_max(vector<int> & input_arr, int & min, int & max) {
        
    int i=0;
    int size = input_arr.size();
    min = max = 0;
    
    if(size%2) {
       min = max = input_arr[0]; 
       i = 1;
    }

    
    while(i < size) {
        int temp_min, temp_max;
        if(input_arr[i] < input_arr[i+1]) {
            temp_min = input_arr[i];
            temp_max = input_arr[i+1];
        }
        else {
            temp_min = input_arr[i+1];
            temp_max = input_arr[i];
        }
        if(temp_min < min) {
            min = temp_min;
        }
        if(temp_max > max) {
            max = temp_max;
        }
        i = i+2;
    }
}

int main(int argc, char** argv) {

    vector<int> input_array;
    
    int min, max, number = 0, element = 0;
    
    cout << "Enter the number of elements in the array" << endl;
    cin >> number;
    
    cout << "Enter the numbers" << endl;
    for(int i=0; i<number; i++){
        cin >> element;
        input_array.push_back(element);
    }
    
    min_max(input_array, min, max);
    
    cout << "The min value in the array is: " << min << endl;
    cout << "The max value in the array is: " << max << endl;
}

