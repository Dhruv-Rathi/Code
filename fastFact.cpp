#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = 1e6;
int sp[N];

void fastFact(){
	for(int i=1;i<=N;i++) sp[i] = i;

	// O(Nlog(logN))

	for(int i=2;i<=N;i++){
		if(sp[i] == i){ // That means it is a prime
			for(int j=2*i;j<=N;j+=i){
				if(sp[j] == j){
					sp[j] = i;
				}
			}
		}
	}
}

vector<int> primeFact(int x){
	vector<int> ans;
	while(x>1){
		ans.push_back(sp[x]);
		x/=sp[x];
	}
	return ans;
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