# chapter 2 notes

reminder: this text refers to local variables as "automatic" variables because they come into existence automatically when a function is called, and disappear when the function is exited.

## enumerations

enums are often an alternative to symbolic constants (which use #define). some advantages of enums are that their values can be auto-generated (0, 1, 2...) and compilers can check whether an enum's value is valid.

## convert hex to int

read in character array of ascii symbols from 1...9, a...f, A...F. each symbol represents 4 bits. the same symbol can equate to a different integer value depending on which 4 bit "slot" it's found in.

## increment and decrement

the ++ and -- operators may be used as either a prefix or postfix. but when used as a prefix, the value is adjusted _before_ it's used, whereas with a postfix the adjustment happens after.

so if n = 5: 

x = ++n sets x to 6
x = n++ sets x to 5

either way, n is incremented.
