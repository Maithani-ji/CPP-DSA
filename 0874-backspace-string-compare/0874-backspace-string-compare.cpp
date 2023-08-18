class Solution { // used 2 pointers BUT  use STACK for more easiness
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1; // Pointer for string s
        int j = t.size() - 1; // Pointer for string t

        while (i >= 0 || j >= 0) {
            // Simulate backspaces and find the valid character or skip backspaces in string s
            int skips = 0;
            while (i >= 0 && (s[i] == '#' || skips > 0)) {
                skips += (s[i] == '#') ? 1 : -1;
                i--;
            }

            // Simulate backspaces and find the valid character or skip backspaces in string t
            int skipt = 0;
            while (j >= 0 && (t[j] == '#' || skipt > 0)) {
                skipt += (t[j] == '#') ? 1 : -1;
                j--;
            }

            // Compare the valid characters or check if both characters are exhausted and mismatched
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            // Check if one of the strings is exhausted while the other isn't
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            i--;
            j--;
        }
        return true; // If both strings are exhausted and no mismatches occurred
    }
};
