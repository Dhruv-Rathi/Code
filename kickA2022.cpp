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

void solve(int tc){
	cout<<"Case #"<<tc<<": ";
	string n; cin>>n;
	ll sum = 0;
	for(ll i=0;i<n.length();i++){
		sum+=n[i]-'0';
	}
	if(sum%9 == 0){
		string ans="";
		ans+=n.substr(0,1)+"0"+n.substr(1,n.length()-1);
		cout<<ans<<'\n';
	}
	else{
	    string ans="";
		for(int i=1;i<9;i++){
			if((sum+i)%9 == 0){
				bool flag = 0;
				for(ll j=0;j<n.length();j++){
					if((n[j]-'0')>i){
						flag=1;
						ans+=n.substr(0,j)+to_string(i)+n.substr(j,n.length()-j);
						break;
					}
				}
				if(!flag){
					ans=n+to_string(i);
				}
				cout<<ans<<'\n';
				return;
			}
				
		}
	}
}

bool check_pal(string s){
	int l = 0;
    int h = s.length()-1;

    while(h > l){
        if(s[l++] != s[h--]){
            return 0;
        }
        if(s[l] == '?'|| s[h] =='?') {
        	if(s[l] == '?' && s[h]!='?')
        	s[l] = 1-s[h];
        	else if(s[h] == '?' && s[l]!='?')
        		s[h] = 1-s[l];
        	else{
        		s[l] = 0;
        		s[h] = 1;
        	}
        	return 0;
        }
    }
    return 1;
}

// void solve3(int tc){
// 	cout<<"Case #"<<tc<<": ";

// 	ll n; cin>>n;
// 	string s; cin>>s;

// 	if(n<5){
// 		cout<<"POSSIBLE\n";return;
// 	}
// 	for(int i=0;i<n-4;i++){
// 		string sn = s.substr(i,5);
// 		int l = 0;
//     int h = sn.length()-1;

//     while(h > l){
//         if(sn[l++] != sn[h--]){
//             return 0;
//         }
//         if(sn[l] == '?'|| sn[h] =='?') {
//         	if(sn[l] == '?' && sn[h]!='?')
//         	sn[l] = 1-sn[h];
//         	else if(s[h] == '?' && s[l]!='?')
//         		s[h] = 1-s[l];
//         	else{
//         		s[l] = 0;
//         		s[h] = 1;
//         	}
//         	return 0;
//         }
//     }
//     return 1;
// 	}
// 	if(s[0] == '?' || s[n-1] == '?'){
// 		cout<<"POSSIBLE\n";return;
// 	}
// 	for(int i=0;i<n-4;i++){
// 		if(check_pal(s.substr(i,5))){
// 			cout<<"IMPOSSIBLE\n"; return;
// 		}
// 	}
// 	cout<<"POSSIBLE\n"; return;

// }

ll product(ll n){
	ll p=1;
	while(n){
		p*=n%10;
		n/=10;
	}
	return p;
}
ll sum_dig(ll n){
	ll sum = 0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

void solve4(int tc){
	cout<<"Case #"<<tc<<": ";
	ll a,b;
	cin>>a>>b;
	ll ans = 0;
	f(i,a,b+1){
		if(product(i)%sum_dig(i) == 0) ans++;
	}

	cout<<ans<<'\n';
}
signed main()
{
    fast
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

 
    int tc; cin>>tc;
    f(i,1,tc+1)
    solve4(i);
    
    
}