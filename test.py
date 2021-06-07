# # from sage.misc.prandom import randrange
# # M = 1114597119506223026265579259036275469126397408411
# # ord = -1
# # step = 0
# # A = 106
# # B = 12
# # while True:
# #     A += 1
# #     if A % 10 == 0:
# #         B += 1
# #     # A = randrange(1, 100, 1)
# #     # B = randrange(1, 100, 1)
# #     F = FiniteField(M)
# #     E = EllipticCurve(F, [A, B])

# #     ord = E.order()
# #     step += 1
# #     if step % 10 == 0:
# #         print(step, "tries")
# #     if ord.is_prime():
# #         print("A:", A)
# #         print("B:", B)
# #         print("M:", M)
# #         print("Order of group:", ord)
# #         break



# # Python3 program to print prime factors
# # and their powers.
# import math
# from prime import *
 
# # Function to calculate all the prime
# # factors and count of every prime factor
# def factorize(n):
#     count = 0;
 
#     # count the number of
#     # times 2 divides
#     while ((n % 2 > 0) == False):
         
#         # equivalent to n = n / 2;
#         n >>= 1;
#         count += 1;
 
#     # if 2 divides it
#     if (count > 0):
#         print(2, count);
 
#     # check for all the possible
#     # numbers that can divide it
#     for i in range(3, int(math.sqrt(n)) + 1):
#         count = 0;
#         while (n % i == 0):
#             count += 1;
#             n = int(n / i);
#         if (count > 0):
#             print(i, count);
#         i += 2;
 
#     # if n at the end is a prime number.
#     if (n > 2):
#         print(n, 1);
 
# # Driver Code
# n = generate_prime_number(85);
# factorize(n-1);
 
# # This code is contributed by mits
x = True and False
print(x)