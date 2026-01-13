#include <stdio.h>
#include <stdlib.h>

int m = 7;
int h[100] = {0};

void insert_liniar(int givenKey) {
  for (int i = 0; i < m; i++) {
    int index = (givenKey + i) % m; // ex3 si 4 modificare linia asta
    if (h[index] == 0) {
      h[index] = givenKey;
      return;
    }
  }
}

void afisare_hash_table_linear() {
    for (int i = 0; i < m; i++) {
        if (h[i] != 0)
            printf("Pozitia %d -> %d\n", i, h[i]);
        else
            printf("Pozitia %d -> (gol)\n", i);
    }
}

int main(void) {
  insert_liniar(36);
  insert_liniar(14);
  insert_liniar(26);
  insert_liniar(21);
  insert_liniar(5);
  insert_liniar(19);
  insert_liniar(4);
  afisare_hash_table_linear();
  return 0;
}
