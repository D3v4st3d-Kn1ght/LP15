#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *pArquivo = NULL;

  pArquivo = fopen("quadrado.svg", "w");

  if( pArquivo == NULL ) {
     printf("O arquivo não foi aberto!");
  } 
  else { 
    int x,y,w,h;

    printf("Digite a posição do objeto no eixo x: ");
    scanf("%d", &x);
    
    printf("Digite a posição do objeto no eixo y : ");
    scanf("%d", &y);
    
    printf("Digite o valor da largura do quadrado: ");
    scanf("%d", &w);

    printf("Digite o valor da altura quadrado: ");
    scanf("%d", &h);

    char string[] = "<svg version=\"1.1\" width=\"300\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\"> <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" /> </svg>";
    fprintf(pArquivo,string, x, y, w, h);
    fclose(pArquivo);
  }
  return 0;
}