#include <stdio.h>
#include <string.h>

//ABERTURA
int abertura(FILE * arquivo) {
    int retorno = fprintf(arquivo, "<svg version=\"1.1\" ");

    if (retorno < 0) {
      return 0;
    }

    retorno = fprintf(arquivo, "width=\"1000\" height=\"20000\" ");

    if (retorno < 0) {
      return 0;
    }

    retorno = fprintf(arquivo, "xmlns=\"http://www.w3.org/2000/svg\">");

    if (retorno < 0) {
      return 0;
    }

    return 1;
}


//RETANGULO
int retangulo(FILE * arquivo) {

    int x,y,w,h;

    printf("Digite a posição do objeto no eixo x: ");
    scanf(" %d", &x);
    
    printf("Digite a posição do objeto no eixo y : ");
    scanf(" %d", &y);
    
    printf("Digite o valor da largura do quadrado: ");
    scanf(" %d", &w);

    printf("Digite o valor da altura quadrado: ");
    scanf(" %d", &h);

    char string[] = "\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />";

    int retorno = fprintf(arquivo, string , x, y, w, h);

    if(retorno < 0) {
      return 0;
    }
    return 1;
}


//FUNCAO CIRCULO!!!
int circulo(FILE * arquivo) {

    int x,y,r;

    printf("Digite a posição do objeto no eixo x: ");
    scanf(" %d", &x);
    
    printf("Digite a posição do objeto no eixo y : ");
    scanf(" %d", &y);
    
    printf("Digite o valor do raio: ");
    scanf(" %d", &r);

    char string[] = "\n<circle cx=\"%d\" cy=\"%d\" r=\"%d\"/>";

    int retorno = fprintf(arquivo, string , x, y, r);

    if(retorno < 0) {
      return 0;
    }
    return 1;
}


//FUNCAO LINHA!!!
int line(FILE * arquivo) {

    int x1,y1,x2,y2;

    printf("Digite a posição horizontal do primeiro ponto: ");
    scanf(" %d", &x1);
    
    printf("Digite a posição vertical do primeiro ponto : ");
    scanf(" %d", &y1);
    
    printf("Digite a posição horizontal do último ponto: ");
    scanf(" %d", &x2);

    printf("Digite a posição vertical do último ponto: ");
    scanf(" %d", &y2);

    char string[] = "\n<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" />";

    int retorno = fprintf(arquivo, string , x1, y1, x2, y2);

    if(retorno < 0) {
      return 0;
    }
    return 1;
}


//FUNCAO TEXTO!!!
int texto(FILE * arquivo) {
    
    char string[100];
    int x, y = 0;

    printf("Digite a posição horizontal do texto: ");
    scanf(" %d", &x);

    printf("Digite a posição vertical do texto: ");
    scanf(" %d", &y);

    printf("Digite um texto de até 99 letras: ");
    
    getchar();
    fgets(string, 100, stdin);
     
    printf("Digitou: %s\n", string);


    int retorno = fprintf(arquivo, "\n<text x=\"%d\" y=\"%d\" class=\"small\">%35s</text>", x, y, string);

    if(retorno < 0) {
       return 0;
    }

    return 1;
}


//FECHAMENTO
int fechamento(FILE * arquivo) {
    int retorno = fprintf(arquivo, "\n</svg>");

    if(retorno < 0) {
      return 0;
    }

    return 1;
}


//FUNÇÃO MAINNNNNNN!!!
//MAIN
int main(void) {

    char forma[20];
    int controle = 1;
    int comparador = 0;

    FILE * pArquivo = NULL;
    
    pArquivo = fopen("desenho.svg", "w");
    int resultado = abertura(pArquivo);
    
    //Loop
    while(controle) {

        if (pArquivo == NULL) {
            printf("O arquivo não foi aberto!");
        } 
        else {
            if (resultado) {
                
                printf("\nDigite a forma a ser usada - r, c, l, t -- f pra finalizar: ");
                scanf(" %c", forma);

                if( !strcmp(forma, "r") ) {
                    resultado = retangulo(pArquivo);
                }
                else if( !strcmp(forma, "c") ) {
                    resultado = circulo(pArquivo);
                }
                else if( !strcmp(forma, "l") ) {
                    resultado = line(pArquivo);
                }
                else if( !strcmp(forma, "t") ) {
                    resultado = texto(pArquivo);
                }
                else if ( strcmp(forma, "f") ) {
                    printf("\nOpção Inexistente!");
                }
                if( !strcmp(forma, "f") ) {
                    comparador = 1;
                    controle = 0;
                }
                else {
                    printf("\nDigite novamente!");
                }
            } 
            else {
                printf("Erro ao gravar no arquivo.");
            }
        }
    }
    fechamento(pArquivo);

    fclose(pArquivo);
    
    return 0;
}