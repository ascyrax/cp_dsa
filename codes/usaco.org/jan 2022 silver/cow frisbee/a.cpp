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
        ll n;
        cin >> n;
        vector<ll> heights(n);

        map<ll, ll> index; // value and its corresponding index.
        for (ll i = 0; i < n; i++)
        {
                cin >> heights[i];
                index[heights[i]] = i;
        }

        map<ll, ll> right; // contains the value of first greater no to the right.

        stack<ll> r;
        r.push(heights[0]);
        for (ll i = 1; i < n; i++)
        {
                ll h = heights[i];
                while (true)
                {
                        ll top = r.top();
                        if (h > top)
                        {
                                right[top] = h;
                                r.pop();
                        }
                        else
                                break;
                        if (r.empty())
                                break;
                }
                r.push(h);
        }
        while (!r.empty())
        {
                ll top = r.top();
                right[top] = -1;
                r.pop();
        }

        map<ll, ll> left;
        stack<ll> l;
        l.push(heights[n - 1]);
        for (ll i = n - 2; i >= 0; i--)
        {
                ll h = heights[i];
                while (true)
                {
                        ll top = l.top();
                        if (h > top)
                        {
                                left[top] = h;
                                l.pop();
                        }
                        else
                                break;
                        if (l.empty())
                                break;
                }
                l.push(h);
        }
        while (!l.empty())
        {
                ll top = l.top();
                left[top] = -1;
                l.pop();
        }

        ll ans = 0;
        for (auto el : right)
        {
                if (el.second != -1)
                        ans += index[el.second] - index[el.first] + 1;
        }
        for (auto el : left)
        {
                if (el.second != -1)
                        ans += index[el.first] - index[el.second] + 1;
        }
        cout << ans << endl;
}

//................................

// ll

// ll

// ll

// int
