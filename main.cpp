#include<iostream>
#include<random>
#include<ctime>
#include "sqrt_ispc.h"

using namespace std;

int main(){
    long long unsigned int N = 15000000;
    float* input = new float[N];
    float* output = new float[N];
    
    float lo=0.0, hi=5.0;
    
    struct timespec start, finish;
    double elapsed;
    
    srand(time(NULL));
    
    for(int i=0; i<N; i++)
        input[i] = lo + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(hi - lo)));;

	clock_gettime(CLOCK_MONOTONIC, &start);
	ispc::squareRoot(input, N, output);
	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

	cout<<"Elapsed Time: "<<elapsed<<endl;
    return 0;
}
