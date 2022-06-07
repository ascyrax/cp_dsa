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

struct segtree
{
        vector<ll> nodes;
        int size = 1;
        void init(int n)
        {

                while (size < n)
                        size *= 2;
                nodes.assign(2 * size - 1, 0ll);
        }

        // setting the nodes of the segtree

        void set(int i, int v, int x, int lx, int rx) //x is the current node  // lx and rx are the node-x's range wrt the input values of the array;
        {
                // if x i.e. the current node of the segtree is a leaf
                // if (rx - lx == 1)
                // {
                //     nodes[x] = v;
                //     return;
                // }
                if (rx - lx == 0)
                {
                        nodes[x] = v;
                        return;
                }
                int mid = (lx + rx) / 2;
                if (i <= mid)
                {
                        set(i, v, 2 * x + 1, lx, mid);
                }
                else if (i > mid)
                {
                        set(i, v, 2 * x + 2, mid + 1, rx);
                }
                nodes[x] = nodes[2 * x + 1] + nodes[2 * x + 2];
                return;
        }
        void set(int i, int v)
        {
                set(i, v, 0, 1, size);
        }

        // sum of range inside the segtree

        ll sumRange;

        void sum(int l, int r, int x, int lx, int rx)
        {
                // cout << "hi " << l << " " << r << " " << x << " " << lx << " " << rx << endl;
                if (lx == rx)
                {
                        if (lx >= l && lx <= r)
                        {
                                sumRange += nodes[x];
                        }
                        return;
                }
                if (lx >= l && rx <= r)
                {
                        sumRange += nodes[x];
                        // cout << "in " << sumRange << endl;
                        return;
                }
                else if (rx < l || lx > r)
                {
                        return;
                }
                else
                {
                        sum(l, r, 2 * x + 1, lx, (lx + rx) / 2);
                        sum(l, r, 2 * x + 2, (lx + rx) / 2 + 1, rx);
                        return;
                }
        }

        void sum(int l, int r)
        {
                sumRange = 0ll;
                sum(l, r, 0, 1, size);
        }
};

//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;

        segtree st;
        st.init(n);

        for (int i = 1; i <= n; i++)
        {
                int v;
                cin >> v;
                st.set(i, v);
        }
        //segtree initial state before the queries
        // for (int i : st.nodes)
        //     cout << i << " ";
        // cout << endl;
        while (m--)
        {
                int op;
                cin >> op;
                if (op == 1)
                {
                        int i, v;
                        cin >> i >> v;
                        st.set(i, v);
                        // print the changed segtree
                        // for (int i : st.nodes)
                        //     cout << i << " ";
                        // cout << endl;
                }
                else if (op == 2)
                {
                        int l, r;
                        cin >> l >> r;
                        // used l+1 becz we want l and r to be 1-indexed
                        st.sum(l, r);
                        cout << st.sumRange << endl;
                }
        }
}

//................................
