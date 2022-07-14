//----AUTHOR: eeshan_deo_iitkgp----/
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvd vector<vd>
#define vvll vector<vll>
#define vvc vector<vc>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define w(x)  \
    int x;    \
    cin >> x; \
    for (ll tc = 1; tc <= x; tc++)
#define in(i, x, y) for (ll i = x; i < y; i++)
#define rin(i, x, y) for (ll i = x; i >= y; i--)
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define lb lower_bound
#define ub upper_bound


ll fxp(ll a, ll b) {
    assert(b >= 0);
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res % mod;
}

inline ll minv(ll x) { return fxp(x, mod - 2); }

void c_p_c() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int mXn = 1001;
const ll inf = 1e18;
int n, m, col[mXn][mXn], name[mXn][mXn];

int dx[] = {1, 0};
int dy[] = {0, 1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

struct RetroActiveUnionFind  //no path comp, only rank comp
{
    int n, components, *par, *sz;
    multiset<int> compSz;
    RetroActiveUnionFind() {}
    RetroActiveUnionFind(int csz)
    {
        n = components = csz;
        compSz.clear();
        par = new int[n + 1], sz = new int[n + 1];
        for (int i = 0; i <= n; i++)
            par[i] = i, sz[i] = 1, compSz.insert(sz[i]);
    }
    int find(int x)
    {
        if (x != par[x])
            return find(par[x]);
        return x;
    }
    vpii st;
    void merge(int x, int y)
    {
        int xroot = find(x), yroot = find(y);
        if (xroot == yroot)return;
        if (sz[xroot] < sz[yroot])swap(x, y), swap(xroot, yroot);
        //cout << "merge " << xroot << ' ' << yroot << endl;
        compSz.erase(compSz.find(sz[xroot]));
        compSz.erase(compSz.find(sz[yroot]));
        sz[xroot] += sz[yroot];
        par[yroot] = xroot;
        st.pb({yroot, xroot});
        compSz.insert(sz[xroot]);
        components--;
    }
    void revertAll() {
        while (!st.empty()) {
            int yroot = st.back().ff, xroot = st.back().ss;
            // cout << "revert " << yroot << ' ' << xroot << endl;
            st.pop_back();
            par[yroot] = yroot;
            compSz.erase(compSz.find(sz[xroot]));
            sz[xroot] -= sz[yroot];
            compSz.insert(sz[xroot]);
            compSz.insert(sz[yroot]);
        }
    }
    int getMaxSz() {
        return *(compSz.rbegin());
    }
    void print()
    {
        for (int i = 1; i <= n; i++)
        {
            //cout << "par: " << i << " -> " << par[i] << endl;
            cout << "sz: " << i << " -> " << sz[i] << endl;
        }
    }
};

signed main() {
    c_p_c();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    cin >> n >> m;
    int cnt = 0;
    in(i, 0, n) {
        in(j, 0, m) {
            cin >> col[i][j];
            name[i][j] = ++cnt;
        }
    }
    RetroActiveUnionFind uf(cnt);
    map<pii, vpii> edg;
    in(i, 0, n) {
        in(j, 0, m) {
            in(k, 0, 2) {
                int ni = i + dx[k], nj = j + dy[k];
                if (isValid(ni, nj)) {
                    //cout << ni << ' ' << nj << endl;
                    int c1 = col[i][j], c2 = col[ni][nj];
                    if (c1 > c2)swap(c1, c2);
                    if (c1 == c2)uf.merge(name[i][j], name[ni][nj]);
                    else {
                        edg[ {c1, c2}].pb({name[i][j], name[ni][nj]});
                    }
                }
            }
        }
    }
    uf.st.clear();
    uf.print();
    int ans = 0;
    for (auto &v : edg) {
        for (auto x : v.ss) {
            uf.merge(x.ff, x.ss);
        }
        // cout << "for " << v.ff.ff << ' ' << v.ff.ss << ' ' << uf.getMaxSz() << endl;
        ans = max(ans, uf.getMaxSz());
        uf.revertAll();
    }
    cout << ans << endl;
}