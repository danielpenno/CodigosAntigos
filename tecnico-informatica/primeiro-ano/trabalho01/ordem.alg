algoritmo "ordem"
// Fun��o :
// Autor :
// Data : 22/3/2009
// Se��o de Declara��es 
var
  i : inteiro
  a, b, c : real
inicio
// Se��o de Comandos 
   escreval("=========================================================================================")
   escreva("Digite o valor de i: ")
   leia(i)
   escreva("Digite o valor de a: ")
   leia(a)
   escreva("Digite o valor de b: ")
   leia(b)
   escreva("Digite o valor de c: ")
   leia(c)
   escreval("=========================================================================================")
   se (i = 1) entao
      se ((a < b) e (a < c)) entao
         se (b < c) entao
            escreval("A ordem crescente �:", a,",", b, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem crescente �:", a,",", c, ",", b)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((b < a) e (b < c)) entao
         se (a < c) entao
            escreval("A ordem crescente �:", b,",", a, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem crescente �:", b,",", c, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((c < a) e (c < b)) entao
         se (a < b) entao
            escreval("A ordem crescente �:", c,",", a, ",", b)
            escreval("=========================================================================================")
         senao
            escreval("A ordem crescente �:", c,",", b, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((a = b) ou (a = c) ou (c = b)) entao
         escreval("ERRO! Digite n�meros diferentes e tente novamente.")
         escreval("=========================================================================================")
      fimse
   fimse
   se (i = 2) entao
      se ((a > b) e (a > c)) entao
         se (b > c) entao
            escreval("A ordem decrescente �:", a,",", b, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem decrescente �:", a,",", c, ",", b)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((b > a) e (b > c)) entao
         se (a > c) entao
            escreval("A ordem decrescente �:", b,",", a, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem decrescente �:", b,",", c, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((c > a) e (c > b)) entao
         se (a > b) entao
            escreval("A ordem decrescente �:", c,",", a, ",", b)
            escreval("=========================================================================================")
         senao
            escreval("A ordem decrescente �:", c,",", b, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((a = b) ou (a = c) ou (c = b)) entao
         escreval("ERRO! Digite n�meros diferentes e tente novamente.")
         escreval("=========================================================================================")
      fimse
   fimse
   se (i = 3) entao
      se ((a < b) e (a < c)) entao
         se (b > c) entao
            escreval("A ordem pedida �:", a,",", b, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem pedida �:", a,",", c, ",", b)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((b < a) e (b < c)) entao
         se (a > c) entao
            escreval("A ordem pedida �:", b,",", a, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem pedida �:", b,",", c, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((c < a) e (c < b)) entao
         se (a > b) entao
            escreval("A ordem pedida �:", c,",", a, ",", b)
            escreval("=========================================================================================")
         senao
            escreval("A ordem pedida �:", c,",", b, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((a = b) ou (a = c) ou (c = b)) entao
         escreval("ERRO! Digite n�meros diferentes e tente novamente.")
         escreval("=========================================================================================")
      fimse
   fimse
fimalgoritmo
