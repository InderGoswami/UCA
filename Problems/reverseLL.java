class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null){  
            return head;

        }
        ListNode temp=reverseList(head.next);
        head.next.next=head;
        head.next=null;
        return temp;//fixed (end of original linked list)
        
    }
}
