#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>  // 添加这一行
#include <unordered_map>
#include <iostream>
#include <list>

using namespace std ;
class Solution {
public:
    // 判断是否为2点幂
    bool isPowerOfTwo(int n) {
        if (n <= 1) return false;
        return (n & (n - 1)) == 0;  // 位与操作
    }
    // 406. 根据身高重建队列
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0]==b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        list<vector<int>> res;

        for(int i = 0; i < people.size(); ++i)
        {
            list<vector<int>>::iterator it = res.begin();
            int position = people[i][1];
            while(position--)
            {
                it++;
            }
            res.insert(it, people[i]);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }

    // 452. 用最少数量的箭引爆气球
    static bool cmp2(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp2);
        int res = 1;
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] <= points[i-1][1])
            {
                points[i][1] = min(points[i][1], points[i-1][1]);
            }
            else{
                res++;
            }
            }
        return res;
    }

    // 435. 无重叠区间
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    // }
    // 763. 划分字母区间
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a'] = i;
        }
        int left =0;
        int right =0;
        vector<int> res;
        for(int i=0;i<s.size();i++)
        {
            right = max(right,hash[s[i]-'a']);
            if(i==right)
            {
                res.push_back(right-left+1);
                left = i+1;
            }
        }
        return res;
    }
    // 56. 合并区间
    static bool cmp3(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp3);
        vector<vector<int>> res;
        if(intervals.size()==1) return intervals;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);

            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    // 738. 单调递增的数字
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int nine = num.size();
        for(int i = num.size()-1;i>0;i--)
        {
            if(num[i]<num[i-1])
            {
                num[i-1]--;
                nine = i;
                printf("%c\n",num[i]);
            }
        }
        printf("%d\n",nine);
        for(int i = nine;i<num.size();i++)
        {
            num[i] = '9';
        }
        return stoi(num);
    }

    // 724. 寻找数组的中心下标
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int leftSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(leftSum == sum-leftSum-nums[i])
            {
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};



int main() {
    // 创建 Solution 的实例
    Solution solution;

     int n = 120;
    int result = solution.monotoneIncreasingDigits(n);
    std::cout << "Original number: " << n << std::endl;
    std::cout << "Modified number: " << result << std::endl;
    return 0;
}