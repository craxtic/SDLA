#pragma once


#define AXIM_VERSION_MAJOR 0
#define AXIM_VERSION_MINOR 0
#define AXIM_VERSION_PATCH 0



#define AXIM_API_EXPORT __attribute__((__visibility__("default")))
#define AXIM_API_IMPORT __attribute__((__visibility__("default")))


#if defined (AXIM_API_EXPORTS)

#define AXIM_API AXIM_API_EXPORT

#else

#define AXIM_API AXIM_API_IMPORT

#endif


#define MOBJECT_COUNT_PER_SCENE_PROBABLY 32
