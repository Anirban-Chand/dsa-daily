class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans=0;
        while(amount[0]>0 || amount[1]>0 || amount[2]>0){
            sort(amount.begin(), amount.end());
            ans++;
            amount[1]--;
            amount[2]--;
        }
        return ans;
    }
};
