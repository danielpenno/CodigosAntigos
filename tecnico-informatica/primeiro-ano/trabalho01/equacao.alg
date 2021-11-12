algoritmo "equacao"
// Função :
// Autor :
// Data : 23/3/2009
// Seção de Declarações 
var
  a, b, c, delta, x1, x2 : real
inicio
// Seção de Comandos 
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
      escreval("ERRO! O valor de c não pode ser 0.")
   senao
      delta <- (b * b) - 4 * a * c
      escreval("O valor de delta é:", delta)
      se (delta < 0) entao
         escreval("A equação não tem solução!")
      fimse
      se (delta = 0) entao
         escreval("A equação possui duas soluções iguais!")
         x1 <- (-b + (delta ^ 0.5)) / (2 * a)
         x2 <- (-b - (delta ^ 0.5)) / (2 * a)
         escreval("Valor de x1:", x1, " - Valor de x2:", x2)
      fimse
      se (delta > 0) entao
         escreval("A equação possui duas soluções diferentes!")
         x1 <- (-b + (delta ^ 0.5)) / (2 * a)
         x2 <- (-b - (delta ^ 0.5)) / (2 * a)
         escreval("Valor de x1:", x1)
         escreval("Valor de x2:", x2)
      fimse
   fimse
   escreval("=========================================================================================")
fimalgoritmo
