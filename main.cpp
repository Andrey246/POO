#include <iostream>
#include <cstring>

class string{

private:

    char *str = nullptr;
    int length = 0;

public:

    string();
    string(const string&);
    string(const char*);
    string(const char);

    void set(const char*);
    ///functia pos e declarata inafara clasei
    friend string copy(string&,int,int);
    friend void insert(string&,string&,int);
    friend void Delete(string& arg,int,int);

    char* get();
    void operator=(string&);
    void operator=(const char);
    char operator[](int);


    friend string operator+(string&,string&);
    friend string operator+(string&,const char);
    friend string operator+(const char,string&);

    friend bool operator==(string&,string&);
    friend bool operator==(string&,const char);
    friend bool operator==(const char,string&);

    friend bool operator!=(string&,string&);
    friend bool operator!=(string&,const char);
    friend bool operator!=(const char,string&);

    friend bool operator<(string&,string&);
    friend bool operator<(string&,const char);
    friend bool operator<(const char,string&);

    friend bool operator<=(string&,string&);
    friend bool operator<=(string&,const char);
    friend bool operator<=(const char,string&);

    friend bool operator>(string&,string&);
    friend bool operator>(string&,const char);
    friend bool operator>(const char,string&);

    friend bool operator>=(string&,string&);
    friend bool operator>=(string&,const char);
    friend bool operator>=(const char,string&);

    friend int length(string&);

    std::ostream& operator<<(std::ostream&);
    std::istream& operator>>(std::istream&);

    ~string();

};


std::ostream& string::operator<<(std::ostream& out){

    out<<str<<'\n';
    return out;

}

std::istream& string::operator>>(std::istream& in){

    char buffer[128];
    in.getline(buffer,128);
    length = strlen(buffer);
    delete[] str;
    str = new char[length+1];
    strcpy(str,buffer);

    return in;

}

string::string(){}

string::string(const char* str0){

    length = strlen(str0);
    str = new char[length+1];
    strcpy(str,str0);

}

string::string(const char chr0){

    length = 2;
    str = new char[length];
    str[0] = chr0;
    str[1] = '\0';

}

string::string(const string& str0){

    length = strlen(str0.str);
    str = new char[length+1];
    strcpy(str,str0.str);

}

string::~string(){

    delete[] str;

}

void string::set(const char* str0){

    if( length != strlen(str0) ){
        delete[] str;
        length = strlen(str0);
        str = new char[length+1];
    }
    strcpy(str,str0);

}

char* string::get(){

    return str;

}

void string::operator=(string& arg){

    delete[] str;
    length = arg.length;
    str = new char[length+1];
    strcpy(str,arg.str);

}

void string::operator=(char arg){

    delete[] str;
    length = 2;
    str = new char[length];
    str[0] = arg;
    str[1] = '\0';

}

char string::operator[](int n){

    return str[n];

}

string operator+(string& arg1,string& arg2){

    string tmp;
    tmp.length = arg1.length+arg2.length;
    tmp.str = new char[tmp.length+1];
    strcpy(tmp.str,arg1.str);
    strcat(tmp.str,arg2.str);

    return tmp;
}

string operator+(string& arg1,const char arg2){

    string tmp;
    tmp.length = arg1.length + 1;
    tmp.str = new char[tmp.length+1];
    strcpy(tmp.str,arg1.str);
    tmp.str[tmp.length-1] = arg2;
    tmp.str[tmp.length] = '\0';

    return tmp;
}

string operator+(const char arg1,string& arg2){

    string tmp;
    tmp.length = arg2.length + 1;
    tmp.str = new char[tmp.length+1];
    tmp.str[0] = arg1;
    strcpy(tmp.str+1,arg2.str);

    return tmp;
}

bool operator==(string& arg1,string& arg2){

    return strcmp(arg1.str,arg2.str)==0;

}

bool operator==(string& arg1,const char arg2){

    return arg2 == arg1.str[0];

}

bool operator==(const char arg1,string& arg2){

    return arg1 == arg2.str[0];

}

bool operator!=(string& arg1,string& arg2){

    return strcmp(arg1.str,arg2.str)!=0;

}

bool operator!=(string& arg1,const char arg2){

    return arg2 != arg1.str[0];

}

bool operator!=(const char arg1,string& arg2){

    return arg1 != arg2.str[0];

}

bool operator<(string& arg1,string& arg2){

    return strcmp(arg1.str,arg2.str)<0;

}

bool operator<(string& arg1,const char arg2){

    return arg1.str[0] < arg2;
}

bool operator<(const char arg1,string& arg2){

    return  arg1 < arg2.str[0];

}

bool operator<=(string& arg1,string& arg2){

    return strcmp(arg1.str,arg2.str) < 0 && strcmp(arg1.str,arg2.str) == 0 ;

}

bool operator<=(string& arg1,const char arg2){

    return arg1.str[0] < arg2 && arg1.str[0] == arg2;

}

bool operator<=(const char arg1,string& arg2){

    return  arg1 < arg2.str[0] && arg2.str[0] == arg1;

}

bool operator>(string& arg1,string& arg2){

    return strcmp(arg1.str,arg2.str) > 0;

}

bool operator>(string& arg1,const char arg2){

    return arg1.str[0] < arg2;

}

bool operator>(const char arg1,string& arg2){

    return arg1 < arg2.str[0];

}

bool operator>=(string& arg1,string& arg2){

    return strcmp(arg1.str,arg2.str) > 0 && strcmp(arg1.str,arg2.str) == 0;

}

bool operator>=(string& arg1,const char arg2){

    return arg1.str[0] > arg2 && arg1.str[0] == arg2;

}

bool operator>=(const char arg1,string& arg2){

    return arg1 > arg2.str[0] && arg2.str[0] == arg1;

}

int length(string& arg){

    return arg.length;

}

string copy(string& arg,int index,int count){

    string tmp;
    tmp.length = count;
    tmp.str = new char[tmp.length+1];
    strncpy(tmp.str,arg.str+index,count);

    return tmp;

}

int pos(string& arg,string& substr){

    int index = 0;

    while(index <= length(arg) ){
    if( strncmp(arg.get()+index,substr.get(),length(substr)) == 0 )
        return index;
    index++;
    }

    return -1;

}

void insert(string& arg, string& source, int index){

    string tmp0 = copy(arg,0,index+1);
    string tmp1 = copy(arg,index+1,length(arg)-index);

    delete[] arg.str;
    arg.str = new char[tmp0.length+source.length+tmp1.length+1];
    strcpy(arg.str,tmp0.str);
    strcat(arg.str,source.str);
    strcat(arg.str,tmp1.str);

}

void Delete(string& arg,int index,int count){

    string tmp0 = copy(arg,0,index);
    string tmp1 = copy(arg,index+count,length(arg)-index);

    if(index==0){
        arg = tmp1;
        return;
    }
    else if(index+count >= length(arg)){
        arg = tmp0;
        return;
    }

    delete[] arg.str;
    arg.str = new char[tmp0.length+tmp1.length+1];

    strcpy(arg.str,tmp0.str);
    strcat(arg.str,tmp1.str);

}


int main(){

    string str1,str2;
    str1>>std::cin;
    str2>>std::cin;

    char* p;
    while(p = strstr(str1.get(),str2.get())){
        Delete(str1,pos(str1,str2),length(str2));
        p = str1.get();
    }

    str1<<std::cout;

}
