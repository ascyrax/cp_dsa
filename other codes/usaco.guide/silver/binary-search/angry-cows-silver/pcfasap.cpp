#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define size(x) (int)(x).size()
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
        freopen("angry.in", "r", stdin);
        freopen("angry.out", "w", stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
        for (int i = 0; i < n; i++)
                cin >> v[i];
        sort(v.begin(), v.end());
        int r = v[0] + (v[n - 1] - v[0]) / 2;
        //ans =min r
        int left = v[0], right = v[n - 1];
        int prevLeft = left, prevRight = right;
        while (left < right)
        {
                int ptr = 0;
                int kcount = 0;
                while (true)
                {
                        auto newPtr = upper_bound(v.begin(), v.end(), v[ptr] + 2 * r) - v.begin();
                        kcount++;
                        if (newPtr == n) //ie upper_bound ka result v.end() aaya
                                break;
                        ptr = newPtr;
                }
                if (kcount > k)
                {
                        prevLeft = left;
                        left = r + 1;
                        r = left + (right - left) / 2;
                }
                else
                {
                        prevRight = right;
                        right = r;
                        r = left + (right - left) / 2;
                }
                // if (prevLeft == left && prevRight == right)
                //         break;
        }
        cout << r << endl;
}

//................................
