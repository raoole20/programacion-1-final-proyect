#include <iostream>
#include <vector>
#include <cstdlib>
#include "Customer.cpp"
#include "Product.cpp"
#include "Sales.cpp"
#include "ProductQuantity.cpp"
#include "Supplier.cpp"
#include "OrderModule.cpp"
using namespace std;
 // Constructor de la clase App
class App
{
public:
	App() {
		Customers customerInstace("", "", "", "");
		this->customerService = customerInstace;

		Product productInstance("", "", "", 0, 0, false, 0);
		this->productService = productInstance;
	};
	void init() {
		this->printTitle("GESTOR DE VENTAS");
		this->printIntegrators();
	};

	void killApp() {
		run = false;
	}

	int showMenu() {
		this->clear();
		this->printTitle("MENU PRINCIPAL");
		cout << "Seleccione una opcion:" << endl << endl;
		cout << "1. Modulo de Clientes" << endl;
		cout << "2. Modulo de Producto" << endl;
		cout << "3. Modulo de Ventas" << endl;
		cout << "4. Modulo de Proveedores" << endl;
		cout << "9. Mostrar Integrantes" << endl;
		cout << "10. Salir" << endl;

		int tempOption;
		cin >> tempOption;

		return tempOption;
	}

	void printSeparator(int type = 0) {
		switch (type) {
		case 1:
			cout << "---------------";
			break;
		default:
			cout << "=========================================" << endl;
		}
	}

	void printTitle(string message) {
		this->printSeparator();
		cout << "\t   " << message << endl;
		this->printSeparator();
	}

	void printIntegrators() {
		cout << endl;
		this->printSeparator(1);
		cout << "Integrantes";
		this->printSeparator(1);
		cout << endl << endl << endl;
		cout << "* Raul Espina: 30.643.473" << endl;
		cout << "* Arelenys Davila: 15.764.502" << endl;
		cout << "Para continuar, presiona cualquier tecla y luego Enter..." << endl;
		string temp;
		cin >> temp;
	}

	void clear() {
		std::cout << "\x1B[2J\x1B[H";
	}

	void customerMenu() {
		auto continueProcess = true;
		while (continueProcess) {
			this->clear();
			this->printTitle("MENU DE CLIENTES");
			cout << "Seleccione una opcion:" << endl << endl;
			cout << "1. Registrar Cliente" << endl;
			cout << "2. Listar Clientes" << endl;
			cout << "3. Modificar Cliente" << endl;
			cout << "4. Eliminar Cliente" << endl;
			cout << "5. Buscar Cliente por ID" << endl;
			cout << "6. Volver al menu principal" << endl;

			int option;
			cin >> option;
			switch (option)
			{
				case 1: {
					this->clear();
					this->printTitle("REGISTRO DE CLIENTES");
					cout << "Por favor ingrese los datos del cliente";
					cout << endl << endl << endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					auto customer = customerService.createNewCustomer(customerList);
					cout << endl << endl << endl;

					this->printTitle("Cliente");
					cout << endl;
					cout << "detalles del usuario:";
					cout << endl << endl << endl;
					customer.displayUserInformation();
					cout << endl << endl << endl;

					cout << "Desea guardar al Cliente" << endl;
					cout << "1. Si" << endl;
					cout << "2. No" << endl;
					string temp;
					cin >> temp;

					if (temp == "1") {
						this->customerList.push_back(customer);
						cout << "Cliente guardado con exito" << endl;
					}
					else {
						cout << "Cliente no guardado" << endl;
					}

					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					cin >> temp;
				}
				  break;
				case 2: {
					this->clear();
					this->printTitle("Lista Cliente");
					cout << "Lista de clientes registrados" << endl;

					if (customerList.size() == 0) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "No hay clientes registrados" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					else {
						for (auto c : this->customerList) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
					}


					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					string temp; 
					cin >> temp;
				}
					  break;
				case 3: {
					this->clear();
					this->printTitle("Modificar Cliente");
					cout << "Ingrese el ID del cliente a modificar" << endl;
					string id;
					cin >> id;

					auto customerFound = false;
					for (auto &c : this->customerList) {
						if (c.getId() == id) {
							customerFound = true;
							this->printTitle("Cliente");
							cout << endl;
							cout << "detalles del usuario:";
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;

							cout << "Desea modificar al Cliente" << endl;
							cout << "Cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
							cout << "1. Si" << endl;
							cout << "2. No" << endl;
							string temp;
							cin >> temp;

							if (temp == "1" || temp == "si") {	
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								c.modifiCustomer();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
								cout << "Cliente modificado con exito: " << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl;

								c.displayUserInformation();
							}
							else {
								cout << "Cliente no modificado" << endl;
							}
						}
					}

					if (!customerFound) {
						cout << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
						cout << "Cliente no encontrado" << endl;
						cout << endl;
						this->printSeparator(1);
						this->printSeparator(1);
					}

					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
				}
					  break;
				case 4: {
					this->clear();
					this->printTitle("Eliminar Cliente");
					cout << "Ingrese el ID del cliente a buscar: " << endl;
					string id;
					cin >> id;

					auto find = false;
					auto index = 0;
					auto countIteration = 0;
					for (auto c : this->customerList) {
						if (id == c.getId()) {
							cout << "Detalles del cliente: " << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							find = true;
							index= countIteration;
						}
						countIteration++;
					}

					if (!find) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "Cliente no encontrado" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					else {
						cout << "Desea eliminar al Cliente? " << endl;
						cout << "En caso de no elegir una opción válida, el usuario será eliminado." << endl << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						int deleteOption;
						cin >> deleteOption;

						switch (deleteOption)
						{
							case 2:
								cout << "el usuario no ha sido eliminado" << endl;
								break;
							case 1:	
							default:
								this->customerList.erase(std::next(customerList.begin(), index));
								cout << "el usuario ha sido eliminado" << endl;
								this->printSeparator(1);
								cout << endl;
								break;
						}

					}
					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;

				}
					break;
				case 5: {
					this->clear();
					this->printTitle("Buscar Cliente");
					cout << "Ingrese el ID del cliente a buscar: " << endl;
					string id;
					cin >> id;

					auto find = false;
					for (auto c : this->customerList) {
						if (id == c.getId()) {	
							cout << "Detalles del cliente: " << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							find = true;
						}	
					}

					if (!find) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "Cliente no encontrado" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
						
				}
					  break;
				case 6:
					continueProcess = false;
					break;
				default:
					this->clear();
					cout << "Opcion no valida, Intente nuevamente" << endl;
					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
					break;
			}
		}
	}

