// Analysis - Impact of using local data - Implementation of Condition 1:

#include <iostream>
#include <chrono>

int main(){
    
    int LOOP_LIMIT = 10;
    
    for(int i=0;i<LOOP_LIMIT;i++){
        
        auto start = std::chrono::high_resolution_clock::now();

            int p[5]; //This will never cause page fault
            if(i==0){
                p[0] = 977;
                for(int j=1;j<5;j++){
                    p[j] = p[j-1]+1;
                }
            }
            for(int j=0;j<5;j++){
                
                std::cout << "J:" << j << " Address of p[j]:" << (&p[j]); 
                
                std::cout << " Value of p[j]: " << p[j] << std::endl;
            }

    auto end = std::chrono::high_resolution_clock::now();
        
        auto single_run_time = std::chrono::duration_cast<std::chrono::nanoseconds>
        
        (end - start).count();
        
        std::cout << "Single run time: " << single_run_time << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
}
