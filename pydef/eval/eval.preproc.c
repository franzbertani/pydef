#1 "eval.c"
#1 "<built-in>" 1
#1 "<built-in>" 3
#362 "<built-in>" 3
#1 "<command line>" 1
#1 "<built-in>" 2
#1 "eval.c" 2
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 1 3 4
#64 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 1 3 4
#68 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 1 3 4
#626 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h" 1 3 4
#627 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2 3 4
#692 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h" 1 3 4
#693 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2 3 4
#69 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 1 3 4
#246 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h" 1 3 4
#247 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 2 3 4
#70 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h" 1 3 4
#27 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 1 3 4
#33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/_types.h" 1 3 4
#37 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/_types.h" 3 4
typedef signed char __int8_t;

typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
#70 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/_types.h" 3 4
typedef int __darwin_ct_rune_t;

typedef union {
  char __mbstate8[128];
  long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;

typedef long int __darwin_ptrdiff_t;

typedef long unsigned int __darwin_size_t;

typedef __builtin_va_list __darwin_va_list;

typedef int __darwin_wchar_t;

typedef __darwin_wchar_t __darwin_rune_t;

typedef int __darwin_wint_t;

typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
#33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h" 2 3 4
#34 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 2 3 4
#55 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 3 4
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;

typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h" 1 3 4
#57 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h" 3 4
struct __darwin_pthread_handler_rec {
  void (*__routine)(void *);
  void *__arg;
  struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
  long __sig;
  char __opaque[56];
};

struct _opaque_pthread_cond_t {
  long __sig;
  char __opaque[40];
};

struct _opaque_pthread_condattr_t {
  long __sig;
  char __opaque[8];
};

struct _opaque_pthread_mutex_t {
  long __sig;
  char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
  long __sig;
  char __opaque[8];
};

struct _opaque_pthread_once_t {
  long __sig;
  char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
  long __sig;
  char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
  long __sig;
  char __opaque[16];
};

struct _opaque_pthread_t {
  long __sig;
  struct __darwin_pthread_handler_rec *__cleanup_stack;
  char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;
#81 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 2 3 4
#28 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h" 2 3 4
#40 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h" 3 4
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;
#72 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h" 1 3 4
#35 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 1 3 4
#76 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h" 3 4
typedef signed char int8_t;
#77 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h" 3 4
typedef short int16_t;
#78 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h" 3 4
typedef int int32_t;
#79 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h" 3 4
typedef long long int64_t;
#80 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h" 3 4
typedef unsigned char u_int8_t;
#82 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h" 3 4
typedef unsigned short u_int16_t;
#83 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h" 3 4
typedef unsigned int u_int32_t;
#84 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h" 3 4
typedef unsigned long long u_int64_t;
#85 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4

typedef int64_t register_t;

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h" 2 3 4

typedef __darwin_intptr_t intptr_t;
#93 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h" 3 4
typedef unsigned long uintptr_t;
#94 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/i386/types.h" 2 3 4

typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;

typedef u_int64_t syscall_arg_t;
#36 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h" 2 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h" 2 3 4
typedef __darwin_va_list va_list;
#76 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 3 4
typedef __darwin_size_t size_t;
#77 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h" 1 3 4
#78 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h" 1 3 4
#39 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h" 3 4
int renameat(int, const char *, int, const char *) __attribute__((availability(macosx, introduced = 10.10)));

int renamex_np(const char *, const char *, unsigned int) __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0)));
int renameatx_np(int, const char *, int, const char *, unsigned int) __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0)));
#80 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 2 3 4

typedef __darwin_off_t fpos_t;
#92 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 3 4
struct __sbuf {
  unsigned char *_base;
  int _size;
};

struct __sFILEX;
#126 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h" 3 4
typedef struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;

  void *_cookie;
  int(*_Nullable _close)(void *);
  int(*_Nullable _read) (void *, char *, int);
  fpos_t(*_Nullable _seek) (void *, fpos_t, int);
  int(*_Nullable _write)(void *, const char *, int);

  struct __sbuf _ub;
  struct __sFILEX *_extra;
  int _ur;

  unsigned char _ubuf[3];
  unsigned char _nbuf[1];

  struct __sbuf _lb;

  int _blksize;
  fpos_t _offset;
} FILE;
#65 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 2 3 4

extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
#142 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE *restrict, fpos_t *);
char *fgets(char *restrict, int, FILE *);

FILE *fopen(const char *restrict __filename, const char *restrict __mode) __asm("_" "fopen");

int fprintf(FILE *restrict, const char *restrict, ...) __attribute__((__format__(__printf__, 2, 3)));
int fputc(int, FILE *);
int fputs(const char *restrict, FILE *restrict) __asm("_" "fputs");
size_t fread(void *restrict __ptr, size_t __size, size_t __nitems, FILE *restrict __stream);
FILE *freopen(const char *restrict, const char *restrict,
              FILE *restrict) __asm("_" "freopen");
int fscanf(FILE *restrict, const char *restrict, ...) __attribute__((__format__(__scanf__, 2, 3)));
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void *restrict __ptr, size_t __size, size_t __nitems, FILE *restrict __stream) __asm("_" "fwrite");
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *) __attribute__((__cold__));
int printf(const char *restrict, ...) __attribute__((__format__(__printf__, 1, 2)));
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename(const char *__old, const char *__new);
void rewind(FILE *);
int scanf(const char *restrict, ...) __attribute__((__format__(__scanf__, 1, 2)));
void setbuf(FILE *restrict, char *restrict);
int setvbuf(FILE *restrict, char *restrict, int, size_t);
int sprintf(char *restrict, const char *restrict, ...) __attribute__((__format__(__printf__, 2, 3))) __attribute__((__availability__(swift, unavailable, message = "Use snprintf instead.")));
int sscanf(const char *restrict, const char *restrict, ...) __attribute__((__format__(__scanf__, 2, 3)));
FILE *tmpfile(void);

__attribute__((__availability__(swift, unavailable, message = "Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tmpnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE *restrict, const char *restrict, va_list) __attribute__((__format__(__printf__, 2, 0)));
int vprintf(const char *restrict, va_list) __attribute__((__format__(__printf__, 1, 0)));
int vsprintf(char *restrict, const char *restrict, va_list) __attribute__((__format__(__printf__, 2, 0))) __attribute__((__availability__(swift, unavailable, message = "Use vsnprintf instead.")));
#205 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h" 1 3 4
#26 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h" 3 4
char *ctermid(char *);
#206 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 2 3 4

FILE *fdopen(int, const char *) __asm("_" "fdopen");

int fileno(FILE *);
#228 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
int pclose(FILE *) __attribute__((__availability__(swift, unavailable, message = "Use posix_spawn APIs or NSTask instead.")));

FILE *popen(const char *, const char *) __asm("_" "popen") __attribute__((__availability__(swift, unavailable, message = "Use posix_spawn APIs or NSTask instead.")));
#249 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
int __srget(FILE *);
int __svfscanf(FILE *, const char *, va_list) __attribute__((__format__(__scanf__, 2, 0)));
int __swbuf(int, FILE *);
#260 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
inline __attribute__ ((__always_inline__)) int
__sputc(int _c, FILE *_p)
{
  if(--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n')) {
    return *_p->_p++ = _c;
  } else {
    return __swbuf(_c, _p);
  }
}
#286 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);

int getw(FILE *);
int putw(int, FILE *);

__attribute__((__availability__(swift, unavailable, message = "Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tempnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tempnam(const char *__dir, const char *__prefix) __asm("_" "tempnam");
#324 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h" 3 4
typedef __darwin_off_t off_t;
#325 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 2 3 4

int fseeko(FILE *__stream, off_t __offset, int __whence);
off_t ftello(FILE *__stream);

int snprintf(char *restrict __str, size_t __size, const char *restrict __format, ...) __attribute__((__format__(__printf__, 3, 4)));
int vfscanf(FILE *restrict __stream, const char *restrict __format, va_list) __attribute__((__format__(__scanf__, 2, 0)));
int vscanf(const char *restrict __format, va_list) __attribute__((__format__(__scanf__, 1, 0)));
int vsnprintf(char *restrict __str, size_t __size, const char *restrict __format, va_list) __attribute__((__format__(__printf__, 3, 0)));
int vsscanf(const char *restrict __str, const char *restrict __format, va_list) __attribute__((__format__(__scanf__, 2, 0)));
#349 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h" 3 4
typedef __darwin_ssize_t ssize_t;
#350 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 2 3 4

int dprintf(int, const char *restrict, ...) __attribute__((__format__(__printf__, 2, 3))) __attribute__((availability(macosx, introduced = 10.7)));
int vdprintf(int, const char *restrict, va_list) __attribute__((__format__(__printf__, 2, 0))) __attribute__((availability(macosx, introduced = 10.7)));
ssize_t getdelim(char **restrict __linep, size_t *restrict __linecapp, int __delimiter, FILE *restrict __stream) __attribute__((availability(macosx, introduced = 10.7)));
ssize_t getline(char **restrict __linep, size_t *restrict __linecapp, FILE *restrict __stream) __attribute__((availability(macosx, introduced = 10.7)));
FILE *fmemopen(void *restrict __buf, size_t __size, const char *restrict __mode) __attribute__((availability(macos, introduced = 10.13))) __attribute__((availability(ios, introduced = 11.0))) __attribute__((availability(tvos, introduced = 11.0))) __attribute__((availability(watchos, introduced = 4.0)));
FILE *open_memstream(char **__bufp, size_t *__sizep) __attribute__((availability(macos, introduced = 10.13))) __attribute__((availability(ios, introduced = 11.0))) __attribute__((availability(tvos, introduced = 11.0))) __attribute__((availability(watchos, introduced = 4.0)));
#367 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
extern const int sys_nerr;
extern const char *const sys_errlist[];

int asprintf(char **restrict, const char *restrict, ...) __attribute__((__format__(__printf__, 2, 3)));
char *ctermid_r(char *);
char *fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *);
int fpurge(FILE *);
void setbuffer(FILE *, char *, int);
int setlinebuf(FILE *);
int vasprintf(char **restrict, const char *restrict, va_list) __attribute__((__format__(__printf__, 2, 0)));
FILE *zopen(const char *, const char *, int);

FILE *funopen(const void *,
              int (*_Nullable)(void *, char *, int),
              int (*_Nullable)(void *, const char *, int),
              fpos_t (*_Nullable)(void *, fpos_t, int),
              int (*_Nullable)(void *));
#407 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_common.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h" 2 3 4
#42 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h" 3 4
extern int __sprintf_chk(char *restrict, int, size_t,
                         const char *restrict, ...);
#52 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h" 3 4
extern int __snprintf_chk(char *restrict, size_t, int, size_t,
                          const char *restrict, ...);

extern int __vsprintf_chk(char *restrict, int, size_t,
                          const char *restrict, va_list);

extern int __vsnprintf_chk(char *restrict, size_t, int, size_t,
                           const char *restrict, va_list);
#408 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h" 2 3 4
#2 "eval.c" 2
#1 "/Library/Developer/CommandLineTools/usr/lib/clang/11.0.0/include/stdint.h" 1 3 4
#63 "/Library/Developer/CommandLineTools/usr/lib/clang/11.0.0/include/stdint.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 1 3 4
#23 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h" 3 4
typedef unsigned char uint8_t;
#24 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h" 3 4
typedef unsigned short uint16_t;
#25 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h" 3 4
typedef unsigned int uint32_t;
#26 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h" 3 4
typedef unsigned long long uint64_t;
#27 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 2 3 4

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
#58 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h" 3 4
typedef long int intmax_t;
#59 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h" 3 4
typedef long unsigned int uintmax_t;
#60 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h" 2 3 4
#64 "/Library/Developer/CommandLineTools/usr/lib/clang/11.0.0/include/stdint.h" 2 3 4
#3 "eval.c" 2
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/printf.h" 1 3 4
#49 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/printf.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 1 3 4
#76 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_mbstate_t.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_mbstate_t.h" 3 4
typedef __darwin_mbstate_t mbstate_t;
#77 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ct_rune_t.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ct_rune_t.h" 3 4
typedef __darwin_ct_rune_t ct_rune_t;
#78 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_rune_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_rune_t.h" 3 4
typedef __darwin_rune_t rune_t;
#79 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h" 1 3 4
#34 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h" 3 4
typedef __darwin_wchar_t wchar_t;
#80 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 2 3 4
#89 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 3 4
#1 "/Library/Developer/CommandLineTools/usr/lib/clang/11.0.0/include/stdarg.h" 1 3 4
#30 "/Library/Developer/CommandLineTools/usr/lib/clang/11.0.0/include/stdarg.h" 3 4
typedef __builtin_va_list va_list;
#48 "/Library/Developer/CommandLineTools/usr/lib/clang/11.0.0/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
#90 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 1 3 4
#69 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h" 3 4
typedef __darwin_clock_t clock_t;
#70 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h" 1 3 4
#31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h" 3 4
typedef __darwin_time_t time_t;
#73 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h" 1 3 4
#33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h" 3 4
struct timespec {
  __darwin_time_t tv_sec;
  long tv_nsec;
};
#74 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 2 3 4

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long tm_gmtoff;
  char *tm_zone;
};
#98 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 3 4
extern char *tzname[];

extern int getdate_err;

extern long timezone __asm("_" "timezone");

extern int daylight;

char *asctime(const struct tm *);
clock_t clock(void) __asm("_" "clock");
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *) __asm("_" "mktime");
size_t strftime(char *restrict, size_t, const char *restrict, const struct tm *restrict) __asm("_" "strftime");
char *strptime(const char *restrict, const char *restrict, struct tm *restrict) __asm("_" "strptime");
time_t time(time_t *);

void tzset(void);

char *asctime_r(const struct tm *restrict, char *restrict);
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t *restrict, struct tm *restrict);
struct tm *localtime_r(const time_t *restrict, struct tm *restrict);

time_t posix2time(time_t);

void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm *const);
time_t timegm(struct tm *const);

int nanosleep(const struct timespec *__rqtp, struct timespec *__rmtp) __asm("_" "nanosleep");
#153 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 3 4
typedef enum {
  _CLOCK_REALTIME __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 0,

  _CLOCK_MONOTONIC __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 6,

  _CLOCK_MONOTONIC_RAW __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 4,

  _CLOCK_MONOTONIC_RAW_APPROX __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 5,

  _CLOCK_UPTIME_RAW __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 8,

  _CLOCK_UPTIME_RAW_APPROX __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 9,

  _CLOCK_PROCESS_CPUTIME_ID __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 12,

  _CLOCK_THREAD_CPUTIME_ID __attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0))) = 16
} clockid_t;

__attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0)))
int clock_getres(clockid_t __clock_id, struct timespec *__res);

__attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0)))
int clock_gettime(clockid_t __clock_id, struct timespec *__tp);

__attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, introduced = 10.0))) __attribute__((availability(tvos, introduced = 10.0))) __attribute__((availability(watchos, introduced = 3.0)))
__uint64_t clock_gettime_nsec_np(clockid_t __clock_id);

__attribute__((availability(macosx, introduced = 10.12))) __attribute__((availability(ios, unavailable)))
__attribute__((availability(tvos, unavailable))) __attribute__((availability(watchos, unavailable)))
int clock_settime(clockid_t __clock_id, const struct timespec *__tp);
#198 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 3 4
__attribute__((availability(macosx, introduced = 10.15))) __attribute__((availability(ios, introduced = 13.0))) __attribute__((availability(tvos, introduced = 13.0))) __attribute__((availability(watchos, introduced = 6.0)))
int timespec_get(struct timespec *ts, int base);
#92 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_wctype.h" 1 3 4
#42 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_wctype.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/__wctype.h" 1 3 4
#60 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/__wctype.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h" 3 4
typedef __darwin_wint_t wint_t;
#61 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/__wctype.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_wctype_t.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_wctype_t.h" 3 4
typedef __darwin_wctype_t wctype_t;
#63 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/__wctype.h" 2 3 4
#72 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/__wctype.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ctype.h" 1 3 4
#69 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ctype.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctype.h" 1 3 4
#70 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctype.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/runetype.h" 1 3 4
#49 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/runetype.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h" 1 3 4
#50 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/runetype.h" 2 3 4
#60 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/runetype.h" 3 4
typedef struct {
  __darwin_rune_t __min;
  __darwin_rune_t __max;
  __darwin_rune_t __map;
  __uint32_t *__types;
} _RuneEntry;

typedef struct {
  int __nranges;
  _RuneEntry *__ranges;
} _RuneRange;

typedef struct {
  char __name[14];
  __uint32_t __mask;
} _RuneCharClass;

typedef struct {
  char __magic[8];
  char __encoding[32];

  __darwin_rune_t (*__sgetrune)(const char *, __darwin_size_t, char const **);
  int (*__sputrune)(__darwin_rune_t, char *, __darwin_size_t, char **);
  __darwin_rune_t __invalid_rune;

  __uint32_t __runetype[(1 << 8)];
  __darwin_rune_t __maplower[(1 << 8)];
  __darwin_rune_t __mapupper[(1 << 8)];

  _RuneRange __runetype_ext;
  _RuneRange __maplower_ext;
  _RuneRange __mapupper_ext;

  void *__variable;
  int __variable_len;

  int __ncharclasses;
  _RuneCharClass *__charclasses;
} _RuneLocale;

extern _RuneLocale _DefaultRuneLocale;
extern _RuneLocale *_CurrentRuneLocale;
#71 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctype.h" 2 3 4
#129 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctype.h" 3 4
unsigned long ___runetype(__darwin_ct_rune_t);
__darwin_ct_rune_t ___tolower(__darwin_ct_rune_t);
__darwin_ct_rune_t ___toupper(__darwin_ct_rune_t);

inline int
isascii(int _c)
{
  return (_c & ~0x7F) == 0;
}
#148 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctype.h" 3 4
int __maskrune(__darwin_ct_rune_t, unsigned long);

inline int
__istype(__darwin_ct_rune_t _c, unsigned long _f)
{

  return isascii(_c) ? !!(_DefaultRuneLocale.__runetype[_c] & _f)
         : !!__maskrune(_c, _f);
}
inline __darwin_ct_rune_t
__isctype(__darwin_ct_rune_t _c, unsigned long _f)
{

  return (_c < 0 || _c >= (1 << 8)) ? 0 :
         !!(_DefaultRuneLocale.__runetype[_c] & _f);
}
#188 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctype.h" 3 4
__darwin_ct_rune_t __toupper(__darwin_ct_rune_t);
__darwin_ct_rune_t __tolower(__darwin_ct_rune_t);

inline int
__wcwidth(__darwin_ct_rune_t _c)
{
  unsigned int _x;

  if(_c == 0) {
    return 0;
  }
  _x = (unsigned int)__maskrune(_c, 0xe0000000L | 0x00040000L);
  if((_x & 0xe0000000L) != 0) {
    return (_x & 0xe0000000L) >> 30;
  }
  return (_x & 0x00040000L) != 0 ? 1 : -1;
}
inline int
isalnum(int _c)
{
  return __istype(_c, 0x00000100L | 0x00000400L);
}
inline int
isalpha(int _c)
{
  return __istype(_c, 0x00000100L);
}
inline int
isblank(int _c)
{
  return __istype(_c, 0x00020000L);
}
inline int
iscntrl(int _c)
{
  return __istype(_c, 0x00000200L);
}
inline int
isdigit(int _c)
{
  return __isctype(_c, 0x00000400L);
}
inline int
isgraph(int _c)
{
  return __istype(_c, 0x00000800L);
}
inline int
islower(int _c)
{
  return __istype(_c, 0x00001000L);
}
inline int
isprint(int _c)
{
  return __istype(_c, 0x00040000L);
}
inline int
ispunct(int _c)
{
  return __istype(_c, 0x00002000L);
}
inline int
isspace(int _c)
{
  return __istype(_c, 0x00004000L);
}
inline int
isupper(int _c)
{
  return __istype(_c, 0x00008000L);
}
inline int
isxdigit(int _c)
{
  return __isctype(_c, 0x00010000L);
}
inline int
toascii(int _c)
{
  return _c & 0x7F;
}
inline int
tolower(int _c)
{
  return __tolower(_c);
}
inline int
toupper(int _c)
{
  return __toupper(_c);
}
inline int
digittoint(int _c)
{
  return __maskrune(_c, 0x0F);
}
inline int
ishexnumber(int _c)
{
  return __istype(_c, 0x00010000L);
}
inline int
isideogram(int _c)
{
  return __istype(_c, 0x00080000L);
}
inline int
isnumber(int _c)
{
  return __istype(_c, 0x00000400L);
}
inline int
isphonogram(int _c)
{
  return __istype(_c, 0x00200000L);
}
inline int
isrune(int _c)
{
  return __istype(_c, 0xFFFFFFF0L);
}
inline int
isspecial(int _c)
{
  return __istype(_c, 0x00100000L);
}
#70 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ctype.h" 2 3 4
#73 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/__wctype.h" 2 3 4
#43 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_wctype.h" 2 3 4

inline int
iswalnum(wint_t _wc)
{
  return __istype(_wc, 0x00000100L | 0x00000400L);
}
inline int
iswalpha(wint_t _wc)
{
  return __istype(_wc, 0x00000100L);
}
inline int
iswcntrl(wint_t _wc)
{
  return __istype(_wc, 0x00000200L);
}
inline int
iswctype(wint_t _wc, wctype_t _charclass)
{
  return __istype(_wc, _charclass);
}
inline int
iswdigit(wint_t _wc)
{
  return __isctype(_wc, 0x00000400L);
}
inline int
iswgraph(wint_t _wc)
{
  return __istype(_wc, 0x00000800L);
}
inline int
iswlower(wint_t _wc)
{
  return __istype(_wc, 0x00001000L);
}
inline int
iswprint(wint_t _wc)
{
  return __istype(_wc, 0x00040000L);
}
inline int
iswpunct(wint_t _wc)
{
  return __istype(_wc, 0x00002000L);
}
inline int
iswspace(wint_t _wc)
{
  return __istype(_wc, 0x00004000L);
}
inline int
iswupper(wint_t _wc)
{
  return __istype(_wc, 0x00008000L);
}
inline int
iswxdigit(wint_t _wc)
{
  return __isctype(_wc, 0x00010000L);
}
inline wint_t
towlower(wint_t _wc)
{
  return __tolower(_wc);
}
inline wint_t
towupper(wint_t _wc)
{
  return __toupper(_wc);
}
#156 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_wctype.h" 3 4
wctype_t
wctype(const char *);
#93 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 2 3 4

