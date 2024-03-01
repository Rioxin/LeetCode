#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  
#include <unordered_map> //哈希表
#include <unordered_set> //哈希表
#include <iostream>

using namespace std ;

class Solution {
public:

    //有效的字母异同词
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        int record[26]={0};
        for(int i=0;i<s.size();i++)
        {
            record[s[i]-'a']++;
            record[t[i]-'a']--;
        }
        for(int i = 0;i<26;i++)
        {
            if(record[i]!=0)
            {
                return false;
            }
        }
        return true;
    }

    //两个数组的交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> record(nums1.begin(),nums1.end());
        for(int i =0;i<nums2.size();i++)
        {
            if(record.find(nums2[i])!=record.end())
            {
                res.insert(nums2[i]);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
    
    //快乐数
    int getsum(int n){
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> record;
        while(n!=1)
        {
            n=getsum(n);
            if(record.find(n)!=record.end())
            {
                return false;
            }
            record.insert(n);
        }
        return true;
    }

    //两数之和
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(target - nums[i])!=hash.end())
            {   
                return {hash[target - nums[i]],i};
            }
            hash.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }

    //四数相加2
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> hash;
        int n = nums1.size();
        int count = 0;
        for(int a :nums1)
        {
            for(int b :nums2)
            {
                hash[a+b]++;
            }
        }
        for(int c :nums3)
        {
            for(int d :nums4)
            {
                int target = -c-d;
                if(hash.find(target)!=hash.end())
                {
                    count+=hash[target];
                }
            }
        }
        return count;
    }

    //赎金信
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hash;
        for(char a :magazine)
        {
            hash[a]++;
        }
        for(char b : ransomNote)
        {
             if(hash.find(b)!=hash.end())
                {
                    hash[b]--;
                }
        }
        for (const auto& pair : hash) {
                if (pair.second < 0) {
                    return false; // 只要发现一个值不为0，就返回false
                }
            }
        return true; // 所有值都为0，返回true
    }

    //三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());   
    for(int num :nums)
    {
        cout<<num<<" ";
    } 
    cout<<endl;
    vector<vector<int>> res={};
    for(int i =0;i<nums.size();i++)
    {
        if(i>0&&nums[i]==nums[i-1])
        {
            continue;
        }
         cout<<"nums[i] = "<< nums[i] <<endl;
        int target= -nums[i];
        int left = i+1;
        int right = nums.size()-1;
        while(left<right)
        {
            cout<<"left = "<< nums[left]<<" right = "<< nums[right] <<endl;
            if(left>i+1&&nums[left]==nums[left-1])
            {
                left++;
                continue;
            }
            if(right<nums.size()-1&&nums[right]==nums[right+1])
            {
                right--;
                continue;
            }
            if(nums[left]+nums[right]==target)
            {
                vector<int> temp = {nums[i],nums[left],nums[right]};
                cout<<"temp = ";
                for(int n :temp)
                {
                    cout << n << " ";
                }
                cout<<endl;
                res.push_back(temp);
                left++;
                right--;
            }
            else if(nums[left]+nums[right]<target)
            {
                left++;
            }
            else if(nums[left]+nums[right]>target)
            {
                right--;
            }

        } 
    }
    return res;
    }

    //四数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4)
        {
            return res;
        }    
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++ )
        {
            if(nums[i]>0&&nums[i]>target)
            {
                break;
            }
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j = i+1;j<nums.size();j++)
            {
                if(nums[i]>0&&nums[i]+nums[j]>target)
            {
                break;
            }
                if(j>i+1 && nums[j]==nums[j-1])
                {
                    continue;
                }
                int left=j+1;
                int right = nums.size()-1;
                while(left<right)
                {
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]<target)
                    {
                        left++;
                    }
                    else if((long)nums[i]+nums[j]+nums[left]+nums[right]>target)
                    {
                        right--;
                    }
                    else 
                    {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left]==nums[left+1])
                        {
                            left++;
                        }
                        while(left<right && nums[right]==nums[right-1])
                        {
                            right--;
                        }                       
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }

};



int main()
{
 // 创建 Solution 对象
    Solution solution;

    // 准备测试数据v
    vector<int> nums = {-3,-1,0,2,4,5};
    // 创建测试用例
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    // 调用 intersection 函数
    // vector<int> result = solution.intersection(nums1, nums2);
    string s = "anagram";
    string t = "nagaram";
    // 调用对象方法
     vector<vector<int>> result = solution.fourSum(nums,1);
    int target = 11;
    // bool result= solution.isHappy(2);

    // 输出结果
    for (vector<int> num : result) {
        for(int n :num)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    // printf("res = %d",result);
    // cout << (result ? "true" : "false") << endl;
    

    return 0;
}