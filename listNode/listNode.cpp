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
    }

    //链表相交
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA=headA;
        ListNode* curB=headB;
        int lenA=0,lenB=0,gap;
        while(curA!=NULL)
        {
            lenA++;
            curA=curA->next;
        }
        while(curB!=NULL)
        {
            lenB++;
            curB=curB->next;
        }
        // curA=headA;
        // curB=headB;
        if(lenA<lenB)
        {
            swap(lenA,lenB);
            swap(curA,curB);
        }
        gap=lenA-lenB;
        while(gap--)
        {
            curA=curA->next;
        }
        while(curA!=NULL)
        {
            if(curA == curB)
            {
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }
        return NULL;
    }

    //环形链表
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* index1 = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow)
            {
                ListNode* index2 = slow;
                while(index1!=index2)
                {
                    index1=index1->next;
                    index2=index2->next;
                }
                return index1;
            }

        }
        return NULL;
    }

    
};



int main()
{
 // 创建 Solution 对象
    Solution solution;

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