wint_t btowc(int);
wint_t fgetwc(FILE *);
wchar_t *fgetws(wchar_t *restrict, int, FILE *restrict);
wint_t fputwc(wchar_t, FILE *);
int fputws(const wchar_t *restrict, FILE *restrict);
int fwide(FILE *, int);
int fwprintf(FILE *restrict, const wchar_t *restrict, ...);
int fwscanf(FILE *restrict, const wchar_t *restrict, ...);
wint_t getwc(FILE *);
wint_t getwchar(void);
size_t mbrlen(const char *restrict, size_t, mbstate_t *restrict);
size_t mbrtowc(wchar_t *restrict, const char *restrict, size_t,
               mbstate_t *restrict);
int mbsinit(const mbstate_t *);
size_t mbsrtowcs(wchar_t *restrict, const char **restrict, size_t,
                 mbstate_t *restrict);
wint_t putwc(wchar_t, FILE *);
wint_t putwchar(wchar_t);
int swprintf(wchar_t *restrict, size_t, const wchar_t *restrict, ...);
int swscanf(const wchar_t *restrict, const wchar_t *restrict, ...);
wint_t ungetwc(wint_t, FILE *);
int vfwprintf(FILE *restrict, const wchar_t *restrict,
              __darwin_va_list);
int vswprintf(wchar_t *restrict, size_t, const wchar_t *restrict,
              __darwin_va_list);
int vwprintf(const wchar_t *restrict, __darwin_va_list);
size_t wcrtomb(char *restrict, wchar_t, mbstate_t *restrict);
wchar_t *wcscat(wchar_t *restrict, const wchar_t *restrict);
wchar_t *wcschr(const wchar_t *, wchar_t);
int wcscmp(const wchar_t *, const wchar_t *);
int wcscoll(const wchar_t *, const wchar_t *);
wchar_t *wcscpy(wchar_t *restrict, const wchar_t *restrict);
size_t wcscspn(const wchar_t *, const wchar_t *);
size_t wcsftime(wchar_t *restrict, size_t, const wchar_t *restrict,
                const struct tm *restrict) __asm("_" "wcsftime");
size_t wcslen(const wchar_t *);
wchar_t *wcsncat(wchar_t *restrict, const wchar_t *restrict, size_t);
int wcsncmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wcsncpy(wchar_t *restrict, const wchar_t *restrict, size_t);
wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
wchar_t *wcsrchr(const wchar_t *, wchar_t);
size_t wcsrtombs(char *restrict, const wchar_t **restrict, size_t,
                 mbstate_t *restrict);
size_t wcsspn(const wchar_t *, const wchar_t *);
wchar_t *wcsstr(const wchar_t *restrict, const wchar_t *restrict);
size_t wcsxfrm(wchar_t *restrict, const wchar_t *restrict, size_t);
int wctob(wint_t);
double wcstod(const wchar_t *restrict, wchar_t **restrict);
wchar_t *wcstok(wchar_t *restrict, const wchar_t *restrict,
                wchar_t **restrict);
long wcstol(const wchar_t *restrict, wchar_t **restrict, int);
unsigned long
wcstoul(const wchar_t *restrict, wchar_t **restrict, int);
wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
int wmemcmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wmemcpy(wchar_t *restrict, const wchar_t *restrict, size_t);
wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
wchar_t *wmemset(wchar_t *, wchar_t, size_t);
int wprintf(const wchar_t *restrict, ...);
int wscanf(const wchar_t *restrict, ...);
int wcswidth(const wchar_t *, size_t);
int wcwidth(wchar_t);
#170 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 3 4
int vfwscanf(FILE *restrict, const wchar_t *restrict,
             __darwin_va_list);
int vswscanf(const wchar_t *restrict, const wchar_t *restrict,
             __darwin_va_list);
int vwscanf(const wchar_t *restrict, __darwin_va_list);
float wcstof(const wchar_t *restrict, wchar_t **restrict);
long double
wcstold(const wchar_t *restrict, wchar_t **restrict);

long long
wcstoll(const wchar_t *restrict, wchar_t **restrict, int);
unsigned long long
wcstoull(const wchar_t *restrict, wchar_t **restrict, int);
#195 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 3 4
size_t mbsnrtowcs(wchar_t *restrict, const char **restrict, size_t,
                  size_t, mbstate_t *restrict);
wchar_t *wcpcpy(wchar_t *restrict, const wchar_t *restrict) __attribute__((availability(macosx, introduced = 10.7)));
wchar_t *wcpncpy(wchar_t *restrict, const wchar_t *restrict, size_t) __attribute__((availability(macosx, introduced = 10.7)));
wchar_t *wcsdup(const wchar_t *) __attribute__((availability(macosx, introduced = 10.7)));
int wcscasecmp(const wchar_t *, const wchar_t *) __attribute__((availability(macosx, introduced = 10.7)));
int wcsncasecmp(const wchar_t *, const wchar_t *, size_t n) __attribute__((availability(macosx, introduced = 10.7)));
size_t wcsnlen(const wchar_t *, size_t) __attribute__((availability(macosx, introduced = 10.7)));
size_t wcsnrtombs(char *restrict, const wchar_t **restrict, size_t,
                  size_t, mbstate_t *restrict);
FILE *open_wmemstream(wchar_t **__bufp, size_t *__sizep) __attribute__((availability(macos, introduced = 10.13))) __attribute__((availability(ios, introduced = 11.0))) __attribute__((availability(tvos, introduced = 11.0))) __attribute__((availability(watchos, introduced = 4.0)));
#215 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/wchar.h" 3 4
wchar_t *fgetwln(FILE *restrict, size_t *) __attribute__((availability(macosx, introduced = 10.7)));
size_t wcslcat(wchar_t *, const wchar_t *, size_t);
size_t wcslcpy(wchar_t *, const wchar_t *, size_t);
#50 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/printf.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 1 3 4
#33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_locale.h" 1 3 4
#43 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_locale.h" 3 4
struct lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_n_cs_precedes;
  char int_p_sep_by_space;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};

struct lconv *localeconv(void);
#34 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 2 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_xlocale.h" 1 3 4
#29 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_xlocale.h" 3 4
struct _xlocale;
typedef struct _xlocale *locale_t;

int ___mb_cur_max(void);
int ___mb_cur_max_l(locale_t);
#35 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 2 3 4
#64 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 3 4
extern const locale_t _c_locale;

locale_t duplocale(locale_t);
int freelocale(locale_t);
struct lconv *localeconv_l(locale_t);
locale_t newlocale(int, const char *, locale_t);
const char *querylocale(int, locale_t);
locale_t uselocale(locale_t);

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_ctype.h" 1 3 4
#38 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_ctype.h" 3 4
unsigned long ___runetype_l(__darwin_ct_rune_t, locale_t);
__darwin_ct_rune_t ___tolower_l(__darwin_ct_rune_t, locale_t);
__darwin_ct_rune_t ___toupper_l(__darwin_ct_rune_t, locale_t);

int __maskrune_l(__darwin_ct_rune_t, unsigned long, locale_t);

inline int
__istype_l(__darwin_ct_rune_t _c, unsigned long _f, locale_t _l)
{
  return !!(isascii(_c) ? (_DefaultRuneLocale.__runetype[_c] & _f)
            : __maskrune_l(_c, _f, _l));
}
inline __darwin_ct_rune_t
__toupper_l(__darwin_ct_rune_t _c, locale_t _l)
{
  return isascii(_c) ? _DefaultRuneLocale.__mapupper[_c]
         : ___toupper_l(_c, _l);
}
inline __darwin_ct_rune_t
__tolower_l(__darwin_ct_rune_t _c, locale_t _l)
{
  return isascii(_c) ? _DefaultRuneLocale.__maplower[_c]
         : ___tolower_l(_c, _l);
}
inline int
__wcwidth_l(__darwin_ct_rune_t _c, locale_t _l)
{
  unsigned int _x;

  if(_c == 0) {
    return 0;
  }
  _x = (unsigned int)__maskrune_l(_c, 0xe0000000L | 0x00040000L, _l);
  if((_x & 0xe0000000L) != 0) {
    return (_x & 0xe0000000L) >> 30;
  }
  return (_x & 0x00040000L) != 0 ? 1 : -1;
}
inline int
digittoint_l(int c, locale_t l)
{
  return __maskrune_l(c, 0x0F, l);
}
inline int
isalnum_l(int c, locale_t l)
{
  return __istype_l(c, 0x00000100L | 0x00000400L, l);
}
inline int
isalpha_l(int c, locale_t l)
{
  return __istype_l(c, 0x00000100L, l);
}
inline int
isblank_l(int c, locale_t l)
{
  return __istype_l(c, 0x00020000L, l);
}
inline int
iscntrl_l(int c, locale_t l)
{
  return __istype_l(c, 0x00000200L, l);
}
inline int
isdigit_l(int c, locale_t l)
{
  return __istype_l(c, 0x00000400L, l);
}
inline int
isgraph_l(int c, locale_t l)
{
  return __istype_l(c, 0x00000800L, l);
}
inline int
ishexnumber_l(int c, locale_t l)
{
  return __istype_l(c, 0x00010000L, l);
}
inline int
isideogram_l(int c, locale_t l)
{
  return __istype_l(c, 0x00080000L, l);
}
inline int
islower_l(int c, locale_t l)
{
  return __istype_l(c, 0x00001000L, l);
}
inline int
isnumber_l(int c, locale_t l)
{
  return __istype_l(c, 0x00000400L, l);
}
inline int
isphonogram_l(int c, locale_t l)
{
  return __istype_l(c, 0x00200000L, l);
}
inline int
isprint_l(int c, locale_t l)
{
  return __istype_l(c, 0x00040000L, l);
}
inline int
ispunct_l(int c, locale_t l)
{
  return __istype_l(c, 0x00002000L, l);
}
inline int
isrune_l(int c, locale_t l)
{
  return __istype_l(c, 0xFFFFFFF0L, l);
}
inline int
isspace_l(int c, locale_t l)
{
  return __istype_l(c, 0x00004000L, l);
}
inline int
isspecial_l(int c, locale_t l)
{
  return __istype_l(c, 0x00100000L, l);
}
inline int
isupper_l(int c, locale_t l)
{
  return __istype_l(c, 0x00008000L, l);
}
inline int
isxdigit_l(int c, locale_t l)
{
  return __istype_l(c, 0x00010000L, l);
}
inline int
tolower_l(int c, locale_t l)
{
  return __tolower_l(c, l);
}
inline int
toupper_l(int c, locale_t l)
{
  return __toupper_l(c, l);
}
#76 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/__wctype.h" 1 3 4
#33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/__wctype.h" 3 4
inline int
iswalnum_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00000100L | 0x00000400L, _l);
}
inline int
iswalpha_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00000100L, _l);
}
inline int
iswcntrl_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00000200L, _l);
}
inline int
iswctype_l(wint_t _wc, wctype_t _charclass, locale_t _l)
{
  return __istype_l(_wc, _charclass, _l);
}
inline int
iswdigit_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00000400L, _l);
}
inline int
iswgraph_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00000800L, _l);
}
inline int
iswlower_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00001000L, _l);
}
inline int
iswprint_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00040000L, _l);
}
inline int
iswpunct_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00002000L, _l);
}
inline int
iswspace_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00004000L, _l);
}
inline int
iswupper_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00008000L, _l);
}
inline int
iswxdigit_l(wint_t _wc, locale_t _l)
{
  return __istype_l(_wc, 0x00010000L, _l);
}
inline wint_t
towlower_l(wint_t _wc, locale_t _l)
{
  return __tolower_l(_wc, _l);
}
inline wint_t
towupper_l(wint_t _wc, locale_t _l)
{
  return __toupper_l(_wc, _l);
}
#139 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/__wctype.h" 3 4
wctype_t
wctype_l(const char *, locale_t);
#79 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 2 3 4
#93 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 3 4
#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_stdio.h" 1 3 4
#32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_stdio.h" 3 4
int fprintf_l(FILE *restrict, locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__printf__, 3, 4)));
int fscanf_l(FILE *restrict, locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__scanf__, 3, 4)));
int printf_l(locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__printf__, 2, 3)));
int scanf_l(locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__scanf__, 2, 3)));
int sprintf_l(char *restrict, locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__printf__, 3, 4))) __attribute__((__availability__(swift, unavailable, message = "Use snprintf_l instead.")));
int sscanf_l(const char *restrict, locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__scanf__, 3, 4)));
int vfprintf_l(FILE *restrict, locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__printf__, 3, 0)));
int vprintf_l(locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__printf__, 2, 0)));
int vsprintf_l(char *restrict, locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__printf__, 3, 0))) __attribute__((__availability__(swift, unavailable, message = "Use vsnprintf_l instead.")));

