#include <bits/stdc++.h>
using namespace std;

int cnt=0;
int n;
vector<int> cols;
vector<int> diagonals;//正对角线
vector<int> antidiagonals;


void backtrack(int row){
    if(row == n){
        cnt++;
        return;
    }
    for(int col=0;col<n;col++){
        int diagonal = row-col+n - 1;
        int antidiagonal = row+col;
        if(cols[col] or diagonals[diagonal] or antidiagonals[antidiagonal]){
            continue;
        }
        cols[col] = diagonals[diagonal] = antidiagonals[antidiagonal] = 1;
        backtrack(row+1);
        cols[col] = diagonals[diagonal] = antidiagonals[antidiagonal] = 0;


    }


}


int main(){
    
    //cin>>n;
    n=8;
    cols.resize(n, 0);
    diagonals.resize(2 * n - 1, 0);
    antidiagonals.resize(2 * n - 1, 0);
    backtrack(0);
    cout<<cnt;
}