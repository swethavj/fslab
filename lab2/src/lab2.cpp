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

			fp1.open("file2.txt",ios::out|ios::app);
			fp1<<buf;
			fp1.close();
		}
		int search()
		{

			cout<<"enter the key"<<endl;
			cin>>key;
			fstream f1;
			f1.open("file2.txt",ios::in);
			while(!fp1.eof())
			{
				getline(fp1,buf);
				unpack();

				if(usn == key)
				{
					cout<<"record found";
					pos=f1.tellp();
					return pos;
				}
				else
				{
					cout<<"record not found";

				}
				fp1.close();
				return -1;
				}
			}

		string unpack()
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
							i++;

			cout<<name<<endl;
			cout<<usn <<endl;
			cout<<branch<<endl;
			cout<<semester<<endl;


		}
		int modify(key,string filename)
		{
			cout<<"1.insert"<<"2.search"<<"3.modify";


		}
