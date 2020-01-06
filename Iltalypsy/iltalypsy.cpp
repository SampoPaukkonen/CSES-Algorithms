#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll c;
    priority_queue<ll, vector<ll>, greater<ll>> byre;
    ll smallest = 1;
    for (ll i = 0; i < m; ++i){
       cin >> c;
       byre.push(c);
       while(!byre.empty() && smallest == byre.top()){
           ++smallest;
           byre.pop();
       }
       cout << smallest << " ";
    }
}
