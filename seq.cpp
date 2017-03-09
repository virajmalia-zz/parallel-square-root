#include<iostream>
#include<ctime>
#include<random>

using namespace std;

/*Returns the square root of n.*/
float squareRoot(float n)
{
  float x = n;
  float y = 0;
  float e = 0.0001; /* e decides the accuracy level*/
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
 
int main(){

  long long unsigned int N = 15000000;
    float* input = new float[N];
    float* output = new float[N];
    
    float lo=0.0, hi=5.0;
    
    struct timespec start, finish;
    double elapsed;
    
    srand(time(NULL));
    
    for(int i=0; i<N; i++)
        input[i] = lo + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(hi - lo)));
	
  clock_gettime(CLOCK_MONOTONIC, &start);
  for(unsigned int i=0; i<15000000; i++){
    
	output[i] = squareRoot(input[i]); 
  }
  
  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  for(int i=0; i<16; i++){
        cout.precision(4);
        cout<<output[i]<<endl;
  }

  cout<<"Elapsed Time: "<<elapsed<<endl;      //89.78 sec p=87.98

  return 0;
}
