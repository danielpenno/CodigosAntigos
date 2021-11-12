algoritmo "media"
// Fun��o :
// Autor :
// Data : 9/3/2009
// Se��o de Declara��es
var
 x, y, z, media, recuperacao : real
inicio
// Se��o de Comandos
 escreval("=========================================================================================")
 escreva("Digite o valor da primeira nota: ")
 leia(x)
 escreva("Digite o valor da segunda nota: ")
 leia(y)
 escreval("=========================================================================================")
 media <- (x + y) / 2
 se (media >= 7) entao
    escreval("M�dia:", media, " - Situa��o: Aprovado")
    escreval("=========================================================================================")
 fimse
 se ((media >= 5) e (media < 7)) entao
    escreval("M�dia:", media, " - Situa��o: Recupera��o")
    escreval("=========================================================================================")
    escreva("Digite o valor da nota na prova de recupera��o: ")
    leia(z)
    escreval("=========================================================================================")
    recuperacao <- media + z
    se (recuperacao >= 10) entao
       escreval("Nota na prova de recuperaca��o:", z, " - Situa��o: Aprovado")
       escreval("=========================================================================================")
    fimse
    se (recuperacao < 10) entao
       escreval("Nota na prova de recuperaca��o:", z, " - Situa��o: Reprovado")
       escreval("=========================================================================================")
    fimse
 fimse
 se (media < 5) entao
    escreval("M�dia:", media, " - Situa��o: Em Constru��o")
    escreval("=========================================================================================")
 fimse
fimalgoritmo