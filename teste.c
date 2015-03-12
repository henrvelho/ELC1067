#include<stdio.h>
int main(){
FILE *arquivo;
	int matricula;
	char nome[100];
	printf("digite a matricula: ");
	scanf("%d", &matricula);
	printf("digite o nome: ");
	scanf("%s", nome);
	arquivo = fopen ("saida.txt", "w");
	fprint(arquivo, " %d %s \n", matricula, nome);
	fclose(arquivo);
}
	
