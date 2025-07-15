/*
 * 3136. Valid Word
 * Date: 15-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        bool vowel_found = false;
        bool consonant_found = false;

        for (char c : word) {
            if (!isalnum(static_cast<unsigned char>(c))) {
                return false;
            }

            c = tolower(c);

            if (isalpha(c)) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vowel_found = true;
                } else {
                    consonant_found = true;
                }
            }
        }

        return vowel_found && consonant_found;
    }
};


int main() {
    Solution sol;
    // Test cases
    return 0;
}
