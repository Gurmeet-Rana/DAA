/* Given an already sorted array of positive integers, design an algorithm and implement it using a
 program to find whether given key element is present in the array or not. Also, find total number
 of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input) */

 #include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
    int searchElement(int arr[], int n, int key)
    {
        int comparisons = 0;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            comparisons++;
            int mid = low + (high - low) / 2;
            if (arr[mid] == key)
            {
                cout << "Key element found at index " << mid << endl;
                return comparisons;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
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
