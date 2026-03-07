#pragma once
#include "types.h"

void createNewFile();
DishData readFromFile(int index, const char* filename = FILENAME);
int getRecordCount(const char* filename = FILENAME);
void appendToFile(const DishData& data);
void removeFromFile(int index);
