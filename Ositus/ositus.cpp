#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_possible(vector<ll>&numbers, ll k, ll target_sum)
{
    ll sum = 0;
    ll count = 1;
    ll num;
    for (ll i = 0; i < (ll) numbers.size(); ++i){
        num = numbers.at(i);
        if (num > target_sum){
            return false;
        }
        sum += num;
        if (sum > target_sum){
            ++count;
            sum = num;
        }
    }
    return count <= k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll>numbers(n);
    ll tmp;
    ll low, high;
    low = 1;
    high = 0;
    for (ll i = 0; i < n; ++i){
        cin >> tmp;
        high += tmp;
        numbers.at(i) = tmp;
    }
    ll m, ans;
    while(low <= high){
        m = (low + high) / 2;
        if (is_possible(numbers, k, m)){
            ans = m;
            high = m - 1;
        }
        else{
            low = m + 1;
        }
    }
    cout << ans << "\n";
}
