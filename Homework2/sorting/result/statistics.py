import os
arr = []
for file in list(os.listdir(".")):
    if (file.endswith(".raw")):
        if (arr == []):
            with open(file, "r") as f:
                for line in f:
                    arr.append(line.strip())
        else:
            for i in range(len(arr)):
                if (arr[i].isnumeric()):
                    with open(file, "r") as f:
                        arr[i] = str(int(arr[i]) + int(f.readlines()[i].strip()))

for i in range(len(arr)):
    if (arr[i].isnumeric()):
        arr[i] = str(int(arr[i]) // 5)
    print(arr[i])

print("average")
for i in range(len(arr)):
    if (not arr[i].isnumeric() and arr[i] != ""):
        print(arr[i])
        sum = 0
        for j in range(10):
            sum += int(arr[i+j+1])
        print(sum // 10)
