#pragma once


#define SDLA_VERSION_MAJOR 0
#define SDLA_VERSION_MINOR 0
#define SDLA_VERSION_PATCH 0




#define SDLA_API_EXPORT __attribute__((__visibility__("default")))
#define SDLA_API_IMPORT __attribute__((__visibility__("default")))


#if defined (SDLA_API_EXPORTS)

#define SDLA_API SDLA_API_EXPORT

#else

#define SDLA_API SDLA_API_IMPORT

#endif


#define MOBJECT_COUNT_PER_SCENE_PROBABLY 32
