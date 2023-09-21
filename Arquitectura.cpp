#include <iostream>
#include <bitset>

int Multiplicacion(int multiplicand, int multiplier) {
    int result = 0;
    int multiplicandAbs = abs(multiplicand);
    int multiplierAbs = abs(multiplier);
    int product = 0;

    for (int i = 0; i < 32; i++) { // Suponiendo números de 32 bits
        int lsbMultiplier = multiplierAbs & 1;
        if (lsbMultiplier == 1) {
            product += multiplicandAbs;
        }
        multiplicandAbs <<= 1;
        multiplierAbs >>= 1;
    }

    if ((multiplicand < 0) ^ (multiplier < 0)) {
        result = -product;
    }
    else {
        result = product;
    }

    return result;
}

std::string Binario(int n) {
    return std::bitset<32>(n).to_string();
}

int main() {
    while (true) {
        system("cls");
        std::cout << "Este codigo funciona con una cantidad predeterminada de 32 bytes, pero funciona con cualquier cantidad de bits pero se tendria que modificar directamente en el codigo en las lineas 10 y 30 cambiando el 32 por la cantidad de bits que se desea"<<std::endl << std::endl;
        int multiplicand, multiplier;

        std::cout << "Ingrese el multiplicando: ";
        std::cin >> multiplicand;

        std::cout << "Ingrese el multiplicador: ";
        std::cin >> multiplier;

        int product = Multiplicacion(multiplicand, multiplier);

        std::cout << "Resultado: " << product << std::endl;
        std::cout << "Resultado en binario: " << Binario(product) << std::endl;
        system("pause");
    }
}