import math
from prime import *


def primeFactors(n):
    arr = []
    if(n % 2 == 0):
        arr.append(2)

    while n % 2 == 0:
        n = n/2

    for i in range(3, int(math.sqrt(n)+1), 2):
        while n % i == 0:
            if(len(arr) == 0):
                arr.append(i)
            elif(arr[len(arr)-1] != i):
                arr.append(i)
            n = n/i
    if n > 2:
        arr.append(int(n))
    return arr


def findPrimefactors(n):
    # Print the number of 2s that divide n
    while (n % 2 == 0):
        # s.add(2)
        print(2)
        n = n // 2

    # n must be odd at this po. So we can
    # skip one element (Note i = i +2)
    for i in range(3, int(math.sqrt(n) + 1), 2):

        # While i divides n, print i and divide n
        while (n % i == 0):
            # s.add(i)
            print(i)
            n = n // i

    # This condition is to handle the case
    # when n is a prime number greater than 2
    if (n > 2):
        print(n)


p = generate_prime_number(55)
# print(primeFactors(101772665954685200507098931443389343082543279947190588868406755488643105839567-1))
# print(findPrimefactors(101772665954685200507098931443389343082543279947190588868406755488643105839567-1))
print(p-1)
print(primeFactors(p-1))

