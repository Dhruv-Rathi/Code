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

class trieNode {
public:
	int cnt;
	trieNode* left;
	trieNode* right;
	trieNode() {
		cnt = 0;
		left = NULL;
		right = NULL;
	}
};

void insert(int n, trieNode* head){
	trieNode* cur = head;
	for(int i=31;i>=0;i--){
		int bit = (n>>i)&1;
		if(bit){
			if(!cur->right){
				cur->right = new trieNode();
			}
			cur = cur->right;
			cur->cnt++;
		}else{
			if(!cur->left){
				cur->left = new trieNode();
			}
			cur = cur->left;
			cur->cnt++;
		}
	}
}

void del(int n, trieNode *head){
	trieNode* cur = head;
	for(int i=31;i>=0;i--){
		int bit = (n>>i)&1;
		if(bit){
			cur->right->cnt--;
			cur = cur->right;
		}else{
			cur->left->cnt--;
			cur = cur->left;
		}
	}
}

ll findMaxXor(int n, trieNode *head){
	trieNode* cur = head;
	ll ans = 0;
	for(int i=31; i>=0; i--){
		int bit = (n>>i)&1;
		if(bit == 0){
			if(cur->right && cur->right->cnt>0){
				ans+=(1LL<<i);
				cur = cur->right;
			}else cur = cur->left;
		}else{
			if(cur->left && cur->left->cnt>0){
				ans+=(1LL<<i);
				cur = cur->left;
			}else cur = cur->right;
		}
	}
	return ans;
}

ll countXor(int n, int k, trieNode *head){
	trieNode* cur = head;
	ll ans = 0;
	for(int i=31;i>=0;i--){
		if(cur == NULL) break;
		int bit = (n>>i)&1;
		int k_bit = (k>>i)&1;
		if(bit){
			if(k_bit){
				if(cur->right)
					ans+=cur->right->cnt;
				cur = cur->left;
			}else{
				cur = cur->right;
			}
		}else{
			if(k_bit){
				if(cur->left)
					ans+=cur->left->cnt;
				cur = cur->right;
			}else{
				cur = cur->left;
			}
		}
	}
	
	return ans;
}

void solve(){
	int q; cin>>q;
	trieNode *head = new trieNode();
	insert(0,head);

	while(q--){
		char ch; ll x; cin>>ch>>x;
		if(ch == '+'){
			insert(x,head);
		}else if(ch == '-'){
			del(x,head);
		}else{
			cout<<findMaxXor(x,head)<<'\n';
		}
	}
}

void solve2(){
	int n; cin>>n;
	trieNode* head = new trieNode();
	
	ll pre = 0, ans = 0;
	insert(0,head);
	f(i,0,n){
		int x; cin>>x;
		pre = pre^x;
		ans = max(ans, findMaxXor(pre, head));
		insert(pre,head);

	}
	cout<<ans<<'\n';
}

void solve3(){
	int n,k; cin>>n>>k;
	trieNode* head = new trieNode();
	
	ll pre = 0, ans = 0;
	insert(0,head);
	f(i,0,n){
		int x; cin>>x;
		pre = pre^x;
		ans+=countXor(pre,k,head);
		insert(pre,head);
	}cout<<ans<<'\n';
}

 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    test(t)
    solve3();
    
}