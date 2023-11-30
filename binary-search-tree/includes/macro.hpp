# ifndef __MACRO_HPP__
# define __MACRO_HPP__

#define LOCATION __FILE__, __FUNCTION__, __LINE__
#define REPORT_ERROR { printf( "Error: %s(%s):%d\n", LOCATION ); exit(EXIT_FAILURE); }
#define ROOT        0
#define LEFT_CHILD  1
#define RIGHT_CHILD 2
#define ARRAY_LENGTH 100000

#endif
