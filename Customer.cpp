#ifndef CUSTOMERS_h
#define CUSTOMERS_h

#include <iostream>
#include <random>
#include <sstream>
#include "UUID.cpp" // Incluir la clase UUID
using namespace std;

class Customers
{
public:
    // Constructor con valores predeterminados para name, lastName, email y phone
	Customers(string name = "", string lastName = "", string email = "", string phone = "") {
		this->name = name;
		this->lastName = lastName;
		this->email = email;
		this->phone = phone;
	}
    // Mostrar la informaci�n del usuario
	void displayUserInformation() {
		cout << "ID del usuario: " << this->id << endl;
		cout << "Nombre del usuario: " << this->name << endl;
		cout << "Apellido del usuario: " << this->lastName << endl;
		cout << "Email del usuario: " << this->email << endl;
		cout << "Telefono del usuario: " << this->phone << endl;
	};

    // Crear un nuevo cliente
	Customers createNewCustomer (vector<Customers> customers) { 
	    Identify id; // Crear una instancia de la clase UUID
    	string colums[4] = { "Nombre", "Apellido", "Email", "Telefono" };
		Customers newCustomer("", "", "", "");
        newCustomer.setId(to_string(id._id)); // Establecer un ID �nico para el nuevo cliente
		for (auto colum : colums) {
			cout << "Ingrese el " << colum << " del cliente: ";
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
						newCustomer.setName(value);
					}
					else {
						newCustomer.setLastName(value);
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

						if (existCustomer(value, customers)) {
							cout << "El email ingresado ya existe, intente nuevamente" << endl;
							continue;
						}
						newCustomer.setEmail(value);
						valid = true;
					}
					else {
						if (value.length() < 8) {
							cout << "El telefono ingresado no es valido, intente nuevamente" << endl;
							continue;
						}
						newCustomer.setPhone(value);
						valid = true;
					}
				}
			} while (!valid);
		}
		return newCustomer;
	}
   // Modificar un cliente
	void modifiCustomer() {
		string colums[4] = { "Nombre", "Apellido", "Email", "Telefono" };
		for (auto colum : colums) {
			cout << "Ingrese el nuevo " << colum << " del cliente: ";
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
	bool existCustomer(string email, vector<Customers> customers) {
		for (auto c : customers) {
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

#endif // !CUSTOMERS_h