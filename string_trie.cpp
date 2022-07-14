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
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T> ostream &operator<<(ostream &os, const vector<T> a){ for (auto ele : a) os << ele << " "; return os;} 
template <class T> istream &operator>>(istream &is, vector<T> &a){ for (auto &ele : a) is >> ele; return is; }

int good[26];

struct node{
	node* child[26];
	int cnt;
	// vector<string> wend;
	node(){
		cnt = 0;
		for(int i=0;i<26;i++){
			child[i] = NULL;
		}
	}
};

struct trie{
	node *root;
	trie(){
		root = new node();
	}

	void insert(string s){
		node* cur = root;
		for(int i=0;i<s.length();i++){
			
			int x = s[i]-'a';
			if(cur->child[x] == NULL){
				cur->child[x] = new node();
			}
			cur = cur->child[x];
			cur->cnt++;
		}
	}

	ll rec(node* cur, int k){
		if(k<0) return 0;
		ll ans = (cur->cnt>0?1:0);
		for(int i=0;i<26;i++){
			if(cur->child[i]!=NULL){
				ans+=rec(cur->child[i],k+good[i]-1);
			}
		}
		return ans;
	}

	ll count_good(int k){
		return rec(root,k);
	}
};


void solve(){
	string s, st;
	cin>>s>>st;
	f(i,0,26){
		good[i] = st[i]-'0';
	}
	trie t;
	for(int i=0;i<s.length();i++){
		t.insert(s.substr(i));
	}
	int k;
	cin>>k;
	cout<<t.count_good(k);
}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    // test(t)
    solve();
    
}