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
	OrderModules(Suppliers Supplier, vector<ProductQuantity> productList)
		: Supplier(Supplier), productList(productList) {
		float total = 0;
		Identify id;

		for (auto product : productList) {
			total += product.product.getPrice() * product.quantity;
		}
			
		this->id = to_string(id._id);
		this->total = total;
	}


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
	string id;
	Suppliers Supplier;
	vector <ProductQuantity> productList;
	float total;
	float totalWithDiscount;
	float discount;
};