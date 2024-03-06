#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>
#include <stack>

using namespace std ;
class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut; 
    MyQueue() { 
    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        while(!stackIn.empty())
        {
            stackOut.push(stackIn.top());
            stackIn.pop();
        }
        int res =  stackOut.top();
        stackOut.pop();
        return res;
    }
    
    int peek() {
        int res=this->pop();
        stackOut.push(res);
        return res;
    }
    
    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
    
};

class MyStack {
public:
    deque<int> deqIn;
    deque<int> deqOut;
    MyStack() {

    }
    
    void push(int x) {
        deqIn.push_back(x);
    }
    
    int pop() {
        if(deqOut.empty())
        {
            while(!deqIn.empty())
            {
                
            }
        }
    }
    
    int top() {

    }
    
    bool empty() {

    }
};