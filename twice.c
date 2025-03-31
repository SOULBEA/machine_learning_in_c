#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// data set
float train[][2] = {
  {0, 0},
  {1, 2},
  {2, 4},
  {3, 6},
  {4, 8},
};
#define train_count (sizeof(train)/sizeof(train[0])) // get the amount of elements in train dataset

// function to get any random number between 0 to 1
float rand_float(void){
  return (float) rand()/(float) RAND_MAX;
}
// if the cost is near to zero the better the model performs
float cost(float w, float b){
  float result = 0.0f;
  for(size_t i = 0; i<train_count; ++i){
    float x = train[i][0];
    float y = x*w + b;
    float d = y-train[i][1];
    result += d*d; // to amplify the error in the reading
  }
  result /= train_count;
  return result;
}

int main(){
  srand(time(0));  // genarate random seed to get random number every time
  // y = x*w;
  float w = rand_float()*10.0f;
  float eps = 1e-3;
  float rate = 1e-3;
  float b = rand_float()*5.0f;

  printf("%f\n", cost(w, b));
  // trying to get the w result near to zero 
  for(size_t i = 1; i<500; ++i){
    float c = cost(w,b);
    float dw = (cost(w+eps, b) - c)/eps; // derivative of weight including bias
    float db= (cost(w, eps+b) - c)/eps; // derivateve of bias including weight
    w -= rate*dw;
    b -= rate*db;
    printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
  }
  printf("---------------------\n");
  printf("w = %f, b = %f\n", w, b);
  return 0;
}
