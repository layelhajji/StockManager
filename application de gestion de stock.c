#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define C 1000
typedef struct s_produit  {
		int reference ;
		char marque[N];
		float prix;
		int stock;
		} s_produit ;
typedef struct date {
	int annee;
	int jour;
	int mois;
} date;

int search( int ref){

		struct s_produit produit;
        FILE *file;

        file = fopen("produit.txt", "r");

		int test = 0;
  		while (fread(&produit,sizeof(struct s_produit), 1, file) && test == 0){
         	if (produit.reference == ref)
			{
    			test=1;
				}
		}
		fclose(file);
		return test;
}

void Modifier(int ref, s_produit produits[N]){

 		struct s_produit produit;
        struct s_produit nvproduit;
        FILE *file;
        int s;
        float p;

        printf("Stock a ajouter :\n ");
        scanf("%d", &s);
        printf("Nouveau prix:\n ");
        scanf("%f2", &p);



        file = fopen("produit.txt", "r");

        int nbproduits = 0;

        while(fread(&produit, sizeof(struct s_produit), 1, file)) {
        	if (produit.reference == ref){
        		produit.stock +=s;
        		produit.prix +=p;
        		produits[nbproduits] = produit;
            	nbproduits++;
			}
        	else {
        		produits[nbproduits] = produit;
            	nbproduits++;
			}

        }
        fclose(file);
        remove("produit.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        int i=0 ;
        while (  i<nbproduits )
        {
            if (produits[i].reference == nvproduit.reference)
                fwrite(&nvproduit, sizeof(produits[i]), 1, nf);
            else
                fwrite(&produits[i], sizeof(produits[i]), 1, nf);
            i++;
        }
        fclose(nf);
        rename("nv.txt", "produit.txt");
}


s_produit produits[N];
int c=0 ;


void menu()

{
	int x ;
		printf("\n\t\t\t\t      **** GESTION DES STOCKS ********\n\n\n");
		printf("\t1- Ajouter un produit dans le stock\t\t\t2- Modifier un produit dans le stock \n\n ");
        printf("\t3- Supprimer un produit du stock\t\t\t4- Afficher tout les produits dans le stock  \n\n");
        printf("\t5- Rechercher un produit dans le stock\t\t\t6-Ici vous trouvez l_archive des historique \n\n");
        printf("\t7- Quitter\n\n");
        printf("Quel est votre choix ? \n\n\n");
        scanf("%d", &x);
        gerer(x);

}

void gerer (int a) {

    if (a==1)
    {

        int ref,test;
        printf("\nVeuillez donner la reference: \n\n");
        scanf("%d",&ref);
        test = search(ref);
        struct date date;
        FILE *file2;
        if (test == 0){
			struct s_produit produit;
        	FILE *file1;
        	FILE *file2;
			int test;
			produit.reference = ref;
			printf("\n\nVeuillez donner la marque\n\n");
	        scanf("%s",&produit.marque);
	        printf("\nPrix: ");
	        scanf("%f", &produit.prix);
	        printf("\nStock: ");
	        scanf("%d", &produit.stock);
	        printf("\nVeuillez donner la date de la tache\n\n");
	        scanf("%d%d%d",&date.jour,&date.mois,&date.annee);

	        file1 =fopen("produit.txt", "a");
	        file2=fopen("historique.txt","a");
	        fwrite(&produit, sizeof(produit), 1, file1);
	        fprintf(file2,"\n Le produit %d  a ete ajoute le %d/%d/%d  ",produit.reference,date.jour,date.mois,date.annee);

	        if(fwrite != 0)
	            printf("\nLe produit est ajoute avec succes \n\n");
	        else
	            printf("ERREUR!!\n\n");
			fclose(file1);
			fclose(file2);
			char c;
			printf("\nCliquer sur 0 pour retourner au menu principal");
			scanf("%c",&c);
			menu();
		}
		else{
			int n;
			printf("\tCe produit deja existe  , vous pouvez le modifier ?\n\n");
			printf("1:oui \n0:non \n");
			scanf("%d",&n);
			if(n == 1){
					Modifier(ref , produits);
		     printf("\nVeuillez donner la date de la  tache\n\n");
	          scanf("%d%d%d",&date.jour,&date.mois,&date.annee);
	          file2=fopen("historique.txt","a");
	          fprintf(file2,"\n Le produit %d a ete modifie le  %d/%d/%d  ",ref,date.jour,date.mois,date.annee);
	          fclose(file2);

				printf("\nLe produit est modifie avec succes\n\n");
			}
			else{
				menu();
			}
		}
        menu();
}
    else if (a==2)
    {
    	struct date date;
    	FILE *file;
    	int ref;
		printf("\nVeuillez donner la reference \n\n ");
        scanf("%d", &ref);
        Modifier(ref , produits);
        printf("\nVeuillez donner la date de la  tache\n\n");
	    scanf("%d%d%d",&date.jour,&date.mois,&date.annee);
	    printf("\nle produit est modifie avec succes");
          file=fopen("historique.txt","a");
          fprintf(file,"\n Le produit %d a ete modifie le %d/%d/%d  ",ref,date.jour,date.mois,date.annee);
          fclose(file);
        menu();
    }
    else if (a==3)
    {
        struct s_produit produit;
        struct date date;
        int ref;
        FILE *file1;
        FILE *file2;

        printf("\nVeuillez modifier la reference du produit que vous voulez supprimer \n\n ");
        scanf("%d", &ref);
        printf("\nVeuillez donner la date de la  tache\n\n");
        scanf ("%d%d%d ",&date.jour,&date.mois,&date.annee);

        file1 = fopen("produit.txt", "r");
        file2= fopen("historique.txt","a");

        int nbproduits = 0;

        while(fread(&produit, sizeof(struct s_produit), 1, file1)) {
            produits[nbproduits] = produit;
            nbproduits++;
        }
        fprintf(file2,"\n Le produit %d a ete supprime a la date %d/%d/%d \n\n",produit.reference,date.jour,date.mois,date.annee);
        fclose(file1);
        fclose(file2);
        remove("produit.txt");

        FILE *nf;
        nf = fopen("nv.txt", "a");
        int i=0 ;
        while (  i<nbproduits )
        {
            if (produits[i].reference != ref)
                fwrite(&produits[i], sizeof(produits[i]), 1, nf);
            i++;
        }
        fclose(nf);
        rename("nv.txt", "produit.txt");
         menu();
    }
    else if (a==4)
    {
        FILE *file1;
        struct s_produit produit ;
        struct date date;
        file1 = fopen("produit.txt", "r");
        int nbproduits = 0;
        while(fread(&produit, sizeof(struct s_produit), 1, file1)) {
            produits[nbproduits] = produit;
            nbproduits++;
        }
        fclose(file1);


        int c=0;

        while (c<nbproduits)
        {


            printf("\nMarque du produit: %s\n\n", produits[c].marque);
            printf("\nReference du produit: %d\n\n", produits[c].reference);
            printf("\nStock du produit : %d\n\n", produits[c].stock);
            printf("\nPrix du produit : %f\n\n", produits[c].prix);
            printf("\n");
            c++;
        }
menu();
    }


    else if (a==5)
    {	struct s_produit produit ;
    	int ref ;
    	FILE *file1;


    	printf("\nVeuillez donner la reference:");
    	scanf("%d",&ref);

    	file1 = fopen("produit.txt", "r");
		    	int test = 0 ;
    	while (fread(&produit,sizeof(struct s_produit), 1, file1) && test == 0){
         	if (produit.reference == ref)
			{
            	printf("\nReference: %d\n\n",produit.reference);
				printf("\nMarque: %s\n\n",produit.marque);
				printf("\nPrix: %f\n\n",produit.prix);
				printf("\nStock: %d\n\n",produit.stock);
				test = 1;
			}
		}

		if(test == 0)
			printf("\nCe produit n_existe pas dans le stock \n\n");
		fclose(file1);
		        menu();
	} else if (a==6) {
		FILE *file;
	file=fopen("historique.txt","r");
    char ligne[C];
            while (fgets(ligne, sizeof(ligne), file)) {
                    printf("%s \n",ligne);
             }
             fclose(file);
            menu(); }
	else if (a==7) {
		printf("*****AU REVOIR*****");
	}

	}

int main()
 { menu ();
 return 0 ; }
