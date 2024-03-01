import random
from colorama import Fore, Style, init

init(autoreset=True)

colors = [Fore.RED, Fore.YELLOW, Fore.GREEN, Fore.BLUE, Fore.MAGENTA]

for i in range(30):
    treeText = " " * (30 - i)
    treeText += "".join([random.choice(colors) + "#" if j % 2 == 0 else " " for j in range(i * 2 + 1)])
    print(treeText)

for _ in range(3):
    trunkText = " " * 27 + "# # #"
    trunkText = "".join([random.choice(colors) + char for char in trunkText])
    print(trunkText)
