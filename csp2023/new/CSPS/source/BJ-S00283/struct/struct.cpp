#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen ("struct.in", "r", stdin);
    freopen ("struct.out", "w", stdout);
    int n, cnt = 0;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1])
            cnt++;
    cout << cnt;
    return 0;
}
