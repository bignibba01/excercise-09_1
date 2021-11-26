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

void addBook(struct Libro*);				//aggiunge un libro al file
void deleteBook();							//elimina un libro
void drawMenu();							//disegna il menu principale per scegliere le operazioni
int getLastId(struct Libro);				//prende l'ultimo id inserito nel file di testo
void initializeBook(struct Libro);			//inizializzo un libro
void showBooks();							//fa vedere tutti i libri
void showSomeBooks(int);					//fa vedere alcuni libri

struct Libro {
	char* titolo;
	char* autore;
	unsigned int annoPubblicazione;
	char* casaEditrice;
	int numPagine;
	char* genere;
	unsigned int id;
	int valutazione;
};

int main() {

	_Bool endLoop = false;

	while (true) {
		
		int result;
		
		drawMenu();

		printf("Scegli l'operazione da eseguire -> ");
		scanf(" %d", &result);
		fflush(stdin);

		switch (result) {
			case 1: {
				struct Libro* book;

				book = (struct Libro*)malloc(sizeof(struct Libro));

				FILE* file;
				char* path = "..\\File\\file.dat";

				if ((file = fopen(path, "wb")) == NULL) {
					printf("Errore -> Impossibile aprire il file\n");
					return 0;
				}

				addBook(book);

				fwrite(book, sizeof(book), )

				fclose(file);
				free(book);

				break;
			}
			case 2: {
				break;
			}
			case 3: {
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
		
		system("cls");
		if (endLoop)
			break;
	}

	return 0;
}


void addBook(struct Libro *book) {

	char buffer[255];
	//---Inserimento nella struct Libro i valori inseriti dall'utente---
	printf("Titolo -> ");
	scanf(" %[^\n]s", &buffer);
	fflush(stdin);

	book->titolo = (char*)malloc((sizeof(char) * strlen(buffer)));
	strcpy(book->titolo, buffer);

	printf("Autore -> ");
	scanf(" %[^\n]s", &buffer);
	fflush(stdin);

	book->autore = (char*)malloc((sizeof(char) * strlen(buffer)));
	strcpy(book->autore, buffer);

	printf("Anno di pubblicazione -> ");
	scanf(" %d", &book->annoPubblicazione);
	fflush(stdin);


	printf("Casa editrice -> ");
	scanf(" %[^\n]s", &buffer);
	fflush(stdin);

	book->casaEditrice = (char*)malloc((sizeof(char) * strlen(buffer)));
	strcpy(book->casaEditrice, buffer);

	printf("Numero di pagine totali -> ");
	scanf(" %d", &book->numPagine);
	fflush(stdin);

	printf("Genere -> ");
	scanf(" %[^\n]s", &buffer);
	fflush(stdin);

	book->genere = (char*)malloc((sizeof(char) * strlen(buffer)));
	strcpy(book->genere, buffer);
	
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

void initializeBook(struct Libro *book) {
	//book->titolo = (char*)malloc(sizeof(buffer));
	//book->autore = (char*)malloc(sizeof(buffer));
	book->annoPubblicazione = (int*)malloc(sizeof(int));
	/*book->casaEditrice = (char*)malloc(sizeof(buffer));*/
	book->numPagine = (int*)malloc(sizeof(int));
	/*book->genere = (char*)malloc(sizeof(buffer));*/
	book->valutazione = (int*)malloc(sizeof(int));
}