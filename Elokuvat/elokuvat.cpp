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
    priority_queue<pi, vector<pi>, greater<pi>> q;
    ll s, e;
    for (ll i = 0; i < n; ++i){
        cin >> s >> e;
        q.push(make_pair(e, s));
    }
    ll count = 1;
    pi current = q.top();
    q.pop();
    while(true){
        while(!q.empty() && q.top().second < current.first){
            q.pop();
        }
        if (q.empty()){
            break;
        }
        ++count;
        current = q.top();
        q.pop();
    }
    cout << count << "\n";
}
