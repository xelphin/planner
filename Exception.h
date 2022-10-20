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
                    + std::string(" , your is ")
                    + std::to_string(length)
                    + std::string(" characters long "));
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


class StringIsNotOfArrayFormat : public std::exception {
public:
    const char* what() const noexcept override {
        return "The string is not in the format of a proper array.";
    }
};

class MissingElemInArrayString : public std::exception {
public:
    const char* what() const noexcept override {
        return "Missing element in array string.";
    }
};

class InvalidCharacterAfterBackSlash : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid character after backslash, may only be: \", \\, n.";
    }
};

class InvalidCharacterInString : public std::exception {
private:
    int m_indexOfChar;
    char m_invalidChar;
    std::string* m_msg;
public:
    explicit InvalidCharacterInString(const int index, const char chr) : 
        m_indexOfChar(index),
        m_invalidChar(chr)
    {
        m_msg = new std::string(std::string("Invalid Character: ") 
                    + std::to_string(m_invalidChar)
                    + std::string(" found at index ") 
                    + std::to_string(m_indexOfChar));
    }
    const char* what() const noexcept override {
        return (*m_msg).c_str();
    }
    ~InvalidCharacterInString() override {
        delete m_msg;
    }
};


// DATABASE EXCEPTIONS
class InvalidDatabaseFormat_Year : public std::exception {
private:
    int m_minLength;
    int m_maxLength;
    int m_length;
    std::string* m_msg;
public:
    explicit InvalidDatabaseFormat_Year(const int minLength, const int maxLength, const int length) : 
        m_minLength(minLength),
        m_maxLength(maxLength),
        m_length(length)
    {
        m_msg = new std::string(std::string("First line in database.txt should be year between ") 
                    + std::to_string(m_minLength)
                    + std::string(" to ") 
                    + std::to_string(m_maxLength)
                    + std::string(" , your first line is ")
                    + std::to_string(length));
    }
    const char* what() const noexcept override {
        return (*m_msg).c_str();
    }
    ~InvalidDatabaseFormat_Year() override {
        delete m_msg;
    }
};

// CALENDAR EXCEPTIONS
class NoSelectedPoint : public std::exception {
public:
    const char* what() const noexcept override {
        return "No point is selected.";
    }
};
class AttemptToRemoveFromEmptyCalendar : public std::exception {
public:
    const char* what() const noexcept override {
        return "Removing from an empty Calendar is an invalid action.";
    }
};

class CorruptedFile_InvalidPointType : public std::exception {
private:
    int m_line;
    std::string m_input;
    std::string* m_msg;
public:
    explicit CorruptedFile_InvalidPointType(const int line, const std::string& input) : 
        m_line(line),
        m_input(input)
    {
        m_msg = new std::string(std::string("Options for Point Type are: ")
                    + std::string(" \"Event\", \"Task\" and \"Reminder\". ")
                    + std::string(" At line: ")
                    + std::to_string(m_line)
                    + std::string(" , the input is: ") 
                    + m_input);
    }
    const char* what() const noexcept override {
        return (*m_msg).c_str();
    }
    ~CorruptedFile_InvalidPointType() override {
        delete m_msg;
    }
};

class CorruptedFile_InvalidAmountOfElements : public std::exception {
private:
    int m_lineIndex;
    int m_wanted;
    int m_got;
    std::string* m_msg;
public:
    explicit CorruptedFile_InvalidAmountOfElements(const int lineIndex, const int wanted, const int got) : 
        m_lineIndex(lineIndex),
        m_wanted(wanted),
        m_got(got)
    {
        m_msg = new std::string(std::string("Invalid amount of elements in array: ")
                    + std::string(" wanted: ")
                    + std::to_string(m_wanted)
                    + std::string(" received: ") 
                    + std::to_string(m_got));
    }
    const char* what() const noexcept override {
        return (*m_msg).c_str();
    }
    ~CorruptedFile_InvalidAmountOfElements() override {
        delete m_msg;
    }
};
class InvalidPointFormat : public std::exception {
public:
    const char* what() const noexcept override {
        return "The string/int format is incorrect.";
    }
};


#endif // EXCEPTION_H