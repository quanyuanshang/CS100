#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using string = std::string;
template <typename T>
using vector = std::vector<T>;
template <typename T>
using unordered_set = std::unordered_set<T>;
template <typename T>
using unordered_map = std::unordered_map<T>;
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
// 用set
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2)
        {
            if (nums_set.find(num) != nums_set.end())
            {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
// 用数组，有数据大小<1000的规定
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result;
        int harsh[1005] = {0};
        for (int i = 0; i < nums1.size(); i++)
        {
            harsh[nums1[i]] = 1; // 不用++防止重复
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (harsh[nums2[i]] == 1)
            {
                result.insert(nums2[i]);
            }; // 不用++防止重复
        }

        return vector<int>(result.begin(), result.end());
    }
};

// 两数之和
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {

            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
            {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

// 四数相加
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        std::unordered_map<int, int> map;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                map[a + b]++;
            }
        }
        int count = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                int target = 0 - (c + d);
                if (map.find(target) != map.end())
                {
                    count += map[target];
                }
            }
        }
        return count;
    }
};