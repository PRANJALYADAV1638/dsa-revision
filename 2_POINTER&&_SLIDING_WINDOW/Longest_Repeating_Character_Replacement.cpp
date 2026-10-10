/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left=0;
        int right=0;

        int ans=0;
        int windowsize=0;
        int maxfreq=0;
        while(right<s.length()){
            mp[s[right]]++;
           windowsize++;
           maxfreq=max(maxfreq,mp[s[right]]);


           while(windowsize-maxfreq>k){
           
          mp[s[left]]--;
          windowsize--;
          left++;
          
        
           }
           
           ans=max(ans,right-left+1);
           right++;
        }
        return ans;
    }
};
*/