	void productMenu() {
		auto continueProcess = true;

		do {
			this->clear();
			this->printTitle("MENU DE PRODUCTOS");
			cout << "Seleccione una opcion:" << endl << endl;
			cout << "1. Registrar Producto" << endl;
			cout << "2. Listar Productos" << endl;
			cout << "3. Modificar Producto" << endl;
			cout << "4. Eliminar Producto" << endl;
			cout << "5. Buscar Producto por ID" << endl;
			cout << "6. Volver al menu principal" << endl;

			int option;
			cin >> option;
			switch (option)
			{
				case 1: {
						this->clear();
						this->printTitle("REGISTRO De Productos");
						cout << "Por favor ingrese los datos del producto";
						cout << endl << endl << endl;
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						auto producto = this->productService.createNewProduct();
						cout << endl << endl << endl;

						this->printTitle("Producto");
						cout << endl;
						cout << "detalles del producto:";
						cout << endl << endl << endl;
						producto.displayProductInformation();
						cout << endl << endl << endl;

						cout << "Desea guardar el Producto" << endl;
						cout << "Cualquier otra opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						string temp;
						cin >> temp;

						if (temp == "1" || temp == "si") {
							this->productList.push_back(producto);
							cout << "Producto guardado con exito" << endl;
						}
						else {
							cout << "Producto no guardado" << endl;
						}

						cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
						cin >> temp;
					}
					break;
				case 2: {
						this->clear();
						this->printTitle("Lista de Productos");
						cout << "Lista de productos registrados" << endl;
						

						if (this->productList.size() == 0) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							cout << "No hay productos registrados" << endl;
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
						else {
							for (auto p : this->productList) {
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl << endl;
								p.displayProductInformation();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
							}
						}	

						cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
						string temp;
						cin >> temp;
					}
					break;
				case 3:
					{
						this->clear();
						this->printTitle("Modificar Producto");
						cout << "Ingrese el ID del producto a modificar" << endl;
						string id;
						cin >> id;

						auto productFound = false;
						for (auto &p : this->productList) {
							if (p.getId() == id) {
								productFound = true;
								this->printTitle("Producto");
								cout << endl;
								cout << "detalles del producto:";
								cout << endl << endl << endl;
								p.displayProductInformation();
								cout << endl << endl << endl;

								cout << "Desea modificar al Producto" << endl;
								cout << "Cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
								cout << "1. Si" << endl;
								cout << "2. No" << endl;
								string temp;
								cin >> temp;

								if (temp == "1" || temp == "si") {
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									p.modifiProduct();
									cout << endl << endl << endl;
									this->printSeparator(1);
									this->printSeparator(1);
									cout << endl;
									cout << "Producto modificado con exito: " << endl;
									this->printSeparator(1);
									this->printSeparator(1);
									cout << endl << endl;

									p.displayProductInformation();
								}
								else {
									cout << "Producto no modificado" << endl;
								}
							}
						}

						if (!productFound) {
							cout << "Producto no encontrado" << endl;
						}

						cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
						string temp;
						cin >> temp;
					}
					break;
				case 4:
					{
						this->clear();
						this->printTitle("Eliminar Producto");
						cout << "Ingrese el ID del producto a buscar: " << endl;
						string id;
						cin >> id;

						auto find = false;
						auto index = 0;
						auto countIteration = 0;
						for (auto p : this->productList) {
							if (id == p.getId()) {
								cout << "Detalles del producto: " << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl << endl;
								p.displayProductInformation();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
								find = true;
								index = countIteration;
							}
							countIteration++;
						}

						if (!find) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							cout << "Producto no encontrado" << endl;
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
						else {
							cout << "Desea eliminar al Producto? " << endl;
							cout << "Cualquier opcion diferente a 1 sera considerado como un no" << endl;
							cout << "En caso de no elegir una opción válida, el producto será eliminado." << endl << endl;
							cout << "1. Si" << endl;
							cout << "2. No" << endl;
							int deleteOption;
							cin >> deleteOption;

							switch (deleteOption)
							{
							case 2:
								cout << "el producto no ha sido eliminado" << endl;
								break;
							case 1:
							default:
								this->productList.erase(std::next(productList.begin(), index));
								cout << "el producto ha sido eliminado" << endl;
								this->printSeparator(1);
								break;
							}
						}
						cout << endl << "Para continuar, presione cualquier tecla y luego Enter" << endl;
						string temp;
						cin >> temp;		
					}
					break;
				case 5:
					{
						this->clear();
						this->printTitle("Buscar Producto");
						cout << "Ingrese el ID del producto a buscar: " << endl;
						string id;
						cin >> id;

						auto find = false;
						for (auto p : this->productList) {
							if (id == p.getId()) {
								cout << "Detalles del producto: " << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl << endl;
								p.displayProductInformation();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
								find = true;
							}
						}

						if (!find) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							cout << "Producto no encontrado" << endl;
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
						cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
						string temp;
						cin >> temp;	
					}
					break;
				case 6:
					continueProcess = false;
					break;
				default:
					this->clear();
					cout << "Opcion no valida, Intente nuevamente" << endl;
					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
					break;
			}
		} while (continueProcess);
	}

