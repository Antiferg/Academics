import random

try:
    from termcolor import colored
except ImportError:
    from colorama import Fore, init
    init(autoreset=True)

    colors = [Fore.RED, Fore.YELLOW, Fore.GREEN, Fore.BLUE, Fore.MAGENTA]

for i in range(30):
    treeText = " " * (29 - i)
    if 'colored' in locals():
        treeText += "".join([colored("#", random.choice(colors)) if j % 2 == 0 else " " for j in range(i * 2 + 1)])
    else:
        treeText += "".join([random.choice(colors) + ("#" if j % 2 == 0 else " ") for j in range(i * 2 + 1)])
    print(treeText)

if 'colored' not in locals():
    for _ in range(3):
        print(" " * 27 + f"{'# '.join([random.choice(colors) for _ in range(3)])}#")
