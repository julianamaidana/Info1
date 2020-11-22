#include <stdio.h>

int cont (void) {
 static int a = 1;
  return a++;
}  

int main (void) {
 
 for (int i = 0; i<10; i++) {
  printf ("%d\n", cont() );
  }
  
return 0;
}
