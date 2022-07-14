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

 
string s;
ll ans = 0;
const int n = 7;
int visited[9][9];

int is_valid(int r, int c){
	if(r<1 || r>7 || c<1 || c>7){
		return 0;
	}
	return 1;
}

void rec(ll level, ll r, ll c){
    if(r == 7 && c == 1){
    	if(level == 48)
    		ans++;
    	return;
    }

    if(visited[r][c-1] == 1 && visited[r][c+1]==1 && visited[r-1][c] == 0 && visited[r+1][c] == 0) return;
    if(visited[r][c-1] == 0 && visited[r][c+1]==0 && visited[r-1][c] == 1 && visited[r+1][c] == 1) return;
    visited[r][c] = 1;
    // cout<<"Hello";
    if(s[level] == 'R'){
    	if(is_valid(r,c+1)&&visited[r][c+1]==0){
    		rec(level+1,r,c+1);
    	}
    }
    else if(s[level] == 'L'){
    	if(is_valid(r,c-1)&&visited[r][c-1]==0){
    		rec(level+1,r,c-1);
    	}
    }
    else if(s[level] == 'D'){
    	if(is_valid(r+1,c) && visited[r+1][c] == 0){
    		rec(level+1,r+1,c);
    	}
    }
    else if(s[level] == 'U'){
    	if(is_valid(r-1,c) && visited[r-1][c] == 0){
    		rec(level+1,r-1,c);
    	}
    }
    else{
    	if(is_valid(r,c+1)&&visited[r][c+1]==0){
    		rec(level+1,r,c+1);
    	}
    	if(is_valid(r,c-1)&&visited[r][c-1]==0){
    		rec(level+1,r,c-1);
    	}
    	if(is_valid(r-1,c) && visited[r-1][c] == 0){
    		rec(level+1,r-1,c);
    	}
    	if(is_valid(r-1,c) && visited[r-1][c] == 0){
    		rec(level+1,r-1,c);
    	}
    }

    visited[r][c] = 0;
    return;

}
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 	f(i,0,9){
		visited[0][i] = 1;
		visited[8][i] = 1;
		visited[i][0] = 1;
		visited[i][8] = 1;
	}
    ans = 0;
	cin>>s;
	// cout<<s<<'\n';
	
    rec(0,1,1);
    
    cout<<ans;
    
    
    
}