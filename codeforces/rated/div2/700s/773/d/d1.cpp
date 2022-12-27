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
        vector<int> v(n);
        map<int, int> m;
        for (int &i : v)
        {
                cin >> i;
                m[i]++;
        }
        for (auto el : m)
                if (el.second & 1)
                {
                        cout << -1 << endl;
                        return;
                }

        vector<int> sorted = v;
        sort(sorted.begin(), sorted.end());

        vector<pair<int, int>> operations;

        int lensum = 0;

        for (int i = 0; i < sorted.size(); i++)
        {
                // cout << "before" << endl;
                // for (auto el : v)
                //         cout << el << " ";
                // cout << endl;

                // cout << "sorted[i] = " << sorted[i] << endl;

                int j = i;
                for (j = i; j < n; j++)
                {
                        if (v[j] == sorted[i])
                                break;
                }

                // cout << "j = " << j << endl;
                // cout << "v[j]= " << v[j] << endl;

                if (j == i)
                        continue;

                int len = j - i + 1;
                int temp = j;
                for (int k = i; k <= j; k++)
                {
                        operations.pb(make_pair(lensum + temp++, v[k]));
                }
                reverse(v.begin() + i, v.begin() + j + 1);
                lensum += 2 * len;

                // cout << "after" << endl;
                // for (auto el : v)
                //         cout << el << " ";
                // cout << endl;
        }

        cout << operations.size() << endl;
        for (auto el : operations)
                cout << el.first + 1 << " " << el.second << endl;

        // for (auto el : v)
        //         cout << el << " ";
        // cout << endl;

        cout << (n + lensum) / 2 << endl;
        for (int i = 0; i < (n + lensum) / 2; i++)
                cout << 2 << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
