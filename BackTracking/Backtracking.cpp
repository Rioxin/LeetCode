#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //组合
    vector<vector<int>> res;
    vector<int> path;
    void fun(int start,int n,int k)
    {
        if(path.size()==k)
        {
            res.push_back(path);
            path.clear();
            return;
        }
        for(int i = start;i<n;i++)
        {
            path.push_back(i);
            fun(i+1,n,k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        fun(1,n,k);
        return res;
    }

    // 组合总和 III
    void fun(int k,int n,int start)
    {
        int sum = 0;
        for(int num : path)
        {
            sum+=num;
        }
        if(path.size()==k && sum==n)
        {
            res.push_back(path);
            return;
        }
        for(int i =start;i<10;i++)
        {
            path.push_back(i);
            fun(k,n,i+1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        fun(k,n,1);
        return res;
    }

    //电话号码的字母组合
    const string phone[10]{
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    string s;
    vector<string> res2;
    void fun(int index,int n ,string digits)
    {
        if(path.size()==n)
        {
            res2.push_back(s);
            return;
        }
        int dig = digits[index] - '0';
        for(int i = 0 ;i<phone[dig].size();i++)
        {
            s.push_back(phone[dig][i]);
            fun(index+1,n,digits);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        fun(0,digits.size(),digits);
        return res2;
    }

    //组合总和
    void fun(vector<int>& candidates, int target,int start,int sum)
    {
        if(sum>=target)
        {
            if(sum==target)res.push_back(path);
            return;
        }
        for(int i = start;i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            sum+=candidates[i];
            fun(candidates,target,i,sum);
            path.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        fun(candidates,target,0,0);
        return res;
    }

    //组合总和 II
    void fun(vector<int>& candidates, int target,int start,int sum)
    {
        if(sum>=target)
        {
            if(sum==target)
            {
                res.push_back(path);
            }
            return;
        }
        for(int i = start;i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            sum+=candidates[i];
            fun(candidates,target,i+1,sum);
            path.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        fun(candidates,target,0,0);
        return res;
    }
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createTree();

    cout << "Preorder Traversal: ";
    vector<vector<int>> result = solution.zigzagLevelOrder(root);
    for (vector<int>res : result) {
        for( int val :res ){
        cout << val << " ";
        }
        cout<<endl;
    }
    cout << endl;

    return 0;
}