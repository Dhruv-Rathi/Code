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


bool isBST = true;

pair<int, int> check(node *cur){
	if(cur == NULL){
		return {1e9, -1e9};
	}
	pair<int,int> LInt = check(cur->left);
	pair<int,int> RInt = check(cur->right);
	if(cur->val >= RInt.F) isBST = false;
	if(cur->val <= LInt.S) isBST = false;
	return {min(LInt.F, cur->val), max(RInt.S, cur->val)};

}

is_BBST = true;

int check2(node *cur){
	if(cur == NULL) return 0;
	int Lht = check(cur->left);
	int Rht = check(cur->right);

	if(abs(Lht-Rht)>1) is_BBST = false;

	return max(Lht, Rht)+1;
}

// MORRIS TRAVERSAL

void printInorder(node *cur){
	while(cur!=NULL){
		if(cur->left!=NULL){
			node *temp = cur->left;
			while(temp->right!=cur && temp->right!=NULL){
				temp = temp->right;
			}
			if(temp->right == cur){ // is active
				temp->right = NULL;
				cout<<cur->val<<' '; // Shift this to else part for preorder.
				cur = cur->right;
			}else{
				temp->right = cur;
				cur = cur->left;
			}
		}else{
			cout<<cur->val<<' ';
			cur = cur->right;
		}
	}
}

void flip(node *cur){
	if(cur == NULL) return;
	swap(cur->left, cur->right);

	flip(cur->left);
	flip(cur->right);
}

// KSUM PATH

// Variant 1: No of KSUM Paths from root to leaf.

int countKPath(node *cur, int K){
	if(cur == NULL) return 0;

	if(cur->left == NULL && cur->right == NULL){
		if(cur->val  ==  K) return 1;
		return 0;
	}
	return countKPath(cur->left, k-(cur->val))+
			countKPath(cur->right, k-(cur->val));
}

// Variant 2: No. of paths with sum K between any 2 nodes.



// Find Diameter:

int dfs(node *cur, int &ans){
	if(cur == NULL) return 0;

	int lc = dfs(cur->left, ans);
	int rc = dfs(cur->right, ans);

	ans = max(ans, lc+1+rc);

	return max(lc, rc)+1;
}



void solve(){
	
}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}