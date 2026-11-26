#ifndef INPUTE_H
#define INPUTE_H
#include <stdexcept>

class Input_Exception : public std::runtime_error
{
public:
    Input_Exception();
    Input_Exception(std::string error, bool needStreamReset);
    void setStreamReset(bool needStreamReset);
    bool hasStreamReset() const;

private:
    bool needStreamReset;
};

#endif