export void squareRoot(float* uniform n,uniform int N,float* uniform result)
{
    uniform float e = 0.0001;

    foreach (i=0...N){
        float x = n[i];
        float y = 1;
   
        while(x - y > e){
            x = (x + y)/2;
            y = n[i]/x;
        }    
        result[i] = x;
    }
}