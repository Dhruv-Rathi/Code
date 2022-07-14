#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define S second
#define F first
#define all(a) (a).begin(), (a).end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define MAXN 200100

struct node{
	ll sum, lazy1, lazy2;
	node(){
		sum = 0;
		lazy1 = 0;
		lazy2 = 0;
	}
};

node merge(node a, node b){
	node c;
	c.sum = a.sum+b.sum;
	return c;
}

ll arr[MAXN];
node t[4*MAXN];

void push(ll id, ll l, ll r){
	
	if(t[id].lazy2){
		t[id].sum = (r-l+1)*t[id].lazy2;
		if(l!=r){
			t[2*id].lazy2 = t[id].lazy2;
			t[2*id+1].lazy2 = t[id].lazy2;
			t[2*id].lazy1 = t[2*id+1].lazy1 = 0;
		}
		t[id].lazy2 = 0;
	}
	if(t[id].lazy1){
		t[id].sum+=t[id].lazy1*(r-l+1);
		if(l!=r){
			t[2*id].lazy1 = t[id].lazy1;
			t[2*id+1].lazy1 = t[id].lazy1;
		}
		t[id].lazy1 = 0;
	}
}


#define mid (l+r)/2
void build(ll id, ll l, ll r){
	if(l == r){
		t[id].sum = arr[l];
		return ;
	}
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	t[id] = merge(t[2*id], t[2*id+1]);
}

void update1(ll id, ll l, ll r, ll lq, ll rq, ll v){
	push(id,l,r);
	if(lq>r || l>rq) return;
	if(l>=lq && r<=rq){
		t[id].lazy1 += v;
		push(id, l, r);
		return ;
	}
	update1(2*id,l,mid,lq,rq,v);
	update1(2*id+1,mid+1,r,lq,rq,v);
	t[id] = merge(t[2*id], t[2*id+1]);
}

void update2(ll id, ll l, ll r, ll lq, ll rq, ll v){
	push(id,l,r);
	if(lq>r || l>rq) return;
	if(l>=lq && r<=rq){
		t[id].lazy2 = v;
		push(id, l, r);
		return ;
	}
	update2(2*id,l,mid,lq,rq,v);
	update2(2*id+1,mid+1,r,lq,rq,v);
	t[id] = merge(t[2*id], t[2*id+1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq){
	push(id,l,r);
	if(lq>r || l>rq) return node();
	if(l>=lq && r<=rq){
		return t[id];
	}
	return merge(
	query(2*id,l,mid,lq,rq) ,
	query(2*id+1,mid+1,r,lq,rq));
}
#undef mid

void solve(){
	ll n,q; cin>>n>>q;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	build(1,0,n-1);
	while(q--){
		int ch; cin>>ch;
		ll a,b,x;
		if(ch == 1){
			cin>>a>>b>>x;
			a--; b--;
			update1(1,0,n-1,a,b,x);
		}else if(ch == 2){
			cin>>a>>b>>x;
			a--; b--;
			update2(1,0,n-1,a,b,x);
		}else{
			cin>>a>>b;
			a--; b--;
			cout<<query(1,0,n-1,a,b).sum<<'\n';
		}
	}

}
 
signed main()
{
    IOS
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll tc = 1;
    // cin>>tc;
    for(int i=1;i<=tc;i++){
    //	cout<<"Case #"<<i<<": ";
    	solve();
    }
    
}