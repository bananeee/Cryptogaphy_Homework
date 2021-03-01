#include <bits/stdc++.h>

using namespace std;

int getChar(char c)
{
    return (c - 'a');
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findRelativePrime(long num, long numLength)
{
    long start = pow(10, numLength) + 1;
    int step = num % 2 ? 2 : 1;
    while (gcd(num, start) != 1)
    {
        start+= step;
    }
    return start;
}

/**
 * @brief Find multiplicative inverse of a modulo m: b^-1 mod a
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int extendEuclid(int a, int b)
{
    int m = a;
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    int q, r;

    if (gcd(a, b) != 1)
    {
        cout << "gcd(a,b) != 1" << endl;
        return 0;
    }

    while (b > 0)   
    {
        // Break here
        q = a / b;
        r = a % b;
        int xTemp = x2 - q * x1;
        int yTemp = y2 - q * y1;

        a = b;
        b = r;
        x2 = x1;
        x1 = xTemp;
        y2 = y1;
        y1 = yTemp;
    }

    return y2 >= 0 ? y2 % m : (y2 + m) % m;
    
}



int main()
{
    // cout << findRelativePrime(31510176, 7);
    cout << extendEuclid(75, 28);
}
