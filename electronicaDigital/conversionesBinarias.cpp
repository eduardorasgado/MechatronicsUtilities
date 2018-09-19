
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// UTILITIES
void requestBinary(int longitud, int binario[]){
        cout << "Tu binario sera tomado dato por dato de derecha a izquierda" << endl;
        for(int i = (longitud-1);i >=0;i--) cout << "Inserte[" << i << "]: ",cin >> binario[i];
        for(int i = (longitud-1);i >= 0 ;i--) cout << binario[i] << " "; cout << endl;
}

// FUNCTIONS
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
	int longitud;
	cout << "Longitud de tu numero binario: " << endl;
	cin >> longitud;
	int binario[longitud];
	//cout << "Tu binario sera tomado dato por dato de derecha a izquierda" << endl;
	//for(int i = (longitud-1);i >=0;i--) cout << "Inserte[" << i << "]: ",cin >> binario[i];
	//for(int i = (longitud-1);i >= 0 ;i--) cout << binario[i] << " "; cout << endl;
	requestBinary(longitud, binario);
	//algoritmo
	int decimal = 0;
	for(int i=0;i < longitud;i++) decimal += (binario[i]==1) ? pow(2,i) : 0;
	cout << "El numero decimal es: " << decimal << endl;
}

void hexaToBinary(char HEXA[], int BINARY[16][4]){
	//  char HEXA[] = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'];
	int lenHex;
	cout << "Ingrese la longitud de su hexadecimal: ", cin >> lenHex;
	char hexadecimal[lenHex];
	cout << "Ingrese su hexadecimal de Izquierda a Derecha" << endl;
	for(int i = 0;i < lenHex;i++) cout << "Hexadecimal[" << i <<"]: ", cin >> hexadecimal[i];
	for(char &C : hexadecimal) cout << C << " "; cout << endl;
	// Porque cade hexadecimal representa 4 binarios
	int binLength = lenHex * 4;
	int binario[binLength];
	for(int i = 0;i < lenHex;i++){
		int exactHex;
                for(int k = 0;k < 16;k++){
                	// Iterar en HEXA para encontrar el indice
                        // que se usara en BINARY para asignarle a
                        // binario
                        exactHex = (HEXA[k] == hexadecimal[i]) ? k : exactHex;
                 }
		 for(int j = 0;j < 4;j++){
			// iterando entre los miembros de BINARY[]
			// y asignando de acuerdo a el hexadecimal correspondiente
			 binario[((4*i)+j)] = BINARY[exactHex][j];
		}
	}
	// imprimiendo el binario resultante
	for(int &bin : binario) cout << bin << " "; cout << endl;
}

void binaryToHexa(char HEXA[], int BINARY[16][4]){
	int longitud;
        cout << "Longitud de tu numero binario: " << endl, cin >> longitud;
	int binario[longitud];
	requestBinary(longitud, binario);
	// for(int i = (longitud-1);i >= 0 ;i--) cout << binario[i] << " "; cout << endl;

	// algoritmo
	// si el user introduce 1 0 1 1 0 entoces el arreglo interno queda: 0 1 1 0 1
	int extra = ((longitud % 4) == 0) ? 0 : (longitud % 4);
	int lenHexa = ((longitud%4) == 0) ? (longitud / 4) : ((longitud / 4) + 1);
	char hexadecimal[lenHexa];

	// creando un nuevo arreglo binario con los ceros en caso de necesitarlo
	int newLength = (lenHexa * 4);
	int binarioCompletado[newLength];
	for(int i = 0;i < newLength;i++) binarioCompletado[i] = (i < longitud) ? binario[i] : 0;
	// El nuevo binario impreso
	cout << "El nuevo binario es: " << endl;
	for (int i = (newLength - 1);i >=0;i--) cout << binarioCompletado[i] << " "; cout << endl;

	cout << "extra: " << extra << ", Longitud del hexadecimal: " << lenHexa << endl;
	// buscamos los valores para hexadecimal
	for(int i = 0; i < lenHexa;i++){
		for(int k = 0;k < 16;k++){
			int counterAp = 0;
			for(int j = 0;j < 4;j++){
				// comparando y si counterAp junta 4 el indice k es elegido
				counterAp = ( binarioCompletado[((newLength-1) - ((i*4)+j))] == BINARY[k][j]) ? (counterAp+1) : counterAp;
			}
			hexadecimal[i] = (counterAp == 4) ? HEXA[k] : hexadecimal[i];
		}
	}
	// imprimimos los valores del hexadecimal
	cout << "El valor hexadecimal es: " << endl;
	for(char &C : hexadecimal) cout << C << " ";
	cout << endl;
}

void octalToBinary(int BINARY_OCTAL[8][3]){
	int lenOcta;
        cout << "Ingrese la longitud de su Octal: ", cin >> lenOcta;
        int octal[lenOcta];
        cout << "Ingrese su octal de Izquierda a Derecha" << endl;
        for(int i = 0;i < lenOcta;i++) cout << "Octal[" << i <<"]: ", cin >> octal[i];
        for(int &num : octal) cout << num << " "; cout << endl;
        // Porque cade octal representa 3 binarios
        int binLength = lenOcta * 3;
        int binario[binLength];
	// iterando entre los miembros de BINARY_OCTAL[]
        // y asignando de acuerdo al valor dentro de octal[i]
        // 0 1 2 3 4 5 6 7 <- valores octales son subindices
        // que representan su base binario dentro de BINARY_OCTAL
        for(int i = 0;i < lenOcta;i++) for(int j = 0;j < 3;j++) binario[((3*i)+j)] = BINARY_OCTAL[octal[i]][j];

        // imprimiendo el binario resultante
        for(int &bin : binario) cout << bin << " "; cout << endl;
}

