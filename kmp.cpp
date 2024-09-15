#include<iostream>
#include<cstring>
#include"kmp.h"
using namespace std;
String::String():len(0),str(nullptr),nextval(nullptr){}
String::String(const char *s):str(nullptr),len(strlen(s)),nextval(nullptr){
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
	get_nextval();
	}
String::String(const String &s):str(nullptr),len(strlen(s.str)),nextval(nullptr){
	len = strlen(s.str);
	str = new char[len+1];
	strcpy(str,s.str);
	get_nextval();
}
String& String::operator=(const String &s){
	delete[] str;
	len = strlen(s.str);
	str = new char[len+1];
	strcpy(str,s.str);
	get_nextval();
	return *this;
}
String& String::operator=(const char *s){
	delete[] str;
	len = strlen(s);
	str = new char[len+1];
	strcpy(str,s);
	get_nextval();
	return *this;
}
ostream& operator<<(ostream &os,const String &str)
{
	os<<str.str;
	return os;
}
istream& operator>>(istream &is,String &str)
{
	delete[] str.str;
	str = new char[String::CINMAX+1];
	is>>str.str;
	str.len = strlen(str.str);
	return is;
}
const String operator+(const String &str1,const String &str2){
	String str3;
	str3.len = str2.len +str1.len;
	str3.str = new char[str3.len+1];
	strcpy(str3.str,str1.str);
	strcat(str3.str,str2.str);
	str3.get_nextval();
	return (const String)str3;
}
String::~String(){
	delete[] str;
	delete[] nextval;
	}
/*
void String::get_next(){
	next = new int[len];
	next[0] = -1;
	next[1] = 0;
	int flag = 0;
	for (int i = 2;i<len;i++){
		for (int j = 1;j <= i;j++)
		{
			flag = 0;
			for (int k = 0;k < i - j;k++){
				if(str[k] != str[j+k]){
					flag = 1;
					break;}
				}
			if(flag == 0){
				next[i] = i - j;
				break;
				}
			}
	}
}
*/
void String::get_nextval(){
	int i=0,j=-1;
	nextval = new int[len];
	nextval[0]= -1;
	while(i<len){
		if(j == -1||str[j] == str[i])
		{j++;i++;
		if(	str[j] != str[i]){nextval[i] = j;}
		else{ 
			nextval[i] = nextval[j];
			}
		}
		else{
			j = nextval[j];
		}
	}
}
void String::printnextval()const{
	for (int i = 0;i < len;i++){
		cout<<nextval[i]<<" ";
	}
	cout<<endl;
}
int String::find(String &a)const{
	int i = 0,j = 0;
	while(j<a.len&&i<len)
	{
		if(j == -1||str[i] == a.str[j])
		{
			i++;j++;
			}
		else{
			j = a.nextval[j];
		}
	}
	if(j == a.len) return i -j ;
	else return -1;
}
