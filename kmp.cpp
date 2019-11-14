///KMP_IMPLEMENTATION
///Time Complexity O(N)
#include <bits/stdc++.h>
using namespace std;

///Create lps[] that will hold the longest prefix suffix
///Function which process lps array
void processPat(string pat,long long M,long long lps[]){
    long long i=1,j=0;///j is length of the previous longest prefix suffix
    lps[0]=0;///first index always 0 that is there no lps substrings
    while(i<M){
        if(pat[j] == pat[i]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j=lps[j-1];///return back to previous character for match
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void Search(string txt,string pat){
    long long M,N,i,j,cnt=0;
    N=txt.size();
    M=pat.size();
    if(N<M){
        cout<<"pattern size is greater that Text size";
        return;
    }
    long long lps[M+5];
    processPat(pat,M,lps);
    i=0;j=0;
    while(i<N){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j==M){///i.e we found a match in text
            cout<<"Pattern found at index: "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<N && pat[j] != txt[i]){
            if(j != 0){
                j=lps[j-1];///the tricky part to previous character to match
            }
            else{
                i++;
            }
        }
    }
}
int main(){
    int t,cas=0;
        string text,pattern;
        cin>>text>>pattern;
        Search(text,pattern);
    return 0;
}

