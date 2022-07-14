#include<bits.stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// keep some information

	// define pointers
	int tail=0, head=-1;
	while(tail<n){
		while(head+1<n && (/* its possible to take */)){
		// take that element
		}
		// update the answer

		// mobe tail one step
		if(tail<=head){
			// remove tail element
		}
		else{
			tail++;
			head = tail-1;
		}
	}
}