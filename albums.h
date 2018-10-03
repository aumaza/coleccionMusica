#ifndef ALBUMS_H_INCLUDED
#define ALBUMS_H_INCLUDED

typedef struct
{
    int id;
    char name[30];
    int cantIntegrantes;
    char origin[20];
    int isEmpty;

}Band;

typedef struct
{
    int id;
    char name[51];
    int year;
    int cantSongs;
    int idGenre;
    int idBand;
    int isEmpty;
}Album;

typedef struct
{
    int id;
    char description[20];
    int isEmpty;
}Genre;

Album* newAlbum();
Band* newBand();
Genre* newGenre();

int menu();
int checkNULL(ArrayList* x);
int searchGenre(Genre* nGenre, int tamGenre, int id);
int searchBand(Band* x, int tamBand, int id);
int searchAlbum(ArrayList* Album, int id);
int loadMenu();
void addAlbum(ArrayList* album, int tam, Genre* Genre, int tamGen, Band* Band, int tamBand);
void addBand(Band* nBand, int tam);
void addGenre(Genre* nGenre, int tam);
void showBand(Band* band, int tam);
void showBands(ArrayList* x, int tam);
void loadDescription(Genre* Genre, int tamGen, int idGenre, char* string);
int  selectGenre(Genre* Genre, int tamGen);
int  selectBand(Band* x, int tam);
int checkNULL(ArrayList* x);
int checkNULLX(void* x,int y);




#endif // ALBUMS_H_INCLUDED
