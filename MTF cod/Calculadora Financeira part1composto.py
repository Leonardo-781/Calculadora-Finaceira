import math


# Função para converter o tempo
def converter_tempo(tempo, tipo_tempo_atual, tipo_tempo_desejado):
    fatores = {
        ('anual', 'mensal'): 12,
        ('mensal', 'anual'): 1/12,
        ('mensal', 'diario'): 30.44,
        ('diario', 'mensal'): 1/30.44,

    }
    fator = fatores.get((tipo_tempo_atual, tipo_tempo_desejado))
    if fator:
        tempo_convertido = tempo * fator
    else:
        tempo_convertido = tempo
    return tempo_convertido

def calcular_taxa_juros(valor_presente, valor_futuro, tempo, tipo_tempo):
    fatores_tempo = {
        'anual': 1,
        'mensal': 12,
        'diario': 365,
    }
    fator = fatores_tempo.get(tipo_tempo)
    if fator:
        tempo = tempo * fator
    else:
        tempo = tempo

    try:
        taxa = ((valor_futuro / valor_presente) ** (1 / tempo)) - 1
        return taxa
    except ZeroDivisionError:
        return "O tempo não pode ser zero."

def converter_taxa_para_decimal(taxa_porcentagem):
    return taxa_porcentagem / 100

def calcular():
    escolha = input("O que você gostaria de calcular? VP, VF, J, I, N: ").lower()

    if escolha == 'vp':
        tipo_tempo = input("Digite o tipo de tempo (anual/mensal/diario): ").lower()
        tempo = float(input("Digite o tempo: "))
        tipo_taxa = input("Digite o tipo de taxa (anual/mensal/diario): ").lower()
        taxa_porcentagem = float(input("Digite a taxa de juros (%): "))
        valor_futuro = float(input("Digite o valor futuro: "))

        taxa = converter_taxa_para_decimal(taxa_porcentagem)

        if tipo_tempo != tipo_taxa:
            tempo = converter_tempo(tempo, tipo_tempo, tipo_taxa)

        valor_presente = valor_futuro / ((1 + taxa) ** tempo)
        print(f"O valor presente é: {valor_presente}")

    elif escolha == 'vf':
        tipo_tempo = input("Digite o tipo de tempo (anual/mensal/diario): ").lower()
        tempo = float(input("Digite o tempo: "))
        tipo_taxa = input("Digite o tipo de taxa (anual/mensal/diario): ").lower()
        taxa_porcentagem = float(input("Digite a taxa de juros (%): "))
        valor_presente = float(input("Digite o valor presente: "))


        taxa = converter_taxa_para_decimal(taxa_porcentagem)


        if tipo_tempo != tipo_taxa:
            tempo = converter_tempo(tempo, tipo_tempo, tipo_taxa)

        valor_futuro = valor_presente * ((1 + taxa) ** tempo)
        print(f"O valor futuro é: {valor_futuro}")

    elif escolha == 'j':
        tipo_tempo = input("Digite o tipo de tempo (anual/mensal/diario): ").lower()
        tempo = float(input("Digite o tempo: "))
        tipo_taxa = input("Digite o tipo de taxa (anual/mensal/diario): ").lower()
        taxa_porcentagem = float(input("Digite a taxa de juros (%): "))
        valor_presente = float(input("Digite o valor presente: "))

        taxa = converter_taxa_para_decimal(taxa_porcentagem)


        if tipo_tempo != tipo_taxa:
            tempo = converter_tempo(tempo, tipo_tempo, tipo_taxa)

        juros = valor_presente*(((1+taxa)**tempo)-1)
        print(f"O valor dos juros é: {juros}")

    elif escolha == 'i':
        valor_presente = float(input("Digite o valor presente: "))
        valor_futuro = float(input("Digite o valor futuro: "))
        tipo_tempo = input("Digite o tipo de tempo (anual/mensal/diario): ").lower()
        tempo = float(input("Digite o tempo: "))
        taxa = ((valor_futuro / valor_presente) ** (1 / tempo)) - 1

        print(f"A taxa de juros é: {taxa}")


    elif escolha == 'n':
        valor_presente = float(input("Digite o valor presente: "))
        valor_futuro = float(input("Digite o valor futuro: "))
        taxa_porcentagem = float(input("Digite a taxa de juros (%): "))

        taxa = converter_taxa_para_decimal(taxa_porcentagem)

        tempo = math.log(valor_futuro / valor_presente) / math.log(1 + taxa)
        print(f"O tempo convertido é: {tempo}")


    elif escolha == 'cc':
        periodo = float(input("Digite o tempo: "))
        taxa_nominal = float(input("Digite a taxa de juros (%): "))
        taxa = converter_taxa_para_decimal(taxa_nominal)

        #taxa1 = ((1+taxa)**periodo) - 1
        taxa2 = (1+taxa)**(1/periodo) - 1

        #print(f"Taxa equivalencia 1: {taxa1}")
        print(f"Taxa equivalencia 2: {taxa2}")






    else:
        print("Escolha inválida")

calcular()
