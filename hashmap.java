
public class hashmap{
     private static class Node{
           String key;
           int value;
           Node next;

        //    ponter to the next node in case of collision

           Node(String key,int value){
            this.key =key;
            this.value =value;
            this.next = null; 
        }
    }

    // declaring the bucket and intializing the size

    private Node[] buckets;
    private final int size=10;

    public hashmap(){
        buckets = new Node[size];
    }
    // hashfunction
    private int getBucketIndex(String key){

        // hashCode() is a built-in Java tool that turns any string into a safe integer math number
        int hashcode =key.hashCode();

    //  absolute value prevent negative index

        return Math.abs(hashcode)%size;

    }
// put operation
    private void put(String key,int value){
        int bucketIndex =getBucketIndex(key);
        Node head = buckets[bucketIndex];

        // check if chain already exists or not

        Node temp = head;
        while(temp!=null){
        if(temp.key.equals(key)){
            temp.value=value;
            return;
        }
        temp =temp.next;
        }
        // key doesnot exist then insert a new  node
        Node newNode = new Node(key, value);
        buckets[bucketIndex]= newNode;
        System.out.println("(" + key + " -> " + value + ")"+ bucketIndex);
    }
    // get operation
    public Integer get(String key){
        int bucketIndex = getBucketIndex(key);
        Node head = buckets[bucketIndex];

        // Traverse the specific bucket chain to locate the string matching key
        Node temp = head;
        while (temp != null) {
            if (temp.key.equals(key)) {
                return temp.value; // Key found, return the integer value!
            }
            temp = temp.next;
        }

        // Key does not exist in our hashmap
        return null; 
    }

    // Main execution point to try it out
    public static void main(String[] args) {
        hashmap map = new hashmap();

        System.out.println("--- Executing Custom Put Operations ---");
        map.put("Amrutha", 95);
        map.put("Rahul", 88);
        map.put("Jessica", 100);
        map.put("Amrutha", 99); // Testing update mechanism on an existing key

        System.out.println("\n--- Executing Custom Get Operations ---");
        System.out.println("Result for 'Amrutha': " + map.get("Amrutha"));
        System.out.println("Result for 'Rahul': " + map.get("Rahul"));
        System.out.println("Result for missing key 'Peter': " + map.get("Peter"));
    }
}
    


