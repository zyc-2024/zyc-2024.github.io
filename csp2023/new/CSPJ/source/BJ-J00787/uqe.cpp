#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0) cout<<"NO"<<endl;
        cout<<((0-b)+sqrt(b*b-4*a*c))/2*a<<endl;
    }
}
