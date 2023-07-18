#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums){
    nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
    return nums[nums.size()/2];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << majorityElement(nums) << endl;
}