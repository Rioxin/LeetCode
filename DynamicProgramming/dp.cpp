#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>
#include <list>

using namespace std ;
class Solution {
public:
    // 96. 不同的二叉搜索树
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};



int main() {
    // 创建 Solution 的实例
    Solution solution;

    int n = 4;
    int result = solution.numTrees(n);
    std::cout << "Original number: " << n << std::endl;
    std::cout << "Modified number: " << result << std::endl;
    return 0;
}