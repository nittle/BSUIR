#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minJumps(vector<int>& arr) {
    if(arr[0] == 0 ) return -1;

    int currReach = 0, maxReach = 0, jump = 0, n = arr.size();

    for (int i = 0; i < n; i++)
    {
        maxReach = max(maxReach, arr[i] + i);
        if(maxReach >= n - 1) return ++jump;
        if(i == currReach) {
            if(currReach == maxReach) return -1;
            currReach = maxReach;
            jump++;
        }
                
    }

    return jump;
}

int main() {
    vector<int> arr = {9, 3, 9, 1, 8, 9, 5, 3, 10, 4, 6, 10, 7, 1, 7, 7, 7, 2, 3, 1, 4, 1, 5, 2, 4, 5, 9, 3};
    cout << minJumps(arr);

    return 0;
}