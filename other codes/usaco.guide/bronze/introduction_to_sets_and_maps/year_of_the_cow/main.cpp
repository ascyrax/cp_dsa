/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back

double startTime;
double gct() // get_current_time
{
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

void suraj()
{ ///////////////////////
    vector<string> vs = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake",
                         "Horse", "Goat", "Monkey", "Rooster", "Dog",
                         "Pig", "Rat"};

    int n;
    cin >> n;
    cin.ignore();
    map<string, int> mdiff, mbirth;
    mbirth["Bessie"] = 0;
    mdiff["Bessie"] = 0;
    for (int i = 0; i < n; i++)
    {
        string a;
        getline(cin, a);
        stringstream ss(a);
        vector<string> words;
        string word;
        while (ss >> word)
        {
            words.pb(word);
        }
        for (int i = 0; i < vs.size(); i++)
        {
            if (vs[i] == words[4])
            {
                mbirth[words[0]] = i;
                break;
            }
        }
        int diff = abs(mbirth[words[7]] - mbirth[words[0]]);
        // cout<<"diff "<<diff<<endl;
        if (words[3] == "previous")
        {
            if (mbirth[words[0]] < mbirth[words[7]])
            {
                diff = diff;
            }
            else
            {
                diff = 12 - diff;
            }
            mdiff[words[0]] = mdiff[words[7]] - diff;
        }
        else if (words[3] == "next")
        {
            if (mbirth[words[0]] < mbirth[words[7]])
            {
                diff = 12 - diff;
            }
            else
            {
                diff = diff;
            }
            mdiff[words[0]] = mdiff[words[7]] + diff;
        } // cout<<"diff "<<diff<<endl;
        // for(auto i:mdiff)cout<<i.first<<" "<<i.second<<endl;
        // cout<<"-------------------------------------"<<endl;
    }

    // for(auto i:mbirth){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    // for(auto i:mdiff){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    cout << abs(mdiff["Elsie"]) << endl;

} ////////////////////////////

int main()
{
    startTime = (double)clock();
    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
    ioss
    // int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
    suraj();
    //}
    return 0;
}
