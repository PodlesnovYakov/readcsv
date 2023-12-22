#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>
class reader
{
public:
    void readcsv(const std::string& filename, const char sep);
    void Setfilename(const std::string& _filename) {
        filename = _filename;
    }
    const std::string& Getfilename() {
        return filename;
    }
private:
    std::string filename;
};

class ParsingException : public std::exception {
private:
    std::string message;
public:
    ParsingException(const std::string& error) : message(error) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileOpenException : public std::exception {
private:
    std::string message;
public:
    FileOpenException(const std::string& error) : message(error) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

