#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z,int security_value[])
{
    int no_of_stocks=0;
   // participants code here
    int n = *(&security_value+1)-security_value;
    
    int dp[z+1] = {0};
    for (int i=0;i<=z;i++){
        for(int j = 0;j<n;j++){
            for(int k = 1; k<=(j+1);k++){
                if(k*security_value[j]<=i)
                {
                    dp[i] = max(dp[i], dp[i-k*security_value[j]]+k);
                }
            }
        }
    }
    no_of_stocks = dp[z];
    return no_of_stocks;
}
 
int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z,security_value);
cout << no_of_stocks_purchased;
 
 
 
}
 
 
