#include<stdio.h>
int main(){
    int n;
    printf("enter the no of elements ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        int p=i;
        for(int j=i+1;j<n;j++){
            if(arr[p]>arr[j]){
                p=j;
            }
        }
        int temp=arr[p];
        arr[p]=arr[i];
        arr[i]=temp;
    }
  printf(" the sorted array is:");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}