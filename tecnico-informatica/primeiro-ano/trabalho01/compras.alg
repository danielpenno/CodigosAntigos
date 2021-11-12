algoritmo "compras"
// Função :
// Autor :
// Data : 24/3/2009
// Seção de Declarações 
var
  leite_preco1, leite_preco2, leite_preco3 : real
  achoc_preco1, achoc_preco2, achoc_preco3 : real
  bisc_preco1, bisc_preco2, bisc_preco3 : real
  leite_preco, achoc_preco, bisc_preco : real
  total, total2, desconto : real
  leite_merc, achoc_merc, bisc_merc : inteiro
inicio
// Seção de Comandos
   escreval("=========================================================================================")
   escreva("Digite o preço do leite longa vida no supermercado O Barateiro(R$): ")
   leia(leite_preco1)
   escreva("Digite o preço do leite longa vida no supermercado Boas Compras(R$): ")
   leia(leite_preco2)
   escreva("Digite o preço do leite longa vida no supermercado Leva Mais(R$): ")
   leia(leite_preco3)
   escreval("=========================================================================================")
   se ((leite_preco1 < leite_preco2) e (leite_preco1 < leite_preco3)) entao
      escreval("O preço do leite longa vida mais barato está no supermercado O Barateiro.")
      leite_merc <- 1
      leite_preco <- leite_preco1
   fimse
   se ((leite_preco2 < leite_preco1) e (leite_preco2 < leite_preco3)) entao
      escreval("O preço do leite longa vida mais barato está no supermercado Boas Compras.")
      leite_merc <- 2
      leite_preco <- leite_preco2
   fimse
   se ((leite_preco3 < leite_preco1) e (leite_preco3 < leite_preco2)) entao
      escreval("O preço do leite longa vida mais barato está no supermercado Leva Mais.")
      leite_merc <- 3
      leite_preco <- leite_preco3
   fimse
   se ((leite_preco1 = leite_preco2) e (leite_preco1 < leite_preco3)) entao
      escreval("O preço do leite longa vida mais barato está no supermercado O Barateiro.")
      leite_merc <- 1
      leite_preco <- leite_preco1
   fimse
   se ((leite_preco1 = leite_preco3) e (leite_preco1 < leite_preco2)) entao
      escreval("O preço do leite longa vida mais barato está no supermercado O Barateiro.")
      leite_merc <- 1
      leite_preco <- leite_preco1
   fimse
   se ((leite_preco2 = leite_preco3) e (leite_preco2 < leite_preco1)) entao
      escreval("O preço do leite longa vida mais barato está no supermercado Boas Compras.")
      leite_merc <- 2
      leite_preco <- leite_preco2
   fimse
   se ((leite_preco1 = leite_preco2) e (leite_preco1 = leite_preco3)) entao
      escreval("O preço do leite longa vida mais barato está no supermercado O Barateiro.")
      leite_merc <- 1
      leite_preco <- leite_preco1
   fimse
   
// Achocolatado em Pó
   
   escreval("=========================================================================================")
   escreva("Digite o preço do achocolatado em pó no supermercado O Barateiro(R$): ")
   leia(achoc_preco1)
   escreva("Digite o preço do achocolatado em pó no supermercado Boas Compras(R$): ")
   leia(achoc_preco2)
   escreva("Digite o preço do achocolatado em pó no supermercado Leva Mais(R$): ")
   leia(achoc_preco3)
   escreval("=========================================================================================")
   se ((achoc_preco1 < achoc_preco2) e (achoc_preco1 < achoc_preco3)) entao
      escreval("O preço do achocolatado em pó mais barato está no supermercado O Barateiro.")
      achoc_merc <- 1
      achoc_preco <- achoc_preco1
   fimse
   se ((achoc_preco2 < achoc_preco1) e (achoc_preco2 < achoc_preco3)) entao
      escreval("O preço do achocolatado em pó mais barato está no supermercado Boas Compras.")
      achoc_merc <- 2
      achoc_preco <- achoc_preco2
   fimse
   se ((achoc_preco3 < achoc_preco1) e (achoc_preco3 < achoc_preco2)) entao
      escreval("O preço do achocolatado em pó mais barato está no supermercado Leva Mais.")
      achoc_merc <- 3
      achoc_preco <- achoc_preco3
   fimse
   se ((achoc_preco1 = achoc_preco2) e (achoc_preco1 < achoc_preco3)) entao
      escreval("O preço do achocolatado em pó mais barato está no supermercado O Barateiro.")
      achoc_merc <- 1
      achoc_preco <- achoc_preco1
   fimse
   se ((achoc_preco1 = achoc_preco3) e (achoc_preco1 < achoc_preco2)) entao
      escreval("O preço do achocolatado em pó mais barato está no supermercado O Barateiro.")
      achoc_merc <- 1
      achoc_preco <- achoc_preco1
   fimse
   se ((achoc_preco2 = achoc_preco3) e (achoc_preco2 < achoc_preco1)) entao
      escreval("O preço do achocolatado em pó mais barato está no supermercado Boas Compras.")
      achoc_merc <- 2
      achoc_preco <- achoc_preco2
   fimse
   se ((achoc_preco1 = achoc_preco2) e (achoc_preco1 = achoc_preco3)) entao
      escreval("O preço do achocolatado em pó mais barato está no supermercado O Barateiro.")
      achoc_merc <- 1
      achoc_preco <- achoc_preco1
   fimse
   
