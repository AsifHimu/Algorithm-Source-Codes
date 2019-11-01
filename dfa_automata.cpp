#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 123

int getNextState(string pat, int M, int state, int x){
	if(state<M && x==pat[state]){
		return state+1;
	}
	int ns,i;

	for(ns=state;ns>0;ns--){
		if(pat[ns-1] == x){
			for(i=0;i<ns-1;i++){
				if(pat[i] != pat[state-ns+1+i]){
					break;
				}
			}
			if(i==ns-1){
				return ns;
			}
		}
	}
	return 0;
}
void computeTF(string pat, int M, int TF[][NO_OF_CHARS]){
	int state,x;
	for(state=0;state<=M;++state){
		for(x=0;x<NO_OF_CHARS;++x){
			TF[state][x]=getNextState(pat,M,state,x);
		}
	}
}
int search(string pat, string txt){
	int M=pat.size();
	int N=txt.size();
	int TF[M+1][NO_OF_CHARS];

	computeTF(pat,M,TF);

	int i,state=0,cnt=0;
	for(i=0;i<N;i++){
		state=TF[state][txt[i]];
		if(state==M){
			//cout<<" Pattern found at index "<< i-M+1<<endl;
			cnt++;
		}
	}
	return cnt;
}
int main(){
	int t;
	string pat;
	string txt;
	cin>>t;
	for(int i=1;i<=t;i++){
	    cin>>txt;
	    cin>>pat;
	    printf("Case %d: ",i);
	    cout<<search(pat, txt)<<endl;
	}
	return 0;
}

