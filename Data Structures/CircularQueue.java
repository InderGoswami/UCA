public class CircularQueue{
    static class CircularQ{
        static int arr[];
        static int size;
        static int rear;
        static int front;//In circular queue front remains changing
        CircularQ(int size){
            arr=new int[size];
            this.size=size;
            rear=-1;
            front=-1;
        }
        public static boolean isEmpty(){
            if(rear==front && front==-1){
                return true;
            }
            return false;
        }
        public static boolean isFull(){
            if((rear+1)%size==front){
                return true;
            }
            //we want to look next to rear to add elment but there is front at that position
            return false;
        }
        public static void add(int val){
            if(isFull()){
                System.out.println("Queue is full");
                return ;
            }
            if(front==-1){//Adding first element in queue
                //update the front also
                front=0;
            }
            rear=(rear+1)%size;
            arr[rear]=val;
        }
        public static int remove(){//O(1)
            if(isEmpty()){
                System.out.println("Queue is Empty");
                return -1;
            }
            int val=arr[front];
            //if we are at last element
            //front==rear
            if(rear==front){
                //queue will became empty
                rear=front=-1;
            }
            else{
                front=(front+1)%size;
            }
            return val;

        }
            public static int peek(){
                if(isEmpty()){
                    System.out.println("Empty Queue");
                    return -1;
                }
                return arr[front];

            }

    }
    public static void main(String args[]){
        //Queue using array:-has 2 pointers front and rear
        //Suppose there is normal queue with 8 size of array with 8 elements
        //Removing element from queue implemented using array is O(1)
        //But circular queue was brought in game to reduce this time complexity of O(n) for removing
        //In normal queue using array if element removed from first, all the further elements have to be shifted by one place in left side
        //But in circular queue , No need to shift other elements just , exceed the value of front by 1
        //front will point to next element
        //1 2 3 f=0 r=2
        //remove
        //_ 2 3 f=1 r=0-> we have vacant space in front 
        //but we can add elment only at rear .Hence shift rear pointer to empty spaece
        //using formula rear=(rear+1)%size
        //rear=(rear+1)%size will only kept this in mind if rear is in last positon ,if incremented it has to point to zero
        //remove
        //_ _ 3 f=2 r=0
        //Add 9 -> 9 _ 3 ->f=2 r=0
        //Add 7 -> 9 7 3 ->f=2 r=1
        //to remove element from front remove it from last positon of array
        //but change it to zero using formula front=(front+1)%size
        //9 7 _ ->f=0 r=1
        CircularQ q=new CircularQ(3);
        q.add(1);
        q.add(2);
        q.add(3);
        System.out.println(q.remove());
        q.add(4);
        System.out.println(q.remove());
        q.add(5);
        System.out.println(q.remove());
        System.out.println(q.remove());
        System.out.println(q.remove());
        
        
    }
}