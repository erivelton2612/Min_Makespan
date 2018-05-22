/* 
 * File:   main.c
 * Author: Erivelton
 *
 * Created on 16 de Maio de 2018, 09:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *set;
    double fitness;
} individuo;

void printCromo(int *randon, int NoP){
    
    int i;
    
    for(i=0;i<NoP-1;i++){
        printf("%d - ",randon[i]);
    }
    printf("%d\n", randon[i]);
}

void printPop (int **Pop, int NPop, int NoP){
    
    int i;
    
    for(i=0;i<NPop;i++){
         printCromo(Pop[i], NoP);
    }
    
}

void Fitness(int * cromo, int NoP){
    
}


individuo * RamdonGenerate(){
    
    int  i, temp, count[3] = {};
    individuo *ind = (individuo *) malloc (sizeof(individuo)*9);
        
    for (i=0; i<9 ;i++){
        temp =rand()%3;
        
        if(count[temp]>=3){
            i--;
        }else{
            count[temp]++;
            ind->set[i] = temp+1;
        }
        
    }
    Fitness(ind->set,9);
    
    return ind;
}

int ** InitialPop(int NPop, int NoP){
    
     individuo **vector = (individuo **) malloc(sizeof(individuo *)*NPop);
     clock_t start, end;
     int i;
    start = clock();
     for(i=0 ; i< NPop ; i++){
          vector[i] = RamdonGenerate();
     }
    end = clock();
    return vector;
}
 

void Selection(){
    
}

void CrossOver(){
    //um par de cromossomos são selecionados e um novo cromossomo é criado alterando as informações geneticas dos pais
    
    //Two parent strings are denoted as P1 and P2, and two children strings are denoted as H1 and H2.
}

void Mutation(double mutation){
    //setar uma  probabilidade de mutação selecionado entre 0 e 1
    //se o numero selecionado for acima do parametro entao a mutação é executada, senao o cromossomo permanece igual.
    double prb;
    clock_t start, end;
    start = clock();
    prb = rand() % 101;
    end = clock();
    prb = prb/100;
    
    //comentar
    if (mutation + prb > 1)
        printf("Vamos mutar! Probabilidade %0.2lf \n", prb);
    //
    else 
        printf("Não vamos :( Probabilidade %0.2lf \n", prb);
    
}

void Operators(double mutation){
    Selection();
    CrossOver();
    Mutation(mutation);

}
    
/*
    The chosen chromosomes form half of the previous
population, and they are called parents.
*/


int main(int argc, char** argv) {

    int Nmach,  //numero de maquinas
        NPop=10,//tamanho da população;
        Njobs = 3,//numero de jobs
        Noppj = 3;//numero de operações por job
    int **Population;
    double mutation = 0.1;
    int **tempoOpe = (int **) malloc(sizeof(int*)*Njobs);
   
     tempoOpe[0] = (int*) malloc(sizeof(int)*Noppj);
     tempoOpe[1] = (int*) malloc(sizeof(int)*Noppj);
     tempoOpe[2] = (int*) malloc(sizeof(int)*Noppj);
     
     tempoOpe[0][0] = 4;
     tempoOpe[0][1] = 2;
     tempoOpe[0][2] = 1;
     tempoOpe[1][0] = 5;
     tempoOpe[1][1] = 4;
     tempoOpe[1][2] = 6;
     tempoOpe[2][0] = 1;
     tempoOpe[2][1] = 3;
     tempoOpe[2][2] = 2;
     
    printPop(tempoOpe,Njobs,Noppj);
    srand( (unsigned)time(NULL) );
    
    Population = InitialPop(NPop,Njobs*Noppj);
    
    printPop(Population,NPop, Njobs*Noppj);
    
    Operators(mutation);

/*
    
    randon = RamdonGenerate();
    
    printCromo(randon, NoP);
*/
    
    
    return (EXIT_SUCCESS);
}

