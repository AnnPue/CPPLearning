#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// ==================== 二叉树节点定义 ====================
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ==================== 你的算法实现（迭代法） ====================
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> stk;
        TreeNode *cur = root;

        while (cur != nullptr || !stk.empty())
        {
            while (cur != nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top();
            stk.pop();

            k--;
            if (k == 0)
            {
                return cur->val;
            }

            cur = cur->right;
        }
        return -1; // 如果 k 无效，返回 -1（仅用于防御）
    }
};

// ==================== 辅助函数：释放内存 ====================
void deleteTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// ==================== 测试用例运行器 ====================
void runTestCase(TreeNode *root, int k, int expected, double testId)
{
    Solution sol;
    int result = sol.kthSmallest(root, k);
    cout << "测试 " << testId << ": k = " << k
         << " | 期望值: " << expected
         << " | 实际值: " << result
         << " | " << (result == expected ? "✅ 通过" : "❌ 失败") << endl;
}

int main()
{
    cout << "========== 开始测试 kthSmallest ==========" << endl
         << endl;

    // -------- 测试 1：标准平衡树 --------
    // 结构：
    //     3
    //    / \
    //   1   4
    //    \
    //     2
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    cout << "【测试集 1】标准 BST (1,2,3,4)" << endl;
    runTestCase(root1, 1, 1, 1.1);
    runTestCase(root1, 2, 2, 1.2);
    runTestCase(root1, 3, 3, 1.3);
    runTestCase(root1, 4, 4, 1.4);
    cout << endl;

    // -------- 测试 2：左倾退化链表（类似斜树） --------
    // 结构：
    //     5
    //    /
    //   4
    //  /
    // 3
    // /
    // 2
    // /
    // 1
    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->left->left = new TreeNode(3);
    root2->left->left->left = new TreeNode(2);
    root2->left->left->left->left = new TreeNode(1);

    cout << "【测试集 2】左退化链表 (1,2,3,4,5)" << endl;
    runTestCase(root2, 1, 1, 2.1); // 最小元素在树的最深处
    runTestCase(root2, 3, 3, 2.2);
    runTestCase(root2, 5, 5, 2.3); // 最大元素是根节点
    cout << endl;

    // -------- 测试 3：右倾退化链表 --------
    // 结构：
    // 1
    //  \
    //   2
    //    \
    //     3
    TreeNode *root3 = new TreeNode(1);
    root3->right = new TreeNode(2);
    root3->right->right = new TreeNode(3);

    cout << "【测试集 3】右退化链表 (1,2,3)" << endl;
    runTestCase(root3, 1, 1, 3.1);
    runTestCase(root3, 2, 2, 3.2);
    runTestCase(root3, 3, 3, 3.3);
    cout << endl;

    // -------- 测试 4：单节点 --------
    TreeNode *root4 = new TreeNode(100);
    cout << "【测试集 4】单节点 (100)" << endl;
    runTestCase(root4, 1, 100, 4.1);
    cout << endl;

    // -------- 测试 5：复杂完全二叉树 --------
    // 结构：
    //       5
    //      / \
    //     3   7
    //    / \   \
    //   2   4   8
    // 中序序列：2,3,4,5,7,8
    TreeNode *root5 = new TreeNode(5);
    root5->left = new TreeNode(3);
    root5->right = new TreeNode(7);
    root5->left->left = new TreeNode(2);
    root5->left->right = new TreeNode(4);
    root5->right->right = new TreeNode(8);

    cout << "【测试集 5】复杂树 (2,3,4,5,7,8)" << endl;
    runTestCase(root5, 1, 2, 5.1);
    runTestCase(root5, 4, 5, 5.2);
    runTestCase(root5, 6, 8, 5.3);
    cout << endl;

    // ========== 释放内存（防止内存泄漏） ==========
    deleteTree(root1);
    deleteTree(root2);
    deleteTree(root3);
    deleteTree(root4);
    deleteTree(root5);

    cout << "========== 所有测试执行完毕 ==========" << endl;
    return 0;
}