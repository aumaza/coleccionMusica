#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayList.h"
#include "misFunciones.h"
#include "albums.h"

#define TAM 40
#define TAM_GEN 10
#define TAM_ALB 20


#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#endif

/** \brief optionMain Function
 *
 * \param prompt the options the task to do, in a numeric main
 * \param call to the available functions
 * \return the action request in main selection.
 *
 */


int menu()
{
    osDetect(SO);


    int opc;

    do
    {
        osDetect(SO);

        ArrayList* list=al_newArrayList();
        checkNULL(list);


        printf("\n======================================");
        printf("\nSeleccione la Operacion a Realizar");
        printf("\n======================================\n");
        printf("\n1. Altas");
        printf("\n2. Modificar");
        printf("\n3. Baja");
        printf("\n4. Informes");
        printf("\n5. Salir");
        printf("\n\n======================================\n");

        opc=optionValid();
        printf("\n======================================\n");

        switch(opc)
        {

        case 1: loadMenu(); break;
        /*case 2:
            break;
        case 3:
            break;*/
        case 4: showBands(list,TAM); break;

        }
    }
    while(opc != 5);

    return 0;

}


Band* newBand()
{
    Band* newBand = (Band*)malloc(sizeof(Band));

if( newBand != NULL)
{

    newBand->id = 0;
    strcpy(newBand->name, "");
    newBand->cantIntegrantes = 0;
    strcpy(newBand->origin, "");
    newBand->isEmpty = 0;
}

return newBand;

}


Album* newAlbum()
{

    Album* newAlbum=(Album*)malloc(sizeof(Album));

    if(newAlbum != NULL)
    {
        newAlbum->id = 0;
        strcpy(newAlbum->name, "");
        newAlbum->cantSongs= 0;
        newAlbum->year = 0;
        newAlbum->idBand = 0;
        newAlbum->isEmpty = 0;
    }

    return newAlbum;
}


Genre* newGenre()
{

    Genre* newGenre=(Genre*)malloc(sizeof(Genre));

    if(newGenre != NULL)
    {
        newGenre->id = 0;
        strcpy(newGenre->description, "");
        newGenre->isEmpty = 0;
    }

    return newGenre;
}

int checkNULL(ArrayList* x)
{
    if(x==NULL)
    {
        printf("\nERROR AL CREAR!!");
        wait(SO);
        return 1;
    }

    else
    {
        printf("\nSUCCESS");
        return 0;
    }
}


int checkNULLX(void* x,int y)
{
    if(x==NULL)
    {
        printf("\nERROR AL CREAR!!");
        wait(SO);
        return 1;
    }

    else
    {
        printf("\nSUCCESS");
        return 0;
    }
}

