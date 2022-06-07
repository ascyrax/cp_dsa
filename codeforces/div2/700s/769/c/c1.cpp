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

void suraj()
{
        int a, b;
        cin >> a >> b;

        queue<pair<int, int>> q;

        q.push(make_pair(a, 0));

        map<int, bool> visited;

        while (!q.empty())
        {
                auto top = q.front();
                q.pop();
                if (visited.count(top.first) == 1)
                        continue;
                else
                        visited[top.first] = true;
                if (top.first == b)
                {
                        cout << top.second << endl;
                        break;
                }

                int up = top.first + 1;
                int down = top.first - 1;
                int repl = top.first | b;

                if (top.first < b)
                        q.push(make_pair(up, top.second + 1));
                q.push(make_pair(down, top.second + 1));
                if (top.first < b)
                        q.push(make_pair(repl, top.second + 1));
        }
}

//................................

// int

// int

// int

// int
