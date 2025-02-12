#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,mb,mc; ll ans;
int a[1000005],b[1000005],c[1000005],tb[1000005],tc[1000005];
pii Ans;
ll calc(int i,int j){return 1ll*(j-i)*(a[i]+a[j]);}

void solve(int l,int r,int ql,int qr){
    if(l>r) return;
    int mid=(l+r)/2,opt=0;
    ll maxa=0;
    for(int i=ql;i<=qr;i++) if(chkmax(maxa,calc(tb[i],tc[mid]))) opt=i;
    if(chkmax(ans,maxa)){
        Ans={tb[opt],tc[mid]};
    }
    solve(l,mid-1,ql,opt);
    solve(mid+1,r,opt,qr);
}

int main(){
    n=readint();
    for(int i=1;i<=n;i++) a[i]=readint();
    for(int i=1;i<=n;i++) b[i]=max(b[i-1],a[i]);
    for(int i=n;i>=1;i--) c[i]=max(c[i+1],a[i]);
    for(int i=1;i<=n;i++){
        if(b[i]>b[i-1]) tb[++mb]=i;
        if(c[i]>c[i+1]) tc[++mc]=i;
    }
    solve(1,mc,1,mb);
    printf("%lld\n",ans);
    printf("%d %d\n",Ans.first,Ans.second);
    return 0;
}