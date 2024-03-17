#include<vector>
#include<iostream>

using namespace std; 
int partnums(vector<int> &nums,int left,int right)
{
    int part = nums[right];
    int pre = left-1;
    for(int i = left;i<right;i++)
    {
        if(nums[i]<part)
        {
            pre++;
            swap(nums[pre],nums[i]);
        }
    }
    swap(nums[pre+1],nums[right]);
    return pre+1;
}
void quickSort(vector<int> &nums,int left,int right)
{
    if(left<right)
    {
        int part = partnums(nums,left,right);
        quickSort(nums,left,part-1);
        quickSort(nums,part+1,right);
    }
    return;
}

// 打印数组元素
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}