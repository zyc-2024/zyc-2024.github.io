#include<bits/stdc++.h>
using namespace std;
const int N=5005,mo=998244353;
#define ll long long
#define pb push_back
#define poly vector<int>
int dfn[N],low[N],tot,co,S[N],top,be[N];
poly ve[N];

int sz[N],f[N][N],sum[N];
poly v[N];
int ksm(int x,int p){
    int res=1;
    for(;p;p>>=1,x=(ll)x*x%mo){
        if(p&1) res=(ll)res*x%mo;
    }
    return res;
}
int g[N];
void dfs(int u,int fa){
    sz[u] = 1;
    f[u][sz[u]]=1;
//  cout<<"mjn "<<u<<" "<<sz[u]<<endl;
    for(auto k:ve[u]){
        if(k==fa) continue;
        dfs(k,u);
        for(int i=0;i<=sz[u]+sz[k];i++) g[i]=0;
        for(int i=1;i<=sz[u];i++){
            for(int j=1;j<=sz[k];j++){
                int ssw=(ll)f[u][i]*f[k][j]%mo;
                g[i]=(g[i]-ssw+mo)%mo;
                g[i+j]=(g[i+j]+(ll)ssw*ksm(2,(i*j-1)))%mo;
            }
        }
        sz[u]+=sz[k];
        for(int i=1;i<=sz[u];i++) f[u][i]=g[i];
    }
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y; scanf("%d%d",&x,&y);
        ve[x].pb(y); ve[y].pb(x);
    }
    if(n == 2){
        cout << 1 << "\n";
        return 0;
    }
    dfs(1,0);
//  cout<<"#"<<f[1][3]<<endl;
    int ans=0;
    for(int i=1;i<=n;i++) ans=(ans+f[1][i])%mo;
    cout<<ans;
}/*

5 4
5 4
4 2
2 1
1 3

*/