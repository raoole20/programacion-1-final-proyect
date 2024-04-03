#ifndef SUPPLIERS_h
#define SUPPLIERS_h

#include <iostream>
#include <random>
#include <sstream>
#include "UUID.cpp" // Incluir la clase UUID
using namespace std;

class Suppliers
{
public:
    // Constructor con valores predeterminados para name, lastName, email y phone
	Suppliers(string name = "", string lastName = "", string email = "", string phone = "") {
		this->name = name;
		this->lastName = lastName;
		this->email = email;
		this->phone = phone;
	}
    // Mostrar la informaci�n del Proveedor
	void displayUserInformation() {
		cout << "ID del Proveedor: " << this->id << endl;
		cout << "Nombre del Proveedor: " << this->name << endl;
		cout << "Apellido del Proveedor: " << this->lastName << endl;
		cout << "Email del Proveedor: " << this->email << endl;
		cout << "Telefono del Proveedor: " << this->phone << endl;
	};

    // Crear un nuevo Proveedor
	Suppliers createNewSupplier (vector<Suppliers> suppliers) { 
	    Identify id; // Crear una instancia de la clase UUID
    	string colums[4] = { "Nombre", "Apellido", "Email", "Telefono" };
		Suppliers newSupplier("", "", "", "");
        newSupplier.setId(to_string(id._id)); // Establecer un ID �nico para el proveedor
		for (auto colum : colums) {
			cout << "Ingrese el " << colum << " del Proveedor: ";
			auto valid = false;
			do {
				if (colum != "Email" && colum != "Telefono") {
						string value;
						std::getline(std::cin, value);
					if (value.length() < 3) {
						cout << "El " << colum << " ingresado no es valido, intente nuevamente" << endl;
						continue;
					}

					if (colum == "Nombre") {
						newSupplier.setName(value);
					}
					else {
						newSupplier.setLastName(value);
					}

					valid = true;
				}
				else {
						string value;
						std::getline(std::cin, value);
					if (colum == "Email") {
						if (value.find("@") == string::npos) {
							cout << "El email ingresado no es valido, intente nuevamente" << endl;
							continue;
						}

						if (existSupplier(value, suppliers)) {
							cout << "El email ingresado ya existe, intente nuevamente" << endl;
							continue;
						}
						newSupplier.setEmail(value);
						valid = true;
					}
					else {
						if (value.length() < 8) {
							cout << "El telefono ingresado no es valido, intente nuevamente" << endl;
							continue;
						}
						newSupplier.setPhone(value);
						valid = true;
					}
				}
			} while (!valid);
		}
		return newSupplier;
	}
   // Modificar un cliente
	void modifiSupplier() {
		string colums[4] = { "Nombre", "Apellido", "Email", "Telefono" };
		for (auto colum : colums) {
			cout << "Ingrese el nuevo " << colum << " del Proveedor: ";
			auto valid = false;
			do {
				if (colum != "Email" && colum != "Telefono") {
					string value;
					std::getline(std::cin, value);
					if (value.length() < 3) {
						cout << "El " << colum << " ingresado no es valido, intente nuevamente" << endl;
						continue;
					}

					if (colum == "Nombre") {
						this->setName(value);
					}
					else {
						this->setLastName(value);
					}

					valid = true;
				}
				else {
						string value;
						std::getline(std::cin, value);
					if (colum == "Email") {
						if (value.find("@") == string::npos) {
							cout << "El email ingresado no es valido, intente nuevamente" << endl;
							continue;
						}
						this->setEmail(value);
						valid = true;
					}
					else {
						if (value.length() < 8) {
							cout << "El telefono ingresado no es valido, intente nuevamente" << endl;
							continue;
						}
						this->setPhone(value);
						valid = true;
					}
				}
			} while (!valid);
		}
	}	
   // Comprobar si ya existe un cliente con el email dado
	bool existSupplier(string email, vector<Suppliers> Suppliers) {
		for (auto c : Suppliers) {
			if (c.getEmail() == email) {
				return true;
			}
		}
		return false;
	}

	string getId() { return this->id; };	
	string getLastName() { return this->lastName; };
	string getEmail() { return this->email; };
	string getPhone() { return this->phone; };
	string getName() { return this->name; };
	void setName(string name) { this->name = name; }
	void setLastName(string lastName) { this->lastName = lastName; }
	void setEmail(string email) { this->email = email; }
	void setPhone(string phone) { this->phone = phone; }
	void setId(string id) { this->id = id; }
private:
	string id;
	string name;
	string lastName;
	string email;
	string phone;
};

#endif // !SUPPLIERS_h