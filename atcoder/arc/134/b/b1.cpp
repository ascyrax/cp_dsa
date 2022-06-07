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
        string s;
        cin >> s;
        int lens = n;

        map<char, vector<int>> cnt;

        for (int i = 0; i < lens; i++)
        {
                cnt[s[i]].pb(i);
        }
        for (auto &el : cnt)
        {
                sort(el.second.rbegin(), el.second.rend());
        }

        int left = 0, right = n;
        for (auto el : cnt)
        {
                char c = el.first;
                vector<int> v = el.second;

                // cout << c << " : ";
                // for (auto el : v)
                //         cout
                //             << el << " ";
                // cout << endl;

                for (int i = 0; i < v.size(); i++)
                {
                        // cout << "v[i] : " << v[i] << endl;
                        // cout << "left : " << left << endl;
                        // cout << "right : " << right << endl;
                        if (v[i] >= right)
                                continue;
                        if (v[i] <= left)
                        {
                                break;
                        } // effwpnwipsusiwkzo
                        else
                        {
                                for (; left < v[i];)
                                {
                                        if (s[left] <= c)
                                        {
                                                // cout << "if" << endl;
                                                left++;
                                                // cout << "s : " << s << endl;
                                        }
                                        else if (s[left] > c)
                                        {
                                                // cout << "else" << endl;
                                                char temp = s[left];
                                                s[left] = s[v[i]];
                                                s[v[i]] = temp;
                                                left++;
                                                right = v[i];
                                                // cout << "s : " << s << endl;
                                                break;
                                        }
                                }
                        }
                }
        }
        cout << s << endl;
}

//................................

// int

// int

// int

// int
