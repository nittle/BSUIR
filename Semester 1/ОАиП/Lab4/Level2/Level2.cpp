#include <iostream>

using namespace std;
int main()
{
    int size, choice;

    cout << "Enter number of elms: ";
    cin >> size;

    cout << "How to fill the array(1 - from keybr, 2 - with rand nums)?: ";
    cin >> choice;

    int* arr = new int[size];

    switch (choice)
    {
    case 1:
        cout << "Input nums separated with space: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        cin.clear();
        cin.ignore(10000, '\n');
        break;
    case 2: 
        srand(time(NULL));
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100-50;
            cout << arr[i] << " ";
        }
        break;
    default:
        cout << "Wrong input!";
        return 0;
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    bool isFirstZero = true, containsZero = false;
    int result = 1;

    for (int i = 0; i < size; i++)
    {
        if (!isFirstZero && arr[i] != 0) result *= arr[i];
        if (arr[i] == 0) {
            isFirstZero = !isFirstZero;
            containsZero = true;
        }
    }

    if (!containsZero) cout << "The array doesnt contain a zero value" << endl;
    else cout << "Result: " << result;
}