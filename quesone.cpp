#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;

ll Solve(ll YonduKey, ll LockKey, vector<int> Keys)
{
    ll mod = 1e5;
    sort(Keys.begin(), Keys.end());

    ll res{0};
    ll temp = YonduKey;
    for (ll i = Keys.size() - 1; i >= 0; i--)
    {

        temp = temp * Keys[i];

        if (temp == LockKey)
        {
            res++;
            return res;
        }
        else if (temp < LockKey)
        {

            if (LockKey % temp == 0)
            {
                res++;
            }
            else
            {
                temp /= Keys[i];
            }
        }
        else
        {
            temp /= Keys[i];
        }
    }
    return res == 0 ? -1 : res;
}
int main()
{

    ll YonduKey;
    cin >> YonduKey;

    ll LockKey;

    cin >> LockKey;

    ll N;

    cin >> N;
    vector<int> Keys(N);
    for (ll i_Keys = 0; i_Keys < N; i_Keys++)
    {
        cin >> Keys[i_Keys];
    }

    ll out_;

    out_ = Solve(YonduKey, LockKey, Keys);
    cout << out_;
}