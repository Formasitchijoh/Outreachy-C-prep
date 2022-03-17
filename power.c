#include <stdio.h>

int power(int a , int b){
    int result = 1;

    while(b-- > 0){
        result = result * a;

    }
    return result;
}

int main(void){
    int x , n;
    printf("Enter the value then it's power\n");
    scanf("%d%d",&x,&n);
    
    printf("The value of %d to the power %d is : %d \n", x , n , power(x , n));
    return 0;


}