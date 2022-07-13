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



// OPTIMAL SOLUTION - TWO POINTERS
class Solution {
public:
    bool isSubsequence(string s, string t) {
        return solution2_twoPointer(s,t);
    }

    bool solution2_twoPointer(string &s, string &t){
        int i=0, j=0;
        while(i<s.size() and j<t.size()){
            if(s[i] == t[j]) i++;
            j++;
        }
        if(i==s.size()) return true;
        return false;
    }
};
