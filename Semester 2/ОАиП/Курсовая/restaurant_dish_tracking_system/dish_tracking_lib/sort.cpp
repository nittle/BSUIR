#include "sort.h"
#include "core.h"
#include <fstream>
#include <cstring>

void swapDishesInFile(int index1, int index2, const char* filename) {
  if (index1 == index2) return;

  DishData d1 = readFromFile(index1, filename);
  DishData d2 = readFromFile(index2, filename);

  std::fstream str(filename, std::ios::in | std::ios::out | std::ios::binary);
  if (!str.is_open()) return;

  str.seekp(index1 * sizeof(DishData), std::ios::beg);
  str.write(reinterpret_cast<const char *>(&d2), sizeof(DishData));

  str.seekp(index2 * sizeof(DishData), std::ios::beg);
  str.write(reinterpret_cast<const char *>(&d1), sizeof(DishData));

  str.close();
}

void bubbleSortByCost(const char* filename) {
  int count = getRecordCount(filename);
  for (int i = 0; i < count - 1; ++i) {
    for (int j = 0; j < count - i - 1; ++j) {
      DishData current = readFromFile(j, filename);
      DishData next = readFromFile(j + 1, filename);
      
      if (current.cost > next.cost) {
        swapDishesInFile(j, j + 1, filename);
      }
    }
  }
}

void selectionSortByCalories(const char* filename) {
  int count = getRecordCount(filename);
  for (int i = 0; i < count - 1; ++i) {
    int minIndex = i;
    DishData minDish = readFromFile(i, filename);

    for (int j = i + 1; j < count; ++j) {
      DishData currentDish = readFromFile(j, filename);
      if (currentDish.calories < minDish.calories) {
        minIndex = j;
        minDish = currentDish;
      }
    }

    if (minIndex != i) {
      swapDishesInFile(i, minIndex, filename);
    }
  }
}

void insertionSortByName(const char* filename) {
  int count = getRecordCount(filename);
  std::fstream str(filename, std::ios::in | std::ios::out | std::ios::binary);
  if (!str.is_open()) return;

  for (int i = 1; i < count; ++i) {
    DishData keyDish = readFromFile(i, filename);
    int j = i - 1;

    DishData jDish = readFromFile(j, filename);
    // Continue shifting as long as j is valid and j's name is alphabetically greater than key's name
    while (j >= 0 && std::strcmp(jDish.name, keyDish.name) > 0) {
      str.seekp((j + 1) * sizeof(DishData), std::ios::beg);
      str.write(reinterpret_cast<const char *>(&jDish), sizeof(DishData));
      
      j--;
      if (j >= 0) {
        jDish = readFromFile(j, filename);
      }
    }
    
    // Insert the key into its correct position
    str.seekp((j + 1) * sizeof(DishData), std::ios::beg);
    str.write(reinterpret_cast<const char *>(&keyDish), sizeof(DishData));
  }
  str.close();
}
