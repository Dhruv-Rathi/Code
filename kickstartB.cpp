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

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}

ll power(ll a, ll b, ll N){ ll p = 1;
    while (b > 0){
        if (b & 1) p = ((p % N) * (a % N)) % N;
        a = ((a % N) * (a % N)) % N; b /= 2;
    } return p;
}

const int N = 500010;

int fact[N];

void pre(){
	fact[0] = 1;
	for(int i=1;i<N;i++){
	fact[i] = 1LL*fact[i-1]*i%mod;
	}
}

int ncr(int n, int r){
	if(n<r) return 0;
	int ans = fact[n];
	ans = 1LL*ans*power(fact[n-r],mod-2,mod)%mod;
	ans = 1LL*ans*power(fact[r],mod-2,mod)%mod;
	ans = (ans+mod)%mod;
	return ans;
}
void solve(int tc){

	cout<<"Case #"<<tc<<": ";
	ld pi = 3.14159265358979323;
	int r,a,b; cin>>r>>a>>b;
	ld ans = 0;
	while(r>0){
		ans+=pi*r*r;
		r*=a;
		if(r == 0)  break;
		ans+=pi*r*r;
		r/=b;
	}
	cout<<fixed<<setprecision(6)<<ans<<'\n';

}

int checkPalindrome(string str)
{
    int len = str.length();
   
    for (int i = 0; i < len / 2; i++) {
       
        if (str[i] != str[len - i - 1])
            return 0;
    }
   
    return 1;
}

void solve2(int tc){
	cout<<"Case #"<<tc<<": ";
	ll a; cin>>a;
	ll ans = 0;
	for(ll i=1;i*i<=a;i++){
		if(a%i == 0){
			ans+=checkPalindrome(to_string(i));
			if(i!=a/i){
				ans+=checkPalindrome(to_string(a/i));
			}
		}
	}

	cout<<ans<<'\n';
}

void solve3(int tc){
	cout<<"Case #"<<tc<<": ";
	ll n,d; cin>>n>>d;
	vi v(n);
	f(i,0,n){
		cin>>v[i];
	}
	ll ans = 0;
	if(d==2){
		for(ll i=0;i<n;i++){
			if(v[i] == 1) ans++;
			while(v[i] == 1 && i<n){
				i++;
			}
		}
	}
	else{
		ll mx = 0;
		map<ll,ll> m;
		f(i,0,n){
			mx = max(mx, min(v[i],d-v[i]));
		}
		ll cnt=0, uni = 0;
		for(ll i=0;i<n;i++){
			if(v[i] == mx) cnt++;
			while(v[i] == mx && i<n){
				i++;
			}

			if(m[v[i]] == 0){
				uni++;
			}
			m[v[i]]++;
		}
		ll cnt2=0;
		for(ll i=0;i<n;i++){
			if(v[i] == (d-mx)) cnt2++;
			while(v[i] == (d-mx) && i<n){
				i++;
			}
		}
		
		if(mx == 1){
			ans+=cnt*mx+cnt2*mx;
		}
		else
			ans+=(cnt*(mx-1)+1)+(cnt2*(mx-1)+1);
	}
	cout<<ans<<'\n';
}



// int uniquePathsWithObstacles(vector<vector<int>>& A)
// {
     
//     int r = A.size(), c = A[0].size();
     
//     // create a 2D-matrix and initializing
//     // with value 0
//     vector<vector<int>> paths(r, vector<int>(c, 0));
     
//     // Initializing the left corner if
//     // no obstacle there
//     if (A[0][0] == 0)
//         paths[0][0] = 1;
         
//     // Initializing first column of
//     // the 2D matrix
//     for(int i = 1; i < r; i++)
//     {
//         // If not obstacle
//         if (A[i][0] == 0)
//             paths[i][0] = paths[i-1][0];
//     }
     
//     // Initializing first row of the 2D matrix
//     for(int j = 1; j < c; j++)
//     {
         
//         // If not obstacle
//         if (A[0][j] == 0)
//             paths[0][j] = paths[0][j - 1];
//     }  
      
//     for(int i = 1; i < r; i++)
//     {
//         for(int j = 1; j < c; j++)
//         {
             
//             // If current cell is not obstacle
//             if (A[i][j] == 0)
//                 paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
//         } 
//     }
     
//     // Returning the corner value
//     // of the matrix
//     return paths[r - 1];
// }

// void solve4(int tc){
// 	cout<<"Case #"<<tc<<": ";
// 	int r,c; cin>>r>>c;
// 	char a[r][c];
// 	for(int i=0;i<r;i++){
// 		for(int j=0;j<c;j++){
// 			cin>>a[i][j];
// 		}
// 	}
// 	string ans = "S";
// 	int i=0,j=0;
// 	while(a[i+1][0]=='*' && i<r){
// 		ans+="SS";
// 		i++;
// 	}
// 	ans+="E";
// 	i--;
// 	while(a[i][j+1]=='*' && j<c){
// 		ans+="EE";
// 	}
// 	ans+="N";
// 	j--;
// 	for(;j>=0;j--){
// 		for(i)
// 	}


// }

void solve4(int tc){
	cout<<"Case #"<<tc<<": ";
	ll n,d; cin>>n>>d;
	vi v(n);
	f(i,0,n){
		cin>>v[i];
	}
	ll ans = 0;
	if(d==2){
		for(ll i=0;i<n;i++){
			if(v[i] == 1) ans++;
			while(v[i] == 1 && i<n){
				i++;
			}
		}
	}
	else{
		ll mx = 0, mn = 1e9+1;
		map<ll,ll> m;
		f(i,0,n){
			mx = max(mx, v[i]);
			mn = min(mn, v[i]);
		}
		ll steps = 0;

	}

}

signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    int tc; cin>>tc; 
    for(int i=1;i<=tc;i++)
    solve3(i);
    
    
    
}