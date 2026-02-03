#include <iostream>
#include <iomanip>

using namespace std;

const char FILE_NAME[] = "students_db.txt";
const int BUFFER_SIZE = 50;
const int GROUP_NAME_LENGTH = 7;
const char PREFIX[] = "#\t";

struct student {
    int id;
    char lname[BUFFER_SIZE];
    char group[GROUP_NAME_LENGTH];
    int physics[BUFFER_SIZE];
    int maths[BUFFER_SIZE];
    int informatics[BUFFER_SIZE];
    float average;
};

void initStudent(student& st) {
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        st.lname[i] = '\0';
        st.informatics[i] = -1;
        st.maths[i] = -1;
        st.physics[i] = -1;
    }
    for (int i = 0; i < GROUP_NAME_LENGTH; i++)
    {
        st.group[i] = '\0';
    }
    st.average = -1;
}

void assignIndeces(student* pstudents) {
    for (int i = 0; i < BUFFER_SIZE; i++)
        pstudents[i].id = i;
}

float countAverage(const int marks[]) {
    int count = 0, i = 0;
    while(marks[i] != -1)
    {
        count += marks[i];
        i++;
    } 

    return (float)count / i;
}

void printStudentInfo(student st) {
    cout << PREFIX << "Id: " << st.id << endl;
    cout << PREFIX << "Last name: " << st.lname << endl;
    cout << PREFIX << "Group: " << st.group << endl;
    cout << PREFIX << "Physics marks: ";
    for (int i = 0; st.physics[i] != -1; i++)
        cout << st.physics[i] << " ";

    cout << endl;
        cout << PREFIX << "Maths marks: ";
    for (int i = 0; st.maths[i] != -1; i++)
        cout << st.maths[i] << " ";

    cout << endl;
        cout << PREFIX << "Informatics marks: ";
    for (int i = 0; st.informatics[i] != -1; i++)
        cout << st.informatics[i] << " ";

    cout << endl;

    cout << PREFIX << "Average: " << setprecision(3) << st.average << endl;
}

void strToIntArr(int* const arr, char* const str, const int size) {
    int count = 0, n = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\0') {
            arr[count] = n;
            n = 0;
            count++;

            if(str[i] == '\n' || str[i] == '\r' || str[i] == '\0'
                || str[i+1] == '\n' || str[i+1] == '\r' || str[i+1] == '\0')
                break;

            continue;
        }

        n *= 10;
        n += str[i] - '0';
    }
    
}

// Copies str1 into str2
void copyString(char* const str1, char* const str2, const int size) {
    for (int i = 0; i < size; i++)
    {
        if(str1[i] == '\n' || str1[i] == '\r' || str1[i] == '\0') break;
        str2[i] = str1[i];
    }
    
}

void append(const student info, student* const pstudents, int& lastIndex) {
    student& st = pstudents[lastIndex];
    st = info;
    st.id = lastIndex;
    st.average = (countAverage(st.maths) + countAverage(st.informatics) + countAverage(st.physics)) / 3;

    lastIndex++;
}

void saveToFile(const student* const pstudents, const int lastIndex) {
    FILE* pfile = fopen(FILE_NAME, "w");

    int count = 0;
    for (int i = 0; i < lastIndex; i++)
    {
        student st = pstudents[i];

        fputs(st.lname, pfile);
        fputs("\n", pfile);
        fputs(st.group, pfile);
        fputs("\n", pfile);

        for (int j = 0; st.physics[j] != -1; j++)
            fprintf(pfile, "%d ", st.physics[j]);

        fputs("\n", pfile);
        for (int j = 0; st.maths[j] != -1; j++)
            fprintf(pfile, "%d ", st.maths[j]);

        fputs("\n", pfile);
        for (int j = 0; st.informatics[j] != -1; j++)
            fprintf(pfile, "%d ", st.informatics[j]);

        fputs("\n\n", pfile);
    }

    fclose(pfile);
}

void createNew() {
    FILE* pfile = fopen(FILE_NAME, "w");

    if (pfile == nullptr) {
        cout << PREFIX << "Error creating the file" << endl;
        return;
    }
    else cout << PREFIX << "File created" << endl;

    fclose(pfile);
}

