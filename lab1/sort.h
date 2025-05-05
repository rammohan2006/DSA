#include <stdio.h>
#include <iostream>

int bubble(int arr[],int );

int insertion(int arr[],int n);

int selection(int arr[],int n);

int bubble(int arr[],int n){
    if (n==0){
        printf("\n\n\nno elements in the array\nplease enter some elements into the array for sorting\n");
        printf("\n\n\n\n");
        return -1;
    }
    if (n==1){
        printf("\n\n\ncannot sort a single element\nplease give atleast 2 elements\n");
        printf("\n\n\n\n");
        return -1;
    }
    int i,j,temp;
    for(i=0;i<n;i++){
        for (j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }printf("the bubble sorted array is : [");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if (i<(n-1)){
            printf(",");
            
        }
    }printf("]\n\n\n\n");
    return 0;
}

int insertion(int arr[],int n){
    if (n==0){
        printf("\n\n\nno elements in the array\nplease enter some elements into the array for sorting\n");
        printf("\n\n\n\n");
        return -1;
    }
    if (n==1){
        printf("\n\n\ncannot sort a single element\nplease give atleast 2 elements\n");
        printf("\n\n\n\n");
        return -1;
    }
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 &&  (arr[j]>temp)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("\n\n\nthe insertion sorted array is : [");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if (i<(n-1)){
            printf(",");
            
        }
    }printf("]\n\n\n\n");
    return 0;
}

int selection(int arr[],int n){
    if (n==0){
        printf("\n\n\nno elements in the array\nplease enter some elements into the array for sorting\n");
        printf("\n\n\n\n");
        return -1;
    }
    if (n==1){
        printf("\n\n\ncannot sort a single element\nplease give atleast 2 elements\n");
        printf("\n\n\n\n");
        return -1;
    }
    int i,j,temp,min;
    for(i=0;i<n-1;i++){
        min=i;
        j=i+1;
        for(j;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if (min!=i){
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    printf("\n\n\nthe insertion sorted array is : [");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
        if (i<(n-1)){
            printf(",");
            
        }
    }printf("]\n\n\n\n");
    return 0;
}