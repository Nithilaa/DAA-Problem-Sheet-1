#include <iostream>

using namespace std;

// Function to swap numbers
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* This function takes last element as pivot,
places the pivot element at its correct
position in sorted array, and places
all smaller (smaller than pivot) to left
of pivot and all greater elements to
right of pivot */
int partition(int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSort_rec(int A[], int l, int h)
{
	if (l < h) {
		/* Partitioning index */
		int p = partition(A, l, h);
		quickSort_rec(A, l, p - 1);
		quickSort_rec(A, p + 1, h);
	}
}

//////

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
//////

// Driver code
int main()
{

	int n = 5;
	int arr[n];
	cout<<"Enter array elements : ";
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

	int choice;
	cout<<"\n1. Recursive quick sort\n2. Non recursive quick sort\nEnter your choice : ";
	cin>>choice;
    cout<<"\n";
	switch(choice)
	{
	    case 1: quickSort_rec(arr, 0, n - 1);
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout<<"\n";
                break;

        case 2: quickSortIterative(arr, 0, n - 1);
                printArr(arr, n);
                cout<<"\n";
                break;
	}

	return 0;
}
