#include <stdio.h>
#include<stdlib.h>
#include<time.h>

// OR-gate
float train[][3] = {
  {0, 0, 0},
  {1, 0, 1},
  {0, 1, 1}, 
  {1, 1, 1},
};
#define train_count (sizeof(train)/sizeof(train[0])) // get the amount of elements in train dataset

// if the cost is near to zero the better the model performs
float cost(float w1, float w2){
  float result = 0.0f;
  for(size_t i = 0; i<train_count; ++i){
    float x1 = train[i][0];
    float x2 = train[i][1];
    float y = x1*w1 + x2*w2;
    float d = y-train[i][2];
    result += d*d; // to amplify the error in the reading
  }
  result /= train_count;
  return result;
}

float rand_float(void){
  return (float) rand()/(float) RAND_MAX;
}

//simple logic gate
int main(){
  srand(69);
  float w1 = rand_float();
  float w2 = rand_float();
  printf("w1 = %f, w2 = %f\n", w1, w2);
  float c = cost(w1, w2);
  printf("c = %f\n", c);
  return 0;
}