	void salesMenu() {
		auto continueProcess = true;
		while (continueProcess) {
			this->clear();
			this->printTitle("MENU DE VENTAS");
			cout << "Seleccione una opcion:" << endl << endl;
			cout << "1. Facturación" << endl;
			cout << "2. Listar Facturas" << endl;
			cout << "3. Pedidos" << endl;
			cout << "4. Listar Pedidos" << endl;
			cout << "5. Volver al menu principal" << endl;

			int option;
			cin >> option;
			switch (option)
			{
				case 1:
				{
					this->clear();
					this->printTitle("Módulo Factura");

					if(this->productList.size() == 0) {
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "NO HAY PRODUCTOS EN STOCK" << endl;
						cout << "Debe registrar productos antes de crear una factura" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						this->pause();

						break;
					}

					cout << "Por favor ingrese los datos de la Factura";
					cout << endl << endl << endl;
					this->printSeparator(1);
					this->printSeparator(1);
					cout << endl;
					cout << "Introduzca el ID del cliente o el correo del mismo: ";
					string customerId;
					cin >> customerId;

					auto customerFound = false;
					Customers customer;
					for (auto c : this->customerList) {
						if (c.getId() == customerId || c.getEmail() == customerId) {
							customerFound = true;
							customer = c;
						}
					}

					if (!customerFound) {
				        cout << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl;
						cout << "Cliente no encontrado" << endl;
						cout << "Desea registrar al cliente? " << endl;
						cout << "cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						cout << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;

						string temp;
						cin >> temp;
						if (temp == "1" || temp == "si") {
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							customer = this->customerService.createNewCustomer(customerList);
							cout << "Cliente registrado con exito" << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							customer.displayUserInformation();
							cout << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							this->customerList.push_back(customer);
							cout << "Cliente guardado con exito" << endl;
						}
						else {
							cout << "Factura no creada" << endl;
							this->pause();
							break;
						}
					}

					vector<ProductQuantity> products;
					bool continueithProducts = true;
					do {
						cout << endl << endl << endl;
						cout << "Introduzca el ID del producto que desea agregar a la venta: ";
						Product* currentProduct = nullptr; 
						string productId;
						int	quantity;
						cin >> productId;
						auto productFound = false;
						for (auto &p : this->productList) {
							if (p.getId() == productId) {
								productFound = true;
								currentProduct = &p;
							}
						}

						if (!productFound) {
							cout << endl << endl; 
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							cout << endl;
							cout << "PRODUCTO NO ENCONTRADO" << endl;
							cout << "En producto no existe en el registro, debe crearlo desde el modulo de \"Productos\"" << endl;
							cout << endl;
							this->printSeparator(1);
							this->printSeparator(1);
						}
						else {
							auto continueWithSubProcess = true;
							do {
								cout << "Ingresa la cantidad del producto: " << endl;
								cin >> quantity;

								if (quantity > currentProduct->getStock() || quantity < 0){
									cout << endl;
									this->printSeparator(1);
									this->printSeparator(1);	
									cout << endl;
									cout << "La cantidad ingresada supera el stock del producto o se ingreso un valor negativo" << endl;
									cout << "Stock actual: " << currentProduct->getStock() << endl;
									cout << "Desea ingresar una cantidad menor? " << endl;
									cout << "cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
									cout << "1. Si" << endl;
									cout << "2. No" << endl;
									this->printSeparator(1);
									this->printSeparator(1);
									cout << endl;

									string temp;
									cin >> temp;
									if (temp != "1" && temp != "si") {
										continueWithSubProcess = false;
									}
								}
								else {
									cout << endl << endl;
									this->printSeparator(1);
									this->printSeparator(1);
									cout << endl << endl;
									cout << "Producto agregado a la venta" << endl << endl;
									this->printSeparator(1);
									this->printSeparator(1);

									currentProduct->setStock(currentProduct->getStock() - quantity);
									products.push_back({ quantity, *currentProduct });
									continueWithSubProcess = false;
								}
							} while (continueWithSubProcess);
						}

						cout << endl << endl << endl;
						cout << "Desea agregar otro producto a la venta? " << endl;
						cout << "cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						cout << "3. Ver productos disponibles en stock" << endl;
						string temp;
						cin >> temp;

						if ((temp != "1" && temp != "si") && temp != "3") {
							continueProcess = false;
						}		

						if(temp == "3") {
							cout << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							cout << "Productos disponibles en stock" << endl;
							cout << endl;

							if(this->productList.size() == 0) {
								cout << endl << endl;
								cout << "No hay productos en stock" << endl << endl;
								continueProcess = false;
							} 

							for (auto p : this->productList) {
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl << endl;
								p.displayProductInformation();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
							}
						}
					} while (continueProcess);
					if (products.size() == 0) {
						cout << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl;
						cout << "No se han ingresado suficientes productos para crear una factura." << endl;
						cout << "Factura no creada" << endl << endl;
						this->pause();
						this->printSeparator(1);
						this->printSeparator(1);
						break;
					}

					Sales sale(customer, products);
					this->clear();
					this->printTitle("");
					cout << endl <<endl << endl;
					this->printSeparator(1);
					this->printSeparator(1);
					cout << endl;
					sale.displaySalesInformation();
					cout << endl << endl << endl;

					this->salesList.push_back(sale);
					this->pause();
				}
					break;
				case 2:
					this->clear();
					this->printTitle("Lista de Facturas");
					cout << "Lista de facturas registradas" << endl;
						if (this->salesList.size() == 0) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							cout << "No hay ventas registradas" << endl;
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
						else {
							for (auto p : this->salesList) {
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl << endl;
								p.displaySalesInformation();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
							}
						}

						this->pause();
					break;
				case 3:
				{
					this->clear();
					this->printTitle("Módulo Pedido");
					cout << "Por favor ingrese los datos del Pedido";
					cout << endl << endl << endl;
					this->printSeparator(1);
					this->printSeparator(1);
					cout << endl;
					cout << "Introduzca el ID del Proveedor o el correo del mismo: ";
					string SupplierId;
					cin >> SupplierId;

					auto SupplierFound = false;
					Suppliers Supplier;
					for (auto c : this->SupplierList) {
						if (c.getId() == SupplierId || c.getEmail() == SupplierId) {
							SupplierFound = true;
							Supplier = c;
						}
					}

					if (!SupplierFound) {
						cout << "Proveedor no encontrado" << endl;
						cout << "Desea registrar al Proveedor? " << endl;
						cout << "cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						string temp;
						cin >> temp;

						if (temp == "1" || temp == "si") {
							Supplier = this->SupplierService.createNewSupplier(SupplierList);
							cout << "Proveedor registrado con exito" << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							Supplier.displayUserInformation();
							cout << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							this->SupplierList.push_back(Supplier);
							cout << "Proveedor guardado con exito" << endl;
						}
						else {
							cout << "Pedido no creado" << endl;
							this->pause();
							break;
						}
					}

					vector<ProductQuantity> products;
					bool continueithProducts = true;
					do {
						cout << "Introduzca el ID del producto que desea registrar: ";
						Product currentProduct; 
						string productId;
						int	quantity;
						cin >> productId;
						auto productFound = false;
						for (auto p : this->productList) {
							if (p.getId() == productId) {
								productFound = true;
								currentProduct = p;
							}
						}

						if (!productFound) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							cout << endl;
							cout << "Producto no encontrado" << endl;
							cout << endl;
							this->printSeparator(1);
							this->printSeparator(1);
						}
						else {
							auto continueWithSubProcess = true;
							do {
								cout << "Ingresa la cantidad del producto: " << endl;
								cin >> quantity;

								if (quantity > currentProduct.getStock()) {
									cout << endl;
									this->printSeparator(1);
									this->printSeparator(1);	
									cout << endl;
									cout << "La cantidad ingresada supera el stock del producto" << endl;
									cout << "Stock actual: " << currentProduct.getStock() << endl;
									cout << "Desea ingresar una cantidad menor? " << endl;
									cout << "cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
									cout << "1. Si" << endl;
									cout << "2. No" << endl;
									this->printSeparator(1);
									this->printSeparator(1);
									cout << endl;

									string temp;
									cin >> temp;
									if (temp != "1" && temp != "si") {
										continueWithSubProcess = false;
									}
								}
								else {
									cout << "Producto agregado..." << endl;
									currentProduct.setStock(currentProduct.getStock() - quantity);
									products.push_back({ quantity, currentProduct });
									continueWithSubProcess = false;
								}
							} while (continueWithSubProcess);
						}

						cout << endl << endl << endl;
						cout << "Desea registrar otro producto? " << endl;
						cout << "cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						string temp;
						cin >> temp;

						if (temp != "1" && temp != "si") {
							continueProcess = false;
						}
					} while (continueProcess);

					if (products.size() == 0) {
						cout << "No se han ingresado suficientes productos para realizar un pedido." << endl;
						cout << "Pedido no creado" << endl;
						this->pause();
						break;
					}

					
				}
					break;
				case 4:
					break;
				case 5:
					continueProcess = false;
					break;
				default:
					this->clear();
					cout << "Opcion no valida, Intente nuevamente" << endl;
					this->pause();
					break;
			}
		}
	}

