#include <iostream>
#include "linked_list_hash.h"
#include "utils.h"

const int M = 10;

void promptAndInsertNewPerson(PersonData** hashTable) {
	char surname[SURNAME_SIZE] { '\0' }, address[ADDRESS_SIZE] {'\0' };
	int phoneNumber;

	print("Initializing new person");

	print("Input surname: ", '\0');
	input(surname);

	print("Input address: ", '\0');
	input(address);

	print("Input phone number: ", '\0');
	input(phoneNumber);

	PersonData data;
	strcpy(data.surname, surname);
	strcpy(data.address, address);
	data.phoneNumber = phoneNumber;

	insert(data, hashTable);
	print("Success!");
}

void printPerson(PersonData data) {
	print("Surname: ", '\0');
	print(data.surname);
	print("Phone number: ", '\0');
	print(data.phoneNumber);
	print("Address: ", '\0');
	print(data.address);
}

void findAndPrintPerson(int phoneNumber, PersonData** hashTable) {
	PersonData* foundData = find(phoneNumber, hashTable);

	print("---");

	if (foundData == nullptr) {
		print("Not found...");
	}
	else
	{
		printPerson(*foundData);
	}

	print("---");
}

PersonData** initHashtable(int n) {
	PersonData** hashTable = new PersonData * [M]();

	for (int i = 0; i < n; i++)
	{
		promptAndInsertNewPerson(hashTable);
	}

	return hashTable;
}

void printHashtable(PersonData** hashTable, int size) {
	for (int i = 0; i < size; i++)
	{
		print("Bucket ", '\0');
		print(i);
		
		PersonData* bucket = hashTable[i];
		if (bucket == nullptr) {
			print("Empty...");
		}
		else {
			do
			{
				printPerson(*bucket);
				bucket = bucket->next;
			} while (bucket != nullptr);
		}
		print();
	}
}

void displayMenu() {
	print("--- Hash table of people data ---");
	print("1 - insert new person");
	print("2 - find by phone number");
	print("3 - print hash table");
	print("0 - exit");
	print(": ", '\0');
}

int main()
{
	int n, choice = -1;

	print("Input n(number of people): ", '\0');
	input(n);

	PersonData** hashTable = initHashtable(n);

	do
	{
		displayMenu();
		input(choice);

		switch (choice)
		{
			case 1:
				promptAndInsertNewPerson(hashTable);
				break;
			case 2:
				print("Input target phone number: ", '\0');
				int phoneNumber;
				input(phoneNumber);
				findAndPrintPerson(phoneNumber, hashTable);
				break;
			case 3:
				printHashtable(hashTable, M);
				break;
			case 0:
				print("Exiting...");
				break;
			default:
				print("Bad choice!");
				break;
		}
	} while (choice != 0);

	// memory clearing
	for (int i = 0; i < M; i++)
	{
		PersonData* curr = hashTable[i];
		PersonData* next = curr->next;

		while (next != nullptr)
		{
			delete curr;
			curr = next;
			next = next->next;
		}
	}
}
