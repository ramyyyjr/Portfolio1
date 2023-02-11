#include<stdio.h>
#include<string.h>

typedef struct{
    char pays[20];
    char theme[50];
    int date,nmr,nbr;
    float valeur;
    }Timber_Poste;

typedef struct{
    float prix_pc,prix_mc;
    int datep,datem;
}Reponse;

float MontantTotalCollection(Timber_Poste T[100],int n,char pays[20],char theme){
    float somme=0;
    for (int i=0;i<n;i++){
        if(strcmp(T[i].pays,pays)==0&&strcmp(T[i].theme,theme)==0){
        somme=somme+T[i].valeur;}
    }
    return somme;
    }
Reponse PrixExtrememsTimbres(Timber_Poste T[100],int n,char pays[20]){
    Reponse details;
    int datem,datep;
    float prix_pc=T[0].valeur,prix_mc=T[0].valeur;
    for(int i=1;i<n;i++){
        if(strcmp(T[i].pays,pays)==0){
            if(prix_pc<T[i].valeur)  // hadi llprix plus chère
                prix_pc=T[i].valeur;
                datep=T[i].date;
            if(prix_mc>T[i].valeur)  // hadi llprix moins chère
                prix_mc=T[i].valeur;
                datem=T[i].date;
        }
    }
    return details;
}