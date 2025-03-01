import os
import subprocess
import base64
import random
sort_algos = ["cpp_sort", "heap_sort", "merge_sort", "quick_sort"]
random_num = base64.b64encode(str(random.randint(1, 1000)).encode()).decode('utf-8')
with open(f"result/result_{random_num}.txt", "w") as f:
    f.write("Sorting result\n")
with open(f"result/result_{random_num}.raw", "w") as f:
    f.write("\n")
for sort_algo in sort_algos:
    print(f"[*] Start sorting with {sort_algo}...")
    with open(f"result/result_{random_num}.txt", "a") as f:
        f.write(sort_algo + "\n")
    with open(f"result/result_{random_num}.raw", "a") as f:
        f.write(sort_algo + "\n")
    for testcase in range(1, 11):
        print(f"[*] Sorting testcase {testcase}...")
        result = subprocess.check_output(f"./executable/{sort_algo} ./testcases/test{testcase}.txt", shell=True)
        print(f"[*] Sort testcase {testcase} successfully and took {result.decode('utf-8')} miliseconds.")
        with open(f"result/result_{random_num}.txt", "a") as f:
            f.write(f"Test {testcase} took {result.decode('utf-8')} ms\n")
        with open(f"result/result_{random_num}.raw", "a") as f:
            f.write(result.decode('utf-8')+"\n")
    print(f"[*] Sorting with {sort_algo} successfully.")


sort_algo = "numpy_sort"
print(f"[*] Start sorting with {sort_algo}...")
with open(f"result/result_{random_num}.txt", "a") as f:
    f.write(sort_algo + "\n")
with open(f"result/result_{random_num}.raw", "a") as f:
    f.write(sort_algo + "\n")
for testcase in range(1, 11):
    print(f"[*] Sorting testcase {testcase}...")
    result = subprocess.check_output(f"python3 ./executable/{sort_algo}.py ./testcases/test{testcase}.txt", shell=True)
    print(f"[*] Sort testcase {testcase} successfully and took {result.decode('utf-8')} miliseconds.")
    with open(f"result/result_{random_num}.txt", "a") as f:
        f.write(f"Test {testcase} took {result.decode('utf-8')} ms\n")
    with open(f"result/result_{random_num}.raw", "a") as f:
        f.write(result.decode('utf-8')+"\n")
print(f"[*] Sorting with {sort_algo} successfully.")