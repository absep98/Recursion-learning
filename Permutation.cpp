class Solution {
public:
    void solve(vector<int>& nums, vector<int>& tmp, vector<bool>& fq, vector<vector<int>>& ans){
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(!fq[i]){
                fq[i] = true;
                tmp.push_back(nums[i]);
                solve(nums, tmp, fq, ans);
                tmp.pop_back();
                fq[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> fq(n, false);
        vector<int> tmp;
        solve(nums, tmp, fq, ans);
        return ans;
    }
};

// take fq array to mark the value entry
