#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define vi vector<ll>
#define vvi vector<vi>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ss second
#define ff first
#define all(arr) arr.begin(), arr.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test(t) ll t;cin>>t;while(t--)
// #define int ll
 
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto element : v) os << element << " ";return os;}

void solve()
{
	int n;
	cin >> n;
	multiset<int> m;
	int peri = 0;
	int times = 4;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		m.insert(x);
		peri += x;
	}
	int side_length = peri / 4;
	int temp = side_length;
	while (times--)
	{
		side_length = temp;
		while (side_length != 0)
		{
			if (m.empty())
			{
				cout << "NO" << endl;
				return;
			}
			auto it = lower_bound(m.begin(), m.end(), side_length);
			if (it != m.begin() && (*it > side_length))
				--it;

			if (*it <= side_length)
			{side_length -= *it; m.erase(it);}
			else
			{cout << "NO" << endl; return;}

		}

	}
	if (m.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}
 
signed main()
{
    fast
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

 
    test(t)
    solve();
    
    
    
}