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

struct node {
	node *child[26];
	int cnt;
	vector<string> wend;
	node(){
		cnt = 0;
		for(int i=0;i<26;i++){
			child[i] = NULL;
		}
	}
};

void insert(node *root, string &s){
	node *cur = root;

	for(int i=0;i<s.length();i++){
		int x = s[i]-'a';
		cur->cnt++;
		if(cur->child[x] == NULL){
			cur->child[x] = new node();
		}
		cur = cur->child[x];
	}
	cur->wend.push_back(s);
	cur->cnt++;
}


void search(node* cur, int lev, int k, string &st, vector<string> &ans){
	if(cur == NULL || ans.size() == k) return;

	if(lev == st.size()){
		for(auto &i: cur->wend){
			ans.push_back(i);
			if(ans.size() == k) return;
		}
	}

	for(int i=0;i<26;i++){
		if(cur->child[i]!=NULL){
			if(lev<st.size() && i == (st[lev]-'a')){
				search(cur->child[i], lev+1, k, st, ans);
			}else if(lev == st.size()){
				search(cur->child[i], lev, k, st, ans);
			}
		}
	}
}


void solve(){
	ll n,m,q; cin>>n>>m>>q;
	node *root = new node();

	// vector<pair<ll, string>> dict;
	for(ll i=0;i<n;i++){
		int len; string s;
		cin>>len>>s;
		insert(root, s);
	}
	while(q--){
		int len, k; string s; 
		cin>>len>>s>>k;
		string temp = "";
		for(int i=0;i<len;i++){
			temp+=s[i];
			vector<string> ans;
			search(root, 0, k, temp, ans);
			for(auto &i: ans) cout<<i<<' ';
			cout<<'\n';
		}
	}
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}