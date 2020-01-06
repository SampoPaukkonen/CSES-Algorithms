#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll>boards(n);
    for (ll&x: boards){
        cin >> x;
    }
    sort(boards.begin(), boards.end());
    /* ll median = (n % 2 == 0) ? (boards[n/2] + boards[(n/2)-1])/2 : boards[n/2]; */
    ll median = boards[n/2];
    ll x = 0;
    for (ll i = 0; i < n; ++i){
        x += abs(boards[i]-median);
    }
    cout << x << "\n";
}
