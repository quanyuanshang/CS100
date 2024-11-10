#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
// 组合问题
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startindex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i <= n; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
}; // 剪枝
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startindex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startindex; i <= n - (k - path.size()) + 1; i++)
        {

            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};
/// 组合3
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int targetSum, int k, int sum, int startindex)
    {
        if (sum > targetSum)
        {
            return;
        }

        if (path.size() == k)
        {
            if (targetSum == sum)
            {
                result.push_back(path);
            }

            return;
        }
        for (int i = startindex; i <= 10 - (k - path.size()); i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(n, k, 0, 1);
        return result;
    }
};

// phone number
class Solution
{
public:
    const string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} vector<string>;
    vector<string> result;
    string path;
    void backtracking(string &digits, int index, const string &path)
    {
        if (index == digits.size())
        {
            result.push_back(path);
            return;
        }
        int digit = digits[index] - '0';
        string letter = letterMap[digit];
        for (int i = 0; i < letter.size(); i++)
        {

            backtracking(digits, index + 1, path + letter[i]);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return result;
        }
        backtracking(digits, 0, "");
        return result;
    }
};
// 组合选取
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
    }
};