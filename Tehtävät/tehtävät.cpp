#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pi>tasks;
    ll k, d;
    for (ll i = 0; i < n; ++i){
        cin >> k >> d;
        tasks.push_back(make_pair(k, d));
    }
    sort(tasks.begin(), tasks.end());
    ll time = 0;
    ll value = 0;
    for (ll i = 0; i < n; ++i){
        time += tasks.at(i).first;
        value += tasks.at(i).second - time;
    }
    cout << value << "\n";
}
