/*
Realizzare un programma che gestisca la lista di tutti i libri letti in un anno. Per ognuno di essi, il programma deve memorizzare una serie di informazioni,
ad esempio il titolo, l’autore, l’anno di pubblicazione, la casa editrice, la lunghezza, il genere, il codice identificativo, la valutazione.
Il programma dovrà permettere di inserire un nuovo libro, cancellarne uno, visualizzarli tutti, visualizzare solo quelli con una certa valutazione.
Il programma deve lavorare leggendo e scrivendo le informazioni da e su file binario. Consegnare un file .zip contente un progetto che comprenda tutti
i file necessari per testare il programma.

VENTRUCCI TOMAS, MARCHETTI DAVIDE, ZOLI FEREDEICO
*/

#define _CRT_SECURE_NO_WARNINGS
#include <float.h>
#include <stdio.h>

void addBook(struct Libro*);					//aggiunge un libro al file
void deleteBook();							//elimina un libro
void initializeBook(struct Libro);			//inizializzo un libro
void showBooks();							//fa vedere tutti i libri
void showSomeBooks(int);					//fa vedere alcuni libri

char buffer[255];		//buffer di scrittura dei campi del libro

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

	//initialize book struct char pointers
	struct Libro *book;
	FILE file;
	char* path = "..\\File\\file.bin";

	if (fopen(path, "wb") == NULL) {
		printf("Errore -> Impossibile aprire il file\n");
		return 0;
	}


		
	book = (struct Libro*)malloc(sizeof(struct Libro));

	addBook(book);
		
	printf("%d\n", book->valutazione);

	return 0;
}


void addBook(struct Libro *book) {
	/*printf("Titolo -> ");
	scanf(" %[^\n]s", &book->titolo);
	fflush(stdin);

	printf("Autore -> ");
	scanf(" %[^\n]s", &book->autore);
	fflush(stdin);

	printf("Anno di pubblicazione -> ");
	scanf(" %d", &book->annoPubblicazione);
	fflush(stdin);

	printf("Casa editrice -> ");
	scanf(" %[^\n]s", &book->casaEditrice);
	fflush(stdin);

	printf("Numero di pagine totali -> ");
	scanf(" %d", &book->numPagine);
	fflush(stdin);

	printf("Genere -> ");
	scanf(" %[^\n]s", &book->genere);
	fflush(stdin);
	*/
	printf("Valutazione -> ");
	scanf(" %d", &book->valutazione);
	fflush(stdin);
}

void initializeBook(struct Libro *book) {
	book->titolo = (char*)malloc(sizeof(buffer));
	book->autore = (char*)malloc(sizeof(buffer));
	book->annoPubblicazione = (int*)malloc(sizeof(int));
	book->casaEditrice = (char*)malloc(sizeof(buffer));
	book->numPagine = (int*)malloc(sizeof(int));
	book->genere = (char*)malloc(sizeof(buffer));
	book->valutazione = (int*)malloc(sizeof(int));
}