#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personne {

        char nom[30] ; 
        int age ; 
        struct Adresse{
            char ville[30] ;
            char rue[30] ; 
            char codepostale[30];
        }adresse[3];

}per;

struct personne lespersonnes[];
int nombresPersonnes = 0;
void createPer(){

    struct personne *per = &lespersonnes[nombresPersonnes];

    
   

    printf("entrez le nom : ");
    scanf("%s",per->nom);
    printf("entrez l'age' : ");
    scanf("%d",&per->age);
    printf("entrez la ville: ");
    scanf("%s",per->adresse->ville);
    printf("entrez la rue : ");
    scanf("%s",per->adresse->rue);
    printf("entrez le codepostale : ");
    scanf("%s",per->adresse->codepostale);

   lespersonnes[nombresPersonnes] = *per;
   nombresPersonnes++;


}

void afficherPer(){
    for (int i = 0; i < nombresPersonnes; i++){
        struct personne per = lespersonnes[i];
        printf("la persone  : %d \n",i = 1 );
        printf("C'est  : %s \n",per.nom );
        printf("Qui a : %d \n" ,per.age);
        printf("qui habite a : %s \n ",per.adresse->ville);
        printf("exactement  a : %s \n ",per.adresse->rue);
        printf("code postal est  : %s \n ",per.adresse->codepostale);
    }

}

void modifier(struct personne *per,int monchoix ,char new[]){
  switch (monchoix)
  {
  case 1:
   strcpy(per->nom,new);
    break;
  case 2:
  per->age=atoi(new);
  break;
  case 3:
  strcpy(per->adresse->ville,new);
  break;
  case 4:
  strcpy(per->adresse->rue,new);
  break;
  case 5:
  strcpy(per->adresse->codepostale,new);
  break;
  
  default:
  printf("Invalid field");
    break;
  }
    
}

int main(){
    int choix ; 
    
    

    

    do {

         printf("cliquez 1 pour la creation : \n   ou 2 pour l 'affichage :  \n ou 3 pour modification");
         scanf("%d",&choix);
       
        switch(choix){
            case 1:
                createPer(&per );
                break;
            
            case 2 : 
                afficherPer();
                break;
              case 3:
                    {
                    int monchoix;
                    char new[100];
                    printf("poure mise a jour le : 1 nom , 2 age , 3 ville , 4 rue , 5 code postal :");
                    scanf("%d",&monchoix);

                    printf("Entrer la nouvelle valeur : ");
                    scanf("%s",new);
                    modifier(&per,monchoix,new);

                    printf("pour creer entrer 1 pour afficher entrer 2 pour mise_a_jour entrer 3 pour  delete enter 4 pour exist entrer 0: ");
                    scanf("%d", &choix);
                    break;
                    }
                
                

             default:
                printf("Choix invalide.\n"); 
                break;

        }

    }while(choix != 3);
}
