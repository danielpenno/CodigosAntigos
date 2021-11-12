algoritmo "eleicao"
// Fun��o :
// Autor :
// Data : 23/3/2009
// Se��o de Declara��es 
var
   c1, c2, c3, b, n, t : inteiro
   por_b, por_n: real
inicio
// Se��o de Comandos
   escreval("=========================================================================================")
   escreva("Digite quantidade de votos do primeiro candidato: ")
   leia(c1)
   escreva("Digite quantidade de votos do segundo candidato: ")
   leia(c2)
   escreva("Digite quantidade de votos do terceiro candidato: ")
   leia(c3)
   escreva("Digite quantidade de votos em branco: ")
   leia(b)
   escreva("Digite quantidade de votos nulos: ")
   leia(n)
   escreval("=========================================================================================")
   t <- c1 + c2 + c3 + b + n
   por_n <- (n * 100) / t
   por_b <- (b * 100) / t
   escreval("Total de votos:", t)
   escreval("Total de votos do primeiro candidato:", c1)
   escreval("Total de votos do segundo candidato:", c2)
   escreval("Total de votos do terceiro candidato:", c3)
   escreval("Total de votos nulos:", n)
   escreval("Total de votos em branco:", b)
   escreval("Porcentagem de votos nulos em rela��o ao total:", por_n)
   escreval("Porcentagem de votos em branco em rela��o ao total:", por_b)
   escreval("=========================================================================================")
fimalgoritmo
