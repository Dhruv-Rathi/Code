#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll N=3e5;
int main(){

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	ll t;
	cin>>t;
	while(t--){
	ll n,x,ans=0;
	cin>>n;
	ll A[N]={0};
	ll M[N]={0};
	for(ll i=0;i<n;i++){
		cin>>x;
		A[x]++;
	}

	for(ll i=1;i<N;i++)
		M[i]=M[i-1]+A[i];
	
	for(ll i=1;i<N;i++)
		for(ll j=i;j<N;j+=i){
			ans+=A[i]*(M[j-1]-M[j-i-1])*(j/i-1);
		}
	cout<<ans<<"\n";
	}
}
	


