
#include <bits/stdc++.h> 
using namespace std; 
set <int> s1 = {1, 2, 3}, s2 = {2, 3, 1, 1}, 
s3 = {1, 2, 100}, s4 = {3, 4, 5}; 
map <set <int>, int> mp1, mp2; 
set <int> intersection(set <int> a, set <int> b) { 
	if (a.size() > b.size()) swap(a, b); 
	set <int> res = a; 
	for (int i : a) 
		if (b.count(i) == 0) 
			res.erase(i); 
	return res; 
} 
int main() { 
	cout << (s1 == s2) << endl; 
	mp1[s3] = 9; mp1[s1] = 1; 
	mp2[s2] = 1; mp2[s4] = 5; 
	cout << (mp1 < mp2) << ' ';  
	cout << mp2[s3] << ' '; 
	cout << (mp1 <= mp2) << endl; 
	mp1.clear();
	int n, l, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		set<int> tmp;
		for (cin >> l; l; l--) {
			cin >> t;
			tmp.emplace(t);
		}
		mp1[tmp] = i;
	}
	set<int> res = mp1.begin()->first;
	for (auto i : mp1)
		res = intersection(i.first, res);
	cout << res.size();
	return 0;
}
