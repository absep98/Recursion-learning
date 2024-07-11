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
// it will generate all subsequences in order to stop further calls 
// just want to have one answer then do more optimization with true/false conditions below

#include<bits/stdc++.h>
using namespace std;
bool solve(int ind, int sum,vector<int>& nums, vector<int>& dp, int n, int target){
    if(ind == n){
        if(sum == target){
            for(int i = 0 ; i < dp.size() ; i++){
                cout<<dp[i]<<" ";
            }
            cout<<endl;
            return true;
        }
        else{
            return false;
        }
    }
    dp.push_back(nums[ind]);
    sum += nums[ind];
    if(solve(ind+1, sum, nums, dp, n, target)){
        return true;
    }
    sum -= nums[ind];
    dp.pop_back();
    if(solve(ind+1, sum, nums, dp, n, target)){
        return true;
    }
    return false;
}
int main(){
    vector<int> nums = {1,2,3,4,5};
    vector<int> dp;
    solve(0,0, nums, dp, nums.size(), 9);
}
