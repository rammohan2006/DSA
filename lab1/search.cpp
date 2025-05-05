#include <stdio.h>
#include <iostream>
#include "sort.h"

int linear(int arr[],int,int);

int binary(int arr[],int,int);

int main(){
    while(1){
        int i,n,ch;
        printf("1---> linear search\n");
        printf("2---> binary search\n");
        printf("3---> exit\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
        if (ch==3){
            printf("\nsuccessfully completed\n");
            return 0;
        }
        printf("\n\n\n");
        printf("enter the number of elements you want to store in the array : ");
        scanf("%d",&n);
        int arr[n];
        for (i=0;i<n;i++){
            printf("enter element %d : ",i+1);
            scanf("%d",&arr[i]);
        }
        int element;
        printf("enter which element you want to search : ");
        scanf("%d",&element);
        switch (ch){
            case 1:
                /* code */
                linear(arr,n,element);
                break;
            case 2:
                binary(arr,n,element);
                break;
            default:
                printf("invalid choice give a valid choice\n\n\n\n");
                break;
        }

    }
    return 0;
}

int linear(int arr[],int n,int element){
    int i;
    for (i=0;i<n;i++){
        if (element==arr[i]){
            printf("\n\n\nthe element %d is found at the position : %d\n\n\n",element,i+1);
            return 0;
        }

    }
    return 0;
}

int binary(int arr[],int n,int element){
    int high,low,mid,key,temp,i,j;
    bubble(arr,n);
    high=n-1;
    low=0;
    key=element;
    
    while (high>=low){
        mid=(low+high)/2;
        if (key==arr[mid]){
            printf("the element %d is found at position %d in arr\n\n\n",key,mid+1);
            return 0;
        }
        else if (key<arr[mid]){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return 0;
}