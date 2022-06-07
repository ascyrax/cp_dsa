#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

/**
 * https://codeforces.com/problemset/problem/701/C
 * 7
 * bcAAcbc should output 3
 * 6
 * aaBCCe should output 5
 */
int main() {
    int flat_num;
    std::cin >> flat_num;
    vector<char> flats(flat_num);
    std::unordered_set<char> types;
    for (char& p : flats) {
        std::cin >> p;
        types.insert(p);
    }

    int shortest_interval = INT32_MAX;
    std::unordered_map<char, int> curr_pokemon;
    int closest_left = 0;
    for (int right = 0; right < flat_num; right++) {
        curr_pokemon[flats[right]]++;
        // check if removing the left one would remove a needed type
        while (closest_left + 1 <= right && curr_pokemon[flats[closest_left]] > 1) {
            curr_pokemon[flats[closest_left]]--;
            closest_left++;
        }
        /*
         * of course, it's a possibility the current arrangement
         * wasn't valid at all, so we need to check for that
         */
        if (curr_pokemon.size() == types.size()) {
            shortest_interval = std::min(shortest_interval, right - closest_left + 1);
        }
    }
    cout << shortest_interval << endl;
}