int snprintf_l(char *restrict, size_t, locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__printf__, 4, 5)));
int vfscanf_l(FILE *restrict, locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__scanf__, 3, 0)));
int vscanf_l(locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__scanf__, 2, 0)));
int vsnprintf_l(char *restrict, size_t, locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__printf__, 4, 0)));
int vsscanf_l(const char *restrict, locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__scanf__, 3, 0)));

int dprintf_l(int, locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__printf__, 3, 4))) __attribute__((availability(macosx, introduced = 10.7)));
int vdprintf_l(int, locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__printf__, 3, 0))) __attribute__((availability(macosx, introduced = 10.7)));

int asprintf_l(char **restrict, locale_t restrict, const char *restrict, ...)
__attribute__((__format__(__printf__, 3, 4)));
int vasprintf_l(char **restrict, locale_t restrict, const char *restrict, va_list)
__attribute__((__format__(__printf__, 3, 0)));
#94 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_time.h" 1 3 4
#33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_time.h" 3 4
size_t strftime_l(char *restrict, size_t, const char *restrict,
                  const struct tm *restrict, locale_t)
__asm("_" "strftime_l") __attribute__((__format__(__strftime__, 3, 0)));
char *strptime_l(const char *restrict, const char *restrict,
                 struct tm *restrict, locale_t)
__asm("_" "strptime_l") __attribute__((__format__(__strftime__, 2, 0)));
#103 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 2 3 4

#1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_wchar.h" 1 3 4
#33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_wchar.h" 3 4
wint_t btowc_l(int, locale_t);
wint_t fgetwc_l(FILE *, locale_t);
wchar_t *fgetws_l(wchar_t *restrict, int, FILE *restrict, locale_t);
wint_t fputwc_l(wchar_t, FILE *, locale_t);
int fputws_l(const wchar_t *restrict, FILE *restrict, locale_t);
int fwprintf_l(FILE *restrict, locale_t, const wchar_t *restrict, ...);
int fwscanf_l(FILE *restrict, locale_t, const wchar_t *restrict, ...);
wint_t getwc_l(FILE *, locale_t);
wint_t getwchar_l(locale_t);
size_t mbrlen_l(const char *restrict, size_t, mbstate_t *restrict,
                locale_t);
size_t mbrtowc_l(wchar_t *restrict, const char *restrict, size_t,
                 mbstate_t *restrict, locale_t);
int mbsinit_l(const mbstate_t *, locale_t);
size_t mbsrtowcs_l(wchar_t *restrict, const char **restrict, size_t,
                   mbstate_t *restrict, locale_t);
wint_t putwc_l(wchar_t, FILE *, locale_t);
wint_t putwchar_l(wchar_t, locale_t);
int swprintf_l(wchar_t *restrict, size_t n, locale_t,
               const wchar_t *restrict, ...);
int swscanf_l(const wchar_t *restrict, locale_t,
              const wchar_t *restrict, ...);
wint_t ungetwc_l(wint_t, FILE *, locale_t);
int vfwprintf_l(FILE *restrict, locale_t, const wchar_t *restrict,
                __darwin_va_list);
int vswprintf_l(wchar_t *restrict, size_t n, locale_t,
                const wchar_t *restrict, __darwin_va_list);
int vwprintf_l(locale_t, const wchar_t *restrict, __darwin_va_list);
size_t wcrtomb_l(char *restrict, wchar_t, mbstate_t *restrict,
                 locale_t);
int wcscoll_l(const wchar_t *, const wchar_t *, locale_t);
size_t wcsftime_l(wchar_t *restrict, size_t, const wchar_t *restrict,
                  const struct tm *restrict, locale_t)
__asm("_" "wcsftime_l");
size_t wcsrtombs_l(char *restrict, const wchar_t **restrict, size_t,
                   mbstate_t *restrict, locale_t);
double wcstod_l(const wchar_t *restrict, wchar_t **restrict, locale_t);
long wcstol_l(const wchar_t *restrict, wchar_t **restrict, int,
              locale_t);
unsigned long
wcstoul_l(const wchar_t *restrict, wchar_t **restrict, int,
          locale_t);
int wcswidth_l(const wchar_t *, size_t, locale_t);
size_t wcsxfrm_l(wchar_t *restrict, const wchar_t *restrict, size_t,
                 locale_t);
int wctob_l(wint_t, locale_t);
int wcwidth_l(wchar_t, locale_t);
int wprintf_l(locale_t, const wchar_t *restrict, ...);
int wscanf_l(locale_t, const wchar_t *restrict, ...);
#92 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_wchar.h" 3 4
int vfwscanf_l(FILE *restrict, locale_t, const wchar_t *restrict,
               __darwin_va_list);
int vswscanf_l(const wchar_t *restrict, locale_t,
               const wchar_t *restrict, __darwin_va_list);
int vwscanf_l(locale_t, const wchar_t *restrict, __darwin_va_list);
float wcstof_l(const wchar_t *restrict, wchar_t **restrict, locale_t);
long double
wcstold_l(const wchar_t *restrict, wchar_t **restrict, locale_t);

long long
wcstoll_l(const wchar_t *restrict, wchar_t **restrict, int,
          locale_t);
unsigned long long
wcstoull_l(const wchar_t *restrict, wchar_t **restrict, int,
           locale_t);
#119 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_wchar.h" 3 4
size_t mbsnrtowcs_l(wchar_t *restrict, const char **restrict, size_t,
                    size_t, mbstate_t *restrict, locale_t);
int wcscasecmp_l(const wchar_t *, const wchar_t *, locale_t) __attribute__((availability(macosx, introduced = 10.7)));
int wcsncasecmp_l(const wchar_t *, const wchar_t *, size_t n, locale_t) __attribute__((availability(macosx, introduced = 10.7)));
size_t wcsnrtombs_l(char *restrict, const wchar_t **restrict, size_t,
                    size_t, mbstate_t *restrict, locale_t);
#134 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale/_wchar.h" 3 4
wchar_t *fgetwln_l(FILE *restrict, size_t *, locale_t) __attribute__((availability(macosx, introduced = 10.7)));
#106 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/xlocale.h" 2 3 4
#51 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/printf.h" 2 3 4
#67 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/printf.h" 3 4
struct printf_info {

  void *context;
  locale_t loc;
  wchar_t vsep;

  int prec;
  int width;
  wchar_t spec;
  wchar_t pad;

  wchar_t signchar;

  unsigned is_long_double : 1;
  unsigned is_char : 1;
  unsigned is_short : 1;
  unsigned is_long : 1;
  unsigned alt : 1;
  unsigned space : 1;
  unsigned left : 1;
  unsigned showsign : 1;
  unsigned group : 1;
  unsigned extra : 1;
  unsigned wide : 1;

  unsigned is_quad : 1;
  unsigned is_intmax : 1;
  unsigned is_ptrdiff : 1;
  unsigned is_size : 1;

  unsigned is_vec : 1;

  int sofar;
  unsigned get_width;
  unsigned get_prec;
  const char *begin;
  const char *end;
  void *arg[2];
};

enum {
  PA_INT = (1 << 0),
  PA_CHAR = (1 << 1),
  PA_WCHAR = (1 << 2),
  PA_STRING = (1 << 3),
  PA_WSTRING = (1 << 4),
  PA_POINTER = (1 << 5),
  PA_FLOAT = (1 << 6),
  PA_DOUBLE = (1 << 7),
  PA_VECTOR = (1 << 8),
};
#140 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/printf.h" 3 4
typedef int printf_arginfo_function (const struct printf_info *__info,
                                     size_t __n, int *__argtypes);
typedef int printf_function (FILE *__stream,
                             const struct printf_info *__info, const void *const *__args);
#153 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/printf.h" 3 4
struct _printf_domain;
typedef struct _printf_domain *printf_domain_t;

printf_domain_t copy_printf_domain(printf_domain_t __domain)
__attribute__((__nonnull__(1)))
__attribute__((availability(macosx, introduced = 10.9)));
void free_printf_domain(printf_domain_t __domain)
__attribute__((availability(macosx, introduced = 10.9)));
printf_domain_t new_printf_domain(void)
__attribute__((__malloc__))
__attribute__((availability(macosx, introduced = 10.9)));
int register_printf_domain_function(printf_domain_t __domain,
                                    int __spec, printf_function *__render,
                                    printf_arginfo_function *__arginfo, void *__context)
__attribute__((__nonnull__(1)))
__attribute__((availability(macosx, introduced = 10.9)));
int register_printf_domain_render_std(printf_domain_t __domain,
                                      const char *__specs)
__attribute__((__nonnull__(1)))
__attribute__((availability(macosx, introduced = 10.9)));

int asxprintf(char **restrict __ret,
              printf_domain_t restrict __domain, locale_t restrict __loc,
              const char *restrict __format, ...)
__attribute__((__nonnull__(1, 2, 4)))
__attribute__((availability(macosx, introduced = 10.9)));
int dxprintf(int __fd, printf_domain_t restrict __domain,
             locale_t restrict __loc, const char *restrict __format, ...)
__attribute__((__nonnull__(2, 4)))
__attribute__((availability(macosx, introduced = 10.9)));
int fxprintf(FILE *restrict __stream,
             printf_domain_t restrict __domain, locale_t restrict __loc,
             const char *restrict __format, ...)
__attribute__((__nonnull__(1, 2, 4)))
__attribute__((availability(macosx, introduced = 10.9)));
int sxprintf(char *restrict __str, size_t __size,
             printf_domain_t restrict __domain, locale_t restrict __loc,
             const char *restrict __format, ...)
__attribute__((__nonnull__(1, 3, 5)))
__attribute__((availability(macosx, introduced = 10.9)));
int xprintf(printf_domain_t restrict __domain,
            locale_t restrict __loc, const char *restrict __format, ...)
__attribute__((__nonnull__(1, 3)))
__attribute__((availability(macosx, introduced = 10.9)));

