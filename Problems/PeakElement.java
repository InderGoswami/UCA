class Solution {
    public int findPeakElement(int[] nums) {
        //for single element array,single element is a peak element
        if(nums.length==1){
            return 0;
        }

        //before zero index we have -infinity
        //check element at zero index is peak or not
        if(nums[0]>nums[1]){ //it will handle case of decreasing order
            return 0;
        }
        //after last element , we have -infinity
        //check for last element
        if(nums[nums.length-1]>nums[nums.length-2]){//it will handle case of increasing order
            return nums.length-1;
        }
        //Nither last element is peak nor first element is peak
        //it means any of element between second index and second last will be peak
        int s=1;
        int e=nums.length-2;
        while(s<=e){
            int mid=s+(e-s)/2;
            //check whether mid element is peak or not
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            //Around the pivot there will increasing order one side and decreasing order in other side
            else if(nums[mid]>nums[mid-1]){
                //mid element is part of increasing order
                //pivot can not exist in increasing order
                s=mid+1;
            }
            else{
                //mid element is currenlty lie in decreasing order
                e=mid-1;
            }
           
        }
         return -1;
    }
}
