// C++
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        
        unordered_map<string, int> mp;
        for(auto word: words) mp[word]++;
        
        int ans=0;
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


// Python
class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        n = len(words);
        ans=0;
        mp = {};
        for word in words: 
            if word in mp:
                mp[word] += 1
            else:    
                mp[word] = 1
        
        for word, freq in mp.items():
            i, j = 0, 0
            while i<len(s) and j<len(word):
                if s[i] == word[j]:
                    j+=1
                i+=1
                if i==len(s): 
                    break
            
            if j==len(word): 
                ans+=mp[word];
        
        return ans;
