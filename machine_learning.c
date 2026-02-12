#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float train[][3] = {
    {0,0,0},
	{1,0,1},
    {0,1,1},
    {1,1,1},
};

float sigmoidf(float x){
	
	return 1.0f/(1.0f + expf(-x));

}

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void)
{    
    return (float) rand()/ (float) RAND_MAX;
}

float costf(float w1,float w2, float b){

    float result = 0.0f;
    for (size_t i=0 ;i < train_count; ++i){
    
       float x1 = train[i][0];
	   float x2 = train[i][1];
       float y = sigmoidf(x1*w1 + x2*w2 + b);
       float d = y - train[i][2];
       result +=d*d;
       
    };
    result /= train_count;

 
    return result;
};

int main(void) {

    srand(42);
    float eps  = 1e-3;
    float rate = 1e-3;

    float w1 = rand_float();
    float b  = rand_float();
	float w2 = rand_float();
	float c  = costf(w1,w2,b);

    for (size_t i = 0; i < 100*1000; ++i){

        float dw1 = (costf(w1 + eps,w2,b) - c)/eps;
		float dw2 = (costf(w1,w2+eps,b) - c)/eps;
        float db  = (costf(w1,w2, b + eps) - c)/eps;

        w1 -= dw1*rate;
		w2 -= dw2*rate;
        b  -= db*rate;

		//printf("avg cost: %f\n", costf(w1,w2,b));
    };

    for (size_t i=0 ; i< train_count; ++i){

        float x1 = train[i][0];
		float x2 = train[i][1];
        float y  = sigmoidf(x1*w1 + x2*w2 + b) ;
        float deltaf = (train[i][2]-y)/(train[i][2]);


        printf("Learned value: %f, Expected value: %f,Discrepancy:%f\n", y,train[i][2], deltaf);
	};

	printf("--------Parameters--------\n");
	printf("w1 = %f , w2 = %f , b = %f\n", w1,w2,b);
	printf("With cost: %f\n", costf(w1,w2,b));
	
	return 0;

}
