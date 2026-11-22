#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

    int choix;
	char tel[20];
	char adresse[100];
	bool good=false;
	int numero;
	char sorte;
	int nombre;
	float prixtotal=0.0f;
	float soustotal=0.0f;
	char ajouter;
	char repas[500];
	char temp[10];
	char mode;
	float tps=0.0f;
	float tvq=0.0f;
	float montant_total_facture=0.0f;
	int numerofacture=1;
	int totalvendu=0;
	float montant_total=0.0f;
	bool quitter;
	
	
int main(int argc, char *argv[]) {
	
	
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("Bienvenue chez Pizza Pour Tous(PPT)!!\n"
	 "Ce programme permet de calculer la facture des commandes de repas de PPT.\n"); //welcome message
	printf("---------------------------------------------------------------------------------------------------------\n\n");
	
	char *menu=
	 "Menu:\n"
	 "1.Facturer une commande\n" 
	 "2.Afficher le nombre total de repas vendus et le montant des ventes\n"
	 "3.Quitter le programme\n\n";
	 
	do {
		printf("%s",menu); //displays the menu
	
	printf("Entrez votre choix: ");
	scanf("%d", &choix);
	switch (choix) 
	{
		case 1: //option 1 orders a bill
			printf("Entrez votre numero de telephone: ");
			scanf("%s", &tel); //enters the customers phone number
			
			printf("Entrez votre adresse: ");
			scanf("%s", &adresse); //enters the customers addresss
			
		do{

			do{
				printf("Entrez le numero du repas(3, 4, 8, 9, 13, 14): ");
				scanf("%d", &numero); //enters the meal number
				good = numero==3 || numero==4 || numero==8 || numero==9 || numero==13 || numero==14;
				if(!good){
					printf("Entrez le numero qui correspond au menu, \n"); 
				}
			}while (!good);
			
			do{
				printf("Entrez la sorte de pizza (v ou V, f ou F, t ou T, e ou E, m ou M): ");
				scanf("%s", &sorte); //enters the type of pizza
				good = sorte=='v' || sorte=='V' || sorte=='f' || sorte=='F' ||sorte=='t' || sorte=='T' || sorte=='e' || sorte=='E' || sorte=='m' || sorte=='M';
				if(!good){
					printf("Entrez la sorte qui correspond au menu,");
				}
			}while(!good);
			
			do{
				printf("Veuillez entrer le nombre de repas: ");
				scanf("%d", &nombre); //enters the number of meals
				good = nombre > 0;
				if(!good){
					printf("Entrez un mombre superieur a 0, \n");
				}
			}while(!good);
			
				switch (numero) //calculates the price per meal ordered 
                    {
                        case 3:
                            prixtotal = nombre * 20.49;
                            strcat(repas, "1 Moyenne Pizza 12\" + 1 Petite Poutine + 1 Pepsi (355 ml)       ");
                            sprintf(temp, "%d", nombre);
                            strcat(repas, temp);
                            strcat(repas, "     20.49\n");
                            break;
                        case 4:
                            prixtotal = nombre * 21.99;
                            strcat(repas, "1 Moyenne Pizza 12\" + 10 ailes de poulet + Frites + 1 Pepsi (355 ml)       ");
                            sprintf(temp, "%d", nombre);
                            strcat(repas, temp);
                            strcat(repas, "     21.99\n");
                            break;
                        case 8:
                            prixtotal = nombre * 24.49;
                            strcat(repas, "1 Pizza Large 14\" + 1 Moyenne Poutine + 1 Pepsi (355 ml)       ");
                            sprintf(temp, "%d", nombre);
                            strcat(repas, temp);
                            strcat(repas, "     24.49\n");
                            break;
                        case 9:
                            prixtotal = nombre * 25.99;
                            strcat(repas, "1 Pizza Large 14\" + 12 ailes de poulet + Frites + 1 Pepsi (355 ml)       ");
                            sprintf(temp, "%d", nombre);
                            strcat(repas, temp);
                            strcat(repas, "     25.99\n");
                            break;
                        case 13:
                            prixtotal = nombre * 28.49;
                            strcat(repas, "1 Pizza X-Large 16\" + 1 Grande Poutine + 1 Pepsi (355 ml)       ");
                            sprintf(temp, "%d", nombre);
                            strcat(repas, temp);
                            strcat(repas, "     28.49\n");
                            break;
                        case 14:
                            prixtotal = nombre * 29.99;
                            strcat(repas, "1 Pizza X-Large 16\" + 15 ailes de poulet + 1 Pepsi (355 ml)       ");
                            sprintf(temp, "%d", nombre);
                            strcat(repas, temp);
                            strcat(repas, "     29.99\n");
                            break;
                    }
                    
                    totalvendu += nombre;
                    soustotal+=prixtotal;
                    
			do{ 
               	printf("Voulez vous ajouter un autre repas(o ou O pour oui, n ou N pour non): ");
               	scanf(" %c", &ajouter);
               	good = ajouter=='o' || ajouter=='O' || ajouter=='n' || ajouter=='N';
               	if(!good){
                    	printf("Veuillez entrer une valeur de celles disponible, \n");
						}
				}while(!good);
		}while(ajouter=='o' || ajouter=='O'); //repeats the 1st option when the customer enters yes
			
			do{
				printf("Entrez le mode de paiement(C, D ou R): ");
				scanf(" %c", &mode);
				good = mode=='C' || mode=='D' || mode=='R';
				if(!good){
					printf("Entrez le bon mode de paiement, \n");
				}
			}while(!good);
			
			tps= soustotal * 0.05;
			tvq= soustotal * 0.09975;
			montant_total_facture= soustotal + tps + tvq;
			montant_total_facture+=montant_total_facture;
			
			 montant_total += montant_total_facture;
			
			//generates date and time from the system
			time_t now = time(NULL);
	        char buf[32];
	        strftime(buf, sizeof(buf), "%y-%m-%d %H:%M:%S", localtime(&now));
			
			//prints the invoice
			printf("-------------------------------------------------\n");
			printf("Pizza Pour Tous\n");
			printf("Keyce Titi garage\n");
			printf("+237 620 239 480\n");
			printf("-------------------------------------------------\n\n");
			printf("Facture numero %d\n",numerofacture++);
	        printf("Date et heure de la facturation: %s\n", buf);
			printf("Adresse du client: %s\n", adresse);
			printf("Numero du client: %s\n", tel);
			printf("Repas : \n");
            printf("%s\n", repas);
            switch (mode)
                {
                    case 'C':
                        printf("Mode de paiement Comptant\n\n");
                        break;
                    case 'D':
                        printf("Mode de paiement Debit\n\n");
                        break;
                    case 'R':
                        printf("Mode de paiement Credit\n\n");
                        break;
                }
                printf("Sous-Total : %.2f$.\n",soustotal);
                printf("Montant TPS : %.2f$.\n",tps);
                printf("Montant TVQ : %.2f$.\n",tvq);
                printf("Montant total : %.2f$.\n",montant_total_facture);
                printf("Merci pour votre achat et a la prochaine!! \n");
                break; 
                
        case 2: //option 2:total number of meals sold and sales amount
            printf("-----------------------------------------------------------\n");
			printf("Pizza Pour Tous \t"); 
		    now = time(NULL);
	        strftime(buf, sizeof(buf), "%y-%m-%d %H:%M:%S", localtime(&now));
	        printf("Date et heure: %s\n", buf);
			printf("Keyce Titi garage\n");
			printf("+237 620 239 480\n");
			printf("-----------------------------------------------------------\n");  
			printf("Nombre total de repas vendu: %d\n",totalvendu);
			printf("Montant total des ventes: %.2f\n",montant_total);
			printf("Merci pour votre achat et a la prochaine!! \n\n");
			break;
			
		case 3://terminates the program
		printf("Merci et a la prochaine");
		quitter = true;
		break;
		
		default:
		printf("Entree invalide!!\n\n");	
  	}
	
	}while(!quitter);
	
	return 0;
}
