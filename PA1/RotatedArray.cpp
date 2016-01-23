// CSE 101 Winter 2016, PA 1
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help: 
// Due: 1/22/2016 at 11:59 PM

#include <iostream>
#include <chrono>
#include <list>
#include <stdlib.h>

// you can change SIZE to vary the size of array
#define SIZE 1000000000

// returns the index of the element found in the list
int naive_search(int * list, int e) {
    for(int i = 0;i<SIZE;i++){
        if (list[i]==e){
            return i;
        }
    }
    return -1;
}

// returns the index of the found element

/*int rs(int * list, int e, int s, int t){
    if(list[s]==e){
        return s;
    }else if(list[s]<e){
        return s-list[s]+e;
    }else if(list[s]>e){
        return t -(list[s]-e)+1;
    }
}*/

int bs(int * list, int e, int s, int t){
    if(s>t){
            return -1;
    }else{
        if(list[(s+t)/2]>e){
            return bs(list,e,s,(s+t)/2);
        }else if(list[(s+t)/2]<e){
            return bs(list,e,(s+t)/2+1,t);
        }else{
            return (s+t)/2;
        }
    }
}

int rs(int * list, int e, int s, int t){
    int a = list[s];
    int b = e;
    int c = list[(s+t)/2];
    if(a==b){ return s; }
    else if(b==c){ return (s+t)/2; }
    else if(a>b&&b>c){ return bs(list,e,(s+t)/2+1,t); }
    else if(c>b&&b>a){ return bs(list,e,s,(s+t)/2); }
    else if(a>c){ return rs(list,e,s,(s+t)/2); }
    else{ return rs(list,e,(s+t)/2+1,t); }
}

int DQ_search(int * list, int e) {
    return rs(list,e,0,SIZE-1);
}



// This main is already fully implemented. However, you are free
// to modify it if you feel necessary (i.e. running multiple queries
// for larger array sizes instead of running one query per run)
int main(int argc, char * argv[]) {
    std::cout << "Running Rotated Sorted Array with size: " << SIZE << std::endl;
    int * arr = new int[SIZE];

    // build the rotated array using the random rotation point
    srand(time(0));
    int rotation = rand() % SIZE;
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = (i + rotation) % SIZE + 1;
    }

    int target = rand() % SIZE + 1;

    // time the naive approach
    auto begin = std::chrono::high_resolution_clock::now();

    int loc_naive = naive_search(arr, target);

    auto end = std::chrono::high_resolution_clock::now();

    int elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();

    std::cout << "Time for Naive Search: " << elapsed_time << "us" << std::endl;

    // time the DQ approach
    begin = std::chrono::high_resolution_clock::now();

    int loc_DQ = DQ_search(arr, target);

    end = std::chrono::high_resolution_clock::now();

    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count();

    std::cout << "Time for DQ Search: " << elapsed_time << "us" << std::endl;

    if (loc_naive != loc_DQ) {
        std::cout << "ERROR, indicies returned by naive and DQ do not match." << std::endl;
    }
    if (target != arr[loc_naive]) {
        std::cout << "ERROR, index found by naive does not match target." << std::endl;
    }
    if (target != arr[loc_DQ]) {
        std::cout << "ERROR, index found by DQ does not match target." << std::endl;
    }

    delete arr;
    return 0;
}
