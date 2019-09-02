// Saida solicitada na questao limita o calculo da porcentagem em ate 100 mouses

#include <stdio.h>
#include <stdlib.h>

int main() {
  int len = 0;

  int code;
  int defect;

  int codeV[400];
  int defectV[4] = {0, 0, 0, 0};

  do {
    printf("\nCodigo de identificacao: ");
    scanf("%d", &code);

    if (code > 0) {
      printf("\t1 - Necessita de esfera\n");
      printf("\t2 - Necessita de limpeza\n");
      printf("\t3 - Necessita troca do cabo ou conector\n");
      printf("\t4 - Quebrado ou inutilizado\n> ");
      scanf("%d", &defect);

      if (defect > 4) {
        printf("Valor invalido!\nMouse nao sera registrado!\n");
        continue;
      }
      codeV[len] = code;
      defectV[defect-1] += 1;

      len++;
    }

  } while(code);

  printf("\n\n\tQuantidade de mouses: %d\n\n", len);

  printf("\tSituacao                              Quantidade    Percentual\n");
  printf("\t1 - Necessita de esfera                   %d            %d%\n",
    defectV[0], defectV[0]*(100/len)
  );
  printf("\t2 - Necessita de limpeza                  %d            %d%\n",
    defectV[1], defectV[1]*(100/len)
  );
  printf("\t3 - Necessita troca do cabo ou conector   %d            %d%\n",
    defectV[2], defectV[2]*(100/len)
  );
  printf("\t4 - Quebrado ou inutilizado               %d            %d%\n",
    defectV[3], defectV[3]*(100/len)
  );

  // system("pause");

  return 0;
}
