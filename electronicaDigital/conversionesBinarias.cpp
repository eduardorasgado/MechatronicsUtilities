
#include <iostream>
#include <cmath>
#include <cstring>

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
	for(int i = (longitud-1);i >=0;i--) cout << "Inserte[" << i << "]: ",cin >> binario[i];
	for(int i = (longitud-1);i >= 0 ;i--) cout << binario[i] << " "; cout << endl;

	//algoritmo
	int decimal = 0;
	for(int i=0;i < longitud;i++) decimal += (binario[i]==1) ? pow(2,i) : 0;
	cout << "El numero decimal es: " << decimal << endl;
}

void hexaToBinary(){
	cout << "3" << endl;
	 // char HEXA[] = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'];
}

void binaryToHexa(){
	cout << "4" << endl;
}

int main(){
	char HEXA[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'};
	int BINARY[][] = {{0,0,0,0}, {0,0,0,1}, {0,0,1,0},{0,0,1,1}, {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0},
				{1,0,0,1},{1,0,1,0}, {1,0,1,1}, {1,1,0,0}, {1,1,0,1}, {1,1,1,0}, {1,1,1,1}};
	int OCTAL[] = {0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, 16, 17};

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
	cout << '\n';
	switch(opcion){
		case 1:
			cout << "********CONVERSION DECIMAL A BINARIO********" << endl;
			decimalToBinary();
			break;
		case 2:
			cout << "********CONVERSION BINARIO A DECIMAL********" << endl;
			binaryToDecimal();
			break;
		case 3:
			cout << "********CONVERSION HEXADECIMAL A BINARIO********" << endl;
			binaryToHexa();
			break;
		case 4:
			cout << "********CONVERSION BINARIO A HEXADECIMAL********" << endl;
			hexaToBinary();
			break;
	}
	return 0;
}
