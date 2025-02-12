#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<26-n;i++){
        cout<<(char)(((int)'A'+n+i));
    }
    for(int i=0;i<n;i++){
        cout<<(char)('A'+i);
    }
}