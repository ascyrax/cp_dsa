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
int n;
vector<char> s;
int ptr = 0;

//...............................

void suraj()
{
        cin >> n;
        s = vector<char>(n);
        for (int i = 0; i < n; i++)
                cin >> s[i];
        ptr = 0;

        int c = 0, r = n;
        while (ptr < n)
        {

                if (s[ptr] == '(')
                {
                        if (ptr + 2 <= n - 1)
                        {
                                c++;
                                ptr += 2;
                        }
                        else if (ptr + 1 <= n - 1)
                        {
                                c++;
                                ptr += 2;
                        }
                        else if (ptr + 1 > n - 1)
                        {
                                break;
                        }
                        continue;
                }
                else if (s[ptr] == ')')
                {
                        // ++ptr;
                        bool found = false;
                        for (int j = ptr + 1; j < n; j++)
                        {
                                if (s[j] == ')')
                                {
                                        ptr = j + 1;
                                        c++;
                                        found = true;
                                        break;
                                }
                        }
                        if (!found)
                        {
                                break;
                        }
                }
        }
        cout << c << " " << s.size() - 1 - ptr + 1 << endl;
}

//................................

// int

// int

// int

// int
