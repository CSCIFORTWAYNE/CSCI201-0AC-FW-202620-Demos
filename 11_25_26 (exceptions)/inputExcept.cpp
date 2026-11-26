#include "inputExcept.h"

Input_Exception::Input_Exception() : std::runtime_error("Input Failure detected. Resetting stream.")
{
    needStreamReset = true;
}

Input_Exception::Input_Exception(std::string error, bool needStreamReset) : std::runtime_error(error)
{
    this->needStreamReset = needStreamReset;
}

void Input_Exception::setStreamReset(bool needStreamReset)
{
    this->needStreamReset = needStreamReset;
}

bool Input_Exception::hasStreamReset() const
{
    return needStreamReset;
}