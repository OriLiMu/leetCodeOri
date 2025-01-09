#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() == 0)
      return 0;
    int left = 0, right = 1;
    unordered_map<char, bool> curCharsMap;
    int maxLength = 1;
    int curMaxLength = 1;
    curCharsMap[s[0]] = 1;
    while (right <= s.size() - 1)
    {
      // if contains right char.
      if (curCharsMap.count(s[right]))
      {
        // loop from left char to the char which equals to the right and remove
        // the char from start after the same char in s
        while (true)
        {
          curCharsMap.erase(s[left]);
          curMaxLength--;
          if (s[left] == s[right])
          {
            left++;
            break;
          }
          left++;
        }
      }
      else
      {
        curMaxLength++;
        if (curMaxLength > maxLength)
          maxLength = curMaxLength;
      }
      curCharsMap[s[right]] = 1;
      right++;
    }

    return maxLength;
  }
};

int main()
{
  Solution sol;
  cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << sol.lengthOfLongestSubstring("bbbbb") << endl;
  cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
}
