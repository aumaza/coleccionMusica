#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct inf_solista
{
    char nombre[40];
    char f_nac[11];
    char f_fall[11];
    int edad;
};

struct inf_banda
{
    char nombre[40];
    int cant_integ;
    char pais_origen[20];
    int anio_form;
    int anio_sep;
};

struct inf_genero
{
    char genero[20];
};

struct Album
{
    char nombre[40];
    int cant_track;
    int anio_lanz;
    struct inf_solista inf_solo;
    struct inf_banda inf_band;
    struct inf_genero inf_gen;
};

//PROTOTIPOS

void menuGeneral ();

#endif // FUNCIONES_H_INCLUDED
