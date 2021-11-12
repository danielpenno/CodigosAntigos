algoritmo "imc"
var
   x, y, imc : real
inicio
   escreval("=========================================================================================")
   escreva("Digite o valor de peso: ")
   leia(x)
   escreva("Digite o valor de altura: ")
   leia(y)
   escreval("=========================================================================================")
   imc <- x / (y * y)
   escreval("O imc da pessoa é de", imc, ".")
   se (imc < 18.5) entao
      escreval("A pessoa está abaixo do peso ideal.")
      escreval("=========================================================================================")
   fimse
   se ((imc > 18.5) e (imc < 24.9)) entao
      escreval("A pessoa está com o peso normal.")
      escreval("=========================================================================================")
   fimse
   se ((imc > 25.0) e (imc < 29.9)) entao
      escreval("A pessoa está acima do peso.")
      escreval("=========================================================================================")
   fimse
   se ((imc > 30) e (imc < 34.9)) entao
      escreval("A pessoa está com obesidade de Grau I.")
      escreval("=========================================================================================")
   fimse
   se ((imc > 35.0) e (imc < 39.9)) entao
      escreval("A pessoa está com obesidade de Grau II.")
      escreval("=========================================================================================")
   fimse
   se (imc > 40) entao
      escreval("A pessoa está com obesidade de Grau III.")
      escreval("=========================================================================================")
   fimse

fimalgoritmo
