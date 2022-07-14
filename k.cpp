#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, b, c) for (int i = a; i < b; i += c)
int h, w;
int recur(int dp[1000][1000], int i, int j)
{
    if (i == h - 1 && j == w - 1)
        return 1;
    if (i >= h || j >= w)
        return 0;
    if (dp[i][j] == 0)
        return 0;
    if (dp[i][j] > 0)
        return dp[i][j];
    return dp[i][j] = recur(dp, i + 1, j) + recur(dp, i, j + 1);
}
int main()
{

    cin >> h >> w;
    char c;
    int dp[1000][1000];
    memset(dp, -1, sizeof dp);
    fo(i, 0, h, 1)
        fo(j, 0, w, 1)
    {
        cin >> c;
        if (c == '#')
            dp[i][j] = 0;
    }

    cout << recur(dp, 0, 0);
    return 0;
}