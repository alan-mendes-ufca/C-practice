/*
3) Crie um programa em C que utilize uma struct para armazenar informações
básicas de um produto e calcule seu preço de venda final.
a) Crie uma struct chamada Produto que contenha: codigo: Um inteiro
(int). preco_custo: Um valor de ponto flutuante (float).
percentual_lucro: Um valor de ponto flutuante (float).
b) Crie uma função chamada ler_produto com o seguinte protótipo:
Produto ler_produto();
Esta função deve solicitar ao usuário o código, o preço de custo e o
percentual de lucro do produto. A função deve retornar uma nova
struct Produto preenchida
c) Crie uma função chamada calcular_preco_venda com o seguinte
protótipo:
float calcular_preco_venda(Produto p);
Calcule o preço de venda final usando a fórmula:

d) Na main, chame a função ler_produto e armazene o resultado em uma
variável local. Chame a função calcular_preco_venda passando a
struct lida. Imprima todos os dados do produto (código, custo, lucro) e
o Preço de Venda Final calculado.
*/