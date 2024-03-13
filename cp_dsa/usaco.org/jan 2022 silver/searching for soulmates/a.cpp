// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

#define endl "\n"

#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);

#define pb push_back

double startTime;

double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

int main()
{

        // ioss

        // startTime=(double)clock();

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................

//...............................
// bfs i got this. thanks atcoder.
void suraj()
{
        ll a, b;
        cin >> a >> b;

        if (a == b)
        {
                cout << 0 << endl;
                return;
        }

        map<ll, bool> flag;
        // a-> b // int
        queue<pair<ll, ll>> q;
        // flag[a] = true;
        q.push(make_pair(a, 0));
        ll cnt = 0;
        while (!q.empty())
        {
                cnt++;
                // cout << "cnt = " << cnt << endl;
                if (cnt % 1000000 == 0)
                {
                        cout << "cnt = " << cnt << " -> time :" << gct() << endl;
                }
                pair<ll, ll> top = q.front();
                q.pop();

                if (flag.count(top.first) == 0)
                        flag[top.first] = true;
                else
                        continue;

                ll mul = top.first * 2ll;
                ll div = -1;
                if (top.first % 2 == 0)
                        div = top.first / 2ll;
                ll add = top.first + 1ll;

                if (mul == b || div == b || add == b)
                {
                        cout << top.second + 1 << endl;
                        cout << "cnt = " << cnt << endl;
                        break;
                }
                else
                {
                        // if (flag[mul] != true)
                        {
                                if (mul < b)
                                {
                                        q.push(make_pair(mul, top.second + 1));
                                        // flag[mul] = true;
                                }
                        }
                        if (div != -1) // && flag[div] != true)
                        {
                                // if (top.first > b)
                                {
                                        q.push(make_pair(div, top.second + 1));
                                        // flag[div] = true;
                                }
                        }
                        // if (flag[add] != true)
                        {
                                q.push(make_pair(add, top.second + 1));
                                // flag[add] = true;
                        }
                }
        }
}

//................................

// ll

// ll

// int

// int
