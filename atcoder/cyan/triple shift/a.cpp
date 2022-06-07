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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
                cin >> i;
        for (int &i : b)
                cin >> i;

        vector<int> aa, bb;
        aa = a;
        bb = b;
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());

        if (aa != bb)
        {
                cout << "No" << endl;
                return;
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
                // cout << "i = " << i << endl;
                if (a[i] == b[i])
                        continue;
                int locn = -1;
                for (int j = i; j < n; j++)
                {
                        if (a[j] == b[i])
                        {
                                locn = j;
                                break;
                        }
                }
                int diff = locn - i;
                if (diff % 2 == 0)
                {
                        flag = 1;
                        // doing the given operation optimally some on of times will bring a[locn] to a[i] .
                        a.erase(a.begin() + locn);
                        a.insert(a.begin() + i, b[i]);
                }
                else
                {
                        if (i + 2 < n)
                        {
                                flag = 1;
                                // cout << "a" << endl;
                                // for (auto el : a)
                                //         cout << el << " ";
                                // cout << endl;
                                a.erase(a.begin() + locn);
                                // for (auto el : a)
                                //         cout << el << " ";
                                // cout << endl;
                                a.insert(a.begin() + i, b[i]);
                                // for (auto el : a)
                                //         cout << el << " ";
                                // cout << endl;
                                int temp = *(a.begin() + i + 1);
                                a.erase(a.begin() + i + 1);
                                // for (auto el : a)
                                //         cout << el << " ";
                                // cout << endl;
                                a.insert(a.begin() + i + 2, temp);
                                // for (auto el : a)
                                //         cout << el << " ";
                                // cout << endl;
                        }
                        else
                        {
                                // cout << "No" << endl;
                                // return;
                                flag = -1;
                        }
                }
                // for (auto el : a)
                //         cout << el << " ";
                // cout << endl;
        }
        if (flag == 1)
                cout << "Yes" << endl;
        else
                cout << "No" << endl;
}

//................................

// int

// int

// int

// int
