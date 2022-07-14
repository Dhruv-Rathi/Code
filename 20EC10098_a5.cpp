/*	
	Name: Dhruv Rathi
	Roll No.: 20EC10098
	ASSIGNMENT 5
*/
#include<iostream>
using namespace std;

// I am storing the number of ways in which i can be created from l to r of the given string in dp[l][r][i].

// This function checks the value of the dp array and then prints the results.
void possible(int l, int arr[], int m[5][5], int n, int dp[][50][5] ){
	cout<<l<<": ";
	if(dp[0][n-1][l] > 0) cout<<"Possible\n";
	else cout<<"Not Possible\n";
}


bool check(int l, int r, int dp[][50][5]){
	for(int i=0;i<5;i++){
		if(dp[l][r][i]>0) return 0;
	}
	return 1;

}
// This function is to fill the dp array with all the necessary values.
void countways(int i, int j, int arr[],int m[][5], int dp[][50][5]){
	if(i==j){
		if(dp[i][j][arr[i]]==-1){
			dp[i][j][arr[i]] = 1;
		}
		else{
			++dp[i][j][arr[i]];
		}
	}
	else if(i == j-1){
		if(dp[i][j][m[arr[i]][arr[j]]]==-1){
			dp[i][j][m[arr[i]][arr[j]]] = 1;
		}
		else{
			++dp[i][j][m[arr[i]][arr[j]]];
		}
	}
	if(!check(i, j, dp)){
		for(int l=0;l<5;l++){
			if(dp[i][j][i]>0){
				dp[i][j][m[i][arr[j]]]++;
			}
		}
	}
	else{
		countways(i,j-1,arr,m,dp);
	}
}


int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	cout<<"Enter M:\n";
	int m[5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>m[i][j];
		}
	}
	cout<<"Enter string: ";
	char s[50];
	cin>>s;
	// Calculating length of the string entered.
	int len=0;
	while(s[len]!='\0') len++;
	// cout<<len<<'\n';
	// Converting character array to integer array.
	int arr[len];
	for(int i=0;i<len;i++){
		arr[i] = s[i]-'0'-1;
	}
	int dp[50][50][5];
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++)
			for(int k=0;k<5;k++)
				dp[i][j][k]=-1;
	}
	// Calling this function first so that the dp array gets filled.
	countways(0,len-1,arr,m,dp);

	// Printing the results.
	possible(1,arr,m,len,dp);
	possible(2,arr,m,len,dp);
	possible(3,arr,m,len,dp);
	possible(4,arr,m,len,dp);
	possible(5,arr,m,len,dp);

	cout<<"Number of ways in which mixing "<<s<<" results in\n";
	for(int i=0;i<5;i++){
		cout<<i+1<<":"<<dp[0][len-1][i]<<'\n';
	}

	// cout<<countways(arr, m, len, 0, len-1)<<'\n';
	return 0;
}