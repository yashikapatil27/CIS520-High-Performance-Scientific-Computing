import ctypes

lib = ctypes.CDLL('./t2.so')

lib.checkPrime.argtypes = [ctypes.c_int]
lib.checkPrime.restype = None

# Python wrapper function for checkPrime
def checkPrimeWrapper(N):
    lib.checkPrime(N)

for i in range(1000):
    N = 1000000000 + i
    checkPrimeWrapper(N)
