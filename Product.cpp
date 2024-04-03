#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "UUID.cpp"  // Incluye la implementación de UUID (suponiendo que existe)
using namespace std;

class Product
{
public:	
    // Constructor con valores predeterminados para las variables miembro
	Product(string id = "", string name = "", string description = "", float price = 0, int stock = 0, bool isOffer = false, float offerPrice = 0) {
		this->id = id;
		this->name = name;
		this->description = description;
		this->price = price;
		this->stock = stock;
		this->isOffer = isOffer;
		this->offerPrice = offerPrice;
	}

    // Muestra información del producto
    void displayProductInformation()
    {
        cout << "ID del producto: " << this->id << endl;
        cout << "Nombre del producto: " << this->name << endl;
        cout << "Descripción del producto: " << this->description << endl;
        cout << "Precio del producto: " << this->price << endl;
        cout << "Stock del producto: " << this->stock << endl;
    };

    // Crea un nuevo producto
	Product createNewProduct() {
		string colums[5] = { "Nombre", "Descripcion", "Precio", "Stock", "Oferta" };
		Product newProduct("", "", "", 0, 0, false, 0);
		Identify id;
		newProduct.setId(to_string(id._id));
		for (auto colum : colums) {
			auto valid = false;

			do {
				if (colum != "Oferta") {
					cout << "Ingrese el " << colum << " del producto: ";
					cout << "\n";
					string value;
					std::getline(std::cin, value);
					if (colum == "Nombre") {
						newProduct.setName(value);
						valid = true;
					}
					else if (colum == "Descripcion") {
						newProduct.setDescription(value);
						valid = true;
					}
					else if (colum == "Precio") {
						    try {
								auto price = stof(value);
								newProduct.setPrice(price);
								valid = true;
							} catch (std::invalid_argument&) {
								cout << "Por favor, ingrese un número válido para el precio." << endl;
							}
					}
					else {
						try {
							newProduct.setStock(stoi(value));
							valid = true;
						}
						catch(const std::exception& e) {
							cout << "Por favor, ingrese un número válido para el Stok." << endl;
						}
					}
				}
				else {
				
					valid = true;
				}
			} while (!valid);
		}
		return newProduct;
	}
// Muestra los detalles del producto.
	void displayProductDetails() {
		cout << "ID del producto: " << this->id << endl;
		cout << "Nombre del producto: " << this->name << endl;
		cout << "Descripcion del producto: " << this->description << endl;
		cout << "Precio del producto: " << this->price << endl;
		cout << "Stock del producto: " << this->stock << endl;
	}		

// Modifica los atributos del producto.
	void modifiProduct() {
		string colums[5] = { "Nombre", "Descripcion", "Precio", "Stock", "Oferta" };
		for (auto colum : colums) {
			auto valid = false;
			do {
				if (colum != "Oferta") {
					cout << "Ingrese el nuevo " << colum << " del producto: ";
					string value;
					std::getline(std::cin, value);

					if (colum == "Nombre") {
						this->setName(value);
						valid = true;
					}
					else if (colum == "Descripcion") {
						this->setDescription(value);
						valid = true;
					}
					else if (colum == "Precio") {
						    try {
								auto price = stof(value);
								this->setPrice(price);
								valid = true;
							} catch (std::invalid_argument&) {
								cout << "Por favor, ingrese un número válido para el precio." << endl;
							}
					}
					else {
						try {
							this->setStock(stoi(value));
							valid = true;
						}
						catch(const std::exception& e) {
							cout << "Por favor, ingrese un número válido para el Stok." << endl;
						}
					}
					valid = true;
				}
				else {
					valid = true;
				}
			} while (!valid);
		}
	
	}

// Obtiene el ID del producto.
	string getId() {
		return this->id;
	}
// Obtiene el nombre del producto.
	string getName() {
		return this->name;
	}
// Obtiene la descripción del producto.
	string getDescription() {
		return this->description;
	}
// Obtiene el precio del producto.
	float getPrice() {
		return this->price;
	}
// Obtiene el stock del producto.
	int getStock() {
		return this->stock;
	}
// Obtiene si el producto está en oferta.
	bool getIsOffer() {
		return this->isOffer;
	}
// Obtiene el precio de oferta del producto.
	float getOfferPrice() {
		return this->offerPrice;
	}
// Establece el nombre del producto.
	void setName(string name) {
		this->name = name;
	}
// Establece la descripción del producto.
	void setDescription(string description) {
		this->description = description;
	}
// Establece el precio del producto. 
	void setPrice(float price) {
		this->price = price;
	}
	void setStock(int stock) {
		this->stock = stock;
	}

	void setIsOffer(bool isOffer) {
		this->isOffer = isOffer;
	}

	void setOfferPrice(float offerPrice) {
		this->offerPrice = offerPrice;
	}

	void setId(string id) {
		this->id = id;
	}

private:
    // Atributos privados de la clase
	string id;
	string name;
	string description;
	float price;
	int stock;
	bool isOffer;
	float offerPrice;
};

#endif // PRODUCT_H