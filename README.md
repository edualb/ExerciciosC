# Lista de exercicios de Estrutura de dados 2

# A1

- ## **Exercicio 1:**

    Implemente uma função que faça a inserção em uma lista duplamente encadeada. Esta lista deve ser uma agenda telefônica, com o nome completo e o telefone de cada contato. A inserção na lista deve ser feita em ordem alfabética.

    *Faça o programa no DEV C++, utilizando a estrutura de um Tipo Abstrato de Dados(TAD) com: listaDupEnc.h, listaDupEnc.c e main.c.*

- ## **Exercicio 2:**

    Implemente um tipo abstrato de dados (TAD) que ofereça os serviços para a manipulação de uma pilha encadeada de caracteres. Deverão ser implementadas pelo menos as seguintes funções: 
    
    -   criar pilha
    -   empilhar e desempilhar elementos da pilha 
    -   destruir a estrutura de dados criada
    
    Você pode implementar esta estrutura de dados utilizando vetor ou lista encadeada.

- ## **Exercicio 3:**

    Uma palavra é dita palíndromo se a sequência de letras que a forma é a mesma, se já ela  lida da esquerda para a direita ou vice-versa.
    
    - Exemplos:
        
            arara, raiar, hanah.
    
    Escreva um programa que leia uma string e diga se essa string é palíndromo ou não.
    
    *Utilize a estrutura de dados de pilha implementada na questão 2.* 
    
    Esse programa deve usar uma função (definida no mesmo arquivo do programa principal) que indique se uma dada string é ou não palíndromo.

    Para isso, é preciso inverter a string empilhando todos os seus caracteres e desempilhando-os numa nova string. 
    
    Em seguida compare a string invertida com a original.

    *Protótipo da função:* int eh_palindromo(char palavra[])