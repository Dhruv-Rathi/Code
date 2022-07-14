#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = 0;
    // keep some information
    int cnt = 0;
    // define pointers
    int tail = 0,head = -1; // [tail,head]
    while(tail<n){
        while(head+1<n && (/*its possible to take next element*/) ((arr[head+1]==0 && cnt<k)||(arr[head+1]==1 && cnt<=k))){
            // take thatv element
            head++;
            if(arr[head]==0)cnt++;
        }

        // update the answer
        ans = max(ans,(head-tail+1));

        // move tail one step
        if(tail<=head){
            // remove tail element
            if(arr[tail]==0)cnt--;
            tail++;
        }else{
            tail++;
            head = tail-1;
        }
    }

    cout<<ans<<endl;
}


void solve2(){
    string s,t;
    cin>>s>>t;
    int a[26] = {0};
    for(int i=0;i<t.length();i++){
        a[t[i]-'a']++;
    }
    int head = -1, tail = 0, cur = 0;
    int taken[26] = {0};
    int ans = s.length();
    string final=s;
    while(tail<s.length()){
        while(head+1<s.length() && cur<t.length()){
            head++; 
            int x = s[head]-'a';
            if(taken[x]<a[x])
                cur++;
            taken[x]++;
        }
        if(cur==t.length()){
            if(ans>(head-tail+1)){
                ans = head-tail+1;
                final = s.substr(tail,head-tail+1);
            }
        }
        if(a[s[tail]-'a']){
            taken[s[tail]-'a']--;
            if(taken[s[tail]-'a']<a[s[tail]-'a'])
                cur--;
        }
        tail++;
    }
    cout<<final<<'\n';
}

void solve3(){
     int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = 0;
    // keep some information
    map<ll,ll> freq;
    int distinct = 0;   
    // define pointers
    int tail = 0,head = -1; // [tail,head]
    while(tail<n){
        while(head+1<n && (distinct<k||(distinct == k && freq[arr[head+1]]>0)) ){
            // take thatv element
            head++;
            if(freq[arr[head]] == 0){
                cnt++;
            }
            freq[arr[head]]++;
        }

        // update the answer
        ans += (head-tail+1);

        // move tail one step
        if(tail<=head){
            // remove tail element
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0) distinct--;
            tail++;
        }else{
            tail++;
            head = tail-1;
        }
    }

    cout<<ans<<endl;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int _t; cin>>_t; while(_t--)
    solve2();

    return 0;
}