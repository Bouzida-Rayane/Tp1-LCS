#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud
{
int valeur; 
struct Noeud *suiv; 
} Noeud;
// Fonction pour créer un nouveau noeud
Noeud *cree(int _value)
{
Noeud *NV; 
NV = (Noeud *)malloc(sizeof(Noeud)); 
NV->_value = value; 
NV->suiv = NULL; 
return NV; 
}
// Fonction pour afficher les valeurs de la liste
void affiche(Noeud *debut)
{
Noeud *courant; 
courant = debut; 
while (courant != NULL)
{ 
la fin
printf("la valeur est %d\n", courant->valeur); 
courant = courant->suiv; 
}
}
// Fonction pour ajouter un noeud au début de la liste
Noeud *ajouterD(Noeud *debut, int _value)
{
Noeud *NV; 
NV = (Noeud *)malloc(sizeof(Noeud));
NV->valeur = _value; 
NV->suiv = NULL; 
if (debut == NULL)
{ 
debut = NV; 
}
NV->suiv = debut; 
debut = NV; 
return debut; 
}
// Fonction pour ajouter un noeud à la fin de la liste
Noeud *ajouterF(Noeud *debut, int _value)
{
Noeud *NV; 
NV = (Noeud *)malloc(sizeof(Noeud)); 
noeud
NV->valeur = _value; 
NV->suiv = NULL; 

if (debut == NULL)
{ 
debut = NV; 
}
Noeud *courant; 
courant = debut; 
while (courant->suiv != NULL)
{ 
courant = courant->suiv; 
}
courant->suiv = NV; 
return debut; 
}
// Fonction pour rechercher une valeur dans la liste
void rechercher(Noeud *debut, int _value)
{
int trouve; 
Noeud *courant; 
courant = debut; 
while (courant != NULL)
{ 
if (courant->valeur == _value)
{ 
trouve = 1;
break; 
}
else
{
trouve = 0;
}
courant = courant->suiv; 
}
if (trouve == 1) 
printf("la valeur existe\n");
else 
printf("la valeur n'existe pas\n");

int taille(Noeud *debut)
{
int taille = 0;
Noeud *courant; 
courant = debut;
while (courant != NULL)
{ 
taille++; 
courant = courant->suiv; 
}
return taille; 
}
// Fonction pour insérer un noeud à une position donnée
Noeud *insertion(Noeud *debut, int pos, int val)
{
Noeud *NV,
*courant; 

NV = (Noeud *)malloc(sizeof(Noeud)); 
NV->valeur = val; 
NV->suiv = NULL; 
int size = taille(debut); 
if (pos < 1 || pos > size + 1)
{ 
printf("la position est incorrecte\n");
}
else if (pos == 1)
{
NV->suiv = debut; 
debut = NV; 
}
else
{
courant = debut; 
for (int i = 1; i < pos - 1; i++)
{ 
courant = courant->suiv;
}
NV->suiv = courant->suiv; 
courant->suiv = NV; 
}
return debut; 
}
// Fonction pour supprimer le premier noeud de la liste
Noeud *suppressionD(Noeud *debut)
{
Noeud *P; 
P = debut; 
if (debut == NULL)
{
printf("la liste est vide\n");
}
else
{
debut = debut->suiv; 
free(P); 
}
return debut; /
}
// Fonction pour supprimer le dernier noeud de la liste
Noeud *suppressionF(Noeud *debut)
{
if (debut == NULL) 
printf("la liste est vide\n");
Noeud *courant; 
courant = debut; 
if (courant->suiv == NULL)
{ 
free(courant); 
printf("l'element a été bien supprimé\n");
}
while (courant->suiv->suiv != NULL)
{ 
courant = courant->suiv; 
}
free(courant->suiv); 
courant->suiv = NULL; 
return debut; 
}
// Fonction pour supprimer un noeud à une position donnée
Noeud *suppressionP(Noeud *debut, int pos)
{
Noeud *courant,
*tmp; 
courant = debut; 
tmp = debut; 
int i;
if (debut == NULL)
{ 
printf("la liste est vide\n");
return NULL;
}
int size = taille(debut); 
if (pos < 1 || pos > size)
{ 
printf("la position est invalide\n");
return debut;
}
if (pos == 1)
{ 
debut = debut->suiv; 
free(courant);
return debut; 
for (i = 1; i < pos - 1; i++)
{
courant = courant->suiv; 
}
tmp = courant->suiv; 
courant->suiv = tmp->suiv; 
free(tmp); 
return debut; 
}
// Fonction pour modifier la valeur du premier noeud
Noeud *modifierD(Noeud *debut, int _value)
{
if (debut == NULL) 
return NULL;
debut->valeur = _value;
return debut;
}
// Fonction pour modifier la valeur du dernier noeud
Noeud *modifierF(Noeud *debut, int _value)
{
if (debut == NULL)
{ 
printf("la liste est vide\n");
return NULL;
}
Noeud *courant; 
courant = debut; 
while (courant->suiv != NULL)
{ 
courant = courant->suiv; 
}
courant->valeur = _value; 
return debut; 
}
// Fonction pour modifier la valeur d'un noeud à une position donnée
Noeud *modifierP(Noeud *debut, int pos, int _value)
{
int i; 
if (debut == NULL)
{ 
printf("la liste est vide\n");
return NULL;
}
int size = taille(debut); 
if (pos < 1 || pos > size)
{
printf("la position est invalide\n");
return debut;
}
Noeud *courant; 
courant = debut; 
for (i = 1; i < pos; i++)
{ 
courant = courant->suiv; 
}
courant->valeur = _value; 
return debut; 
}

int main()
{
Noeud *debut = NULL; 
Noeud *P = cree(10); 
Noeud *D = cree(20); 
Noeud *T = cree(30); 
printf("adreese du noeud debut : %p\n"
, debut);
printf("adreese du noeud P : %p\n"
, P);
printf("adreese du noeud D : %p\n"
, D);
printf("adreese du noeud T : %p\n"
, T);
debut = P; 
P->suiv = D; 
D->suiv = T; 
T->suiv = NULL; 
printf("----------------------\n");
printf("adreese du noeud %p\n", debut);
printf("adreese du noeud P suivant %p\n", P->suiv);
printf("adreese du noeud D suivant %p\n", D->suiv);
printf("adreese du noeud T suivant %p\n", T->suiv);
printf("---------------Affichage----------------------\n");
affiche(debut); 
printf("---------------Ajout au debut----------------------\n");
debut = ajouterD(debut, 100); 
affiche(debut); 
printf("---------------Affichage ajout à la Fin----------------------\n");
debut = ajouterF(debut, 200);
affiche(debut); 
printf("---------------Recherche----------------------\n");
rechercher(debut, 20);
printf("---------------Taille de la liste----------------------\n");
printf("la taille est %d\n"
, taille(debut)); 
printf("---------------Insertion à une position----------------------\n");
debut = insertion(debut, 3, 555);
affiche(debut); 
printf("---------------Suppression au debut----------------------\n");
debut = suppressionD(debut); 
affiche(debut);
printf("---------------Suppression à la fin----------------------\n");
debut = suppressionF(debut); 
affiche(debut); 
printf("---------------Suppression à une position----------------------\n");
debut = suppressionP(debut, 4); 
affiche(debut); 
printf("--------------Modifier au debut----------------------\n");
debut = modifierD(debut, 2024);
affiche(debut); 
printf("---------------Modifier à la fin----------------------\n");
debut = modifierF(debut, 2025); 
affiche(debut); 
printf("--------------Modifier à une position----------------------\n");
debut = modifierP(debut, 1, 2000);

affiche(debut); 
return 0; 
}