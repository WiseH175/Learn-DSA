#include<iostream>
using namespace std;

int main()
{
    // cout << "Enter String: ";
    // string a;
    // cin >> a;                                 // If you input 2 words, cin picks only first word. 
    // cout << a << endl;

    string s1 = "Hello";
    string s2 = "World";
    string res = s1 + s2;                        // Concatenate strings
    cout << res << endl;

    s1[0] = 'M';                                // Changes value of 1st letter of s1
    cout << s1 << endl;

    cout << s1.size() <<endl;                   //Size of string s1

    string s3;
    cout << "Enter String: ";
    getline(cin, s3);                           //Take input of whole line
    cout << s3;


    return 0;
}