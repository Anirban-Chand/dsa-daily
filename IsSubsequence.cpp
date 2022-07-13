// BRUTE FORCE RECURSIVE SOLUTION
class Solution {
public:
    bool isSubsequence(string s, string t) {        
        string temp="";
        return solve(s,t,0,temp);
    }
    
    bool solve(string &s, string &t, int i, string temp){
        if(i==t.size()){
            if(temp == s) 
                return true;
            return false;
        }
        
        bool dontTake = solve(s, t, i+1, temp);
        
        temp+=t[i];
        bool take = solve(s,t,i+1,temp);
        return take or dontTake;
    }
};
