#include <bits/stdc++.h>
using namespace std;
bool is_legal(int *calls, int *n, vector<vector<bool>>&board, vector<bool>&columns, int x, int y){
    *calls += 1;
    return true;
    if (!columns.at(y)){
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < *n; ++j){
                if (board.at(i).at(j) && abs(x-i) == abs(y-j)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
void backtrack(int *calls, int *n, vector<vector<bool>>&board, vector<bool>&columns, int x, int *count){
    *calls += 1;
    if (x == *n){
        *count += 1;
        return;
    }
    for (int y = 0; y < *n; ++y){
        if (is_legal(calls, n, board, columns, x, y)){
            columns.at(y) = true;
            board.at(x).at(y) = true;
            backtrack(calls, n, board, columns, x+1, count);
            columns.at(y) = false;
            board.at(x).at(y) = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    //true at board[i][j] means that a queen is placed at board[i][j]
    //true at column[i] means that a queen is currently at column[i]
    vector<vector<bool>> board(n, vector<bool>(n));
    vector<bool>columns(n);
    int count = 0;
    int calls = 1;
    auto t1 = chrono::high_resolution_clock::now();
    backtrack(&calls, &n, board, columns, 0, &count);
    auto t2 = chrono::high_resolution_clock::now();
    cout << count << " number of possible placements\n";
    cout << calls << " number of function calls in total\n";
    cout << "program took: " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
}
