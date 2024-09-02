public class QueueUsingArr{
    public static class Queue{
        static int arr[];
        static int size;
        static int rear;
        //front will remain always zero 
        //but rear remains changing
        Queue(int n){
            arr=new int[n];
            size=n;
            //no need to take front as it remains fixed 0
            rear=-1;
        }
        public static boolean isEmpty(){
            return rear==-1;//intially rear is -1 means no element in queue
        }
        public static void add(int val){
            if(rear==size-1){
                System.out.println("Queue is full");
                return;
            }
            arr[++rear]=val;
            //rear points to last value in queue
        }
        public static  int remove(){//O(n)
            if(isEmpty()){
                System.out.println("Empty Queue");
                return -1;
            }
            int val=arr[0];//front
            //delete first element from array
            //Shift element after front index in left by one position
            for(int i=0;i<rear;i++){
                arr[i]=arr[i+1];
            }
            rear--;
            return val;
        }
        public static int peek(){
            if(isEmpty()){
                System.out.println("Empty Queue");
                return -1;
            }
            return arr[0];
        }
    }
    public static void main(String args[]){
        //Drawback of implementing Queue using array is fixed size of array
        //Another drawback of implementing Queue using array is removing element from front takes time complexity of O(n)
        //Array is efficient in implementing Circular Queue
        Queue q=new Queue(5);
        q.add(1);
        q.add(2);
        q.add(3);
        //1 2 3
        while(!q.isEmpty()){
            
            System.out.println(q.remove());
        }

    }
}