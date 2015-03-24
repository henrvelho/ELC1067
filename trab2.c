#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void le_alunos(int *matriculas,char nomes[50][50], int *n){

	
	int linha;
	int mat;
	linha=0;
	char c, *retorno;
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
strcpy(nomes[linha],nome); //copia o nome com a linha
linha++;

	}
*n=linha;
	fseek(alunos, 0, SEEK_SET); //vai para o inicio do arquivo
	while(fgets(linha, 100, alunos)){
		sscanf(linha ,"%d %[^\n]s", &item_aluno.matricula, &item_aluno.nome); //verifica se o nome é o mesmo passado na funcção
		retorno = strstr(item_aluno.nome, argv[1]);
		if(retorno != NULL){ 
			printf("%f %s \n", calculaMedia(vetor_nota, notas_tam, item_aluno.matricula), item_aluno.nome); // irá printar o nome e a media
		}
	}
fclose(f);

}

void le_notas(int *matricula){
	int notas_tam=0;
	
	FILE *f= fopen("notas.txt", "r"); //abre arquivo notas
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
