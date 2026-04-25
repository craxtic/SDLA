#pragma 

#include <cstdio>


#define check_null_unlikely(condition, msg) do{ \
  if(!condition) [[unlikely]] { \
    std::perror(msg); \
  } \
}while(0)


// #define check_null_unlikely(condition, msg, return_stm) do{ 
//   if(!condition) [[unlikely]] { 
//     std::perror(msg); 
//   } 
// }while(0)