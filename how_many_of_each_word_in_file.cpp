#include <fstream> // Нужен для ввода из файла
#include <iostream> // нужен для вывода в консоль
#include <string> // Полезные функции обработки строки

using namespace std;

string const filename = "test.txt";

string to_lowercase(string str) // как оказалось в изначальном c++ нет to_lower для строк
{
	for(auto iter = str.begin(); iter != str.end(); iter++)
		*iter = tolower[*iter];
	return str;
}

vector<string> split(string str) // то же можно сказать про split (здесь только изначально извесный набор символов(маленькие буквы))
{
	auto result = new vector<string>();

	for(auto iter = str.begin(); iter != str.end(); iter++)
	{
		if(*iter >= 'a' && *iter <= 'z')
		{	
			auto start_of_word = iter;
		}

	}
}

int main()
{
	auto file_input_stream = new fstream(filename, input.in); //
	auto word_dictionary = new map<string, int>();  // словарб
	auto words_met = new vector<string>(); // для ключей к словарю

	if(!file_input.is_open())
		return -1;

	while(file_input_stream.eof())
	{
		string temporary_input;
		file_input_stream >> temporary_input;


	}
}
