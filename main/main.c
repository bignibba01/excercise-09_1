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

	Libro* book = malloc(sizeof(Libro));
	char* path = "File\\file.bin";
	_Bool endLoop = false;
	int numberElement = 0, error = 0;

	while (true) {
		
		int result;
		
		drawMenu();

		printf("Scegli l'operazione da eseguire -> ");
		scanf(" %d", &result);
		fflush(stdin);

		switch (result) {
			case 1: {
				FILE* file;
				if ((file = fopen(path, "ab")) == NULL) {
					printf("Error -> Impossibile aprire il file.\n");				//lesgo
					system("pause");
					break;
				}

				addBook(book);
				printf("%s\n", book->titolo);
				fwrite(&book, sizeof(Libro), 1, file);
				if (fwrite != 0)
					printf("OK\n");
				else
					printf("GLS\n");
				fclose(file);

				system("pause");
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				FILE* fileRead = NULL;
				Libro* tmp = NULL;
				fileRead = fopen(path, "r+b");
				if (fileRead == NULL) {
					printf("Error -> Impossibile aprire il file.\n");
					system("pause");
					break;
				}

				while (fread(&tmp, sizeof(Libro), 1, fileRead) == 1) {
					printf("titolo -> %s, autore -> %s\n", tmp->titolo, tmp->autore);
				}
				rewind(fileRead);
				fclose(fileRead);
				free(tmp);
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

void addBook(Libro *book) {

	//---Inserimento nella struct Libro i valori inseriti dall'utente---
	printf("Titolo -> ");
	scanf(" %[^\n]s", book->titolo);
	fflush(stdin);

	printf("Autore -> ");
	scanf(" %[^\n]s", book->autore);
	fflush(stdin);

	printf("Anno di pubblicazione -> ");
	scanf(" %d", &book->annoPubblicazione);
	fflush(stdin);

	printf("Casa editrice -> ");
	scanf(" %[^\n]s", book->casaEditrice);
	fflush(stdin);

	printf("Numero di pagine totali -> ");
	scanf(" %d", &book->numPagine);
	fflush(stdin);

	printf("Genere -> ");
	scanf(" %[^\n]s", book->genere);
	fflush(stdin);
	
	printf("Valutazione -> ");
	scanf(" %d", &book->valutazione);
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