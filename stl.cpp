#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1e9+7
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {
  
  for(auto element : v) {
 
    os << element << " ";
  }
 
  return os;
}
struct monotone_dequeue{
	deque<int> dq;
	void insert(int x){// O(1) armotize
		while(!dq.empty() && dq.back()>x){
			dq.pop_back();
		}
		dq.push_back(x);

	}
	void remove(int x){
		if(dq.front()==x)
			dq.pop_front();

	}
	int getmin(){
		return dq.front();
	}
};

void solve()
{
	ll n,m;
	cin>>n>>m;
	map<int,int> m1;
	rep(i,0,n)
	{
		int x;
		cin>>x;
		m1[x]++;
	}
	rep(i,0,m)
	{
		int x;
		cin>>x;
		if(m1[x]>0)
		{
			cout<<"YES\n";
			
		}
		else{
			cout<<"NO\n";
			m1[x]++;
		}
	}

}

void solve1()
{
	ll n,k;
	cin>>n>>k;
	vi a(n);
	rep(i,0,n){
		cin>>a[i];
	}
	monotone_dequeue mt;
	for(ll i=0;i<n;i++)
	{
		mt.insert(a[i]);
		if(i-k>=0) mt.remove(a[i-k]);
		if(i>=(k-1)){
			cout<<(mt.getmin())<<' ';
		}
	}
	cout<<'\n';

}

void solve2(){
	int q; cin>>q;
	map<string, int> m;
	rep(i,0,q){
		string ch; cin>>ch;
		string name; cin>>name;
		if(ch == "add"){
			 int y; cin>>y;
			 m[name] = y;
		}
		else if(ch == "erase"){
			// if(m.find(name)!=m.end()){
			// 	m[name]
			// }
			m[name] = 0;
		}else{
			if(m.find(name)!=m.end()){
				cout<<m[name]<<'\n';
			}
			else cout<<0<<'\n';
		}
	}
}

void solve3(){
	map<string, int> m;
	int n; cin>>n;
	rep(i,0,n){
		string s; cin>>s;
		if(m[s] == 0){
			cout<<"OK\n"; 
		}else{
			cout<<s<<m[s]<<'\n';
		}
		m[s]++;
	}
}
void solve4(){
	int q; cin>>q;
	multiset<int> mt;
	while(q--){
		string ch; cin>>ch;
		if(ch == "add"){
			int x; cin>>x;

			mt.insert(x);
		}else if(ch == "erase"){
			int x; cin>>x;
			if(mt.find(x)!=mt.end())
				mt.erase(mt.find(x));

		}else if(ch == "eraseall"){
			int x; cin>>x;
			if(mt.find(x)!=mt.end())
				mt.erase(x);
		}else if(ch == "find"){
			int x; cin>>x;
			if(mt.find(x)!=mt.end()){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}else if(ch == "count"){
			int x; cin>>x;
			cout<<mt.count(x)<<'\n';
		}else if(ch == "print"){
			for(auto i: mt){
				cout<<i<<' ';
			}cout<<'\n';
		}else{
			mt.clear();
		}
	}
}

void solve5(){
	multimap<string, int> m;
    int q; cin>>q;
    while(q--){
        string ch; cin>>ch;
        string name; cin>>name;
        if(ch == "add"){
            int y; cin>>y;
            m.insert({name,y});
        }else if(ch == "erase"){
            auto it = m.find(name);
            if(it!=m.end()){
                m.erase(it);
            }
        }else if(ch == "eraseall"){
            if(m.find(name)!=m.end()){
                m.erase(name);
            }
        }else{
            auto it = m.find(name);
            if(it!=m.end()){
                cout<<it->second<<'\n';
            }else{
                cout<<"0\n";
            }
        }
    }
}
 
int main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve5();
    }  
    
    
   return 0;
}