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
The time complexity of the permutation generation code can be analyzed as follows:

### Time Complexity

The algorithm generates all possible permutations of the input list. For an input list of length \( n \), the total number of permutations is \( n! \) (n factorial).

- **Permutations Count**: There are \( n! \) permutations for a list of \( n \) distinct elements.
- **Backtracking Depth**: The recursion tree has \( n \) levels (one level for each position in the permutation).
- **Swapping and Copying**: For each level in the recursion, there are \( O(n) \) operations for swapping elements and copying the current permutation when a complete permutation is found.

Thus, the overall time complexity is \( O(n \times n!) \).

### Space Complexity

The space complexity includes the space used by the recursion stack and the space used to store the permutations.

- **Recursion Stack**: The depth of the recursion tree is \( n \), so the space required for the recursion stack is \( O(n) \).
- **Result Storage**: There are \( n! \) permutations, and each permutation has \( n \) elements, so the space required to store all permutations is \( O(n \times n!) \).

Overall, the space complexity is dominated by the storage for all permutations, which is \( O(n \times n!) \).

### Summary

- **Time Complexity**: \( O(n \times n!) \)
- **Space Complexity**: \( O(n \times n!) \)

This is expected for generating all permutations, as each permutation needs to be explicitly constructed and stored.
class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind ; i < nums.size() ; i++){
            swap(nums[ind], nums[i]);
            solve(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(0, nums, ans);
        return ans;
    }
};

// its more faster as compared using swap method
same as above one
