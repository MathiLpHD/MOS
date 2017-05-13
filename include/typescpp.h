#ifndef TYPESCPP_H
#define TYPESCPP_H

/*
*	General C-Types
*/
typedef unsigned char 	u8;
typedef unsigned short 	u16;
typedef unsigned int 	u32;
typedef unsigned long long 	u64;


typedef signed char 	s8;
typedef signed short 	s16;
typedef signed int 		s32;
typedef signed long long	s64;


typedef unsigned char u_char;

typedef int pid_t;
typedef s64 ino_t;
typedef s64 off_t;
typedef int dev_t;
typedef int mode_t;
typedef int nlink_t;
typedef int uid_t;
typedef int gid_t;
typedef int blksize_t;
typedef s64 blkcnt_t;
#define time_t s64

struct stat_fs
{
	dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	off_t st_size;
	blksize_t st_blksize;
	blkcnt_t st_blocks;
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
};


/*
* Return code
*/
enum
{
	RETURN_OK = 0,
	NOT_DEFINED = -1, //If not implemented
	ERROR_MEMORY = -2,
	PARAM_NULL = -3,
	ERROR_PARAM = -4,
	RETURN_FAILURE = -128 //Added by NoMaintener aka William. In case of error
};

enum class Color
{
	Black = 0x00,
	Blue = 0x01,
	Green = 0x02,
	Cyan = 0x03,
	Red = 0x04,
	Magenta = 0x05,
	Brown = 0x06,
	LightGray = 0x07,
	DarkGray = 0x08,
	LightBlue = 0x09,
	LightGreen = 0x0A,
	LightCyan = 0x0B,
	LightRed = 0x0C,
	LightMagenta = 0x0D,
	Yellow = 0x0E,
	White = 0x0F
};

/*
*	Interruption handler
*/
typedef void(*int_handler)(void);


#define true 1
#define false 0

typedef unsigned char 	uchar;
typedef unsigned short 	ushort;
typedef unsigned int 	uint;
typedef unsigned long long 	ulong;

typedef unsigned char byte;

#endif