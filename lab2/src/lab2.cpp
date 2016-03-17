//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<fstream>
#include<istream>
#define max 100
using namespace std;

class Student{
	string name;
	string usn;
	string branch;
	string semester;
	string buf;
	fstream fp1;
	string key;
	string temp;
	int pos;
	public:
		void read()
		{
			cin.clear();
			cin.ignore(255,'\n');
			cout<<"enter the name usn  branch semester";
			cout<<endl;
			getline(cin,name);
			cout<<endl;
			cin>>usn>>branch>>semester;
			cout<<"insertion done the info's are"<<endl;
			cout<<name<<endl<<usn<<endl<<branch<<endl<<semester<<endl;
		}
		int pack()
		{
			string temp,$;
			int len,i;
			temp+=usn+'|'+ name+'|'+branch+'|'+semester;
			len=temp.size();
			buf=temp;
			for(i=len+1;i<100;i++)
				buf+='$';
				cout<<buf;
			return 0;
		}
		void write()
		{

			fp1.open("file3.txt",ios::out|ios::app);
			fp1<<buf;
			fp1.close();
		}
		int search(string key)
		{
			//cout<<"enter the key"<<endl;
			//cin>>key;
			//fstream f1;
			int pos;
			fp1.open("file3.txt",ios::in);
			while(!fp1.eof())
			{
				getline(fp1,buf);
				pos=fp1.tellp();
				unpack();

				if(usn==key)
				{
					cout<<name<<endl;
								cout<<usn <<endl;
								cout<<branch<<endl;
								cout<<semester<<endl;
				}
				else
					cout<<"record not found"<<endl;
				fp1.close();

				return 0;

			}
		}

		void unpack()
		{
			int i=0;
			name.erase();
			while(buf[i]!='|')
				name+=buf[i++];
				i++;

			usn.erase();
			while(buf[i]!='|')

				usn+=buf[i++];
				i++;

			branch.erase();
			while(buf[i]!='|')

							branch+=buf[i++];
							i++;

			semester.erase();
			while(buf[i]!='$')

							semester+=buf[i++];



		}
		void modify()
		{

			int ch,pos;
			pos=search(key);
			cout<<"enter ur choice"<<endl;
			cout<<"1.NAME"<<endl<<"2.usn"<<endl<<"3.branch"<<endl<<"4.semester";
			cin>>ch;
			switch(ch)
			{
			case 1:cout<<"enter the name"<<endl;
					cin.clear();
					cin.ignore(255,'\n');
					getline(cin,name);
					break;
			case 2: cout<<"enter the usn"<<endl;
					cin>>usn;
					break;
			case 3: cout<<"enter the branch"<<endl;
					cin>>branch;
					break;
			case 4: cout<<"enter the semester"<<endl;
					cin>>semester;
					break;
			}
			pack();
			write();




		}
};
int main()
{
	int ch;
	string key;
	Student s;
	while(1)
	{
	cout<<"enter ur choice"<<endl;
	cout<<"1.insert"<<"2.search"<<"3.modify"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1: s.read();
				s.pack();
				s.write();
				break;
		case 2:
			cout<<"key\n";
			cin>>key;
			s.search(key);
				break;
		case 3: s.modify();
				break;
	}
	}
	return 0;
}
