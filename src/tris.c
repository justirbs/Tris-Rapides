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
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  for(i=0; i<n-1; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(tab2[j]<tab2[min]){
        min=j;
      }
    }
    if(min!=j){
      echanger(tab2, min, i);
    }
  }
  t2=clock();
  printf("\n\nTri par sélection :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void triBulle(int* tab, int n){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int estTrie; //variable booléeene qui indique si un tableau est trié ou non
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  estTrie=0;
  t1=clock();
  while(!estTrie){
    estTrie=1;
    for(i=0; i<n-1; i++){
      if(tab2[i]>tab2[i+1]){
        estTrie=0;
        echanger(tab2, i, i+1);
      }
    }
  }
  t2=clock();
  printf("\n\nTri à bulle :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void triInsertion(int* tab, int n){
  int* tab2; //une copie du tableau
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int tmp; //variable pour effectuer un échange
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  for(i=0; i<n; i++){
    tmp=tab2[i];
    j=i;
    while(j>0 && tab2[j-1]>tmp){
      tab2[j]=tab2[j-1];
      j--;
    }
    tab2[j]=tmp;
  }
  t2=clock();
  printf("\n\nTri par insertion :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void triRapide(int* tab, int n){
  int* tab2; //une copie du tableau
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  quickSort(tab2, 0, n-1);
  t2=clock();
  printf("\n\nTri rapide :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void quickSort(int* tab, int debut, int fin){
  int indice_pivot; //indice du pivot
  if(debut<fin){
    indice_pivot=partitionner(tab, debut, fin);
    quickSort(tab, debut, indice_pivot-1);
    quickSort(tab, indice_pivot+1, fin);
  }
}

int partitionner(int* tab, int debut, int fin){
  int pivot; //le pivot autour du quel on déplace les cases du tableau
  int cpt; //compteur pour savoir l'indice du pivot à la fin
  int i; //iterrateur de boucle
  pivot=tab[debut];
  cpt=debut;
  for(i=debut; i<=fin; i++){
    if(tab[i]<pivot){
      cpt++;
      echanger(tab, cpt, i);
    }
  }
  echanger(tab, cpt, debut);
  return(cpt);
}

void triFusion(int* tab, int n){
  int* tab2; //une copie du tableau
  clock_t t1; //temps début d'execution
  clock_t t2; //temps fin d'execution
  tab2=creerTabEntier1D(n);
  CopierTab(tab, tab2, n);
  t1=clock();
  mergeSort(tab, 0, n-1);
  t2=clock();
  printf("\n\nTri fusion :\n");
  afficherTab(tab2, n);
  printf("temps d'execution : %f μs\n", ((float)(t2-t1)/CLOCKS_PER_SEC)*1000000);
  free(tab2);
}

void mergeSort(int* tab, int debut, int fin){
  int m; //le milieu du tableau
  if(debut<fin){
    m=debut+(fin-1)/2;
    printf("\n\n");
    afficherTab(tab, fin-debut);
    mergeSort(tab, debut, m);
    mergeSort(tab, m+1, fin);
    fusionner(tab, debut, fin, m);
  }
}

void fusionner(int* tab, int debut, int fin, int m){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int k; //iterrateur de boucle
  int* tab1; //tableau de gauche
  int* tab2; //tableau de droite
  int n1; //taille du tableau de gauche
  int n2; //taille du tableau de droite
  n1=m-debut+1;
  n2=fin-m;
  tab1=creerTabEntier1D(n1);
  tab2=creerTabEntier1D(n2);
  for(i=0; i<n1; i++){
    tab1[i]=tab[debut+i];
  }
  for(i=0; i<n2; i++){
    tab2[i]=tab[m+1+i];
  }
  i=0;
  j=0;
  k=1;
  while(i<n1 && j<n2){
    if(tab1[i]<=tab2[j]){
      tab[k]=tab1[i];
      i++;
    } else {
      tab[k]=tab2[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    tab[k]=tab1[i];
    i++;
    k++;
  }
  while(j<n2){
    tab[k]=tab2[j];
    j++;
    k++;
  }
}
