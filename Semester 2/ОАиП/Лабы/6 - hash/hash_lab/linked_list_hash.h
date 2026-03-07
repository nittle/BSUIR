#pragma once

int const SURNAME_SIZE = 30;
int const ADDRESS_SIZE = 100;

struct PersonData {
	char surname[SURNAME_SIZE] { '\0' };
	char address[ADDRESS_SIZE] { '\0' };
	int phoneNumber;
	PersonData* next = nullptr;
};

int hash(int key);
void insert(PersonData data, PersonData** hashTable);
PersonData* find(int key, PersonData** hashTable);