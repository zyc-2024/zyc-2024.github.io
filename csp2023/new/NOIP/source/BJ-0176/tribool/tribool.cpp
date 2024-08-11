#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
long long i,j,n,m,x[100005],y[100005],t,id,a[100005],b[100005],sum,k,fa[100005];
char c[100005];
bool flag,fl;
void dfs(long long z,long long xy){
    if(z==n+1){
        for(long long l=1;l<=n;l++){
            b[l]=a[l];
        }
        fl=true;
        for(long long l=1;l<=m;l++){
            if(c[l]=='T'){
                b[x[l]]=1;
            }
            if(c[l]=='F'){
                b[x[l]]=2;
            }
            if(c[l]=='U'){
                b[x[l]]=0;
            }
            if(c[l]=='+'){
                b[x[l]]=b[y[l]];
            }
            if(c[l]=='-'){
                b[x[l]]=(3-b[y[l]])%3;
            }
        }
        for(long long l=1;l<=n;l++){
            if(b[l]!=a[l]){
                fl=false;
                break;
            }
        }
        if(fl){
            sum=min(xy,sum);
        }
        return ;
    }
    a[z]=0;
    dfs(z+1,xy+1);
    a[z]=1;
    dfs(z+1,xy);
    a[z]=2;
    dfs(z+1,xy);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>id>>t;
    if(id==1||id==2){
        for(i=1;i<=t;i++){
            sum=0x3f3f3f3f3f3f3f3f;
            cin>>n>>m;
            memset(a,0,sizeof(a));
            for(j=1;j<=m;j++){
                cin>>c[j];
                if(c[j]=='T'||c[j]=='F'||c[j]=='U'){
                    cin>>x[j];
                }
                if(c[j]=='+'||c[j]=='-'){
                    cin>>x[j]>>y[j];
                }
            }
            dfs(1,0);
            cout<<sum<<endl;
        }
    }
    if(id==3||id==4){
        for(i=1;i<=t;i++){
            sum=0;
            cin>>n>>m;
            memset(a,0,sizeof(a));
            for(j=1;j<=m;j++){
                cin>>c[j]>>x[j];
                if(c[j]=='U'){
                    a[x[j]]=1;
                }
                else{
                    a[x[j]]=0;
                }
            }
            for(j=1;j<=n;j++){
                if(a[j]==1){
                    sum++;
                }
            }
            cout<<sum<<endl;
        }
    }
    if(id==5||id==6){
        for(i=1;i<=t;i++){
            sum=0;
            cin>>n>>m;
            memset(a,0,sizeof(a));
            for(j=1;j<=m;j++){
                cin>>c[j]>>x[j];
                if(c[j]=='U'){
                    a[x[j]]=1;
                }
                else{
                    cin>>y[j];
                    a[x[j]]=a[y[j]];
                }
            }
            for(k=1;k<100;k++){
                for(j=1;j<=m;j++){
                    if(c[j]=='U'){
                        a[x[j]]=1;
                    }
                    else{
                        a[x[j]]=a[y[j]];
                    }
                }

            }
            for(j=1;j<=n;j++){
                if(a[j]==1){
                    sum++;
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
