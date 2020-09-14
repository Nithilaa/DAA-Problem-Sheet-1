#include <iostream>
using namespace std;

int gcd_with_rec(int n1, int n2);
int gcd_without_rec(int x, int y);

int main()
{
   int n1, n2;

   cout << "Enter two positive integers: ";
   cin >> n1 >> n2;

   cout << "\nGCD of " << n1 << " & " <<  n2 << " using recursion is            : " << gcd_with_rec(n1, n2) << "\n";
   cout << "\nGCD of " << n1 << " & " <<  n2 << " without using recursion is    : " << gcd_without_rec(n1, n2) << "\n";

   return 0;
}

int gcd_with_rec(int n1, int n2)
{
    if (n2 != 0)
       return gcd_with_rec(n2, n1 % n2);
    else
       return n1;
}

int gcd_without_rec(int x, int y)
{
    int minimum = min(x, y);

    if (x % minimum == 0 && y % minimum == 0)
        return minimum;

    for (int i = minimum / 2; i >= 2; i--) {
        if (x % i == 0 && y % i == 0)
            return i;
    }

    return 1;
}
