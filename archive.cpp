# include "lul.h"

void makeData(std::string filename) {
	int cnt;
	using namespace std;
	fstream file;
	vector<int> numbers;
	file.open(filename, ios::out | ios::binary);

	cnt = rand() % 10 + 1;

	for (int i = 0; i < cnt; i++) {
		int num;
		num = rand() % 70;
		numbers.push_back(num);
	}
	file.write((char*)&cnt, sizeof(cnt)); // размер файла записываем в файл
	file.write(reinterpret_cast<char*>(numbers.data()), cnt * sizeof(int)); // заполняем файл целыми числами
	file.close();
}

void makeFiles() {
	srand(time(0));

	makeData("1.dat");
	makeData("2.dat");
	makeData("3.dat");
	makeData("4.dat");
}

// Создание ZIP архива
void createZip() {
	int errorp;
	zip_t* archive = zip_open("rick.zip", ZIP_CREATE, &errorp);

	// Добавление файла
	zip_source_t* source = zip_source_file(archive, "1.dat", 0, 0);
	zip_file_add(archive, "1.dat", source, ZIP_FL_OVERWRITE);

	source = zip_source_file(archive, "2.dat", 0, 0);
	zip_file_add(archive, "2.dat", source, ZIP_FL_OVERWRITE);

	source = zip_source_file(archive, "3.dat", 0, 0);
	zip_file_add(archive, "3.dat", source, ZIP_FL_OVERWRITE);

	source = zip_source_file(archive, "4.dat", 0, 0);
	zip_file_add(archive, "4.dat", source, ZIP_FL_OVERWRITE);

	zip_close(archive);
}

void readZip(int &numFiles, double summ, std::string archiveName, std::vector<double> &arithmeticMean) {
	using namespace std;
	int errorp;

	zip_t* archive = zip_open(archiveName.c_str(), 0, &errorp);
	//проверка 
	if (!archive) {  
		cout << "Ошибка открытия архива'" << archiveName << "'!" << endl;
		return;  
	}

	numFiles = zip_get_num_entries(archive, 0);
	//проверка 
	if (numFiles < 0) {
		cout << "Ошибка получения файлов из архива" << endl;
		zip_close(archive);
		return;
	}
	cout << "В архиве " << numFiles << " файлов:" << endl << endl;
	 
	// print the data of all files in archive
	for (int i = 0; i < numFiles; i++) {
		int count;
		const char* name = zip_get_name(archive, i, 0);
		cout << "  " << name << endl;

		// open file
		zip_file_t* file = zip_fopen(archive, name, 0);
		zip_fread(file, &count, sizeof(int));
		cout << "Количество чисел в файле: " << count << endl;

		// Создаем вектор нужного размера
		vector<int> numbers(count);

		// Читаем все числа прямо в вектор
		int bytesRead = zip_fread(file, numbers.data(), count * sizeof(int));

		cout << "Содержимое файла: ";
		for (int i : numbers) {
			cout << i << " ";
		}
		cout << endl << endl;
		
		addNumber(count, summ, numbers, arithmeticMean);

		zip_fclose(file);
	}

	zip_close(archive);
}

void addNumber(int count, double summ, std::vector<int> numbers, std::vector<double>& arithmeticMean) {
	using namespace std;
	for (int i : numbers) {
		summ += i;
	}
	summ /= count;
	arithmeticMean.push_back(summ);
}

void printResult(const std::string& filename, int numFiles) {
	using namespace std;
	ifstream file(filename, ios::binary);

	if (!file.is_open()) {
		cerr << "Ошибка: не удалось открыть файл " << filename << endl;
		return;
	}

	vector<double> data(numFiles);

	// Читаем бинарные данные как double
	file.read(reinterpret_cast<char*>(data.data()), numFiles * sizeof(double));

	if (file.good()) {
		cout << "Содержимое файла " << filename << ": ";
		for (double val : data) {
			cout << val << " ";
		}
		cout << endl;
	}
	else {
		cerr << "Ошибка при чтении файла" << endl;
	}

	file.close();
}

void secreteFunction() {
	using namespace std;
	cout << "..............W$ХН~Н!Н!НХGFDSSFFFTTSDS." << endl;
	cout << "...........*UHWHН!hhhhН!? M88WHXХWWWWSW$." << endl;
	cout << ".......X * #M@$Н!eeeeНXНM$$$$$$WWxХWWWSW$" << endl;
	cout << "…...ХН!Н!Н!? HН..ХН$Н$$$$$$$$$$8XХDDFDFWW$" << endl;
	cout << "....Н!f$$$$gХhН!jkgfХ~Н$Н#$$$$$$$$$$8XХKKWW$,"<< endl;
	cout << "....ХНgХ:НHНHHHfg~iU$XН ? R$$$$$$$$MMНGG$$R$$" << endl;
	cout << "....~НgН!Н!df$$$$$JXW$$$UН!? $$$$$$RMMНLFG$$$$" << endl;
	cout << "......НХdfgdfghtХНM""T#$$$$WX ? ? MRRMMMН$$$$$$$" << endl;
	cout << "......~? W…fiW * `........`""#$$$$8Н!Н!? WWW ? Н!J$$$$" << endl;
	cout << "...........M$$$$.............`""T#$T~Н8$WUXUQ$$$$" << endl;
	cout << "...........~#$$$mХ.............~Н~$$$ ? $$$$$$$F$" << endl;
	cout << "..............~T$$$$8xx......xWWFW~## * '''''''''\\II$\\" << endl;
	cout << "...............$$$.P$T#$$@@W@ */**$$..........,,$," << endl;
	cout << ".............$$$L!?$$.XXХXUW...../.....$$,,,,...,,ХJ'" << endl;
	cout << "............$$$.......LM$$$$Ti...../....Un+НHFGJ`" << endl;
	cout << "..........$$$H.Нu....""$$B$$MEb!MХUНT$$" << endl;
	cout << "............W$@WTL...""*$$$W$TH$Н***" << endl;
	cout << "..............?$$$B$Wu,,''***PF~***$/" << endl;
	cout << "....................L$$$$$B$$eeeХWP$$/" << endl;
	cout << ".......................\"##*$$$$M$$F''" << endl;
}

void cake() {
	using namespace std;
	cout << "-----------------------()---()—()—()—()" << endl;
	cout << "-----------------------||---||—||—||—||" << endl;
	cout << "---------------------{*~*~*~*~*~*~*~*~*~}" << endl;
	cout << "-----------------@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "-----------------{~*~*~*~*~*~*~*~*~*~*~*~*~}" << endl;
	cout << "--------------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "--------------{~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~}" << endl;
	cout << "--------------{~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~}" << endl;
	cout << "--------------{~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~}" << endl;
	cout << "--------------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "-------------------------)---------(" << endl;
	cout << "--------------------____,-----------,____" << endl;
	cout << "--------------------/____________________\\" << endl;
}
