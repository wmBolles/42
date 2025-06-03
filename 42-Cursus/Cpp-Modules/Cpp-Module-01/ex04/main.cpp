#include <iostream>
#include <fstream>

void    replace(std::string& line, std::string s1, std::string s2)
{
    std::string temp;
    size_t  pos = line.find(s1);
    while (pos != std::string::npos) {
        temp = line.substr(0, pos);
        temp.append(s2);
        temp.append(line.substr(pos + s1.length()));
        line = temp;
        pos = line.find(s1, pos + s2.length());
    }
}
void    search_and_replace(std::string filename, std::string s1, std::string s2)
{
    if (filename == "" || s1 == "")
    {
        std::cout << "Empty Filename/s1 !" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::ifstream inFile(filename);
    std::ofstream outFile(filename + ".replace");
    if (inFile.fail() || outFile.fail()) {
        std::cout << "failed to open/create file !" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (getline(inFile, line))
    {
        if (s1 == "\n")
            line = "\n";
        replace(line, s1, s2);
        outFile << line;
        if (!inFile.eof())
            outFile << std::endl;
    }
}

int main(int ac, char *av[])
{
    if (ac == 4)
        search_and_replace(av[1], av[2], av[3]);
    else std::cout << "Invalid arguments !\n";
}