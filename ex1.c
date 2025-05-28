#include <stdio.h>
#include <string.h>

int main(void) {
  FILE *pArquivo = NULL;

  pArquivo = fopen("quadrado.svg", "w");

  if( pArquivo == NULL ) {
     printf("O arquivo não foi aberto!");
  } 
  else { 
    char nome[1000] = "<svg version=\"1.1\" width=\"300\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\"> <rect x=\"20\" y=\"30\" width=\"100\" height=\"100\" fill=\"red\" /> </svg>";
    
     for(int i = 0; i < strlen(nome); i++) {
         if( nome[i] == '\0') {
	          break;
         }
         fputc(nome[i], pArquivo);
     }
  }
  fclose(pArquivo);
  return 0;
}