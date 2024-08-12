import java.util.ArrayList;

class CustomHashSet<T> {
    private ArrayList<T>[] buckets;
    private int capacity;
    private int size;
    private static final int DEFAULT_CAPACITY = 16;
    private static final double LOAD_FACTOR = 0.75;

    @SuppressWarnings("unchecked")
    public CustomHashSet() {
        this.capacity = DEFAULT_CAPACITY;
        this.buckets = new ArrayList[capacity];
        for (int i = 0; i < capacity; i++) {
            buckets[i] = new ArrayList<>();
        }
        this.size = 0;
    }

    public boolean add(T element) {
        if (contains(element))
            return false;

        if ((double) (size + 1) / capacity > LOAD_FACTOR) {
            resize();
        }

        int index = hash(element);
        buckets[index].add(element);
        size++;
        return true;
    }

    public boolean contains(T element) {
        int index = hash(element);
        return buckets[index].contains(element);
    }

    public boolean remove(T element) {
        int index = hash(element);
        boolean removed = buckets[index].remove(element);
        if (removed) {
            size--;
            return true;
        }
        return false;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private void resize() {
        capacity *= 2;
        ArrayList<T>[] oldBuckets = buckets;
        buckets = new ArrayList[capacity];
        for (int i = 0; i < capacity; i++) {
            buckets[i] = new ArrayList<>();
        }
        for (ArrayList<T> bucket : oldBuckets) {
            for (T element : bucket) {
                int index = hash(element);
                buckets[index].add(element);
            }
        }
    }

    private int hash(T element) {
        return Math.abs(element.hashCode()) % capacity;
    }
}

public class CustomHashSetExample {
    public static void main(String[] args) {
        CustomHashSet<String> customHashSet = new CustomHashSet<>();

        // Adding elements
        customHashSet.add("Apple");
        customHashSet.add("Banana");
        customHashSet.add("Orange");

        // Displaying elements
        System.out.println("Custom HashSet elements: " + customHashSet);

        // Size of the HashSet
        System.out.println("Size of Custom HashSet: " + customHashSet.size());

        // Checking if the HashSet is empty
        System.out.println("Is Custom HashSet empty? " + customHashSet.isEmpty());

        // Adding duplicate element
        customHashSet.add("Apple");
        System.out.println("Custom HashSet after adding duplicate element: " + customHashSet);

        // Removing an element
        customHashSet.remove("Banana");
        System.out.println("Custom HashSet after removing 'Banana': " + customHashSet);

        // Checking if an element is present
        System.out.println("Is 'Apple' present in Custom HashSet? " + customHashSet.contains("Apple"));
    }
}

