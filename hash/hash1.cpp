void put(int key, int value) {
    // 1. Compute the index using the hash function
    int index = hashFunction(key, capacity);

    // 2. Check if the key exists in the linked list at the index, update if found
    Entry* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value; // Update value
            return; // Exit, no need to insert or rehash
        }
        current = current->next;
    }

    // 3. If the key doesn't exist, create and insert a new entry
    // Note: Always use 'new' for dynamic allocation
    // Insert at head (LIFO) is O(1)
    Entry* newEntry = new Entry(key, value, table[index]);
    table[index] = newEntry;

    // 4. Increment the count and ensure load factor by resizing if needed
    count++;
    ensureLoadFactor(count); // Pass current count to check against capacity
}

void ensureLoadFactor(int current_size) {
    // 1. Calculate the maximum allowed size based on the load factor (0.75 * capacity)
    int maxSize = (int)(capacity * 0.75);

    // 2. If the current size exceeds or equals the max allowed size, trigger rehashing
    if (current_size > maxSize) {
        // 3. Calculate the new capacity (1.5 times the old capacity)
        int newCap = (int)(capacity * 1.5);
        
        // 4. Call the rehash function with the new capacity
        rehash(newCap);
    }
}

void rehash(int newCapacity) {
    // 1. Store the current table and capacity
    Entry** oldTable = table;
    int oldCapacity = capacity;

    // 2. Create a new table with the new capacity and update the capacity
    capacity = newCapacity;
    table = new Entry*[newCapacity];

    // 3. Initialize the new table with nullptr values
    for (int i = 0; i < newCapacity; i++) {
        table[i] = nullptr;
    }

    // 4. For each index in the old table:
    for (int i = 0; i < oldCapacity; i++) {
        Entry* current = oldTable[i];
        
        // Traverse the linked list at that index
        while (current != nullptr) {
            // Recompute the new index for each entry using the new capacity
            int newIndex = hashFunction(current->key, newCapacity);

            // Insert the entry into the new table at the recomputed index
            // (Create a COPY of the node to put into the new table)
            Entry* newEntry = new Entry(current->key, current->value, table[newIndex]);
            table[newIndex] = newEntry;

            current = current->next;
        }
    }

    // 5. Delete all entries in the old table by traversing each linked list and deleting nodes
    for (int i = 0; i < oldCapacity; i++) {
        Entry* current = oldTable[i];
        while (current != nullptr) {
            Entry* prev = current;
            current = current->next;
            delete prev; // Delete the old node
        }
    }

    // 6. Delete the old table array
    delete[] oldTable;
}