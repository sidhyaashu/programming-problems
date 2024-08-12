/*
put(key, value): Adds a key-value pair to the HashMap.
get(key): Retrieves the value associated with the specified key.
size(): Returns the number of key-value mappings in the HashMap.
containsKey(key): Checks if the HashMap contains a mapping for the specified key.
containsValue(value): Checks if the HashMap maps one or more keys to the specified value.
remove(key): Removes the mapping for the specified key from the HashMap.
keySet(): Returns a Set view of the keys contained in the HashMap.
clear(): Removes all of the mappings from the HashMap.
isEmpty(): Returns true if the HashMap contains no key-value mappings.
 */

package Collection_Framework.Map.HashMap;

import java.util.HashMap;

public class HashMapDemo {

    public static void main(String[] args) {
        // Creating a HashMap
        HashMap<String, Integer> hashMap = new HashMap<>();

        // Adding elements to the HashMap
        hashMap.put("John", 25);
        hashMap.put("Alice", 30);
        hashMap.put("Bob", 28);

        // Displaying the HashMap
        System.out.println("HashMap: " + hashMap);

        // Getting the size of the HashMap
        System.out.println("Size of HashMap: " + hashMap.size());

        // Accessing a value using a key
        System.out.println("Age of John: " + hashMap.get("John"));

        // Checking if a key exists
        System.out.println("Does Alice exist? " + hashMap.containsKey("Alice"));

        // Checking if a value exists
        System.out.println("Is age 28 present? " + hashMap.containsValue(28));

        // Removing an entry from the HashMap
        hashMap.remove("Bob");
        System.out.println("HashMap after removing Bob: " + hashMap);

        // Iterating over the HashMap
        System.out.println("Iterating over HashMap:");
        for (String key : hashMap.keySet()) {
            System.out.println("Key: " + key + ", Value: " + hashMap.get(key));
        }

        // Clearing the HashMap
        hashMap.clear();
        System.out.println("HashMap after clearing: " + hashMap);

        // Checking if the HashMap is empty
        System.out.println("Is HashMap empty? " + hashMap.isEmpty());
    }
}

