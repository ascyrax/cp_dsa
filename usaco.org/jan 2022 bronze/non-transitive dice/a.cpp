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
bool check(vector<int> a, vector<int> b, vector<int> c)
{
        // check if a beats b & b beats c & c beats a.
        int ab = 0, bc = 0, ca = 0;
        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                        if (a[i] - b[j] != 0)
                        {
                                ab += (a[i] - b[j]) / abs(a[i] - b[j]);
                        }
                        if (b[i] - c[j] != 0)
                        {
                                bc += (b[i] - c[j]) / abs(b[i] - c[j]);
                        }
                        if (c[i] - a[j] != 0)
                        {
                                ca += (c[i] - a[j]) / abs(c[i] - a[j]);
                        }
                }
        }
        if (ab > 0 && bc > 0 && ca > 0)
        {
                return true;
        }
        else
                return false;
}
//...............................

void suraj()
{
        vector<int> a(4), b(4);

        for (int &el : a)
                cin >> el;
        for (int &el : b)
                cin >> el;

        // checking if a beats b.
        int ab = 0;
        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                        if (a[i] - b[j] != 0)
                        {
                                ab += (a[i] - b[j]) / abs(a[i] - b[j]);
                                // cout << (a[i] - b[j]) / abs(a[i] - b[j]) << " ";
                        }
                        // else
                        //         cout << 0 << " ";
                }
                // cout << endl;
        }
        // cout << ab << endl;

        vector<int> v;
        for (int i = 1; i <= 10; i++)
        {
                // for (int j = 1; j <= 4; j++)
                v.pb(i);
        }
        // for (auto el : v)
        //         cout << el << " ";
        // cout << endl;

        if (ab > 0)
        { // a beat b => b must beat c and c must beat a
                // complete search 36C4.
                // cout << "if" << endl;
                vector<int> arr;
                for (int i = 0; i < 10; i++)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                for (int k = 0; k < 10; k++)
                                {
                                        for (int l = 0; l < 10; l++)
                                        {
                                                arr.clear();
                                                arr.pb(v[i]);
                                                arr.pb(v[j]);
                                                arr.pb(v[k]);
                                                arr.pb(v[l]);
                                                if (check(a, b, arr))
                                                {
                                                        cout << "yes" << endl;
                                                        return;
                                                }
                                        }
                                }
                        }
                }
                cout << "no" << endl;
        }
        else if (ab < 0)
        {
                // b beats a => a must beat c & c must beat b
                // complete search 36C4.
                // cout << "else" << endl;
                vector<int> arr;
                for (int i = 0; i < 10; i++)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                for (int k = 0; k < 10; k++)
                                {
                                        for (int l = 0; l < 10; l++)
                                        {
                                                arr.clear();
                                                arr.pb(v[i]);
                                                arr.pb(v[j]);
                                                arr.pb(v[k]);
                                                arr.pb(v[l]);
                                                if (check(b, a, arr))
                                                {
                                                        cout << "yes" << endl;
                                                        return;
                                                }
                                        }
                                }
                        }
                }
                cout << "no" << endl;
        }
        else
        { // In a non-transitive set of three dice, each die beats one other die, and loses to another die. therefore this case not possible.
                cout << "no" << endl;
        }
}

//................................

// int

// int

// int

// int
// for (int i = 0; i < 36; i++)
// {
//         if (arr.size() == 1)
//                 arr.pop_back();
//         arr.pb(v[i]);
//         for (int j = 0; j < 36; j++)
//         {
//                 if (j == i)
//                         continue;
//                 if (arr.size() == 2)
//                         arr.pop_back();
//                 arr.pb(v[j]);
//                 for (int k = 0; k < 36; k++)
//                 {
//                         if (k == i || k == j)
//                                 continue;
//                         if (arr.size() == 3)
//                                 arr.pop_back();
//                         arr.pb(v[k]);
//                         for (int l = 0; l < 36; l++)
//                         {
//                                 if (l == i || l == j || l == k)
//                                         continue;
//                                 if (arr.size() == 4)
//                                         arr.pop_back();
//                                 arr.pb(v[l]);
//                                 if (check(a, b, arr))
//                                 {
//                                         cout << "yes" << endl;
//                                         return;
//                                 }
//                         }
//                 }
//         }
// }
// for (int i = 0; i < 36; i++)
// {
//         for (int j = 0; j < 36; j++)
//         {
//                 if (j == i)
//                         continue;
//                 for (int k = 0; k < 36; k++)
//                 {
//                         if (k == j)
//                                 continue;
//                         for (int l = 0; l < 36; l++)
//                         {
//                                 if (l == k)
//                                         continue;
//                                 arr.clear();
//                                 arr.pb(v[i]);
//                                 arr.pb(v[j]);
//                                 arr.pb(v[k]);
//                                 arr.pb(v[l]);
//                                 if (check(b, a, arr))
//                                 {
//                                         cout << "yes" << endl;
//                                         return;
//                                 }
//                         }
//                 }
//         }
// }
// cout << "no" << endl;