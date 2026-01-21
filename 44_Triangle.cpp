#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于生成随机数
#include <climits> // 用于INT_MIN

using namespace std;

// 记忆化数组，存储已经计算过的(i,j)位置的最大路径和
vector<vector<int>> memo;

// 递归函数：计算从(i,j)位置到底边的最大路径和
int dfs(const vector<vector<int>> &triangle, int i, int j)
{
    // 终止条件：到达最后一行
    if (i == triangle.size() - 1)
    {
        return triangle[i][j];
    }

    // 记忆化：如果已经计算过该位置，直接返回结果
    if (memo[i][j] != INT_MIN)
    {
        return memo[i][j];
    }

    // 递归计算正下方和右下方的最大路径和
    int down = dfs(triangle, i + 1, j);           // 正下方
    int down_right = dfs(triangle, i + 1, j + 1); // 右下方

    // 存储当前位置的最大路径和到记忆数组
    memo[i][j] = triangle[i][j] + max(down, down_right);

    return memo[i][j];
}

// 回溯函数：根据记忆数组找到具体路径
void findPath(const vector<vector<int>> &triangle, vector<int> &path, int i, int j)
{
    // 将当前位置加入路径
    path.push_back(triangle[i][j]);

    // 终止条件：到达最后一行
    if (i == triangle.size() - 1)
    {
        return;
    }

    // 选择下一个位置（正下方或右下方，取更大的那个）
    int down = dfs(triangle, i + 1, j);
    int down_right = dfs(triangle, i + 1, j + 1);

    if (down > down_right)
    {
        findPath(triangle, path, i + 1, j);
    }
    else
    {
        findPath(triangle, path, i + 1, j + 1);
    }
}

// 主函数：计算最大路径和并返回路径
int maxPathSumRecursive(const vector<vector<int>> &triangle, vector<int> &path)
{
    if (triangle.empty())
        return 0;

    int n = triangle.size();
    // 初始化记忆数组，值为INT_MIN表示未计算
    memo = vector<vector<int>>(n, vector<int>(n, INT_MIN));

    // 从顶端(0,0)开始递归计算最大路径和
    int max_sum = dfs(triangle, 0, 0);

    // 回溯找到具体路径
    path.clear();
    findPath(triangle, path, 0, 0);

    return max_sum;
}

int main()
{
    srand((unsigned)time(NULL));
    // 示例数字三角形
    vector<vector<int>> triangle;
    for (int i = 0; i < 5; ++i)
    {
        triangle.push_back(vector<int>(i + 1));
        for (int j = 0; j <= i; ++j)
        {
            triangle[i][j] = rand() % 10; // 随机生成0到9的数字
        }
    }
    // 输出数字三角形
    cout << "数字三角形：" << endl;
    for (const auto &row : triangle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    vector<int> path;
    int max_sum = maxPathSumRecursive(triangle, path);

    // 输出结果
    cout << "最大路径和：" << max_sum << endl;
    cout << "路径（从顶到底）：";
    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;

    return 0;
}
