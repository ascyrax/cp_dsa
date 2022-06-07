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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, q;
//...............................
struct segTree
{
        int len = 1;
        vector<ll> v;
        void init(int n)
        {
                while (len < n)
                {
                        len = len * 2;
                }
                v = vector<ll>(2 * len - 1, 0);
        }

        //set index=>value
        void set(int index, int val)
        {
                set(index, val, 0, 0, len - 1);
        }
        void set(int index, int val, int node, int lx, int rx)
        {
                int mid = lx + (rx - lx) / 2;
                if (rx - lx == 0)
                { //lx is equal to rx which is equal to node

                        // if (lx == index)
                        // {
                        // cout << lx << " " << rx << endl;
                        v[node] = val; //since lx=rx=node currently
                        return;
                        // }
                }
                if (index <= mid)
                {
                        set(index, val, node * 2 + 1, lx, mid);
                        v[node] = min(v[node * 2 + 1], v[node * 2 + 2]);
                        return;
                }
                else if (index > mid)
                {
                        set(index, val, 2 * node + 2, mid + 1, rx);
                        v[node] = min(v[node * 2 + 1], v[node * 2 + 2]);
                        return;
                }
        }
        //sum of l to r
        ll minVal = 1e9;
        ll rangeMin(int l, int r)
        {
                minVal = 1e9;
                rangeMin(l, r, 0, 0, len - 1);
                return minVal;
        }
        void rangeMin(int l, int r, int node, int lx, int rx)
        {
                // cout << "node = " << node << " " << lx << " " << rx << endl;
                int mid = lx + (rx - lx) / 2;
                if (rx - lx == 0)
                {
                        // cout << "if1" << endl;
                        if (rx >= l && rx <= r)
                                minVal = min(minVal, v[node]);
                        return;
                }
                if (lx >= l && rx <= r)
                {
                        // cout << "if2" << endl;
                        minVal = min(minVal, v[node]);
                        return;
                }
                else if (rx < l || lx > r)
                {
                        // cout << "else if" << endl;
                        return;
                }
                else
                {
                        // cout << "else " << endl;
                        rangeMin(l, r, node * 2 + 1, lx, mid);
                        rangeMin(l, r, node * 2 + 2, mid + 1, rx);
                        return;
                }
        }
};

//...............................

void suraj()
{
        cin >> n >> q;

        segTree st;
        st.init(n);

        for (int i = 0; i < n; i++)
        {
                int el;
                cin >> el;
                st.set(i, el);
        }

        for (int i = 0; i < q; i++)
        {
                int a;
                cin >> a;
                if (a == 1)
                {
                        int index, value;
                        cin >> index >> value;
                        st.set(index, value);
                }
                else if (a == 2)
                {
                        int l, r;
                        cin >> l >> r;
                        cout << st.rangeMin(l, r - 1) << endl;
                }
        }
}

//................................
