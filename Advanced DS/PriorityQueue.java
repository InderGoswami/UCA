public class PriorityQueue{
    private Integer[] pq;
    private int n;//By default java will intialize this n with zero
    PriorityQueue(int capacity){
        this.pq=new Integer[capacity+1];

    }
    private void swim(int k){
        while(k>1 &&  pq[k/2]<pq[k]){//we have reached top 
            exch(k,k/2);
            k=k/2;//1 based indexing

        }
    }
    private void exch(int i,int j){
        int temp=this.pq[i];
        this.pq[i]=this.pq[j];
        this.pq[j]=temp;
    }
    public void insert(int x){
        this.pq[++n]=x;
        swim(n);//only passing the index where we have added element

    }
    private void sink(int k){
        while(2*k<=n){//2*k child index
            int j=2*k;
            if(j<n && this.pq[j]<this.pq[j+1]){ //j<n right child available
                j++;
            }
            if(this.pq[k]>=this.pq[j])break;
            exch(k,j);
            k=j;

        }
    }

    public Integer demax(){
        if(isEmpty()){
            return null;
        }
        int maxEle=this.pq[1];
        exch(1,n--);
        sink(1);
        this.pq[n+1]=null;//loitering
        return maxEle;

    }
    public boolean isEmpty(){
        return this.n==0;
    }
    public Integer size(){
        return this.n;

    }
    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue(10);
        pq.insert(5);
        pq.insert(10);
        pq.insert(3);
        System.out.println("Max element: " + pq.demax()); // Should print 10
        System.out.println("Max element: " + pq.demax()); // Should print 5
        System.out.println("Max element: " + pq.demax()); // Should print 3
        System.out.println("Is empty: " + pq.isEmpty()); // Should print true
    }
}