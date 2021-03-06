// https://codeforces.com/problemset/problem/1472/E
//  cf round 693 div3 E.Correct Placement
//  usaco.guide custom comparators
//  @author: ascyrax

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
bool custom(const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b)
{ // the value that we r searching is always the "b".
        // and the lower bound will be the location just after the b. => equality case me return false so that a (ie some other element which is equal to b)
        // moves to the right of b and its location will be returned in the end.
        // cout<<"a: ";
        // cout << a.first.first << " " << a.first.second << " " << a.second << endl;
        // cout<<"b: ";
        // cout << b.first.first << " " << b.first.second << " " << b.second << endl;

        if (a.first.first >= b.first.first)
        {
                if (a.first.second < b.first.second)
                {
                        // cout << "true" << endl;
                        return true;
                } // ie a should remain at the left of b only.
                else if (a.first.second >= b.first.second)
                {
                        // cout << "false" << endl;
                        return false;
                } // ie a should not be to the left of b becz it is a probable ans
        }
        else if (a.first.first < b.first.first)
        {
                {
                        // cout << "true" << endl;
                        return true;
                } // ie a should remain at the left of b only.
        }
}
//...............................

void suraj()
{
        int n;
        cin >> n;

        vector<pair<pair<int, int>, int>> vp, vpRev;

        for (int i = 0; i < n; i++)
        {
                int h, w;
                cin >> h >> w;
                vp.pb(make_pair(make_pair(h, w), i + 1));
                vpRev.pb(make_pair(make_pair(w, h), i + 1));
        }

        sort(vp.begin(), vp.end());
        sort(vpRev.begin(), vpRev.end());

        // cout << "vp:" << endl;
        // for (auto el : vp)
        // {
        //         cout << el.first.first << " " << el.first.second << " " << el.second << endl;
        // }

        // cout << "vpRev:" << endl;
        // for (auto el : vpRev)
        // {
        //         cout << el.first.first << " " << el.first.second << " " << el.second << endl;
        // }

        map<int, int> ans;

        for (int i = 0; i < n; i++)
        {
                auto current = vp[i];

                current.first.first++;
                current.first.second++;

                // cout << "current: " << current.first.first << " " << current.first.second << " " << current.second << endl;

                auto loc = lower_bound(vp.begin() + i + 1, vp.end(), current, custom);

                // cout << (*loc).first.first << " " << (*loc).first.second << " " << (*loc).second << endl;

                if (loc == vp.end())
                {
                        // cout << "if" << endl;
                        loc = lower_bound(vpRev.begin(), vpRev.end(), current, custom);

                        if ((*loc).second == current.second)
                        {
                                loc = lower_bound(loc + 1, vpRev.end(), current);
                                if (loc == vpRev.end())
                                        // cout << -1 << endl;
                                        ;
                                else
                                        ans[(*loc).second] = current.second;
                        }
                        else
                        {
                                ans[(*loc).second] = current.second;
                        }
                }
                else
                {
                        // cout << "else" << endl;
                        ans[(*loc).second] = current.second;
                }
        }

        // cout << "ans: " << endl;
        for (int i = 1; i <= n; i++)
                if (ans.count(i) > 0)
                        cout << ans[i] << " ";
                else
                        cout << -1 << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int

// when ioss is uncommented (-1 3 -1) is the 2nd output
// 4
// 3
// 3 4
// 5 4
// 3 3
// 3
// 1 3
// 2 2
// 3 1
// 4
// 2 2
// 3 1
// 6 3
// 5 4
// 4
// 2 2
// 2 3
// 1 1
// 4 4
// -1 1 -1
// -1 3 -1
// -1 -1 -1 2
// 3 -1 -1 2

// when ioss is commented(-1 -1 -1) is the 2nd output. wtf. this one is correct btw
// 4
// 3
// 3 4
// 5 4
// 3 3
// -1 1 -1
// 3
// 1 3
// 2 2
// 3 1
// -1 -1 -1
// 4
// 2 2
// 3 1
// 6 3
// 5 4
// -1 -1 -1 2
// 4
// 2 2
// 2 3
// 1 1
// 4 4
// 3 -1 -1 2