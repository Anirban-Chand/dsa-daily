class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        int ans=0;
        unordered_map<string, int> mp;
        for(auto word: words) mp[word]++;
        
        for(auto it : mp){
            string word = it.first;
            int i=0,j=0;
            while(i<s.size() and j<word.size()){
                if(s[i] == word[j]) j++;
                i++;
                if(i==s.size()) break;
            }
            if(j==word.size()) ans+=mp[word];
        }
        return ans;
    }
};
