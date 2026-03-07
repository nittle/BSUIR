#include "avl.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void displayMenu() {
    print("--- AVL Tree ---");
    print("1. Add custom values");
    print("2. Fill with random values");
    print("3. Delete an element");
    print("4. Get tree height(ind. task)");
    print("5. Display traversals");
    print("0. Exit");
    print("Choice: ", '\0');
}

int main() {
    srand(time(NULL));
    Node* root = nullptr;
    int choice, value, count;

    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            print("Invalid input. Please enter a number.");
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            print("Enter the number of elements followed by the values:", ' ');
            if (std::cin >> count) { // 'count' is the first number
                for (int i = 0; i < count; i++) {
                    if (std::cin >> value) { // Read the next value
                        root = insert(root, value);
                    }
                }
                print("Insertion complete.");
            }
            break;

        case 2: {
            print("How many random values?", ' ');
            if (!(std::cin >> count) || count <= 0) break;

            int maxRange = (count > 100) ? count * 2 : 100;

            int* usedNumbers = new int[count];
            int currentSize = 0;

            print("Generating unique values...");

            while (currentSize < count) {
                int randomVal = rand() % maxRange + 1;
                bool isUnique = true;

                for (int i = 0; i < currentSize; i++) {
                    if (usedNumbers[i] == randomVal) {
                        isUnique = false;
                        break;
                    }
                }

                if (isUnique) {
                    root = insert(root, randomVal);
                    usedNumbers[currentSize] = randomVal;
                    currentSize++;
                }
            }

            print("Successfully inserted", ' ');
            print(count, ' ');
            print("unique values.");

            delete[] usedNumbers;
            break;
        }
        case 3:
            print("Enter value to delete:", ' ');
            std::cin >> value;
            root = deleteNode(root, value);
            print("Deletion complete.");
            break;

        case 4:
            print("Maximum Tree Height:", ' ');
            print(getHeight(root));
            break;

        case 5:
            print("\nPre-order:", ' ');
            preOrderTraversal(root);
            print("\nIn-order:", ' ');
            inOrderTraversal(root);
            print("\nPost-order:", ' ');
            postOrderTraversal(root);
            print();
            break;

        case 0:
            print("Exiting...");
            break;

        default:
            print("Invalid choice.");
        }
    } while (choice != 0);

    freeMemory(root);
    return 0;
}