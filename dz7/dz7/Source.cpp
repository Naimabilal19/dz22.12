#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#pragma comment(lib, "urlmon.lib")
using namespace std;

int main()
{
	//setlocale(0, "ru");
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);

	// the URL to download from 
	const char* srcURL = "https://api.privatbank.ua/p24api/pubinfo?exchange&coursid=5";
	const char* srcURL1 = "https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?json";
	// the destination file 
	const char* destFile = "file.txt";
	const char* destfile2 = "file2.txt";

	//// URLDownloadToFile returns S_OK on success 
	if (S_OK == URLDownloadToFileA(NULL, srcURL, destFile, 0, NULL))
	{
		cout << "Saved to " << destFile << "\n";
		
	}
	if (S_OK == URLDownloadToFileA(NULL, srcURL1, destfile2, 0, NULL))
	{
		cout << "Saved to " << destfile2 << "\n";
	}
	else cout << "Fail!\n";


	fstream in("file.txt");
	string buffer;
	in >> buffer;
	cout << "\t PrivatBank \t\n EUR\tUAH";
	int s = buffer.find("\"EUR\"\,\"base_ccy\"\:\"UAH\"\,\"buy\"\:\"");
	string a;
	a.assign(buffer, s+30, 5);
	cout << a << "\nSell: ";
	int v = buffer.find("\"EUR\"\,\"base_ccy\"\:\"UAH\"\,\"buy\"\:\"");
	string b;
	b.assign(buffer, v + 48, 5);
	cout << b << "\nSell: ";
	in.close();


	//--------------------------------------------------------------
	fstream in1("file2.txt");
	string buffer2;
	in >> buffer2;
	cout << "\t Bank2 \t\n CZK\tUAH";
	int s2 = buffer.find("\"CZK\"\,\"base_ccy\"\:\"USD\"\,\"buy\"\:\"");
	string c;
	c.assign(buffer, s2 + 2, 5);
	cout << c << "\nSell: ";
	int d = buffer.find("\"CZK\"\,\"base_ccy\"\:\"USD\"\,\"buy\"\:\"");
	string ee;
	ee.assign(buffer, d + 36, 5);
	cout << c << "\nSell: ";

}