#pragma once

#include "constants.h"

enum Meal { Breakfast, Lunch, Dinner };

struct DishData {
  char name[MAX_DISH_NAME_SIZE];
  int cost;
  int calories;
  bool isVegetarian;
  bool isSpicy;
  Meal mealType;
};
