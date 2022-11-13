/************************************************************************/
/* Auteur : S. Gueye							*/
/* TP : Transformation d'un arbre binaire quelconque en arbre binaire	*/
/* de recherche								*/
/* Date dernière maj : 20/12/2019					*/
/************************************************************************/

#include <iostream>
#include "AB.h"
#include <string>
using namespace std;

/****************************************/
/* Objectif : Constructeur d'un noeud dont les fils sont NULL
/* Entrées : entier x
/* Complexité : 0(1)
/****************************************/
noeud::noeud(int x)
{
	cle = x;

	fg = fd = pere = NULL;
}

/****************************************/
/* Objectif : Constructeur d'un noeud de fils donnés
/* Entrées : entier x, fg, fd
/* Complexité : 0(1)
/****************************************/
noeud::noeud(int x, noeud *fg, noeud *fd)
{
	cle = x;
	this->fg = fg;
	this->fd = fd;
}

/****************************************/
/* Objectif : Destructeur d'un noeud
/****************************************/
noeud::~noeud()
{
	if (fg)
		delete (fg);
	if (fd)
		delete (fd);
}

/****************************************/
/* Objectif : Constructeur d'un AB
/****************************************/
AB::AB(noeud *x)
{
	r = x;
}

/****************************************/
/* Objectif : Destructeur d'un AB
/****************************************/
AB::~AB()
{
	if (r)
		delete (r);
}

/****************************************/
/* Objectif : Accesseur à la racine r
/****************************************/
noeud *AB::root()
{
	return (r);
}

/****************************************/
/* Objectif : Parcours infixe
/****************************************/
void AB::AfficheT()
{
	n = N(r);
	cout << "T = ";

	for (int i = 0; i < n; i++)
		cout << T[i] << " ";

	cout << endl;
}

/****************************************/
/* Objectif : Parcours prefixe
/****************************************/
void AB::Prefixe(noeud *x)
{
	if (x)
	{
		cout << " " << x->cle;
		Prefixe(x->fg);
		Prefixe(x->fd);
	}
}

/****************************************/
/* Objectif : Parcours postfixe
/****************************************/
void AB::Postfixe(noeud *x)
{
	if (x)
	{
		Postfixe(x->fg);
		Postfixe(x->fd);
		cout << " " << x->cle;
	}
}

/****************************************/
/* Objectif : Parcours infixe
/****************************************/
void AB::Infixe(noeud *x)
{
	if (x)
	{
		Infixe(x->fg);
		cout << " " << x->cle;
		Infixe(x->fd);
	}
}

/****************************************/
/* Objectif : Compteur de noeud sur un arbre
/****************************************/
int AB::Compter_recursive(noeud *x)
{
	if (x == NULL)
		return 0;
	else
		return 1 + Compter_recursive(x->fg) + Compter_recursive(x->fd);
}

/****************************************/
/* Objectif : Nombre d'éléments de l'arbre
/****************************************/
int AB::N(noeud *x)
{
	return (Compter_recursive(x));
}

/****************************************/
/* Objectif : Hauteur de l'arbre de racine x
/****************************************/
int AB::Hauteur(noeud *x)
{
	int res, resfg, resfd;

	res = resfg = resfd = -1;

	if (x)
	{
		resfg = Hauteur(x->fg);
		resfd = Hauteur(x->fd);

		if (resfg > resfd)
			res = resfg + 1;
		else
			res = resfd + 1;
	}

	return (res);
}

/****************************************/
/* Objectif : Parcours infixe et insertion des Noeud->clés dans un Tableau[indice]->entier
/****************************************/
void AB::InfixeCleTableau(noeud *x, int &compteur)
{
	if (x && compteur < 50)
	{
		InfixeCleTableau(x->fg, compteur);
		T[compteur] = x->cle;
		compteur++;
		InfixeCleTableau(x->fd, compteur);
	}
}
/****************************************/
/* Objectif : Parcours infixe et insertion du Tableau[indice]->entier au Noeud->clés
/****************************************/
void AB::InfixeTableauCle(noeud *x, int &compteur2)
{

	if (x)
	{
		InfixeTableauCle(x->fg, compteur2);
		x->cle = T[compteur2];
		++compteur2;
		InfixeTableauCle(x->fd, compteur2);
	}
}
/****************************************/
/* Objectif : Stocker dans T les valeurs
/* de l'arbre triées en ordre croissant
/****************************************/
void AB::Tri()
{

	int tempValeur;
	int compteur(0);
	int v1 = 0;
	// Insertion des clés dans le tableau
	AB::InfixeCleTableau(root(), compteur);

	// Tri par comparaison (=> swap les valeurs si v0>v1)

	for (int v0 = 0; v0 < N(r); v0++)
	{

		for (int v1 = v0 + 1; v1 < N(r); v1++)
		{
			if (T[v0] > T[v1])
			{
				tempValeur = T[v1];
				T[v1] = T[v0];
				T[v0] = tempValeur;
			}
		}
	}
}

/****************************************/
/* Objectif : Transformation d'un arbre binaire de racine x
/* en un arbre binaire de recherche contenant les mêmes
/* valeurs et ayant la même structure
/****************************************/
void AB::ABtoABR(noeud *x)
{
	int compteur(0);
	if (x != NULL)
	{
		AB::InfixeTableauCle(root(), compteur);
	}
}