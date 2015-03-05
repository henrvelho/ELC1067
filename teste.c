#include<stdio.h>
int main(){
FILE *f;
	int matricula;
	char nome[100];
	printf("digite a matricula: ");
	scanf("%d", &matricula);
	printf("digite o nome: ");
	scanf("%s", nome);
	f = fopen ("saida.txt", 'w');
	fprint("saida.txt", " %d %s \n", matricula, nome);
	fclose(saida.txt);
}
	
