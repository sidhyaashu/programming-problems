package Collection_Framework.Map.HashMap;

import java.util.*;

public class CustomHashMap<K, V> {
    private static final int DEFAULT_CAPACITY = 16;
    private static final double LOAD_FACTOR = 0.75;

    private int size;
    private int capacity;
    private List<Entry<K, V>>[] buckets;

    public CustomHashMap() {
        this(DEFAULT_CAPACITY);
    }

    public CustomHashMap(int initialCapacity) {
        this.capacity = initialCapacity;
        this.size = 0;
        this.buckets = new LinkedList[capacity];
    }

    private static class Entry<K, V> {
        K key;
        V value;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    public void put(K key, V value) {
        int index = getIndex(key);
        if (buckets[index] == null) {
            buckets[index] = new LinkedList<>();
        }
        for (Entry<K, V> entry : buckets[index]) {
            if (entry.key.equals(key)) {
                entry.value = value;
                return;
            }
        }
        buckets[index].add(new Entry<>(key, value));
        size++;
        if ((double)size / capacity > LOAD_FACTOR) {
            resize();
        }
    }

    public V get(K key) {
        int index = getIndex(key);
        if (buckets[index] != null) {
            for (Entry<K, V> entry : buckets[index]) {
                if (entry.key.equals(key)) {
                    return entry.value;
                }
            }
        }
        return null;
    }

    public void remove(K key) {
        int index = getIndex(key);
        if (buckets[index] != null) {
            Iterator<Entry<K, V>> iterator = buckets[index].iterator();
            while (iterator.hasNext()) {
                Entry<K, V> entry = iterator.next();
                if (entry.key.equals(key)) {
                    iterator.remove();
                    size--;
                    return;
                }
            }
        }
    }

    private int getIndex(K key) {
        return Math.abs(key.hashCode()) % capacity;
    }

    private void resize() {
        capacity *= 2;
        List<Entry<K, V>>[] newBuckets = new LinkedList[capacity];
        for (List<Entry<K, V>> bucket : buckets) {
            if (bucket != null) {
                for (Entry<K, V> entry : bucket) {
                    int index = getIndex(entry.key);
                    if (newBuckets[index] == null) {
                        newBuckets[index] = new LinkedList<>();
                    }
                    newBuckets[index].add(entry);
                }
            }
        }
        buckets = newBuckets;
    }

    public void display() {
        System.out.println("CustomHashMap:");
        for (List<Entry<K, V>> bucket : buckets) {
            if (bucket != null) {
                for (Entry<K, V> entry : bucket) {
                    System.out.println("Key: " + entry.key + ", Value: " + entry.value);
                }
            }
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public static void main(String[] args) {
        CustomHashMap<String, Integer> customHashMap = new CustomHashMap<>();
        
        // Insertion
        customHashMap.put("John", 25);
        customHashMap.put("Alice", 30);
        customHashMap.put("Bob", 28);

        // Retrieval
        System.out.println("Age of John: " + customHashMap.get("John"));

        // Deletion
        customHashMap.remove("Bob");

        // Displaying HashMap
        customHashMap.display();

        // Additional Operation: Checking if the HashMap is empty
        System.out.println("Is CustomHashMap empty? " + customHashMap.isEmpty());

        // Advanced Operation: Iterating over entries
        System.out.println("Iterating over CustomHashMap:");
        for (List<Entry<String, Integer>> bucket : customHashMap.buckets) {
            if (bucket != null) {
                for (Entry<String, Integer> entry : bucket) {
                    System.out.println("Key: " + entry.key + ", Value: " + entry.value);
                }
            }
        }
    }
}
