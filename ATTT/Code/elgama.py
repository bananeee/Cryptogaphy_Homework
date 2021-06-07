from prime import generate_prime_number, is_prime, randrange
from support import *


def elgama_encrypt(x, alpha, beta, p):
    """Elgama encryption

    Args:
        x : content
        alpha : primitive element of p 
        beta : random element of p
        p : random big prime
    """
    k = randrange(0, 10000000, 1)
    y1 = modexp(alpha, k, p)
    y2 = (x * modexp(beta, k, p)) % p

    return y1, y2

def elgama_decrypt(y1, y2, a, p):
    """Elgama dectryption

    Args:
        y1 : 
        y2 : 
        a : discrete logarithm of beta
        p : random big prime
    """
    
    return (y2 * modinv(modexp(y1, a, p), p)) % p


if __name__ == "__main__":
    # p is random 256-bit prime
    a = int(input("Choose secret key a:"))

    x = int(input("Enter number to encrypt:"))

    p = 101772665954685200507098931443389343082543279947190588868406755488643105839567

    alpha = primitive(p)
    # a = randrange(0, 10000, 1)
    beta = modexp(alpha, a, p)

    y1, y2 = elgama_encrypt(x, alpha, beta, p)
    
    print("Public key is (p, alpha, beta):", p, ",", alpha, ",", beta)
    print("Private key is (a):", a)
    
    print("ElGama encryption is (", y1 , ",", y2, ")")
    print("ElGama decryption is ", elgama_decrypt(y1, y2, a, p))
    
