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
        // ioss
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        string x;
        cin >> x;
        int xLen = x.size();

        string l = "", r = "";
        int i = 0, dot = -1;
        for (i = 0; i < xLen; i++)
        {
                if (x[i] == '.')
                {
                        dot = i;
                        break;
                }
                if ((int)l.size() == 0 && x[i] == '0')
                        continue;
                l += x[i];
        }
        if (dot == -1)
                dot = xLen;
        for (i = dot + 1; i < xLen; i++)
                r += x[i];
        // ll xInt = x;
        // if (xInt >= 10)
        // {
        //         while (xInt >= 10)
        //         {
        //                 b++;
        //                 xInt /= 10;
        //                 x /= 10;
        //         }
        //         if (b != 0)
        //                 cout << x << "E" << b << endl;
        //         else
        //                 cout << x << endl;
        // }
        // else if (xInt >= 1)
        // {
        //         cout << x << endl;
        // }
        // else
        // {
        //         if (x == 0)
        //         {
        //                 cout << 0 << endl;
        //         }
        //         else
        //         {
        //                 // cout << "here" << endl;
        //                 while (x < 1)
        //                 {
        //                         b--;
        //                         x *= 10;
        //                 }
        //                 cout << x << "E" << b << endl;
        //         }
        // }
        int b = 0;
        b = (int)l.size();
        cout << l << " " << r << " " << b << endl;
        if (b == 1)
        {
                cout << l;
                if ((int)r.size() > 0)
                {
                        cout << "." << r << endl;
                }
        }
        else if (b > 0)
        {
                cout << l[0];
                int flag = 0;
                for (int i = 1; i < (int)l.size(); i++)
                {
                        if (l[i] != '0')
                        {
                                flag = 1;
                                break;
                        }
                }
                if (flag != 0)
                {
                        cout << ".";
                        for (i = 1; i < (int)l.size(); i++)
                        {
                                cout << l[i];
                        }
                        cout << r << "E" << b - 1 << endl;
                }
                else
                {
                        cout << "E" << b - 1 << endl;
                }
        }
        else
        {

                if (stoi(r) == 0)
                {
                        cout << 0 << endl;
                        return;
                }
                b = -1;
                for (i = dot + 1; i < xLen; i++)
                {
                        if (x[i] != '0')
                        {
                                break;
                        }
                        else
                                b--;
                }
                string rr = "";
                int flag = 0;
                for (int j = i + 1; j < xLen; j++)
                {
                        if (x[j] != '0')
                        {
                                flag = 1;
                                break;
                        }
                }
                cout << x[i];
                if (flag == 1)
                {
                        cout << ".";
                        for (i = i + 1; i < xLen; i++)
                        {
                                cout << x[i];
                        }
                        cout << "E" << b << endl;
                }
                else if (flag == 0)
                {
                        cout << "E" << b << endl;
                }
        }
}

//................................
