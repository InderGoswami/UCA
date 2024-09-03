public class QueueUsingLL{
    public static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    public static class Queue{
        static Node head=null;
        static Node tail=null;
        public static boolean isEmpty(){
            if(head==null && head==null){
                return true;
            }
            return false;
        }
        //No need to write function isFull bcz of no  size constraint in linked list
        public static void add(int data){
            //if queue is empty
            Node newNode=new Node(data);
            if(isEmpty()){
                head=newNode;
                tail=newNode;
                return;
            }
            //Add element at tail O(n)
            tail.next=newNode;
            tail=newNode;

        }
        public static int  remove(){
            if(isEmpty()){
                System.out.println("Queue is Empty");
                return -1;
            }
            //remove element from front(head)
            int val=head.data;
            //special case //only one element is present
            if(tail==head){
                tail=head=null;
                return val;
            }
            head=head.next;
            return val;
        }
        public static int peek(){
            if(isEmpty()){
                System.out.println("Queue is empty");
                return -1;
            }
            return head.data;
        }
    }
    public static void main(String args[]){
        //remove element from front (head)
        //add element at last (tail)
        Queue q=new Queue();
        q.add(1);
        q.add(2);
        q.add(3);
        while(!q.isEmpty()){
            System.out.println(q.peek());
            q.remove();
        }
    }
}