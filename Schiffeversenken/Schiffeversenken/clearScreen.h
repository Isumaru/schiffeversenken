#if WIN32
#define CLEAR system( "cls" )
#else if LINUX
#define CLEAR system( "clear" )
#endif
