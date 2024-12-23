#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
// 斐波那契
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// 爬楼梯
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// 不同路径
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
}; // 不同路径2
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// 整数拆分
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1); // 一定要初始化，确保每个位置一开始都是有值的。
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
// 不同的二叉搜索树
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// 使用最小花费爬楼梯
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {

        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};
// 分割等和子集
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};

// 目标和
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {

        int left;
        int sum = 0;
        for (auto num : nums)
        {
            sum += num;
        }
        if (abs(target) > sum || (sum + target) % 2 == 1)
        {
            return false;
        }

        left = (sum + target) / 2;
        vector<int> dp(left + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = left; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[left];
    }
};

// 求找零的组合数
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// 零钱兑换
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0;
        for (int j = 0; j <= amount; j++)
        {
            for (int i = 0; i < coins.size(); i++)
            {
                if (j - coins[i] >= 0 && dp[j - coins[i]] != INT_MAX)
                { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        if (dp[amount] == INT_MAX)
        {
            return -1;
        }
        return dp[amount];
    }
}; // 第二遍写回顾

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] != INT_MAX) // 如果dp[j-coins[i]]是初始值则跳过
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
        {
            return -1;
        }
        return dp[amount];
    }
};

// 10
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs)
        { // 遍历物品
            int num1 = 0, num0 = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    num0++;
                }
                else
                {
                    num1++;
                }
            }
            for (int i = m; i >= num0; i--) // 遍历背包，倒序
            {
                for (int j = n; j >= num1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// 完全平方数
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                if (dp[j - i * i] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
            if (dp[n] == INT_MAX)
            {
                return -1;
            }
        }
        return dp[n];
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() && dp[j] == true)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// 买卖股票
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};
// II
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};
/// III
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
};

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int i = 1; i < 2 * k; i += 2)
        {
            dp[0][i] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 1; j < 2 * k; j += 2)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};
// 含冷冻期
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][3], max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
    }
};