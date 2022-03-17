#include <stdio.h>
#include <stdlib.h>
#define N 10

void Quicksort(int a[], int low, int high);
int split(int A[] , int low , int high);

int main(void){
 int i;
 int A[N];

    printf("Enter %d the values into the array : ",N);
    for(i = 0; i < N ; i++ )
        scanf("%d",&A[i]);

        Quicksort(A , 0 , N-1);

        printf("The numbers in sorted order is\n");
        for( i = 0; i < N; i ++)
            printf("%3d",A[i]);
        printf("\n");
    
        return 0;

}


int split(int A[], int low, int high){
    int part_element = A[low];

 /*
   *This is an infinite loop that will only break if
    * low >= high for both the ascending and decending 
    * part of the array
    */

    for(;;){
        while(low < high && part_element <= A[high])
            high--;
        if(low >= high)
            break;
        A[low++] = A[high];//assignment of the value of A[high] to A[low++]
                            //making A[high temporarily empty

        while(low < high && A[low] <= part_element)
            low++;
        if(low >= high)
            break;
        A[high--] = A[low];
    }
    A[high] = part_element;
    return high;

}

void Quicksort(int a[] , int low, int high){
    
    int middle;
    if( low >= high)
        return;
    
    //split returns the last index of high
    //obtained during the spliting 

    middle = split(a , low , high);
   Quicksort(a , low, middle - 1);//lesser part of the  array which decreases each time quick sort is called arrag
    Quicksort(a , middle + 1, high);//greater part of the array which increases each time the second sort is called anf arraged

}