void readFile(student* const pstudents, int& lastIndex) {
    FILE* pfile = fopen(FILE_NAME, "r");

    if (pfile == nullptr) {
        cout << PREFIX << "Error opening the file" << endl;
        return;
    }
    char data[BUFFER_SIZE];
    int lineStart = 0;
    student newSt;
    initStudent(newSt);

    for (int i = 0; fgets(data, BUFFER_SIZE, pfile) != NULL; i++)
    {      
        if (data[0] == '\r' || data[0] == '\n') {
            lineStart = i + 1;
        }
        else {
            switch (i - lineStart)
            {
            case 0:
                copyString(data, newSt.lname, BUFFER_SIZE);
                break;
            case 1:
                copyString(data, newSt.group, BUFFER_SIZE);
                break;
            case 2:
                strToIntArr(newSt.physics, data, BUFFER_SIZE);
                break;
            case 3:
                strToIntArr(newSt.maths, data, BUFFER_SIZE);
                break;
            case 4:
                strToIntArr(newSt.informatics, data, BUFFER_SIZE);
                append(newSt, pstudents, lastIndex);
                initStudent(newSt);
                break;            
            }
        }
    }
    
    fclose(pfile);
}

// Expects a pointer to int array to write results
void indTask(student* pstudents, int lastIndex, int* res) {
    int ind = 0;

    for (int i = 0; i < lastIndex; i++)
    {
        student st = pstudents[i];
        bool hasFourOrFive = 0, hasAllEights = 1;

        for (int i = 0; st.physics[i] != -1; i++)
        {
            if (st.physics[i] == 4 || st.physics[i] == 5) {
                hasFourOrFive = 1;
                break;
            }
        }
        for (int i = 0; st.maths[i] != -1; i++)
        {
            if (st.maths[i] <= 8) {
                hasAllEights = 0;
                break;
            }
        }
        for (int i = 0; st.informatics[i] != -1; i++)
        {
            if (st.informatics[i] <= 8) {
                hasAllEights = 0;
                break;
            }
        }

        if (hasAllEights && hasFourOrFive) {
            res[ind] = i;
            ind++;
        }
    }
}

void changeMark(int arr[]) {
    int markId, mark;
    cout << "What mark do you want to change?: ";
    cin >> markId;
    markId--;

    if (arr[markId] == -1 || markId > BUFFER_SIZE - 1) {
        cout << PREFIX << "Wrong input" << endl;
        return;
    }

    cout << "Enter new mark: ";
    cin >> mark;

    arr[markId] = mark;
    cout << PREFIX << "Mark changed!" << endl;
}

void remove(student* const pstudents, const int index, int& lastIndex) {
    student blank{};

    initStudent(blank);

    for (int i = index; i < lastIndex; i++)
    {
        if (i == lastIndex - 1)
        {
            pstudents[i] = blank;
            break;
        }
        pstudents[i] = pstudents[i + 1];
        pstudents[i].id = i;
    }

    lastIndex--;
}

template<typename T>
void swap(T* xp, T* yp) {
    T temp = *yp;
    *yp = *xp;
    *xp = temp;
}

// true if str1 should be higher in alph order than str2
bool compareStrings(const char str1[], const char str2[]) {
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (tolower(str1[i]) < tolower(str2[i]))
            return true;
        else if (tolower(str1[i]) > tolower(str2[i]))
            return false;
    }

    return false;
}

