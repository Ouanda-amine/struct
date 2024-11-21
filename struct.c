#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

struct Adresse {
    char ville[100];
    char rue[100];
    char codepostale[100];
};
struct Personne {
    int id;
    char nom[100];
    int age ;
    struct Adresse adr[3]; 
};
void CreatePer(struct Personne *per ,int id ){
    
    per->id=id;
   
    printf("__le nom :  ");
    scanf("%s",per->nom);
    printf("__l' age  :  ");
    scanf("%d",&per->age);
    printf("__la ville :  ");
    scanf("%s",per->adr[0].ville);
    printf("__le rue :  ");
    scanf("%s",per->adr[0].rue);
    printf("__le cp :  ");
    scanf("%s",per->adr[0].codepostale);


}

void afficherPer(struct Personne per){
    printf("id __ : %d  . \n",per.id);

    printf("C'est  __ : %s  . \n",per.nom);

    printf("Qui a  __ : %d  . ans \n",per.age);

    printf("habite a  __ : %s  . \n",per.adr[0].ville);

    printf("exactement a  __ : %s  . \n",per.adr[0].rue);

    printf("code postale __ : %s  . \n",per.adr[0].codepostale);

}
void modifierPer(struct Personne *per , int monchoix , char new[]){
    switch(monchoix){
        case 1 : 
        strcpy(per->nom,new);
        break;
        case 2 : 
        per->age=atoi(new);
        break;
        case 3 : 
        strcpy(per->adr->ville,new);
        break;
        case 4 : 
        strcpy(per->adr->rue,new);
        break;
        case 5 : 
        strcpy(per->adr->codepostale,new);
        break;

        default :
        printf("invalide");
        break;
        
    }
}
void SupprimerPer(struct Personne *per){
    per->id=0;
    strcpy(per->nom,"");
    per->age=0;

    for (int i =0;i<3;i++){
        strcpy(per->adr[i].ville,"");
        strcpy(per->adr[i].rue,"");
        strcpy(per->adr->codepostale,"");
    }

    printf("Suppression avec succes \n");
}

int main(){
    struct Personne 
    lespersonnes[MAX]={0};
    int choix ;
    int id=0;

    do{
         printf("Entrez _1_ pour creer  ,  _2_ pour afficher   et _3_ pour modifer    ");
        scanf("%d",&choix);
        switch(choix){
            case 1 : 
            CreatePer(&lespersonnes[id], id + 1);
            id++;
            break;
            case 2 : 
            for (int i = 0 ; i < id ; i++){
                afficherPer(lespersonnes[i]);
            }
            
            break;
            case 3 : 
     
            char nouv[100];
            int chhoisee;
            int iddetected;

            printf("tu veux changer la personne avec l'id :   ");
            scanf("%d",&iddetected);

            printf("entrez 1 pour changer nom  2 pour l'age 3 pour ville 4 pour rue et 5 pour cp :  ");
            scanf("%d",&chhoisee);

            printf("entrez votre modification : ");
            scanf("%s",nouv);

            modifierPer(&lespersonnes[iddetected - 1],chhoisee,nouv);



            break;
            case 4 :

            int idOut ;

            printf("entrez l'id de la personne qui vous voulez sup :");
            scanf("%d",&idOut);

            SupprimerPer(&lespersonnes[idOut - 1]);
            break;
            

            default :
            printf("invalide");
            break;
            
        }

    }while(choix !=0);



}