from prime import generate_prime_number, is_prime, randrange
from support import *
import math


def is_square(i):
    return i == math.isqrt(i) ** 2


def findFirstPoint(a, b, p):
    x = 0
    while True:
        f = x**3 + a*x + b
        if is_square(f):
            y = int(sqrt(f))
            return (x, y)
        else:
            x += 1
    return


def ecc_encrypt(M, a, b, p, P, B):
    # M = double_and_add(x, P, p, a)
    print("M:", M)
    k = randrange(1, 100, 1)

    M1 = double_and_add(k, P, p, a)
    M2 = ecc_add(M[0], M[1], double_and_add(k, B, p, a)[
                 0], double_and_add(k, B, p, a)[0], p, a)
    return M1, M2


def ecc_decrypt(M1, M2, s, p, a):
    return ecc_add(M2[0], M2[1], double_and_add(s, M1, p, a)[0], -double_and_add(s, M1, p, a)[0], p, a)


if __name__ == "__main__":
    a = 53
    b = 7
    p = 1114597119506223026265579259036275469126397408411
    P = findFirstPoint(a, b, p)

    s = int(input("Enter secret key:"))  # secret key

    M = input("Enter point to encrypt:")
    M = tuple(int(x.strip()) for x in M.split(','))

    # print(s, M, p, a)
    B = double_and_add(s, P, p, a)
    
    print("Public key is (a, b, p, P, B): (", a, ",", b,",", p, ",", P, ",", B, ")")
    print("Private key is (s):", s)

    M1, M2 = ecc_encrypt(M, a, b, p, P, B)

    print("EEC encryption is(", M1 , ",", M2, ")")
    print("EEC decryption is", ecc_decrypt(M1, M2, s, p, a))
  
