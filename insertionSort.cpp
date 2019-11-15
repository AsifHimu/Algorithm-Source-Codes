#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,value,temp;
    cout<<"How many numbers?"<<endl;
    cin>>value;
    int num[value+10];
    for(i=0;i<value;i++){
        cin>>num[i];
    }
    for(i=1;i<value;i++){
        temp=num[i];
        j=i-1;
        while(j>=0 && num[j]>temp){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=temp;
    }
    cout<<"Ordered elements"<<endl;
    for(i=0;i<value;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
