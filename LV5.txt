ZADATAK 1.


#include <math.h>
#include <stdio.h>


typedef struct tocka {
    float x;
    float y;
    float z;
} Tocka;
typedef struct trokut {
    struct tocka *t1;
    struct tocka *t2;
    struct tocka *t3;
} Trokut;

void unesiTocke(Tocka*, int);
void unesiTrokute(Trokut*, Tocka*, int);
float pronadjiNajveciOpseg(Trokut*, int);
float len3d(Tocka* a, Tocka*b);
/* Ukoliko koristite dodatne funkcije mozete ih navesti nakon ovog komentara */

void unesiTocke(Tocka* p, int n){
    for(int i=0; i<n; i++){
        scanf("%f %f %f", &p[i].x, &p[i].y, &p[i].z);
    }
}


void unesiTrokute(Trokut* t, Tocka* p, int m){
    int ind1, ind2, ind3;
    
    for(int i=0; i<m;i++){
        scanf("%d %d %d", &ind1, &ind2, &ind3);
        
        t[i].t1 = &p[ind1];
        t[i].t2 = &p[ind2];
        t[i].t3 = &p[ind3];
    }
}

float len3d(Tocka* a, Tocka* b){
    return sqrt((pow(b->x - a->x, 2) + pow(b->y - a->y, 2) + pow(b->z - a->z,2)));
}

float pronadjiNajveciOpseg(Trokut* t, int m){
    float najOpseg=0, opseg;
    
    for(int i=0; i<m; i++){
        float a = len3d(t[i].t1, t[i].t2);
        printf("%.2f\n",a);
        float b = len3d(t[i].t2, t[i].t3);
         printf("%.2f\n",b);
        float c = len3d(t[i].t3, t[i].t1);
         printf("%.2f\n", c);
        opseg = a+b+c;
        
        if(opseg>najOpseg){
            najOpseg = opseg;
        }
    }
    return najOpseg;
}

int main(void)
{
  int n, m;
  Tocka tocke[100];
  Trokut trokuti[100];
  float opseg=0;

  printf("Upisi broj tocaka koje zelis unijeti: ");
  scanf("%d", &n);

  printf("Upisi broj trokuta koje zelis unijeti: ");
  scanf("%d", &m);

  unesiTocke(tocke, n);
  unesiTrokute(trokuti, tocke, m);

  opseg = pronadjiNajveciOpseg(trokuti, m);

  printf("REZULTATI:\n");
  printf("%.2f", opseg);

	return 0;
}

ZADATAK 2. ( NIJE ZAVRSEN DO KRAJA)

/*
Primjer kako bi izgledalo izvodjenje programa, 
prema ovom redosljedu trebate upisivati podatke u strukture.
Ispis racuna se izvodi sam (ne treba editirati tu funkciju). 

Unesi ime kupca: Petar Kupcevic 
Unesi ime prodavaca: Ivan Prodavacevic
Unesi broj artikala: 4
Unesi ime artikla: Pivo Osjecko 0.5l
Unesi cijenu artikla: 5.99
Unesi kolicinu pojedinog artikla: 120
Unesi ime artikla: Brandy Badel 1l
Unesi cijenu artikla: 69.99
Unesi kolicinu pojedinog artikla: 5
Unesi ime artikla: Vino Crno Ribar 1l
Unesi cijenu artikla: 12.99
Unesi kolicinu pojedinog artikla: 55
Unesi ime artikla: Coca Cola 2l
Unesi cijenu artikla: 12.99
Unesi kolicinu pojedinog artikla: 20

REZULTATI:
Kupac: Petar Kupcevic
Prodavac: Ivan Prodavacevic
-----------------------------
Artikli: 
rb   naziv                    kolicina    cijena    ukupno
1    Pivo Osjecko 0.5l         120        5.99       718.80
2    Brandy Badel 1l           5          69.99      349.95
3    Vino Crno Ribar 1l        55         12.99      714.45
4    Coca Cola 2l              20         12.99      259.80

Ukupan iznos racuna: 2043.00
*/



#include <stdio.h>


typedef struct artikl {
  char naziv[50];
  float cijena;
  int kolicina;
} Artikl;
typedef struct racun {
  char prodavac[50];
  char kupac [50];
  Artikl artikli[10];
  int  broj_artikala;
  float ukupan_iznos;
} Racun;


void ispisRacuna(Racun *r) {
  int i;
  float cijena;
  int kolicina;
  printf("REZULTATI:\n");
  printf("Kupac: %s\n", r->kupac);
  printf("Prodavac: %s\n", r->prodavac);
  printf("-----------------------------\n");
  printf("Artikli: \n");
  printf("rb   naziv                    kolicina    cijena    ukupno\n");
  for (i = 0; i < r->broj_artikala; i++) {
    cijena = r->artikli[i].cijena;
    kolicina = r->artikli[i].kolicina;
    printf("%-4d %-25s %-10d %-10.2f %.2f\n", i+1, r->artikli[i].naziv, kolicina, cijena, kolicina*cijena);
  }
  printf("\nUkupan iznos racuna: %.2f", r->ukupan_iznos);
}

/* ovu funkciju trebate napisati prema uputama iz zadatka*/

void unesiPodatkeRacuna(Racun *r) {
    
    while (getchar() != '\n');
    
    printf("Unesite adresu: \n");
    fgets(clan.adresa, sizeof(clan.adresa), stdin);
    clan.adresa[strcspn(clan.adresa, "\n")] = '\0';
        
   
    scanf("%49[^\n]", r->kupac);
    scanf("%49[^\n]", r->prodavac);
    scanf("%d", &r->broj_artikala);
    
  
    for(int i=0; i < r->broj_artikala; i++){
        scanf("%49[^\n]",r->artikli[i].naziv);
        scanf("%d",r->artikli[i].cijena);
        scanf("%d", r->artikli[i].kolicina);
    }
    
      r ->ukupan_iznos = 0;
      
      for(int i=0; i< r->broj_artikala; i++){
          r->ukupan_iznos += r->artikli[i].cijena * r->artikli[i].kolicina;
      }
}

int main(void)
{
  int n, m;
  Racun racun;
  unesiPodatkeRacuna(&racun);

  ispisRacuna(&racun);

	return 0;
}

