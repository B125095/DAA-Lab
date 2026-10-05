#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int LCS(char c1[],char c2[],int i,int j){
    int c[i+1][j+1];
    for(int k=0;k<=i;k++){
        for(int l=0;l<=j;l++){
    if(k==0 || l==0) c[k][l]=0;
    else if(c1[k]==c2[l]){
    c[k][l]= c[k-1][l-1]+1;
    }
    else c[k][l]= max(c[k-1][l],c[k][l-1]);

}}
return c[i][j];
}
int main(){
    int i,j;
   printf("Enter the number of element in 1st array:\n");
   scanf("%d",&i);
    printf("Enter the number of element in 2nd array:\n");
   scanf("%d",&j);
   char c1[i],c2[j];
   printf("Enter the elements in 1st array:\n");
   for(int k=0;k<=i;k++){
    scanf("%c",&c1[k]);
   }
   printf("Enter the elements in 2nd array:\n");
   for(int l=0;l<=i;l++){
    scanf("%c",&c2[l]);
   }
   int ans=LCS(c1,c2,i,j);
   printf("The longest common subsequence is: %d",ans);


    return 0;
}