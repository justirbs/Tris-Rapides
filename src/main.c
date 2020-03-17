/*!
 * \file main.c
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 17 mars 2020
 *
 * \brief fonction principale
 *
 *
 */

 //Inclusion des entêtes de librairies
 #include "tris.h"
 #include "tableau.h"
 #include "saisie.h"
 #include <stdio.h>
 #include <stdlib.h>

/*Question 6*/

int main(void){
  int* tab; //tableau d'entiers
  int n; //la taille des tableaux
  printf("Quelle est la taille du tableau ?\n");
  do {
    n=saisirEntier();
  } while (n<=0);
  tab=creerTabEntier1D(n);
  InitTab(tab, n);
  system("clear");
  printf("Voici votre tableau : \n");
  afficherTab(tab, n);
  triSelection(tab, n);
  triBulle(tab, n);
  triInsertion(tab, n);
  free(tab);
  return(0);
}
