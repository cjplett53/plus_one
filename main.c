#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
void welcome(){
    printf("Welcome to the function: plusOne()");
}
int main(int argc, char *argv[]){
    printf("Welcome to plusOne!\n");
    int returnSize = 0;
    int digits[100];
    printf("Enter digits, press 'q' to quit: ");
    int index = 0;
    char c;
    while((c = getchar())!='q'){
        if(isspace((unsigned char)c)) continue;
        if(!isdigit((unsigned char)c)) continue;
        digits[index++]=c-'0';
    }
    int *arr = plusOne(digits, index, &returnSize);
    for(int i=0; i<returnSize; ++i){
        printf("%d, ", arr[i]);
    }
    return 0;
}


