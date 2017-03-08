#include<iostream>
#include<ctime>

using namespace std;

/*Returns the square root of n.*/
float squareRoot(float n)
{
  float x = n;
  float y = 1;
  float e = 0.0001; /* e decides the accuracy level*/
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
 
int main(){

  float n;
  float lo=0.0, hi=5.0;
  srand(time(NULL));

  struct timespec start, finish;
  double elapsed;

  clock_gettime(CLOCK_MONOTONIC, &start);

  for(unsigned int i=0; i<15000000; i++){
    n = lo + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(hi - lo)));
    cout.precision(4);
    cout<<"Square root of "<<n<<" is "<<squareRoot(n)<<"  Iteration: "<<i<<endl;
  }
  
  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

  cout<<"Elapsed Time: "<<elapsed<<endl;      //89.78 sec p=87.98

  return 0;
}