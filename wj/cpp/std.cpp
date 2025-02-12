#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 1e5;
    // cin >> n;
    vector<int> p(n + 2),a(n + 2),b(n + 2);
    for(int i = 2;i <= n + 1;i ++){
        //cin >> p[i];
        p[i] = n + 1 - i + 2;
        a[p[i]] = i;
        b[i] = p[i];
    }
    vector<pair<int,int>> ans;
    auto Swap = [&](int x,int y)->void{
        if(x == y){
            return ;
        }
        if(x == 2 && y == 1)return ;
        swap(a[p[x]],a[p[y]]);
        swap(p[x],p[y]);
        ans.push_back({x,y});
    };  
    for(int i = n + 1;i >= 2;i --){
        if(p[i] == i)continue;
        int now = a[i];
        if(gcd(now,i) == 1){
            Swap(now,i);
        }else {
            if(now % 2 == 1 && i % 2 == 1){
                Swap(2,now);
                Swap(2,i);
            }else if(now % 2 == 1 && i % 2 == 0){
                Swap(2,now);
                Swap(2,i - 1);
                Swap(i - 1,i);
            }else if(now % 2 == 0 && i % 2 == 1){
                Swap(now,now - 1);
                Swap(2,now - 1);
                Swap(2,i);
            }else {
                Swap(now,now - 1);
                Swap(2,now - 1);
                Swap(2,i - 1);
                Swap(i - 1,i);
            }
        }
    }
    for(auto [x,y]:ans){
        if(x == 1 || y == 1){
            cout << "NO\n";
            return 0;
        }
        if(gcd(x,y) != 1){
            cout << "NO\n";
            return 0;
        }
        swap(b[x],b[y]);
    }
    for(int i = 2;i <= n + 1;i ++)if(b[i] != i){
        cout << "NO\n";return 0;
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    // for(auto [x,y]:ans){
    //     cout << x << " " << y << "\n";
    // }
}
/*
4 3 2
2 3 4
*/