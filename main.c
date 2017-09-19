#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TI 5
#define TC 10

typedef struct
{
    int idCancion;
    char titulo [50];
    int interprete;
    float duracion;
}eCancion;

typedef struct
{
    int idInterprete;
    char nombre [50];
    char nacionalidad [50];
}eInterprete;

void inicializarCanciones (eCancion lista[], int tam);
void inicializarInterpretes (eInterprete lista[], int tam);

void listarCanciones (eCancion lista[], int tam);
void listarInterpretes (eInterprete lista[], int tam);

void listarCancionesConInterpretes(eCancion[], int, eInterprete[],int);

int main()
{
    eInterprete listaInterpretes [TI];
    eCancion listaCanciones [TC];

    inicializarInterpretes(listaInterpretes,TI);
    inicializarCanciones(listaCanciones,TC);

    listarInterpretes(listaInterpretes, TI);
    listarCanciones(listaCanciones, TC);

    system("pause");
    system("cls");

    listarCancionesConInterpretes (listaCanciones, TC, listaInterpretes, TI);

    return 0;
}

void inicializarInterpretes(eInterprete lista[], int tam)
{
    int id[]={1,2,3,4,5};
    char nombre[][50]={"Sh","Ad","Ka","Br","Sa"};
    char nacionalidad[][30]={"Colombia","RUGB","Argentina","EEUU","EEUU"};
    int i;

    for (i=0;i<tam;i++)
    {
        lista[i].idInterprete=id[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].nacionalidad, nacionalidad[i]);
    }
}

void inicializarCanciones(eCancion lista[], int tam)
{
    int idCancion[]={1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};
    char titulo[][30]={"Melt","La bici","When","Ment","Heart","Stone","I was","Your men","Aaa","Bbb"};
    char interprete[]={2,1,4,3,1,5,3,5,5,4};
    float duracion[]={1.05,2,1.5,3,4,4.5,3.5,3,2.5,2};
    int i;

    for (i=0;i<tam;i++)
    {
        lista[i].idCancion=idCancion[i];
        lista[i].interprete=interprete[i];
        lista[i].duracion=duracion[i];
        strcpy(lista[i].titulo, titulo[i]);
    }
}

void listarCanciones(eCancion lista[],int tam)
{
    int i;
    printf("CANCIONES\n");
    for (i=0;i<tam;i++)
    {
        printf("%d-%s-%d--.2%f\n",lista[i].idCancion,lista[i].titulo,lista[i].interprete,lista[i].duracion);
    }
}

void listarInterpretes(eInterprete lista[],int tam)
{
    int i;
    printf("INTERPRETES\n");
    for (i=0;i<tam;i++)
    {
        printf("%d-%s-%s\n",lista[i].idInterprete,lista[i].nombre,lista[i].nacionalidad);
    }
}

void listarCancionesConInterpretes(eCancion listaCanciones[],int tamC,eInterprete listaInterpretes[],int tamI)
{
    int i;
    int j;
    eInterprete auxInterprete;
    printf("CANCIONES C/INTERPRETE\n");
    printf("Id \tTitulo\t\t\tInterprete\tDuracion\n");

    for (i=0;i<tamC;i++)
    {
        for (j=0;j<tamI;j++)
        {
            if (listaCanciones[i].interprete==listaInterpretes[j].idInterprete)
            {
                auxInterprete = listaInterpretes[j];
                break;
            }
        }
        printf("%4d\t%20s\t%20s\t%4.2f\n",listaCanciones[i].idCancion,listaCanciones[i].titulo,auxInterprete.nombre,listaCanciones[i].duracion);
    }
}
