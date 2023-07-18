#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target){
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    cout << searchInsert(nums, target) << endl;
}