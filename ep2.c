/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2021                          **/
/**   2021102 - Marcio Moretto Ribeiro                              **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   Guilherme Cavalanti Gomes                  11844788           **/
/**                                                                 **/
/*********************************************************************/

/*
	Calculo para raiz quadrada
*/

#include <stdio.h>

/*
	Calcula a raiz quadrada de um valor, com uma determinada
	precisao. Retorna esse valor, ou -1 quando:
	
	* a < 0
	* epsilon <= 0
	* epsilon >= 1
	
	Parametro:
		a - valor cuja raiz quadrada sera calculada
		epsilon - precisao do calculo
*/
double modulo(double n){
    if(n>0) return n; 
    return -n;
}
double raizQuadrada(double a, double epsilon){
    double resposta;
    if(a<0 || epsilon>=1 || epsilon<=0)return -1;
    if(a==0)return 0;
    double i = a/2;
    double dif = 1;
    while(dif>epsilon){
        double i1 = 0.5*(i + a/i);
        dif = modulo(i1-i);
        if(dif>epsilon)i = i1;
    }
    resposta = i;
    return resposta;
}
/*
	Apenas para seus testes. ISSO SERA IGNORADO NA CORRECAO
*/
int main() {

	/* escreva seu codigo (para testes) aqui */

	/* Exemplo de teste: */
	double valor = 63;
	double precisao = 0.001;
	printf("Raiz aproximada de %f = %f\n", valor, raizQuadrada(valor, precisao));

	return 0;
}