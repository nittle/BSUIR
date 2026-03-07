#include "search.h"
#include "core.h"
#include "sort.h"
#include <cstring>
#include <fstream>

int linearSearchByName(const char *targetName) {
  int count = getRecordCount(FILENAME);
  for (int i = 0; i < count; ++i) {
    DishData d = readFromFile(i, FILENAME);
    if (std::strcmp(d.name, targetName) == 0) {
      return i;
    }
  }
  return -1;
}

int binarySearchByCalories(int targetCalories) {
  int count = getRecordCount(FILENAME);
  if (count <= 0)
    return -1;

  int left = 0;
  int right = count - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    DishData midDish = readFromFile(mid, FILENAME);

    if (midDish.calories == targetCalories) {
      return mid;
    }

    if (midDish.calories < targetCalories) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

Meal determineMealType(int time) {
  if (time >= 6 && time <= 11)
    return Meal::Breakfast;
  if (time >= 12 && time <= 16)
    return Meal::Lunch;
  return Meal::Dinner;
}

int getSuitableDishes(int time, bool wantSpicy, bool wantVegetarian) {
  Meal targetMeal = determineMealType(time);

  int totalDishes = getRecordCount(FILENAME);

  // Truncate the temp file to ensure it's empty
  std::fstream tempStr(TEMP_FILENAME,
                       std::ios::out | std::ios::binary | std::ios::trunc);
  if (!tempStr.is_open())
    return 0;

  int matchCount = 0;
  for (int i = 0; i < totalDishes; ++i) {
    DishData d = readFromFile(i, FILENAME);

    // Filter by Meal
    if (d.mealType != targetMeal)
      continue;

    // Filter by Vegetarian (Strict if wantVegetarian is true)
    if (wantVegetarian && !d.isVegetarian)
      continue;

    // Filter by Spicy (Strict if wantSpicy is false)
    if (!wantSpicy && d.isSpicy)
      continue;

    // If it passes all filters, write to temp file
    tempStr.write(reinterpret_cast<const char *>(&d), sizeof(DishData));
    matchCount++;
  }
  tempStr.close();

  // Sort the temp file
  if (matchCount > 1) {
    selectionSortByCalories(TEMP_FILENAME);
  }

  return matchCount;
}

int getDishesByMealType(Meal mealType) {
  int totalDishes = getRecordCount(FILENAME);

  // Truncate the temp file
  std::fstream tempStr(TEMP_FILENAME, std::ios::out | std::ios::binary | std::ios::trunc);
  if (!tempStr.is_open()) return 0;

  int matchCount = 0;
  for (int i = 0; i < totalDishes; ++i) {
    DishData d = readFromFile(i, FILENAME);

    if (d.mealType != mealType) continue;

    tempStr.write(reinterpret_cast<const char*>(&d), sizeof(DishData));
    matchCount++;
  }
  tempStr.close();

  // Sort alphabetically by name
  if (matchCount > 1) {
    insertionSortByName(TEMP_FILENAME);
  }

  return matchCount;
}
