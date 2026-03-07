#include "linked_list_hash.h"

int hash(int key) {
	return key % 10;
}

void insert(PersonData data, PersonData** hashTable) {
	int hashIndex = hash(data.phoneNumber);

	PersonData* current = hashTable[hashIndex];

	if (current == nullptr) {
		hashTable[hashIndex] = new PersonData(data);
	}
	else {
		while (current->next != nullptr)
			current = current->next;
		current->next = new PersonData(data);
	}
}

PersonData* find(int key, PersonData** hashTable) {
	int hashIndex = hash(key);

	PersonData* found = hashTable[hashIndex];

	while (found->next != nullptr && found->phoneNumber != key)
		found = found->next;

	return found;
}