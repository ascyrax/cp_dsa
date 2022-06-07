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

        vector<int> aa = a;
        vector<int> bb = b;

        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());

        if (aa != bb)
        {
                cout << "No" << endl;
                return;
        }

        for (int i = 0; i <= n - 3; i++)
        {
                cout << " i = " << i << endl;
                if (a[i] == b[i])
                        continue;
                else
                {
                        int j;
                        for (j = i + 1; j <= n; j++)
                        {
                                if (a[j] == b[i])
                                        break;
                        }

                        int len = j - i + 1;
                        // if (j <= n - 2)
                        // {
                        //         int temp = a[i];
                        //         a[i] = a[j]; // ie a[i]=b[i]
                        //         a[j] = a[n - 1];
                        //         a[n - 1] = temp;
                        // }
                        // else
                        // {
                        //         // j=n-1
                        //         int temp = a[i];
                        //         a[i] = a[n - 2];
                        //         a[n - 2] = a[n - 1];
                        //         a[n - 1] = temp;
                        // }
                        cout << "len = " << len << endl;
                        while (len > 3)
                                len -= 2;
                        if (len == 3)
                        {
                                a.insert(a.begin() + i, a[j]);
                                a.erase(a.begin() + j + 1);
                                for (auto el : a)
                                        cout << el << " ";
                                cout << endl;
                        }
                        else if (len == 2)
                        {
                                int val1 = a[i], val2 = a[j], val3 = a[i + 1];
                                if (j == i + 1)
                                        val3 = a[i + 2];
                                // cout << val1 << val2 << val3 << endl;
                                a.erase(a.begin() + j);
                                for (auto el : a)
                                        cout << el << " ";
                                cout << endl;

                                a.erase(a.begin() + i);
                                a.erase(a.begin() + i);
                                for (auto el : a)
                                        cout << el << " ";
                                cout << endl;

                                a.insert(a.begin() + i, {val2, val3, val1});
                                for (auto el : a)
                                        cout << el << " ";
                                cout << endl;
                        }
                }
        }
        // cout << "hi" << endl;

        // if (a[n - 3] == b[n - 3])
        // {
        if (a[n - 2] == b[n - 2])
                cout << "Yes" << endl;
        else
                cout << "No" << endl;
        // }
        // else
        // {
        //         int flag = 0;
        //         // int j = n - 2;
        //         if (a[n - 2] == b[n - 3])
        //         {
        //                 if (a[n - 1] == b[n - 2])
        //                         flag = 1;
        //                 else
        //                         flag = -1;
        //         }
        //         if (a[n - 1] == b[n - 3])
        //         {
        //                 if (a[n - 3] == b[n - 2])
        //                         flag = 1;
        //                 else
        //                         flag = -1;
        //         }

        //         if (flag == -1)
        //                 cout << "No" << endl;
        //         else
        //                 cout << "Yes" << endl;
        // }
}

//................................

// int

// int

// int

// int
