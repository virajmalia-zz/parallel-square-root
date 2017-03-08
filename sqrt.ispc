task void launchedSquareRoot(float* uniform n,uniform int N,float* uniform result, uniform int width){
	uniform int start=taskIndex*width;
	uniform int stop=start+width-1;
	uniform float e=0.0001;
	foreach (i=start...stop){
        	float x = n[i];
        	float y = 1;
	

	 while(x - y > e){
        	x = (x + y)/2;
		y = n[i]/x;
        }
        result[i] = x;
	}
}

export void squareRoot(float* uniform n,uniform int N,float* uniform result){
	uniform int width = 15000000;
	uniform int factor = 5;
	launch[factor] launchedSquareRoot(n, N, result, width/factor);
	sync;   
}
