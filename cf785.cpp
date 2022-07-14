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
	string s; cin>>s;
	int sum = 0, n = s.length();
	f(i,0,s.length()){
		sum+=(s[i]-'a'+1);
	}
	int bob = 0;
	if(n%2)
		bob = min(s[0]-'a'+1,s[n-1]-'a'+1);
	int alice = sum-bob;
	int dif = abs(alice-bob);
	if(alice>bob){
		cout<<"Alice ";
	}else cout<<"Bob ";
	cout<<dif<<'\n';
}

void solve2(){
	string s; cin>>s;
	map<char, int> m;
	int uni = 0;
	int n = s.length();
	f(i,0,n){
		m[s[i]]++;
	}
	bool ans = 1;
	int k = m.size(); 
	f(i,0,n-k){
		if(s[i] != s[i+k]){ ans = 0; break;}
	}
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
}



// void solve4(){
// 	string s; cin>>s;
// 	int m[26]={0};
// 	int n = s.length();
// 	f(i,0,n){
// 		m[s[i]-'a']++;
// 		if(m[s[i]]-m[s[]])
// 	}
// }

void printArray(int p[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    cout << p[i] << " "; 
    cout << endl; 
} 
  
ll ans = 0;

bool is_palindrome(int n ){
    int rev = 0, orig = n;
    while( n != 0){
        rev = 10*rev + (n % 10);
        n = n/10;
    }
    return orig == rev;

}

bool checkarr(int p[], int n) 
{ 
    int i = 0;
    while(p[i]>9 && i<n){
    	if(!is_palindrome(p[i])) return 0;
    	i++;
    }
    return 1;
} 
void printAllUniqueParts(int n) 
{ 
    int p[n]; // An array to store a partition 
    int k = 0; // Index of last element in a partition 
    p[k] = n; // Initialize first partition as number itself 
  
    while (true) 
    { 
        // print current partition 
        if(checkarr(p, k+1) && p[0]>9) ans = (ans+1)%mod;
        else if(p[0]<=9) ans = (ans+1)%mod;
        // cout<<p[0]<<'\n';
        // printArray(p,k+1);
       
        int rem_val = 0; 
        while (k >= 0 && p[k] == 1) 
        { 
            rem_val += p[k]; 
            k--; 
        } 
  
        // if k < 0, all the values are 1 so there are no more partitions 
        if (k < 0) return; 
  
        // Decrease the p[k] found above and adjust the rem_val 
        p[k]--; 
        rem_val++; 
  
  
        while (rem_val > p[k]) 
        { 
            p[k+1] = p[k]; 
            rem_val = rem_val - p[k]; 
            k++; 
        } 

        p[k+1] = rem_val; 
        k++; 
    } 
} 

void pre2(){
	int a[40001];
	for(int i=1;i<11;i++){
		ans = 0;
		printAllUniqueParts(i);
		a[i] = ((ans%mod)+mod)%mod;
	}
	for(int i=1;i<11;i++){
		cout<<a[i]<<'\n';
	}
}
void solve3(){
	ans = 0;
	int n; cin>>n;
	printAllUniqueParts(n);
	cout<<((ans%mod)+mod)%mod<<'\n';

}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // pre2();
 	// cout<<"H";
    test(t)
    solve2();
    
    
    
}