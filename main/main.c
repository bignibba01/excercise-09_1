/*
Realizzare un programma che gestisca la lista di tutti i libri letti in un anno. Per ognuno di essi, il programma deve memorizzare una serie di informazioni,
ad esempio il titolo, l’autore, l’anno di pubblicazione, la casa editrice, la lunghezza, il genere, il codice identificativo, la valutazione.
Il programma dovrà permettere di inserire un nuovo libro, cancellarne uno, visualizzarli tutti, visualizzare solo quelli con una certa valutazione.
Il programma deve lavorare leggendo e scrivendo le informazioni da e su file binario. Consegnare un file .zip contente un progetto che comprenda tutti
i file necessari per testare il programma.

VENTRUCCI TOMAS, MARCHETTI DAVIDE, ZOLI FEREDEICO
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "book.h"

void drawMenu();							//disegna il menu principale per scegliere le operazioni
int getLastId(struct Libro);				//prende l'ultimo id inserito nel file di testo
int getNumberElement(FILE*);				//legge il primo intero nel file di testo indicando il numero di libri presenti nel file

int main() {

	FILE* file;
	char* path = "File\\file.dat";
	_Bool endLoop = false;
	int numberElement = 0, error = 0;

	if ((file = fopen(path, "ab")) != NULL) {
		printf("GG\n");				//lesgo
	}

	system("pause");

	while (true) {
		
		int result;
		
		drawMenu();

		printf("Scegli l'operazione da eseguire -> ");
		scanf(" %d", &result);
		fflush(stdin);

		switch (result) {
			case 1: {

				system("pause");
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				system("pause");

				break;
			}
			case 4: {
				break;
			}
			case 5: {
				endLoop = true;
				break;
			}
		}
		if (endLoop)
			break;
		
		system("cls");
	}

	return 0;
}

void addBook(Libro *book, int index) {

	//---Inserimento nella struct Libro i valori inseriti dall'utente---
	printf("Titolo -> ");
	scanf(" %[^\n]s", book[index].titolo);
	fflush(stdin);

	printf("Autore -> ");
	scanf(" %[^\n]s", book[index].autore);
	fflush(stdin);

	printf("Anno di pubblicazione -> ");
	scanf(" %d", &book[index].annoPubblicazione);
	fflush(stdin);

	printf("Casa editrice -> ");
	scanf(" %[^\n]s", book[index].casaEditrice);
	fflush(stdin);

	printf("Numero di pagine totali -> ");
	scanf(" %d", &book[index].numPagine);
	fflush(stdin);

	printf("Genere -> ");
	scanf(" %[^\n]s", book[index].genere);
	fflush(stdin);
	
	printf("Valutazione -> ");
	scanf(" %d", &book[index].valutazione);
	fflush(stdin);
	//---Fine insermimento---

}

void drawMenu() {
	printf("Lista dei libri su un file binario\n\
1)Aggiungi libro\n\
2)Cancella un libro\n\
3)Visualizza un libro\n\
4)Viusalizza per valutazione\n\
5)Esci\n");

}

int getNumberElement(FILE* file) {
	int number = 0;
	rewind(file);
	fscanf(file, "%d", &number);
	return number;
}