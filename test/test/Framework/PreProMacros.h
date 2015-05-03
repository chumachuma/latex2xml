#ifndef PREPROMACROS_SOME_INLINE_FUNCTIONALITIES
#define PREPROMACROS_SOME_INLINE_FUNCTIONALITIES

#define print(stringLiteral) std::cout << stringLiteral << std::endl
#define m_print(stringLiteral) print(stringLiteral)

#define glue(code1,code2) code1 ## code2

#define strLiteral(code) #code
#define m_strLiteral(code) strLiteral(code)

#define hline "-------------------------------------------------------------------------------" //79 dashes
#define newline std::cout << std::endl

#endif