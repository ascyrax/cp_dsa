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
        int n, k;
        cin >> n >> k;

        multiset<pair<int, int>> s;

        for (int i = 0; i < n; i++)
        {
                int a, b;
                cin >> a >> b;
                s.insert(make_pair(b, a));
        }

        cout << "sorted pairs" << endl;
        multiset<pair<int, int>> copy = s;
        for (auto el : copy)
                cout << el.first << " " << el.second << endl;

        vector<pair<int, int>> v(k, make_pair(0, 0));
        int cnt = 0;
        while (s.size() > 0)
        {
                for (int i = 0; i < k; i++)
                {
                        cout << "i = " << i << endl;
                        while (1)
                        {
                                pair<int, int> top = *s.begin();
                                if (top.second < v[i].first)
                                        s.erase(s.begin());
                                else
                                        break;
                                if (s.size() == 0)
                                        break;
                        }
                        cout << "s.size()= " << s.size() << endl;
                        if (s.size() == 0)
                                break;

                        v[i] = *(s.begin());
                        cnt++;
                        s.erase(s.begin());

                        if (s.size() == 0)
                                break;

                        cout << "v" << endl;
                        for (auto el : v)
                                cout << el.first << " " << el.second << endl;
                }
                // cout << "v" << endl;
                // for (auto el : v)
                //         cout << el.first << " " << el.second << endl;
        }
        cout << cnt << endl;
}
// sorted pairs
//  69 57
//  72 35
//  78 53
//  79 77
//  87 49
//  90 80
//  94 75
//  95 46
//  95 64
//  99 22
//................................

// int

// int

// int

// int
