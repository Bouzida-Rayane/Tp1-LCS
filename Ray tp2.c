#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structure date
typedef struct Date
{
    char jour[3];
    char mois[3];
    char annee [5];
}date;
//structure produit
typedef struct Produit
{
    char *Nom_produit;//allocation darori
    char reference[100];
    float montant;
    date dateAchat;
}produit;
//structure liste
 typedef struct Liste
 {
     produit cellule;
     struct Liste *suiv;
 }liste;
// fonction cree liste produits
liste *cree_liste_produits()
{
    liste *nv=(liste*)malloc(sizeof(liste));
    if(nv==NULL)
    {
        printf("erreur d'allocation.\n");
        return NULL;
    }
    nv->suiv=NULL;
    return nv;
}
// fonction est vide
int est_vide(liste *debut)
{
    if(debut==NULL)
    {
        return 1;//liste vide
    }
    else
    {
        return 0;
    }
}
// fonction creer produit
liste *creer_produit()
{
    liste *nv=cree_liste_produits();

    /*liste *nv=(liste)malloc(sizeof(liste));*/
    if(nv==NULL)
    {
       printf("erreur d'allocation.\n");
       return NULL;
    }

    nv->cellule.Nom_produit=(char*)malloc(50*sizeof(char));//allocation de memoire pour le nom du produit

    if(nv->cellule.Nom_produit==NULL)
    {
       printf("erreur d'allocation.\n");
       return NULL;
    }
    printf("Saisir le nom du produit:\n");
    scanf("%s",nv->cellule.Nom_produit);
    printf("Saisir la reference du produit:\n");
    scanf("%s",nv->cellule.reference);
    printf("Saisir le montant du produit:\n");
    scanf("%f",&nv->cellule.montant);
    printf("Saisir la date d'achat (JJ MM AAAA):\n");
    scanf("%s %s %s",nv->cellule.dateAchat.jour,nv->cellule.dateAchat.mois,nv->cellule.dateAchat.annee);
    nv->suiv=NULL;

    return nv;
}
//fonction afficher produit (un seul produit)
void afficher_produit(liste *produit)
{
    if(produit==NULL)
    {
        printf("produit introuvable");
        return ;
    }
    printf("----------AFFICHAGE DU PRODUIT:----------\n");
    printf("NOM PRODUIT:%s\n",produit->cellule.Nom_produit);
    printf("REFERENCE DU PRODUIT:%s\n",produit->cellule.reference);
    printf("DATE :%s / %s / %s \n",produit->cellule.dateAchat.jour,produit->cellule.dateAchat.mois,produit->cellule.dateAchat.annee);

}
//ajouter au debut
liste *ajouter_debut(liste *debut)
{
    liste *nv=creer_produit();
    if (debut==NULL)
    {
        debut=nv;
    }
    else
    {
    nv->suiv=debut;
    debut=nv;
    }
    return debut;

}
//ajout a la fin
liste *ajouter_fin(liste *debut)
{
    liste *nv=creer_produit();
    if (debut==NULL)
    {
        debut=nv;
    }
    liste *ptr=debut;
    while(ptr->suiv != NULL)
    {
        ptr=ptr->suiv;
    }
    ptr->suiv=nv;
    return nv;
}
//afficher tous les produits
void afficher_produits(liste *debut)
{
   if(debut==NULL)
    {
        printf(" Produit introuvable.\n");
        return NULL;
    }
    liste *ptr=debut;
    while (ptr != NULL)
    {
    printf("----------AFFICHAGE DU PRODUIT:----------\n");
    printf("NOM PRODUIT:%s\n",ptr->cellule.Nom_produit);
    printf("REFERENCE DU PRODUIT:%s\n",ptr->cellule.reference);
    printf("DATE :%s / %s / %s \n",ptr->cellule.dateAchat.jour,ptr->cellule.dateAchat.mois,ptr->cellule.dateAchat.annee);
    ptr=ptr->suiv;
    }
}
//longueur de la liste
int longueur(liste *debut)
{
    int L=0;
    liste *ptr=debut;
    while (ptr != NULL)
    {
        L++;
        ptr=ptr->suiv;
    }
    return L;
}
//supprime debut
liste *supprimer_debut(liste *debut)
{
    liste *ptr=debut;
    if (debut==NULL)
    {
        printf("la liste est vide.\n");
    }
    else
    {
        debut=debut->suiv;
        free(ptr);
    }
    return debut;
}
//supprimer fin
liste *supprimer_fin(liste *debut)
{
    liste *ptr=debut;
    if (debut==NULL)
    {
        printf("la liste est vide.\n");
    }
    if(ptr->suiv == NULL)//liste avec un seul element
    {
        free(ptr);
    }
    while (ptr->suiv->suiv != NULL)
    {
        ptr = ptr->suiv;
    }
    free(ptr->suiv);
    ptr->suiv = NULL;
    return debut;

} Y
//filtrer date apres la date choisie par utilisateur
void filter_date(liste *debut, Date dt)
{
    
}
//rembourser 
liste *rembourser(liste *debut,char *refer)
{
    if(est_vide(debut))
    {
        printf("La liste est vide");
    }
    if(strcmp(debut->cellule.reference,refer)==0)
    {
        supprimer_debut(debut);
    }
    liste *ptr=debut , *prev=NULL;

    while(ptr!=NULL && strcmp(ptr->cellule.reference,refer)!=0)
    {
        prev = ptr;
        ptr = ptr->suiv;
    }

    if(ptr->suiv == NULL)
    {
        supprimer_fin(debut);
    }
    if(ptr==NULL)
    {
       printf("produit non trouve\n");
       return debut ;
    }
    else 
    {
    prev->suiv=ptr->suiv;
    free(ptr);
    }
    
return debut;
}
int main()
{
    liste *debut = NULL;
    int choix;
    do
    {
        printf("---------------MENU---------------\n");
        printf("1. Saisir un produits.\n");
        printf("2. Afficher les produits.\n");
        printf("3. Ajouter un produit au debut.\n");
        printf("4. Ajouter un produit a la fin.\n");
        printf("5. Supprimer un produit au debut.\n");
        printf("6. Supprimer un produit a la fin.\n");
        printf("7. Afficher la longueur de la liste\n");
        printf("8. Quitter\n");
        printf("\n  Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            debut = ajouter_debut(debut);
            //printf("Produit ajoute au debut avec succes.\n");
            break;
        case 2:
            afficher_produits(debut);
            break;
        case 3:
            debut = ajouter_debut(debut);
            break;
        case 4:
            debut = ajouter_fin(debut);
            break;
        case 5:
            debut = supprimer_debut(debut); 
            printf("Produit supprime au debut.\n");
            break;
        case 6:
            debut = supprimer_fin(debut);
            printf("Produit supprime a la fin.\n");
            break;
        case 7:
            printf("La longueur de la liste est: %d\n", longueur(debut));
            break;
        case 8:
            printf("QUIT!\n");
            break;

        default:
            printf("Choix invalide. Veuillez ressayer.\n");
        }
    }
    while (choix != 8);

return 0;
}
