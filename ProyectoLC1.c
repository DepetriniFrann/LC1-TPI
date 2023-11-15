//Integrantes:

//De Bonis Ulises
//Depetrini Francisco
//Tanlongo Joaquin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float deposito(float cant_ingresada, float saldo[], int indice);
float extraccion(float cant_ingresada, float saldo[], int indice);
float transferencia(float cant_ingresada, float saldo[], int indice, int indice_transf, char nombre[][50], int user_transf_encontrado, int cuenta_ingresada, int numero_cuenta[], int opcion_trnasf);

int main()
{

    int numero_cuenta[10];
    int contra[10];
    char nombre[10][50];
    float saldo[10];
    int estado[10];

    int usuario_ingresado, user_transf_encontrado, contra_ingresada, pass_encontrado, user_encontrado, indice, intentos, opcion, movimientos, cuenta_ingresada, indice_transf, opcion_trnasf, bucle;
    float cant_ingresada;

    opcion = 0;
    bucle = 0;

    numero_cuenta[0] = 1234;
    contra[0] = 4321;
    strcpy(nombre[0], "Joaquin");
    saldo[0] = 150000;
    estado[0] = 1;

    numero_cuenta[1] = 4567;
    contra[1] = 4115;
    strcpy(nombre[1], "Agustina");
    saldo[1] = 19000;
    estado[1] = 1;

    numero_cuenta[2] = 5991;
    contra[2] = 7100;
    strcpy(nombre[2], "Felipe");
    saldo[2] = 4000;
    estado[2] = 1;

    numero_cuenta[3] = 8250;
    contra[3] = 3125;
    strcpy(nombre[3], "Juan");
    saldo[3] = 33000;
    estado[3] = 1;

    numero_cuenta[4] = 1118;
    contra[4] = 8014;
    strcpy(nombre[4], "Mariana");
    saldo[4] = 7890;
    estado[4] = 1;

    numero_cuenta[5] = 6750;
    contra[5] = 4270;
    strcpy(nombre[5], "Mariela");
    saldo[5] = 28900;
    estado[5] = 1;

    numero_cuenta[6] = 9620;
    contra[6] = 4284;
    strcpy(nombre[6], "Nicolas");
    saldo[6] = 28960;
    estado[6] = 1;

    numero_cuenta[7] = 3956;
    contra[7] = 2896;
    strcpy(nombre[7], "Milagro");
    saldo[7] = 39529;
    estado[7] = 1;

    numero_cuenta[8] = 2986;
    contra[8] = 9628;
    strcpy(nombre[8], "Julieta");
    saldo[8] = 52390;
    estado[8] = 1;

    numero_cuenta[9] = 6859;
    contra[9] = 2865;
    strcpy(nombre[9], "Pedro");
    saldo[9] = 25899;
    estado[9] = 1;

    do
    {
        movimientos = 0;
        do
        {
            user_encontrado = 0;
            // USUARIO //

            do
            {
                printf("Ingrese su numero de cuenta\n");
                scanf("%i", &usuario_ingresado);
                indice = 0;

                do
                {

                    if (usuario_ingresado == numero_cuenta[indice])
                    {
                        user_encontrado = 1;
                    }
                    else
                    {
                        indice = indice + 1;
                    }

                } while (indice < 10 && user_encontrado == 0);

                if (user_encontrado == 0)
                {
                    printf("Cuenta inexistente\n");
                }

            } while (user_encontrado == 0);

            intentos = 0;
            pass_encontrado = 0;
            // CONTRASEÑA //
            if (estado[indice] == 1)
            {

                do
                {
                    printf("Ingrese su contrase%ca\n", 164);
                    scanf("%i", &contra_ingresada);
                    if (contra_ingresada == contra[indice])
                    {
                        pass_encontrado = 1;
                    }
                    if (contra_ingresada != contra[indice])
                    {
                        printf("Contrase%ca incorrecta\n", 164);
                        intentos = intentos + 1;
                    }

                } while (intentos < 3 && pass_encontrado == 0);

                if (intentos >= 3)
                {
                    printf("Supero la cantidad de intentos, su cuenta ha sido bloqueada\n");
                    estado[indice] = 0;
                }
            }
            else
            {
                printf("Su cuenta esta bloqueada; comuniquese con la entidad bacaria\n");
            }
        } while (pass_encontrado == 0 || user_encontrado == 0);

        do
        {

            printf("\n");
            printf("Ingrese una opcion:\n");
            printf("1. Realizar un Deposito\n");
            printf("2. Realizar una Extraccion\n");
            printf("3. Consultar el Saldo de Cuenta\n");
            printf("4. Realizar una Transferencia entre Cuentas\n");
            printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual\n");
            printf("6. Salir de la Sesion\n");
            scanf("%i", &opcion);
            printf("\n");

            switch (opcion)
            {
            case 1:
                movimientos = movimientos + 1;
                deposito(cant_ingresada, saldo, indice);
                break;

            case 2:
                movimientos = movimientos + 1;
                extraccion(cant_ingresada, saldo, indice);
                break;

            case 3:
                movimientos = movimientos + 1;
                printf("El saldo de su cuenta es: $%.2f\n", saldo[indice]);
                break;

            case 4:
                transferencia(cant_ingresada, saldo, indice, indice_transf, nombre, user_transf_encontrado, cuenta_ingresada, numero_cuenta, opcion_trnasf);
                break;

            case 5:
                printf("La cantidad de Operaciones es (%i)\n", movimientos);
                printf("El saldo actual de su cuenta es de: $%.2f\n", saldo[indice]);
                break;

            default:
                break;
            }
        } while (opcion != 6 && movimientos < 10);

        if (movimientos > 9)
        {
            printf("Ha alcanzado el l%cmite de operaciones. Gracias.\n", 161);
        }

        if (opcion == 6)
        {
            printf("Gracias por confiar en nosotros.\nQue tenga un buen dia!!\n");
        }
    } while (bucle == 0);
    system("pause");
    return 0;
}

