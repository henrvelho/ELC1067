#include <stdio.h>
#include <stdlib.h>

typedef struct PIXEL {
    int r, g, b;
} PIXEL;

typedef struct IMAGEM {
    int largura;
    int altura;
    int maxcor;
    PIXEL *pixels;
} IMAGEM;

IMAGEM *nova_imagem(int largura, int altura, int maxcor) {
    IMAGEM *imagem = (IMAGEM *) malloc(sizeof(IMAGEM));
    imagem->pixels = (PIXEL *) malloc(largura * altura * sizeof(PIXEL));
    imagem->largura = largura;
    imagem->altura = altura;
    imagem->maxcor = maxcor;
    return imagem;
}

void destruir_imagem(IMAGEM *imagem) {
    free(imagem->pixels);
    free(imagem);
}

PIXEL *pixel_da_imagem(IMAGEM *imagem, int x, int y) {
    return &(imagem->pixels[y * imagem->largura + x]);
}

IMAGEM *ler_arquivo_ppm_p3(const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) return NULL;
    int largura, altura, maxcor, x, y;
    IMAGEM *imagem = NULL;
    char formato[6];
    fgets(formato, 6, arq);
    if (strcmp("P3\n", formato) == 0) {
        fscanf(arq, "%d", &largura);
        fscanf(arq, "%d", &altura);
        fscanf(arq, "%d", &maxcor);
        imagem = nova_imagem(largura, altura, maxcor);
        for (y = 0; y < altura; y++) {
            for (x = 0; x < largura; x++) {
                PIXEL *p = pixel_da_imagem(imagem, x, y);
                fscanf(arq, "%d", &(p->r));
                fscanf(arq, "%d", &(p->g));
                fscanf(arq, "%d", &(p->b));
            }
        }
    }
    fclose(arq);
    return imagem;
}

void salvar_arquivo_ppm_p3(const char *nome_arquivo, IMAGEM *imagem) {
    FILE *arq = fopen(nome_arquivo, "w");
    int x, y;
    fprintf(arq, "P3\n%d %d\n%d", imagem->largura, imagem->altura, imagem->maxcor);
    for (y = 0; y < imagem->altura; y++) {
        for (x = 0; x < imagem->largura; x++) {
            PIXEL *p = pixel_da_imagem(imagem, x, y);
            fprintf(arq, "\n%d %d %d", p->r, p->g, p->b);
        }
    }
    fclose(arq);
}

IMAGEM *rotacionar_90_graus_direita(IMAGEM *original) {
    int x, y;
    int h = original->altura, w = original->largura;
    IMAGEM *rotacionada = nova_imagem(h, w, original->maxcor);
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            PIXEL *p1 = pixel_da_imagem(original, x, y);
            PIXEL *p2 = pixel_da_imagem(rotacionada, h - y - 1, x);
            p2->r = p1->r;
            p2->g = p1->g;
            p2->b = p1->b;
        }
    }
    return rotacionada;
}

IMAGEM *reflexao_diagonal_principal(IMAGEM *original) {
    int x, y;
    int h = original->altura, w = original->largura;
    IMAGEM *rotacionada1 = nova_imagem(h, w, original->maxcor);
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            PIXEL *p1 = pixel_da_imagem(original, x, y);
            PIXEL *p2 = pixel_da_imagem(rotacionada1,y, x);
            p2->r = p1->r;
            p2->g = p1->g;
            p2->b = p1->b;
        }
    }
    return rotacionada1;
}

IMAGEM *reflexao_vertical(IMAGEM *original) {
    int x, y;
    int h = original->altura, w = original->largura;
    IMAGEM *rotacionada2 = nova_imagem(h, w, original->maxcor);
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            PIXEL *p1 = pixel_da_imagem(original, x, y);
            PIXEL *p2 = pixel_da_imagem(rotacionada2, x, (h - y - 1));
            p2->r = p1->r;
            p2->g = p1->g;
            p2->b = p1->b;
        }
    }
    return rotacionada2;
}


IMAGEM *reflexao_horizontal(IMAGEM *original) {
    int x, y;
    int h = original->altura, w = original->largura;
    IMAGEM *rotacionada3 = nova_imagem(h, w, original->maxcor);
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            PIXEL *p1 = pixel_da_imagem(original, x, y);
            PIXEL *p2 = pixel_da_imagem(rotacionada3, w - x - 1,y);
            p2->r = p1->r;
            p2->g = p1->g;
            p2->b = p1->b;
        }
    }
    return rotacionada3;
}

IMAGEM *reflexao_tons(IMAGEM *original) {
    int x, y;
    int h = original->altura, w = original->largura;
    IMAGEM *rotacionada4 = nova_imagem(h, w, original->maxcor);
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            PIXEL *p1 = pixel_da_imagem(original, x, y);
            PIXEL *p2 = pixel_da_imagem((h+w+x)/3, x,y);
            p2->r = p1->r;
            p2->g = p1->g;
            p2->b = p1->b;
        }
    }
    return rotacionada4;
}







int main() {

    int continuar=1;
    IMAGEM *original = ler_arquivo_ppm_p3("imagem.ppm");
    if (original == NULL) {
        printf("Arquivo nao eh PPM P3 ou nao existe");
        return 1;
    }
    do{
        printf("\n bem vindo ao programa \n");
        printf("\n programa master manipulation images \n");
        printf("\n opcao 1 rotacionar 90 \n");
        printf("\n opcao 2 reflexao diagonal principal \n");
        printf("\n opcao 3 reflexao vertical \n");
        printf("\n opcao 4 reflexao horizontal \n");
        printf("\n opcao 5 tons de cinza \n");
        scanf("%d", &continuar);
        system("cls || clear");
        switch(continuar){

            case 1:
    printf("aplicando rotacao 90");
    IMAGEM *rotacionada = rotacionar_90_graus_direita(original);
    salvar_arquivo_ppm_p3("imagemsaida.ppm", rotacionada);
    destruir_imagem(original);
    destruir_imagem(rotacionada);
    break;


            case 2:
                printf("aplicando reflexao diagonal principal");
    IMAGEM *rotacionada1 = reflexao_diagonal_principal(original);
    salvar_arquivo_ppm_p3("imagemsaida.ppm", rotacionada1);
    destruir_imagem(original);
    destruir_imagem(rotacionada1);
                break;

            case 3:
                printf("aplicando reflexao vertical");
    IMAGEM *rotacionada2 = reflexao_vertical(original);
    salvar_arquivo_ppm_p3("imagemsaida.ppm", rotacionada2);
    destruir_imagem(original);
    destruir_imagem(rotacionada2);
    break;



            case 4:
                printf("aplicando reflexao horizontal");
    IMAGEM *rotacionada3 = reflexao_horizontal(original);
    salvar_arquivo_ppm_p3("imagemsaida.ppm", rotacionada3);
    destruir_imagem(original);
    destruir_imagem(rotacionada3);
    break;


            case 5:
                printf("aplicando tons de cinza");
                IMAGEM *rotacionada4 = reflexao_horizontal(original);
    salvar_arquivo_ppm_p3("imagemsaida.ppm", rotacionada4);
    destruir_imagem(original);
    destruir_imagem(rotacionada4);
    break;

            default:
                printf("digite opcao valida");
        }


    } while(continuar);
    return 0;
}
