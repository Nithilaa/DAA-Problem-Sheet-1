#include <iostream>
using namespace std;

int fib_with_rec(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fib_with_rec(x-1)+fib_with_rec(x-2));
   }
}

void fib_without_rec(int num) {
   int x = 0, y = 1, z = 0;
   for (int i = 0; i < num; i++) {
      cout << x << " ";
      z = x + y;
      x = y;
      y = z;
   }
}

int main() {
   int x , i=0;
   cout << "Enter the number of terms of series : ";
   cin >> x;

   cout << "\nFibonnaci Series with recursion       : ";
   while(i < x) {
      cout << " " << fib_with_rec(i);
      i++;
   }

   cout << "\nFibonnaci Series without recursion    : ";
   fib_without_rec(x);

   return 0;
}
