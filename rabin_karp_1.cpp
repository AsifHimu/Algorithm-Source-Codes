///Getting TLE -_-
///From Tusher Roy

#include<bits/stdc++.h>
using namespace std;
#define prime 101

long long createHash(string str, int end){
    long long hash = 0;
    for (int i = 0 ; i <= end; i++) {
        hash += str[i]*pow(prime,i);
    }
    return hash;
}
 long long recalculateHash(string str,int oldIndex, int newIndex,long long oldHash, int patternLen) {
   long long newHash = oldHash - str[oldIndex];
    newHash = newHash/prime;
    newHash += str[newIndex]*pow(prime, patternLen - 1);
    return newHash;
}
 bool checkEqual(string str1,int start1,int end1, string str2,int start2,int end2){
    if(end1 - start1 != end2 - start2) {
        return false;
    }
    while(start1 <= end1 && start2 <= end2){
        if(str1[start1] != str2[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}
int patternSearch(string text, string pattern){
    int cnt=0;
    int m = pattern.size();
    int n = text.size();
    long long patternHash = createHash(pattern, m - 1);
    long long textHash = createHash(text, m - 1);
    for (int i = 1; i <= n - m + 1; i++) {
        if(patternHash == textHash && checkEqual(text, i - 1, i + m - 2, pattern, 0, m - 1)) {
            cnt++;
        }
        if(i < n - m + 1) {
            textHash = recalculateHash(text, i - 1, i + m - 1, textHash, m);
        }
    }
    return cnt;
}

int main(){
    int t,cas=0;
    while(t--){
        string text,pattern;
        cin>>text>>pattern;
        printf("Case %d: ",++cas);
        cout<<patternSearch(text,pattern)<<endl;
    }
    return 0;
}
