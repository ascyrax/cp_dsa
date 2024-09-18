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
        int n;
        cin >> n;
        string s;
        cin >> s;

        map<int, bool> m; // m[i]=true => index i has to be a mex of atleast one continuous subsegment
        for (int i = 0; i < n + 1; i++)
        {
                if (s[i] == '1')
                        m[i] = true;
                else
                        m[i] = false;
        }

        if (m[n] == false || m[0] == false || m[1] == false)
        {
                cout << "NO" << endl;
                return;
        }
        vector<int> dg(n, -1); // directed graph with vertices 0 to n-1.// this is a tree actually
        dg[0] = 1;
        int end = 1, preend = 0;

        // int node = 0;
        // while (node != -1)
        // {
        //         cout << node << " ";
        //         node = dg[node];
        // }
        // cout << endl;

        for (int i = 2; i <= n - 1; i++)
        {
                if (m[i] == false)
                {
                        dg[preend] = i;
                        preend = i;
                        dg[i] = end;
                }
                else if (m[i] == true)
                {
                        dg[end] = i;
                        preend = end;
                        end = i;
                }
                // int node = 0;
                // while (node != -1)
                // {
                //         cout << node << " ";
                //         node = dg[node];
                // }
                // cout << endl;
        }
        cout << "YES" << endl;
        int node = 0;
        while (node != -1)
        {
                cout << node << " ";
                node = dg[node];
        }
        cout << endl;
}

//................................

// int

// int

// int

// int
