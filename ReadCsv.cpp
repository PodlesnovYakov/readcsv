#include "reader.h"

int main() {
    reader Solve;
    std::cout << "Input file name."<< std::endl;
    std::string filename;
    std::getline(std::cin, filename);
    const char comma = ',';
    const char tab = '\t';
    int choicesep;
    bool Rightchoice = true;
    while (Rightchoice) {
    std::cout << "Input separator of your file." << std::endl <<
        "0 - comma (,) separator" << std::endl <<
        "1 - tab (4 spaces) separator." << std::endl;
    std::cin >> choicesep;
        if (choicesep == 0)
        {
            Solve.readcsv(filename, comma);
            Rightchoice = false;
        }
        else if (choicesep == 1) {
            Solve.readcsv(filename, tab);
            Rightchoice = false;
        }
        else {
            std::cout << "You chose the wrong number" << std::endl;
        }
    }
    return 0;
}
