#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vector<int>> vvii;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
#define mod 1000000007
#define mod2 998244353
#define f(x,a,b) for(int x=a;x<b;x++)
#define frev(x,a,b) for(int x=a;x>=b;x--)
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

// int n,m;
// vpii g[100100];
// int dis[100100];


// void BFS01(int sc){
// 	deque<int> dq;
// 	for(int i=1;i<=n;i++){
// 		dis[i] = 1e9;
// 	}
// 	dis[sc] = 0;
// 	dq.PB(sc);
// 	while(!dq.empty()){
// 		int x = dq.front();
// 		dq.pop_front();
// 		for(auto v: g[x]){
// 			int neigh = v.F;
// 			int weigh = v.S;
// 			if(dis[neigh]>dis[x]+weigh){
// 				dis[neigh] = dis[x]+weigh;
// 				if(weigh == 0){
// 					dq.push_front(neigh);
// 				}else{
// 					dq.push_back(neigh);
// 				}
// 			}
// 		}
// 	}
// }

// void solve(){
// 	memset(g,0,sizeof(g));
// 	cin>>n>>m;
// 	f(i,0,m){
// 		int x,y; cin>>x>>y;
// 		g[x].PB({y,0});
// 		g[y].PB({x,1});
// 	}
// 	BFS01(1);
// 	if(dis[n]==1e9) cout<<-1;
// 	else
// 		cout<<dis[n];
// 	cout<<'\n';
// }


 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 	

    // test(t)
    solve();
    
}