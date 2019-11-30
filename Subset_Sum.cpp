#include<bits/stdc++.h>
using namespace std;
#define clr(str) memset(str,0,sizeof(str))
#define max 1000

void subset_sum(int ara[],int sum,int num){
    bool mark[max][max];
    clr(mark);
    for(int i=0;i<num;i++){
        mark[i][0]=true;
    }
    //mark[0][0]=true;
    for(int i=1;i<=sum;i++){
        mark[0][i]=false;
    }
    mark[0][ara[0]]=true;
    for(int i=1;i<num;i++){
        for(int j=1;j<=sum;j++){
            if(j<ara[i]){
                mark[i][j]=mark[i-1][j];
            }
            else{
                mark[i][j]=mark[i-1][j] || mark[i-1][j-ara[i]];
            }
        }
    }
    vector<int>vt;
    int suma=sum;
    if(mark[num-1][sum]==true){
        cout<<"YES"<<endl;
        for(int i=num-1;i>=0;i--){
                //cout<<mark[i][sum]<<endl;
            if(mark[i-1][sum]==true){
                continue;
            }
            else{
                vt.push_back(ara[i]);
                sum=sum-ara[i];
                if(sum==0)break;
            }
        }
        cout<<"Sum ="<<suma<<endl;
        for(int k=0;k<vt.size();k++){
            cout<<vt[k]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    clr(ara);
    vt.clear();
}
int main(){
    int test,i,num,ara[max],sum,cas=0;
    cin>>test;
    while(test--){
        cout<<"How many set value?"<<endl;
        cin>>num;
        cout<<"Enter the values"<<endl;
        for(i=0;i<num;i++){
            cin>>ara[i];
        }
        sort(ara,ara+num);
        cout<<"Enter the sum value"<<endl;
        printf("Case %d: \n",++cas);
        cin>>sum;
        subset_sum(ara,sum,num);
    }
    return 0;
}
