// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;
#define M 100

// Function to count numbers in the range
// [0, X] whose product of digit is K
int cntNum(string X, int i, int prod, int sum,
		int st, int tight, int dp[M][M][2][2])
{
	// If count of digits in a number
	// greater than count of digits in X
	if (i >= X.length() || prod > K) {

		// If product of digits of a
		// number equal to K
		return (prod%sum == 0);
	}

	// If overlapping subproblems
	// already occurred
	if (dp[prod][i][tight][st] != -1) {
		return dp[prod][i][tight][st];
	}

	// Stores count of numbers whose
	// product of digits is K
	int res = 0;

	// Check if the numbers
	// exceeds K or not
	int end = tight ? X[i] - '0' : 9;

	// Iterate over all possible
	// value of i-th digits
	for (int j = 0; j <= end; j++) {

		// if number contains leading 0
		if (j == 0 && !st) {

			// Update res
			res += cntNum(X, i + 1, prod, K,
						false, (tight & (j == end)), dp);
		}

		else {

			// Update res
			res += cntNum(X, i + 1, prod * j, K,
						true, (tight & (j == end)), dp);
		}

		// Update res
	}

	// Return res
	return dp[prod][i][tight][st] = res;
}

// Utility function to count the numbers in
// the range [L, R] whose prod of digits is K
int UtilCntNumRange(int L, int R, int K)
{
	// Stores numbers in the form
	// of string
	string str = to_string(R);

	// Stores overlapping subproblems
	int dp[M][M][2][2];

	// Initialize dp[][][] to -1
	memset(dp, -1, sizeof(dp));
	int x = R;
	ll sum = 0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	// Stores count of numbers in
	// the range [0, R] whose
	// product of digits is k
	int cntR = cntNum(str, 0, 1, sum,
					false, true, dp);

	// Update str
	str = to_string(L - 1);

	// Initialize dp[][][] to -1
	memset(dp, -1, sizeof(dp));
	x = L;sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	// Stores count of numbers in
	// the range [0, L - 1] whose
	// product of digits is k
	int cntL = cntNum(str, 0, 1, K,
					false, true, dp);

	return (cntR - cntL);
}
void solve(int tc){
	cout<<"Case #"<<tc<<": ";
	ll a,b;
	cin>>a>>b;

}
// Driver Code
int main()
{
	fast
    

 
    int tc; cin>>tc;
    f(i,1,tc+1)
    solve(i);
}
