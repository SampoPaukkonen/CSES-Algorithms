#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    multiset<ll>prices;
    ll tmp;
    for (ll i = 0; i < n; ++i){
        cin >> tmp;
        prices.insert(tmp);
    }
    for (ll i = 0; i < m; ++i){
        cin >> tmp;
        auto a = prices.upper_bound(tmp);
        --a;
        if (a == prices.end()){
            cout << "QAQ\n";
        }
        else{
            cout << *a << "\n";
            prices.erase(a);
        }
    }
}
