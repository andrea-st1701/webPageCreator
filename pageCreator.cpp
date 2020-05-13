#include <iostream>
#include <fstream>
using namespace std;
class html
{
	private:
	public:
		html();
};
class css
{
	public:
		css();
};
html::html()
{
	char title[100];
	ofstream h;
	h.open("index.html", ios_base::out);
	cout<<"insert title: ";
	gets(title);
	h<<"<!DOCTYPE html>\n<html>\n<head><title>"<<title<<"</title>" ;
	h.close();
	h.open("index.html", ios::app);
	h<<"<link rel=""stylesheet"" href="<<" 'stylesheet.css' >";
	h<<"\n</head>\n<div id=""container"">\n<body>\n<h1 style=""text-align:center;"">"<<title<<"</h1>\n";
	for(int i=0; i<10;i++)
	{
		h<<"daghgfdshfjfjhsjfhjshfshfjslhfjlsh\n";
	}
	
	h<<"</div>\n</body>";
	h<<"</html>";
}
css::css()
{
	ofstream c;
	c.open("stylesheet.css");
	char color[20];
	int contSz=0;
	cout<<"insert background color (blue, red, yellow, green, black,...) in case it is not available it will appear white\n";
	gets(color);
	c<<"body\n{\n	background-color:"<<color<<";\n";
	c.close();
	c.open("stylesheet.css", ios::app);
	cout<<"insert foreground color: ";
	gets(color);
	c<<"color:"<<color;
	c<<";}";
	cout<<"insert container size in percentage (ex 50%) if you don't want to insert a conteiner write '0'\n";
	cin>>contSz;
	if(contSz!=0)
	{
		c<<"#container\n{\nwidth:"<<contSz<<"%;\nposition:relative;\nmargin-left:auto;\nmargin-right:auto;\n height:auto;";
		cout<<"insert container background color: ";
		cin.ignore();
		gets(color);
		c<<"background-color: "<<color<<";\n}";
	}
	c.close();
}
int main()
{
	css c;
	html h;
}
