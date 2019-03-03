#include <stdio.h>

#define max 10

int a[11] = { 3, 6, 2, 8, 9, 0, 1, 7, 4, 6, 5 };
int b[10];

void merging(int valor_baixo, int valor_medio, int valor_alto) {
   int l1, l2, i;

   for(l1 = valor_baixo, l2 = valor_medio + 1, i = valor_baixo; l1 <= valor_medio && l2 <= valor_alto; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= valor_medio)    
      b[i++] = a[l1++];
   while(l2 <= valor_alto)   
      b[i++] = a[l2++];
   for(i = valor_baixo; i <= valor_alto; i++)
      a[i] = b[i];
}

void sort(int valor_baixo, int valor_alto) {
   int valor_medio;
   
   if(valor_baixo < valor_alto) {
      valor_medio = (valor_baixo + valor_alto) / 2;
      sort(valor_baixo, valor_medio);
      sort(valor_medio + 1, valor_alto);
      merging(valor_baixo, valor_medio, valor_alto);
   } else { 
      return;
   }   
}

int main() { 
   int i;

   printf("Vetor antes da ordenacao:\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   sort(0, max);

   printf("\nVetor depois da ordenacao:\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}