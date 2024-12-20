#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
#if 1
    string str = "D:\hello\world\test.text";
    cout << str << endl;
    string str1 = "D:\\hello\\world\\test.text";
    cout << str1 << endl;

    string str2 = "<html>\
            <head>\
            <title>\
            海贼王\
            </title>\
            </head>\
            <body>\
            <p>\
            我是要成为海贼王的男人!!!\
            </p>\
            </body>\
            </html>";
            cout << str2 << endl;

#else
     string str1 = R"(D:\hello\world\test.text)";
    cout << str1 << endl;

    string str2 = R"(<html>\
            <head>\
            <title>\
            海贼王\
            </title>\
            </head>\
            <body>\
            <p>\
            我是要成为海贼王的男人!!!\
            </p>\
            </body>\
            </html>)";
            cout << str2 << endl;

#endif
        return 0;
}