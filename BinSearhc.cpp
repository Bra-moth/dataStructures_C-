#include <iostream>
#include <algorithm>

using namespace std;

const int Elements = 10; //globally initialized 11 number of integers//
int arr[Elements];
int target;


int binarySearch(int arr[], int left, int right, int target)
{
    //Devide and Conqure

        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
}



void bubblesort()
{
    bool swapped;
    for (int i = 0; i < Elements - 1; i++){
        swapped = false;
        for (int j = 0; j < Elements - i - 1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j]; //creates a temporary array index to store the removed element
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        // if no two elements were swapped by inner loop, the break
        if (swapped == false)
            break;
    }


}


int main()
{
    int i;

    cout << "Enter " << Elements << " integers, pressing ENTER to confirm every entry....\n" << endl;
    for (i = 0; i < Elements; i++)
    {
        cin >> arr[i];
    }


    // menu driven program
    int choice;

    do{
    cout << "1. Sort the Elements in Ascending Order:\n";
    cout << "2. Search for an integer \n";
    cout << "3. Exit \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
            system("cls");
            bubblesort(); //The elements must be sorted for binary search to be implemented successfully
            cout << "Sorted array: ";
            for(int i = 0; i < Elements; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 2:
        {
            cout << "Enter the number to search " << endl;
            cin >> target;

            system("cls");
            for(int i = 0; i < Elements; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            ///perfom a binary search

            int index = binarySearch(arr, 0, Elements-1, target);
            if (index != -1)
                cout << target << " found at index " << index+1 << " \n";
            else
                cout << target << " not found.\n";
            break;

        }
        case 3:
            cout << "Existing program..\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;


    }

    }while (choice != 3);


}
