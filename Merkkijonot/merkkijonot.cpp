#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int uniques = 0;
    string answer = "";
    do{
        answer = answer + s + "\n";
        ++uniques;
    }while(next_permutation(s.begin(), s.end()));
    cout << uniques << "\n";
    cout << answer;
}
