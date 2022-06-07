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
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        map<int, int> m;
        int sum = 0;
        int ptr = -1;
        int len_left = 0;
        for (int i = 0; i < k; i++)
        {
                len_left++;
                ptr = sum % n;
                if (m.count(ptr))
                        break;
                m[ptr]++;
                sum += v[ptr];
        }

        int cnt = 0;
        int sum_temp = sum, ptr_temp = ptr;
        int loop_sum = 0;
        while (1)
        {
                cnt++;
                ptr_temp = sum_temp % n;
                if (ptr_temp == ptr)
                {
                        break;
                }
                loop_sum += v[ptr_temp];
                sum_temp += v[ptr_temp];
        }

        int left = 0, left_sum = 0, ptr_left = 0;
        while (1)
        {
                if (left)
        }
}

//................................

// int

// int

// int

// int