void SupplierMenu() {
		auto continueProcess = true;
		while (continueProcess) {
			this->clear();
			this->printTitle("MENU DE PROVEEDORES");
			cout << "Seleccione una opcion:" << endl << endl;
			cout << "1. Registrar Proveedor" << endl;
			cout << "2. Listar Proveedor" << endl;
			cout << "3. Modificar Proveedor" << endl;
			cout << "4. Eliminar Proveedor" << endl;
			cout << "5. Buscar Proveedor por ID" << endl;
			cout << "6. Volver al menu principal" << endl;

			int option;
			cin >> option;
			switch (option)
			{
				case 1: {
					this->clear();
					this->printTitle("REGISTRO DE PROVEEDORES");
					cout << "Por favor ingrese los datos del Proveedor";
					cout << endl << endl << endl;
					auto Supplier = SupplierService.createNewSupplier(SupplierList);
					cout << endl << endl << endl;

					this->printTitle("Proveedores");
					cout << endl;
					cout << "Detalles del proveedor:";
					cout << endl << endl << endl;
					Supplier.displayUserInformation();
					cout << endl << endl << endl;

					cout << "Desea guardar al Proveedor" << endl;
					cout << "1. Si" << endl;
					cout << "2. No" << endl;
					string temp;
					cin >> temp;

					if (temp == "1") {
						this->SupplierList.push_back(Supplier);
						cout << "Proveedor guardado con exito" << endl;
					}
					else {
						cout << "Proveedor no guardado" << endl;
					}

					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					cin >> temp;
				}
				  break;
				case 2: {
					this->clear();
					this->printTitle("Lista Proveedor");
					cout << "Lista de proveedores registrados" << endl;

					if (SupplierList.size() == 0) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "No hay proveedores registrados" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					else {
						for (auto c : this->SupplierList) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
					}


					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					string temp; 
					cin >> temp;
				}
					  break;
				case 3: {
					this->clear();
					this->printTitle("Modificar Proveedor");
					cout << "Ingrese el ID del proveedor a modificar" << endl;
					string id;
					cin >> id;

					auto SupplierFound = false;
					for (auto &c : this->SupplierList) {
						if (c.getId() == id) {
							SupplierFound = true;
							this->printTitle("Proveedores");
							cout << endl;
							cout << "detalles del proveedor:";
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;

							cout << "Desea modificar al Proveedor" << endl;
							cout << "Cualquier opcion diferente a 1 o \"si\" sera considerado como un no" << endl;
							cout << "1. Si" << endl;
							cout << "2. No" << endl;
							string temp;
							cin >> temp;

							if (temp == "1" || temp == "si") {	
								c.modifiSupplier();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
								cout << "Proveedor modificado con exito: " << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl;

								c.displayUserInformation();
							}
							else {
								cout << "Proveedor no modificado" << endl;
							}
						}
					}

					if (!SupplierFound) {
						cout << "Proveedor no encontrado" << endl;
					}

					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
				}
					  break;
				case 4: {
					this->clear();
					this->printTitle("Eliminar Proveedor");
					cout << "Ingrese el ID del Proveedor a buscar: " << endl;
					string id;
					cin >> id;

					auto find = false;
					auto index = 0;
					auto countIteration = 0;
					for (auto c : this->SupplierList) {
						if (id == c.getId()) {
							cout << "Detalles del Proveedor: " << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							find = true;
							index= countIteration;
						}
						countIteration++;
					}

					if (!find) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "Proveedor no encontrado" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					else {
						cout << "Desea eliminar al Proveedor? " << endl;
						cout << "En caso de no elegir una opción válida, el usuario será eliminado." << endl << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						int deleteOption;
						cin >> deleteOption;

						switch (deleteOption)
						{
							case 2:
								cout << "el usuario no ha sido eliminado" << endl;
								break;
							case 1:	
							default:
								this->SupplierList.erase(std::next(SupplierList.begin(), index));
								cout << "el usuario ha sido eliminado" << endl;
								this->printSeparator(1);
								cout << endl;
								break;
						}

					}
					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;

				}
					break;
				case 5: {
					this->clear();
					this->printTitle("Buscar Proveedor");
					cout << "Ingrese el ID del Proveedor a buscar: " << endl;
					string id;
					cin >> id;

					auto find = false;
					for (auto c : this->SupplierList) {
						if (id == c.getId()) {	
							cout << "Detalles del Proveedor: " << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							find = true;
						}	
					}

					if (!find) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "Proveedor no encontrado" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
						
				}
					  break;
				case 6:
					continueProcess = false;
					break;
				default:
					this->clear();
					cout << "Opcion no valida, Intente nuevamente" << endl;
					cout << "Para continuar, presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
					break;
			}
		}
	}
	void pause() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Presione ENTER para continuar...";
		std::cin.get();
	}
	bool getRun() {
		return this->run;
	}
private:
	bool run = true;
	vector<Customers> customerList;
	vector<Product> productList;
	vector<Sales> salesList;
	Customers customerService;
	Product productService;
	Suppliers SupplierService;
	vector<Suppliers> SupplierList;
	vector<OrderModules> OrderModuleList;
};
