import random

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
'y', 'z','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '*', '+', ')', '(']

password = ''

print("Bem-vindo ao gerador de senhas em python")
numLetras = int(input("Quantas letras você deseja na senha?\n"))
numNumeros = int(input("Quantos números você deseja na senha?\n"))
numSimbolos = int(input("Quantos símbolos você deseja na senha?\n"))

numLetrasGeradas = 0
numNumerosGerados = 0
numSimbolosGerados = 0

numSorteado = 0
while (numLetrasGeradas != numLetras or numNumerosGerados != numNumeros or numSimbolosGerados != numSimbolos):
    
    numSorteado = random.randint(1, 3)

    if (numSorteado == 1 and numLetrasGeradas != numLetras):
        password += letters[random.randint(0, len(letters) - 1)]
        numLetrasGeradas += 1
        continue
    elif (numSorteado == 2 and numNumerosGerados != numNumeros):
        password += numbers[random.randint(0, len(numbers) - 1)]
        numNumerosGerados += 1
        continue
    elif (numSorteado == 3 and numSimbolosGerados != numSimbolos):
        password += symbols[random.randint(0, len(symbols) - 1)]
        numSimbolosGerados += 1
        continue

print(password)