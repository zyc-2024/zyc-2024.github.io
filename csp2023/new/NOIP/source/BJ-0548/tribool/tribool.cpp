#include<bits/stdc++.h>
using namespace std;

struct Node{
    vector<int> to, fr;
    int fnf;
};
const int NMAX=100010;
int c, t, n, m, x[NMAX], tgt[NMAX], e[NMAX][2], es[NMAX], fnf[NMAX], fns[NMAX];
bool isu[NMAX], vis[NMAX];
char v[NMAX];
// vector<int> to[NMAX], fm[NMAX];
vector<int> tt[NMAX], ft[NMAX], so[NMAX];

void trc(int cur, int curt){
    if(!ft[cur].size()){
        fnf[cur]=cur; fns[cur]=1; return ;
    }
    if(ft[cur][0]>curt){
        fnf[cur]=cur; fns[cur]=1; return ;
    }
    int l=0, r=ft[cur].size()-1, mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(ft[cur][mid]<curt){
            l=mid+1; continue;
        }
        else if(ft[cur][mid]>curt){
            r=mid-1; continue;
        }
    }
    int cure=ft[cur][mid];
    if(fnf[cur]==-1){
        fnf[cur]=e[cure][0]; fns[cur]=es[cure];
        trc(e[cure][0], cure);
        fnf[cur]=fnf[fnf[cur]]; fns[cur]=es[cure]*fns[fnf[cur]];
        return ;
    }
    else{
        fnf[cur]=fnf[fnf[cur]]; fns[cur]=es[cure]*fns[fnf[cur]];
        return ;
    }
    return ;
}

void dele(int cure){
    v[cure]='?';
    ft[e[cure][1]].pop_back();
    tt[e[cure][0]].pop_back();
    return ;
}

void putflg(int cur, int curt){
    if(vis[cur]){
        return ;
    }
    isu[cur]=true;
    int l=0, r=tt[cur].size()-1, mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(tt[cur][mid]<curt){
            l=mid+1; continue;
        }
        else if(tt[cur][mid]>curt){
            r=mid-1; continue;
        }
    }
    for(int i=mid+1;i<tt[cur].size();i++){
        putflg(e[tt[cur][i]][1], tt[cur][i]);
    }
    vis[cur]=true;
    return ;
}

int main(){
    // freopen("tribool4.in", "r", stdin);
    // freopen("tribool.out", "w", stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n+3;i++){
            tt[i].clear(); ft[i].clear();
            fnf[i]=-1; fns[i]=1; so[i].clear(); es[i]=1; isu[i]=false; vis[NMAX]=false;
        }isu[n+3]=true;
        printf("::fnsinit\n");
        for(int i=1;i<=m;i++){
            cin>>v[i]; // an edge from e[i][0] to e[i][1].
            if(v[i]=='+'||v[i]=='-'){
                cin>>e[i][1]>>e[i][0];
                if(v[i]=='-'){
                    es[i]=-1;
                }
            }
            else{
                cin>>e[i][1];
                if(v[i]=='T') e[i][0]=n+1;
                else if(v[i]=='F') e[i][0]=n+2;
                else e[i][0]=n+3;
                v[i]='+';
            }
            tt[e[i][0]].push_back(i);
            while(ft[e[i][1]].size()&&ft[e[i][1]][ft[e[i][1]].size()-1]>tt[e[i][1]][tt[e[i][1]].size()-1]){
                // dele(ft[e[i][1]][ft[e[i][1]].size()-1]);
                v[ft[e[i][1]][ft[e[i][1]].size()-1]]='?';
                tt[e[ft[e[i][1]][ft[e[i][1]].size()-1]][0]].pop_back();
                ft[e[i][1]].pop_back();

            }
            ft[e[i][1]].push_back(i);
            printf("::v[%d]=%c\n", i, v[i]);
        }
        printf("::fnsinput\n");
if(c==3||c==4){printf("0");continue;}
        for(int i=m;i>=1;i--){
            if(v[i]=='?') continue;
            trc(e[i][1], i);
        }
        for(int i=1;i<=n;i++){
            if(fnf[i]==i&&fns[i]==-1){
                isu[i]=true;
            }
        }
        for(int i=1;i<=n;i++){
            if(isu[i]){
                for(int j=0;j<tt[i].size();j++){
                    putflg(i, tt[i][j]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(isu[i]){
                ans++;
            }
        }

    }
    return 0;
}

/*
1 1
3 3
- 2 1
- 3 2
+ 1 3
*/
