import os
try:
    import numpy
    print("[*] Numpy library is installed.")

    print("""[*] Want to generate new testcases?
    [1] Yes, generate new
    [2] No, run the program
    [3] No, exit the program""")
    choice = "0"
    while (not choice.isnumeric() or int(choice) not in [1,2,3]):
        choice = input("    Your choice (1,2,3): ")
    choice = int(choice)
    if (choice == 3):
        exit
    else:
        if (choice == 1):
            print("[*] Start compiling generator...")
            os.system("g++ core/generate.cpp -o core/generate")
            print("[*] Compile generator successfully")
            print("[*] Start generating testcases...")
            os.system("./core/generate")
            print("[*] Generate testcases successfully")
        print("[*] Start compiling program...")
        os.system("python3 core/compile.py")
        print("[*] Compile generate file successfully")
        print("[*] Start sorting program...")
        os.system("python3 core/execute.py")

except Exception as e:
    print(e)
    print("[*] Numpy library is not installed. Please install it.")
    exit

