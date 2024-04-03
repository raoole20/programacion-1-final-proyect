#include <iostream>
#include <cstdlib>
#include "UUID.cpp"
#include "App.cpp"

/*
* �	Crear una aplicaci�n que gestione las ventas de una empresa.
�	Implement
�	Utilizar clases para representar 
		*productos 
		*clientes 
		*pedidos 
		*facturas
�	Implementar m�todos para gestionar las operaciones CRUD sobre los datos.ar funcionalidades como: 
		*registro de productos 
		*registro de clientes 
		*creaci�n de pedidos  
		*generaci�n de facturas 
		*control de stock
*/

int main()
{
    // Crear una instancia de la aplicación
    App app;
    app.init();

    // Bucle principal de la aplicación
    while (app.getRun())
    {
        // Mostrar el menú y obtener la opción seleccionada
        int option = app.showMenu();
        switch (option)
        {
            case 1: 
                app.customerMenu(); // Acceder al módulo de clientes
                break;
            case 2: 
                app.productMenu(); // Acceder al módulo de productos
                break;
            case 3:
                app.salesMenu(); // Acceder al módulo de pedidos/ventas
                break;
            case 9:
                app.clear();
                app.init(); // Mostrar nuevamente la pantalla de inicio
                break;
            case 10:
                app.killApp(); // Finalizar la aplicación
                break;
            default:	
                app.clear();
                cout << "Opción no válida, inténtalo nuevamente" << endl;	
                cout << "Para continuar, presiona cualquier tecla y luego Enter" << endl;
                string temp;
                cin >> temp;
                break;
        }
    }

    return 0;
}
