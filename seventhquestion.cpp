#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& nums, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid + 1;
    int count = 0;
    while(left <= mid and right <= high){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            count += (mid - left + 1);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
    return count;
}

int mergesort(vector<int>& nums, int low, int high){
    int count = 0;
    if(low >= high){
        return count;
    }
    int mid = (low + high)/2;
    count += mergesort(nums, low, mid);
    count += mergesort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);
    return count;
}

int numberofinversions(vector<int>& nums){
    return mergesort(nums, 0, nums.size() - 1);
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << numberofinversions(nums) << endl;
}