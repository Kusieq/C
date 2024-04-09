#include <stdio.h>
#include <inttypes.h>

__int128_t silnia(int x) {
  __int128_t wartosc = 1;
  if (x == 1 || x == 0) {
    return 1;
  }
  for (int i = 1; i <= x; i++) {
    wartosc *= i;
  }
  return wartosc;
}

int Wartosc(int n, int k) {
  __int128_t p = n - k;
  return silnia(n) / (silnia(k) * silnia(p));
}

int main() {
  int n = 0;
  printf("Podaj wysokosc trojkata: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("\nZly wymiar %d", n);
    return 0;
  }

  if (n > 63) {
    printf("\nRozmiar trojkata jest zbyt duzy!");
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int wartosc = Wartosc(i, j);
      printf("%d ", wartosc);
    }
    printf("\n");
  }

  return 0;
}
