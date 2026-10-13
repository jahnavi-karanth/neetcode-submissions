class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int maxlen=0,len=0;
        int l=0,r=0,n=s.size();
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            hash[s[r]]=r;
            len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};
