from prime import generate_prime_number, is_prime
from support import *


def rsa_encrypt(x, b, n):
    """RSA encryption ek = x^b mod n

    Args:
        x : content
        b : random number that gcd(b, phi(n)) = 1
        n : pq
    """
    return modexp(x, b, n)


def rsa_decrypt(y, a, n):
    """RSA encryption dk = y^a mod p

    Args:
        y : encrypted content
        a : modular inverse of b
        n : pq
    """
    return modexp(y, a, n)

    print()


if __name__ == "__main__":
    # p, q are 512 bit primes
    # random b such taht gcd(b, phi(n)) = 1 => choose b as random prime for easy calculating

    x = int(input("Enter number to encrypt:"))

    # p = generate_prime_number(512)
    # q = generate_prime_number(512)

    p = 9607148119662215966953860291134935552021529970948227821414276310259699224328420089251860001734469581369286662661929489456209928679379851155917574132015383
    q = 7942814997448628785890615271902035560839675652138142370694028632742919644785493862232366756328919273314953243481427167839097110118579835974997476662633073

    n = p*q
    pn = (p-1)*(q-1)  # phi(n)

    # b = generate_prime_number(10)
    b = 673
    a = modinv(b, pn)

    print("Public key is (n,b): (", n, ",", b, ")")
    print("Private key is (p,q,a): (", p, ",", q, ",", a, ")")

    encrypt = rsa_encrypt(x, b, n)
    decrypt = rsa_decrypt(encrypt, a, n)
    print("RSA encryption is", encrypt)
    print("RSA decryption is", decrypt)
