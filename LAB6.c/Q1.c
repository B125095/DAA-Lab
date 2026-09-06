#include<stdio.h>
int fibonacci(int n){
    int dp[n];
    dp[0]=0;
    dp[1]=1;
for(int i=2;i<n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}
return dp[n-1];

}
int main(){
    int n;
    printf("Enter the fibonacci sequence number which you want\n");
    scanf("%d",&n);
    printf("The %dth fibonacci number is : %d",n,fibonacci(n));
    return 0;
}