// Biscoito

   escreval("=========================================================================================")
   escreva("Digite o preço do biscoito no supermercado O Barateiro(R$): ")
   leia(bisc_preco1)
   escreva("Digite o preço do biscoito no supermercado Boas Compras(R$): ")
   leia(bisc_preco2)
   escreva("Digite o preço do biscoito no supermercado Leva Mais(R$): ")
   leia(bisc_preco3)
   escreval("=========================================================================================")
   se ((bisc_preco1 < bisc_preco2) e (bisc_preco1 < bisc_preco3)) entao
      escreval("O preço do biscoito mais barato está no supermercado O Barateiro.")
      bisc_merc <- 1
      bisc_preco <- bisc_preco1
   fimse
   se ((bisc_preco2 < bisc_preco1) e (bisc_preco2 < bisc_preco3)) entao
      escreval("O preço do biscoito mais barato está no supermercado Boas Compras.")
      bisc_merc <- 2
      bisc_preco <- bisc_preco2
   fimse
   se ((bisc_preco3 < bisc_preco1) e (bisc_preco3 < bisc_preco2)) entao
      escreval("O preço do biscoito mais barato está no supermercado Leva Mais.")
      bisc_merc <- 3
      bisc_preco <- bisc_preco3
   fimse
   se ((bisc_preco1 = bisc_preco2) e (bisc_preco1 < bisc_preco3)) entao
      escreval("O preço do biscoito mais barato está no supermercado O Barateiro.")
      bisc_merc <- 1
      bisc_preco <- bisc_preco1
   fimse
   se ((bisc_preco1 = bisc_preco3) e (bisc_preco1 < bisc_preco2)) entao
      escreval("O preço do biscoito mais barato está no supermercado O Barateiro.")
      bisc_merc <- 1
      bisc_preco <- bisc_preco1
   fimse
   se ((bisc_preco2 = bisc_preco3) e (bisc_preco2 < bisc_preco1)) entao
      escreval("O preço do biscoito mais barato está no supermercado Boas Compras.")
      bisc_merc <- 2
      bisc_preco <- bisc_preco2
   fimse
   se ((bisc_preco1 = bisc_preco2) e (bisc_preco1 = bisc_preco3)) entao
      escreval("O preço do biscoito mais barato está no supermercado O Barateiro.")
      bisc_merc <- 1
      bisc_preco <- bisc_preco1
   fimse

// Total
   escreval("=========================================================================================")
   total <- (12 * leite_preco) + (achoc_preco) + (20 * bisc_preco)
   escreval("Total das compras: R$", total)
   se ((leite_merc = 1) e (achoc_merc = 1) e (bisc_merc = 1)) entao
      desconto <- (total / 100) * 10
      total2 <- total - desconto
      escreval("Você comprou todos os prod. no mesmo sup., então você possui 10% de desconto.")
      escreval("Total com 10% de desconto: R$", total2)
   fimse
   se ((leite_merc = 2) e (achoc_merc = 2) e (bisc_merc = 2)) entao
      desconto <- (total / 100) * 10
      total2 <- total - desconto
      escreval("Você comprou todos os prod. no mesmo sup., então você possui 10% de desconto.")
      escreval("Total com 10% de desconto: R$", total2)
   fimse
   se ((leite_merc = 3) e (achoc_merc = 3) e (bisc_merc = 3)) entao
      desconto <- (total / 100) * 10
      total2 <- total - desconto
      escreval("Você comprou todos os prod. no mesmo sup., então você possui 10% de desconto.")
      escreval("Total com 10% de desconto: R$", total2)
   fimse
   escreval("=========================================================================================")
fimalgoritmo
