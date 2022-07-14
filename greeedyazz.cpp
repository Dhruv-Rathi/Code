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
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define all(a) a.begin(), a.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define yesorno(x) cout<<((x)?"YES":"NO")<<"\n"
#define test(t) int tc; cin>>tc; while(tc--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 

void solve(){
	int n; cin>>n; string s; cin>>s;

	int a[26] = {0};
	f(i,0,n){
		a[s[i]-'a']++;
	}
	
	int od = 0, ev = 0;
	for(int i=0;i<26;i++){
		if(a[i]){
			if(a[i]%2)
				od++;
			else
				ev++;
		}
	}
	if(n%2){
		if(od!=1){
			cout<<-1<<'\n'; return;
		}
	}else{
		if(od){
			cout<<-1<<'\n'; return;
		}
	}

	int l = 0, r = n-1;
	int ans = 0;
	while(l<=r){
		if(s[l] == s[r]){
			l++; r--;
		}else{
			int front = l, back = r;

			while(s[front]!=s[r]){
				front++;
			}
			while(s[back]!=s[l]){
				back--;
			}
			if(front-l<r-back){
				while(front!=l){
					swap(s[front],s[front-1]);
					front--;
					ans++;
				}
			}else{
				while(back!=r){
					swap(s[back],s[back+1]);
					back++;
					ans++;
				}
			}
			l++; r--;
		}
		
	}

	cout<<ans<<'\n';
}
 
void solve2(){
	ll n; cin>>n;
	ll w[n];
	f(i,0,n){cin>>w[i];}
	sort(w,w+n);
	if(w[0]!=1){
		cout<<1<<'\n'; return;
	}

	ll lim = 1;
	for(int i=1;i<n;i++){
		if(w[i]>lim+1){
			break;
		}else{
			lim+=w[i];
		}
	}
	cout<<lim+1<<'\n';
}
void solve3(){
	ll n,k; cin>>n>>k;
	ll s[n];
	f(i,0,n){
		cin>>s[i];
	}
	ll pre[n+1] = {0};
    ll ans = 0;
    for(int i=0;i<(n+1-k);i++){
        if(i!=0)
            pre[i]+=pre[i-1];
        if((s[i] == 0 && pre[i]%2 == 0)||(s[i] == 1 && pre[i]%2 == 1)){
            pre[i]+=1;
            pre[i+k]-=1;
            ans++;
        }
    }
    
    for(int i = (n+1-k);i<n;i++){
        pre[i]+=pre[i-1];
    }
    bool f = 0;
    for(int i=0;i<n;i++){
        if((s[i] == 0 && pre[i]%2 == 0)||(s[i] == 1 && pre[i]%2 == 1)){
            f = 1;
            break;
        }
    }
    if(f){
        cout<<-1<<'\n';
    }else{
        cout<<ans<<'\n';
    }

}

bool comp(const pair<int,int> &a,const pair<int,int> &b){return ((a.F - a.S) < (b.F - b.S));}

void solve4(){

	int n; cin>>n;
	vpll a(n);
	f(i,0,n){
		cin>>a[i].F>>a[i].S;
	}
	sort(all(a),comp);
	reverse(all(a));
	ll ans = 0, cnt = 0;
	f(i,0,n){
		if(ans<a[i].F){
			cnt += (a[i].F-ans);
			ans+=(a[i].F-ans);
		}
		ans-=a[i].S;
	}

	cout<<cnt<<'\n';
}

void solve5(){
	int n; cin>>n;
	int v[n], w[n];
	f(i,0,n){
		cin>>v[i];
	}
	sort(v,v+n);
	f(i,0,n){
		cin>>w[i];
	}
	sort(w,w+n); reverse(w,w+n);
	ll ans = 0;
	f(i,0,n){
		ans+= 1LL*v[i]*w[i];
	}
	cout<<ans<<'\n';
}



void solve6(){
	int m; cin>>m;
	vector<string> s(m);
	f(i,0,m){
		cin>>s[i];
	}
	ll cnt[m][2];
	memset(cnt,0LL,sizeof(cnt));
	f(i,0,m){
		for(char c: s[i]){
			if(c == '0') cnt[i][0]++;
			else cnt[i][1]++;
		}
	}
	vector<int> id(m);
	f(i,0,m){
		id[i] = i;
	}
	sort(all(id), [&](int x, int y){
		return cnt[x][1]*cnt[y][0]<cnt[y][1]*cnt[x][0];
	});

	string st="";
	f(i,0,m){
		st+=s[id[i]];
	}
	ll pre[st.length()]={0};
	if(st[0] == '1'){
		pre[0] = 1;
	}
	f(i,1,st.length()){
		pre[i] = pre[i-1]+(st[i] == '1');
	}
	ll ans = 0;
	for(ll i=0;i<st.length();i++){
		if(st[i] == '0'){
			ans+=pre[i];
		}
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
    solve3();
}