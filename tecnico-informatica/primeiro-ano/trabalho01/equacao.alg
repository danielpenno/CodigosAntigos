algoritmo "equacao"
// Fun��o :
// Autor :
// Data : 23/3/2009
// Se��o de Declara��es 
var
  a, b, c, delta, x1, x2 : real
inicio
// Se��o de Comandos 
   escreval("==============
   ===========================================================================")
   escreva("Digite o valor de a: ")
   leia(a)
   escreva("Digite o valor de b: ")
   leia(b)
   escreva("Digite o valor de c: ")
   leia(c)
   escreval("=========================================================================================")
   se (c = 0) entao
      escreval("ERRO! O valor de c n�o pode ser 0.")
   senao
      delta <- (b * b) - 4 * a * c
      escreval("O valor de delta �:", delta)
      se (delta < 0) entao
         escreval("A equa��o n�o tem solu��o!")
      fimse
      se (delta = 0) entao
         escreval("A equa��o possui duas solu��es iguais!")
         x1 <- (-b + (delta ^ 0.5)) / (2 * a)
         x2 <- (-b - (delta ^ 0.5)) / (2 * a)
         escreval("Valor de x1:", x1, " - Valor de x2:", x2)
      fimse
      se (delta > 0) entao
         escreval("A equa��o possui duas solu��es diferentes!")
         x1 <- (-b + (delta ^ 0.5)) / (2 * a)
         x2 <- (-b - (delta ^ 0.5)) / (2 * a)
         escreval("Valor de x1:", x1)
         escreval("Valor de x2:", x2)
      fimse
   fimse
   escreval("=========================================================================================")
fimalgoritmo
