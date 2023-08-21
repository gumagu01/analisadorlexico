# Define as palavras-chave e operadores do Python
import keyword

keywords = keyword.kwlist
operators = ['+', '-', '*', '/', '>', '<', '=', '==', '!=', '<=', '>=', 'and', 'or', 'not']

# Função para verificar se um caractere é um delimitador
def isDelimiter(ch):
    delimiters = " \n\t;,()[]{}"
    return ch in delimiters

# Função para verificar se uma string é uma palavra-chave
def isKeyword(word):
    return word in keywords

# Função para verificar se uma string é um operador
def isOperator(ch):
    return ch in operators

# Função para verificar se uma string é um número inteiro
def isInteger(word):
    return word.isdigit() or (word[0] == '-' and word[1:].isdigit())

# Função para verificar se uma string é um número real
def isRealNumber(word):
    try:
        float(word)
        return True
    except ValueError:
        return False

# Função para analisar a entrada e imprimir os tokens
def parse(input_str):
    token = ""
    index = 0

    while index < len(input_str):
        ch = input_str[index]

        if isDelimiter(ch):
            if token:
                if isKeyword(token):
                    print(f"'{token}' É UMA PALAVRA-CHAVE")
                elif isInteger(token):
                    print(f"'{token}' É UM NÚMERO INTEIRO")
                elif isRealNumber(token):
                    print(f"'{token}' É UM NÚMERO REAL")
                else:
                    print(f"'{token}' É UM IDENTIFICADOR VÁLIDO")
                token = ""
            if isOperator(ch):
                print(f"'{ch}' É UM OPERADOR")
            index += 1

        else:
            token += ch
            index += 1

# Função principal
def main():
    input_str = "int a = b + 1c; "
    parse(input_str)

if __name__ == "_main_":
    main()
