#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

set<int> maidx, miidx;

ll compute(int n, int pos){
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(i == pos) continue;
		auto it1 = maidx.lower_bound(i);
		auto it2 = miidx.lower_bound(i);
		if(it1 == maidx.end() || it2 == miidx.end())
			break;
		int x = max(*it1, *it2);
		ans += 1LL*(n-x);
		if(pos>=x) ans--;
	}
	return ans;
}

void solve(){
	int n; cin>>n;
	vector<ll> a(n);
	map<ll,ll> m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]++;
	}
	if(n == 1){
		cout<<"1\n"; return;
	}
	auto it = *(m.rbegin());
	ll ma = it.F, maCnt = it.S;
	auto it1 = *(m.begin());
	ll mi = it1.F, miCnt = it1.S;
	maidx.clear(); miidx.clear();
	for(int i=0;i<n;i++){
		if(a[i] == ma) maidx.insert(i);
		if(a[i] == mi) miidx.insert(i);
	}

	ll ans = compute(n, -1);
	if(maCnt == 1){
		m[ma]--;
		m.erase(m.find(ma));
		maidx.clear();
		auto it3 = *(m.rbegin());
		int pos = -1;
		for(int i=0;i<n;i++){
			if(a[i] == ma) pos = i;
			if(a[i] == it3.F) maidx.insert(i);
		}
		ans = max(ans, compute(n, pos));
		maidx.clear(); maidx.insert(pos);
		m[ma]++;
	}
	if(miCnt == 1){
		m[mi]--;
		m.erase(m.find(mi));
		miidx.clear();
		auto it4=*(m.begin());
		int pos=-1;
		for(int i=0;i<n;i++){
			if(a[i] == mi) pos = i;
			if(a[i] == it4.F) miidx.insert(i);
		}
		ans = max(ans, compute(n,pos));
		miidx.clear(); miidx.insert(pos);
		m[mi]++;
	}
	cout<<ans<<'\n';

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