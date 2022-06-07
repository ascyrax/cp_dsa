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
void prints(vector<int> &a)
{
        for (auto el : a)
                cout << el << " ";
        cout << endl;
}
//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int &i : a)
        {
                cin >> i;
                cnt[i]++;
        }
        for (auto el : cnt)
        {
                if (el.second & 1)
                {
                        cout << -1 << endl;
                        return;
                }
        }

        vector<int> copy = a;
        sort(copy.begin(), copy.end());

        vector<pair<int, int>> v1;

        int carry = 0;

        vector<int> lens;

        for (int i = n - 1; i >= 0; i--)
        {
                int val = copy[i];
                // cout << "val : " << val << endl;
                for (int j = i; j >= 0; j--)
                {
                        if (a[j] == val)
                        {
                                if (i == j)
                                        break;
                                // cout << "i = " << i << " , j = " << j << endl;
                                // rev 0toj and then rev 0toi
                                // for reversing 0toj
                                int temp = j;
                                for (int k = 0; k <= j; k++)
                                        v1.pb(make_pair(carry + temp++, a[k]));
                                carry += 2 * (j - 0 + 1);
                                reverse(a.begin(), a.begin() + j + 1);
                                lens.pb(2 * (j - 0 + 1));
                                // prints(a);
                                // for reversing now from 0toi.
                                temp = i;
                                for (int k = 0; k <= i; k++)
                                        v1.pb(make_pair(carry + temp++, a[k]));
                                carry += 2 * (i - 0 + 1);
                                reverse(a.begin(), a.begin() + i + 1);
                                lens.pb(2 * (i - 0 + 1));
                                // prints(a);
                                break;
                        }
                }
        }
        cout << v1.size() << endl;
        for (auto el : v1)
                cout << el.first + 1 << " " << el.second << endl;

        // cout << (carry + n) / 2 << endl;
        // for (int i = 1; i <= (carry + n) / 2; i++)
        //         cout << 2 << " ";
        // cout << endl;
        for (int i = 1; i <= n / 2; i++)
                lens.pb(2);
        cout << lens.size() << endl;
        for (auto el : lens)
                cout << el << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
