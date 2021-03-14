#include <bits/stdc++.h>

using namespace std;

int getChar(char c)
{
    return (c - 'a');
}

void getCharFromString(string s)
{
    for (int i = 0; i < s.size(); i++)
        cout << getChar(s[i]) << " ";
    cout << endl;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findRelativePrime(long num, long start)
{
    // long start = pow(10, numLength) + 1;
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
    getCharFromString("minh");
    // while (true)
    // {
    //     cout << "Welcome, this is a small tool support for cryptography course\n"
    //     << "Please choose command:\n"
    //     << "0. Get alphabet position from a string\n"
    //     << "1. Get GCD from 2 number a & b\n"
    //     << "2. Find relative prime of a number\n"
    //     << "3. Find multiplicative inverse of a modulo m: b^-1 mod a\n";

    //     int userChoice;
    //     cin >> userChoice;

    //     switch (userChoice)
    //     {
    //     case 0:
            
    //         break;
    //     case 1:
            
    //         break;
    //     case 2:
            
    //         break;
    //     case 3:
            
    //         break;
    //     default:
    //         cout << "Wrong command!";
    //         break;
    //     }
    // }
    // // getCharFromString("minh");
    // cout << findRelativePrime(571 * 4970, 34564456);
    
}
