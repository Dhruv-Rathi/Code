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

int sudoku[9][9];

bool check(int i, int j, int val){
	f(k,0,9){
		if(sudoku[i][k] == val || sudoku[k][j] == val) return false;
	}
	int l = (i/3)*3;
	int r = (j/3)*3;
	for(int a = l; a<(l+3);a++){
		f(b,r,r+3) if(sudoku[a][b] == val) return false;
	}
	return true;
}

void rec(int i, int j){
	if(i==9){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++) cout<<sudoku[i][j];
			cout<<'\n';
		}
		return;
	}
	if(sudoku[i][j] == 0){
		for(int val=1;val<=9;val++){
			if(check(i,j,val)){
				sudoku[i][j] = val;
				if(j == 8){
					rec(i+1,0);
				}else{
					rec(i,j+1);
				}
				sudoku[i][j] = 0; // backtrack
			}
		}
	}else{
		if(j == 8){
			rec(i+1,0);
		}else{
			rec(i,j+1);
		}
	}
}

void solve(){
	string s[9];
	f(i,0,9){
		cin>>s[i];
		f(j,0,9){
			if(s[i][j] == '.'){
				sudoku[i][j] = 0;
			}
			else
				sudoku[i][j] = (s[i][j]-'0');
		}
	}
	// f(i,0,9){
	// 	f(j,0,9) cout<<sudoku[i][j]<<' ';
	// 	cout<<'\n';
	// }

	rec(0,0);

}

void solve2(){
	int n,m,k; cin>>n>>m>>k;
	int p[n][m];
    int row[n];
    int col[m];
    f(i,0,n){
        row[i] = i;
    }
    f(j,0,m) col[j] = j;
    
	f(i,0,n)
		f(j,0,m) cin>>p[i][j];
	while(k--){
		char ch; cin>>ch;
		int x,y; cin>>x>>y; x--; y--;
		if(ch == 'c'){
			swap(col[x], col[y]);
		}else if(ch == 'r'){
			swap(row[x], row[y]);
		}else{
			cout<<p[row[x]][col[y]]<<'\n';
		}
	}
}

void solve3(){
	ll c,d; cin>>c>>d;

	ll a,b;
	a=b=c;
	bool f = 0;
	for( int mask = 0;mask<=31;mask++){
		// cout<<mask<<"->"<<(d&(1<<mask))<<'\n';
		if((!(c&(1<<mask)))&&(d&(1<<mask))){
			// cout<<mask<<' ';
			if(f){
				a = a|(1<<mask);
				f = 0;
			}else{
				b = (b|(1<<mask));
				f = 1;
			}
		}
	}

	cout<<(a+b);

}

void solve4(){
	ll n; cin>>n;
	ll cnt = 0;
	ll ans[64]={0};
	f(i,0,64){
		if(((n>>i)&(1))){
			ans[64-i-1] = 1;
		}
	}
	f(i,0,64){
		cout<<ans[i];
		if(ans[i] == 1){
			cnt++;
		}
	}
	cout<<'\n';
	if(n == 0){
		cout<<-1<<'\n';
		cout<<-1<<'\n';
		cout<<0<<'\n';
		cout<<-1<<'\n';
		cout<<2<<'\n'; 
		return;
	}
	ll y;
	f(i,0,64){
		if(ans[i] == 1){
			cout<<(64-i-1)<<'\n';
			y = (64-i-1);
			break;
		}
	}
	ll x;
	frev(i,63,0){
		if(ans[i] == 1){
			cout<<(64-i-1)<<'\n';
			x = 64-i-1;
			break;
		}
	}
	if(n<0){
		cout<<0<<'\n';
	}
	else{
		if(cnt == 1 && ans[63]!=1){
			cout<<1<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	cout<<(1LL<<x)<<'\n';
	if(n<0){
		cout<<2<<'\n';
	}else{
		if(cnt == 1 && ans[63]!=1){
			cout<<(1LL<<y)<<'\n';
		}else{
			y++;
			cout<<(1LL<<y)<<'\n';
		}
	}
}


 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    test(t)
    solve4();

	// int arr[1501]={0};
 	
 // 	int mul2=1, mul3=1, mul5=1, cnt = 2;

 // 	arr[1] = 1;

 // 	while(cnt<=1500){
 // 		arr[cnt] = min({2*arr[mul2], 3*arr[mul3], 5*arr[mul5]});
 // 		if(arr[cnt] == 2*arr[mul2]){
 // 			mul2++;
 // 		}
 // 		if(arr[cnt] == 3*arr[mul3]){
 // 			mul3++;
 // 		}
 // 		if(arr[cnt] == 5*arr[mul5]){
 // 			mul5++;
 // 		}
 // 		cnt++;
 // 	}
 //    int tc; cin>>tc; while(tc--){
 //    	int n; cin>>n;
 //    	cout<<arr[n]<<'\n';
 //    }
    
    
    
}

