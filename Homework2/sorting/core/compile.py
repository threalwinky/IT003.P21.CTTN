import os

try:
    for file in list(os.listdir("script")):
        if (file.endswith(".cpp")):
            os.system(f"g++ script/{file} -o executable/{file[:-4]}")
            print(f"[*] Compile {file} successfully")
        elif (file.endswith(".py")):
            print(f"[*] Copy {file} to executable")
            os.system(f"cp script/{file} executable/{file}")
except:
    print("[*] Compile failed.")