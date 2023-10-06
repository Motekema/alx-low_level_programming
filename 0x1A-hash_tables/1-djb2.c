#include "hash_tables.h"

/**
* hash_djb2 - function that generates random number through
* a string given (hash numbers)
*
* @str: strings
* Return: hash numbers
*/
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash_;
int f;

hash_ = 5381;
while ((f = *str++))
{
hash_ = ((hash_ << 5) + hash_) +f; /* hash_ * 33 + f */
}
return (hash_);
}
