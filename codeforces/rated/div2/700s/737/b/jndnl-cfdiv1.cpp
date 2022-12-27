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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        vector<int> copy = v;
        sort(copy.begin(), copy.end());
        vector<int> sameBox;
        int nBox = 1; //assuming first element is placed in the first box
        for (int i = 1; i < n; i++)
        {
                int current = v[i];
                auto it = lower_bound(copy.begin(), copy.end(), current);
                if (v[i - 1] == *(it - 1))
                {
                        // sameBox.pb(i);
                        // nBox++;
                        ;
                }
                else
                {
                        nBox++; //implies that the current element is placed in a new box
                        // sameBox.clear();
                }
        }
        if (nBox <= k)
                cout << "YES" << endl;
        else
                cout << "NO" << endl;
}

//................................
