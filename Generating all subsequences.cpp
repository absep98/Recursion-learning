#include<bits/stdc++.h>
using namespace std;
void solve(int ind, int sum,vector<int>& nums, vector<int>& dp, int n, int target){
    if(ind == n){
        if(sum == target){
            for(int i = 0 ; i < dp.size() ; i++){
                cout<<dp[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    dp.push_back(nums[ind]);
    sum += nums[ind];
    solve(ind+1, sum, nums, dp, n, target);
    sum -= nums[ind];
    dp.pop_back();
    solve(ind+1, sum, nums, dp, n, target);
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    vector<int> dp;
    solve(0,0, nums, dp, nums.size(), 9);
}
