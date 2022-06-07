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
bool is_pal(string s)
{
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
                if (s[l] == s[r])
                {
                        l++;
                        r--;
                }
                else
                {
                        return false;
                }
        }
        return true;
}
//...............................

void suraj()
{
        string s;
        cin >> s;
        int cnta = 0;
        for (int i = 0; i < s.size(); i++)
        {
                if (s[i] == 'a')
                        cnta++;
        }
        if (cnta == s.size())
        {
                cout << "Yes" << endl;
                return;
        }

        int left = 0; // cnt of a in the left.
        for (int i = 0; i < s.size(); i++)
        {
                if (s[i] != 'a')
                {
                        left = i;
                        break;
                }
        }
        int right = -1; // cnt of a in the right
        for (int i = s.size() - 1; i >= 0; i--)
        {
                if (s[i] != 'a')
                {
                        right = i + 1;
                        break;
                }
        }

        right = s.size() - right;
        if (left > right)
        {
                cout << "No" << endl;
                return;
        }
        s = s.substr(left, s.size() - right - left);

        if (is_pal(s))
                cout << "Yes" << endl;
        else
                cout << "No" << endl;
}

//................................

// int

// int

// int

// int