int vasxprintf(char **restrict __ret,
               printf_domain_t restrict __domain, locale_t restrict __loc,
               const char *restrict __format, va_list __ap)
__attribute__((__nonnull__(1, 2, 4)))
__attribute__((availability(macosx, introduced = 10.9)));
int vdxprintf(int __fd, printf_domain_t restrict __domain,
              locale_t restrict __loc, const char *restrict __format,
              va_list __ap)
__attribute__((__nonnull__(2, 4)))
__attribute__((availability(macosx, introduced = 10.9)));
int vfxprintf(FILE *restrict __stream,
              printf_domain_t restrict __domain, locale_t restrict __loc,
              const char *restrict __format, va_list __ap)
__attribute__((__nonnull__(1, 2, 4)))
__attribute__((availability(macosx, introduced = 10.9)));
int vsxprintf(char *restrict __str, size_t __size,
              printf_domain_t restrict __domain, locale_t restrict __loc,
              const char *restrict __format, va_list __ap)
__attribute__((__nonnull__(1, 3, 5)))
__attribute__((availability(macosx, introduced = 10.9)));
int vxprintf(printf_domain_t restrict __domain,
             locale_t restrict __loc, const char *restrict __format,
             va_list __ap)
__attribute__((__nonnull__(1, 3)))
__attribute__((availability(macosx, introduced = 10.9)));

struct _printf_compiled;
typedef struct _printf_compiled *printf_comp_t;

void free_printf_comp(printf_comp_t __pc)
__attribute__((availability(macosx, introduced = 10.9)));
printf_comp_t new_printf_comp(printf_domain_t restrict __domain,
                              locale_t restrict __loc, const char *restrict __fmt)
__attribute__((__nonnull__(1, 3)))
__attribute__((availability(macosx, introduced = 10.9)));

int asxprintf_exec(char **restrict __ret,
                   printf_comp_t restrict __pc, ...)
__attribute__((__nonnull__(1, 2)))
__attribute__((availability(macosx, introduced = 10.9)));
int dxprintf_exec(int __fd, printf_comp_t restrict __pc, ...)
__attribute__((__nonnull__(2)))
__attribute__((availability(macosx, introduced = 10.9)));
int fxprintf_exec(FILE *restrict __stream,
                  printf_comp_t restrict __pc, ...)
__attribute__((__nonnull__(1, 2)))
__attribute__((availability(macosx, introduced = 10.9)));
int sxprintf_exec(char *restrict __str, size_t __size,
                  printf_comp_t restrict __pc, ...)
__attribute__((__nonnull__(1, 3)))
__attribute__((availability(macosx, introduced = 10.9)));
int xprintf_exec(printf_comp_t restrict __pc, ...)
__attribute__((__nonnull__(1)))
__attribute__((availability(macosx, introduced = 10.9)));

int vasxprintf_exec(char **restrict __ret,
                    printf_comp_t restrict __pc, va_list __ap)
__attribute__((__nonnull__(1, 2)))
__attribute__((availability(macosx, introduced = 10.9)));
int vdxprintf_exec(int __fd, printf_comp_t restrict __pc,
                   va_list __ap)
__attribute__((__nonnull__(2)))
__attribute__((availability(macosx, introduced = 10.9)));
int vfxprintf_exec(FILE *restrict __stream,
                   printf_comp_t restrict __pc, va_list __ap)
__attribute__((__nonnull__(1, 2)))
__attribute__((availability(macosx, introduced = 10.9)));
int vsxprintf_exec(char *restrict __str, size_t __size,
                   printf_comp_t restrict __pc, va_list __ap)
__attribute__((__nonnull__(1, 3)))
__attribute__((availability(macosx, introduced = 10.9)));
int vxprintf_exec(printf_comp_t restrict __pc, va_list __ap)
__attribute__((__nonnull__(1)))
__attribute__((availability(macosx, introduced = 10.9)));
#4 "eval.c" 2
#1 "./sort.h" 1

#1 "./header.h" 1
typedef struct acc_struct {
  unsigned int x_acc;
  unsigned int y_acc;
  unsigned int z_acc;
} acc_struct_t;
typedef struct task_struct {
  long int e_wc;
  struct task_struct *in_set[3];
  int in_set_count;
  long int deadline[2];
  short int deadlineVersion;
  void (*function_pointer)();
  char isEnabled[2];
  short int isEnabledVersion;
  char isActive[2];
  short int isActiveVersion;
  short int marked_to_remove[2];
  short int stopped;
  void *app_pointer;
} task_struct_t;

typedef struct app_struct {
  task_struct_t *app_tasks[6];
  task_struct_t *initial_task;
  task_struct_t *final_task;
  int tasks_count;
  unsigned long int x_min;
  short int x_ok[2];
  short int x_okVersion;
  short int isActive[2];
  short int isActiveVersion;
} app_struct_t;
#138 "./header.h"
void sense();
void median();
void lowpass();
void magnitude();
void classify();
void operate();
void compress();
void send();
#4 "./sort.h" 2

void heapify(task_struct_t *, int);
void adjust(task_struct_t *, int);
void heapsort(task_struct_t **, int);
#5 "eval.c" 2
#16 "eval.c"
struct sense_var_struct { acc_struct_t version_array[30 + 1];
                          short int versions_count;
                          short int window_begin_index;
                          short int write_index;
                          short int write_count;
                          char is_full;
};
struct sense_var_struct __attribute__ ((persistent)) var_struct_sense = { .versions_count = 30, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
acc_struct_t g_sense;
struct median_var_struct { acc_struct_t *version_array[1 + 1];
                           short int versions_count;
                           short int window_begin_index;
                           short int write_index;
                           short int write_count;
                           char is_full;
};
struct median_var_struct __attribute__ ((persistent)) var_struct_median = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
acc_struct_t *g_median;
struct lowpass_var_struct { acc_struct_t *version_array[1 + 1];
                            short int versions_count;
                            short int window_begin_index;
                            short int write_index;
                            short int write_count;
                            char is_full;
};
struct lowpass_var_struct __attribute__ ((persistent)) var_struct_lowpass = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
acc_struct_t *g_lowpass;
struct magnitude_var_struct { acc_struct_t *version_array[1 + 1];
                              short int versions_count;
                              short int window_begin_index;
                              short int write_index;
                              short int write_count;
                              char is_full;
};
struct magnitude_var_struct __attribute__ ((persistent)) var_struct_magnitude = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
acc_struct_t *g_magnitude;
struct classify_var_struct { int version_array[1 + 1];
                             short int versions_count;
                             short int window_begin_index;
                             short int write_index;
                             short int write_count;
                             char is_full;
};
struct classify_var_struct __attribute__ ((persistent)) var_struct_classify = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
int g_classify;
struct operate_var_struct { int version_array[1 + 1];
                            short int versions_count;
                            short int window_begin_index;
                            short int write_index;
                            short int write_count;
                            char is_full;
};
struct operate_var_struct __attribute__ ((persistent)) var_struct_operate = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
int g_operate;
struct compress_var_struct { acc_struct_t *version_array[1 + 1];
                             short int versions_count;
                             short int window_begin_index;
                             short int write_index;
                             short int write_count;
                             char is_full;
};
struct compress_var_struct __attribute__ ((persistent)) var_struct_compress = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
acc_struct_t *g_compress;
struct send_var_struct { int version_array[1 + 1];
                         short int versions_count;
                         short int window_begin_index;
                         short int write_index;
                         short int write_count;
                         char is_full;
};
struct send_var_struct __attribute__ ((persistent)) var_struct_send = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count = 9 };
int g_send;
extern app_struct_t *active_app_array[2];
extern int active_app_count;
extern task_struct_t *enabled_task_array[8];
extern int enabled_task_count;
extern task_struct_t task_struct_sense;
extern task_struct_t task_struct_median;
extern task_struct_t task_struct_lowpass;
extern task_struct_t task_struct_magnitude;
extern task_struct_t task_struct_classify;
extern task_struct_t task_struct_operate;
extern task_struct_t task_struct_compress;
extern task_struct_t task_struct_send;
extern app_struct_t app_struct_app_1;
extern app_struct_t app_struct_app_2;

int __attribute__ ((persistent)) resets = -1;
int __attribute__ ((persistent)) seen_resets = 0;
int __attribute__ ((persistent)) next_task = 0;
long int __attribute__ ((persistent)) tardis_time = 0;
long int __attribute__ ((persistent)) delta_cycles = 0;
long int __attribute__ ((persistent)) frequency = 0;
long int __attribute__ ((persistent)) exec_depth_x100 = 0;
long int __attribute__ ((persistent)) voltageX100 = 0;
long int __attribute__ ((persistent)) is_pruning = 0;
long int __attribute__ ((persistent)) isSenseEnabled = 1;
long int __attribute__ ((persistent)) slack = 0;
long int __attribute__ ((persistent)) selected_app = 0;

void activate_new_app();
void manage_underperf();
void manage_overperf();
int check_if_new(task_struct_t *);
void set_threshold(int);
unsigned long int get_exec_depth_x100();
void initialize();
void prune_tasks();
void subtract_cycles_from_all();

