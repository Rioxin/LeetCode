#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>

using namespace std ;
//链表
struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(NULL){}
    };

class Solution {
public:
    //移除元素
    int removeElement(vector<int>& nums, int val) {
        int slow=0,fast=0;
        while(fast!=nums.size())
        {
            if(nums[fast]!=val)
            {
                nums[slow++]=nums[fast++];
            }
            else
            {
                fast++;
            }
        }
        return slow;
    }

    //翻转字符串
    void reverseString(vector<char>& s) {
        for(int i = 0,j=s.size()-1;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }

    //反转字符串中的单词(有瑕疵)
    void reverses(string &s,int begin,int end)
    {
        for(int i = begin,j=end;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }
    string reverseWords(string s) {
        int slow = 0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
            if(slow!=0)
            s[slow++]=' ';
            while(i<s.size()&&s[i]!=' ')
            {
                s[slow++]=s[i++];
            }
            }
        }
        s.resize(slow);
        cout<<slow<<endl;
        reverses(s,0,s.size()-1);
        int pre = 0;
        for(int i=0;i<s.size();i++ )
        {
            if(s[i]==' ')
            {
              reverses(s,pre,i-1);  
              pre=i+1;
            }
        }
        reverses(s,pre,s.size()-1);  
        return s;
    }
   
    //反转链表(有问题)
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = new ListNode(-1);
        pre->next=head;
        ListNode* fast = head;
        while(fast!=NULL)
        {
            ListNode* temp = fast->next;
            fast->next=pre;
            pre=fast;
            fast=temp;

        }
        return pre;
    }

    
};



int main()
{
 // 创建 Solution 对象
    Solution solution;

    // 准备测试数据v
    vector<int> nums = {1,1,1,1,1,1,1,1};

    // 调用 threeSum 方法
    // vector<vector<int>> result = solution.generateMatrix(2);
    int target = 11;
    // int result= solution.minSubArrayLen(nums,target);

    // // 输出结果
    // for (const auto& res : result) {
    //     // printf("[%d, %d, %d]\n", triplet[0], triplet[1], triplet[2]);
    // // cout << "[";
    // // for (const auto& value : res) {
    // //     cout << value << ", ";
    // // }
    // // cout << "]" << endl;
    //     // printf("%d ",res);
    // }
    // // printf("res = %d",result);

    // //链表
    // int val = 6;
    // ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next->next = new ListNode(7);
    // ListNode* resList = solution.removeNthFromEnd(head,1);
    // while (resList != nullptr) 
    // { // 当前节点不为空时
    //     std::cout << resList->val << " "; // 打印当前节点的值
    //     resList = resList->next; // 移动到下一个节点
    // }
    // std::cout << std::endl;

       string s = "  hello world  ";
    int k = 2;
    // 打印原始字符串
    for (char c : s) {
        cout << c;
    }
    cout <<"!"<< endl;

    // 调用反转函数
    string ress=solution.reverseWords(s);
    for (char c : ress) {
        cout << c;
    }
    cout <<"!"<< endl;

    return 0;
}