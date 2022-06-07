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

        // cin>>t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................

//...............................

void suraj()
{
        int a, n;
        cin >> a >> n;

        queue<pair<int, int>> q;

        q.push(make_pair(1, 0));

        int ans = -1;

        map<int, bool> flag;

        // flag[1] = false;

        // bfs from 1 to n using a.
        while (!q.empty())
        {
                pair<int, int> top = q.front();
                q.pop();
                if (flag.count(top.first) == 0)
                        flag[top.first] = true;
                else
                        continue;
                // if (flag[top.first] == true)
                //         continue;
                // flag[top.first] = true;

                int mul = top.first * a;

                string s = to_string(top.first);
                int lens = s.size();

                int var = stoi(s.substr(lens - 1, 1) + s.substr(0, lens - 1));

                // cout << "current: " << top.first << " " << top.second << endl;
                // cout << "mul: " << mul << endl;
                // cout << "var: " << var << endl;

                if (mul == n || var == n)
                {
                        ans = top.second + 1;
                        break;
                }

                // if (flag.count(mul) == 0)
                // {
                //         flag[mul] = false;
                if (to_string(mul).size() <= to_string(n).size())
                        q.push(make_pair(mul, top.second + 1));
                // }
                // if (flag.count(var) == 0)
                // {
                //         flag[var] = false;
                if ((top.first % 10 != 0) && to_string(var).size() <= to_string(n).size())
                        q.push(make_pair(var, top.second + 1));
                // }
        }

        cout << ans << endl;
}

//................................

// int

// int

// int

// int
