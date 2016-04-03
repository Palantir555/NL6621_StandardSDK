#ifndef TYPES_DEF_H_
#define TYPES_DEF_H_

#include <stdint.h>

#define IN
#define OUT
#define INOUT

#ifndef PACKED 

#ifndef GCC
#define PACKED __packed
#else
#define PACKED __attribute__((packed))
#endif


#ifdef GCC
#define PACKED_STRUCT_COMPAT struct __attribute__((packed))
#define PACKED_UNION_COMPAT  union  __attribute__((packed))
#else /* __packed attribute for Keil */
#define PACKED_STRUCT_COMPAT __packed struct
#define PACKED_UNION_COMPAT  __packed union
#endif /* GCC */

#endif /* PACKED */

#ifndef NULL
#define NULL                0
#endif

#ifndef INLINE
#ifdef __GNUC__
/** inline directive */
#define    INLINE    inline
#else
/** inline directive */
#define    INLINE    __inline
#endif
#endif

typedef signed char         INT8;
typedef unsigned char       UINT8;
typedef signed short int    INT16;
typedef unsigned short int  UINT16;
typedef signed int          INT32;
typedef unsigned int        UINT32;
typedef volatile unsigned long    VUINT32;
typedef volatile unsigned long  const VUC32;  /* Read Only */
typedef volatile UINT16         VUINT16;
typedef volatile UINT16  const VUC16;  /* Read Only */

typedef unsigned char *       PUINT8;
typedef unsigned short int *    PUINT16;
typedef unsigned int *       PUINT32;

#ifndef BOOL_T
typedef unsigned char       BOOL_T;
#endif

#ifndef VOID
#define     VOID              void  
//typedef void                VOID;
typedef void *                PVOID;
#endif

typedef char *                PSTRING;
typedef char    STRING;

#define NST_FALSE                              0
#define NST_TRUE                               1

typedef uint64_t        UINT64;

typedef union _LARGE_INTEGER
{
    struct 
    {
        UINT32 LowPart;
        UINT32 HighPart;
    } u;
    int64_t QuadPart;
} LARGE_INTEGER;


#endif /*TYPES_DEF_H_*/
