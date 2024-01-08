/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2021                          **/
/**   2021102 - Marcio Moretto Ribeiro                              **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   Guilherme Cavalanti Gomes                  11844788           **/
/**                                                                 **/
/*********************************************************************/

/*
	Caixa eletronico das Ilhas Weblands, com estoque ilimitado de cedulas
	de B$50,00, B$20,00, B$5,00 e B$1,00.
*/

#include <stdio.h>

/* Numero de cedulas de B$50,00 */
int n50;
	
/* Numero de cedulas de B$20,00 */
int n20;

/* Numero de cedulas de B$5,00 */
int n5;
	
/* Numero de cedulas de B$1,00 */
int n1;


/*
	Determina a quantidade de cada nota necessaria para totalizar
	um determinado valor de retirada, de modo a minimizar a quantidade
	de cÃ©dulas entregues.
	
	Abastece as variaveis globais n50, n20, n5 e n1 com seu respectivo
	numero de cedulas.
	
	Parametro:
		valor - O valor a ser retirado
*/
void fazRetirada(int valor) {
    int total = valor;
    //VALOR NAO ACEITAVEL
    if(total < 0){
        n50 = -1;
        n20 = -1;
        n5  = -1;
        n1  = -1;
        return;
    }
    //VALOR NORMAL
    n50 = 0;
    n20 = 0;
    n5  = 0;
    n1  = 0;
    int i = 0;
    while (i!=1)
    {
        //CONTA QUANTAS NOTAS CABEM E SUBTRAI DO VALOR TOTAL
        if(total - 50 >= 0){
            total -= 50;
            n50 ++;
        }
        //NAO CABEM MAIS NOTAS
        else{i = 1;}
    }
    if (total == 0){return;} //CASO JA TENHA ACABADO TUDO
    
    //MESMO CÓDIGO PRAS OUTRAS NOTAS ATÉ ACABAR TUDO
    i = 0;
    //NOTAS DE 20
    while (i!=1)
    {
        if(total - 20 >= 0){
            total -= 20;
            n20 ++;
        }
        else{i = 1;}
    }
    if (total == 0){return;}
    i = 0;
    //NOTAS DE 5
    while (i!=1)
    {
        if(total - 5 >= 0){
            total -= 5;
            n5 ++;
        }
        else{i = 1;}
    }
    if (total == 0){return;}
    i = 0;
    //NOTAS DE 1
    while (i!=1)
    {
        if(total - 1 >= 0){
            total -= 1;
            n1 ++;
        }
        else{i = 1;}
    }
}

/*
	Funcao main apenas para seus testes. ISSO SERA IGNORADO NA CORRECAO
*/
int main() {
	int valor;
	valor = 138;
	fazRetirada(valor);
	printf("Valor: %i\n",valor);
	printf("Notas de 50: %i\n", n50);
	printf("Notas de 20: %i\n", n20);
	printf("Notas de 5:  %i\n", n5);
	printf("Notas de 1:  %i\n", n1);    
	valor = -21;
	fazRetirada(valor);
	printf("Valor: %i\n",valor);
	printf("Notas de 50: %i\n", n50);
	printf("Notas de 20: %i\n", n20);
	printf("Notas de 5:  %i\n", n5);
	printf("Notas de 1:  %i\n", n1);
    valor = 0;
	fazRetirada(valor);
	printf("Valor: %i\n",valor);
	printf("Notas de 50: %i\n", n50);
	printf("Notas de 20: %i\n", n20);
	printf("Notas de 5:  %i\n", n5);
	printf("Notas de 1:  %i\n", n1);
	return 0;
}