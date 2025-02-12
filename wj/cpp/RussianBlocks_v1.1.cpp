#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <set>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 28;
bitset<maxn> bs[maxn];
set<pair<int, int> > s;
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 }, nxt[] = { 1,2,3,0 };
unsigned long long score;
#define POSIN(x,y) (x>=2&&x<maxn&&y>=2&&y<maxn)
inline void color(const int a) { SetConsoleTextAttribute(GetStdHandle(-11), a); }
inline void SetPos(COORD a) { HANDLE out = GetStdHandle(-11); SetConsoleCursorPosition(out, a); }
inline void SetPos(int i, int j) { COORD pos = { (SHORT)i, (SHORT)j }; SetPos(pos); }
inline void put(const int y, const int x, const char c, const int col) {
	SetPos(x - 1, y - 1);
	color(col);putchar(c);color(15);
}
inline void rotate(vector<pair<int, int> >& vc) {
	auto cmp = [](const pair<int, int> a, const pair<int, int> b) {return a.second < b.second; };
	int xmin = min_element(vc.begin(), vc.end())->first,
		xmax = max_element(vc.begin(), vc.end())->first,
		ymin = min_element(vc.begin(), vc.end(), cmp)->second,
		ymax = max_element(vc.begin(), vc.end(), cmp)->second;
	vector<string> vs(xmax - xmin + 1);
	for (int i = 0; i <= xmax - xmin; i++) vs[i] = string(ymax - ymin + 1, '0');
	for (int i = 0; i < vc.size(); i++) vs[vc[i].first - static_cast<std::vector<std::string, std::allocator<std::string>>::size_type>(xmin)][vc[i].second - static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(ymin)] = '1';
	int xmid = (xmax - xmin) >> 1, ymid = (ymax - ymin) >> 1;
	vs[xmid][ymid] += (char)2;
	reverse(vs.begin(), vs.end());
	vector<string> t(ymax - ymin + 1);
	int stx = -1, sty = -1;
	for (int i = 0; i <= xmax - xmin; i++) for (int j = 0; j <= ymax - ymin; j++) t[j].push_back(vs[i][j]), stx = (vs[i][j] >= '2' ? j : stx), sty = (vs[i][j]>='2' ? (int)t[j].size() - 1 : sty);
	vs = t;
	t.clear();
	vector<vector<pair<int, int>>> dis(ymax - ymin + 1);
	for (int i = 0; i <= ymax - ymin; i++) dis[i] = vector<pair<int, int> >(xmax - xmin + 1, {-1,-1});
	queue<pair<int, int> > q;
	q.emplace(stx, sty);
	dis[stx][sty] = { xmid + xmin, ymid + ymin };
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx>ymax-ymin || ny<0 || ny>xmax-xmin || dis[nx][ny] != make_pair(-1, -1) || vs[nx][ny] == '0') continue;
			dis[nx][ny] = { dis[x][y].first + dx[i], dis[x][y].second + dy[i] };
		}
	}
	bool allin = true;
	for (int i = 0; i <= ymax - ymin; i++) for (int j = 0; j <= xmax - xmin; j++) if (vs[i][j] == '1' || vs[i][j] == '3') allin &= POSIN(i + xmin, j + ymin) & (bs[i + xmin][static_cast<size_t>(j) + ymin] ^ 1);
	if (allin) {
		vc.clear();
		for (int i = 0; i <= ymax - ymin; i++) for (int j = 0; j <= xmax - xmin; j++) if (vs[i][j] == '1' || vs[i][j] == '3') vc.emplace_back(i + xmin, j + ymin);
	}
}
inline bool clear() {
	bool found = false;
	unsigned int x = 0;
	for (int i = 0; i < maxn; i++) {
		if (bs[i].count() != (size_t)maxn - 2 && found) break;
		found |= bs[i].count() == (size_t)maxn - 2;
		if (bs[i].count() == (size_t)maxn - 2) x++, bs[i].reset();
	}
	score += (long long)(1LL << 7) * (long long)(1LL << x);
	return found;
}
inline void pushdown(vector<pair<int, int> > vc) {
	Sleep(200);
	char c = '|';
	if (_kbhit()) {
		fflush(stdin);
		c = _getch();
	}
	bool flag = false;
	for (int i = 0; i < vc.size(); i++) if (vc[i].first >= maxn - 1 || bs[vc[i].first + 1][vc[i].second]) flag = true;
	for (int i = 0; i < 55 && flag && c != 'a' && c != 'A' && c != 'd' && c != 'D' && c!='w'&&c!='W'; i++) {
		if (_kbhit()) {
			fflush(stdin);
			c = _getch();
		}
		Sleep(1);
	}
	if (flag && c != 'a' && c != 'A' && c != 'd' && c != 'D' && c!='W' && c!='w') {
		for (int i = 0; i < vc.size(); i++) bs[vc[i].first][vc[i].second] = true;
		return;
	}
	for (int i = 0; i < vc.size(); i++) put(vc[i].first, vc[i].second, ' ', 2);
	bool allin = true;
	for (int i = 0; i < vc.size(); i++) allin &= !(!POSIN(vc[i].first + (flag ^ 1), vc[i].second + ((c == 'a' || c == 'A') ? -1 : 0) + ((c == 'd' || c == 'D') ? 1 : 0)) || bs[vc[i].first + 1][static_cast<size_t>(vc[i].second) + ((c == 'a' || c == 'A') ? -1 : 0) + ((c == 'd' || c == 'D') ? 1 : 0)]);
	int mn = 10000;
	if (c == 's' || c == 'S')for (int i = 0; i < vc.size(); i++) {
		int dis = 0;
		for (int j = vc[i].first; j < maxn; j++) {
			if (!bs[j][vc[i].second]) dis++;
			else break;
		}
		mn = min(dis - 1, mn);
	}
	else if (c == 'w' || c == 'W') rotate(vc);
	for (int i = 0; i < vc.size(); i++) {
		vc[i].first += 1 - ((allin && (c == 'a' || c == 'A' || c == 'd' || c == 'D')) || flag || c=='w'||c=='W');
		if (c == 'A' || c == 'a' && allin) vc[i].second--;
		else if (c == 'D' || c == 'd' && allin) vc[i].second++;
		else if (c == 's' || c == 'S') vc[i].first += mn - 1;
		put(vc[i].first, vc[i].second, '#', 2);
	}
	pushdown(vc);
}
inline bool build(const int k, const int lx, const int ly) {
	if (k == 0) {
		for (auto it = s.begin(); it != s.end(); it++) put(it->first, it->second, '#', 2);
		return true;
	}
	s.emplace(lx, ly);
	int w = rand() % 4, cnt = 0;
	while ((!POSIN(lx + dx[w], ly + dy[w]) || s.count({ lx + dx[w], ly + dy[w] }) || bs[lx + dx[w]][static_cast<size_t>(ly) + dy[w]]) && cnt < 8) w = nxt[w], cnt++;
	if (cnt == 8) return false;
	return build(k - 1, lx + dx[w], ly + dy[w]);
}
inline void update() {
	int l = maxn - 1;
	for (; bs[l].none(); l--);
	for (int i = maxn - 1; i > l; i--) bs[i] = bs[i - maxn - 1 + l];
	for (int i = 0; i < maxn - l - 1; i++) bs[i].reset();
}
int main() {
	system("TITLE 俄罗斯方块 v1.1 作者: williamwei");
	srand((unsigned int)time(0));
	color(12);
	for (int i = 0; i < maxn; i++) { for (int j = 0; j < maxn; j++) putchar((i == 0 || j == 0 || i == maxn - 1 || j == maxn - 1) ? '#' : ' '); putchar('\n'); }
	while (true) {
		while (clear()) update();
		for (int i = 2; i < maxn; i++) for (int j = 2; j < maxn; j++) if (bs[i][j])put(i, j, '#', 2);
		s.clear();
		if (!build((rand() % 3) + 3, 2, (rand() % (maxn - 2)) + 2)) {
			system("cls");
			color(12);
			printf("YOU LOSE\nSCORE:%lld\n", score);
			break;
		}
		else pushdown(vector<pair<int, int> >(s.begin(), s.end()));
		Sleep(700);
	}
}