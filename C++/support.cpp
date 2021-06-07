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

// Returns true if n is prime 
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
            return false; 
  
    return true; 
} 
  
/* Iterative Function to calculate (x^n)%p in 
   O(logy) */
int power(int x, unsigned int y, int p) 
{ 
    int res = 1;     // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Utility function to store prime factors of a number 
void findPrimefactors(unordered_set<int> &s, int n) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        s.insert(2); 
        n = n/2; 
    } 
  
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            s.insert(i); 
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when 
    // n is a prime number greater than 2 
    if (n > 2) 
        s.insert(n); 
} 
  
// Function to find smallest primitive root of n 
int findPrimitive(int n) 
{ 
    unordered_set<int> s; 
  
    // Check if n is prime or not 
    if (isPrime(n)==false) 
        return -1; 
  
    // Find value of Euler Totient function of n 
    // Since n is a prime number, the value of Euler 
    // Totient function is n-1 as there are n-1 
    // relatively prime numbers. 
    int phi = n-1; 
  
    // Find prime factors of phi and store in a set 
    findPrimefactors(s, phi); 
  
    // Check for every number from 2 to phi 
    for (int r=2; r<=phi; r++) 
    { 
        // Iterate through all prime factors of phi. 
        // and check if we found a power with value 1 
        bool flag = false; 
        for (auto it = s.begin(); it != s.end(); it++) 
        { 
  
            // Check if r^((phi)/primefactors) mod n 
            // is 1 or not 
            if (power(r, phi/(*it), n) == 1) 
            { 
                flag = true; 
                break; 
            } 
         } 
  
         // If there was no power with value 1. 
         if (flag == false) 
           return r; 
    } 
  
    // If no primitive root found 
    return -1; 
} 


int main()
{
    // cout << findRelativePrime(31510176, 7);
    // getCharFromString("minh");
    cout << findPrimitive(678577);
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
