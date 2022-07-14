#include<bits/stdc++.h>

using namespace std;
#define int long long

int board[9][9],ans;
string s;
const int n = 7;

bool is_valid(int r,int c){

if(r<1 || r>7 || c<1 || c>7) return false;
return true;

}

void rec(int level,int r,int c){

    if(r == 7 && c == 1){
        if(level == 48) ans++;
        return;
    }

    if(board[r][c-1] == 1 && board[r][c+1] == 1 && board[r-1][c] == 0 && board[r+1][c] == 0) return;
    if(board[r][c-1] == 0 && board[r][c+1] == 0 && board[r-1][c] == 1 && board[r+1][c] == 1) return;

    board[r][c] = 1;

    if(s[level] == 'D'){
        if(is_valid(r+1,c) && board[r+1][c] == 0){
            rec(level+1,r+1,c);
        }
    }

    else if(s[level] == 'R'){
        if(is_valid(r,c+1) && board[r][c+1] == 0){
            rec(level+1,r,c+1);
        }
    }

    else if(s[level] == 'U'){
        if(is_valid(r-1,c) && board[r-1][c] == 0){
            rec(level+1,r-1,c);
        }
    }

    else if(s[level] == 'L'){
        if(is_valid(r,c-1) && board[r][c-1] == 0){
            rec(level+1,r,c-1);
        }
    }

    else{ //s[level] == '?' , can go anywhere
        if(is_valid(r+1,c) && board[r+1][c] == 0){
            rec(level+1,r+1,c);
        }
        if(is_valid(r,c+1) && board[r][c+1] == 0){
            rec(level+1,r,c+1);
        }
        if(is_valid(r-1,c) && board[r-1][c] == 0){
            rec(level+1,r-1,c);
        }
        if(is_valid(r,c-1) && board[r][c-1] == 0){
            rec(level+1,r,c-1);
        }
    }

    board[r][c] = 0;

    return;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    for(int i=0;i<9;i++) board[0][i] = 1;
    for(int i=0;i<9;i++) board[8][i] = 1;
    for(int i=1;i<8;i++) board[i][0] = 1;
    for(int i=1;i<8;i++) board[i][8] = 1;

    cin >> s;
    ans = 0;
    rec(0,1,1);
    cout << ans << "\n" ;

    return 0;
}