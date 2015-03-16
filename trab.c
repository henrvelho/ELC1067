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
	int notas_tam=0;
	
	FILE *f= fopen("notas.txt", "r");
if(f == NULL({
	printf("arquivo não foi aberto! não quero brincar ");
	return(0);
}

	while(feof(f) !=0){
		if (fscanf(f, "%d",&not ) < 0)
	break;
c=fgetc(f);
// verifica os espaços vazio entre as strings
	while(c==' '){
c= fgetc(f);
	}
// conta quantos registros tem	
	while(!feof(notas)){
		c = fgetc(notas);
		if( c == '\n')
			notas_tam++;
	}
// verifica se o numero não passa de 50 o permitido
	if(notas_tam > 50){
		fprintf(stderr, "Número de registros do arquivo de notas foi excedido! \n");
		return 0;
	}
	
	while(c=!'\n'){
nome[i]=c;
c=fgetc(f);
i++;
}
nome[i] = '\0';
nota [linha]=not;
strcpy(nota[linha],nome);
linha++;
}
*n=linha;
fclose(f);
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
le_alunos(matriculas,nomes,&n); //chama funcao para ler alunos
le_notas(matriculas); 


}
