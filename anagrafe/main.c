#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <string.h>

typedef struct data {
	int giorno;
	int mese;
	int anno;
} DATA;

typedef struct indirizzo {
	char via[30];
	int civico;
	char citta[30];
} INDIRIZZO;

typedef struct persona{
	char nome [30];
	char cognome [30];
	INDIRIZZO indirizzo;
	DATA data;
} PERSONA;


/*FUNZIONE DI INSERIMENTO DATI ANAGRAFICI PERSONA*/
void inserimento (PERSONA*persona) {
	
	printf("inserisci nome e cognome della persona\n");
	
	//inserimento nome
	fgets (persona-> nome, 30, stdin);
	(persona -> nome)[strlen(persona -> nome)-1]= '\0';
	
	
	//inserimento cognome
	fgets (persona-> cognome, 30, stdin);
	(persona -> cognome)[strlen(persona -> cognome)-1]= '\0';

	printf("inserisci la via, il numero civico di residenza\n");
	
	/*inserimento via*/
	fgets (persona->indirizzo.via, 30, stdin);
	(persona->indirizzo. via)[strlen(persona->indirizzo. via)-1]= '\0';
	
	
	//inserimento civico
	scanf("%d*c",&persona->indirizzo.civico);
	
	
	//inserimento citta
	
	printf("Inserisci citta':");
	fgets (persona->indirizzo.citta, 30, stdin);
	(persona->indirizzo.citta)[strlen(persona->indirizzo. citta)-1]= '\0';
	
	printf("inserisci giorno mese e anno di nascita\n");
	
	//inserimento data
	scanf ("%d%d%d",&persona->data.giorno,&persona->data.mese,&persona->data.anno);

}

/* OUTPUT data di nascita */
void stampaData(DATA* data){
    printf("DATA DI NASCITA: %d/%d/%d\n", data->giorno, data->mese, data->anno);
}

/* OUTPUT indirizzo */
void stampaIndirizzo(INDIRIZZO* indirizzo){
    printf("INDIRIZZO: Via %s %d, %s\n", indirizzo->via, indirizzo->civico,indirizzo->citta);
}

/* OUTPUT persona */
void stampaPersona(PERSONA* persona){
    printf("\nNOME: %s\n", persona->nome);
    printf("COGNOME: %s\n", persona->cognome);
    stampaData(&(persona->data));
    stampaIndirizzo(&(persona->indirizzo));
}



/*funzione ricerca persona nell'anagrafe*/

PERSONA *cerca(PERSONA*anagrafe, char nome, char cognome, int dimensione){
	int i;
	PERSONA *persona=NULL;
	while(i<dimensione && persona==NULL){
	if (strcmp(nome,(anagrafe+i)->nome)&& strcmp(cognome,(anagrafe +i)->cognome))
		persona= anagrafe +i;
	else 
		i++;
	}
	return persona;
}


/*inserimento ricerca nome e cognome*/

PERSONA*ricerca (PERSONA*anagrafe, int dimensione){
	
	char nome[30];
	char cognome [30];
	
	printf("inserisci nome e cognome della persona che vuoi ricercare\n");
	fgets( nome,30,stdin);
	fgets(cognome,30,stdin);
	
	(nome)[strlen(nome-1)]='\0';
	(cognome)[strlen(cognome-1)]='\0';
	return cerca(anagrafe, nome, cognome, dimensione);
}

/*visualizza intera anagrafe*/
void visualizza (PERSONA* anagrafe, int dimensione){
	
	printf("\n***********");
	printf("ANAGRAFE\n");
	printf("***********\n");
	
	for(int i=0; i<dimensione; i++)
		stampaPersona(anagrafe+i);
}
 /* funzione principale di interazione con l'utente */
int main() {
	int numero = -1;
	
	/* elenco di persone */
	PERSONA anagrafe[30];

	/* numero di persone */
	int numeroPersone = 0;
	
	/* ciclo di interazione con l'utente */
	while(numero!=0) {
		printf("\nCiao utente! Puoi svolgere le seguenti operazioni:\n");
		printf("Introduci 1 -> Immetti una persona\n");
		printf("Introduci 2 -> Cancella una persona\n");
		printf("Introduci 3 -> Ricerca una persona\n");
		printf("Introduci 4 -> Visualizza l'anagrafe\n");
		printf("Introduci 0 -> Termina il programma\n");
		scanf("%d%*c", &numero);
		
		/* immetti una persona */
		if(numero==1)
			/* ci sono ancora posti nell'anagrafe? */
			if(numeroPersone<30) {
				inserimento (anagrafe+numeroPersone);
				numeroPersone++;
				printf("Inserimento effettuato\n");
			}
			else
				printf("Mi dispiace, abbiamo raggiunto la capienza massima\n");
	
		/* cancella una persona */
		else  if(numero==3) {
			PERSONA* persona ;
			persona= ricerca(anagrafe, numeroPersone);
			if(persona!=NULL) {
				printf("\nEcco la persona cercata");
				stampaPersona(persona);
			}
			else
				printf("Mi dispiace, la persona non %c presente nell'anagrafe\n", 138);
		}

		/* visualizza tutta l'anagrafe */
		else  if(numero==4)
			visualizza(anagrafe, numeroPersone);

		/* numero sbagliato? */
		else  if(numero!=0)
			printf("Questo numero non vuol dire niente. Riproviamo!\n");
	}
}


