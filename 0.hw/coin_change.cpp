class Solution {
public:
    int coinChange(vector<int>& vec, int need) {
        std::vector<int> dp(need+1, 0);
        dp[0] = dp[1] = 1;
        return change(vec, vec.size()-1, need);
    }
    
    int change(vector<int>& vec, int index,  int need, vec) {
        
        if (need < 0 || index < 0) return -1;
        if (need == 0) return 0;
        // если есть такой индекс в мапе то возврашаем 
        auto a = change(vec, index-1, need);
        auto b = change(vec, index, need-vec[index]);
        
        int res = INT_MAX;

        if (a >= 0) res = std::min(a, res);
        if (b >= 0) res = std::min(b+1, res);
        //-> map[index] = res
        if (res == INT_MAX) return -1;
        else return res;
    }
};

