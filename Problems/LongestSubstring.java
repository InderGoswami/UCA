class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i=0;
        Map<Character,Integer> mp=new HashMap();
        int ans=0;
        int currLen=0;
        for(int j=0;j<s.length();j++){
            if(mp.get(s.charAt(j))==null){
               
                mp.put(s.charAt(j),1);
                currLen++;
                
            }
            else{
            while(mp.get(s.charAt(j))!=null){
                mp.remove(s.charAt(i));
                currLen--;
                i++;
            }
                mp.put(s.charAt(j),1);
                currLen++;
            }
            ans=Math.max(ans,currLen);
        }
        return ans;
    }
