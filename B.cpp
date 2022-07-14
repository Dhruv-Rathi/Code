#include<bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
       int s,b;
       cin>>s>>b;
       vector<int> space(s);
       vector<pair<int,int>> base(b);
       vector<int> ans;
       for(int i=0LL;i<s;++i) cin>>space[i];
       for(int i=0LL;i<b;++i)
       {
              int x,y;
              cin>>x>>y;
              base[i]= make_pair(x,y);
       }
       
       sort(base.begin(),base.end());
       // for(int i=1LL;i<b;++i)
       // base[i].second+=base[i-1].second;
       
       for(int i=0;i<s;++i)
       {
              int attack= space[i];
              int low= 0;
              int high= b-1;
              if(attack==0 || attack<base[0].first)
              {
                     ans.push_back(0LL);
                     continue;
              }
              while(low<high)
              {
                     int mid=low+ (high-low+1)/2;
                     if(base[mid].first<=attack)
                     low=mid+1;// can attack
                     else
                     high=mid-1;// can't attack
              }
              
              if((low>=1) && ((base[low].first)>attack))
              {
                     low--;
                     // ans.push_back(base[low].second);
                     
              }
              // else 
              //  ans.push_back(base[low].second);
              int sum=0;
              for(int i=0;i<=low;++i)
              sum+=base[i].second;
              ans.push_back(sum);
             
       }
       for(auto x: ans)
       cout<<x<<" ";
       
}
int32_t main()
{ 
        
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    
    
}