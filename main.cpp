// brute force solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> rotate(vector<int> arr, int n){     // function that rotate three elements
    int temp = arr[n - 1];
    arr[n - 1] = arr[n];
    arr[n] = arr[n + 1];
    arr[n + 1] = temp;  
    return arr;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int size;
        cin >> size;
        vector <int> arr(size);
        for(int i = 0; i < size; i++)
            cin >> arr[i];
        for(int i = 0; i < size - 3; i++){      // in this "for" loop, we are going to sort array
            if(arr[i] != i + 1){                // by searching for each number, from 1 to size-3 ...
                int iter = i + 1;
                while(arr[iter] != i + 1)
                    iter++;
                if(iter == size - 1){
                    arr = rotate(arr, iter - 1);
                        iter--;
                }
                while(arr[i] != i + 1){         // ... and moving it using only rotation function 
                    arr = rotate(arr, iter);    // described in problem specyfication ("readme" file)
                    iter--;
                }
            }  
        }
        for(int i = 0; i < 3; i++){             // we rotate last 3 numbers (rest can always be sorted, for any valid input)
            if(arr[size - 3] < arr[size - 2] && arr[size - 2] < arr[size - 1]){
                cout << "YES" << endl;          
                break;
            }else{
                arr = rotate(arr, size - 2);
            }
        }
        if(arr[size - 3] > arr[size - 2] || arr[size - 2] > arr[size - 1])      
            cout << "NO" << endl;
        
    }
    return 0;
}
