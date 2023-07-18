#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target){
    if(nums.size() == 0){
        return {-1, -1};
    }
    auto up = upper_bound(nums.begin(), nums.end(), target), low = lower_bound(nums.begin(), nums.end(), target);
    if(low == nums.end() or *low != target){
        return {-1, -1};
    }
    up--;
    return {(int)(low - nums.begin()), (int)(up - nums.begin())};
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    vector<int> ans = searchRange(nums, target);
    for(auto &i : ans){
        cout << i << " ";
    }
}