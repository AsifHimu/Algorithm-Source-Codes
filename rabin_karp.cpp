///Rabin_Karp_IMPLEMENTATION
///Time Complexity O(T+P)
#include<bits/stdc++.h>
#define MD 1000000009
#define ll long long
#define MX 1000005
using namespace std;
ll pm=31,powr[MX],hs[MX];

void powCalc(){
    powr[0] = 1;
    for(int i=1;i<MX;i++){
        powr[i] = (powr[i-1]*pm)%MD;
    }
}
vector<int> ans;
void rabin_karp(string txt,string ptt){
    int P=ptt.size(),T=txt.size(),i,crr,j;

    memset(hs,0,sizeof hs);
    ans.clear();///Clearing vector element for multiple input
    for(i=0; i<T; i++){
        hs[i+1] = (hs[i]+(txt[i]-'a'+1)*powr[i])%MD;
    }
    ll hss = 0;
    for(i=0; i<P; i++){
        hss = (hss+(ptt[i]-'a'+1)*powr[i])%MD;
    }
    for(i=0;i+P-1<T;i++){
        crr = (hs[i+P] + MD - hs[i])%MD;

        if(crr == hss*powr[i]%MD){
            ans.push_back(i);
        }
    }
    for(j=0;j<ans.size();j++){
        cout<<ans[j];///Pattern finding index
    }
}
int main(){
    string text,pattern;
    cin>>text>>pattern;
    powCalc();
    rabin_karp(text,pattern);
    return 0;
}

