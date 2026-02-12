#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct neuron{
	
	float w[10];
	float in[10];
	float out[10];
	struct neuron*set;

} neuron_s, neuron_t;

float rand_float(){
	return (float) rand()/ (float) RAND_MAX;
}

int main(){

	srand(10);
	


}

