#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    multiset <ll> kids;
    ll tmp;
    for (ll i = 0; i < n; ++i){
        cin >> tmp;
        kids.insert(tmp);
    }
    multiset<ll>::iterator a;
    ll carts = 0;
    while(!kids.empty()){
        a = kids.end();
        --a;
        tmp = x - *a;
        kids.erase(a);
        if(tmp != 0 && !kids.empty()){
            a = kids.lower_bound(tmp);
            if (a == kids.end()){
                --a;
            }
            while(a != kids.end() && tmp < *a){
                --a;
            }
            if (a != kids.end()){
                kids.erase(a);
            }
        }
        ++carts;
    }
    cout << carts << "\n";
}
