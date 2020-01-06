#include <bits/stdc++.h>
using namespace std;
vector<string>board(8);
vector<int>columns(8);
bool is_legal(int x, int y){
    if (board.at(x).at(y) == '.' && columns.at(y) == 0){
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < 8; ++j){
                if (board.at(i).at(j) == 'q' && abs(x-i) == abs(y-j)){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
void backtrack(int x, int *count){
    if (x == 8){
        *count += 1;
        return;
    }
    for (int y = 0; y < 8; ++y){
        if (is_legal(x, y)){
            columns.at(y) = 1;
            board.at(x).at(y) = 'q';
            backtrack(x+1, count);
            columns.at(y) = 0;
            board.at(x).at(y) = '.';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(string &x: board){
        cin >> x;
    }
    int count = 0;
    backtrack(0, &count);
    cout << count << "\n";
}
