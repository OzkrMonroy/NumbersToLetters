#include<iostream>
#include<string>

using namespace std;
void getUnits(int num);
void getTens(int num);
void concatUnitToTens(string numInLetters, int unit);
void getHundreds(int num);
void getMiles(int num);
void getMillions(int num);

string numberInLetters;

int main() {

	int num;
	cout << "-----------------------------------------------------" << "\n" << endl;
	cout << "            Conversor de numeros a letras            " << endl;
	cout << "            numeros de 1 hasta 999999999             " << "\n" << endl;
	cout << "-----------------------------------------------------" << "\n" << endl;
	cout << "Ingrese el numero" << "\n" << endl;
	cin >> num;
	cout << "\n";

	if (num >= 1 && num <= 999999999) {
		getMillions(num);

		cout << "El numero " << num << " en letras es: " << numberInLetters << endl;
	}
	else {
		cout << "El numero ingresado se encuentra fuera del rango indicado.";
	}
	return 0;
}

void getMillions(int num) {
	int millions = num / 1000000;
	int miles = num - millions * 1000000;
	
	if (millions == 1) {
		numberInLetters += "UN MILLON ";
	}
	else if (millions > 1) {
		getHundreds(millions);
		numberInLetters += " MILLONES ";
	}
	getMiles(miles);
}

void getMiles(int num) {
	int miles = num / 1000;
	int hundreds = num - miles * 1000;

	if (miles > 1) {
		getHundreds(miles);
	}
	if(miles != 0){
		numberInLetters += " MIL ";
	}
	getHundreds(hundreds);
}


void getHundreds(int num) {
	int hundreds = num / 100;
	int tens = num - hundreds * 100;

	switch (hundreds)
	{
	case 1:
		if (tens > 0) {
			numberInLetters += "CIENTO ";
			getTens(tens);
			break;
		}
		numberInLetters += "CIEN";
		break;
	case 2:
		numberInLetters += "DOSCIENTOS ";
		getTens(tens);
		break;
	case 3:
		numberInLetters += "TRESCIENTOS ";
		getTens(tens);
		break;
	case 4:
		numberInLetters += "CUATROCIENTOS ";
		getTens(tens);
		break;
	case 5:
		numberInLetters += "QUINIENTOS ";
		getTens(tens);
		break;
	case 6:
		numberInLetters += "SEISCIENTOS ";
		getTens(tens);
		break;
	case 7:
		numberInLetters += "SETECIENTOS ";
		getTens(tens);
		break;
	case 8:
		numberInLetters += "OCHOCIENTOS ";
		getTens(tens);
		break;
	case 9:
		numberInLetters += "NOVECIENTOS ";
		getTens(tens);
		break;
	default:
		getTens(tens);
		break;
	}
}

void getTens(int num) {
	int tens = num / 10;
	int unit = num - tens * 10;

	switch (tens) {
	case 1: 
		switch (unit) {
		case 0:
			numberInLetters += " DIEZ";
			break;
		case 1:
			numberInLetters += " ONCE";
			break; 
		case 2:
				numberInLetters += " DOCE";
				break;
		case 3:
			numberInLetters += " TRECE";
			break;
		case 4:
			numberInLetters += " CATORCE";
			break;
		case 5:
			numberInLetters += " QUINCE";
			break;
		default:
			numberInLetters += " DIECI";
			getUnits(unit);
			break;
		}
	break;
	case 2:
		if (unit == 0) {
			numberInLetters += " VEINTE";
			break;
		}
		numberInLetters += "VEINTI";
		getUnits(unit);
	break;
	case 3:
		concatUnitToTens("TREINTA", unit);
		break;
	case 4:
		concatUnitToTens("CUARENTA", unit);
		break;
	case 5:
		concatUnitToTens("CINCUENTA", unit);
		break;
	case 6:
		concatUnitToTens("SESENTA", unit);
		break;
	case 7:
		concatUnitToTens("SETENTA", unit);
		break;
	case 8:
		concatUnitToTens("OCHENTA", unit);
		break;
	case 9:
		concatUnitToTens("NOVENTA", unit);
		break;
	default:
		getUnits(unit);
		break;
	}
}

void concatUnitToTens(string numInLetters, int unit) {
	numberInLetters += numInLetters;
	if (unit > 0) {
		numberInLetters += " Y ";
		getUnits(unit);
	}
}

void getUnits(int num) {
	switch (num) {
	case 1: {
		numberInLetters += "UNO";
		break;
	}
	case 2: {
		numberInLetters += "DOS";
		break;
	}
	case 3: {
		numberInLetters += "TRES";
		break;
	}
	case 4: {
		numberInLetters += "CUATRO";
		break;
	}
	case 5: {
		numberInLetters += "CINCO";
		break;
	}
	case 6: {
		numberInLetters += "SEIS";
		break;
	}
	case 7: {
		numberInLetters += "SIETE";
		break;
	}
	case 8: {
		numberInLetters += "OCHO";
		break;
	}
	case 9: {
		numberInLetters += "NUEVE";
		break;
	}

	default: {
		numberInLetters += "";
		break;
	}
	}
}
