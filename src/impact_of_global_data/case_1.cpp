// Analysis - Impact of using global data: Case 1 - 

#include <chrono>
#include <bits/stdc++.h>
using namespace std;

int main(){
    const int length = 1024*1024; // #cache lines = length/64
    
    //Data
    int arr[length];

    //For each value of STEP in the set S = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}
    for(int STEP=1;STEP<=1024;STEP*=2){

        auto start = chrono::high_resolution_clock::now();

        //Generalized Task
        for(int i=0;i<length;i+=STEP){
            arr[i] *= 3;
        }

        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;

        cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
    }
    
    return 0;
}
