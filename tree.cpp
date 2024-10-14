#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 前序遍历
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 中序遍历
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;

        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 后序
class Solution
{
public:
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;

        traversal(cur->left, vec);

        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 非递归遍历
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *node;
        while (!st.empty())
        {
            node = st.top();
            st.pop();
            if (node != nullptr)
            {
                result.push_back(node->val); // 中
            }
            else
            {
                continue;
            }
            st.push(node->right); // 右
            st.push(node->left);  // 左
        }
        return result;
    }
};
class Solution // 后续遍历
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *node;
        while (!st.empty())
        {
            node = st.top();
            st.pop();
            if (node != nullptr)
            {
                result.push_back(node->val); // 中
            }
            else
            {
                continue;
            }

            st.push(node->left);  // 左
            st.push(node->right); // 右
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
class Solution // 中序
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};

// 层序遍历,最小深度
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        TreeNode *node;
        int depth = 0;
        int min_layer = INT_MAX;
        if (root != NULL)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size(); // 不记录的话容易和下一层的元素一起弹出来，这是控制弹出数目
            vector<int> vec;
            depth++;
            while (size--) // 在循环里que的size是不断变化的
            {
                node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
                if (!node->right && !node->left)
                {
                    return depth;
                }
            }
        }
        return min_layer == INT_MAX ? 0 : min_layer;
    }
};
// 最小深度
class Solution
{
public:
    int getheight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftheight = getheight(node->left);

        int rightheight = getheight(node->right);
        if (node->left == nullptr && node->right != nullptr)
        {
            return 1 + rightheight;
        }
        else if (node->left != nullptr && node->right == nullptr)
        {
            return 1 + leftheight;
        }
        else
            return min(leftheight, rightheight) + 1;
    }
    int minDepth(TreeNode *root)
    {
        return getheight(root);
    }
};
// 翻转二叉树
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr) // root是指操作的变量
            return root;
        swap(root->left, root->right); // 中
        invertTree(root->left);        // 左
        invertTree(root->right);       // 右

        return root;
    }
};

// 对称二叉树
class Solution
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr) // 第二层就是两个都为空就可以直接返回。
            // 剩下的内部节点由bool inside = compare(left->right, right->left)检查
            // 到最终两个节点都是空就直接返回true。
            return true;
        else if (left->val != right->val)
            return false;
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool result = outside & inside;
        return result;
    };

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
};

// 二叉树的最大深度
class Solution
{
public:
    int getheight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftheight = getheight(node->left);

        int rightheight = getheight(node->right);
        int height = max(leftheight, rightheight) + 1;
        return height;
    }
    int maxDepth(TreeNode *root)
    {
        return getheight(root);
    }
};

// 平衡二叉树
class Solution
{
public:
    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1)
            return -1;

        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) == -1 ? false : true;
    }
};
// 二叉树的所有路劲
class Solution
{
public:
    void traversal(TreeNode *node, vector<int> &path, vector<string> &result)
    {
        path.push_back(node->val); // middle

        if (node->left == nullptr && node->right == nullptr)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);

            result.push_back(sPath);
        }
        if (node->left)
        {
            traversal(node->left, path, result);
            path.pop_back(); // 回溯
        }
        if (node->right)
        {
            traversal(node->right, path, result);
            path.pop_back(); // 回溯
        }
    };
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        vector<int> path;
        if (root == nullptr)
            return result;
        traversal(root, path, result);
        return result;
    }
};

// 路径总和
class Solution
{
public:
    bool traversal(TreeNode *node, int count)
    {
        if (node->left == nullptr && node->right == nullptr && count == 0)
            return true;
        if (node->left == nullptr && node->right == nullptr && count != 0)
            return false;
        if (node->left)
        {
            count -= node->left->val;
            if (traversal(node->left, count))
                return true;
            count += node->left->val; // 回溯
        }
        if (node->right)
        {
            count -= node->right->val;
            if (traversal(node->right, count))
                return true;
            count += node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return traversal(root, targetSum - root->val);
    }
};