# Programa feito para fazer textos personalizados em escala.
# Ao fornecer um texto como template, e fornecendo os dados (nome,
# endereço, etc.) é completado um template para tornar o texto
# personalizado de maneira automática


n = int(input('Digite a quantidade de nomes:\n'))
print('Digite os nomes\n')

nome = []
for i in range(n):
    nome[i] = input(f'Digite o {i}º nome\n')

texto = input()

for i in range(n):
    print(texto)
