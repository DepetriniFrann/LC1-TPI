#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente
{
    int numero_cuenta;
    int contra;
    char nombre[50];
    float saldo;
    char estado[20];
};

int main()
{

    struct cliente clientes[10];

    int usuario_ingresado, contra_ingresada, es_encontrado, user_encontrado, indice, intentos, opcion;
    user_encontrado = 0;
    es_encontrado = 0;
    intentos = 0;
    indice = -1;
    opcion = 0;

    clientes[0].numero_cuenta = 1234;
    clientes[0].contra = 4321;
    strcpy(clientes[0].nombre, "Joaquin");
    clientes[0].saldo = 150000;
    strcpy(clientes[0].estado, "Activo");

    clientes[1].numero_cuenta = 4567;
    clientes[1].contra = 4115;
    strcpy(clientes[1].nombre, "Agustina");
    clientes[1].saldo = 19000;
    strcpy(clientes[1].estado, "Activo");

    clientes[2].numero_cuenta = 5991;
    clientes[2].contra = 7100;
    strcpy(clientes[2].nombre, "Felipe");
    clientes[2].saldo = 4000;
    strcpy(clientes[2].estado, "Activo");

    clientes[3].numero_cuenta = 8250;
    clientes[3].contra = 3125;
    strcpy(clientes[3].nombre, "Juan");
    clientes[3].saldo = 33000;
    strcpy(clientes[3].estado, "Activo");

    clientes[4].numero_cuenta = 1118;
    clientes[4].contra = 8014;
    strcpy(clientes[4].nombre, "Mariana");
    clientes[4].saldo = 7890;
    strcpy(clientes[4].estado, "Activo");

    clientes[5].numero_cuenta = 6750;
    clientes[5].contra = 4270;
    strcpy(clientes[5].nombre, "Mariela");
    clientes[5].saldo = 28900;
    strcpy(clientes[5].estado, "Activo");

    clientes[6].numero_cuenta = 9620;
    clientes[6].contra = 4284;
    strcpy(clientes[6].nombre, "Nicolas");
    clientes[6].saldo = 28960;
    strcpy(clientes[6].estado, "Activo");

    clientes[7].numero_cuenta = 3956;
    clientes[7].contra = 2896;
    strcpy(clientes[7].nombre, "Milagro");
    clientes[7].saldo = 39529;
    strcpy(clientes[7].estado, "Activo");

    clientes[8].numero_cuenta = 2986;
    clientes[8].contra = 9628;
    strcpy(clientes[8].nombre, "Julieta");
    clientes[8].saldo = 52390;
    strcpy(clientes[8].estado, "Activo");

    clientes[9].numero_cuenta = 6859;
    clientes[9].contra = 2865;
    strcpy(clientes[9].nombre, "Pedro");
    clientes[9].saldo = 25899;
    strcpy(clientes[9].estado, "Activo");

    
        do
        {
            user_encontrado = 0;
            // USUARIO //

            do
            {
                printf("Ingrese su numero de cuenta\n");
                scanf("%i", &usuario_ingresado);
                indice = -1;

                do
                {
                    indice = indice + 1;
                    if (usuario_ingresado == clientes[indice].numero_cuenta)
                    {
                        user_encontrado = 1;
                    }
                } while (indice < 10 && user_encontrado == 0);

                if (user_encontrado == 0)
                {
                    printf("Cuenta inexistente\n");
                }

            } while (user_encontrado == 0);

            // CONTRASEÑA //

            intentos = 0;
            es_encontrado = 0;
            do
            {
                printf("Ingrese su contrase%ca\n", 164);
                scanf("%i", &contra_ingresada);
                if (contra_ingresada == clientes[indice].contra)
                {
                    printf("\n");
                    printf("Bienvenido\n");
                    printf("Numero de cuenta: %i\n", clientes[indice].numero_cuenta);
                    printf("Contrase%ca: %i\n", 164, clientes[indice].contra);
                    printf("Nombre: %s\n", clientes[indice].nombre);
                    printf("Saldo: $%.2f\n", clientes[indice].saldo);
                    printf("Estado de la cuenta: %s\n", clientes[indice].estado);
                    es_encontrado = 1;
                }
                if (contra_ingresada != clientes[indice].contra)
                {
                    printf("Usuario incorrecto\n");
                    intentos = intentos + 1;
                }

            } while (intentos < 3 && es_encontrado == 0);

            if (intentos >= 3)
            {
                printf("Supero la cantidad de intentos, su cuenta ha sido bloqueada\n");
                strcpy(clientes[indice].estado, "Bloqueado");
            }
        } while (es_encontrado == 0 || user_encontrado == 0);


if (es_encontrado == 1 && user_encontrado == 1)
{
    printf("Ingrese una opcion:\n");
    printf("1. Realizar un Deposito\n");
    printf("2. Realizar una Extraccion\n");
    printf("3. Consultar el Saldo de Cuenta\n");
    printf("4. Realizar una Transferencia entre Cuentas\n");
    printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
    printf("6. Salir de la Sesion\n");
    scanf("%i", &opcion);

    switch (opcion)
    {
    case 1:
    if (clientes[indice].estado == "Activo")
    {
        printf("1. Haz un Deposito\n");
    } else {
          printf("Su cuenta esta bloqueada; comuniquese con la entidad bacaria\n");
    }
    
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    default:
        break;
    }
}
system("pause");
    return 0;
}