#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int x = 53;

int fibonacci(int n){
    if(n==1 || n==2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n){
    if(n==0)
        return 1;
    return n*(factorial(n-1));
}

int add(int x, int y){
    return x+y;
}

void f(int (*add)(int, int)){
    printf("I'm adding 1+1");
    int ans = add(1, 1);
    printf("The result is %d", ans);
}
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 0;
    for(int i=digitsSize-1; i>=0; i--){
        int temp = digits[i] + carry;
        if(i == (digitsSize-1)) ++temp;
        if(temp > 9){
            carry = 1;
            temp = 0;
        }
        else carry = 0;
        digits[i] = temp;
    }
    int *returnArray = malloc((digitsSize+carry)*(sizeof(int)));
    int i=0;
    if(carry==1) returnArray[i++]=1;
    for(i; i<digitsSize+carry; ++i){
        returnArray[i] = digits[i-carry];
    }
    *returnSize = digitsSize+carry;
    return returnArray;
}
int main(int argc, char *argv[]){
    int returnSize = 0;
    int digits[] = {9, 8, 9};
    int digitsSize = sizeof(digits)/sizeof(int);
    int *arr = plusOne(digits, digitsSize, &returnSize);
    for(int i=0; i<returnSize; ++i){
        printf("%d, ", arr[i]);
    }
    return 0;
}