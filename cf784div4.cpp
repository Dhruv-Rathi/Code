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

void solve(){
	int n; cin>>n;

	cout<<"Division ";
	if(n>=1900) cout<<1;
	else if(n>=1600) cout<<2;
	else if(n>=1400) cout<<3;
	else cout<<4;
	cout<<'\n';
}

void solve2(){
	int n; cin>>n;
	vi a(n);
	f(i,0,n) cin>>a[i];
	sort(all(a));
	int cnt = 1;
	f(i,1,n){
		if(a[i] == a[i-1]) cnt++;
		else cnt = 1;
		if(cnt == 3){
			cout<<a[i]<<'\n'; return;
		}
	}
	cout<<-1<<'\n';
}

void solve3(){
	int n; cin>>n;
	vi a(n);
	f(i,0,n) cin>>a[i];
	int p = a[0]%2;
	for(int i=2;i<n;i+=2){
		if(a[i]%2 != p){
			cout<<"NO\n"; return;
		}
	}
	p = a[1]%2;
	for(int i=1;i<n;i+=2){
		if(a[i]%2 != p){
			cout<<"NO\n"; return;
		}
	}
	cout<<"YES\n";
}

void solve4(){
	int n; cin>>n;
	string s; cin>>s;
	int w=0, r=0, b=0, x=0, y=0;
	for(int i=0;i<n;i++){
		if(s[i] == 'W') {
			w++;
			if(x && !y){
				cout<<"NO\n"; return;
			}
			if(!x && y){
				cout<<"NO\n"; return;
			}
			x = 0; y = 0;
		}
		else if(s[i] == 'R') {
			r++;
			x++;
		}
		else {
			b++;
			y++;
		}

		
	}

	f(i,0,n){
		int cnt1=0, cnt2=0;
		if(s[i] == 'R'){
			ll j=i-1;
			while(s[j] == 'B' && j>=0){
				cnt1++;
				j--;
			}
			j = i+1;
			while(s[j]=='B' && j<n){
				cnt2++;
				j++;
			}
			if(cnt1>1 && cnt2>1){
				cout<<"NO\n"; return;
			}
		}
	}
	f(i,0,n){
		int cnt1=0, cnt2=0;
		if(s[i] == 'B'){
			ll j=i-1;
			while(s[j] == 'R' && j>=0){
				cnt1++;
				j--;
			}
			j = i+1;
			while(s[j]=='R' && j<n){
				cnt2++;
				j++;
			}
			if(cnt1>1 && cnt2>1){
				cout<<"NO\n"; return;
			}
		}
	}

	// for(int i=0;i<n;){
	// 	while(s[i] == 'B' && i<n){
	// 		i++;
	// 	}
	// 	if(i==n || s[i]=='W'){
	// 		cout<<"NO\n"; return;
	// 	}
	// 	while(s[i] == 'R' && i<n)
	// }

	// for(int i=0)

	if(b==0 && r==0){
		cout<<"YES\n"; return;
	}
	if(r==0 && b!=0){
		cout<<"NO\n"; return;
	}
	if(b==0 && r!=0){
		cout<<"NO\n"; return;
	}

	cout<<"YES\n";
}

void solve5(){
	int n; cin>>n;
	vi a(11,0), b(11,0);
	map <ll,ll> m;
	vector<string> str;
	f(i,0,n){

		string s; cin>>s;
		str[i] = s;
		m[s[0]-'a']++;
		m[s[]]
		a[s[0]-'a']++;
		b[s[1]-'a']++;
	}

	cout<<a<<'\n'<<b<<'\n';

	ll ans = 0;
	f(i,0,n){
		m[str[i][1]-'a']--;
		ans+=m
	}
}

void solve6(){
	int n; cin>>n;
	vi a(n);
	f(i,0,n) cin>>a[i];
	vi pre(n,0);
	pre[0] = a[0];
	f(i,1,n){
		pre[i] = pre[i-1]+a[i];
	}
	vi back(n,0);
	back[n-1] = a[n-1];
	for(int i=n-2;i>=0;i--){
		back[i]= back[i+1]+a[i];
	}
	reverse(all(back));
	// cout<<pre<<'\n'<<back<<'\n';
	int ans = 0, i=0, j=0;

	while(i<n && j<n){
		if(pre[i]==back[j]){
			if(i+j+2 <= n){
				ans = max(ans,i+j+2);
				i++; j++;
			}
			else{
				break;
			}
		}
		else if(pre[i]>back[j]){ 
			j++;
		}
		else{
			i++;
		}
	}

	while(i<n){
		if(i+j+2 <= n){
				ans = max(ans,i+j+2);
				i++;
			}
			else{
				break;
			}
	}

	while(j<n){
		if(i+j+2 <= n){
				ans = max(ans,i+j+2);
				 j++;
			}
			else{
				break;
			}
	}

	cout<<ans<<'\n';

}

void solve7(){
	int n,m; cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c; cin>>c;
			if(c=='.') arr[i][j]=0;
			else if(c == '*') arr[i][j] = 1;
			else arr[i][j] = 2;
		}
	}

	for(int i=0;i<m;i++){
		for(int j=n-1;j>=0;j--){
			while(arr[j][i] == 0 && j>=0){
				j--;
			}
			if(j>=0 && arr[j][i] == 1){
				arr[j][i] = 0; j++;
				while(arr[j][i] == 0 && j<n){
					j++;
				}
				j--;
				arr[j][i] = 1;
			}
		}
	}
	// f(i,0,n){
	// 	f(j,0,m) cout<<arr[i][j];
	// 	cout<<'\n';
	// }

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0) cout<<'.';
			else if(arr[i][j]==1) cout<<'*';
			else cout<<'o';
		}
		cout<<'\n';
	}
}

void solve8(){
	ll n,k; cin>>n>>k;
	ll a[31]={0};
	f(i,0,n){
		ll x; cin>>x;
		ll j=0;
		while(x){
			a[j++]+=x%2;
			x/=2;
		}
	}

	ll i = 30, ans = 0;
	
	while(i>=0 && k>0){
		if((n-a[i])<=k){
			
			k-=(n-a[i]);
			ans+=pow(2,i);
			a[i] = n;
		}
		// cout<<k<<' ';
		i--;
	}

	while(i>=0){
		if(a[i] == n){
			ans+=pow(2,i);
		}
		i--;
	}

	cout<<ans<<'\n';

}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve5();
    
    
    
}