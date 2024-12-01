#include "filehandler.hpp"


std::ifstream h_read_file(char* name)
{
    std::ifstream f; 
    f.open(name);

    if(f.is_open())
    {
        printf("[%s] opened succesfully\n", name);
    }
    else
    {
        printf("Failed to open file [%s]\n", name);
    }

    return f;
}

int h_read_line(std::ifstream &f, std::string &str)
{
    if(!f.is_open())
    {
        printf("Cannot access file\n");
        return -1;
    }

    str.clear();

    std::getline(f, str);

   // printf("Line read: %s \n", str.c_str());

    return str.length();
}