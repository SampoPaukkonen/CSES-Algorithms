#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    set<ll>cows;
    string s;
    ll num;
    for (ll i = 0; i < m; ++i){
        cin >> s >> num;
        if (s[0] == '+'){
            cows.insert(num);
        }
        else if (s[0] == '-'){
            cows.erase(num);
        }
        else {
            if (cows.find(num) == cows.end()){
                cout << "QAQ" << "\n";
            }
            else{
                cout << "10-4" << "\n";
            }
        }
    }
}