void
sense()
{
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running SENSE\n");
  acc_struct_t sense_out;
  __delay_cycles(80000);
  siren_command("START_TIME: misd(SENSE)\n");
  g_sense = sense_out;
  var_struct_sense.version_array[var_struct_sense.write_index] = g_sense;
  var_struct_sense.write_index = (var_struct_sense.write_index + 1) % (var_struct_sense.versions_count + 1);
  if(var_struct_sense.is_full) {
    var_struct_sense.window_begin_index = (var_struct_sense.window_begin_index + 1) % (var_struct_sense.versions_count + 1);
  } else if(var_struct_sense.write_index == 0) {
    var_struct_sense.is_full = 1;
    var_struct_sense.window_begin_index = (var_struct_sense.window_begin_index + 1) % (var_struct_sense.versions_count + 1);
  }
  if(var_struct_sense.write_count < var_struct_sense.versions_count) {
    var_struct_sense.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, sense\n", delta_cycles);
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_sense.deadline[!task_struct_sense.deadlineVersion & 0x1] = 666666;
    task_struct_sense.deadlineVersion = !task_struct_sense.deadlineVersion & 0x1;
  }
  extern task_struct_t task_struct_median;
  short int task_struct_median_enVersion = task_struct_median.isEnabledVersion;
  if(!(task_struct_median.isEnabled[task_struct_median_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (var_struct_sense.write_count >= 10)) {
    task_struct_median.isEnabled[!task_struct_median_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_median;
    enabled_task_count++;
    task_struct_median.isEnabledVersion = !task_struct_median_enVersion & 0x1;
  }
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1] = task_struct_sense.deadline[!task_struct_sense.deadlineVersion & 0x1];
    task_struct_median.deadlineVersion = !task_struct_median.deadlineVersion & 0x1;
  }
}
void
median()
{
  acc_struct_t sense = g_sense;
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running MEDIAN\n");
  acc_struct_t *median_out;
  __delay_cycles(32000);
  g_median = median_out;
  var_struct_median.version_array[var_struct_median.write_index] = g_median;
  var_struct_median.write_index = (var_struct_median.write_index + 1) % (var_struct_median.versions_count + 1);
  if(var_struct_median.is_full) {
    var_struct_median.window_begin_index = (var_struct_median.window_begin_index + 1) % (var_struct_median.versions_count + 1);
  } else if(var_struct_median.write_index == 0) {
    var_struct_median.is_full = 1;
    var_struct_median.window_begin_index = (var_struct_median.window_begin_index + 1) % (var_struct_median.versions_count + 1);
  }
  if(var_struct_median.write_count < var_struct_median.versions_count) {
    var_struct_median.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, median\n", delta_cycles);
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1] = task_struct_sense.deadline[!task_struct_sense.deadlineVersion & 0x1];
    task_struct_median.deadlineVersion = !task_struct_median.deadlineVersion & 0x1;
  }
  extern task_struct_t task_struct_lowpass;
  short int task_struct_lowpass_enVersion = task_struct_lowpass.isEnabledVersion;
  if(!(task_struct_lowpass.isEnabled[task_struct_lowpass_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)) {
    task_struct_lowpass.isEnabled[!task_struct_lowpass_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_lowpass;
    enabled_task_count++;
    task_struct_lowpass.isEnabledVersion = !task_struct_lowpass_enVersion & 0x1;
  }
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1] = task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1];
    task_struct_lowpass.deadlineVersion = !task_struct_lowpass.deadlineVersion & 0x1;
  }
}
void
lowpass()
{
  acc_struct_t *median = g_median;
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running LOWPASS\n");
  acc_struct_t *lowpass_out;
  __delay_cycles(50000);
  g_lowpass = lowpass_out;
  var_struct_lowpass.version_array[var_struct_lowpass.write_index] = g_lowpass;
  var_struct_lowpass.write_index = (var_struct_lowpass.write_index + 1) % (var_struct_lowpass.versions_count + 1);
  if(var_struct_lowpass.is_full) {
    var_struct_lowpass.window_begin_index = (var_struct_lowpass.window_begin_index + 1) % (var_struct_lowpass.versions_count + 1);
  } else if(var_struct_lowpass.write_index == 0) {
    var_struct_lowpass.is_full = 1;
    var_struct_lowpass.window_begin_index = (var_struct_lowpass.window_begin_index + 1) % (var_struct_lowpass.versions_count + 1);
  }
  if(var_struct_lowpass.write_count < var_struct_lowpass.versions_count) {
    var_struct_lowpass.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, lowpass\n", delta_cycles);
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1] = task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1];
    task_struct_lowpass.deadlineVersion = !task_struct_lowpass.deadlineVersion & 0x1;
  }
  extern task_struct_t task_struct_magnitude;
  short int task_struct_magnitude_enVersion = task_struct_magnitude.isEnabledVersion;
  if(!(task_struct_magnitude.isEnabled[task_struct_magnitude_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)) {
    task_struct_magnitude.isEnabled[!task_struct_magnitude_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_magnitude;
    enabled_task_count++;
    task_struct_magnitude.isEnabledVersion = !task_struct_magnitude_enVersion & 0x1;
  }
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1] = task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1];
    task_struct_magnitude.deadlineVersion = !task_struct_magnitude.deadlineVersion & 0x1;
  }
  extern task_struct_t task_struct_compress;
  short int task_struct_compress_enVersion = task_struct_compress.isEnabledVersion;
  if(!(task_struct_compress.isEnabled[task_struct_compress_enVersion]) && (app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) && (1)) {
    task_struct_compress.isEnabled[!task_struct_compress_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_compress;
    enabled_task_count++;
    task_struct_compress.isEnabledVersion = !task_struct_compress_enVersion & 0x1;
  }
  if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) {
    task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1] = 2000000;
    task_struct_compress.deadlineVersion = !task_struct_compress.deadlineVersion & 0x1;
  }
}
void
magnitude()
{
  acc_struct_t *lowpass = g_lowpass;
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running MAGNITUDE\n");
  acc_struct_t *magnitude_out;
  __delay_cycles(15000);
  g_magnitude = magnitude_out;
  var_struct_magnitude.version_array[var_struct_magnitude.write_index] = g_magnitude;
  var_struct_magnitude.write_index = (var_struct_magnitude.write_index + 1) % (var_struct_magnitude.versions_count + 1);
  if(var_struct_magnitude.is_full) {
    var_struct_magnitude.window_begin_index = (var_struct_magnitude.window_begin_index + 1) % (var_struct_magnitude.versions_count + 1);
  } else if(var_struct_magnitude.write_index == 0) {
    var_struct_magnitude.is_full = 1;
    var_struct_magnitude.window_begin_index = (var_struct_magnitude.window_begin_index + 1) % (var_struct_magnitude.versions_count + 1);
  }
  if(var_struct_magnitude.write_count < var_struct_magnitude.versions_count) {
    var_struct_magnitude.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, magnitude\n", delta_cycles);
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1] = task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1];
    task_struct_magnitude.deadlineVersion = !task_struct_magnitude.deadlineVersion & 0x1;
  }
  extern task_struct_t task_struct_classify;
  short int task_struct_classify_enVersion = task_struct_classify.isEnabledVersion;
  if(!(task_struct_classify.isEnabled[task_struct_classify_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)) {
    task_struct_classify.isEnabled[!task_struct_classify_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_classify;
    enabled_task_count++;
    task_struct_classify.isEnabledVersion = !task_struct_classify_enVersion & 0x1;
  }
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1] = task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1];
    task_struct_classify.deadlineVersion = !task_struct_classify.deadlineVersion & 0x1;
  }
}
void
classify()
{
  acc_struct_t *magnitude = g_magnitude;
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running CLASSIFY\n");
  int classify_out;
  __delay_cycles(15000);
  g_classify = classify_out;
  var_struct_classify.version_array[var_struct_classify.write_index] = g_classify;
  var_struct_classify.write_index = (var_struct_classify.write_index + 1) % (var_struct_classify.versions_count + 1);
  if(var_struct_classify.is_full) {
    var_struct_classify.window_begin_index = (var_struct_classify.window_begin_index + 1) % (var_struct_classify.versions_count + 1);
  } else if(var_struct_classify.write_index == 0) {
    var_struct_classify.is_full = 1;
    var_struct_classify.window_begin_index = (var_struct_classify.window_begin_index + 1) % (var_struct_classify.versions_count + 1);
  }
  if(var_struct_classify.write_count < var_struct_classify.versions_count) {
    var_struct_classify.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, classify\n", delta_cycles);
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1] = task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1];
    task_struct_classify.deadlineVersion = !task_struct_classify.deadlineVersion & 0x1;
  }
  extern task_struct_t task_struct_operate;
  short int task_struct_operate_enVersion = task_struct_operate.isEnabledVersion;
  if(!(task_struct_operate.isEnabled[task_struct_operate_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)) {
    task_struct_operate.isEnabled[!task_struct_operate_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_operate;
    enabled_task_count++;
    task_struct_operate.isEnabledVersion = !task_struct_operate_enVersion & 0x1;
  }
  if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_operate.deadline[!task_struct_operate.deadlineVersion & 0x1] = task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1];
    task_struct_operate.deadlineVersion = !task_struct_operate.deadlineVersion & 0x1;
  }
}
void
operate()
{
  int classify = g_classify;
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running OPERATE\n");
  int operate_out;
  __delay_cycles(30000);
  g_operate = operate_out;
  var_struct_operate.version_array[var_struct_operate.write_index] = g_operate;
  var_struct_operate.write_index = (var_struct_operate.write_index + 1) % (var_struct_operate.versions_count + 1);
  if(var_struct_operate.is_full) {
    var_struct_operate.window_begin_index = (var_struct_operate.window_begin_index + 1) % (var_struct_operate.versions_count + 1);
  } else if(var_struct_operate.write_index == 0) {
    var_struct_operate.is_full = 1;
    var_struct_operate.window_begin_index = (var_struct_operate.window_begin_index + 1) % (var_struct_operate.versions_count + 1);
  }
  if(var_struct_operate.write_count < var_struct_operate.versions_count) {
    var_struct_operate.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, operate\n", delta_cycles);
  long int value = task_struct_operate.deadline[task_struct_operate.deadlineVersion] - delta_cycles;
  siren_command("PRINTF: updating tput after operate, value=%l\n", value);
  slack = 0.3 * slack + value;
  if(value < 0 || slack < 0) {
    siren_command("PRINTF: app_1 underperforming\n");
    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = -1;
    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;
    manage_underperf();
  } else if(value > 0 && slack > 0) {
    siren_command("PRINTF: app_1 overperforming\n");
    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = 1;
    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;
    if(selected_app == 0 && selected_app < 2) {
      selected_app++;
    }
    manage_overperf();
  } else {
    siren_command("PRINTF: app_1 performance ok\n");
    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = 0;
    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;
  } if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) {
    task_struct_operate.deadline[!task_struct_operate.deadlineVersion & 0x1] = task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1];
    task_struct_operate.deadlineVersion = !task_struct_operate.deadlineVersion & 0x1;
  }
}
void
compress()
{
  acc_struct_t *lowpass = g_lowpass;
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running COMPRESS\n");
  int compress_out;
  __delay_cycles(20000);
  g_compress = compress_out;
  var_struct_compress.version_array[var_struct_compress.write_index] = g_compress;
  var_struct_compress.write_index = (var_struct_compress.write_index + 1) % (var_struct_compress.versions_count + 1);
  if(var_struct_compress.is_full) {
    var_struct_compress.window_begin_index = (var_struct_compress.window_begin_index + 1) % (var_struct_compress.versions_count + 1);
  } else if(var_struct_compress.write_index == 0) {
    var_struct_compress.is_full = 1;
    var_struct_compress.window_begin_index = (var_struct_compress.window_begin_index + 1) % (var_struct_compress.versions_count + 1);
  }
  if(var_struct_compress.write_count < var_struct_compress.versions_count) {
    var_struct_compress.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, compress\n", delta_cycles);
  slack -= delta_cycles;
  if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) {
    task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1] = 2000000;
    task_struct_compress.deadlineVersion = !task_struct_compress.deadlineVersion & 0x1;
  }
  extern task_struct_t task_struct_send;
  short int task_struct_send_enVersion = task_struct_send.isEnabledVersion;
  if(!(task_struct_send.isEnabled[task_struct_send_enVersion]) && (app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) && (1)) {
    task_struct_send.isEnabled[!task_struct_send_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_send;
    enabled_task_count++;
    task_struct_send.isEnabledVersion = !task_struct_send_enVersion & 0x1;
  }
  if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) {
    task_struct_send.deadline[!task_struct_send.deadlineVersion & 0x1] = task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1];
    task_struct_send.deadlineVersion = !task_struct_send.deadlineVersion & 0x1;
  }
}
void
send()
{
  acc_struct_t *compress = g_compress;
  siren_command("START_CCOUNT: task\n");
  siren_command("PRINTF: running SEND\n");
  int send_out;
  __delay_cycles(90000);
  g_send = send_out;
  var_struct_send.version_array[var_struct_send.write_index] = g_send;
  var_struct_send.write_index = (var_struct_send.write_index + 1) % (var_struct_send.versions_count + 1);
  if(var_struct_send.is_full) {
    var_struct_send.window_begin_index = (var_struct_send.window_begin_index + 1) % (var_struct_send.versions_count + 1);
  } else if(var_struct_send.write_index == 0) {
    var_struct_send.is_full = 1;
    var_struct_send.window_begin_index = (var_struct_send.window_begin_index + 1) % (var_struct_send.versions_count + 1);
  }
  if(var_struct_send.write_count < var_struct_send.versions_count) {
    var_struct_send.write_count++;
  }
  siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, send\n", delta_cycles);
  slack -= delta_cycles;
  long int value = task_struct_send.deadline[task_struct_send.deadlineVersion] - delta_cycles;
  siren_command("PRINTF: updating tput after send, value=%l\n", value);
  if(value < 0 || slack < 0) {
    siren_command("PRINTF: app_2 underperforming\n");
    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = -1;
    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;
    manage_underperf();
  } else if(value > 0 && slack > 0) {
    siren_command("PRINTF: app_2 overperforming\n");
    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = 1;
    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;
    if(selected_app == 0 && selected_app < 2) {
      selected_app++;
    }
    manage_overperf();
  } else {
    siren_command("PRINTF: app_2 performance ok\n");
    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = 0;
    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;
  } if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) {
    task_struct_send.deadline[!task_struct_send.deadlineVersion & 0x1] = task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1];
    task_struct_send.deadlineVersion = !task_struct_send.deadlineVersion & 0x1;
  }
}
task_struct_t __attribute__ ((persistent)) task_struct_sense = { .e_wc = 81, .in_set = {}, .in_set_count = 0, .function_pointer = &sense, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t __attribute__ ((persistent)) task_struct_median = { .e_wc = 33, .in_set = { &task_struct_sense }, .in_set_count = 1, .function_pointer = &median, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t __attribute__ ((persistent)) task_struct_lowpass = { .e_wc = 51, .in_set = { &task_struct_median }, .in_set_count = 1, .function_pointer = &lowpass, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t __attribute__ ((persistent)) task_struct_compress = { .e_wc = 21, .in_set = { &task_struct_lowpass }, .in_set_count = 1, .function_pointer = &compress, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t __attribute__ ((persistent)) task_struct_send = { .e_wc = 91, .in_set = { &task_struct_compress }, .in_set_count = 1, .function_pointer = &send, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t __attribute__ ((persistent)) task_struct_magnitude = { .e_wc = 16, .in_set = { &task_struct_lowpass }, .in_set_count = 1, .function_pointer = &magnitude, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t __attribute__ ((persistent)) task_struct_classify = { .e_wc = 16, .in_set = { &task_struct_magnitude }, .in_set_count = 1, .function_pointer = &classify, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t __attribute__ ((persistent)) task_struct_operate = { .e_wc = 31, .in_set = { &task_struct_classify }, .in_set_count = 1, .function_pointer = &operate, .isEnabled = { 0x0, 0x0 }, .isEnabledVersion = 0x0, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = { 0x0, 0x0 }, .stopped = 0, .app_pointer = ((void *)0) };
task_struct_t *__attribute__ ((persistent)) task_array[8] = { &task_struct_sense, &task_struct_median, &task_struct_lowpass, &task_struct_magnitude, &task_struct_classify, &task_struct_operate, &task_struct_compress, &task_struct_send };
task_struct_t *__attribute__ ((persistent)) active_task_array[8] = {};
int __attribute__ ((persistent)) active_task_count = 0;
task_struct_t *__attribute__ ((persistent)) enabled_task_array[8] = {};
int __attribute__ ((persistent)) enabled_task_count = 0;
app_struct_t __attribute__ ((persistent)) app_struct_app_1 = { .x_min = 333333, .x_ok = { 0, 0 }, .x_okVersion = 0x0, .tasks_count = 6, .app_tasks = { &task_struct_sense, &task_struct_median, &task_struct_lowpass, &task_struct_magnitude, &task_struct_classify, &task_struct_operate }, .initial_task = &task_struct_sense, .final_task = &task_struct_operate, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0 };
app_struct_t __attribute__ ((persistent)) app_struct_app_2 = { .x_min = 1000000, .x_ok = { 0, 0 }, .x_okVersion = 0x0, .tasks_count = 2, .app_tasks = { &task_struct_compress, &task_struct_send }, .initial_task = &task_struct_compress, .final_task = &task_struct_send, .isActive = { 0x0, 0x0 }, .isActiveVersion = 0x0 };
void
set_tasks_app_pointers()
{
  task_struct_sense.app_pointer = (void *)&(app_struct_app_1);
  task_struct_median.app_pointer = (void *)&(app_struct_app_1);
  task_struct_lowpass.app_pointer = (void *)&(app_struct_app_1);
  task_struct_magnitude.app_pointer = (void *)&(app_struct_app_1);
  task_struct_classify.app_pointer = (void *)&(app_struct_app_1);
  task_struct_operate.app_pointer = (void *)&(app_struct_app_1);
  task_struct_compress.app_pointer = (void *)&(app_struct_app_2);
  task_struct_send.app_pointer = (void *)&(app_struct_app_2);
}
app_struct_t *__attribute__ ((persistent)) app_array[2] = { &app_struct_app_1, &app_struct_app_2 };
app_struct_t *__attribute__ ((persistent)) active_app_array[2] = {};
int __attribute__ ((persistent)) active_app_count = 0;

void
subtract_cycles_from_all()
{
  for(short int i = 0, version; i < enabled_task_count; i++) {
    version = enabled_task_array[i]->deadlineVersion;
    enabled_task_array[i]->deadline[(!version) & 0x1] = enabled_task_array[i]->deadline[version] - delta_cycles;
    enabled_task_array[i]->deadlineVersion = (!version) & 0x1;
  }
  if(selected_app > 0) {
    slack -= delta_cycles;
  }
}
int
check_if_new(task_struct_t *task)
{
  for(int i = 0; i < active_task_count; i++) {
    if(active_task_array[i] == task) {
      return 0;
    }
  }
  return 1;
}
void
set_threshold(int energy)
{
  siren_command("SET_VON: %u\n", energy);
  return;
}
unsigned long int
get_exec_depth_x100()
{
  siren_command("GET_CAP_VOLTAGE: %u\n", &voltageX100);
  exec_depth_x100 = voltageX100 * voltageX100 * 235;
  return exec_depth_x100;
}
void
initialize()
{
  siren_command("PRINTF: initializing board after first boot.\n");
  siren_command("SET_TARDIS_VARIABLE: %u\n", &tardis_time);

  set_tasks_app_pointers();

  app_struct_t *app = app_array[active_app_count];
  short int version = app->isActiveVersion;
  app->isActive[(!version) & 0x1] |= 0x1;
  active_app_array[active_app_count] = app;
  app->isActiveVersion = (!version) & 0x1;
  active_app_count = 1;

  for(int i = 0; i < app->tasks_count; i++) {
    version = (app->app_tasks)[i]->isActiveVersion;
    (app->app_tasks)[i]->isActive[(!version) & 0x1] |= 0x1;
    (app->app_tasks)[i]->isActiveVersion = (!version) & 0x1;
    active_task_array[active_task_count] = (app->app_tasks)[i];
    active_task_count++;
  }

  task_struct_t *new_tasks[8];
  int new_task_counter;
  do {
    new_task_counter = 0;
    for(int i = 0; i < active_task_count; i++) {
      task_struct_t *task = active_task_array[i];
      for(int j = 0; j < task->in_set_count; j++) {
        task_struct_t *in_task = task->in_set[j];
        if(check_if_new(in_task)) {
          new_tasks[new_task_counter] = in_task;
          new_task_counter++;
        }
      }
    }
    for(int i = 0; i < new_task_counter; i++) {
      version = new_tasks[i]->isActiveVersion;
      new_tasks[i]->isActive[(!version) & 0x1] |= 0x1;
      new_tasks[i]->isActiveVersion = (!version) & 0x1;
      active_task_array[active_task_count] = new_tasks[i];
      active_task_count++;
    }
  } while(new_task_counter != 0);

  int energy_prediction[8];
  int max_energy_prediction = -10;
  for(int i = 0; i < active_task_count; i++) {
    energy_prediction[i] = active_task_array[i]->e_wc + 1.0 * active_task_array[i]->in_set_count;
    max_energy_prediction = (((max_energy_prediction) > (energy_prediction[i])) ? (max_energy_prediction) : (energy_prediction[i]));
  }

  for(int i = 0; i < active_task_count; i++) {
    if(active_task_array[i]->in_set_count == 0) {
      version = active_task_array[i]->deadlineVersion;
      active_task_array[i]->deadline[(!version) & 0x1] = app->x_min;
      active_task_array[i]->deadlineVersion = (!version) & 0x1;
      version = active_task_array[i]->isEnabledVersion;
      active_task_array[i]->isEnabled[(!version) & 0x1] |= 0x1;
      active_task_array[i]->isEnabledVersion = (!version) & 0x1;
      enabled_task_array[enabled_task_count] = active_task_array[i];
      enabled_task_count++;
    }
  }

  set_threshold(max_energy_prediction + 0);
  return;
}
void
scheduler()
{
  task_struct_t next_task_struct;

  siren_command("START_CCOUNT: scheduler\n");

  if(seen_resets != resets) {
    seen_resets = resets;
    if(next_task == 1) {

      if(is_pruning) {
        prune_tasks();
      }
    }
  }

  siren_command("GET_CCOUNT: scheduler-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, scheduler restore\n", delta_cycles);
  subtract_cycles_from_all();

  short int version;
  while(1) {

    siren_command("GET_TIME: misd(SENSE)-%u\n", &isSenseEnabled);

    if(isSenseEnabled) {
      task_struct_sense.stopped = 0;
    }

    heapsort(enabled_task_array, enabled_task_count);
    siren_command("START_CCOUNT: scheduler\n");
#261 "eval.c"
    unsigned long int exec_depth = get_exec_depth_x100();
#280 "eval.c"
    int selection = 0;
    siren_command("PRINTF: current selected app %u\n", selected_app);
    while(selected_app >= 0) {
      short int found = 0;
      while(selection < enabled_task_count && !found) {
        if(enabled_task_array[selection]->app_pointer != app_array[selected_app]) {

          selection++;
        } else if(enabled_task_array[selection]->stopped == 1) {

          selection++;
        } else if(exec_depth <= (enabled_task_array[selection]->e_wc) * 10) {

          selection++;
        } else if(selected_app > 0 && enabled_task_array[selection]->e_wc * 1000 > slack) {

          selection++;
        } else {
          found = 1;
        }
      }
      if(found) {
        break;
      }
      selected_app--;
      selection = 0;
    }

    siren_command("GET_CCOUNT: scheduler-%l\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %l, schedule\n", delta_cycles);
    subtract_cycles_from_all();

    if(selected_app == -1) {
      selected_app = 0;
    }

    if(selection == enabled_task_count) {
      siren_command("PRINTF: no task is currently available, sleeping for 1ms\n");
      siren_command("SLEEP_FOR_TIME: 1000\n");
      for(short int i = 0; i < enabled_task_count; i++) {
        enabled_task_array[i]->deadline[enabled_task_array[i]->deadlineVersion] -= 1000;
        slack -= 1000;
      }
    } else {
      next_task_struct = *(enabled_task_array[selection]);
      if(next_task_struct.function_pointer == task_struct_sense.function_pointer) {
        task_struct_sense.stopped = 1;
      }

      siren_command("PRINTF: selected task ewc = %l, slack = %l\n", next_task_struct.e_wc, slack);
      (next_task_struct.function_pointer)();

      if(next_task_struct.function_pointer == task_struct_sense.function_pointer) {

        if(var_struct_sense.write_count < 10) {
          version = task_struct_sense.deadlineVersion;
          task_struct_sense.deadline[version] = task_struct_sense.deadline[(!version) & 0x1];
        }
      } else if(next_task_struct.function_pointer == task_struct_operate.function_pointer) {
        siren_command("LOG_EVENT: app_1 done\n");
      } else if(next_task_struct.function_pointer == task_struct_send.function_pointer) {
        siren_command("LOG_EVENT: app_2 done\n");
      }
#383 "eval.c"
      for(int i = 0; i < enabled_task_count; i++) {
        version = enabled_task_array[i]->deadlineVersion;
        enabled_task_array[i]->deadline[(!version) & 0x1] = enabled_task_array[i]->deadline[version] - delta_cycles;
        enabled_task_array[i]->deadlineVersion = (!version) & 0x1;
      }
    }
  }
}
typedef struct queue {
  task_struct_t *array[8];
  short int size;
} queue_t;

queue_t __attribute__ ((persistent)) queues[2];
short int __attribute__ ((persistent)) valid_queue = 0;
app_struct_t __attribute__ ((persistent)) *removed;

app_struct_t *
remove_last_app()
{
  siren_command("PRINTF: removing app %u\n", active_app_count);
  app_struct_t *app = active_app_array[active_app_count - 1];
  short int isActiveVersion = app->isActiveVersion;
  active_app_count = 1;
  app->isActive[(!isActiveVersion) & 0x1] = 0x0;
  removed = app;
  queues[(!valid_queue) & 0x1].array[0] = removed->final_task;
  queues[(!valid_queue) & 0x1].size++;
  removed->final_task->marked_to_remove[(!valid_queue) & 0x1] = 1;
  is_pruning = 1;
  valid_queue = (!valid_queue) & 0x1;
  app->isActiveVersion = (!isActiveVersion) & 0x1;
  return app;
}
void
prune_tasks()
{
  if(removed->isActive[removed->isActiveVersion]) {
    queues[valid_queue].size = 0;
    is_pruning = 0;
    return;
  }
  while(queues[valid_queue].size != 0) {
    task_struct_t *task = queues[valid_queue].array[queues[valid_queue].size - 1];
    queues[(!valid_queue) & 0x1].size--;
    for(short int i = 0; i < task->in_set_count; i++) {

      short int remove = 1;
      for(short int j = 0; j < 2 && remove; j++) {
        for(short int k = 0; k < app_array[j]->tasks_count && remove; k++) {
          if(app_array[j]->app_tasks[k] == task && app_array[j]->isActive[app_array[j]->isActiveVersion]) {
            remove = 0;
          }
        }
      }
      if(remove) {
        if(task->in_set[i]->marked_to_remove[valid_queue] != 1) {

          short int size = queues[(!valid_queue) & 0x1].size;
          queues[(!valid_queue) & 0x1].array[size] = task->in_set[i];
          queues[(!valid_queue) & 0x1].size++;
          task->in_set[i]->marked_to_remove[(!valid_queue) & 0x1] = 1;
        }
      }
    }
    valid_queue = (!valid_queue) & 0x1;
  }

  for(short int i = 0; i < 8; i++) {
    if(task_array[i]->marked_to_remove[valid_queue] == 1) {

      for(int j = 0; j < active_task_count; j++) {
        if(active_task_array[j] == task_array[i]) {
          siren_command("PRINTF: ACTIVE TASK COUNT %u\n", active_task_count);
          active_task_array[j] = active_task_array[active_task_count - 1];
          active_task_count--;
        }
      }
      siren_command("PRINTF: ACTIVE %u\n", active_app_count);

      for(int j = 0; j < enabled_task_count; j++) {
        if(enabled_task_array[j] == task_array[i]) {
          enabled_task_array[j] = enabled_task_array[enabled_task_count - 1];
          enabled_task_count--;
        }
      }
      task_array[i]->marked_to_remove[valid_queue] = 0;
      task_array[i]->deadline[0] = 0;
      task_array[i]->deadline[1] = 0;
      task_array[i]->isEnabled[0] = 0;
      task_array[i]->isEnabled[1] = 0;
      task_array[i]->isActive[0] = 0;
      task_array[i]->isActive[1] = 0;
    }
  }
  is_pruning = 0;
  return;
}
void
reset_threshold()
{
  int energy_prediction[8];
  int max_energy_prediction = -10;
  for(int i = 0; i < active_task_count; i++) {
    energy_prediction[i] = active_task_array[i]->e_wc + 1.0 * active_task_array[i]->in_set_count;
    max_energy_prediction = (((max_energy_prediction) > (energy_prediction[i])) ? (max_energy_prediction) : (energy_prediction[i]));
  }
  set_threshold(max_energy_prediction + 0);
  return;
}
void
increase_threshold()
{
  siren_command("INCREASE_THRESHOLD:\n");
  return;
}
void
deactivate_2()
{

  short int appVersion = app_struct_app_2.isActiveVersion;
  app_struct_app_2.isActive[(!appVersion) & 0x1] = 0;

  short int send_index;
  short int compress_index;
  for(short int i = 0; i < active_task_count; i++) {
    if(active_task_array[i] == &task_struct_send) {
      send_index = i;
    } else if(active_task_array[i] == &task_struct_compress) {
      compress_index = i;
    }
  }
  active_task_array[compress_index] = active_task_array[active_task_count - 1];
  active_task_count--;

  active_task_array[send_index] = active_task_array[active_task_count - 1];
  active_task_count--;

  short int found_compress = 0;
  short int found_send = 0;
  for(short int i = 0; i < enabled_task_count; i++) {
    if(enabled_task_array[i] == &task_struct_send) {
      send_index = i;
      found_send = 1;
    } else if(enabled_task_array[i] == &task_struct_compress) {
      compress_index = i;
      found_compress = 1;
    }
  }
  if(found_compress) {
    enabled_task_array[compress_index] = enabled_task_array[enabled_task_count - 1];
    enabled_task_count--;
  }

  if(found_send) {
    enabled_task_array[send_index] = enabled_task_array[enabled_task_count - 1];
    enabled_task_count--;
  }

  task_struct_compress.deadline[0] = 0;
  task_struct_compress.deadline[1] = 0;
  task_struct_send.deadline[0] = 0;
  task_struct_send.deadline[1] = 0;

  task_struct_compress.isEnabled[0] = 0;
  task_struct_compress.isEnabled[1] = 0;
  task_struct_send.isEnabled[0] = 0;
  task_struct_send.isEnabled[1] = 0;

  task_struct_compress.isActive[0] = 0;
  task_struct_compress.isActive[1] = 0;
  task_struct_send.isActive[0] = 0;
  task_struct_send.isActive[1] = 0;

  active_app_count = 1;
  app_struct_app_2.isActiveVersion = (!appVersion) & 0x1;

  is_pruning = 0;
  siren_command("LOG_EVENT: app_2 OFF\n");
}
void
manage_underperf()
{
  char found = 0;

  if(app_struct_app_1.x_ok[app_struct_app_1.x_okVersion] == -1) {
    if(active_app_count == 1) {
      increase_threshold();
    } else {
      is_pruning = 1;
      deactivate_2();
      reset_threshold();
    }
  } else if(app_struct_app_2.x_ok[app_struct_app_2.x_okVersion] == -1) {
    increase_threshold();
  }
#594 "eval.c"
  return;
}
void
activate_new_app()
{
  if(active_app_count >= 2) {
    return;
  }
  app_struct_t *app = app_array[active_app_count];
  short int appVersion = app->isActiveVersion;
  app->isActive[(!appVersion) & 0x1] |= 0x1;

  active_app_count = 2;
  int added_tasks = 0;
  short int taskVersion;
  for(int i = 0; i < app->tasks_count; i++) {
    taskVersion = (app->app_tasks)[i]->isActiveVersion;
    if(!((app->app_tasks)[i]->isActive[taskVersion])) {
      (app->app_tasks)[i]->isActive[(!taskVersion) & 0x1] |= 0x1;
      (app->app_tasks)[i]->isActiveVersion = (!taskVersion) & 0x1;
      active_task_array[active_task_count] = (app->app_tasks)[i];
      active_task_count++;
      added_tasks++;
    }
  }
  app->isActiveVersion = (!appVersion) & 0x1;
  active_app_array[active_app_count - 1] = app;

  if(added_tasks == 0) {
    return;
  }

  task_struct_t *new_tasks[8];
  int new_task_counter;
  do {
    new_task_counter = 0;
    for(int i = 0; i < active_task_count; i++) {
      task_struct_t *task = active_task_array[i];
      for(int j = 0; j < task->in_set_count; j++) {
        task_struct_t *in_task = task->in_set[j];
        if(check_if_new(in_task)) {
          new_tasks[new_task_counter] = in_task;
          new_task_counter++;
        }
      }
    }
    for(int i = 0; i < new_task_counter; i++) {
      new_tasks[i]->isActive[(!taskVersion) & 0x1] |= 0x1;
      new_tasks[i]->isActiveVersion = (!taskVersion) & 0x1;
      active_task_array[active_task_count] = new_tasks[i];
      active_task_count++;
    }
  } while(new_task_counter != 0);

  for(int i = 0; i < active_task_count; i++) {
    taskVersion = active_task_array[i]->deadlineVersion;
    if(active_task_array[i]->in_set_count == 0 && !(active_task_array[i]->isActive[active_task_array[i]->isActiveVersion])) {
      active_task_array[i]->deadline[(!taskVersion) & 0x1] = app->x_min;
      active_task_array[i]->deadlineVersion = (!taskVersion) & 0x1;
      taskVersion = active_task_array[i]->isEnabledVersion;
      active_task_array[i]->isEnabled[(!taskVersion) & 0x1] |= 0x1;
      active_task_array[i]->isEnabledVersion = (!taskVersion) & 0x1;
      enabled_task_array[enabled_task_count] = active_task_array[i];
      enabled_task_count++;
    }
  }
  return;
}
void
manage_overperf()
{
  short int found = 0;
  short int version;
  for(int i = 0; i < active_app_count && !found; i++) {
    version = active_app_array[i]->x_okVersion;
    if(active_app_array[i]->x_ok[version] == 1 && active_app_count < 2) {
      found = 1;
      activate_new_app();
      siren_command("LOG_EVENT: app_2 ON\n");
      reset_threshold();
    }
  }
  return;
}
int
main()
{
  siren_command("START_CCOUNT: main\n");
  siren_command("GET_FREQ: %u\n", &frequency);
  siren_command("PRINTF: running @ %l Hz\n", frequency);
  WDTCTL = WDTPW | WDTHOLD;
  slack = 0;

  resets++;
  if(resets == 0) {
    initialize();
  } else {

    siren_command("PRINTF: restarted after %l microseconds\n", tardis_time);
    short int version;
    for(int i = 0; i < enabled_task_count; i++) {
      version = enabled_task_array[i]->deadlineVersion;
      enabled_task_array[i]->deadline[(!version) & 0x1] -= tardis_time;
      enabled_task_array[i]->deadlineVersion = (!version) & 0x1;
    }
    if(selected_app > 0) {
      slack -= tardis_time;
    }
  }

  siren_command("GET_CCOUNT: main-%l\n", &delta_cycles);
  siren_command("TEST_EXECUTION_CCOUNT: %l, main\n", delta_cycles);
  subtract_cycles_from_all();

  scheduler();
  return 0;
}
