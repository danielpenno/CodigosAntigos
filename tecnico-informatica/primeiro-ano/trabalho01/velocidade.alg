algoritmo "velocidade"
// Função :
// Autor :
// Data : 16/3/2009
// Seção de Declarações 
var
  x, y : real
inicio
// Seção de Comandos 
   escreval("=========================================================================================")
   escreva("Digite a velocidade máxima permitida(km/h): ")
   leia(x)
   escreva("Digite a velocidade em que o motorista estava dirigindo(km/h): ")
   leia(y)
      se (y < x) entao
      escreval("=========================================================================================")
      escreval("Velocidade máxima permitida:", x, "km/h")
      escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
      escreval("Parabéns! Continue dirigindo calmo desse jeito.")
      escreval("=========================================================================================")
   fimse
   se (y = x) entao
      escreval("=========================================================================================")
      escreval("Velocidade máxima permitida:", x, "km/h")
      escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
      escreval("Cuidado! Dirija com mais cuidado da próxima vez.")
      escreval("=========================================================================================")
   fimse
   se (y > x) entao
      se ((y >= (x + 1)) e (y <= (x + 10))) entao
         escreval("=========================================================================================")
         escreval("Velocidade máxima permitida:", x, "km/h")
         escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
         escreval("Valor da multa: R$50,00")
         escreval("=========================================================================================")
      fimse
      se ((y >= (x + 11)) e (y <= (x + 30))) entao
         escreval("=========================================================================================")
         escreval("Velocidade máxima permitida:", x, "km/h")
         escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
         escreval("Valor da multa: R$100,00")
         escreval("=========================================================================================")
      fimse
      se (y >= (x + 31)) entao
         escreval("=========================================================================================")
         escreval("Velocidade máxima permitida:", x, "km/h")
         escreval("Velocidade que o motorista estava dirigindo:", y, "km/h")
         escreval("Valor da multa: R$200,00")
         escreval("=========================================================================================")
      fimse
   fimse
fimalgoritmo

