#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define F first
#define S second



class LRUCache {
	list<int> order;
	// key -> val, iterator
	unordere_map<int, pair<int, list<int>::iterator>> cache;
	int maxsize = 0;

	void touch (int id){
		auto it = cache.find(id);
		int key = it->first;
		order.erase(it->second->second);
		order.push_front(key);
		it->second.second = order.begin();
	}
	int get(int key){
		if(cache.find(key) == cache.end()){
			return -1;
		}
		else {
			touch(key); return cache[key].first;
		}
	}
	void put(int key, int val){
		if(cache.find() == cache.end()){
			if(cache.size() == maxsize){
				int del = order.back();
				cache.erase(del); order.pop_back();
			}
			order.push_front(key);
		}else{
			touch(key);
		}
		cache[key] = make_pair(val, order.begin());
	}
};

class LFUCache {
private:
	int capacity, size, lfu=0;
	unordere_map<int, list<int>> keys;
	unordere_map<int, pair<int,int>> values;
	unordere_map<int,list<int>::iterator> iters;
	void update(int key){
		int freq = values[key].S;
		auto iter = iters[key];
		values[key].S++;
		keys[freq].erase(iter);
		keys[freq+1].push_back(key);
		iters[key] = --keys[freq+1].end();
		if(keys[lfu].empty()){
			lfu++;
		}
	}

public:
	LFUCache(int capacity){
		this->capacity = capacity;
		size = 0;
	}
	int get(int key){
		if(values.find(key) == values.end()){
			return -1;
		}
		update(key);
		return values[key].first;
	}

	void put(int key, int value){
		if(!capacity){
			return;
		}
		if(values.find(key)!=values.end()){
			values[key].F = value;
			update(key);
		}
		else{
			if(size == capacity){
				int evict = keys[lfu].front();
				keys[lfu].pop_front();
				values.erase(evict);
				iters.erase(evict);
			}else{
				size++;
			}
			values[key] = {value, 1};

			keys[1].push_back(key);
			iters[key] = --keys[1].end();
			lfu = 1;
		}
	}
};

// Min Stack:

class MinStack {
private:
	stack<int> st;
	int minEle;

public:
	void push(int x){
		if(st.empty()){
			st.push(x);
			minEle = x;
			return;
		}
		if(x>=minEle){
			st.push(x);
		}else{
			st.push(2*x-minEle);
			minEle = x;
		}
	}

	void pop(int x){
		int y = st.top();
		if(y<minEle){
			minEle = 2*minEle - y;
		}
		st.pop();
	}
};

void solve(){
	
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