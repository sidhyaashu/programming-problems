package Collection_Framework.Map.HashTable;


import java.util.ArrayList;
import java.util.LinkedList;

public class CustomHashTable<K, V> {
    private static final int DEFAULT_CAPACITY = 10;
    private LinkedList<Entry<K, V>>[] table;
    private int capacity;
    private int size;

    // Constructor to initialize the HashTable
    public CustomHashTable(int capacity) {
        this.capacity = capacity;
        this.table = new LinkedList[capacity];
        this.size = 0;
    }

    // Entry class for key-value pairs
    private static class Entry<K, V> {
        K key;
        V value;

        Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    // Hash function to get index for a given key
    private int hash(K key) {
        return Math.abs(key.hashCode()) % capacity;
    }

    // Put method to insert a key-value pair into the HashTable
    public void put(K key, V value) {
        int index = hash(key);
        if (table[index] == null) {
            table[index] = new LinkedList<>();
        }
        for (Entry<K, V> entry : table[index]) {
            if (entry.key.equals(key)) {
                entry.value = value;
                return;
            }
        }
        table[index].add(new Entry<>(key, value));
        size++;
    }

    // Get method to retrieve the value associated with a key
    public V get(K key) {
        int index = hash(key);
        if (table[index] != null) {
            for (Entry<K, V> entry : table[index]) {
                if (entry.key.equals(key)) {
                    return entry.value;
                }
            }
        }
        return null;
    }

    // Remove method to delete a key-value pair from the HashTable
    public void remove(K key) {
        int index = hash(key);
        if (table[index] != null) {
            for (Entry<K, V> entry : table[index]) {
                if (entry.key.equals(key)) {
                    table[index].remove(entry);
                    size--;
                    return;
                }
            }
        }
    }

    // Check if the HashTable contains a given key
    public boolean containsKey(K key) {
        int index = hash(key);
        if (table[index] != null) {
            for (Entry<K, V> entry : table[index]) {
                if (entry.key.equals(key)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Check if the HashTable is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Get the size of the HashTable
    public int size() {
        return size;
    }

    // Sorting method to sort the HashTable by keys
    public ArrayList<K> sortKeys() {
        ArrayList<K> keys = new ArrayList<>();
        for (LinkedList<Entry<K, V>> entries : table) {
            if (entries != null) {
                for (Entry<K, V> entry : entries) {
                    keys.add(entry.key);
                }
            }
        }
        keys.sort(null);
        return keys;
    }

    // Searching method to search for a key in the HashTable
    public boolean searchKey(K key) {
        return containsKey(key);
    }

    public static void main(String[] args) {
        // Creating a HashTable with capacity 10
        CustomHashTable<String, Integer> hashTable = new CustomHashTable<>(DEFAULT_CAPACITY);

        // Inserting key-value pairs
        hashTable.put("apple", 10);
        hashTable.put("banana", 20);
        hashTable.put("cherry", 30);

        // Retrieving values
        System.out.println("Value associated with 'apple': " + hashTable.get("apple"));
        System.out.println("Value associated with 'banana': " + hashTable.get("banana"));

        // Removing a key-value pair
        hashTable.remove("banana");

        // Checking if the HashTable contains a key
        System.out.println("Does HashTable contain 'banana'? " + hashTable.containsKey("banana"));

        // Checking if the HashTable is empty
        System.out.println("Is HashTable empty? " + hashTable.isEmpty());

        // Getting the size of the HashTable
        System.out.println("Size of HashTable: " + hashTable.size());

        // Sorting keys
        ArrayList<String> sortedKeys = hashTable.sortKeys();
        System.out.println("Sorted keys: " + sortedKeys);

        // Searching for a key
        System.out.println("Is 'apple' present in the HashTable? " + hashTable.searchKey("apple"));
    }
}
