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

        ioss

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
        int n;
        cin >> n;

        map<string, string> birthYearName;
        map<string, int> birthYear;
        vector<string> years = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

        birthYearName["Bessie"] = "Ox";
        birthYear["Bessie"] = 1;

        for (int i = 0; i < n; i++)
        {
                // cout << "i = " << i << endl;
                // cout << "hi" << endl;
                // string line;
                // getline(cin, line);

                vector<string> temp(8);
                for (string &el : temp)
                        cin >> el;
                // int l = 0, r = 0;
                // for (r = 0; r < line.size(); r++)
                // {
                //         if (line[i] == ' ')
                //         {
                //                 temp.pb(line.substr(l, r - l));
                //                 l = r + 1;
                //         }
                // }

                string a = temp[0], b = temp[3], c = temp[4], d = temp[7];

                birthYearName[a] = c;

                if (b == "previous")
                {
                        int diff = 0;
                        auto r = find(years.begin(), years.end(), birthYearName[d]) - years.begin();
                        auto l = find(years.begin(), years.end(), c) - years.begin();

                        diff = r - l;
                        if (diff <= 0)
                                diff += 12;

                        birthYear[a] = birthYear[d] - diff;
                }
                else if (b == "next")
                {
                        int diff = 0;
                        auto l = find(years.begin(), years.end(), birthYearName[d]) - years.begin();
                        auto r = find(years.begin(), years.end(), c) - years.begin();

                        diff = r - l;
                        if (diff <= 0)
                                diff += 12;

                        birthYear[a] = birthYear[d] + diff;
                }
        }

        cout << abs(birthYear["Bessie"] - birthYear["Elsie"]) << endl;
}

//................................

// int

// int

// int

// int
