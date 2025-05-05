#include <stdio.h>
#include <io

int bubble(int arr[],int );

int insertion(int arr[],int n);

int selection(int arr[],int n);

int main(){
    
    while(1){
        int i,n,ch;
        printf("1---> bubble sort\n");
        printf("2---> insertion sort\n");
        printf("3---> selection sort\n");
        printf("4---> exit\n");
        printf("enter your choice : ");
        scanf("%d",&ch);
        if (ch==4){
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
        switch (ch){
            case 1:
                /* code */
                bubble(arr,n);
                break;
            case 2:
                insertion(arr,n);
                break;
            case 3:
                selection(arr,n);
                break;
            default:
                printf("invalid choice give a valid choice\n\n\n\n");
                break;
        }
    }
}

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