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
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
int n, m;
vector<int> pos, ans;
vector<string> dir;
//...............................

//...............................

void suraj()
{
        cin >> n >> m;
        pos = vector<int>(n);
        dir = vector<string>(n, "R");
        ans = vector<int>(n, -1);
        vector<pair<int, int>> hell;
        for (int i = 0; i < n; i++)
        {
                int a;
                cin >> a;
                pos[i] = a;
                hell.pb(make_pair(pos[i], i));
        }

        for (int i = 0; i < n; i++)
        {
                string s;
                cin >> s;
                if (s == "L")
                        dir[i] = s;
        }
        vector<int> posFinal(n);
        vector<string> dirFinal(n);
        sort(hell.begin(), hell.end());
        vector<int> ref(n);
        for (int i = 0; i < n; i++)
        {
                posFinal[i] = pos[hell[i].second];
                dirFinal[i] = dir[hell[i].second];
                ref[i] = hell[i].second;
        }
        pos = posFinal;
        dir = dirFinal;
        for (int el : pos)
                cout << el << " ";
        cout << endl;
        for (string el : dir)
                cout << el << " ";
        cout << endl;

        stack<pair<string, int>> even, odd;

        for (int i = 0; i < n; i++)
        {
                cout << "i = " << i << endl;
                //opposity parity indexes can never collide at an integer value
                if (pos[i] % 2 == 0) // located at even index
                {
                        if (dir[i] == "L")
                        {
                                pair<string, int> top = even.top();
                                if ((int)even.size() > 0 && top.first == "R")
                                {
                                        ans[ref[i]] = (pos[i] - pos[top.second]) / 2;
                                        ans[ref[top.second]] = ans[ref[i]];
                                        even.pop();
                                }
                                else
                                {
                                        even.push(make_pair("L", i));
                                }
                        }
                        else if (dir[i] == "R")
                        {
                                even.push(make_pair("R", i));
                        }
                }
                else // located at odd index
                {
                        if (dir[i] == "L")
                        {
                                pair<string, int> top = odd.top();
                                if ((int)odd.size() > 0 && top.first == "R")
                                {
                                        ans[ref[i]] = (pos[i] - pos[top.second]) / 2;
                                        ans[ref[top.second]] = ans[ref[i]];
                                        odd.pop();
                                }
                                else
                                {
                                        odd.push(make_pair("L", i));
                                }
                        }
                        else if (dir[i] == "R")
                        {
                                odd.push(make_pair("R", i));
                        }
                }
                for (int i : ans)
                        cout << i << " ";
                cout << endl;
        }

        cout << even.size() << " " << odd.size() << endl;
        //for even stack

        vector<pair<string, int>> temp((int)even.size());
        cout << "hi" << endl;
        int lenTemp = (int)even.size();
        int cntL = 0, cntR = 0;
        for (int i = lenTemp - 1; i >= 0; i--)
        {
                temp[i] = even.top();
                if (temp[i].first == "L")
                        cntL++;
                else
                        cntR++;
                even.pop();
        }

        for (auto i : temp)
        {
                cout << i.first << " " << i.second << "            ";
        }
        cout << endl;
        for (int i : ans)
                cout << i << " ";
        cout << endl;
        for (int i = 1; i < lenTemp; i++)
        {
                if (temp[i].first == temp[i - 1].first && temp[i].first == "L") //LL
                {
                        int diff = pos[temp[i].second] - pos[temp[i - 1].second];
                        int distLeft = pos[temp[i - 1].second] - 0; //left waale ko first wall me itna time..aur us samay i+1 waala "diff" distance right me rahega i.e. diff index pe rahega number line ke
                        ans[ref[i - 1]] = distLeft + diff / 2;
                        ans[ref[i]] = distLeft + diff / 2;
                        i++;
                }
                else if (temp[i].first != temp[i - 1].first)
                { // ie. LLLLRRRR me LR waala case
                        if (cntR % 2 == 0)
                                ans[ref[temp[i - 1].second]] = -1;
                        else
                        {
                                int distLeft = pos[temp[i - 1].second] - 0;
                                int distRight = m - pos[temp[i].second];

                                ans[ref[temp[i].second]] = distLeft + distRight + m;
                                ans[ref[temp[i - 1].second]] = distLeft + distRight + m;
                                i++;
                        }
                }
                else //RR
                {
                        int diff = pos[temp[i].second] - pos[temp[i - 1].second];
                        int distRight = (m - pos[temp[i].second]);
                        ans[ref[temp[i].second]] = distRight + diff / 2;
                        ans[ref[temp[i - 1].second]] = distRight + diff / 2;
                }
        }
        for (int i : ans)
                cout << i << " ";
        cout << endl;

        //for odd stack
        vector<pair<string, int>> temp2((int)odd.size());
        int lenTemp2 = (int)odd.size();
        // int cntL = 0, cntR = 0;
        cntL = 0, cntR = 0;
        for (int i = lenTemp2 - 1; i >= 0; i--)
        {
                temp2[i] = odd.top();
                if (temp2[i].first == "L")
                        cntL++;
                else
                        cntR++;
                odd.pop();
        }
        for (auto i : temp2)
        {
                cout << i.first << " " << i.second << "            ";
        }
        cout << endl;
        for (int i = 1; i < lenTemp2; i++)
        {
                if (temp2[i].first == temp2[i - 1].first && temp2[i].first == "L") //LL
                {
                        int diff = pos[temp2[i].second] - pos[temp2[i - 1].second];

                        int distLeft = pos[temp2[i - 1].second] - 0; //left waale ko first wall me itna time..aur us samay i+1 waala "diff" distance right me rahega i.e. diff index pe rahega number line ke
                        ans[ref[i - 1]] = distLeft + diff / 2;
                        ans[ref[i]] = distLeft + diff / 2;
                        i++;
                        cout << diff << " " << distLeft << endl;
                }
                else if (temp2[i].first != temp2[i - 1].first)
                { // ie. LLLLRRRR me LR waala case
                        if (cntR % 2 == 0)
                                ans[ref[temp2[i - 1].second]] = -1;
                        else
                        {
                                int distLeft = pos[temp2[i - 1].second] - 0;
                                int distRight = m - pos[temp2[i].second];

                                ans[ref[temp2[i].second]] = distLeft + distRight + m;
                                ans[ref[temp2[i - 1].second]] = distLeft + distRight + m;
                                i++;
                        }
                }
                else //RR
                {
                        int diff = pos[temp2[i].second] - pos[temp2[i - 1].second];
                        int distRight = (m - pos[temp2[i].second]);
                        ans[ref[temp2[i].second]] = distRight + diff / 2;
                        ans[ref[temp2[i - 1].second]] = distRight + diff / 2;
                }
        }
        //print ans
        for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
        cout << endl;
}

//................................
