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

        ioss

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
        for (int &i : v)
                cin >> i;

        string s;
        cin >> s;

        vector<int> a = v;
        sort(a.begin(), a.end());

        if (a == v)
        {
                cout << 0 << endl;
                return;
        }
        int left = -1, right = -1;
        for (int i = 0; i < n; i++)
        {
                if (a[i] != v[i])
                {
                        left = i;
                        break;
                }
        }

        for (int j = n - 1; j >= left; j--)
        {
                if (a[j] != v[j])
                {
                        right = j;
                        break;
                }
        }
        // cout << "left = " << left << " , right = " << right << endl;

        int sleft = 0, nleft = 0, sright = 0, nright = 0;
        for (int i = 0; i <= left; i++)
        {
                if (s[i] == 'N')
                        nleft++;
                else
                        sleft++;
        }

        for (int i = right; i < n; i++)
        {
                if (s[i] == 'N')
                        nright++;
                else
                        sright++;
        }

        if ((nleft > 0 && sright > 0) || (sleft > 0 && nright > 0))
        {
                cout << 1 << endl;
                return;
        }
        else
        {
                // cout << "else " << endl;
                int cntn = 0, cnts = 0;
                for (int i = left; i <= right; i++)
                {
                        if (s[i] == 'N')
                                cntn++;
                        else
                                cnts++;
                }

                int len = (right) - (left) + 1;
                // cout << "len = " << len << endl;
                // cout << "cntn = " << cntn << " , cnts = " << cnts << endl;
                if (cntn == len || cnts == len)
                        cout << -1 << endl;
                else
                        cout << 2 << endl;
        }
}

//................................

// int

// int

// int

// int
