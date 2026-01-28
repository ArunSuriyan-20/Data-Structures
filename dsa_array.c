/******************************************************************************
Data structures
Array
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int search(int *arr, int ele, int n){
    for (int i=0; i<n ;i++){
        if(arr[i] == ele){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n,ele;
    int *arr;
    int found;
    printf("Enter the n:");
    scanf("%d",&n);
    
    arr = malloc(sizeof(int)*n);
    
    printf("Enter the data: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("The Data: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    printf("Enter the element to search: ");
    scanf("%d",&ele);
    
    found = search(arr, ele, n);
    
    if (!found){
        printf("%d is not in array.\n");
    }else{
        printf("%d is in array.\n");
    }
}











