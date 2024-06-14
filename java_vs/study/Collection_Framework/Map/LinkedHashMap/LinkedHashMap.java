package Collection_Framework.Map.LinkedHashMap;

import java.util.HashMap;
import java.util.LinkedList;

public class LinkedHashMap<K, V> {
    private HashMap<K, V> map;
    private LinkedList<K> order;

    // Constructor to initialize the LinkedHashMap
    public LinkedHashMap() {
        this.map = new HashMap<>();
        this.order = new LinkedList<>();
    }

    // Put method to insert a key-value pair into the LinkedHashMap
    public void put(K key, V value) {
        if (!map.containsKey(key)) {
            order.add(key);
        }
        map.put(key, value);
    }

    // Get method to retrieve the value associated with a key
    public V get(K key) {
        return map.get(key);
    }

    // Remove method to delete a key-value pair from the LinkedHashMap
    public void remove(K key) {
        if (map.containsKey(key)) {
            order.remove(key);
            map.remove(key);
        }
    }

    // Check if the LinkedHashMap contains a given key
    public boolean containsKey(K key) {
        return map.containsKey(key);
    }

    // Check if the LinkedHashMap is empty
    public boolean isEmpty() {
        return map.isEmpty();
    }

    // Get the size of the LinkedHashMap
    public int size() {
        return map.size();
    }

    // Display the LinkedHashMap in the insertion order
    public void display() {
        for (K key : order) {
            System.out.println(key + ": " + map.get(key));
        }
    }

    public static void main(String[] args) {
        // Creating a LinkedHashMap
        LinkedHashMap<String, Integer> linkedHashMap = new LinkedHashMap<>();

        // Inserting key-value pairs
        linkedHashMap.put("apple", 10);
        linkedHashMap.put("banana", 20);
        linkedHashMap.put("cherry", 30);

        // Displaying key-value pairs in insertion order
        System.out.println("LinkedHashMap:");
        linkedHashMap.display();

        // Retrieving values
        System.out.println("Value associated with 'banana': " + linkedHashMap.get("banana"));

        // Removing a key-value pair
        linkedHashMap.remove("banana");

        // Checking if the LinkedHashMap contains a key
        System.out.println("Does LinkedHashMap contain 'banana'? " + linkedHashMap.containsKey("banana"));

        // Checking if the LinkedHashMap is empty
        System.out.println("Is LinkedHashMap empty? " + linkedHashMap.isEmpty());

        // Getting the size of the LinkedHashMap
        System.out.println("Size of LinkedHashMap: " + linkedHashMap.size());
    }
}

