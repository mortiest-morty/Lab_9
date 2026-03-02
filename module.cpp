# include "lul.h"

void DataBinFile(std::string filename, int& n) {
	using namespace std;
	int number;
	srand(time(0));
	n = rand() % 49;

	fstream f;
	f.open(filename, ios::in | ios::out | ios::binary);

	for (int i = 0; i < n; i++) {
		number = rand() % 50 - 5;
		f.write((char*)&number, sizeof(number));
	}

	// сбрасываем указатель в начало файла
	f.seekg(0, ios::beg);
}

void printFile(std::string filename, int count) {
	using namespace std;
	int number = 0;
	fstream f;

	if (count == 0) {
		cout << "Файл пуст ^-^" << endl;
	}
	else {
		f.open(filename, ios::in | ios::out | ios::binary);

		for (int i = 0; i < count; i++) {
			f.read((char*)&number, sizeof(number));
			cout << number << " ";
		}
		cout << endl;
	}
}

void task_1() {
	using namespace std;
	
	int n, number, cnt_even = 0, cnt_odd = 0;
	fstream f_data, f1, f2;
	f_data.open("dk.dat", ios::out | ios::in | ios::binary);
	f1.open("even_numbers.dat", ios::out | ios::in | ios::binary);
	f2.open("odd_numbers.dat", ios::out | ios::in | ios::binary);
	
	DataBinFile("dk.dat", n);
	cout << "Исходные данные: ";
	printFile("dk.dat", n);

	f_data.seekg(0, ios::beg);
	for (int i = 0; i < n; i++) {
		f_data.read((char*)&number, sizeof(number));
		if (number % 2 == 0) {
			cnt_even++;
			f1.write((char*)&number, sizeof(number));
		}
		else {
			cnt_odd++;
			f2.write((char*)&number, sizeof(number));
		}
	}

	f1.seekg(0, ios::beg);
	f2.seekg(0, ios::beg);
	cout << endl;

	cout << "Данные 1 файла (чётные числа): ";
	printFile("even_numbers.dat", cnt_even);
	cout << "Данные 2 файла (нечётные числа): ";
	printFile("odd_numbers.dat", cnt_odd);

	f_data.close();
	f1.close();
	f2.close();

	cout << endl;
	cake();
}


void task_2() {
	using namespace std;
	fstream f1;
	int n = 0, number;
	vector<int> a;

	DataBinFile("oxxymiron.dat", n);
	f1.open("oxxymiron.dat", ios::in | ios::out | ios::binary);

	int zerosToAdd = 50 - n;

	cout << "Размер файла: " << n << " елементов" << endl;
	cout << "Исходный файл (-_  -) : ";
	printFile("oxxymiron.dat", n);
	cout << endl;

	f1.seekg(0, ios::beg);
	for (int i = 0; i < n; i++) {
		f1.read((char*)&number, sizeof(number));
		a.push_back(number);
	}

	vector<int> result(50, 0);

	for (int i = 0; i < n; i++) {
		result[zerosToAdd + i] = a[i];
	}

	f1.close();
	f1.open("oxxymiron.dat", ios::out | ios::binary | ios::trunc);
	f1.write(reinterpret_cast<char*>(result.data()), 50 * sizeof(int));
	f1.close();

	cout << "Обновленный файл (-_-): ";
	printFile("oxxymiron.dat", 50);
	cout << "Добавлено нулей: " << zerosToAdd << endl << endl;
	cout << "(\\(\\ " << endl;
	cout << "( -.-)  " << endl;
	cout << "o_(+)(+)     " << endl;
}


void task_3() {
	using namespace std;

	int n, numFiles;
	double summ = 0;
	string S, archiveName;
	vector<double> arithmeticMean;

	makeFiles();
	createZip();
	cout << "Введите имя архива: ";
	cin >> archiveName;
	
	readZip(numFiles, summ, archiveName, arithmeticMean);
	
	cout << endl << "Введите S: ";
	cin >> S;
	
	ofstream f_Result(S, ios::binary);
	f_Result.write(reinterpret_cast<char*>(arithmeticMean.data()), arithmeticMean.size() * sizeof(double));
	f_Result.close();
	printResult(S, numFiles);
	cout << endl;
	secreteFunction();
}

void makeFileFor4Task(std::string str) {
	using namespace std;
	fstream f1;
	f1.open("logic.dat", ios::in | ios::out | ios::binary);
	f1.write((char*)&str, sizeof(str));
	f1.close();
}

void calculating(std::string) {

}

void task_4() {
	using namespace std;
	fstream f1;
	string str = "And(Or(T,F),T)", str1 = "Or(And(T,T),And(F,F))", str2 = "Or(T,F)", result;

	makeFileFor4Task(str);

	f1.open("logic.dat", ios::in | ios::out | ios::binary);
	f1.read((char*)&result, sizeof(result));
	
	for (int i : str) {
		cout << i;
	}
	

}
