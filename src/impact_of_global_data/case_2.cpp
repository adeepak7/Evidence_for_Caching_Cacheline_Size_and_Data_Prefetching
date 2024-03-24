// Analysis - Impact of using global data: Case 2 - 

#include <chrono>
#include <bits/stdc++.h>
using namespace std;

int main(){

    int STEP = 16;
    int RUN_LIMIT = (int)10e6;
    double time_taken = 0.0;
    const int length = 1024*1024;
    
    //Data
    int arr[length];

    for(int run=1; run<=RUN_LIMIT; run++){

        auto start = chrono::high_resolution_clock::now();

        //Generalized Task
        for(int i=0;i<length;i+=STEP){
            arr[i] *= 3;
        }

        auto end = chrono::high_resolution_clock::now();
        auto single_run_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken += single_run_time;
    }    
    
    //Average
    time_taken = time_taken / (double)RUN_LIMIT;
    
    cout << "Time taken for STEP = " << STEP << fixed << time_taken << setprecision(9);
    
    return 0;
}
