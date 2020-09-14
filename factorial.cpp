#include<iostream>
using namespace std;

int fact_with_recur(int n);
int fact_without_recur(int n);

int main()
{
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;
    cout<<"\n";
    cout << "Factorial of " << n << " with recursion" << " = " << fact_with_recur(n) <<"\n";
    cout << "Factorial of " << n << " without recursion" << " = " << fact_without_recur(n) <<"\n";

    return 0;
}

int fact_with_recur(int n)
{
    if(n > 1)
        return n * fact_with_recur(n - 1);
    else
        return 1;
}

int fact_without_recur(int n)
{
    int result = 1;
    int i = 0;

    if( n <= 1)
            return 1;
        for(i = 2; i <= n; i++)
        {
            result = result * i;
        }
        return result;

}
