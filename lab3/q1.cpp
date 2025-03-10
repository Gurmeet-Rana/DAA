/* Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input */

#include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
    int searchElement(int arr[], int n, int key)
    {
        int comparisons = 0;
        for (int i = 0; i < n; i++)
        {
            comparisons++;
            if (arr[i] == key)
            {
                cout << "Key element found at index " << i << endl;
                return comparisons;
            }
        }
        return -1;
    }
};
int main()
{
    Solution obj;
    int testCases;
    cout << "Enter the number of test cases: ";
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cout << "Enter the size of the vector" << endl;
        cin >> n;
        int arr[n];
        cout << "Enter the values in the array : " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int key;
        cout << "Enter the key element to search for: ";
        cin >> key;
        
        int comparisons = obj.searchElement(arr, n, key);
        if(comparisons == -1){
            cout << "Key element not found" << endl;
            comparisons = n;
        }
        cout << "Total number of comparisons: " << comparisons << endl;
    }
    return 0;
}