int searchGenre(Genre* nGenre, int tamGenre, int id)
{
    int i;
    int index= -1;

    for(i=0; i<tamGenre; i++)
    {
        if((nGenre+i)->id == id && (nGenre+i)->isEmpty == 1)
        {
            index = i;
            break;
        }

        if((nGenre+i)->id == id && (nGenre+i)->isEmpty == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

int searchBand(Band* nBand, int tamBand, int id)
{
    int i;
    int index= -1;

    for(i=0; i<tamBand; i++)
    {
        if((nBand+i)->id == id && (nBand+i)->isEmpty == 1)
        {
            index = i;
            break;
        }

        if((nBand+i)->id == id && (nBand+i)->isEmpty == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}


int searchAlbum(ArrayList* y, int id)
{
    int i;
    int index=-1;
    Album* oneAlbum;

    for(i=0; i<y->len(y); i++)
    {
        oneAlbum=(Album*)y->get(y,i);

        if(oneAlbum->id==index && oneAlbum->isEmpty==1)
        {
            index=i;
            break;
        }
    }

    return index;
}


void addGenre(Genre* nGenre, int tam)
{
    osDetect(SO);

    Genre* pGenre;

    int is;
    int idGenre;


    printf("\n===========================");
    printf("\n.....::CARGAR GENERO::.....");
    printf("\n===========================");
    printf("\nINGRESE ID A BUSCAR: ");
    fflush(stdin);
    scanf("%d", &idGenre);
    getchar();

    is=searchGenre(nGenre,TAM_GEN,idGenre);


    if(is !=-1)
    {
        printf("\nYA EXISTE GENERO CON ESE ID!!");

    }

    else
    {
       pGenre = nGenre;

        if(nGenre != NULL)
        {
            pGenre->id=idGenre;
            printf("\nINGRESE DESCRIPCION: ");
            fflush(stdin);
            fgets(pGenre->description,20,stdin);
            removeNewLine(pGenre->description);
            strupper(pGenre->description);

            nGenre->isEmpty=1;
            //genre->add(genre,nGenre);

        }

    }
    printf("\n\n");
    wait(SO);
}


void addBand(Band* nband, int tam)
{
    osDetect(SO);

    Band* pBand;

    int is;
    int idBand;


    printf("\n==========================");
    printf("\n.....::CARGAR BANDA::.....");
    printf("\n==========================");
    printf("\nINGRESE ID A BUSCAR: ");
    fflush(stdin);
    scanf("%d", &idBand);
    getchar();

    is=searchBand(pBand,TAM,idBand);


    if(is !=-1)
    {
        printf("\nYA EXISTE BANDA CON ESE ID!!");
        showBand((Band*)band->get(band,is),tam);

    }

    else
    {
       nBand = newBand();

        if(nBand != NULL)
        {
            nBand->id=idBand;
            printf("\nINGRESE NOMBRE: ");
            fflush(stdin);
            fgets(nBand->name,30,stdin);
            removeNewLine(nBand->name);
            strupper(nBand->name);

            printf("\nINGRESE CANTIDAD DE INTEGRANTES: ");
            fflush(stdin);
            scanf("%d", &nBand->cantIntegrantes);
            getchar();

            printf("\nINGRESE EL ORIGEN: ");
            fflush(stdin);
            fgets(nBand->origin,20,stdin);
            removeNewLine(nBand->origin);
            strupper(nBand->origin);


            nBand->isEmpty=1;
            band->add(band,nBand);

        }

    }
    printf("\n\n");
    wait(SO);
}


void addAlbum(ArrayList* album, int tam, Genre* Genre, int tamGen, Band* Band, int tamBand)
{
    osDetect(SO);

    Album* nAlbum;

    int is;
    int idAlbum;



    printf("\n==========================");
    printf("\n.....::CARGAR ALBUM::.....");
    printf("\n==========================");
    printf("\nINGRESE ID A BUSCAR: ");
    fflush(stdin);
    scanf("%d", &idAlbum);
    getchar();

    is=searchAlbum(album,idAlbum);


    if(is !=-1)
    {
        printf("\nYA EXISTE ALBUM CON ESE ID!!");

    }

    else
    {
       nAlbum = newAlbum();

        if(nAlbum != NULL)
        {
            nAlbum->id=idAlbum;
            printf("\nINGRESE NOMBRE: ");
            fflush(stdin);
            fgets(nAlbum->name,51,stdin);
            removeNewLine(nAlbum->name);
            strupper(nAlbum->name);

            printf("\nINGRESE ANIO: ");
            fflush(stdin);
            scanf("%d", &nAlbum->year);
            getchar();

            printf("\nCANTIDAD CANCIONES: ");
            fflush(stdin);
            scanf("%d", &nAlbum->cantSongs);
            getchar();

            nAlbum->idGenre=selectGenre(Genre,tamGen);

            nAlbum->idBand=selectBand(Band,tamBand);

            nAlbum->isEmpty=1;
            album->add(album,nAlbum);


        }

    }
    printf("\n\n");
    wait(SO);

}


int loadMenu()
{
    osDetect(SO);

    Genre genre, *nGenre;
    nGenre = &genre;

    Band band, *nBand;
    nBand = &band;

    nGenre=(Genre*)malloc(sizeof(Genre)*TAM_GEN);
    nBand=(Band*)malloc(sizeof(Band)*TAM);

    checkNULLX(nGenre,TAM_GEN);
    checkNULLX(nBand,TAM);


    ArrayList* list=al_newArrayList();
    checkNULL(list);




    int opc;

    do
    {
        osDetect(SO);

        printf("\n======================================");
        printf("\nSeleccione la Operacion a Realizar");
        printf("\n======================================\n");
        printf("\n1. Cargar Banda");
        printf("\n2. Cargar Album");
        printf("\n3. Carga Genero");
        printf("\n4. Salir");
        printf("\n\n======================================\n");

        opc=optionValid();
        printf("\n======================================\n");

        switch(opc)
        {

        case 1: addBand(nBand,TAM); break;
        case 2: addAlbum(list,TAM_ALB,Genre,TAM_GEN,nBand,TAM); break;
        case 3: addGenre(list,TAM_GEN); break;

        }
    }
    while(opc != 4);

    return 0;

}

void showBand(Band* band, int tam)
{

    printf(" %4d %10d  %2s \n\n", band->id, band->cantIntegrantes, band->origin);

}


void loadDescription(Genre* Genre, int tamGen, int idGenre, char* string)
{
    int i;

    for(i=0; i < tamGen; i++)
    {
        if( (Genre + i)->id == idGenre)
        {
            strcpy(string, (Genre+i)->description);
            break;
        }
    }
}

int selectGenre(Genre* x, int tamGen)
{
    int i;
    int idGen;

    printf("\n=====GENEROS=====\n");
    printf("\n=================\n");
    for(i=0; i <tamGen; i++)
    {
        printf("  %d %s\n", x[i].id, x[i].description);
    }
    printf("\n SELECCIONE GENERO: ");
    scanf("%d", &idGen);

    return idGen;

}


int selectBand(Band* x, int tam)
{
    int i;
    int idBand;

    printf("\n=====BANDAS=====\n");
    printf("\n=================\n");
    for(i=0; i <tam; i++)
    {
        printf("  %d %s\n", x[i].id, x[i].name);
    }
    printf("\n SELECCIONE BANDA: ");
    scanf("%d", &idBand);

    return idBand;


}


void showBands(ArrayList* x, int tam)
{
    Band* oneBand;
    osDetect(SO);
    printf("------------------------------------------\n");
    printf("BANDA  INTEGRANTES   ORIGEN\n");
    printf("------------------------------------------\n\n");
    for(int i=0; i<x->len(x); i++)
    {
        oneBand = (Band*) x->get(x, i);
        if( oneBand->isEmpty == 1)
        {

            showBand(oneBand,TAM);
        }
    }
    printf("------------------------------------------\n\n");
    wait(SO);
}

