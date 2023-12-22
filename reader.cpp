#include "reader.h"


std::vector<std::string> split(const std::string& str,const char sep) {
    std::vector<std::string> SplitString;
    std::stringstream line(str);
    std::string value;
    while (std::getline(line, value, sep)) {
        SplitString.push_back(value);
    }
    return SplitString;
}


std::vector<std::vector<double>> parsing(const std::string& filename, const char sep) {
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileOpenException("Can't open file!");
    }

    
    std::string column_name;
    std::getline(file, column_name);
    std::vector<std::string> colNames = split(column_name, sep);
    for (auto column_name : colNames) {
        std::cout << column_name << sep;
    }
    std::cout << std::endl;
    
    std::vector<std::vector<double>> dataframe;
    while (std::getline(file, column_name)) {
        std::vector<std::string> values = split(column_name, sep);
        std::vector<double> row;
        for (auto value : values) {
            try {
                double number = std::stod(value);
                row.push_back(number);
            }
            catch (const std::invalid_argument& e) {
                throw ParsingException("Invalid data format: " + value);
            }
        }
        if (row.size() != colNames.size()) {
            throw ParsingException("Number of values does not match number of columns.");
        }
        dataframe.push_back(row);
    }

    
    file.close();

    return dataframe;
}

void reader::readcsv(const std::string& filename, const char sep)
{
    this->Setfilename(filename);

    try {
        std::vector<std::vector<double>> data = parsing(this->Getfilename(), sep);

        for (auto row : data) {
            for (auto value : row) {
                std::cout << value << sep;
            }
            std::cout << std::endl;
        }
    }
    catch (const FileOpenException& e) {
        std::cout << "Error opening the file: " << e.what() << std::endl;
    }
    catch (const ParsingException& e) {
        std::cout << "Error parsing the file: " << e.what() << std::endl;
    }
}