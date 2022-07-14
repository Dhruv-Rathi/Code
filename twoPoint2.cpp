#include<bits/stdc++.h>
using namespace std;

#define int long long

int distinct = 0;
int freq[1000100];

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = 0;

    // define pointers
    int tail = 0,head = -1; // [tail,head]
    while(tail<n){
        while(head+1<n && ((distinct<k) || ( distinct==k && freq[arr[head+1]]>0 ))){
            head++;
            freq[arr[head]]++;
            if(freq[arr[head]]==1)distinct++;
        }

        // update the answer
        ans += (head-tail+1);

        // move tail one step
        if(tail<=head){
            // remove tail element
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0)distinct--;
            tail++;
        }else{
            tail++;
            head = tail-1;
        }
    }

    cout<<ans<<endl;
}

signed main(){
    solve();
}