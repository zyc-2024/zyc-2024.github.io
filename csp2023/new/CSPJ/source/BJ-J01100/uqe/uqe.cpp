#include<iostream>
#include<math.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,i,x1,x2,d1,d2,f1,f2,j,l;
    cin>>t>>m;
    for(i=1;i<=t;i++){
        cin>>a>>b>>c;
        if(b*b-4*a*c>=0){
            d1=-b-sqrt(b*b-4*a*c);
            f1=2*a;
            for(j=2;j<=sqrt(d1);j++){
                if(d1%j==0){
                   if(f1%j==0){
                       d1=d1/j;
                       f1=f1/j;
                       j--;
                   }
                }
            }
            x1=d1/f1;
            d2=-b+sqrt(b*b-4*a*c);
            f2=2*a;
            for(j=2;j<=sqrt(d2);j++){
                if(d2%j==0){
                   if(f2%j==0){
                       d2=d2/j;
                       f2=f2/j;
                       j--;
                   }
                }
            }
            x2=d2/f2;
            if(x1>=x2){
                if(x1%1==0){
                    cout<<x1;
                }
                else{
                    if(d1>0&&f1>0){
                    cout<<d1<<"/"<<f1;
                    }
                    if(d1<0&&f1<0){
                        cout<<-d1<<"/"<<-f1;
                    }
                    if(d1<0&&f1>0){
                        cout<<"-"<<-d1<<"/"<<f1;
                    }
                    if(d1>0&&f1<0){
                        cout<<"-"<<d1<<"/"<<-f1;
                    }
                    if(d1==0){
                        cout<<0;
                    }
                }
            }
            if(x2>x1){
                if(x2%1==0){
                    cout<<x2;
                }
                else{
                    if(d2>0&&f2>0){
                        cout<<d2<<"/"<<f2;
                    }
                    if(d1<0&&f1<0){
                        cout<<-d2<<"/"<<-f2;
                    }
                    if(d2<0&&f2>0){
                        cout<<"-"<<-d2<<"/"<<f2;
                    }
                    if(d2>0&&f2<0){
                        cout<<"-"<<d2<<"/"<<-f2;
                    }
                    if(d2==0){
                        cout<<0;
                    }
                }
            }
        }
        else cout<<"NO";
    }
    return 0;
}