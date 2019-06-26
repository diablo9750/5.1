#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cassert>                           
#include "CppUnitTest.h"
#include "C:\Users\Михаил\Desktop\Учёба\3.2\Технологии программирования\Лаба4\ConsoleApplication1\ConsoleApplication1\struct.h"
#include <vector>

using namespace std;
using namespace types;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace types {
	// Сигнатуры требуемых внешних функций
	void Init(container& b);
	void Clear(container& b);
	game* InGame(game& g, ifstream& ifst);
	void OutGame(game* g, ofstream& ofst);
	cartoon* InCartoon(cartoon& c, ifstream& ifst);
	void OutCartoon(cartoon* c, ofstream& ofst);
	doc* InDoc(doc& d, ifstream& ifst);
	void OutDoc(doc* d, ofstream& ofst);
	void Out(film* f, ofstream& ofst);
	film* In(ifstream& ifst);
	int addlist(container& b, ifstream& ifst);
	void InContainer(container& b, ifstream& ifst);
	void Out(container& b, ofstream& ofst);
	int Vowel(game* g);
	int Vowel(cartoon* c);
	int Vowel(doc* d);
	int Vowel(film* f);
	bool Compare(film* first, film* second);
	void OutFilter(container& b, ofstream& ofst);
	void Sort(container& b);
}

namespace UnitTestApp
{
	TEST_CLASS(UnitTest1)
	{
		void testfiles(ifstream & in, ifstream & in_test)
		{
			vector<string> strings1;
			string test;
			while (!getline(in, test).eof())
				strings1.push_back(test);
			strings1.push_back(test);

			vector<string> strings2;
			string out;
			while (!getline(in_test, out).eof())
				strings2.push_back(out);
			strings2.push_back(out);

			for (int i = 0; i < out.length(); i++)
			{
				Assert::AreEqual(strings1[i], strings2[i]);
			}
		}
		bool isdigit(int int_test)
		{
			int mass[10] = {{ 0 }, { 1 },{ 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 } };
			for (int i = 0; i < 10; i++)
			{
				if (int_test == mass[i])
				{
					return true;
				}
			}
			return false;
		}
	public:
		//Инициализация(Init)
		TEST_METHOD(TestInit)
		{
			container b;
			List* Top_test = nullptr;
			int count_test = 0;
			Init(b);
			if (!isdigit(b.count))
			{
				cout << "Wrong type of variable" << endl;
			}
			Assert::AreEqual(b.count, count_test);
		}

		//Отчистка контейнера(Clear)
		TEST_METHOD(TestClear)
		{
			container b;
			ifstream ifst("in.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			Init(b);
			InContainer(b, ifst);
			List* current = b.Top;
			if (!isdigit(b.count))
			{
				cout << "Wrong type of variable" << endl;
			}
			int test_count = 0;
			Clear(b);
			Assert::AreEqual(b.count, test_count);
		}

		//---------------------------------------------
		//Тестирование ввода(InGame)
		TEST_METHOD(TestInGame)
		{
			ifstream ifst("test_game.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			vector<string> string1;
			string1.push_back("1");
			string1.push_back("США Тёмный_рыцарь Нолан");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);

			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}
		}
		//(InCartoon)
		TEST_METHOD(TestInCartoon)
		{
			ifstream ifst("test_cartoon.txt");

			vector<string> string1;
			string1.push_back("2");
			string1.push_back("Польша Лунтик 2");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);

			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}

		}
		//(InDoc)
		TEST_METHOD(TestInDoc)
		{
			ifstream ifst("test_doc.txt");

			vector<string> string1;
			string1.push_back("3");
			string1.push_back("Россия История_мира 1999");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);

			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}

		}
		//(InContainer/addlist)
		TEST_METHOD(TestInContainer)
		{
			ifstream ifst("in.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			container b;
			Init(b);
			InContainer(b, ifst);
			int count_test = 4;
			Assert::AreEqual(b.count, count_test);
		}
		//---------------------------------------------
		//Тестирование вывода(OutGame)
		TEST_METHOD(TestOutGame)
		{
			ifstream ifst("test_game.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("test_game_out.txt", ios::trunc);
			container b;
			Init(b);
			InContainer(b, ifst);

			ifstream in("test_game_out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("game_out.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}

			testfiles(in, in_test);
		}
		//(OutCartoon)
		TEST_METHOD(TestOutCartoon)
		{
			ifstream ifst("test_cartoon.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("test_cartoon_out.txt", ios::trunc);
			container b;
			Init(b);
			InContainer(b, ifst);

			ifstream in("test_cartoon_out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("test_cartoon.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}

			testfiles(in, in_test);
		}
		//(OutDoc)
		TEST_METHOD(TestOutDoc)
		{
			ifstream ifst("test_doc.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("test_doc_out.txt", ios::trunc);
			container b;
			Init(b);
			InContainer(b, ifst);

			ifstream in("test_doc_out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("test_doc.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}

			testfiles(in, in_test);
		}
		//(Out)
		TEST_METHOD(TestOut)
		{
			ifstream ifst("in.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("out.txt", ios::trunc);
			container b;
			Init(b);
			InContainer(b, ifst);
			Out(b, ofst);

			ifstream in("out.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("out_test.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}

			testfiles(in, in_test);
		}
		//(OutFilter)
		TEST_METHOD(TestOutFilter)
		{
			ifstream ifst("in.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ofstream ofst("outfilter.txt", ios::trunc);
			container b;
			Init(b);
			InContainer(b, ifst);
			OutFilter(b, ofst);

			ifstream in("outfilter.txt");
			if (!in)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			ifstream in_test("outfilter_test.txt");
			if (!in_test)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}

			testfiles(in, in_test);
		}
		//---------------------------------------------
		//Тестирование дополнительных функций
		TEST_METHOD(TestVowelGame)
		{
			ifstream ifst("test_game.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			container b;
			Init(b);
			InContainer(b, ifst);
			List* current = b.Top;
			int vowel_test;
			int vowel = 4;
			vowel_test = Vowel(current->data);
			if (!isdigit(vowel_test))
			{
				cout << "Wrong type of variable" << endl;
			}
			Assert::AreEqual(vowel, vowel_test);
		}
		TEST_METHOD(TestVowelCartoon)
		{
			ifstream ifst("test_cartoon.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			container b;
			Init(b);
			InContainer(b, ifst);
			List* current = b.Top;
			int vowel_test;
			int vowel = 2;
			vowel_test = Vowel(current->data);
			if (!isdigit(vowel_test))
			{
				cout << "Wrong type of variable" << endl;
			}
			Assert::AreEqual(vowel, vowel_test);
		}
		TEST_METHOD(TestVowelDoc)
		{
			ifstream ifst("test_doc.txt");
			if (!ifst)
			{
				cout << "No input file found!" << endl;
				exit(1);
			}
			container b;
			Init(b);
			InContainer(b, ifst);
			List* current = b.Top;
			int vowel_test;
			int vowel = 6;
			vowel_test = Vowel(current->data);
			if (!isdigit(vowel_test))
			{
				cout << "Wrong type of variable" << endl;
			}
			Assert::AreEqual(vowel, vowel_test);
		}
	};
}