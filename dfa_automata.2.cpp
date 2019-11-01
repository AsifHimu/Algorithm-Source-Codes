//UVA12467
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 123

void computeTransFun(string pat, int M, int TF[][NO_OF_CHARS]){
	int i,lps=0,x;

	for(x=97;x<NO_OF_CHARS;x++){
		TF[0][x]=0;
	}
	TF[0][pat[0]]=1;

	for(i=1;i<=M;i++){
		for(x=97;x<NO_OF_CHARS;x++){
			TF[i][x]=TF[lps][x];
		}
		TF[i][pat[i]]=i+1;
		if(i<M){
			lps=TF[lps][pat[i]];
		}
	}
}

int search(string pat, string txt){
	int M = pat.size();
	int N = txt.size();
	int mx=0;

	int TF[M + 5][NO_OF_CHARS];

	computeTransFun(pat,M,TF);

	int i,j=0;
	for(i=0;i<N;i++) {
		j=TF[j][txt[i]];
		mx=max(mx,j);
	}
	return mx;
}

int main(){
	int t,cas=0,i,j;
    cin>>t;
    while(t--){
        int cnt_val=0,l1=0,l2=0;
        string text;
        string p;
        string s;
        cin>>p;
        text=p;
        //l1=strlen(text);
        reverse(text.begin(),text.end());
        //cout<<p<<endl;
        cnt_val=search(p,text);
        for(i=cnt_val-1;i>=0;i--){
            cout<<p[i];
        }
        cout<<endl;
    }
	return 0;
}
