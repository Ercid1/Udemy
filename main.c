#include <stdio.h>
#include <string.h>

struct Jugador
{
    char nombre[50];
    int edad;
    float altura;
};

void listarJugadores(struct Jugador jugadores[], int numJugadores)
{
    printf("\nNombres y alturas de los jugadores:\n");
    for (int i = 0; i < numJugadores; i++)
    {
        printf("Nombre: %s\n", jugadores[i].nombre);
        printf("Altura: %.2f metros\n", jugadores[i].altura);
    }
}

void buscarJugador(struct Jugador jugadores[], int numJugadores, char nombreBuscar[])
{
    int encontrado = 0;
    for (int i = 0; i < numJugadores; i++)
    {
        if (strcmp(jugadores[i].nombre, nombreBuscar) == 0)
        {
            printf("\nJugador encontrado:\n");
            printf("Nombre: %s\n", jugadores[i].nombre);
            printf("Altura: %.2f metros\n", jugadores[i].altura);
            printf("Edad: %d\n", jugadores[i].edad);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Jugador no encontrado\n");
    }
}

void jugadorMasAlto(struct Jugador jugadores[], int numJugadores)
{
    float alturaMaxima = jugadores[0].altura;
    int indiceJugadorMaximo = 0;

    for (int i = 1; i < numJugadores; i++)
    {
        if (jugadores[i].altura > alturaMaxima)
        {
            alturaMaxima = jugadores[i].altura;
            indiceJugadorMaximo = i;
        }
    }

    printf("\nJugador más alto:\n");
    printf("Nombre: %s\n", jugadores[indiceJugadorMaximo].nombre);
    printf("Edad: %d\n", jugadores[indiceJugadorMaximo].edad);
}

int main()
{
    struct Jugador jugadores[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre del jugador: ");
        fgets(jugadores[i].nombre, sizeof(jugadores[i].nombre), stdin);
        jugadores[i].nombre[strcspn(jugadores[i].nombre, "\n")] = '\0';

        printf("Ingrese la edad del jugador: ");
        scanf("%d", &jugadores[i].edad);

        printf("Ingrese la altura del jugador (en metros): ");
        scanf("%f", &jugadores[i].altura);

                while (getchar() != '\n')
            ;
    }

    int opcion;
    char nombreBuscar[50];

    do
    {
        printf("\n------ MENÚ ------\n");
        printf("1. Listar nombres y alturas de los jugadores\n");
        printf("2. Buscar un jugador por su nombre\n");
        printf("3. Mostrar el jugador más alto\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            listarJugadores(jugadores, 5);
            break;
        case 2:
            printf("Ingrese el nombre del jugador a buscar: ");
            while (getchar() != '\n')
                ;
            fgets(nombreBuscar, sizeof(nombreBuscar), stdin);
            nombreBuscar[strcspn(nombreBuscar, "\n")] = '\0';
            buscarJugador(jugadores, 5, nombreBuscar);
            break;
        case 3:
            jugadorMasAlto(jugadores, 5);
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida. Por favor, ingrese una opción válida.\n");
            break;
        }
    } while (opcion != 0);

    return 0;
}
