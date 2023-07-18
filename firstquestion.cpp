#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
    int i = 0, n = numbers.size(), j = n - 1;
    vector<int> ans;
    while(i < n and j >= 0){
        if(numbers[i] + numbers[j] == target){
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            break;
        }else if(numbers[i] + numbers[j] < target){
            i++;
        }else{
            j--;
        }
    }
    return ans;
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }
    sort(nums.begin(), nums.end());
    vector<int> ans = twoSum(nums, target);
    for(auto &i : ans){
        cout << i << " ";
    }
}