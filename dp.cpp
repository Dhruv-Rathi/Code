#include<bits/stdc++.h>
using namespace std;

int n;
int x[101];
bool saved[101][100100];
bool dp[101][100100];

// O(#S * (1 + #T))
bool rec(int level, int sneed){
	// Pruning
	if(sneed<0) return 0;
	// base
	if(level == n){
		if(sneed==0) return 1;
		return 0;
	}
	// cache check
	if(saved[level][sneed])
		return dp[level][sneed];
	// transition
	bool ans = rec(level+1, sneed) || rec(level+1, sneed-x[level]);

	//save and return
	saved[level][sneed] = 1;
	return dp[level][sneed] = ans;
}
vector<vector<int>> allsol;
vector<int> cursol;
void generate(int level, int sneed){
	if(level==n){
		allsol.push_back(cursol);
		return;
	}
	if(rec(level+1, sneed))
		generate(level+1, sneed);
	if(rec(level+1, sneed-x[level])){
		cursol.push_back(x[level]);
		generate(level+1, sneed-x[level]);
		cursol.pop_back();
	}
}

// O(N + Q)
void solve() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	int q; cin>>q;
	while(q--){
		int y;cin>>y;
		cout<<rec(0,y)<<'\n';
		if(rec(0,y)){
			allsol.clear();
			generate(0,y);
			for(auto sol: allsol){
				for(auto v: sol){
					cout<<v<<" ";
				}
				cout<<endl;
			}
				
			cout<<endl;
		}
	}
}
int main(){
	solve();
	return 0;
}