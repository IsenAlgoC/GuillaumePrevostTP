#include <stdio.h>   /* pour les entrées-sorties */
#include <string.h>  /* pour les manipulations de chaînes de caractères */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compléter votre nom ici                                                */
/*   Nom : GUILLAUME               Prénom : PREVOST                       */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le répertoire stocké en mémoire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	printf("\najouter_un_contact_dans_rep non testee");
	// compléter code ici pour tableau
	int idx;

	if (rep->nb_elts < MAX_ENREG)
	{
		rep->tab[rep->nb_elts] = enr;
		rep->nb_elts += 1;
		rep->est_trie = false;
		modif = true;
	}
	else {
		return(ERROR);
	}

	
#else
#ifdef IMPL_LIST

	bool inserted = false;
	// SI LE REPERTOIRE EST VIDE
	if (rep->nb_elts == 0) {
		if (inserted = InsertElementAt(rep->liste, 0, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
		}
		return inserted;
	}
	// SI LE REPERTOIRE N'EST PAS VIDE : On ajoute à la bonne place
	else {		
		int i = 0;

		while (i < rep->nb_elts && est_sup(GetElementAt(rep->liste, i)->pers, enr)) {
			i++;
		}
		// On ajoute l'élément à la place i
		if (inserted = InsertElementAt(rep->liste, i, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
		}
		return inserted;
	}

	return(ERROR);

#endif
	
#endif
	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du répertoire l'enregistrement dont l'indice est donné en */
  /*   paramètre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB

void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {

	// compléter code ici pour tableau
	printf("\nsupprimer_un_contact_dans_rep non testee");
	if (rep->nb_elts >= 1)		/* s'il y a au moins un element ds le tableau */
	{						/* et que l'indice pointe a l'interieur */
		if (indice <= rep->nb_elts) {
			for (int i = indice; i < rep->nb_elts - 1; i++) {
				rep->tab[i] = rep->tab[i + 1];
			}
		}
		else if(indice >= rep->nb_elts){
			return;
		}
		rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
		modif = true;
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du répertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif à vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne à l'écran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	printf("%s, \t%s \t\t%s", enr.nom, enr.prenom, enr.tel);


} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	printf("\n| %-30s |%-30s |%-30s ", enr.nom, enr.prenom, enr.tel);
} /* fin affichage_enreg */


  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	// Comparaison des noms
	char a = 0;
	char b = 0;
	int len1 = strlen(enr1.nom) + 1;
	int len2 = strlen(enr2.nom) + 1;
	int min = len1;
	if (len1 > len2) {
		min = len2;
	}
	for (int i = 0; i < min; i++) {
		a = enr1.nom[i];
		b = enr2.nom[i];
		// Mise en majuscules
		if (a >= 97) { a -= 32; }
		if (b >= 97) { b -= 32; }
		
		if (a < b) {
			return(true);
		}
		else if (a>b) {
			return(false);
		}
	}
	
	// Comparaison des prénoms
	len1 = strlen(enr1.prenom) + 1;
	len2 = strlen(enr2.prenom) + 1;
	min = len1;
	if (len1 > len2) {
		min = len2;
	}
	for (int i = 0; i < min; i++) {
		a = enr1.prenom[i];
		b = enr2.prenom[i];
		// Mise en majuscules
		if (a >= 97) { a -= 32; }
		if (b >= 97) { b -= 32; }
		if (a < b) {
			return(true);
		}
		else if (a > b) {
			return false;
		}
	}
	return(false);

}
 
