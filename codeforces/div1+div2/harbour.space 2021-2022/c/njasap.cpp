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
        string s;
        cin >> s;
        int n = 10;
        int nA = 10; //min no of matches played if a wins in the end
        int nB = 10; //min no of matches played if b wins in the end
        int wA = 0, wB = 0;
        int mALeft = 5, mBLeft = 5;
        int ans = 10;
        for (int i = 0; i < n; i++)
        {
                if (i % 2 == 0)
                {
                        if (s[i] == '1')
                        {
                                wA++;
                        }
                        else if (s[i] == '0')
                        {
                                wA;
                        }
                        else
                        {
                                wA++;
                        }
                        mALeft--;
                }
                else if (i % 2 == 1)
                {
                        if (s[i] == '1')
                        {
                                wB++;
                        }
                        else if (s[i] == '0')
                        {
                                wB;
                        }
                        else
                        {
                                wB;
                        }
                        mBLeft--;
                }
                if (mBLeft + wB < wA)
                {
                        nA = i + 1;
                        break;
                }
        }
        mALeft = 5, mBLeft = 5;
        wA = 0, wB = 0;

        for (int i = 0; i < n; i++)
        {
                if (i % 2 == 0)
                {
                        if (s[i] == '1')
                        {
                                wA++;
                        }
                        else if (s[i] == '0')
                        {
                                wA;
                        }
                        else
                        {
                                wA;
                        }
                        mALeft--;
                }
                else if (i % 2 == 1)
                {
                        if (s[i] == '1')
                        {
                                wB++;
                        }
                        else if (s[i] == '0')
                        {
                                wB;
                        }
                        else
                        {
                                wB++;
                        }
                        mBLeft--;
                }
                if (mALeft + wA < wB)
                {
                        nB = i + 1;
                        break;
                }
        }
        // cout << nA << " " << nB << endl;
        cout << min(nA, nB) << endl;
}

//................................
