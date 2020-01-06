#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int>s;
    int tmp;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << "\n";
}