/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep)
{
#ifdef IMPL_TAB
	// Tri à bulles
	Enregistrement tmp;
	for (int i = 0; i < rep->nb_elts - 1; i++) {
		for (int j = 0; j < rep->nb_elts - i - 1; j++) {
			if(est_sup(rep->tab[j+1], rep->tab[j])){
				tmp = rep->tab[j];
				rep->tab[j] = rep->tab[j + 1];
				rep->tab[j + 1] = tmp;
			}
		}
	}
	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien à faire !
	// la liste est toujours triée
#endif
#endif

	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le répertoire d'un enregistrement correspondant au  */
  /*   nom à partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au critère ou*/
  /*   un entier négatif si la recherche est négative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	
	int i = ind;		    /* position (indice) de début de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;		


#ifdef IMPL_TAB
	ind_fin = rep->nb_elts - 1;
	strcpy_s(tmp_nom, _countof(tmp_nom), nom);
	for (int j = 0; j < (int)strlen(tmp_nom); j++) {	// Conversion en majuscules
		if (tmp_nom[j] >= 97) { tmp_nom[j] -= 32; }
	}

	while(i <= ind_fin && trouve == false){
		strcpy_s(tmp_nom2, _countof(tmp_nom2), rep->tab[i].nom);
		for (int j = 0; j < (int)strlen(tmp_nom2); j++) {	// Conversion en majuscules
			if (tmp_nom2[j] >= 97) { tmp_nom2[j] -= 32; }
		}
		
		if (strlen(tmp_nom) == strlen(tmp_nom2)) {
			int j = 0;
			while (tmp_nom[j] == tmp_nom2[j] && j < (int)strlen(tmp_nom)) {
				j++;
			}
			if (j == (int)strlen(tmp_nom)) {
				trouve = true;
			}
		}
		i++;
	}
	i--;

#else
#ifdef IMPL_LIST
	ind_fin = rep->nb_elts - 1;
	strcpy_s(tmp_nom, _countof(tmp_nom), nom);
	for (int j = 0; j < (int)strlen(tmp_nom); j++) {	// Conversion en majuscules
		if (tmp_nom[j] >= 97) { tmp_nom[j] -= 32; }
	}

	while (i <= ind_fin && trouve == false) {
		strcpy_s(tmp_nom2, _countof(tmp_nom2), GetElementAt(rep->liste,i)->pers.nom);
		for (int j = 0; j < (int)strlen(tmp_nom2); j++) {	// Conversion en majuscules
			if (tmp_nom2[j] >= 97) { tmp_nom2[j] -= 32; }
		}

		if (strlen(tmp_nom) == strlen(tmp_nom2)) {
			int j = 0;
			while (tmp_nom[j] == tmp_nom2[j] && j < (int)strlen(tmp_nom)) {
				j++;
			}
			if (j == (int)strlen(tmp_nom)) {
				trouve = true;
			}
			}
		i++;
		}
	i--;
#endif
#endif

	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non numériques de la chaines        */
  /*********************************************************************/
void compact(char *s)
{
	int j = 0;
	for (int i = 0; i <= (int)strlen(s); i++) {
		if((s[i] >= 48 && s[i] <= 57) || s[i] == '\0') {
			s[j] = s[i];
			j++;
		}
	}
	return;
}

/**********************************************************************/
/* sauvegarde le répertoire dans le fichier dont le nom est passé en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionné ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */

#ifdef IMPL_TAB
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w");
	if (err == 0) {
		for (int i = 0; i < rep->nb_elts; i++) {
			fputs("\n", fic_rep);
			fputs(rep->tab[i].nom, fic_rep);
			fputs(";", fic_rep);
			fputs(rep->tab[i].prenom, fic_rep);
			fputs(";", fic_rep);
			fputs(rep->tab[i].tel, fic_rep);
		}
		fclose(fic_rep);
	}
	else {
		return ERROR;
	}
	
#else
#ifdef IMPL_LIST
	errno_t err = fopen_s(&fic_rep, nom_fichier, "w");
	if (err == 0) {
		for (int i = 0; i < rep->nb_elts; i++) {
			fputs(GetElementAt(rep->liste, i)->pers.nom, fic_rep);
			fputs(";", fic_rep);
			fputs(GetElementAt(rep->liste, i)->pers.prenom, fic_rep);
			fputs(";", fic_rep);
			fputs(GetElementAt(rep->liste, i)->pers.tel, fic_rep);
			fputs("\n", fic_rep);
		}
		fclose(fic_rep);
	}
	else {
		return ERROR;
	}
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le répertoire le contenu du fichier dont le nom est  */
  /*   passé en argument                                                */
  /*   retourne OK si le chargement a fonctionné et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;								/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
				Enregistrement nouveau;
				if (lire_champ_suivant(buffer, &idx, nouveau.nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, nouveau.prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, nouveau.tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element à priori correct, on le comptabilise */
					}
				}
				InsertElementAt(rep->liste, num_rec, nouveau);

#endif
#endif




			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */