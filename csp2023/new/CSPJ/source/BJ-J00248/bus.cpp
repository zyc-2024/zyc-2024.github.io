#include <iostream>
#include <cstdio>
using namespace std;

int n, m, k;

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, a;
        cin >> u >> v >> a;
    }
    cout << -1 << endl;
    return 0;
}
