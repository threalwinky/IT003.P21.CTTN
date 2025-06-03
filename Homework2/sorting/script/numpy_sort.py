import numpy 
import sys 
from time import time

def numpy_sort(real_numbers):
    real_numbers = numpy.sort(real_numbers)
    return real_numbers

filename = sys.argv[1]
data = open(f'{filename}', 'r').read().strip().split(' ')
real_numbers = [float(x) for x in data]
start_time = time()
real_numbers = numpy_sort(real_numbers)
end_time = time()
result = (end_time - start_time) * 1000
print(int(result), end="")