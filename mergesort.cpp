#include<iostream>
using namespace std;
void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

/////

void merge_nr(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* create temp arrays */
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
       R[j] = arr[m + 1+ j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while(i < n1 && j < n2) {
       if(L[i] <= R[j]) {
          arr[k] = L[i];
          i++;
       }
       else {
          arr[k] = R[j];
          j++;
       }
    k++;
    }
    /* Copy the remaining elements of L[], if there are any */
     while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
     }
     /* Copy the remaining elements of R[], if there are any */
     while(j < n2) {
       arr[k] = R[j];
       j++;
       k++;
     }
}
/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort_nr(int arr[], int l, int r) {
    if(l < r) {
       // Same as (l+r)/2, but avoids overflow for
       // large l and h
       int m = l+(r-l)/2;
       // Sort first and second halves
       mergeSort_nr(arr, l, m);
       mergeSort_nr(arr, m+1, r);
       merge_nr(arr, l, m, r);
    }
}

/////

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr1[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr1[i];
   }

   int choice;
   cout<<"Chose the method : \n\t1. Recursive merge sort\n\t2. Non recursive merge sort.\nYour choice : ";
   cin>>choice;
   switch(choice)
   {
        case 1: cout << "Array before Sorting: ";
                display(arr1, n);
                cout<<"\n";
                mergeSort(arr1, 0, n-1);     //(n-1) for last index
                cout << "Array after Sorting using recursion: ";
                display(arr1, n);
                break;

        case 2: cout << "Array before Sorting: ";
                display(arr1, n);
                cout<<"\n";
                mergeSort_nr(arr1, 0, n - 1);
                cout << "Array after Sorting without using recursion: ";
                display(arr1, n);
                break;

        case 3: cout<<"Enter either 1 or 2!!!";
                break;

   }
}
