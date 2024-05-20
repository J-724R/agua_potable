// Gabriel Galán y Breymari Gómez
// Sección 1
// Ing Industrial
// 31386815
// Codigo complejo y ordenado

#include <stdio.h>
#include <string.h>

int main()
{
    int n_parroquias, continuar = 0, i = 0;
    printf("Cuantas parroquias hay en la ciudad?: ");
    scanf("%d", &n_parroquias);

    int poblacion[n_parroquias + 1],  // La ultima fila tendra la poblacion total
        consumo[n_parroquias + 1][7], // La ultima fila tendra el consumo total del dia
        consumo_total;
    float consumo_per_capita[7];
    char dias_semana[7][10] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"},
         parroquias[n_parroquias][40];

    while (i < n_parroquias) // Ciclo condicional
    {
        printf("Nombre de la parroquia: ");
        scanf("%s", parroquias[i]);
        printf("poblacion: ");
        scanf("%d", &poblacion[i]);

        printf("\n");
        printf("###   ##############################   ###\n");
        printf("###                                    ###\n");
        printf("###   Litros consumidos en la semana   ###\n");
        printf("###                                    ###\n");
        printf("###   ##############################   ###\n");
        printf("\n");

        for (int dia = 0; dia < 7; dia++)
        {
            printf("%s: ", dias_semana[dia]);
            scanf("%d", &consumo[i][dia]);
        }
        printf("\n\n");
        i++;
    };

    for (int dia = 0; dia <= 6; dia++)
    {
        for (int parroquia = 0; parroquia < n_parroquias; parroquia++)
        {
            consumo[n_parroquias][dia] += consumo[parroquia][dia];
            poblacion[n_parroquias] += poblacion[parroquia]; // not working as expected
            consumo_total += consumo[parroquia][dia];
        }
    }

    printf("\n\n");
    printf("###   ##############################   ###\n");
    printf("###                                    ###\n");
    printf("###       Consumo total por dia        ###\n");
    printf("###                                    ###\n");
    printf("###   ##############################   ###\n");
    printf("\n");

    for (int dia = 0; dia < 7; dia++)
    {
        printf("%s: %d  \n", dias_semana[dia], consumo[n_parroquias][dia]);
    }

    printf("\n\n");
    printf("###   ##############################   ###\n");
    printf("###                                    ###\n");
    printf("###          Consumo per capita        ###\n");
    printf("###                                    ###\n");
    printf("###   ##############################   ###\n");
    printf("\n");

    for (int dia = 0; dia < 7; dia++)
    {
        consumo_per_capita[dia] = consumo[n_parroquias][dia] / poblacion[n_parroquias];
        printf("%s: %d \n", dias_semana[dia], consumo_per_capita[dia]);
    }

    printf("\n\n");
    printf("###   ##############################   ###\n");
    printf("###                                    ###\n");
    printf("###       Consulta por Parroquia       ###\n");
    printf("###                                    ###\n");
    printf("###   ##############################   ###\n");
    printf("\n");

    char consulta[40];
    int resultado = 0;
    do
    {
        printf("Parroquia a consultar: ");
        scanf("%s", consulta);

        for (int parroquia = 0; parroquia < n_parroquias; parroquia++)
        {
            resultado = strcmp(parroquias[parroquia], consulta);
            if (resultado == 0)
            {
                printf("\n### Consumo parroquia %s ###\n", consulta);
                for (int dia = 0; dia <= 6; dia++)
                {
                    printf("%s : %d \n", dias_semana[dia], consumo[parroquia][dia]);
                }
                break;
            }
        }

        printf("resultado: %i", resultado);

        if (resultado != 0)
        {
            printf("No se encontro la parroquia");
        }

        printf("Desea hacer otra consulta? \n Presione 0 para continuar o 1 para salir");
        scanf("%s", continuar);
    } while (continuar = 0);

    printf("\nHello World!\n");
    return 0;
}