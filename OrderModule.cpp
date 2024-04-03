#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "UUID.cpp"
#include "Product.cpp"
#include "ProductQuantity.cpp"
#include "Supplier.cpp"

using namespace std;

class OrderModules{
public:
    // Constructor de la clase OrderModules
    // Recibe un objeto de tipo Suppliers y un vector de objetos de tipo ProductQuantity
    // Calcula el total del pedido y genera un ID para el pedido
    OrderModules(Suppliers Supplier, vector<ProductQuantity> productList)
        : Supplier(Supplier), productList(productList) {
        float total = 0;
        Identify id;

        // Calcula el total del pedido
        for (auto product : productList) {
            total += product.product.getPrice() * product.quantity;
        }
            
        this->id = to_string(id._id);
        this->total = total;
    }

    // Función para mostrar la información del pedido
    // Imprime el ID del pedido, el nombre del proveedor, los productos del pedido y el total
    void displaySalesInformation() {
        cout << "RECIBO DE PEDIDO" << endl;
        cout << "-------------------------" << endl << endl << endl;

        cout << "ID del Pedido: " << this->id << endl;
        cout << "Proveedor: " << this->Supplier.getName() << " " << this->Supplier.getLastName() << endl;
        cout << "Productos: " << endl;
        for (auto product : this->productList) {
            cout << "\tID del producto: " << product.product.getId() << endl;
            cout << "\tNombre: " << product.product.getName() << endl;
            cout << "\tCantidad: " << product.quantity << endl;
            cout << "\tPrecio: " << product.product.getPrice() << endl;
            cout << "\t-------------" << endl;
        }
        cout << "Total: " << this->total << "$" << endl;
        cout << "(El valor de la factura esta en Dolares Estados estadounidense)";

    }
private:
    string id; // ID del pedido
    Suppliers Supplier; // Proveedor del pedido
    vector <ProductQuantity> productList; // Lista de productos del pedido
    float total; // Total del pedido
    float totalWithDiscount; // Total del pedido con descuento
    float discount; // Descuento del pedido
};