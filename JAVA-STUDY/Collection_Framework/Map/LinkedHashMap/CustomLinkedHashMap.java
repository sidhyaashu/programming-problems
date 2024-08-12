package Collection_Framework.Map.LinkedHashMap;

import java.util.*;

public class CustomLinkedHashMap<K, V> {
    private HashMap<K, V> map;
    private LinkedList<K> order;

    // Constructor to initialize the CustomLinkedHashMap
    public CustomLinkedHashMap() {
        this.map = new HashMap<>();
        this.order = new LinkedList<>();
    }

    // Put method to insert a key-value pair into the CustomLinkedHashMap
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

    // Remove method to delete a key-value pair from the CustomLinkedHashMap
    public void remove(K key) {
        if (map.containsKey(key)) {
            order.remove(key);
            map.remove(key);
        }
    }

    // Check if the CustomLinkedHashMap contains a given key
    public boolean containsKey(K key) {
        return map.containsKey(key);
    }

    // Check if the CustomLinkedHashMap is empty
    public boolean isEmpty() {
        return map.isEmpty();
    }

    // Get the size of the CustomLinkedHashMap
    public int size() {
        return map.size();
    }

    // Display the CustomLinkedHashMap in the insertion order
    public void display() {
        for (K key : order) {
            System.out.println(key + ": " + map.get(key));
        }
    }

    // Sorting method to sort the CustomLinkedHashMap by keys (Ascending Order)
    public List<Map.Entry<K, V>> sortByKeyAscending() {
        List<Map.Entry<K, V>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<K, V>>() {
            public int compare(Map.Entry<K, V> o1, Map.Entry<K, V> o2) {
                return o1.getKey().compareTo(o2.getKey());
            }
        });
        return list;
    }

    // Sorting method to sort the CustomLinkedHashMap by keys (Descending Order)
    public List<Map.Entry<K, V>> sortByKeyDescending() {
        List<Map.Entry<K, V>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<K, V>>() {
            public int compare(Map.Entry<K, V> o1, Map.Entry<K, V> o2) {
                return o2.getKey().compareTo(o1.getKey());
            }
        });
        return list;
    }

    // Searching method to search for a key in the CustomLinkedHashMap
    public boolean searchKey(K key) {
        return map.containsKey(key);
    }

    // Searching method to search for a value in the CustomLinkedHashMap
    public boolean searchValue(V value) {
        return map.containsValue(value);
    }

    public static void main(String[] args) {
        // Creating a CustomLinkedHashMap
        CustomLinkedHashMap<String, Integer> customLinkedHashMap = new CustomLinkedHashMap<>();

        // Inserting key-value pairs
        customLinkedHashMap.put("apple", 10);
        customLinkedHashMap.put("banana", 20);
        customLinkedHashMap.put("cherry", 30);

        // Displaying key-value pairs in insertion order
        System.out.println("CustomLinkedHashMap:");
        customLinkedHashMap.display();

        // Retrieving values
        System.out.println("Value associated with 'banana': " + customLinkedHashMap.get("banana"));

        // Removing a key-value pair
        customLinkedHashMap.remove("banana");

        // Checking if the CustomLinkedHashMap contains a key
        System.out.println("Does CustomLinkedHashMap contain 'banana'? " + customLinkedHashMap.containsKey("banana"));

        // Checking if the CustomLinkedHashMap is empty
        System.out.println("Is CustomLinkedHashMap empty? " + customLinkedHashMap.isEmpty());

        // Getting the size of the CustomLinkedHashMap
        System.out.println("Size of CustomLinkedHashMap: " + customLinkedHashMap.size());

        // Sorting keys in ascending order
        System.out.println("Sorted keys (Ascending Order): " + customLinkedHashMap.sortByKeyAscending());

        // Sorting keys in descending order
        System.out.println("Sorted keys (Descending Order): " + customLinkedHashMap.sortByKeyDescending());

        // Searching for a key
        System.out.println("Is 'apple' present in the CustomLinkedHashMap? " + customLinkedHashMap.searchKey("apple"));

        // Searching for a value
        System.out.println("Is value '30' present in the CustomLinkedHashMap? " + customLinkedHashMap.searchValue(30));
    }
}
