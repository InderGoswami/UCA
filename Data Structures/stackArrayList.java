import java.util.*;
public class stackArrayList{
    public static class Stack{
        static ArrayList<Integer> list=new ArrayList<>();
        public static boolean isEmpty(){
            if(list.size()==0){
                return true;
            }
            return false;
        }
        public static void push(int val){
            list.add(val);//will add element at last of arrayList
            //hence consider last of list to be top of stack
        }
        public static int pop(){
            if(isEmpty()){
                return -1;
            }
            int val=list.get(list.size()-1);//O(1)
            list.remove(list.size()-1);//O(1)
            return val;
        }
        public static int peek(){
            if(isEmpty()){
                return -1;
            }
            return list.get(list.size()-1);
        }
        public static void printSt(){
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
        //LIFO
        s.printSt();

    }
}