float deposito(float cant_ingresada, float saldo[], int indice)
{

    printf("Cuanto dinero va a Depositar?\n");
    printf("Ingrese una cantidad: $");
    do
    {
        scanf("%f", &cant_ingresada);
        if (cant_ingresada < 1)
        {
            printf("Ingrese una cantidad positiva\n");
            printf("Ingrese una cantidad mayor a 0: $");
        }

    } while (cant_ingresada < 1);

    printf("Depositado con exito $%.2f\n", cant_ingresada);
    saldo[indice] = saldo[indice] + cant_ingresada;
}

float extraccion(float cant_ingresada, float saldo[], int indice)
{

    printf("Cuanto dinero va a Extraer?\n");
    printf("Ingrese una cantidad: $");

    do
    {
        scanf("%f", &cant_ingresada);
        if ((saldo[indice] - cant_ingresada) < 0)
        {
            printf("Excede la cantidad disponible de su cuenta\n");
            printf("Ingrese una cantidad: $");
        }
        if (cant_ingresada < 1)
        {
            printf("Ingrese una cantidad positiva\n");
            printf("Ingrese una cantidad: $");
        }

    } while ((saldo[indice] - cant_ingresada) < 0 || cant_ingresada < 1);

    saldo[indice] = saldo[indice] - cant_ingresada;
}

float transferencia(float cant_ingresada, float saldo[], int indice, int indice_transf, char nombre[][50], int user_transf_encontrado, int cuenta_ingresada, int numero_cuenta[], int opcion_trnasf)
{

    user_transf_encontrado = 0;
    do
    {
        printf("Ingrese el numero de cuenta al que desea Transferirle dinero\n");
        scanf("%i", &cuenta_ingresada);
        indice_transf = 0;

        do
        {

            if (cuenta_ingresada == numero_cuenta[indice_transf])
            {
                user_transf_encontrado = 1;
            }
            else
            {
                indice_transf = indice_transf + 1;
            }
        } while (indice_transf < 10 && user_transf_encontrado == 0);

        if (user_transf_encontrado == 0)
        {
            printf("Cuenta inexistente\n");
        }

    } while (user_transf_encontrado == 0);

    if (user_transf_encontrado == 1)
    {
        printf("Ingrese cuanta cantidad va a transferir\n");

        do
        {
            scanf("%f", &cant_ingresada);
            if ((saldo[indice] - cant_ingresada) < 0)
            {
                printf("Excede la cantidad disponible de su cuenta\n");
                printf("Ingrese una cantidad: $");
            }
            if (cant_ingresada < 1)
            {
                printf("Ingrese una cantidad positiva\n");
                printf("Ingrese una cantidad: $");
            }

        } while ((saldo[indice] - cant_ingresada) < 0 || cant_ingresada < 1);

        printf("Desea transferirle $%.2f a %s?\n1. SI\n2. NO\n", cant_ingresada, nombre[indice_transf]);
        scanf("%i", &opcion_trnasf);

        if (opcion_trnasf == 1)
        {
            printf("Transferencia existosa\n");
            saldo[indice] = saldo[indice] - cant_ingresada;
            saldo[indice_transf] = saldo[indice_transf] + cant_ingresada;
        }
        else
        {
            printf("Transferencia interrumpida.\nGracias!\n");
        }
    }
}
