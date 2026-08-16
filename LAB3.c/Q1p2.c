#include<stdio.h>
int ternarysearch(int arr[],int x,int l,int r){
    int m1,m2;
    if(l>r)return -1;
    if(l==r){
        if(x==arr[l]) return l;
        else return -1;
    }
    else {
        m1=l+((r-l)/3);
        m2=r-((r-l)/3);
    }
         if(x<=arr[m1]) return ternarysearch(arr,x,l,m1) ;
         else if ( x<arr[m2]) return ternarysearch(arr,x,m1+1,m2-1);
         else ternarysearch(arr,x,m2,r);
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
    if(ternarysearch(arr,x,0,n-1)!=-1){
    printf("The given element :%d\nfound at the index %d",x,ternarysearch(arr,x,0,n-1));}
    else{ printf("The element :%d\n this element is not present in the given array");}
    return 0;
}