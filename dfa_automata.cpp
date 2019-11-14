///DFA_IMPLEMENTATION
///Time Complexity O(M*NO_OF_CHARS)
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 123

/* This function builds the TF table
which represents Finite Automata for a
given pattern */
void computeTransFun(string pat, int M, int TF[][NO_OF_CHARS]){
	int i,lps=0,x;

	/// Fill entries in first row
	for(x=0;x<NO_OF_CHARS;x++){
		TF[0][x]=0;
	}
	TF[0][pat[0]]=1;

	/// Fill entries in other rows
	for(i=1;i<=M;i++){
		for(x=0;x<NO_OF_CHARS;x++){
			TF[i][x]=TF[lps][x];///Copy values from row at index lps
		}
		TF[i][pat[i]]=i+1;///Update the entry corresponding to this character
		if(i<M){
			lps=TF[lps][pat[i]];///Update lps for next row to be filled
		}
	}
}
/* Prints all occurrences of pat in txt */
void Search(string pat, string txt){
	int M = pat.size();
	int N = txt.size();

	int TF[M + 5][NO_OF_CHARS];

	computeTransFun(pat,M,TF);

	/// process text over FA.
	int i,j=0;
	for(i=0;i<N;i++) {
		j=TF[j][txt[i]];
		if(j == M) {
            cout << "pattern found at index"<<i - M + 1<<endl;
        }
    }
}

int main(){
	int t,cas=0;
        string text,pattern;
        cin>>text>>pattern;
        Search(pattern,text);
	return 0;
}
