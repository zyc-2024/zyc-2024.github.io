/*
 hmz is cute!
----------------------------
 You've got to have faith
 Don't let them cut you down cut you down once more
*/
#include<bits/stdc++.h>
using namespace std;
#define TY int
#define ll long long
#define db double
#define MAXN 200005
#define MAXM 200005
#define MAXK 27
#define INF (TY)(1e9)
#define mod (TY)(1e9+7)
#define IL inline
#define pb push_back
#define For(i,a,b) for(TY i=(a);i<=(b);++i)
#define FOR(i,a,b) for(TY i=(a);i<(b);++i)
#define Rof(i,a,b) for(TY i=(a);i>=(b);--i)
#define ROF(i,a,b) for(TY i=(a);i>(b);--i)
IL TY qr(){
    TY u=0,v=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())v=(ch=='-'?-1:1);
    for(;ch>='0'&&ch<='9';ch=getchar())u=u*10+(ch-'0');
    return u*v;
}IL void qw(TY now){
    if(now<0){putchar('-');now=-now;}
    if(!now){putchar('0');return;}
    if(now>=10)qw(now/10);putchar(now%10+'0');
}IL void qw(TY now,char c){qw(now);putchar(c);}
IL bool ischar(char c){return (c>='a'&&c<='z')||(c>='A'&&c<='Z');}
IL char getc(){
    char ch=getchar();
    while(!ischar(ch))ch=getchar();
    return ch;
}IL string qs(){
    string lst="";char ch=getc();
    while(!ischar(ch))ch=getchar();
    while(ischar(ch))lst+=ch,ch=getchar();
    return lst;
}IL void ws(string s){FOR(i,0,s.size())putchar(s[i]);}
IL TY Mod(TY a){return (a>=mod?a-mod:a);}
IL TY Ceil(TY a,TY b){return a/b+(a%b!=0);}
IL TY Pow(TY a,TY b){
    TY ans=1,base=a;
    while(b){
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;b>>=1;
    }return ans;
}TY n,ans;bool vis[10];
struct node{
	TY num[6];
}s[9];
IL node change(TY k){
	node lst;
	lst.num[1]=k%10;lst.num[2]=k%100/10;lst.num[3]=k%1000/100;lst.num[4]=k%10000/1000;lst.num[5]=k/10000;
	return lst;
}IL bool same(const node&x,const node&y){For(i,1,5)if(x.num[i]!=y.num[i])return false;return true;}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    /* init */
    n=qr();For(i,1,n)For(j,1,5)s[i].num[j]=qr();
    FOR(i,0,100000){
    	TY cnt=0;node tmp=change(i);
    	memset(vis,0,sizeof(vis));
    	For(j,1,n)if(same(tmp,s[j])){cnt=-1;break;}
    	if(cnt==-1)continue;
    	For(j,1,5)For(k,0,9){
    		node now=tmp;now.num[j]=k;
    		For(f,1,n)if(same(s[f],now))cnt+=(vis[f]==0),vis[f]=1;
    		if(j!=5){
    			now=tmp;
				now.num[j]=(now.num[j]+k)%10;
    			now.num[j+1]=(now.num[j+1]+k)%10;
    			For(f,1,n)if(same(s[f],now))cnt+=(vis[f]==0),vis[f]=1;
			}
		}ans+=(cnt==n);
	}qw(ans);
    return 0;
}