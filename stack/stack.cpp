#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>

using namespace std ;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};
class MyStack {
public:
    queue<int> deq1;
    queue<int> deq2;
    MyStack() {

    }
    
    void push(int x) {
        deq1.push(x);
    }
    
    int pop() {
        // while(deq1.size()>1)
        // {
        //     deq2.push(deq1.front());
        //     deq1.pop();
        // }
        // int res = deq1.front();
        // deq1.pop();
        // while(!deq2.empty())
        // {
        //     deq1.push(deq2.front());
        //     deq2.pop();
        // }

        //仅需一个队列
        int len = deq1.size()-1;
        while(len--)
        {
            deq1.push(deq1.front());
            deq1.pop();
        }
        int res = deq1.front();
        deq1.pop();

        return res;
    }
    
    int top() {
        int res=this->pop();
        deq1.push(res);
        return res;
    }
    
    bool empty() {
        return deq1.empty()&&deq2.empty();
    }
};

class Solution {
public:
    //有效括号
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
           if(c=='{')st.push('}');
           else if(c=='(')st.push(')');
           else if(c=='[')st.push(']');
           else if(c=='[')st.push(']');
           else if(st.empty() || c!=st.top()) return false;
           else{
            st.pop();
           }
        }
        return st.empty();
    }
    
    //删除字符串中的所有相邻重复项
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c : s)
        {
            if(!st.empty() && c==st.top())
            {
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string res;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }

    //150. 逆波兰表达式求值
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s :tokens)
        {
            if(s=="+" || s=="-" || s=="*" || s=="/")
            {
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                if(s=="+") st.push(num1+num2);
                if(s=="-") st.push(num1-num2);
                if(s=="*") st.push(num1*num2);
                if(s=="/") st.push(num2/num1);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }

    //滑动窗口的最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> res;
        for(int i = 0;i<nums.size();i++)
        {
            // while(!deq.empty() && deq.front()<i-k+1) deq.pop_front();
            if(!deq.empty() && i>k && deq.front()==nums[i-k]) deq.pop_front();
            while(!deq.empty() && nums[deq.back()]<nums[i]) deq.pop_back();
            deq.push_back(i);
            if(i>=k-1)
            {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
    static bool cmp(const pair<int,int> &left,const pair<int,int> &right)
    {
        return left.second>right.second;
    }
    //前 K 个高频元素
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;


        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for(const auto it : map){
            pri_que.push(it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};



int main()
{
 // 创建 Solution 对象
    Solution solution;

    // 准备测试数据v
    vector<int> nums = {1,1,1,1,1,1,1,1};
 std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto it=vec.begin();it<vec.end();it++) {
        std::cout << *it << std::endl;
    }
   
   
    return 0;
}
