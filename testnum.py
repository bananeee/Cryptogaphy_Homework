def convertToInt(s):
    sum = 0
    for i in range(0, len(s)):
        sum += ((ord(s[i]) - ord('a')) * 24**i)
    return sum

def convertToString(n):
    s = ""
    while n > 0:
        s = s + chr(n % 24 + ord('a'))
        n = n // 24
    return s

n = convertToInt("hoangducminh")
s = convertToString(n)
print(n, s)

