public class stackLinkedList{
    public static class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    public static class Stack{
        static Node head=null;
        public static boolean isEmpty(){
            if(head==null){
                return true;
            }
            return false;
        }
        //head is top of stack
        public static void push(int data){
            //O(1)
            Node newNode=new Node(data);
            if(isEmpty()){
                head=newNode;
                return;
            }
            newNode.next=head;
            head=newNode;


        }
        public static int pop(){
            //remove first
            if(isEmpty()){
                return -1;
            }
            int val=head.data;
            head=head.next;
            return val;
        }
        public static int peek(){
            if(isEmpty()){
                return -1;
            }
            return head.data;
        }
        public static void printLL(){
            while(!isEmpty()){
                System.out.print(peek()+" ");
                pop();
            }
            System.out.println();

        }
       
    }
    public static void main(String args[]){
        Stack s=new Stack();
        s.push(1);
        s.push(2);
        s.push(3);
        s.printLL();

    }
}