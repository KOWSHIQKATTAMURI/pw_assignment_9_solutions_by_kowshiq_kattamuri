#include<bits/stdc++.h>
using namespace std;

bool find(vector<int>& nums, int size, int element){
    int low = 0, high = size - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == element){
            return true;
        }else if(nums[mid] < element){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return false;
}

void findcommon(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, int a, int b, int c){
    for(int i = 0; i < a; i++){
        if(i != 0 and nums1[i] == nums1[i - 1]){
            continue;
        }
        if(find(nums2, b, nums1[i]) and find(nums3, c, nums1[i])){
            cout << nums1[i] << " ";
        }
    }
}

int main(){
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> nums1(l), nums2(n), nums3(m);
    for(int i = 0; i < l; i++){
        cin >> nums1[i];
    }
    sort(nums1.begin(), nums1.end());
    for(int i = 0; i < n; i++){
        cin >> nums2[i];
    }
    sort(nums2.begin(), nums2.end());
    for(int i = 0; i < m; i++){
        cin >> nums3[i];
    }
    sort(nums3.begin(), nums3.end());
    findcommon(nums1, nums2, nums3, l, n, m);
}