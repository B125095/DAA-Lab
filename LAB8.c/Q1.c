#include<stdio.h>
int min(int a,int b){
    return (a<b)?a:b;
}
int change(int a[],int n,int v){
     int dp[v+1];
     int i,j;
     dp[0]=0;
     for(int i=1;i<=v;i++){
        dp[i]=v+1;
     }
     for(int i=1;i<=v;i++){
        for(int j=0;j<n;j++){
            if(a[j]<=i)
            dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
     }
     if(dp[v]>v)return -1;
      
     return dp[v];
}
int main(){
    int n,v,ans;
    printf("Enter number of coin denomination:");
    scanf("%d",&n);
    int coins[n];
    printf("coin of denomination:");
    for(int i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    printf("Enter the target amount:");
    scanf("%d",&v);
    ans=change(coins,n,v);
    printf("Minimum number of coins=%d\n",ans);

    return 0;
}