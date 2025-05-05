#include <iostream>
using namespace std;

int check(int arr[],int len){
    int i,j,count=0;
    for (i=len-1;i>=0;i--){
        for(j=len-1;j>i;j--){
            if (arr[i]==arr[j]){
                return count;
            }
        }
        count++;
    }
    return count;
}
int main(){
    int i,j,len,count=0,element;
    cout<<"enter the length of the sequence : ";
    cin>>len;
    int arr[len];
    for (i=0;i<len;i++){
        printf("enter a value for arr[%d] : ",i);
        cin>>arr[i];
    }
    count=check(arr,len);
    cout<<"\n\n\n"<<len-count<<"\n\n\n\n";
    
}