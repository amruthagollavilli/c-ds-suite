#include<stdio.h>
int main(){
    int n,j,key;
    printf("enter the no of elements");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
           arr[j+1]=arr[j] ;
           j--;
        }
        arr[j+1]=key;
    }
    printf("sorted lists\n");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}