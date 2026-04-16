// You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring
// that contains exactly k distinct characters.

// Note : If no such substring exists, return -1.

// Examples:

// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.

#include <bits/stdc++.h>
using namespace std;

int longestSubstr(string &s, int k)
{
    int n = s.length();

    int max_len = -1;

    int l = 0, r = 0;

    vector<int> freq(26, 0);

    int cnt = 0;

    while (r < n)
    {

        freq[s[r] - 'a']++;

        if (freq[s[r] - 'a'] == 1)
            cnt++;

        while (cnt > k)
        {

            freq[s[l] - 'a']--;

            if (freq[s[l] - 'a'] == 0)
                cnt--;
            l++;
        }

        if (cnt == k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    return max_len;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout << longestSubstr(s, k);
    return 0;
}