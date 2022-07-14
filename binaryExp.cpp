#include<bits/stdc++.h>
using namespace std;

using lli = long long int;

lli binary_expo(lli a, lli b, lli mod)
{
	lli ans = 1;
	while(b)
	{
		if(b%2 == 1){
			ans = (1LL*ans*a) %mod;
		}
		a = (1LL*a*a) %mod;
		b/=2;
	}
	return ans;
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<binary_expo(a,b,1e9+7)<<'\n';
}

