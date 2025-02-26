/*-------------------------------------------------------------------------------------------------
File:      nume file
Description: descirere file
-------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
Macros
-------------------------------------------------------------------------------------------------*/
#ifndef COMMONH
#define COMMONH

/* Error message color codes for CLI - cmd / powershell*/
#define COLOR_RED "\x1b[91m"
#define COLOR_RESET "\x1b[0m" 
#define COLOR_GRAY "\x1b[37m" 
#define COLOR_MAGENTA "\x1b[95m" 
#define COLOR_GREEN "\x1b[32m"

#define ctoi(X) ((X)-'0') /* character X converted to integer */

typedef unsigned char uint8;
typedef unsigned short  uint16;
typedef unsigned int  uint32;
typedef float uint64; /* this is 32b , not 64 */
typedef enum { false=0, true=1 } bool;
#endif
/*-------------------------------------------------------------------------------------------------
Functions/interfaces
-------------------------------------------------------------------------------------------------*/

