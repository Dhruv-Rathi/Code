#include<bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
#define F first
#define S second

struct range_maintenance{

	set<ii> st;

	void fill_range(int l, int r){
		auto it = st.upper_bound({l,1e9});
		if(it!=st.begin()){
			it--;
			if(it->S>=l){
				l = it->F;
				r = max(r, it->S);
				st.erase(it);
			}
		}

		it = st.upper_bound({r,1e9});
		if(it!=st.begin()){
			it--;
			if(it->S>=r){
				r = it->S;
				l = min(l, it->F);
				st.erase(it);
			}
		}

		while(1){
			auto it = st.lower_bound({l,0});
			if((it == st.end()) || (it->F>r)) break;
			else{
				st.erase(it);
			}
		}
		st.insert({l,r});
	}
	void clear_range(int l, int r){
		auto it = st.upper_bound({l,1e9});
		if(it!=st.begin()){
			it--;
			if(it->S>=r){
				int lo1 = it->F;
				int hi1 = l;

				int lo2 = r;
				int hi2 = it->S;

				st.erase(it);
				st.insert({lo1,hi1});
				st.insert({lo2,hi2});
				return;
			}
			if(it->S>=l){
				int lo = it->F;
				int hi = l;
				st.erase(it);
				st.insert({lo,hi});
			}
		}
		it = st.upper_bound({r,1e9});
		if(it!=st.begin()){
			it--;
			if(it->S>=r){
				int lo = r;
				int hi = it->S;
				st.erase(it);
				st.insert({lo,hi});
			}
		}

		while(1){
			auto it = st.lower_bound({l,0});
			if((it == st.end()) || (it->F>=r)) break;
			else{
				st.erase(it);
			}
		}
	}
	bool check_point(int x){
		auto it = st.upper_bound({x,1e9});
		if(it == st.begin()){
			return 0;
		}else{
			it--;
			if(it->S>=x){
				return 1;
			}else{
				return 0;
			}
		}
	}
	bool check_range_any(int x, int y){ // covers any part of the range
		auto it = st.upper_bound({x,1e9});
		if(it!=st.end()){
			if(it->F<=y){
				return 1;
			}
		}
		return check_point(x);
	}
	bool check_range_all(int x, int y){ // covers whole range.
		auto it = st.upper_bound({x,1e9});
		if(it == st.begin()){
			return 0;
		}else{
			it--;
			if(it->S>=y){
				return 1;
			}else{
				return 0;
			}
		}
	}

	void print_status(){
		cout<<"Current status: ";
		for(auto v: st){
			cout<<"("<<v.F<<","<<v.S<<"), ";
		}
		cout<<'\n';
	}
};


void solve(){
	int q; cin>>q;
	range_maintenance rm;

	while(q--){
		int ch; cin>>ch;
		if(ch==1){
			int l,r; cin>>l>>r;
			rm.fill_range(l,r);
		}else if(ch == 2){
			int l,r; cin>>l>>r;
			rm.clear_range(l,r);
		}else if(ch == 3){
			int x; cin>>x;
			cout<<rm.check_point(x)<<'\n';
		}else{
			int l,r; cin>>l>>r;
			cout<<rm.check_range_any(l,r)<<'\n';
		}
		rm.print_status();
	}
}



signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// int tc; cin>>tc; while(tc--)
		solve();
 
}