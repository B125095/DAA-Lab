#include<stdio.h>
int binarysearch(int arr[],int x,int l,int r){
    int m1;
    if(l>r)return -1;
    if(l==r){
        if(x==arr[l]) return l;
        else return -1;
    }
    else {
        m1=l+(r-l)/2;
    }
         if(x<=arr[m1]) return binarysearch(arr,x,l,m1) ;
         else return binarysearch(arr,x,m1+1,r);
}
int main(){
    int arr[100],n,x;
    printf("Enter the number of element you want to insert:\n");
    scanf("%d",&n);
    printf("Now you enter the elements:\n");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    printf("Now you enter the element that you find :\n");
    scanf("%d",&x);
    if(binarysearch(arr,x,0,n-1)!=-1)
    printf("The given element :%d\nfound at the index %d",x,binarysearch(arr,x,0,n-1));
    else printf("The element :%d\n this element is not present in the given array");
    return 0;
}
