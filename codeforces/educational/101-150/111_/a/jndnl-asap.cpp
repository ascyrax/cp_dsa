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
        string a;
        cin >> a;
        int s = stoi(a);
        if (s == 1)
                cout << 1 << endl;
        else if (s == 2)
        {
                cout << 2 << endl;
        }
        else if (s == 3)
                cout << 2 << endl;
        else if (s == 4)
                cout << 2 << endl;
        else
        {
                int sum = 1;
                int len = 1;
                for (int i = 3; sum + i <= s; i += 2)
                {
                        sum += i;
                        len++;
                }
                if (sum < s)
                        len++;
                cout << len << endl;
        }
}

//................................
