#include <stdio.h>
#include <stdlib.h>

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
    printf("Welcome to plusOne!");
    int digits[] = {9, 8, 9};
    int digitsSize = sizeof(digits)/sizeof(int);
    int *arr = plusOne(digits, digitsSize, &returnSize);
    for(int i=0; i<returnSize; ++i){
        printf("%d, ", arr[i]);
    }
    return 0;

}
