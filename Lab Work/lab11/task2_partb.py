import ctypes
import concurrent.futures

lib = ctypes.CDLL('./t2.so') 

lib.checkPrime.argtypes = [ctypes.c_int]
lib.checkPrime.restype = None

# Python wrapper function for checkPrime
def checkPrimeWrapper(N):
    lib.checkPrime(N)

def checkPrime(i):
    N = 1000000000 + i
    checkPrimeWrapper(N)

num_iterations = 1000

with concurrent.futures.ThreadPoolExecutor() as executor:
    executor.map(checkPrime, range(num_iterations))
