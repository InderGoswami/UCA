class Solution {
    public int search(int[] nums, int target) {
        int start=0;
        int end=nums.length-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            //check whether which part is sorted as binary search can be applied only on sorted array
            else if(nums[start]<=nums[mid]){//left part is sorted
                //check whether target lies i left part or not
                if(target>=nums[start] && target<=nums[mid]){//can lie in this left part
                    end=mid-1;
                }
                else{
                    //can lies in second right part
                    start=mid+1;
                }
            }
            else{//right part is sorted and search in right part
                //find whether it can lie in this part
                if(target>=nums[mid] && target<=nums[end]){
                    start=mid+1;
                }
                else{//lies in right part
                end=mid-1;

                }

            }
            mid=start+(end-start)/2;
        }
        return -1;
        
    }
}
