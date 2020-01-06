#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void exhaust(ll *nums, map<ll, ll>&cache, ll idx, ll current_sum, ll *target_sum, ll *number_of_items)
{
    if (idx == *number_of_items/2){
        ++cache[current_sum];
    }
    else{
        exhaust(nums, cache, idx+1, current_sum, target_sum, number_of_items);
        if (current_sum + nums[idx] <= *target_sum){
            exhaust(nums, cache, idx+1, current_sum + nums[idx], target_sum, number_of_items);
        }
    }
}

ll answer(map<ll, ll>&cache, ll *nums, ll idx, ll target_sum, ll *number_of_items)
{
    if (idx == *number_of_items){
        return cache.count(target_sum) ? cache[target_sum] : 0;
    }
    ll ans = answer(cache, nums, idx+1, target_sum, number_of_items);
    if (target_sum - nums[idx] >= 0){
        ans += answer(cache, nums, idx+1, target_sum - nums[idx], number_of_items);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    ll nums[40];
    for (ll i = 0; i < n; ++i){
        cin >> nums[i];
    }
    map<ll, ll>cache;
    exhaust(nums, cache, 0, 0, &x, &n);
    cout << answer(cache, nums, n/2, x, &n) << "\n";
}
