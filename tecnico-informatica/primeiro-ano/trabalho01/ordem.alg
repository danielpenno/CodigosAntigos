algoritmo "ordem"
// Função :
// Autor :
// Data : 22/3/2009
// Seção de Declarações 
var
  i : inteiro
  a, b, c : real
inicio
// Seção de Comandos 
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
            escreval("A ordem crescente é:", a,",", b, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem crescente é:", a,",", c, ",", b)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((b < a) e (b < c)) entao
         se (a < c) entao
            escreval("A ordem crescente é:", b,",", a, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem crescente é:", b,",", c, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((c < a) e (c < b)) entao
         se (a < b) entao
            escreval("A ordem crescente é:", c,",", a, ",", b)
            escreval("=========================================================================================")
         senao
            escreval("A ordem crescente é:", c,",", b, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((a = b) ou (a = c) ou (c = b)) entao
         escreval("ERRO! Digite números diferentes e tente novamente.")
         escreval("=========================================================================================")
      fimse
   fimse
   se (i = 2) entao
      se ((a > b) e (a > c)) entao
         se (b > c) entao
            escreval("A ordem decrescente é:", a,",", b, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem decrescente é:", a,",", c, ",", b)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((b > a) e (b > c)) entao
         se (a > c) entao
            escreval("A ordem decrescente é:", b,",", a, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem decrescente é:", b,",", c, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((c > a) e (c > b)) entao
         se (a > b) entao
            escreval("A ordem decrescente é:", c,",", a, ",", b)
            escreval("=========================================================================================")
         senao
            escreval("A ordem decrescente é:", c,",", b, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((a = b) ou (a = c) ou (c = b)) entao
         escreval("ERRO! Digite números diferentes e tente novamente.")
         escreval("=========================================================================================")
      fimse
   fimse
   se (i = 3) entao
      se ((a < b) e (a < c)) entao
         se (b > c) entao
            escreval("A ordem pedida é:", a,",", b, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem pedida é:", a,",", c, ",", b)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((b < a) e (b < c)) entao
         se (a > c) entao
            escreval("A ordem pedida é:", b,",", a, ",", c)
            escreval("=========================================================================================")
         senao
            escreval("A ordem pedida é:", b,",", c, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((c < a) e (c < b)) entao
         se (a > b) entao
            escreval("A ordem pedida é:", c,",", a, ",", b)
            escreval("=========================================================================================")
         senao
            escreval("A ordem pedida é:", c,",", b, ",", a)
            escreval("=========================================================================================")
         fimse
      fimse
      se ((a = b) ou (a = c) ou (c = b)) entao
         escreval("ERRO! Digite números diferentes e tente novamente.")
         escreval("=========================================================================================")
      fimse
   fimse
fimalgoritmo
