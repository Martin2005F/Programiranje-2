ZADATAK 1.

#include <stdio.h>

struct cpl {
  float re;
  float im;
};

int main(void)
{
  struct cpl a, b, c, d;
  puts("Upisi realni i imaginarni dio prvog broja");
  scanf("%f", &a.re);
  scanf("%f", &a.im);
  puts("Upisi realni i imaginarni dio drugog broja");
  scanf("%f", &b.re);
  scanf("%f", &b.im);

        c.re = a.re + b.re;
        c.im = a.im + b.im;
        
        d.re = a.re - b.re;
        d.im = a.im - b.im;

  printf("REZULTATI:\n");
  printf("%.3f, %.3f*i\n", c.re, c.im);
  printf("%.3f, %.3f*i\n", d.re, d.im);

  return 0;
}


ZADATAK 2.



/* Obratite pozornost na format ulaznih podataka za pojedinog ucenika. 
 * Ulazni podaci za svakog ucenika su formata:
Pero
Peric
3000103921082
2.12
1.1.1992.
 * gdje su vrijednosti redom: ime, prezime, matbr, prosjek i datum.
 * S obzirom na ulazne podatke formirajte strukturu. Pripazite na veličinu podatka za matbr te format zapisa datuma (točke nakon dana, mjeseca i godine)
 */
#include <stdio.h>

 typedef struct datum{
     int d;
     int m;
     int g;
 }DATUM;
 
typedef struct ucenik{
    char ime[15];
    char prezime[15];
    int matbr[13];
    float prosjek;
    DATUM date;
}UCENIK;


int main(void){
    

UCENIK ucenici[40];
int n;
float max=0; 
int maxi;


 scanf("%d", &n);
 
 for(int i=0;i<n;i++){
     
    printf("upisite ime\n");
    scanf("%s", &ucenici[i].ime);
    //printf("\n");
    
    printf("upisite prezime\n");
    scanf("%s", &ucenici[i].prezime);
    //printf("\n");
    
    printf("upisite MBR\n");
    scanf("%d", &ucenici[i].matbr);
    //printf("\n");
    
    printf("upisite prosjek\n");
    scanf("%f", &ucenici[i].prosjek);
    //printf("\n");
    
    printf("upisite datum\n");
    scanf("%d.%d.%d.", &ucenici[i].date.d, &ucenici[i].date.m, &ucenici[i].date.g);
    //printf("\n");
    
    if(ucenici[i].prosjek > max){
        max = ucenici[i].prosjek;
        maxi=i;
    }
    
 }
 
  printf("REZULTATI:\n");
  printf("%s %s", ucenici[maxi].ime, ucenici[maxi].prezime);
 return 0;

    
}
 
