#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;
int x1, ya, x2, y2;
int x3, y3, x4, y4;
int x5, y5, x6, y6;
//...............................
bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
        if (x1 >= x3 && x1 <= x4 && x2 >= x3 && x2 <= x4 && y1 >= y3 && y1 <= y4 && y2 >= y3 && y2 <= y4)
        {
                return true;
        }
        else
                return false;
}

bool checkForTwo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
        bool ans = check(x1, y1, x2, y1, x3, y3, x4, y4);
        ans = ans || check(x2, y1, x2, y2, x3, y3, x4, y4);
        ans = ans || check(x2, y2, x1, y2, x3, y3, x4, y4);
        ans = ans || check(x1, y2, x1, y1, x3, y3, x4, y4);
        return ans;
}
void suraj()
{

        cin >> x1 >> ya >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        cin >> x5 >> y5 >> x6 >> y6;

        ll areaWhite = ll(y2 - ya) * ll(x2 - x1);
        ll black1 = 0, black2 = 0; //intersection waala area
        black1 = ll(min(y4, y2) - max(y3, ya)) * ll(min(x4, x2) - max(x3, x1));
        black2 = ll(min(y6, y2) - max(y5, ya)) * ll(min(x6, x2) - max(x5, x1));
        int flag = 0;
        //Yes
        //4 then not visible
        if (x4 >= x2 && x3 <= x1 && y4 >= y2 && y3 <= ya)
        {
                cout << "NO" << endl;
        }
        //2 then check for box2
        //black box1 covers two vertices of white box is = two
        //adjacent vertices of white box inside the black box 1

        else if (checkForTwo(x1, ya, x2, y2, x3, y3, x4, y4))
        {
                //box2 covers all 4=> no
                if (x6 >= x2 && x5 <= x1 && y6 >= y2 && y5 <= ya)
                        cout << "NO" << endl;
                //box 2 cover two => check further
                else if (checkForTwo(x1, ya, x2, y2, x5, y5, x6, y6))
                {
                        // cout << "a" << endl;
                        //check further
                        if (check(x1, ya, x2, ya, x3, y3, x4, y4))
                        {
                                // cout << "b" << endl;
                                if (check(x2, y2, x1, y2, x5, y5, x6, y6))
                                {
                                        if (black1 + black2 >= areaWhite)
                                        {
                                                cout << "NO" << endl;
                                        }
                                        else
                                                cout << "YES" << endl;
                                }
                                else
                                        cout << "YES" << endl;
                        }
                        else if (check(x2, ya, x2, y2, x3, y3, x4, y4))
                        {
                                // cout << "c" << endl;
                                if (check(x1, y2, x1, ya, x5, y5, x6, y6))
                                {
                                        if (black1 + black2 >= areaWhite)
                                        {
                                                cout << "NO" << endl;
                                        }
                                        else
                                                cout << "YES" << endl;
                                }
                                else
                                        cout << "YES" << endl;
                        }
                        else if (check(x2, y2, x1, y2, x3, y3, x4, y4))
                        {
                                // cout << "d" << endl;
                                if (check(x1, ya, x2, ya, x5, y5, x6, y6))
                                {
                                        if (black1 + black2 >= areaWhite)
                                        {
                                                cout << "NO" << endl;
                                        }
                                        else
                                                cout << "YES" << endl;
                                }
                                else
                                        cout << "YES" << endl;
                        }
                        else if (check(x1, y2, x1, ya, x3, y3, x4, y4))
                        {
                                // cout << "e" << endl;
                                // cout << black1 << " " << black2 << " " << areaWhite << endl;
                                if (check(x2, ya, x2, y2, x5, y5, x6, y6))
                                {
                                        if (black1 + black2 >= areaWhite)
                                        {
                                                cout << "NO" << endl;
                                        }
                                        else
                                                cout << "YES" << endl;
                                }
                                else
                                        cout << "YES" << endl;
                        }
                }
                //else =>yes visible
                else
                        cout << "YES" << endl;
        }
        //0 then box2 must be covering all 4
        else
        {
                if (x6 >= x2 && x5 <= x1 && y6 >= y2 && y5 <= ya)
                {
                        cout << "NO" << endl;
                }
                else
                        cout << "YES" << endl;
        }
}

//................................
