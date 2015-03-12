#include<stdio.h>
#include<stdlib.h>


void le_alunos(int *matriculas,char nomes[50][50], int *n){

	
	int linha;
	int mat;
	linha=0;
	char c;
	char nome[50];
	int i=0;
FILE *f= fopen("alunos.txt", "r");
if(f == NULL({
	printf("arquivo não foi aberto! não quero brincar ");
	return(0);
}
while(feof(f) !=0){
	if (fscanf(f, "%d",&mat ) < 0) 
			break;

c=fgetc(f);
	while(c==' '){
		c= fgetc(f);
	}
		while(c=!'\n'){
			nome[i]=c;
			c=fgetc(f);
			i++;

	}
nome[i] = '\0';
matriculas [linha]=mat;
strcpy(nomes[linha],nome);
linha++;

	}
*n=linha;
fclose(f);

}

void le_notas(int *matricula){
	FILE *f= fopen("alunos.txt", "r");
if(f == NULL({
	printf("arquivo não foi aberto! não quero brincar ");
	return(0);
}
	
}

int main(int argc, char **argv){

char *nome;
	if(argc>1){
	   nome= argv[1];
	}
printf("%s\n",nome);
int matricula[50];
char nomes[50][50];
int n;
le_alunos(matriculas,nomes,&n);


}
