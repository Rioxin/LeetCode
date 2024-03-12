#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>

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
        vector<int> res;
        stack<TreeNode*> st;
        if(root==NULL)return res;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
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
        TreeNode* cur = root;
        while(cur!=NULL || !st.empty())
        {
            if(cur!=NULL)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=st.top();
                st.pop();
                res.push_back(cur->val);
                cur=cur->right;
            }
        }
        return res;
    }

    //二叉树的层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root==NULL)return res;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> temp ;
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

    //二叉树的锯齿形层序遍历
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root==NULL)return res;
        que.push(root);
        bool l2r=true;
        while(!que.empty())
        {
            int size = que.size();
            vector<int> temp;
            while(size--)
            {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            if(l2r)
            {
                l2r = false;
            }
            else{
                l2r = true;
                reverse(temp.begin(),temp.end());
            }
            res.push_back(temp);
        }
        return res;
    }

    //翻转二叉树
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL) return root;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            swap(node->left,node->right);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return root;
    }
    //层序遍历
    TreeNode* invertTree2(TreeNode* root) {
        queue<TreeNode*> que;
        if(root==NULL) return root;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            while(size--)
            {
                TreeNode* node=que.front();
                que.pop();
                swap(node->left,node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
    
    //对称二叉树
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> st;
        st.push(root->right);
        st.push(root->left);
        while(!st.empty())
        {
            TreeNode* l=st.top();st.pop();
            TreeNode* r=st.top();st.pop();
            if(!l && !r) continue;
            if((!l || !r || (l->val!=r->val))) return false;
            st.push(l->left);
            st.push(r->right);
            st.push(r->left);
            st.push(l->right);
        }
        return true;
    }
    
    //二叉树的最大深度
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root==NULL) return 1;
        que.push(root);
        int deepth =1;
        while(!que.empty())
        {
            int size = que.size();
            deepth++;
            while(size--)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return deepth;
    }
    //递归
    int maxDepth2(TreeNode* root) {
        if(root==NULL) return 0;
        int left = maxDepth2(root->left);
        int right = maxDepth2(root->right);
        int deepth = 1+max(left,right);
        return deepth;
    }

    //二叉树的最小深度
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(root->left==NULL && root->right!=NULL) return 1+right;
        if(root->left!=NULL && root->right==NULL) return 1+left;
        return 1+max(left,right);
    } 

    //完全二叉树的节点个数
    int countNodes(TreeNode* root) {
        if(root == NULL ) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->left;
        int leftdeep=0,rightdeep=0;                                    
        while(left)
        {
            left=left->left;
            leftdeep++;
        }
        while(right)
        {
            right=right->right;
            rightdeep++;
        }
        if(leftdeep == rightdeep) return (2<<leftdeep)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }

    //平衡二叉树
    int getBalanced(TreeNode* node)
    {
        if(node==NULL) return 0;
        int leftDeepth = getBalanced(node->left);
        int rightDeepth = getBalanced(node->right);
        if(leftDeepth==-1||rightDeepth==-1)return -1;
        if(abs(leftDeepth-rightDeepth)>1) return -1;
        return 1+max(leftDeepth,rightDeepth);

    }
    bool isBalanced(TreeNode* root) {
        return getBalanced(root)==-1? false:true;
    }

    //二叉树的所有路径
    void getPath(vector<int> &path,vector<string> &res,TreeNode* node)
    {
        path.push_back(node->val);
        if(node->left==NULL && node->right==NULL)
        {
            string sPath;
            for(int i =0;i<path.size()-1;i++)
            {
                sPath+=to_string(path[i]);
                sPath+="->";
            }
            sPath+=to_string(path[path.size()-1]);
            res.push_back(sPath);
            return;
        }
        if(node->left)
        {
            getPath(path,res,node->left);
            path.pop_back();
        }
        if(node->right)
        {
            getPath(path,res,node->right);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> res;
        getPath(path,res,root);
        return res;

    }

    //相同的树
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)return true;
        if(p==NULL||q==NULL)return false;
        stack<TreeNode*> st;
        st.push(p);
        st.push(q);
        while(!st.empty())
        {
            TreeNode* leftNode = st.top();st.pop();
            TreeNode* rightNode = st.top();st.pop();
            if(leftNode==NULL && rightNode==NULL) continue;
            if(leftNode==NULL || rightNode==NULL ||leftNode!=rightNode)
            {
                return false;
            }
            st.push(leftNode->left);
            st.push(rightNode->left);
            st.push(leftNode->right);
            st.push(rightNode->right);
        }
        return true;
        
     }

     //左叶子之和
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        if(root->left!=NULL && root->left->left==NULL &&root->left->right==NULL)
        {
            sum=root->left->val;
        }
        sum+=sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        return sum;
    }
    //迭代
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if(!root) return 0;
        st.push(root);
        int sum = 0;
        while(!st.empty())
        {
            TreeNode* node = st.top();st.pop();
            if(node->left!=NULL && node->left->left==NULL &&node->left->right==NULL)
            {   
                sum+=node->left->val;
            }
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return sum;
    }

    int max = INT_MIN;
    int res;
    void fun(TreeNode* node,int deepth)
    {
        if(!node->left && !node->right)
        {
            if(deepth>max)
            {
                max=deepth;
                res = node->val;
            }
            return;
        }
        if(node->left)
        {
            fun(node->left,deepth+1);
        }
        if(node->right)
        {
            fun(node->right,deepth+1);
        }
        return;
    }
    //找树左下角的值
    int findBottomLeftValue(TreeNode* root) {
        fun(root,1);
        return res;
    }

    //路径总和
    bool hasPathSum(TreeNode* root, int targetSum) {
        // stack<pair<TreeNode*,int>> st;
        // if(!root) return false;
        // st.push(pair<TreeNode*,int>(root,root->val));
        // while(!st.empty())
        // {
        //     pair<TreeNode*,int> node = st.top();st.pop();
        //     if(!node.first->left && !node.first->right && targetSum==node.second) return true;
        //     if(node.first->right) st.push(pair<TreeNode*,int>(node.first->right,node.second+node.first->right->val));
        //     if(node.first->left) st.push(pair<TreeNode*,int>(node.first->left,node.second+node.first->left->val));
        // }
        // return false;
        if(!root) return false;
        if(!root->left && !root->right && targetSum ==root->val) return true;
        return hasPathSum(root->left , targetSum - root->val) || hasPathSum(root->right , targetSum - root->val);
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