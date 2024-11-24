from multiprocessing import Pool
import os
import time
import numpy as np

def f(x):

    f = x*x*x + 2*(x*x) + 1
    return f

input_list = list(range(1, 1000001))

for num_threads in [1,2,4,8]:
    start_time = time.time()
    p = Pool(num_threads)
    result = p.map(f, input_list )

    end_time = time.time()
    total_time = end_time-start_time
    print(f"{num_threads} {total_time}")
    