// Sort by lname(LnameAsc/LnameDesc), group(GroupAsc/GroupDesc), average(AverageAsc/AverageDesc)
void sort(student* const arr, const int lastIndex, const char* const option) {
    for (int i = 0; i < lastIndex - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < lastIndex - i - 1; j++)
        {
            bool res = false;
            if (!strcmp(option, "LnameAsc")) res = !compareStrings(arr[j].lname, arr[j + 1].lname);
            else if (!strcmp(option, "LnameDesc")) res = compareStrings(arr[j].lname, arr[j + 1].lname);
            else if (!strcmp(option, "GroupAsc")) res = !compareStrings(arr[j].group, arr[j + 1].group);
            else if (!strcmp(option, "GroupDesc")) res = compareStrings(arr[j].group, arr[j + 1].group);
            else if (!strcmp(option, "AverageAsc")) res = arr[j].average > arr[j + 1].average;
            else if (!strcmp(option, "AverageDesc")) res = arr[j].average < arr[j + 1].average;
                 
            if (res) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
    assignIndeces(arr);
}

int main()
{
    setlocale(LC_ALL, "ru");

    int lastIndex = 0;
    student* pstudents = new student[BUFFER_SIZE] {};

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        initStudent(pstudents[i]);
        assignIndeces(pstudents);
    }

    cout << "What do you want to do?\nLevel 1:\n1 - create new file,\n2 - read information from file,\n3 - add new entry,\n4 - ind. task,\n5 - show current entries,\n6 - save to file\nLevel 2:\n7 - edit\n8 - remove\n9 - sort\n============\n0 - quit.\n\n";
    while (1) {
        int choice;
        cout << ":";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createNew();
            break;
        case 2:
            readFile(pstudents, lastIndex);
            cout << PREFIX << "Added info from file" << endl;
            break;
        case 3:
        {
            int count;
            student newSt;
            initStudent(newSt);

            cout << "Enter last name: ";
            cin >> newSt.lname;
            cout << "Enter group: ";
            cin >> newSt.group;
            cout << "Enter physics marks(space separated) where first number is the number of marks: ";
            cin >> count;
            for (int i = 0; i < count; i++)
                cin >> newSt.physics[i];

            cout << "Enter maths marks(space separated) where first number is the number of marks: ";
            cin >> count;
            for (int i = 0; i < count; i++)
                cin >> newSt.maths[i];

            cout << "Enter informatics marks(space separated) where first number is the number of marks: ";
            cin >> count;
            for (int i = 0; i < count; i++)
                cin >> newSt.informatics[i];

            append(newSt, pstudents, lastIndex);
            cout << PREFIX << "New entry created" << endl;
        }
            break;
        case 4: 
        {
            int* res = new int[BUFFER_SIZE];
            for (int i = 0; i < BUFFER_SIZE; i++)
                res[i] = -1;

            indTask(pstudents, lastIndex, res);

            cout << PREFIX << "Students found: ";
            for (int i = 0; res[i] != -1; i++)
                cout << pstudents[res[i]].lname << " ";

            cout << endl;

            delete[] res;
            break;
        }
        case 5:
            if (lastIndex == 0)
                cout << PREFIX << "No entries" << endl;
            else {
                for (int i = 0; i < lastIndex; i++)
                {
                    printStudentInfo(pstudents[i]);
                    cout << endl;
                }
            }
            break;
        case 6:
            saveToFile(pstudents, lastIndex);
            cout << PREFIX << "Saved to " << FILE_NAME << endl;
            break;
        case 7:
            {
            int id, choice;
            cout << "Enter id of student to edit: ";
            cin >> id;
            if (id >= lastIndex) {
                cout << PREFIX << "Wrong input!" << endl;
                break;
            }
            cout << "What to edit?\n1 - name\n2 - group\n3 - physics marks\n4 - maths marks\n5 - informatics marks\n:";
            cin >> choice;

            student& st = pstudents[id];
            switch (choice)
                {
                    case 1:
                        char name[BUFFER_SIZE];
                        cout << "Enter new name: ";
                        cin >> name;

                        copyString(name, st.lname, BUFFER_SIZE);
                        cout << PREFIX << "Name`s been changed!" << endl;
                        break;
                    case 2:
                        char group[GROUP_NAME_LENGTH];
                        cout << "Enter new group: ";
                        cin >> group;

                        copyString(group, st.group, BUFFER_SIZE);
                        cout << PREFIX << "Group`s been changed!" << endl;
                        break;
                    case 3:
                        changeMark(st.physics);
                        break;
                    case 4: 
                        changeMark(st.maths);
                        break;
                    case 5:
                        changeMark(st.informatics);
                        break;
                    default:
                        cout << PREFIX << "Wrong input!" << endl;
                        break;
                }
            }
            break;
        case 8:
            int id;
            cout << "Enter id of entry to remove: ";
            cin >> id;
            if (id >= lastIndex) break;

            remove(pstudents, id, lastIndex);
            cout << PREFIX << "Entry removed" << endl;
            break;
        case 9:
            char option[BUFFER_SIZE];
            int choice, orderChoice;
            cout << "By what field to sort?(1 - last name, 2 - group, 3 - average): ";
            cin >> choice;
            cout << "In what order?(1 - ascending, 2 - descending): ";
            cin >> orderChoice;

            switch (choice)
            {
            case 1:
                strcpy(option, "Lname");
                break;
            case 2:
                strcpy(option, "Group");
                break;
            case 3:
                strcpy(option, "Average");
                break;
            default:
                goto link;
            }
            switch (orderChoice)
            {
            case 1:
                strcat(option, "Asc");
                break;
            case 2:
                strcat(option, "Desc");
                break;
            default:
                goto link;
            }

            sort(pstudents, lastIndex, option);
            cout << PREFIX << "Sorted" << endl;
            break;
            link:
                cout << PREFIX << "Wrong input!";
                break;
        case 0: 
            cout << PREFIX << "Quitting..." << endl;
            return 0;
            break;
        }
        
    }

    delete[] pstudents;
    return 0;
}