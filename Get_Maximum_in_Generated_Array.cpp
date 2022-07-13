class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0 || n==1) return n;
        vector<int> v(n+1, 0);
        v[1]=1;
        for(int i=1; 2*i+1<=n; i++){
            v[2*i] = v[i];
            v[2*i+1] = v[i]+v[i+1];
        }
        
        return *max_element(v.begin(), v.end());
    }
};
