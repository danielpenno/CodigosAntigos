algoritmo "velocidade"
// Fun��o :
// Autor :
// Data : 16/3/2009
// Se��o de Declara��es 
var
  x, y : real
inicio
// Se��o de Comandos 
   escreval("=========================================================================================")
   escreva("Digite a velocidade m�xima permitida(km/h): ")
   leia(x)
   escreva("Digite a velocidade em que o motorista estava dirigindo(km/h): ")
   leia(y)
      se (y < x) entao
      escreval("=========================================================================================")
      escreval("Velocidade m�xima permitida:", x, "km/h")
      escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
      escreval("Parab�ns! Continue dirigindo calmo desse jeito.")
      escreval("=========================================================================================")
   fimse
   se (y = x) entao
      escreval("=========================================================================================")
      escreval("Velocidade m�xima permitida:", x, "km/h")
      escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
      escreval("Cuidado! Dirija com mais cuidado da pr�xima vez.")
      escreval("=========================================================================================")
   fimse
   se (y > x) entao
      se ((y >= (x + 1)) e (y <= (x + 10))) entao
         escreval("=========================================================================================")
         escreval("Velocidade m�xima permitida:", x, "km/h")
         escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
         escreval("Valor da multa: R$50,00")
         escreval("=========================================================================================")
      fimse
      se ((y >= (x + 11)) e (y <= (x + 30))) entao
         escreval("=========================================================================================")
         escreval("Velocidade m�xima permitida:", x, "km/h")
         escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
         escreval("Valor da multa: R$100,00")
         escreval("=========================================================================================")
      fimse
      se (y >= (x + 31)) entao
         escreval("=========================================================================================")
         escreval("Velocidade m�xima permitida:", x, "km/h")
         escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
         escreval("Valor da multa: R$200,00")
         escreval("=========================================================================================")
      fimse
   fimse
fimalgoritmo

