#include <stdio.h>
#include <string.h>

int main()
{
    int n_parroquias, continuar, i = 0;
    printf("Cuantas parroquias hay en la ciudad?: ");
    scanf("%d\n", &n_parroquias);

    int poblacion[n_parroquias],  // La ultima fila tendra la poblacion total
        consumo[n_parroquias][6], // La ultima fila tendra el consumo total del dia
        consumo_per_capita[6],
        consumo_total;
    char dias_semana[7][10] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"},
         parroquias[n_parroquias - 1][40];

    while (i < n_parroquias) // Ciclo condicional
    {
        printf("Nombre de la parroquia: ");
        scanf("%s\n", parroquias[i]);
        printf("poblacion: ");
        scanf("%d\n", poblacion);

        printf("\n### Litros consumidos en la semana ###\n");

        for (int dia = 0; dia < 7; dia++)
        {
            printf("%s : \n", dias_semana[dia]);
            scanf("%d", consumo[i][dia]);
        }
        printf("\n\n\n");
        i++;
    };

    for (int dia = 0; dia <= 6; dia++)
    {
        for (int parroquia = 0; parroquia < n_parroquias; parroquia++)
        {
            consumo[n_parroquias][dia] += consumo[parroquia][dia];
            poblacion[n_parroquias] += poblacion[parroquia];
            consumo_total = consumo[parroquia][dia];
        }
    }

    printf("\n### Consumo total por dia ###\n");
    for (int dia = 0; dia < 7; dia++)
    {
        printf("%s : %d\n", dias_semana[dia], consumo[n_parroquias][dia]);
    }

    printf("\nConsumo per capita: %d\n", (consumo_total / poblacion[n_parroquias]));

    printf("\n### Consulta de consumo ###\n");
    char consulta[40];
    int resultado;
    do
    {
        printf("Parroquia a consultar: ");
        scanf("%s\n", consulta);

        for (int parroquia = 0; parroquia < n_parroquias; parroquia++)
        {
            resultado = strcmp(parroquias[parroquia], consulta);
            if (resultado = 0)
            {
                printf("\n### Consumo parroquia %s ###\n", consulta);
                for (int dia = 0; dia <= 6; dia++)
                {
                    printf("%s : ", dias_semana[dia]);
                }
            }
        }

        if (resultado != 0)
        {
            printf("No se encontro la parroquia");
        }

        printf("Desa hacer otra consulta? \n Presione 0 para continuar o 1 para salir");

    } while (continuar = 0);

    printf("\nHello World!\n");
    return 0;
}