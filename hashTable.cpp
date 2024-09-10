#include <string>
#include <vector>
#include <unordered_set>
using string = std::string;
template <typename T>
using vector = std::vector<T>;
// 有效的字母异位词
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int harsh[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            harsh[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            harsh[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (harsh[i] != 0)
                return false;
        }
        return true;
    }
};

// 两个数组的交集
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set
    }
};