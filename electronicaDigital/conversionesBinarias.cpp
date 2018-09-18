#include <iostream>
#include <cmath>

using namespace std;

void decimalToBinary(){
	cout << "1" << endl;
	double decimal;
	cout << "Introduce tu numero decimal: ";
	cin >> decimal;
	cout << "Introdujiste: " << decimal << endl;
	int binario[100];

	int potencia = 0;
	int i= 0;
	while(pow(2, potencia) < decimal){
		// buscando el numero proximo al decimal, pero en binario
		i = pow(2,potencia);
		potencia++;
	}
	// poniendo 1 en el valor de 2^potencia
	for(int i = 0;i<potencia;i++) binario[i] = (i == (potencia-1)) ? 1 : 0;
	// iterar para ponerle valor a los demas
	int semilla = decimal - i;
	for (int i = (potencia-2); i >= 0;i--){
		binario[i] = (pow(2,i) <= semilla) ? 1 : 0;
		semilla = (binario[i] == 1) ? semilla-pow(2,i) : semilla;
	}
	cout << "-------" << "\n" << "El numero binario es: " << endl;
	for(int i = (potencia-1);i >= 0;i--) cout << binario[i] << " "; cout << endl;
}

void binaryToDecimal(){
	cout << "2" << endl;
	int longitud;
	cout << "Longitud de tu numero binario: " << endl;
	cin >> longitud;
	int binario[longitud];
	cout << "Tu binario sera tomado dato por dato de derecha a izquierda" << endl;
	for(int i = 0;i < longitud;i++) cout << "Inserte[" << i << "]: ",cin >> binario[i];
	for(int &bin : binario) cout << bin << " "; cout << endl;
}

void hexaToBinary(){
	cout << "3" << endl;
}

void binaryToHexa(){
	cout << "4" << endl;
}

int main(){
	// conversiones decimales, binarias, hexadecimales, octales
	cout << "*****CONVERTIDOR DECIMAL, BINARIO, HEXADECIMAL, OCTAL********" << endl;
	int opcion;
	cout << "Ingrese la conversion que desea realizar: " << endl;
	cout << "1. Decimal a binario" << endl;
	cout << "2. Binario a decimal" << endl;
	cout << "3. Hexadecimal a binario" << endl;
	cout << "4. Binario a Hexadecimal" << endl;
	cin >> opcion;
	cout << "Elegiste la opcion: " << opcion << endl;
	switch(opcion){
		case 1:
			cout << "CONVERSION DECIMAL A BINARIO" << endl;
			decimalToBinary();
			break;
		case 2:
			cout << "CONVERSION BINARIO A DECIMAL" << endl;
			binaryToDecimal();
			break;
		case 3:
			cout << "CONVERSION HEXADECIMAL A BINARIO" << endl;
			binaryToHexa();
			break;
		case 4:
			cout << "CONVERSION BINARIO A HEXADECIMAL" << endl;
			hexaToBinary();
			break;
	}
	return 0;
}
