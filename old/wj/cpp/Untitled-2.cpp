#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        long long sum = 0;
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        
        int x = sum / n;  // 平均数
        
        // 分析石子堆的分布
        int count_less = 0, count_more = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < x) ++count_less;
            else if (a[i] > x) ++count_more;
        }
        
        // 如果没有符合条件的堆
        if (count_less == 0 || count_more == 0) {
            cout << "Draw" << endl;
            continue;
        }
        
        // 根据策略进行博弈判断
        if (count_less % 2 == 1) {
            cout << "F" << endl;  // 小 F 先手获胜
        } else {
            cout << "L" << endl;  // 小 L 获胜
        }
    }
    
    return 0;
}
