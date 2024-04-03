#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "UUID.cpp"
#include "Product.cpp"
#include "ProductQuantity.cpp"
#include "Customer.cpp"

using namespace std;

class Sales {
public:
	Sales(Customers customer, vector<ProductQuantity> productList)
		: customer(customer), productList(productList) {
		float total = 0;
		Identify id;

		for (auto product : productList) {
			total += product.product.getPrice() * product.quantity;
		}
			
		this->id = to_string(id._id);
		this->total = total;
	}


	void displaySalesInformation() {
		cout << "RECIBO DE VENTA" << endl;
		cout << "-------------------------" << endl << endl << endl;

		cout << "ID de la venta: " << this->id << endl;
		cout << "Cliente: " << this->customer.getName() << " " << this->customer.getLastName() << endl;
		cout << "Productos: " << endl;
		for (auto product : this->productList) {
			cout << "\tID del producto: " << product.product.getId() << endl;
			cout << "\tNombre: " << product.product.getName() << endl;
			cout << "\tCantidad: " << product.quantity << endl;
			cout << "\tPrecio: " << product.product.getPrice() << endl;
			cout << "\t-------------" << endl;
		}
		cout << "Total: " << this->total << "$" << endl;
		cout << "(El valor de la factura esta en Dolares Estados Unidences)";

	}
private:
	string id;
	Customers customer;
	vector <ProductQuantity> productList;
	float total;
	float totalWithDiscount;
	float discount;
};