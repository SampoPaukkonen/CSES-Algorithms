#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exhaust(vector<ll>&a, ll i, ll sum_so_far, ll total_sum){
    if (i == 0){
        return abs((total_sum - sum_so_far) - sum_so_far);
    }
    return min(exhaust(a, i-1, sum_so_far+a.at(i-1), total_sum), exhaust(a, i-1, sum_so_far, total_sum));
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll tmp;
    ll total_sum = 0;
    for (ll i = 0; i < n; ++i){
        cin >> tmp;
        total_sum += tmp;
        a.at(i) = tmp;
    }
    cout << exhaust(a, a.size(), 0, total_sum) << "\n";
}
