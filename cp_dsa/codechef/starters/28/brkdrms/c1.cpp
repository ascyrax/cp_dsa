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
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if (k == 1)
        {
                cout << s << endl;
                return;
        }
        string s2 = s;
        sort(s2.begin(), s2.end());

        int loop = 0;
        int left = 0;
        vector<vector<char>> ans;
        vector<char> temp;
        vector<bool> flag(n, false);
        for (auto el : s2)
                cout << el;
        cout << endl;
        int last_left = 0;
        for (int i = 0; i < n; i++)
        {
                char c = s2[i];
                cout << "c = " << c << endl;
                for (left = last_left; left < n; left++)
                {
                        if (s[left] == c)
                        {
                                cout << "left = " << left << endl;
                                temp.pb(s[left]);
                                flag[left] = true;
                                left++;
                                last_left = left;
                                break;
                        }
                }
                if (left == n)
                {
                        loop++;
                        left = 0;
                        ans.pb(temp);
                        cout << "temp: " << endl;
                        for (auto el : temp)
                                cout << el << " ";
                        cout << endl;
                        temp.clear();
                }
                if (loop == k - 1)
                        break;
        }
        for (auto vec : ans)
        {
                for (auto c : vec)
                        cout << c;
        }
        for (int i = 0; i < n; i++)
        {
                if (flag[i] == false)
                        cout << s[i];
        }
        cout << endl;
}

//................................

// int

// int

// int

// int
