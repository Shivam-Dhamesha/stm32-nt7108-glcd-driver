#ifndef DATA_H
#define DATA_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Declaration of the logo bitmap (64x64 pixels, 1 byte per pixel)
extern const uint8_t logo[64][64];
extern const uint8_t thermometer_icon[15][15];
extern const uint8_t rh_icon[15][15];


#ifdef __cplusplus
}
#endif

#endif // DATA_H
