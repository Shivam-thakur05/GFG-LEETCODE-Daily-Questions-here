#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;
        for (int card : hand) {
            mp[card]++;
        }

        for (int card : hand) {
            if (mp[card] == 0) continue;  // Skip already used cards

            for (int i = 0; i < groupSize; i++) {
                if (mp[card + i] == 0) return false;
                mp[card + i]--;
            }
        }

        return true;
    }
};
