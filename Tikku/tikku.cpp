#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
void divide_maxima(ll *c, pair<ll, pi> *u, priority_queue<pair<ll, pi>, vector<pair<ll, pi>>> &q)
{
    pair<ll, pi> l;
    pair<ll, pi> r;
    l = make_pair(*c - u->second.first, make_pair(u->second.first, *c));
    r = make_pair(u->second.second - *c, make_pair(*c, u->second.second));
    q.pop();
    q.push(l);
    q.push(r);
    *u = q.top();
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, n;
    cin >> x >> n;
    priority_queue<pair<ll, pi>, vector<pair<ll, pi>>>q;
    multiset<ll> cuts;
    q.push(make_pair(x, make_pair(0, x)));
    ll c;
    pair<ll, pi> u = q.top();
    for (ll i = 0; i < n; ++i){
        cin >> c;
        cuts.insert(c);
        if (u.second.first < c && c < u.second.second){
            divide_maxima(&c, &u, q);
            while(!cuts.empty()){
                auto it = cuts.upper_bound(u.second.first);
                if (it == cuts.end()) break;
                c = *it;
                if (*it < u.second.second){
                    divide_maxima(&c, &u, q);
                }
                else{
                    break;
                }
            }
            u = q.top();
            cout << u.first << "\n";
        }
        else{
            cuts.insert(c);
            cout << u.first << "\n";
        }
    }
}
