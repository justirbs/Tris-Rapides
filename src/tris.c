/*!
 * \file tris.c
 *
 * \autor Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 17 mars 2020
 *
 * \brief fonctions et procéedures relatives aux tris
 *
 *
 */

//Inclusion des entêtes de librairies
#include "tris.h"

// Code des fonctions et procédures

void  echanger(int* tab, int indice1, int indice2){
  int tmp; //variablepour effectuer un échange
  tmp=tab[indice1];
  tab[indice1]=tab[indice2];
  tab[indice2]=tmp;
}


/*Question 5*/

void triSelection(int* tab, int n){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int min; //indice de la case minimum
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  for(i=0; i<n; i++){
    min=i;
    for(j=i; j<n; j++){
      if(tab2[min]>tab2[j]){
        min=j;
        echanger(tab2, min, i);
      }
    }
  }
  printf("\n\nTri par sélection :\n");
  afficherTab(tab2, n);
}

void triBulle(int* tab, int n){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int estTrie; //variable booléeene qui indique si un tableau est trié ou non
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  estTrie=0;
  while(!estTrie){
    estTrie=1;
    for(i=0; i<n-1; i++){
      if(tab2[i]>tab2[i+1]){
        estTrie=0;
        echanger(tab2, i, i+1);
      }
    }
  }
  printf("\n\nTri à bulle :\n");
  afficherTab(tab2, n);
}

void triInsertion(int* tab, int n){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int tmp; //variable pour effectuer un échange
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  for(i=0; i<n; i++){
    tmp=tab2[i];
    j=i;
    while(j>0 && tab2[j-1]>tmp){
      tab2[j]=tab2[j-1];
      j--;
    }
    tab2[j]=tmp;
  }
  printf("\n\nTri par insertion :\n");
  afficherTab(tab2, n);
}
