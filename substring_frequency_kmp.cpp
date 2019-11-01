///KMP
#include <bits/stdc++.h>
using namespace std;

void processPat(string pat,long long M,long long lps[]){
    long long i=1,j=0;
    lps[0]=0;
    while(i<M){
        if(pat[j] == pat[i]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    for(i=0;i<M;i++){
        cout<<lps[i]<<" ";
    }
}
int Search(string txt,string pat){
    long long M,N,i,j,cnt=0;
    N=txt.size();
    M=pat.size();
    if(N<M){
        cout<<"pattern size is greater that Text size";
        return 0;
    }
    long long lps[M+5];
    processPat(pat,M,lps);
    i=0;j=0;
    while(i<N){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j==M){
            cnt++;
            j=lps[j-1];
        }
        else if(i<N && pat[j] != txt[i]){
            if(j != 0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
   // cout<<i<<"jjjjj"<<endl;
    return cnt;
}
int main(){
    int t,cas=0;
    //cin>>t;
    //while(t--){
        string text,pattern;
        cin>>text>>pattern;
        //printf("Case %d: ",++cas);
        cout<<Search(text,pattern)<<endl;
    //}
    return 0;
}
