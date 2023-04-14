#include <bits/stdc++.h>
using namespace std;
int greedycoin(int *coins,int c,int amt,int i){
    if(amt==0||i==-1)
    {cout<<"Amount left:"<<amt<<"\nGreedy Coins used:";
    return c;}
    if(coins[i]<=amt){
    int x=amt/coins[i];
    amt-=x*coins[i];
    c+=x;}
    return greedycoin(coins,c,amt,i-1);
}
int dynamic_coin(int *coins,int amt,int n){
    int dp[amt+1];
    dp[0]=0;
    for(int i=1;i<=amt;i++){
        dp[i]=INT_MAX;
        int res;
        for(int j=0;j<n;j++){
            if(i>=coins[j])
            res=dp[i-coins[j]];
            if(res!=INT_MAX and res+1<dp[i])
            dp[i]=res+1;
        }
    }
    cout<<"\nDynamic Coins used:";
    return dp[amt];
}
int main()
{
    int a[]={1,15,25};
    int sum=30;
    cout<<greedycoin(a,0,sum,3);
    cout<<dynamic_coin(a,sum,3);
    return 0;
}
