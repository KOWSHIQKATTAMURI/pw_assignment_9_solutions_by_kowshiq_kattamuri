#include<bits/stdc++.h>
using namespace std;

int n;
vector<bool> status(n);

bool isBadVersion(int i){
    return status[i];
}

int firstBadVersion(int n){
    long long start = 1, end = n, ans;
    while(start <= end){
        long long int mid = start + (end - start)/2;
        if(isBadVersion(mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int random; //must be less than or equal to n
    cin >> n >> random;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        if(i <= random){
            status[i] = false;
        }else{
            status[i] = true;
        }
    }
    cout << firstBadVersion(n) << endl;
}