void binaryToOctal(int BINARY_OCTAL[8][3]){
	int longitud;
        cout << "Longitud de tu numero binario: " << endl, cin >> longitud;
        int binario[longitud];
        requestBinary(longitud, binario);

        // algoritmo
        // si el user introduce 1 0 1 1 0 entoces el arreglo interno queda: 0 1 1 0 1
        int extra = ((longitud % 3) == 0) ? 0 : (longitud % 3);
        int lenOcta = ((longitud%3) == 0) ? (longitud / 3) : ((longitud / 3) + 1);
        int octal[lenOcta];

        // creando un nuevo arreglo binario con los ceros en caso de necesitarlo
        int newLength = (lenOcta * 3);
        int binarioCompletado[newLength];
        for(int i = 0;i < newLength;i++) binarioCompletado[i] = (i < longitud) ? binario[i] : 0;
        // El nuevo binario impreso
        cout << "El nuevo binario es: " << endl;
        for (int i = (newLength - 1);i >=0;i--) cout << binarioCompletado[i] << " "; cout << endl;

        cout << "extra: " << extra << ", Longitud del Octal: " << lenOcta << endl;

	//buscamos los valores para OCTAL
        for(int i = 0; i < lenOcta;i++){
                for(int k = 0;k < 8;k++){
                        int counterAp = 0;
                        for(int j = 0;j < 3;j++){
                                // comparando y si counterAp junta 3 el indice k es elegido
                                counterAp = ( binarioCompletado[((newLength-1) - ((i*3)+j))] == BINARY_OCTAL[k][j]) ? (counterAp+1) : counterAp;
                        }
                        octal[i] = (counterAp == 3) ? k : octal[i];
                }
        }
        // imprimimos los valores del hexadecimal
        cout << "El valor octal es: " << endl;
        for(int &val : octal) cout << val << " ";
        cout << endl;
}

void binaryToGray(){
	int longitud;
        cout << "Longitud de tu numero binario: " << endl, cin >> longitud;
        int binario[longitud];
        requestBinary(longitud, binario);

	// algoritmo
        // si el user introduce 1 0 1 1 0 entoces el arreglo interno queda: 0 1 1 0 1
        int extra = ((longitud % 4) == 0) ? 0 : (longitud % 4);
        int lenGray = ((longitud%4) == 0) ? (longitud / 4) : ((longitud / 4) + 1);

        // creando un nuevo arreglo binario con los ceros en caso de necesitarlo
        int newLength = (lenGray * 4);
        int binarioCompletado[newLength];
        for(int i = 0;i < newLength;i++) binarioCompletado[i] = (i < longitud) ? binario[i] : 0;
        // El nuevo binario impreso
        cout << "El nuevo binario es: " << endl;
        for (int i = (newLength - 1);i >=0;i--) cout << binarioCompletado[i] << " "; cout << endl;

	// algoritmo
	int gray[newLength];
	int desfase[newLength];
	for(int  i = (newLength-1);i >=0;i--) desfase[i] = (i != (newLength-1)) ? binarioCompletado[i+1] : 0;
	cout << "Desfase: " << endl;for(int  i = (newLength-1);i >=0;i--) cout << desfase[i] << " "; cout << endl;

	// executando la compuerta XOR
	cout << "Se aplica compueta XOR..." << endl;
	for(int i = (newLength-1);i >= 0;i--) gray[i] = (binarioCompletado[i]==1 ^ desfase[i]==1) ? 1 : 0;

	// imprimiendo el codigo gray
	cout << "El codigo de gray es: " << endl;
	for (int i = (newLength-1);i >=0;i--) cout << gray[i] << " "; cout << endl;
}

void grayToBinary(){
	cout << 8 << endl;
}

int main(){
	char HEXA[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'};
	int BINARY[16][4] = {{0,0,0,0}, {0,0,0,1}, {0,0,1,0},{0,0,1,1}, {0,1,0,0}, {0,1,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,0,0},
				{1,0,0,1},{1,0,1,0}, {1,0,1,1}, {1,1,0,0}, {1,1,0,1}, {1,1,1,0}, {1,1,1,1}};
	// int OCTAL[] = {0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, 16, 17};
	int BINARY_OCTAL[8][3] = {{0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1}};

	// conversiones decimales, binarias, hexadecimales, octales
	cout << "*****CONVERTIDOR DECIMAL, BINARIO, HEXADECIMAL, OCTAL********" << endl;
	int opcion;

	cout << "1. Decimal a binario" << endl;
	cout << "2. Binario a decimal" << endl;
	cout << "3. Hexadecimal a binario" << endl;
	cout << "4. Binario a Hexadecimal" << endl;
	cout << "5. Octal a Binario" << endl;
	cout << "6. Binario a Octal" << endl;
	cout << "7. Código Gray a binario" << endl;
	cout << "8. Código binario a código Gray\n" << endl;
	cout << "Ingrese la conversion que desea realizar: " << endl;
	cin >> opcion;
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
			hexaToBinary(HEXA, BINARY);
			break;
		case 4:
			cout << "********CONVERSION BINARIO A HEXADECIMAL********" << endl;
			binaryToHexa(HEXA, BINARY);
			break;
		case 5:
			cout << "********CONVERSION OCTAL A BINARIO*************" << endl;
			octalToBinary(BINARY_OCTAL);
			break;
		case 6:
			cout << "*******CONVERSION BINARIO A OCTAL**************" << endl;
			binaryToOctal(BINARY_OCTAL);
			break;
		case 7:
			cout << "*******CONVERSION BINARIO A GRAY**************" << endl;
			binaryToGray();
			break;
		case 8:
			cout << "*******CONVERSION GRAY A BINARIO**************" << endl;
			grayToBinary();
			break;
	}
	return 0;
}
