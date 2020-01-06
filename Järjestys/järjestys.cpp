#include <bits/stdc++.h>


using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector <int> numbers;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        numbers.push_back(tmp);
    }
    int expected_item = n;
    for (int i = n - 1; i >= 0; --i){
        if (numbers[i] == expected_item){
            --expected_item;
        }
    }
    cout << expected_item << "\n";
}
