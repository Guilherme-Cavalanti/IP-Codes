/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2021                          **/
/**   2021102 - Marcio Moretto Ribeiro                              **/
/**                                                                 **/
/**   Terceiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Guilherme Cavalanti Gomes>                   <11844788>      **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>

#define pecaX 'X'
#define pecaY 'O'
#define espacoVazio ' '

#define true 1
#define false 0

typedef int bool;


/*
	Jogo da Velha - programa para verificar o status de um jogo.

	Lista de Status calculado:
    0 - Jogo nao iniciado: o tabuleiro esta 'vazio', i.e., sem pecas X e O;
    1 - Jogo encerrado1: o primeiro jogador (que usa as pecas X) ganhou;
    2 - Jogo encerrado2: o segundo jogador (que usa as pecas O) ganhou;
    3 - Jogo encerrado3: empate - todas as casas do tabuleiro estao preenchidas com X e O, mas nenhum dos jogadores ganhou;
    4 - Jogo ja iniciado e em andamento: nenhuma das alternativas anteriores.	
 */

/*
	Determina o status de um partida de Jogo da Valha

	Entrada:
		tabuleiro - matriz 3x3 de caracteres representando uma partida valida de Jogo da Velha

	Saida:
		um inteiro contendo o status da partida (valores validos de zero a quatro)
 */

int vitoria(char peca){
    if(peca == pecaX)return 1;
    return 2;
}
int verificaStatus(char tabuleiro[][3]) {
	int status = -1;
    int  i,j;
    int vazios = 0;
    //PARA TABULEIRO VAZIO OU INCOMPLETO
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           if(tabuleiro[i][j] == espacoVazio) vazios++;
        }
    }
    //CASO ESTEJA VAZIO
    if(vazios==9){status = 0; return status;}
    //CASO ALGUEM TENHA VENCIDO
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(tabuleiro[i][j] != espacoVazio){
                //VITÓRIA HORIZONTAL
                if(
                    tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]
                ){
                    status = vitoria(tabuleiro[i][j]); 
                    return status;
                }
                //VITÓRIA VERTICAL
                if(
                    tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]
                ){
                    status = vitoria(tabuleiro[i][j]); 
                    return status;
                }
            }
        }
    }
    //VITÓRIA DIAGONAL
    if(
        tabuleiro[1][1] != espacoVazio &&
        tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] || //DIAGONAL PRA DIREITA
        tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2]    //DIAGONAL PRA ESQUERDA
    ){
        status = vitoria(tabuleiro[1][1]); 
        return status;
    }
    //JOGO INCOMPLETO
    if(vazios>0){status = 4; return status;}
    //JOGO EMPATADO
    status = 3;
	return status;
}

int main(){
	char tab0[][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	char tab1[][3] = {{'X','X','X'},{'O','O',' '},{' ',' ',' '}};
	char tab2[][3] = {{'O','X','X'},{'X','O','O'},{' ',' ','O'}};
	char tab3[][3] = {{'O','X','X'},{'X','O','O'},{'O','X','X'}};
	char tab4[][3] = {{' ',' ',' '},{'X','O','X'},{' ',' ',' '}};

	printf("Status calculado: %i\n", verificaStatus(tab0));
	printf("Status esperado para o tabuleiro0: 0\n\n");

	printf("Status calculado: %i\n", verificaStatus(tab1));
	printf("Status esperado para o tabuleiro1: 1\n\n");

	printf("Status calculado: %i\n", verificaStatus(tab2));
	printf("Status esperado para o tabuleiro2: 2\n\n");
	
	printf("Status calculado: %i\n", verificaStatus(tab3));
	printf("Status esperado para o tabuleiro1: 3\n\n");
	
	printf("Status calculado: %i\n", verificaStatus(tab4));
	printf("Status esperado para o tabuleiro4: 4\n\n");
	
	return 0;
}


/* SAIDA ESPERADA:
Status calculado: 0
Status esperado para o tabuleiro0: 0

Status calculado: 1
Status esperado para o tabuleiro1: 1

Status calculado: 2
Status esperado para o tabuleiro2: 2

Status calculado: 3
Status esperado para o tabuleiro1: 3

Status calculado: 4
Status esperado para o tabuleiro4: 4
*/