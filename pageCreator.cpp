#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class html
{
	private:
		ofstream h;
		char n[100];
	public:
		void newpar();
		void newimg();
		html(char*);
		~html();
};
class css
{
	private:
		ofstream c;
	public:
		css();
};
//
inline ostream& green(ostream &os)
{
	os<<"\n";
	SetConsoleTextAttribute(hConsole,  FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	return os;
}
inline ostream& red(ostream &os)
{
	SetConsoleTextAttribute(hConsole,  FOREGROUND_RED|FOREGROUND_INTENSITY);
	return os;
}
inline ostream& normal(ostream &os)
{
	SetConsoleTextAttribute(hConsole,  FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
	return os;
}
inline ostream& blue(ostream &os)
{
	SetConsoleTextAttribute(hConsole,  FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	return os;
}
//
html::~html()
{
	h.open(n, ios::app);
	h<<"</div>\n</div>\n</body>";
	h<<"</html>";
	cout<<green<<"\nnow you can modify your page as you like it, bye!\n"<<normal;
	h.close();
	system("pause");
}
html::html(char* name)
{
	for(int i=0; i<100; i++)
	{
		n[i]=name[i];
	}
	char title[100];
	h.open(name, ios_base::out);
	cout<<green<<"insert title: "<<normal;
	gets(title);
	h<<"<!DOCTYPE html>\n<html>\n<head><title>"<<title<<"</title>" ;
	h.close();
	h.open(name, ios::app);
	h<<"<link rel=\"stylesheet\" href="<<" 'stylesheet.css' >";
	
	h<<"\n</head>\n<body>\n";
	h<<"<div id=\"container\">\n";
	h<<"<div id=\"header\">\n<h1 style=\"text-align:center; position:relative; top:25px; font-size:40px\">"<<title<<"</h1>\n</div>";
	h<<"<div id=\"content\">\n";

	h.close();
	
}
css::css()
{
	c.open("stylesheet.css");
	char color[20];
	int pc=0,Sz=0 ;
	int n=0;
	cout<<green<<"insert background color (blue, red, yellow, green, black,...) in case it is not available it will appear white\n"<<normal;
	gets(color);
	c<<"body\n{\n	background-color:"<<color<<";\n";
	c.close();
	c.open("stylesheet.css", ios::app);
	cout<<green<<"insert foreground color: "<<normal;
	gets(color);
	c<<"	color:"<<color;
	c<<";\n}";
	cout<<green<<"insert header height in px (eg 100)\n"<<normal;
	cin>>Sz;
	cout<<green<<"insert container size in percentage (eg 50)\n"<<normal;
	cin>>pc;
	if(pc!=0)
	{
		cout<<green<<"insert content padding (eg 20): "<<normal;
		cin>>n;
		c<<"\n#container\n{\n	width:"<<pc<<"%;\n	position:relative;\n	margin-left:auto;\n	margin-right:auto;\n	height:auto;\n}\n	";
		c<<"\n#content\n{\n	position:relative;\n	float:left;\n	height:auto;\n	padding:"<<n<<"px;\n	";
		cout<<green<<"insert content background color: "<<normal;
		cin.ignore();
		gets(color);
		c<<"background-color: "<<color<<";\n}";
	}
	if(Sz!=0)
	{
		cout<<green<<"insert header size in percentage (eg 100=all the container)\n"<<normal;
		cin>>pc;
		c<<"\n#header\n{\n	height:"<<Sz<<"px;\n	width:"<<pc<<"%;\n	position:relative;\nmargin-bottom:10px;\n	margin-left:auto;\n	margin-right:auto;\n";
		cout<<green<<"insert header background color: "<<normal;
		cin.ignore();
		gets(color);
		c<<"background-color: "<<color<<";\n}";
	}
	
	c.close();
}
void html::newpar()
{
	char title[100];
	char file[100];
	char word[100];
	h.open(n, ios::app);
	cout<<green<<"insert title for this paragraph: "<<normal;
	cin.ignore();
	gets(title);
	h<<"<h1 style=\"text-align:center;\">"<<title<<"</h1>\n";
	cout<<green<<"insert name of input file for the paragraph: "<<normal;
	gets(file);
	ifstream in(file);
	if(in)
	{
		h<<"<p>\n";
		while(!in.eof())
		{
			in>>word;
			h<<word<<" ";
		}
		h<<"</p>\n";
		in.close();
		h.close();
	}
	else
	{
		cout<<red<<"error, check that file exists then retry\n"<<normal;
	}
}
void html::newimg()
{
	char name[200];
	cout<<green<<"insert name or url of the image (remember to put it in the folder first\n"<<normal;
	cin.ignore();
	gets(name);
	h.open(n, ios::app);
	h<<"\n<img src=\" "<<name<<"\">\n";
	h.close();
}

int main()
{
	char title[100];
	bool end=0;
	char c='e';
	cout<<green<<"insert file name for your webpage\n"<<normal;;
	gets(title);
	css cs;
	html h1(title);
	while(!end)
	{
		cout<<blue<<"your page is almost done, what do you want to do now?\na=add text paragraph\ni=add image\ne=close page\n\n"<<normal;
		cin>>c;
		switch(c)
		{
			case 'a':
				h1.newpar();
				break;
			case 'i':
				h1.newimg();
				break;
			case'e':
				end=1;
				break;
			default:
				cout<<red<<"invalid character\n"<<normal;
				break;
		}
	}
	
}

