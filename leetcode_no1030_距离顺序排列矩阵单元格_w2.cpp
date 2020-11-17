/* ------------------------------------------------------------------|
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	自定义排序法
*
*	执行用时：108 ms, 在所有 C++ 提交中击败了51.06%的用户
*	内存消耗：16.7 MB, 在所有 C++ 提交中击败了53.34%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> res;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            res.push_back({ i,j });
        }
    }
    //如要使用外部变量，应在[]中加入&或=以捕获变量使用，推测[]内用途是传递参数
    sort(res.begin(), res.end(), [&](vector<int>& u, vector<int>& v) {
        return abs(u[0] - r0) + abs(u[1] - c0) < abs(v[0] - r0) + abs(v[1] - c0);
        });

}