#include "cli.h"
#include "dish_tracking_lib/constants.h"
#include "dish_tracking_lib/core.h"
#include "dish_tracking_lib/search.h"
#include "dish_tracking_lib/sort.h"
#include "dish_tracking_lib/types.h"
#include "utils.h"

void printDishData(const DishData& data, int index = -1) {
  if (index >= 0) {
    print("--- Dish #", '\0');
    print(index, '\0');
    print(" ---");
  }

  print("Name: ", '\0');
  print(data.name);

  print("Cost ($): ", '\0');
  print(data.cost);

  print("Calories: ", '\0');
  print(data.calories);

  print("Is Vegetarian? ", '\0');
  print(data.isVegetarian ? "Yes" : "No");

  print("Is Spicy? ", '\0');
  print(data.isSpicy ? "Yes" : "No");

  print("Meal Type: ", '\0');
  if (data.mealType == Meal::Breakfast)
    print("Breakfast");
  else if (data.mealType == Meal::Lunch)
    print("Lunch");
  else if (data.mealType == Meal::Dinner)
    print("Dinner");
  else
    print("Unknown");
  print(); // Extra newline for spacing
}

void startCLI() {
  int choice = -1;

  while (choice != 0) {
    print("==========================");
    print("1. Create new file (Wipes database)");
    print("2. Get all dishes names with their indices");
    print("3. Get all dish info at specific index");
    print("4. Remove dish at specific index");
    print("5. Add dish to file");
    print("6. Find dish by name (linear search)");
    print("7. Find dish by calories (binary search)");
    print("8. Sort database by cost (Bubble Sort)");
    print("9. Sort database by calories (Selection Sort)");
    print("10. Sort database by name (Insertion Sort)");
    print("11. Look for a suitable dish");
    print("12. Print full menu");
    print("0. Exit");
    print("==========================");
    print("Enter choice: ", '\0');
    input(choice);

    switch (choice) {
    case 1: {
      createNewFile();
      print("New file created. Database is now empty.");
      break;
    }
    case 2: {
      int count = getRecordCount();
      if (count == 0) {
        print("No dishes found in the database.");
      } else {
        print("--- Dish List ---");
        for (int i = 0; i < count; ++i) {
          DishData d = readFromFile(i);
          print(i, '\0');
          print(". ", '\0');
          print(d.name);
        }
      }
      break;
    }
    case 3: {
      print("Enter dish index: ", '\0');
      int index;
      input(index);
      int count = getRecordCount();

      if (index >= 0 && index < count) {
        DishData d = readFromFile(index);
        printDishData(d);
      } else {
        print("Error: Invalid index.");
      }
      break;
    }
    case 4: {
      print("Enter dish index to remove: ", '\0');
      int index;
      input(index);
      int count = getRecordCount();

      if (index >= 0 && index < count) {
        removeFromFile(index);
        print("Dish removed successfully.");
      } else {
        print("Error: Invalid index.");
      }
      break;
    }
    case 5: {
      DishData newDish{};

      print("Enter dish name: ", '\0');
      input(newDish.name);

      print("Enter cost ($): ", '\0');
      input(newDish.cost);

      print("Enter calories: ", '\0');
      input(newDish.calories);

      int temp;

      print("Is it vegetarian? (1 for Yes, 0 for No): ", '\0');
      input(temp);
      newDish.isVegetarian = (temp != 0);

      print("Is it spicy? (1 for Yes, 0 for No): ", '\0');
      input(temp);
      newDish.isSpicy = (temp != 0);

      print("Meal type (0 = Breakfast, 1 = Lunch, 2 = Dinner): ", '\0');
      input(temp);
      if (temp < 0 || temp > 2) {
        print("Error: Invalid meal type. Must be 0, 1, or 2.");
        break;
      }
      newDish.mealType = static_cast<Meal>(temp);

      appendToFile(newDish);
      print("Dish added to the database!");
      break;
    }
    case 6: {
      char searchName[MAX_DISH_NAME_SIZE];
      print("Enter exact dish name to search for: ", '\0');
      input(searchName);

      int index = linearSearchByName(searchName);
      if (index != -1) {
        print("Success! Dish found at index: ", '\0');
        print(index);
      } else {
        print("Dish not found in the database.");
      }
      break;
    }
    case 7: {
      print("Enter exact calorie amount to search for: ", '\0');
      int targetCals;
      input(targetCals);

      print("Sorting the binary file directly by Calories (Selection)...",
            '\0');
      selectionSortByCalories();

      int index = binarySearchByCalories(targetCals);
      if (index != -1) {
        print("Success! Dish with ", '\0');
        print(targetCals, '\0');
        print(" calories found at index: ", '\0');
        print(index);

        printDishData(readFromFile(index));
      } else {
        print("No dish with exactly that many calories was found in the "
              "database.");
      }
      break;
    }
    case 8: {
      print("Sorting the binary file directly by Cost (Bubble)...");
      bubbleSortByCost();
      print("Done. Use option 2 to view changes.");
      break;
    }
    case 9: {
      print("Sorting the binary file directly by Calories (Selection)...");
      selectionSortByCalories();
      print("Done. Use option 2 to view changes.");
      break;
    }
    case 10: {
      print("Sorting the binary file directly by Name (Insertion)...");
      insertionSortByName();
      print("Done. Use option 2 to view changes.");
      break;
    }
    case 11: {
      int arrivalTime;
      int tempSpicy;
      int tempVeg;

      print("Enter guest arrival time (0-23 hours): ", '\0');
      input(arrivalTime);

      if (arrivalTime < 0 || arrivalTime > 23) {
        print("Error: Invalid time. Must be 0-23.");
        break;
      }

      print("Offer spicy dishes? (1 for Yes, 0 for No): ", '\0');
      input(tempSpicy);

      print("Offer vegetarian only? (1 for Yes, 0 for No): ", '\0');
      input(tempVeg);

      print("Looking for suitable dishes...");
      int foundCount = getSuitableDishes(arrivalTime, (tempSpicy != 0), (tempVeg != 0));

      if (foundCount == 0) {
        print("No suitable dishes found.");
      } else {
        print("Found ", '\0');
        print(foundCount, '\0');
        print(" suitable dish(es):");
        print("--------------------------");
        for (int i = 0; i < foundCount; ++i) {
          DishData d = readFromFile(i, TEMP_FILENAME);
          printDishData(d);
        }
      }
      break;
    }
    case 12: {
      const char* mealNames[] = {"Breakfast", "Lunch", "Dinner"};
      Meal meals[] = {Meal::Breakfast, Meal::Lunch, Meal::Dinner};

      for (int m = 0; m < 3; ++m) {
        int count = getDishesByMealType(meals[m]);

        print("==========================");
        print(mealNames[m]);
        print("==========================");

        if (count == 0) {
          print("No dishes in this category.");
        } else {
          int totalCalories = 0;
          int totalCost = 0;

          for (int i = 0; i < count; ++i) {
            DishData d = readFromFile(i, TEMP_FILENAME);
            printDishData(d);
            totalCalories += d.calories;
            totalCost += d.cost;
          }

          print("--------------------------");
          print("Mean Calories: ", '\0');
          print(totalCalories / count);
          print("Mean Cost ($): ", '\0');
          print(totalCost / count);
        }
        print();
      }
      break;
    }
    case 0: {
      print("Exiting application...");
      break;
    }
    default: {
      print("Invalid choice, please select an option from 0 to 12.");
      break;
    }
    }
    print();
  }
}
