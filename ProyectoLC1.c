#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente
{
    int numero_cuenta;
    int contra;
    char nombre[50];
    float saldo;
    int estado;
};


int main()
{

    struct cliente clientes[10];

    int usuario_ingresado, user_transf_encontrado, contra_ingresada, pass_encontrado, user_encontrado, indice, intentos, opcion, movimientos, cuenta_ingresada, indice_transf, opcion_trnasf;
    float cant_ingresada;
    user_encontrado = 0;
    pass_encontrado = 0;
    intentos = 0;
    indice = -1;
    opcion = 0;
    movimientos = 0;

// CARGA CLIENTES

    clientes[0].numero_cuenta = 1234;
    clientes[0].contra = 4321;
    strcpy(clientes[0].nombre, "Joaquin");
    clientes[0].saldo = 150000;
    clientes[0].estado = 1;

    clientes[1].numero_cuenta = 4567;
    clientes[1].contra = 4115;
    strcpy(clientes[1].nombre, "Agustina");
    clientes[1].saldo = 19000;
    clientes[1].estado = 1;

    clientes[2].numero_cuenta = 5991;
    clientes[2].contra = 7100;
    strcpy(clientes[2].nombre, "Felipe");
    clientes[2].saldo = 4000;
    clientes[2].estado = 1;

    clientes[3].numero_cuenta = 8250;
    clientes[3].contra = 3125;
    strcpy(clientes[3].nombre, "Juan");
    clientes[3].saldo = 33000;
    clientes[3].estado = 1;

    clientes[4].numero_cuenta = 1118;
    clientes[4].contra = 8014;
    strcpy(clientes[4].nombre, "Mariana");
    clientes[4].saldo = 7890;
    clientes[4].estado = 1;

    clientes[5].numero_cuenta = 6750;
    clientes[5].contra = 4270;
    strcpy(clientes[5].nombre, "Mariela");
    clientes[5].saldo = 28900;
    clientes[5].estado = 1;

    clientes[6].numero_cuenta = 9620;
    clientes[6].contra = 4284;
    strcpy(clientes[6].nombre, "Nicolas");
    clientes[6].saldo = 28960;
    clientes[6].estado = 1;

    clientes[7].numero_cuenta = 3956;
    clientes[7].contra = 2896;
    strcpy(clientes[7].nombre, "Milagro");
    clientes[7].saldo = 39529;
    clientes[7].estado = 1;

    clientes[8].numero_cuenta = 2986;
    clientes[8].contra = 9628;
    strcpy(clientes[8].nombre, "Julieta");
    clientes[8].saldo = 52390;
    clientes[8].estado = 1;

    clientes[9].numero_cuenta = 6859;
    clientes[9].contra = 2865;
    strcpy(clientes[9].nombre, "Pedro");
    clientes[9].saldo = 25899;
    clientes[9].estado = 1;




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
        if (clientes[indice].estado == 1)
        {

            intentos = 0;
            pass_encontrado = 0;
            do
            {
                printf("Ingrese su contrase%ca\n", 164);
                scanf("%i", &contra_ingresada);

                if (contra_ingresada == clientes[indice].contra)
                {
                    pass_encontrado = 1;
                } else{
                    printf("Usuario incorrecto\n");
                    intentos = intentos + 1;
                }

            } while (intentos < 3 && pass_encontrado == 0);

            if (intentos >= 3)
            {
                printf("Supero la cantidad de intentos, su cuenta ha sido bloqueada\n");
                clientes[indice].estado = 0;
            }
        }
        else
        {
            printf("Su cuenta esta bloqueada; comuniquese con la entidad bancaria\n");
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
    printf("\n");
    scanf("%i", &opcion);

    switch (opcion)
    {
    case 1:
        movimientos = movimientos + 1;
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
        clientes[indice].saldo = clientes[indice].saldo + cant_ingresada;
        
        break;

    case 2:
        movimientos = movimientos + 1;
        printf("Cuanto dinero va a Extraer?\n");
        printf("Ingrese una cantidad: $");
        do
        {
            scanf("%f", &cant_ingresada);
            if ((clientes[indice].saldo - cant_ingresada) < 0)
            {
                printf("Excede la cantidad disponible de su cuenta\n");
                printf("Ingrese una cantidad: $");
            }
            if (cant_ingresada < 1)
            {
                printf("Ingrese una cantidad positiva\n");
                printf("Ingrese una cantidad: $");
            }
            
            
        } while ((clientes[indice].saldo - cant_ingresada ) < 0 || cant_ingresada < 1);

        clientes[indice].saldo = clientes[indice].saldo - cant_ingresada;
        break;

    case 3:
        movimientos = movimientos + 1;
        printf("El saldo de su cuenta es: $%.2f\n", clientes[indice].saldo);

        break;

    case 4:
        user_transf_encontrado = 0;
        do
        {
            printf("Ingrese el numero de cuenta al que desea Transferirle dinero\n");
            scanf("%i", &cuenta_ingresada);
            indice_transf = -1;

            do
            {
                indice_transf = indice_transf + 1;
                if (cuenta_ingresada == clientes[indice_transf].numero_cuenta)
                {
                    user_transf_encontrado = 1;
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
            if ((clientes[indice].saldo - cant_ingresada) < 0)
            {
                printf("Excede la cantidad disponible de su cuenta\n");
                printf("Ingrese una cantidad: $");
            }
            if (cant_ingresada < 1)
            {
                printf("Ingrese una cantidad positiva\n");
                printf("Ingrese una cantidad: $");
            }
            
        } while ((clientes[indice].saldo - cant_ingresada ) < 0 || cant_ingresada < 1);

        

        printf("Desea transferirle $%.2f a %s?\n1. SI\n2. NO\n", cant_ingresada, clientes[indice_transf].nombre);
        scanf("%i", &opcion_trnasf);

        if (opcion_trnasf == 1)
        {
            printf("Transferencia existosa\n");
            clientes[indice].saldo = clientes[indice].saldo - cant_ingresada;
            clientes[indice_transf].saldo = clientes[indice_transf].saldo + cant_ingresada;
        } else{
            printf("Transferencia interrumpida.\nGracias!\n");
            break;
        }

        }
        
        break;

    case 5:

        printf("La cantidad de Operaciones es (%i)\n", movimientos);
        printf("El saldo actual de su cuenta es de: $%.2f\n", clientes[indice].saldo);

        break;

    default:
        break;
    }
} while (opcion != 6 && movimientos < 10);

    if (movimientos > 9)
    {
        printf("Ha alcanzado el límite de operaciones. Gracias.\n");
    }
    
    if (opcion == 6)
    {
        printf("Gracias por confiar en nosotros.\nQue tenga un buen dia!!\n");
    }
    

    system("pause");
    return 0;
}