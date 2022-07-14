#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

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
	if (peri % 4 != 0)
	{
	    cout << "NO" << endl; 
	    return;
	}
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
			auto it = m.upper_bound(side_length);
			if (it != m.begin())
				--it;
			if ((*it) <= side_length)
			{
			    side_length -= (*it);
			    m.erase(it);
			}
			else
			{
			    cout << "NO" << endl; return;
			    
			}
		}

	}
	if (m.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//seive();
	int tc;
	cin >> tc;
	while (tc--)
	{
		solve();
	}

}