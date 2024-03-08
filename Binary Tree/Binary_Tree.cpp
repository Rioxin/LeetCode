#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //三种遍历
    void traversal(TreeNode* cur, vector<int>& vec) {
        if(cur==NULL)return;
        traversal(cur->left,vec);
        traversal(cur->right,vec);
        vec.push_back(cur->val);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    //中左右
    vector<int> preorderTraversal2(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root==NULL)return res;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            res.push_back(node->val);
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return res;
    }

    //左右中
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root==NULL)return res;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            res.push_back(node->val);
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }

    //左中右
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if(root==NULL) return res;
        TreeNode* cur = root;
        while (cur!=NULL || !st.empty())
        {
            if(cur!=NULL)
            {
                st.push(cur);
                cur=cur->left;
            }
            else{
                cur=st.top();
                res.push_back(st.top()->val);
                st.pop();
                cur=cur->right;
            }
        }
        return res;
    }

    //二叉树的层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> temp;
            for(int i =0;i<size;i++)
            {
                TreeNode* node = que.front();
                temp.push_back(node->val);
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }

    //二叉树的层序遍历 II
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> temp;
            for(int i =0;i<size;i++)
            {
                TreeNode* node = que.front();
                temp.push_back(node->val);
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }

    //二叉树的右视图
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> temp;
            for(int i =0;i<size;i++)
            {
                TreeNode* node = que.front();
                temp.push_back(node->val);
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(temp.back());
        }
        return res;
    }

    //二叉树的层平均值
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        if(root!=NULL) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            double sum = 0;
            for(int i =0;i<size;i++)
            {
                TreeNode* node = que.front();
                que.pop();
                sum+=node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            res.push_back(sum/size);
        }
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
    vector<int> result = solution.inorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}