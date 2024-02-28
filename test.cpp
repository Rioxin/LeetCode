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
    //设计链表
class MyLinkedList {
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(NULL){}
    };
public:
    MyLinkedList() {
    dummyhead = new ListNode(0);
    size_=0;

    }
    
    int get(int index) {
        if(index>size_-1 )
        {
            return -1;
        }
        ListNode* cur = dummyhead->next;
        while(index--)
        {
            cur=cur->next;
        }
        return cur->val;

    }
    
    void addAtHead(int val) {
        ListNode* newList = new ListNode(val);
        newList->next = dummyhead->next;
        dummyhead->next = newList;
        size_++;
        printf("size: %d\r\n",size_);

    }
    
    void addAtTail(int val) {
        ListNode* tailList = new ListNode(val);
        ListNode* temp = dummyhead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=tailList;
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if(index==size_-1)
        {
           addAtTail(val); 
        }
        ListNode* pre = dummyhead;
        ListNode* temp = dummyhead;
        ListNode* newtemp = new ListNode(val);
        while(index--)
        {
            pre=pre->next;
        }
            temp = pre->next;
            pre->next = newtemp;
            newtemp->next = temp;
        size_++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index>size_-1)
        {
           return;
        }
        ListNode* cur = dummyhead;
        while(index--)
        {
            cur = cur->next;            
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        cur->next=temp;
        delete temp;
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        temp=nullptr;
        size_--;
    }
    private:
    int size_;
    ListNode* dummyhead;
};
class Solution {
public:

     vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
        unordered_map <int,int> set ;
        set.insert(pair<int,int>(1,2));
        unordered_map <int,string> newmap ;
        newmap.insert(pair<int,string>(1,"hello"));
        newmap.insert({2,"word"});
        cout << "hashmap" << newmap.find(1)->second  <<  endl;
        auto it = newmap.find(1);  // 获取指向键为1的迭代器
        if (it != newmap.end()) {
            std::cout << "Value for key 1: " << it->second << std::endl;
        }
        map.find(2);
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }

            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }

    //二分查找
    int twosearch(vector<int>& nums,int target)
    {
        int left=0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = left + (right - left )/2;
            printf("%d \r\n",mid);
            if (nums[mid] < target)
            {
                left = mid+1;
                printf("%d \r\n",left);
            }
            else if (nums[mid] > target)
            {
                right = mid-1;
                printf("%d \r\n",right);
            }
            else{
                return  mid;
            }
        }
        return -1;
    }

    //移除元素
    int removeElement(vector<int> &nums , int val)
    {
        int slow=0,fast=0;
        if(nums.size()==0)
        {
            return 0;
        }
        while(fast<nums.size())
        {
            if(nums[fast]!=val)
            {
            nums[slow]=nums[fast];
                slow ++;
            }
            fast ++;
        }
        return slow;
    }

    //有序数组的平方
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left=0;
        int right=nums.size()-1;
        int i=nums.size()-1;
        vector<int> res(nums.size(),0);
        while(left<=right)
        {
            if(nums[left]*nums[left] < nums[right]*nums[right] )
            {
                res[i--]=nums[right]*nums[right];
                right--;
            }
            else{
                res[i--]= nums[left]*nums[left];
                left ++;
            }

        }
        return res;
    }

    //长度最小的子数组
    int minSubArrayLen(vector<int> &nums,int s )
    {
        if(nums.size()==0)
        return 0;
        int slow=0,fast=0;
        int sum = 0,res=INT32_MAX;
        for(fast=0;fast<nums.size();fast++)
        {
            sum+=nums[fast];
            if(sum >= s)
            {
                while(sum >= s)
                {
                    res=min(res,fast-slow+1);
                    // printf("%d  %d %d\r\n",sum,slow,fast);
                    sum-=nums[slow];
                    slow++;
                }
            }

        }
        if(res>nums.size())
        {
            res=0;
        }        
        return res;
    }

    //螺旋矩阵2
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n,vector<int>(n,0));
        int loop = n /2;
        int startx=0,starty=0;
        int i,j;
        int offset=1;
        int count =1;
        while(loop--)
        {
            i=startx;
            j=starty;
            for(;j<n-offset;j++)
            {
                res[i][j]=count++;
            }
            for(;i<n-offset;i++)
            {
                res[i][j]=count++;
            }
            for(;j>starty;j--)
            {
                res[i][j]=count++;
            }
            for(;i>startx;i--)
            {
                res[i][j]=count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if(n%2 == 1)
        {
            res[n/2][n/2]=n*n;
        }
        return res;
    }


    //移除链表元素
    ListNode* removeElements(ListNode* head, int val) {
        if(head->next==NULL)
        {
            return NULL;
        }
        ListNode* pre = NULL;
        while(head !=NULL && head->val==val)
        {
            head = head->next;

        }
        ListNode* cur = head;
        
        while(cur!= NULL)
        {
            if(cur->val == val)
            {
                
                pre->next=cur->next;
                delete cur;
                cur=pre->next;
            }
            else
            {
            pre=cur;
            cur=cur->next;
            }
            
        }
        return head;
    }

    //反转链表
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* cur = head;
        ListNode* temp = head;
        ListNode* pre = NULL;
        while(cur!=NULL)
        {
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        
        return pre;

    }
    
    //两两交换链表中的节点
    ListNode* swapPairs(ListNode* head) {
      if(head==NULL || head->next==NULL){
      return head;
      }
     ListNode* cur = new ListNode(-1);
     ListNode* res = head->next;
     cur->next = head;
     while(cur->next!=NULL && cur->next->next!=NULL)
     {
        ListNode* temp1=cur->next;
        ListNode* temp2=cur->next->next->next;
        cur->next=cur->next->next;
        cur->next->next=temp1;
        cur->next->next->next=temp2;
        cur=cur->next->next;
     }
     return res;
    }    

    //删除链表的倒数第N个节点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre=new ListNode(-1);
        pre->next=head;
        ListNode* fast=pre;
        ListNode* slow=pre;
        while(n--)
        {
            if(fast->next==NULL)
            {
                return head;
            }
            fast=fast->next;
        }
        fast=fast->next;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return pre->next;

    //链表相交
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* curA=headA;
    //     ListNode* curB=headB;
    //     int lenA=0,lenB=0,gap;
    //     while(curA!=NULL)
    //     {
    //         lenA++;
    //         curA=curA->next;
    //     }
    //     while(curB!=NULL)
    //     {
    //         lenB++;
    //         curB=curB->next;
    //     }
    //     // curA=headA;
    //     // curB=headB;
    //     if(lenA<lenB)
    //     {
    //         swap(lenA,lenB);
    //         swap(curA,curB);
    //     }
    //     gap=lenA-lenB;
    //     while(gap--)
    //     {
    //         curA=curA->next;
    //     }
    //     while(curA!=NULL)
    //     {
    //         if(curA == curB)
    //         {
    //             return curA;
    //         }
    //         curA=curA->next;
    //         curB=curB->next;
    //     }
    //     return NULL;
    // }

    }
};



