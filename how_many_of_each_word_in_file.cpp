#include <fstream> // Нужен для ввода из файла
#include <iostream> // нужен для вывода в консоль
#include <vector> // объект похожий на массив, меняющий размер
#include <map> // словарь

using namespace std;

string const filename = "test.txt";

string to_lowercase(string &str) // как оказалось в изначальном c++ нет to_lower для строк
{
	for(int i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);
	return str;
}

vector<string> split(string &str) // то же можно сказать про split (здесь только изначально извесный набор символов(маленькие буквы))
{
	vector<string> result = vector<string>();

	for(int i = 0; i < str.size(); i++)
	{
		string word = "";
		while(str[i] >= 'a' && str[i] <= 'z' && i < str.size())
			word += str[i++]; // если подходящие буквы и не конец строки то добавляю их в слово

		if(word != "")
			result.push_back(word); // запись в конец
	}

	return result;
}

int main()
{
	fstream file_input_stream;
	file_input_stream.open(filename, fstream::in); //

	map<string, int> word_dictionary = map<string, int>();  // словарь
	vector<string> words_met = vector<string>(); // для ключей к словарю

	if(!file_input_stream.is_open()) // если файл не открылся, то и читать нечего
		return -1;
	
	while(!file_input_stream.eof())
	{
		string temporary_input;
		file_input_stream >> temporary_input;
		temporary_input = to_lowercase(temporary_input); // все заглавные становятся прописными
		auto splited_input = split(temporary_input); // вектор со словами (или одним словом если оно было без разделителей вродед)

		for(auto i = splited_input.begin(); i != splited_input.end(); i++) // с помощью итератеров пробег по вектору из разделённых слов
			if(word_dictionary[*i]++ == 0) // если в словаре по ключу лежал 0, то он запишется в вектор (в любом случае по ключу значение увеличится на 1)
				words_met.push_back(*i);

	}

	file_input_stream.close(); // лишним не будет закрыть не нужный файл

	cout << "(";
	for(auto i = words_met.begin(); i != words_met.end(); i++)
	{
		cout << "[\"" <<*i<<"\", "<< word_dictionary[*i] << "]";
		if(i+1 != words_met.end())
			cout << ", "; //вывод в правильном формате
	}
	cout << ")\n";

	
}
