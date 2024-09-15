#ifndef KMP_H_
#define KMP_H_
#include<iostream>
class String{
	private:
	    char *str;
		int len;
		enum {CINMAX = 80};
		int *nextval;
	public:
		String();
		String(const char *s);
		String(const String &s);
		~String();
		String & operator=(const String &s);
		String & operator=(const char *s);
		friend std::ostream & operator<<(std::ostream &os,const String &str);
		friend std::istream & operator>>(std::istream &is,String &str);
		friend const String operator+(const String &str1,const String &str2);
		void get_nextval();
		void printnextval()const;
		int find(String &a)const;
};
#endif 