int main()
{
 // 创建 Solution 对象
    Solution solution;

    // 准备测试数据v
    vector<int> nums = {1,1,1,1,1,1,1,1};

    // 调用 threeSum 方法
    vector<vector<int>> result = solution.generateMatrix(2);
    int target = 11;
    // int result= solution.minSubArrayLen(nums,target);

    // 输出结果
    for (const auto& res : result) {
        // printf("[%d, %d, %d]\n", triplet[0], triplet[1], triplet[2]);
    // cout << "[";
    // for (const auto& value : res) {
    //     cout << value << ", ";
    // }
    // cout << "]" << endl;
        // printf("%d ",res);
    }
    // printf("res = %d",result);

    //链表
    int val = 6;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    ListNode* resList = solution.removeNthFromEnd(head,1);
    while (resList != nullptr) 
    { // 当前节点不为空时
        std::cout << resList->val << " "; // 打印当前节点的值
        resList = resList->next; // 移动到下一个节点
    }
    std::cout << std::endl;

    //设计链表 
    // MyLinkedList* obj = new MyLinkedList();
    // obj->addAtHead(1);
    // std::cout << "Value at index 1: " << obj->get(0) << std::endl;
    // obj->addAtTail(3);
    // obj->addAtIndex(1, 2);    //链表变为1->2->3
    // std::cout << "Value at index 1: " << obj->get(0) << std::endl;
    // std::cout << "Value at index 2: " << obj->get(1) << std::endl;
    // std::cout << "Value at index 3: " << obj->get(2) << std::endl;
    // obj->deleteAtIndex(1);    // 现在链表变为1->3
    // std::cout << "Value at index 1 after deletion: " << obj->get(1) << std::endl;

    return 0;
}