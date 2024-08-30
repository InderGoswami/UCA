class Solution {
    public int totalFruit(int[] fruits) {
        int i=0;
        int ans=Integer.MIN_VALUE;
        int count=0;
        Map<Integer,Integer> mp=new HashMap<>();
        for(int j=0;j<fruits.length;j++){
            mp.put(fruits[j],mp.getOrDefault(fruits[j],0)+1);
            count++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp.put(fruits[i],mp.get(fruits[i])-1);
                    
                    if(mp.get(fruits[i])==0){
                        mp.remove(fruits[i]);
                    }
                    i++;
                    count--;
                }
            }
            ans=Math.max(ans,count);
        }
        return ans;
        
    }
}
