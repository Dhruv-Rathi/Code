#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define f(x,a,b) for(int x=a;x<b;x++)
#define pb push_back
#define eb emplace_back //faster than push_back
#define mod1 1000000007
#define mod2 998244353
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define vecpii vector<pair<int,int>>
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}
struct ranks {
	int p,q;
};


void merge(ranks arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    ranks L[n1], M[n2];

    for (int i = 0; i < n1; i++){
        L[i].p = arr[p + i].p;
        L[i].q = arr[p+i].q;
    }
    for (int j = 0; j < n2; j++){
        M[j].p = arr[q + 1 + j].p;
        M[j].q = arr[q + 1 + j].q;
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;
	
	while (i < n1 && j < n2) {
        if (L[i].p <= M[j].p) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = M[j++];
        }
        
    }

    while (i < n1) {
        arr[k++] = L[i++];
        
    }

    while (j < n2) {
        arr[k++] = M[j++];
    }
}

void mergeSort(ranks arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}


ll rec(int i, int j, int m, int k, ll dp[][41][41], ranks r[], int n){
	if(j>k) return 0;
	if(i == n){
		if(j==k) return 1;
		else return 0;
	}
	if(dp[i][j][m] != -1) return dp[i][j][m];
	ll ans = 0;
	ans=rec(i+1,j,min(m,r[i].q),k,dp,r,n)%mod2;
	if(r[i].q<m) ans=((ans%mod2)+(rec(i+1,j+1,m,k,dp,r,n)%mod2))%mod2;

	return dp[i][j][m] = ans%mod2;
}

void solve()
{
	int n,k; cin>>n>>k;
	int p[n], q[n];
	f(i,0,n) cin>>p[i];
	f(i,0,n) cin>>q[i];
	ranks r[n];
	f(i,0,n){
		r[i].p = p[i];
		r[i].q = q[i];
	}

	mergeSort(r,0,n-1);
	// f(i,0,n){
	// 	cout<<r[i].p<<' '<<r[i].q<<'\n';
	// }
	ll dp[31][31][31];
	for(int i=0;i<=30;i++){
		for(int j=0;j<=30;j++){
			for(int k=0;k<=30;k++){
				dp[i][j][k] = -1;
			}
		}
	}
	cout<<(rec(0,0,n,k,dp,r,n)+mod2)%mod2;



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