#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>

using namespace std ;

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
        while(loop--)
        {
            i=startx;
            j=starty;
            for
        }
    }
};

int main()
{
 // 创建 Solution 对象
    Solution solution;

    // 准备测试数据v
    vector<int> nums = {1,1,1,1,1,1,1,1};

    // 调用 threeSum 方法
    // vector<vector<int>> result = solution.threeSum(nums);
    int target = 11;
    int result= solution.minSubArrayLen(nums,target);

    // 输出结果
    // for (const auto& triplet : result) {
    //     // printf("[%d, %d, %d]\n", triplet[0], triplet[1], triplet[2]);
    //     printf("%d ",triplet);
    // }
    printf("res = %d",result);
    return 0;
}