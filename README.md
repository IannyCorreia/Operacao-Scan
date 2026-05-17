# Operacao-Scan
# Algoritmos de Redução Paralela

Este repositório contém uma atividade acadêmica sobre algoritmos de redução/soma prefixada, com o objetivo de comparar o funcionamento dos algoritmos **Reduce Serial**, **Hillis-Steele** e **Blelloch**.

## Tecnologias utilizadas

![C](https://img.shields.io/badge/C-Language-blue?style=for-the-badge&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-Compiler-orange?style=for-the-badge&logo=gnu&logoColor=white)
![LeetGPU](https://img.shields.io/badge/LeetGPU-Playground-purple?style=for-the-badge)
![Algoritmos](https://img.shields.io/badge/Algoritmos-Redução%20Paralela-green?style=for-the-badge)

## Objetivo da atividade

Analisar diferentes abordagens para operações de redução, considerando:

- tempo de execução;
- quantidade de trabalho realizado;
- número de passos necessários;
- comportamento dos algoritmos conforme o tamanho do array aumenta.

## Algoritmos implementados

### Reduce Serial

Algoritmo sequencial usado como base de comparação. Ele percorre o array elemento por elemento, acumulando os valores.

### Hillis-Steele

Algoritmo de soma prefixada que realiza a operação em múltiplas etapas, dobrando a distância de comparação a cada passo.

### Blelloch

Algoritmo de soma prefixada baseado em duas fases principais:

- **up-sweep**: construção das somas parciais;
- **down-sweep**: redistribuição dos valores para formar o resultado final.

## Tamanhos de entrada testados

Os algoritmos foram testados com arrays dos seguintes tamanhos:

```text
100
1.000
10.000
100.000
1.000.000
10.000.000

```
Ambiente de execução

Os códigos foram executados em ambiente online, utilizando o playground do LeetGPU:
```text

https://leetgpu.com/playground
```

A execução foi realizada nesse ambiente por não haver uma GPU local configurada para os testes.
Os tempos de execução podem variar conforme o ambiente, hardware disponível e carga do sistema no momento da execução.
