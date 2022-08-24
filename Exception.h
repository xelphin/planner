#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <exception>


class InvalidLength : public std::exception {
private:
    int m_minLength;
    int m_maxLength;
    int m_length;
    std::string* m_msg;
public:
    explicit InvalidLength(const int minLength, const int maxLength, const int length) : 
        m_minLength(minLength),
        m_maxLength(maxLength),
        m_length(length)
    {
        m_msg = new std::string(std::string("Invalid Length: Needs to be between ") 
                    + std::to_string(m_minLength)
                    + std::string(" to ") 
                    + std::to_string(m_maxLength)
                    + std::string(" , your was ")
                    + std::to_string(length)
                    + std::string(" characters long ")  );
    }
    const char* what() const noexcept override {
        return (*m_msg).c_str();
    }
    ~InvalidLength() override {
        delete m_msg;
    }
};

class InvalidDate : public std::exception {
public:
    const char* what() const noexcept override {
        return "This date doesn't exist.";
    }
};

class InvalidFormatOfRepetitionArray : public std::exception {
public:
    const char* what() const noexcept override {
        return "The array format is incorrect.";
    }
};

class ArrayValueIsTooLarge : public std::exception {
public:
    const char* what() const noexcept override {
        return "The value in the array is too large or written inappropriately.";
    }
};

class TooManyValuesInString : public std::exception {
public:
    const char* what() const noexcept override {
        return "There are too many values in the string. Larger array required.";
    }
};
class TooLittleValuesInString : public std::exception {
public:
    const char* what() const noexcept override {
        return "There are too little values in the string. Smaller array required.";
    }
};


#endif // EXCEPTION_H