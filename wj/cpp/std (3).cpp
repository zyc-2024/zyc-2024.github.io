#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q;
struct Tree {
#define forGraph(u, v) for (int i = fst[u], v = to[i]; i; i = nxt[i], v = to[i])
    int fst[MAXN], to[MAXN], nxt[MAXN], w[MAXN], tot;
    void add(int u, int v, int ww) {
        to[++tot] = v, nxt[tot] = fst[u], fst[u] = tot, w[tot] = ww;
    }
};
struct Tree1 : public Tree {
    int dfn[MAXN], idf[MAXN], dcnt;
    int dep[MAXN];
    int st[MAXN][20];
    long long dis[MAXN];
    void dfs(int u, int pre) {
        dfn[u] = ++dcnt, idf[dcnt] = u;
        dep[u] = dep[pre] + 1;
        forGraph(u, v) if (v != pre) {
            dis[v] = dis[u] + w[i];
            dfs(v, u);
            idf[++dcnt] = u;
        }
    }
    void build() {
        for (int i = 1; i <= dcnt; i++)
            st[i][0] = idf[i];
        for (int j = 1; j <= 18; j++) {
            for (int i = 1; i + (1 << j) - 1 <= dcnt; i++) {
                st[i][j] = (dep[st[i][j - 1]] < dep[st[i + (1 << (j - 1))][j - 1]]) ? 
                    st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    int lca(int u, int v) {
        int l = dfn[u], r = dfn[v];
        if (l > r) swap(l, r);
        int len = __lg(r - l + 1);
        return dep[st[l][len]] < dep[st[r - (1 << len) + 1][len]] ? 
            st[l][len] : st[r - (1 << len) + 1][len];
    }
    long long dist(int u, int v) {
        return dis[u] + dis[v] - 2 * dis[lca(u, v)];
    }
} t1;
struct SegmentTree {
    struct Chain {
        pair<int, long long> u, v;
        long long dist;
        inline Chain() : u(), v(), dist(0) {}
        inline Chain(pair<int, long long> u, pair<int, long long> v) : u(u), v(v) {
            dist = t1.dist(u.first, v.first) + u.second + v.second;
        }
        inline bool operator<(const Chain &b) const {
            return dist < b.dist;
        }
        inline Chain operator+(const Chain &b) const {
            Chain c = max(*this, b);
            for (auto x : {u, v}) if (x.first) {
                for (auto y : {b.u, b.v}) if (y.first) {
                    c = max(c, Chain(x, y));
                }
            }
            return c;
        }
    };
    struct Node {
        Chain chain;
        long long tag;
    } t[MAXN << 2];
    #define lc (i << 1)
    #define rc (i << 1 | 1)
    void tag(int i, long long v) {
        t[i].tag += v;
        t[i].chain.u.second += v;
        t[i].chain.v.second += v;
        if (t[i].chain.v.first) t[i].chain.dist += 2 * v;
    }
    void pushDown(int i) {
        if (t[i].tag) {
            tag(lc, t[i].tag);
            tag(rc, t[i].tag);
            t[i].tag = 0;
        }
    }
    void pushUp(int i) {
        t[i].chain = t[lc].chain + t[rc].chain;
    }
    void build(int *idf, long long *dis, int i = 1, int l = 1, int r = n) {
        if (l == r) {
            t[i].chain.u.first = idf[l];
            t[i].chain.u.second = dis[idf[l]];
            return;
        }
        int mid = (l + r) >> 1;
        build(idf, dis, lc, l, mid);
        build(idf, dis, rc, mid + 1, r);
        pushUp(i);
    }
    void add(int a, int b, long long v, int i = 1, int l = 1, int r = n) {
        if (a <= l && r <= b) {
            tag(i, v);
            return;
        }
        int mid = (l + r) >> 1;
        pushDown(i);
        if (a <= mid) add(a, b, v, lc, l, mid);
        if (b > mid) add(a, b, v, rc, mid + 1, r);
        pushUp(i);
    }
} st;
long long ans[MAXN * 5];
struct Tree2 : public Tree {
    long long dis[MAXN];
    int dfn[MAXN], ed[MAXN], idf[MAXN], dcnt;
    void dfs1(int u, int pre) {
        dfn[u] = ++dcnt, idf[dcnt] = u;
        forGraph(u, v) if (v != pre) {
            dis[v] = dis[u] + w[i];
            dfs1(v, u);
        }
        ed[u] = dcnt;
    }
    void build() {
        st.build(idf, dis);
    }
    vector<pair<int, int>> qs[MAXN];
    void dfs2(int u, int pre) {
        for (auto p : qs[u]) {
            ans[p.first] = max(
                t1.dist(st.t[1].chain.u.first, p.second) + st.t[1].chain.u.second,
                t1.dist(st.t[1].chain.v.first, p.second) + st.t[1].chain.v.second
            );
        }
        forGraph(u, v) if (v != pre) {
            st.add(1, n, w[i]);
            st.add(dfn[v], ed[v], -2 * w[i]);
            dfs2(v, u);
            st.add(1, n, -w[i]);
            st.add(dfn[v], ed[v], 2 * w[i]);
        }
    }
} t2;
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        t1.add(u, v, w);
        t1.add(v, u, w);
    }
    t1.dfs(1, 0);
    t1.build();
    for (int i = 1; i < n; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        t2.add(u, v, w);
        t2.add(v, u, w);
    }
    t2.dfs1(1, 0);
    t2.build();
    for (int i = 1; i <= q; i++) {
        int a, b; scanf("%d%d", &a, &b);
        t2.qs[b].push_back({i, a});
    }
    t2.dfs2(1, 0);
    long long Ans = 0;
    for (int i = 1; i <= q; i++) {
//        printf("%lld\n", ans[i]);
        Ans ^= ans[i];
    }
    printf("%lld\n",Ans);
    return 0;
}

/*
3 4
1 2 1
2 3 2
1 2 2
2 3 1
1 1
1 2
2 1
2 2
*/