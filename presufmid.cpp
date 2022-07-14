#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int pi[100005];

void prefix(string s){
	int n = s.length(); 
	pi[0] = 0;
	for(int i=1;i<n;i++){
		int j = pi[i-1];
		while(j>0 && s[i]!=s[j]){
			j = pi[j-1];
		}
		if(s[i] == s[j]){
			j++;
		}
		pi[i] = j;
	}

	for(int i=0;i<n;i++){
		cout<<pi[i]<<' ';
	}
	cout<<'\n';
}

void solve(){
	int n; cin>>n;
	string s; cin>>s;
	// prefix(s);
	int kmp[n+1];
	string ans = "";
	int i=0, j=-1; kmp[0]=-1;
	while(i<n){
		while(j!=-1 && s[i]!=s[j]) j=kmp[j];
		j++; i++;
		kmp[i] = j;
	}
	// for(int i=0;i<=n;i++){
	// 	cout<<kmp[i]<<' ';
	// }cout<<'\n';

	if(kmp[n] == 0){
		cout<<"-1\n"; return;
	}

	for(int i=n-1;i>1;i--){
		if(kmp[i] == kmp[n]){
			cout<<s.substr(0,kmp[n])<<'\n';
			return;
		}
	}

	if(kmp[kmp[n]] == 0){
		cout<<-1<<'\n';
	}else{
		cout<<s.substr(0,kmp[kmp[n]])<<'\n';
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
    cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}