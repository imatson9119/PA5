#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>

class ItemNotFoundException : public std::runtime_error {
public:
	ItemNotFoundException() : std::runtime_error("ItemNotFoundException") { }
};

#endif