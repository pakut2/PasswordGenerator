#include <iostream>
#include <cstdlib>
#include <set>
#include <ctime>
#include <string>
#include <vector>
#include <windows.h>
#include <map>
#include <conio.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int length;

void alphanumeric();
void numeric();
void text();
void passwdDb();
void AnDatabase();
void NumDatabase();
void TextDatabase();
void menu();

void menu()
{
    system("cls");
	char choise;

	while(true)
	{
		cout << "PASSWORD GENERATOR \n";
		cout << "1 - Generate alphanumeric password \n";
		cout << "2 - Generate numeric password \n";
		cout << "3 - Generate text password \n";
		cout << "4 - Password database \n";
		cout << "5 - Terminate program \n";

		cout << endl;
		choise = getch();

		switch(choise)
		{
			case '1': alphanumeric(); break;
			case '2': numeric(); break;
			case '3': text(); break;
			case '4': passwdDb(); break;
			case '5': exit(0); break;
			default: cout << "Incorrect input"; break;
		}
		cout << endl;
		getchar(); getchar();
		system("cls");
	}
}

vector<char> createANArray()
{
    vector<char> alphanumeric;
    for(int i='0'; i<'9'; i++)
    {
        alphanumeric.push_back(char(i));
    }

    for(int i='a'; i<'z'; i++)
    {
        alphanumeric.push_back(char(i));
    }

    for(int i='A'; i<'Z'; i++)
    {
        alphanumeric.push_back(char(i));
    }

        return alphanumeric;
}

string randomANPasswd()
{
    srand(time(NULL));
    vector<char> arrayAN = createANArray();
    string pass = "";
    for(int i=0; i<length; i++)
    {
        int tmp = rand()%arrayAN.size();
        pass += arrayAN[tmp];
    }

    return pass;
}

void alphanumeric()
{
    system("cls");
    set<string> passwd;
    set<string>::iterator it;
    int n;

    cout << "How many passwords do you want do generate? \n";
    cin >> n;
    system("cls");

    cout << "How many characters shall a password contain? \n";
    cin >> length;
    system("cls");

    ofstream alphanum;
    alphanum.open("AlphanumericPasswords.txt", ofstream::out | ofstream::app);

    for(int i=0; i<n; i++)
    {
        string tmp = randomANPasswd();
        Sleep(1000);
        passwd.insert(tmp);
        alphanum << tmp << endl;
    }

    for(it=passwd.begin(); it!=passwd.end(); it++)
    {
        cout << *it << '\n';
    }
    alphanum.close();

    cout << endl;
    cout << "Press any key to continue \n";
    getch();
    menu();
}

vector<char> createNumArray()
{
    vector<char> numeric;
    for(int i='0'; i<'9'; i++)
    {
        numeric.push_back(char(i));
    }
        return numeric;
}

string randomNumPasswd()
{
    srand(time(NULL));
    vector<char> arrayAN = createNumArray();
    string pass = "";
    for(int i=0; i<length; i++)
    {
        int tmp = rand()%arrayAN.size();
        pass += arrayAN[tmp];
    }

    return pass;
}

void numeric()
{
    system("cls");
    set<string> passwd;
    set<string>::iterator it;
    int n;

    cout << "How many passwords do you want do generate? \n";
    cin >> n;
    system("cls");

    cout << "How many characters shall a password contain? \n";
    cin >> length;
    system("cls");

    ofstream num;
    num.open("NumericPasswords.txt", ofstream::out | ofstream::app);

    for(int i=0; i<n; i++)
    {
        string tmp = randomNumPasswd();
        Sleep(1000);
        passwd.insert(tmp);
        num << tmp << endl;
    }

    for(it=passwd.begin(); it!=passwd.end(); it++)
    {
        cout << *it << '\n';
    }
    num.close();

    cout << endl;
    cout << "Press any key to continue \n";
    getch();
    menu();
}

vector<char> createTextArray()
{
    vector<char> text;
    for(int i='a'; i<'z'; i++)
    {
        text.push_back(char(i));
    }

    for(int i='A'; i<'Z'; i++)
    {
        text.push_back(char(i));
    }

        return text;
}

string randomTextPasswd()
{
    srand(time(NULL));
    vector<char> arrayAN = createTextArray();
    string pass = "";
    for(int i=0; i<length; i++)
    {
        int tmp = rand()%arrayAN.size();
        pass += arrayAN[tmp];
    }

    return pass;
}

void text()
{
    system("cls");
    set<string> passwd;
    set<string>::iterator it;
    int n;

    cout << "How many passwords do you want do generate? \n";
    cin >> n;
    system("cls");

    cout << "How many characters shall a password contain? \n";
    cin >> length;
    system("cls");

    ofstream Text;
    Text.open("TextPasswords.txt", ofstream::out | ofstream::app);

    for(int i=0; i<n; i++)
    {
        string tmp = randomTextPasswd();
        Sleep(1000);
        passwd.insert(tmp);
        Text << tmp << endl;
    }

    for(it=passwd.begin(); it!=passwd.end(); it++)
    {
        cout << *it << '\n';
    }
    Text.close();

    cout << endl;
    cout << "Press any key to continue \n";
    getch();
    menu();
}

void passwdDb()
{
    system("cls");
    char choice;

    cout << "PASSWORD DATABASE \n";
    cout << "1 - List alphanumeric passwords \n";
    cout << "2 - List numeric passwords \n";
    cout << "3 - List text passwords \n";
    cout << "4 - Return to main menu \n";
    cout << "5 - Terminate program \n";

    choice = getch();
    switch(choice)
    {
        case '1': AnDatabase(); break;
        case '2': NumDatabase(); break;
        case '3': TextDatabase(); break;
        case '4': menu(); break;
        case '5': exit(0); break;
    }
}

void AnDatabase()
{
    system("cls");
    string line;
    fstream an;
    an.open("AlphanumericPasswords.txt", ios::in);

    if(!an.good())
    {
        cout << "Cannot locate file \n";
        cout << endl;
        cout << "Press any key to continue \n";
        getch();
        passwdDb();
    }
    else
    {
        while(!an.eof())
        {
            getline(an, line);
            cout << line << endl;
        }
    }
    an.close();

    cout << endl;
    cout << "Press any key to continue \n";
    getch();
    passwdDb();
}

void NumDatabase()
{
    system("cls");
    string line;
    fstream num;
    num.open("NumericPasswords.txt", ios::in);

    if(!num.good())
    {
        cout << "Cannot locate file \n";
        cout << endl;
        cout << "Press any key to continue \n";
        getch();
        passwdDb();
    }
    else
    {
        while(!num.eof())
        {
            getline(num, line);
            cout << line << endl;
        }
    }
    num.close();

    cout << endl;
    cout << "Press any key to continue \n";
    getch();
    passwdDb();
}

void TextDatabase()
{
    system("cls");
    string line;
    fstream text;
    text.open("TextPasswords.txt", ios::in);

    if(!text.good())
    {
        cout << "Cannot locate file \n";
        cout << endl;
        cout << "Press any key to continue \n";
        getch();
        passwdDb();
    }
    else
    {
        while(!text.eof())
        {
            getline(text, line);
            cout << line << endl;
        }
    }
    text.close();

    cout << endl;
    cout << "Press any key to continue \n";
    getch();
    passwdDb();
}

int main()
{
    menu();

    return 0;
}
