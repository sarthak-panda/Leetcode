class Solution {
public:
    int minOperations(const string& s) {
        int n = s.size();

        // O(n), instead of copying and sorting the string
        if (is_sorted(s.begin(), s.end())) return 0;

        char lowest_char = 'z' + 1, highest_char = 'a' - 1;
        int count_of_lowest_char = 0, count_of_highest_char = 0;

        for (char c : s) {
            if (c < lowest_char) {
                lowest_char = c;
                count_of_lowest_char = 1;
            } else if (c == lowest_char) {
                count_of_lowest_char++;
            }

            if (c > highest_char) {
                highest_char = c;
                count_of_highest_char = 1;
            } else if (c == highest_char) {
                count_of_highest_char++;
            }
        }

        // Equivalent to sorted_s[0] == s[0] ||
        //             sorted_s[n-1] == s[n-1]
        if (lowest_char == s[0] || highest_char == s[n - 1])
            return 1;

        if (count_of_highest_char == 1 &&
            count_of_lowest_char == 1 &&
            s[0] == highest_char &&
            s[n - 1] == lowest_char) {
            
            return n == 2 ? -1 : 3;
        }

        return 2;
    }
};