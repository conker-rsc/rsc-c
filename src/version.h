#ifndef _H_VERSION
#define _H_VERSION

#define VERSION_CONFIG 55
#define VERSION_ENTITY 13
#define VERSION_FILTER 2
#define VERSION_MAPS 33
#if defined(ANDROID)
#define VERSION_MEDIA 59
#else
#define VERSION_MEDIA 33
#endif
#define VERSION_MODELS 16
#define VERSION_SOUNDS 1
#define VERSION_TEXTURES 17

#define ENTITY_IS_TGA(x)     ((x) < 9)
#define MEDIA_IS_TGA(x)      ((x) < 28)

#define HAS_SEPARATE_LAND(x) ((x) > 27)

#endif
