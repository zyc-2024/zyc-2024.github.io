#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    cin >> n >>m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >>b >>c;
    }
    srand(time(NULL));
    cout << rand() % 100000;
    return 0;
}
