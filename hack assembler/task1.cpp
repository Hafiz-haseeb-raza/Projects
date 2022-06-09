#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream(file1);
ofstream(file2);
string removecomments(string line1)
{
    auto p = line1.find("/");
    string s;
    s = line1.substr(0, p);
    return s;
}
void computeDestination(string str1)
{
    if (str1 == "\0")
    {
        file2 << "000";
    }
    else if (str1 == "M")
    {
        file2 << "001";
    }
    else if (str1 == "D")
    {
        file2 << "010";
    }
    else if (str1 == "MD")
    {
        file2 << "011";
    }
    else if (str1 == "A")
    {
        file2 << "100";
    }
    else if (str1 == "AM")
    {
        file2 << "101";
    }
    else if (str1 == "AD")
    {
        file2 << "110";
    }
    else if (str1 == "AMD")
    {
        file2 << "111";
    }
}
void compJump(string str3)
{
    if (str3 == "\0")
    {
        file2 << "000";
    }
    else if (str3 == "JGT")
    {
        file2 << "001";
    }
    else if (str3 == "JEQ")
    {
        file2 << "010";
    }
    else if (str3 == "JGE")
    {
        file2 << "011";
    }
    else if (str3 == "JLT")
    {
        file2 << "100";
    }
    else if (str3 == "JNE")
    {
        file2 << "101";
    }
    else if (str3 == "JLE")
    {
        file2 << "110";
    }
    else if (str3 == "JMP")
    {
        file2 << "111";
    }
}

void computeComputation(string str2)
{
    if (str2.find("M") != string::npos)
    {
        file2 << "1";
        if (str2 == "D|M")
        {
            file2 << "010101";
        }
        else if (str2 == "D&M")
        {
            file2 << "000000";
        }
        else if (str2 == "M-D")
        {
            file2 << "000111";
        }
        else if (str2 == "D-M")
        {
            file2 << "010011";
        }
        else if (str2 == "D+M")
        {
            file2 << "000010";
        }
        else if (str2 == "M-1")
        {
            file2 << "110010";
        }
        else if (str2 == "M+1")
        {
            file2 << "110111";
        }
        else if (str2 == "-M")
        {
            file2 << "110011";
        }
        else if (str2 == "!M")
        {
            file2 << "110001";
        }
        else if (str2 == "M")
        {
            file2 << "110000";
        }
    }
    else if (str2.find("M") == string::npos)
    {
        file2 << "0";
        if (str2 == "D|A")
        {
            file2 << "010101";
        }
        else if (str2 == "D&A")
        {
            file2 << "000000";
        }
        else if (str2 == "A-D")
        {
            file2 << "000111";
        }
        else if (str2 == "D+A")
        {
            file2 << "000010";
        }
        else if (str2 == "A-1")
        {
            file2 << "110010";
        }
        else if (str2 == "D-1")
        {
            file2 << "001110";
        }
        else if (str2 == "A+1")
        {
            file2 << "110111";
        }
        else if (str2 == "D+1")
        {
            file2 << "011111";
        }
        else if (str2 == "-A")
        {
            file2 << "110011";
        }
        else if (str2 == "-D")
        {
            file2 << "001111";
        }
        else if (str2 == "!A")
        {
            file2 << "110001";
        }
        else if (str2 == "!D")
        {
            file2 << "001101";
        }
        else if (str2 == "A")
        {
            file2 << "110000";
        }
        else if (str2 == "D")
        {
            file2 << "001100";
        }
        else if (str2 == "-1")
        {
            file2 << "111010";
        }
        else if (str2 == "1")
        {
            file2 << "111111";
        }
        else if (str2 == "0")
        {
            file2 << "101010";
        }
    }
}
void DecimalToBinary(int p)
{
    int arr[15];
    for (int i = 0; i <= 14; i++)
    {
        arr[i] = p % 2;
        p = p / 2;
    }
    file2 << "0";
    for (int i = 14; i >= 0; i--)
    {
        file2 << arr[i];
    }
    file2 << endl;
}
void convertAInstruction(string line)
{

    string str;
    str = line.substr(1, line.length());
    int p = stoi(str);

    DecimalToBinary(p);
}
void printstr(string str1, string str2, string str3)
{
    cout << str1 << "\n"
         << str2 << "\n"
         << str3 << "\n";
}
void convertCInstruction(string line)
{
    file2 << "111";
    if (line.find("=") != string::npos && line.find(";") != string::npos)
    {
        int p = line.find("=");
    
        string str1 = line.substr(0, p);
        int c = line.find(";");
        string str2 = line.substr(0, c);
        str2.erase(0, p + 1);
        string str3 = line.substr(c + 1, line.length());
        printstr(str1, str2, str3);
        computeComputation(str2);
        computeDestination(str1);
        compJump(str3);
        file2<<"\n";

        //exit(0);
    }

    else if (line.find("=") == string::npos && line.find(";") != string::npos)
    {
        
       
        string str1 = "\0";

        int c = line.find(";");
        string str2 = line.substr(0, c);
        string str3 = line.substr(c + 1, line.length());
        printstr(str1, str2, str3);
        computeComputation(str2);
        computeDestination(str1);
        compJump(str3);
         file2<<"\n";
    }
    else if (line.find("=") == string::npos && line.find(";") == string::npos)
    {
        string str1 = "\0";
        file2 << "111";
        string str2 = line.substr(0, line.length());
        string str3 = "\0";
        printstr(str1, str2, str3);
        computeComputation(str2);
        computeDestination(str1);
        compJump(str3);
         file2<<"\n";
    }
    else if(line.find("=") != string::npos && line.find(";") == string::npos){
        int p=line.find("=");
        string str1=line.substr(0,p);
        string str2=line.substr(p+1,line.length());
        string str3="\0";
        printstr(str1, str2, str3);
        computeComputation(str2);
        computeDestination(str1);
        compJump(str3);
        file2<<"\n";        
    }
}



int main()
{
    file1.open("haseeb.asm");
    file2.open("usama.hack");
    string line;
    getline(file1, line);
    while (file1)
    {
        line = removecomments(line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        if (line.empty())
        {
            getline(file1, line);
            continue;
        }
        if (line[0] == '@')
        {
            convertAInstruction(line);
        } /*else{
            file2<<line<<endl;
        }*/
        else
        {
            convertCInstruction(line);
        }

        getline(file1, line);
    }
    return 0;
}
