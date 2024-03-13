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
void compare(string &s, string &rev)
{
        int len = s.size();
        int i = 0;
        for (i = 0; i < len; i++)
        {
                if (s[i] == rev[i])
                        continue;
                else
                        break;
        }
        s = s.substr(i);
        rev = rev.substr(i);
        return;
}
//...............................

void suraj()
{
        string s;
        cin >> s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        // cout << s << " " << rev << endl
        int cnt = 0;
        while (s.size() > 0)
        {
                compare(s, rev);
                if (s.size() == 0)
                        break;
                cout << s << " " << rev << endl;
                int i = 0;
                for (i = 0; i < rev.size(); i++)
                {
                        if (s[i] == rev[0])
                                break;
                }
                string left = s.substr(0, i);
                string right = s.substr(i);
                s = right + left;
                cnt += left.size();
                cout << s << " " << rev << endl;
        }
        cout << cnt << endl;
}

//................................

// int

// int

// int

// int
