#1 "test_single_task.c"
#1 "<built-in>" 1
#1 "<built-in>" 3
#362 "<built-in>" 3
#1 "<command line>" 1
#1 "<built-in>" 2
#1 "test_single_task.c" 2
#1 "./header.h" 1
typedef struct task_struct {
  int e_wc;
  struct task_struct *in_set[3];
  int in_set_count;
  unsigned long int deadline;
  void (*function_pointer)();
  char isEnabled;
} task_struct_t;

typedef struct app_struct {
  task_struct_t *app_tasks[5];
  task_struct_t *initial_task;
  task_struct_t *final_task;
  int tasks_count;
  unsigned long int x_min;
  char x_ok;
  char isActive;
} app_struct_t;
#2 "test_single_task.c" 2
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
#3 "test_single_task.c" 2
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
#4 "test_single_task.c" 2
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
#5 "test_single_task.c" 2

#1 "./fake_sensor.h" 1

int __attribute__ ((persistent)) samples[100] = { 0, 27, 91, 27, 43, 44, 5, 68, 2, 30, 40, 61, 92, 18, 88, 43, 2, 35, 24, 17, 32, 29, 79, 70, 63, 41, 0, 91, 22, 6, 63, 71, 98, 14, 35, 67, 60, 34, 41, 70, 89, 24, 54, 58, 64, 84, 14, 0, 53, 92, 22, 22, 20, 71, 94, 50, 19, 18, 87, 47, 79, 48, 9, 78, 37, 19, 35, 26, 99, 30, 91, 76, 90, 99, 82, 74, 31, 28, 80, 24, 39, 40, 58, 10, 74, 28, 29, 73, 9, 49, 33, 37, 66, 48, 86, 21, 7, 99, 60, 69 };
int __attribute__ ((persistent)) current_sample = 0;

int
get_sample()
{
  int sample = samples[current_sample];
  current_sample = (current_sample + 1) % 100;
  return sample;
}
void
reset_sensor()
{
  current_sample = 0;
}
#12 "test_single_task.c" 2

struct task_1_var_struct { int version_array[1 + 1];
                           short int versions_count;
                           short int window_begin_index;
                           short int write_index;
                           char is_full;
};
struct task_1_var_struct __attribute__ ((persistent)) var_struct_task_1 = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0 };
int g_task_1;
struct task_2_var_struct { int version_array[1 + 1];
                           short int versions_count;
                           short int window_begin_index;
                           short int write_index;
                           char is_full;
};
struct task_2_var_struct __attribute__ ((persistent)) var_struct_task_2 = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0 };
int g_task_2;
struct task_3_var_struct { int version_array[1 + 1];
                           short int versions_count;
                           short int window_begin_index;
                           short int write_index;
                           char is_full;
};
struct task_3_var_struct __attribute__ ((persistent)) var_struct_task_3 = { .versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0 };
int g_task_3;
extern app_struct_t *active_app_array[2];
extern int active_app_count;
extern task_struct_t *enabled_task_array[3];
extern int enabled_task_count;
extern task_struct_t task_struct_task_1;
extern task_struct_t task_struct_task_2;
extern task_struct_t task_struct_task_3;
extern app_struct_t app_struct_app_1;
extern app_struct_t app_struct_app_2;

int __attribute__ ((persistent)) delta_time = 0;
float __attribute__ ((persistent)) tputs[2] = { 0, 0 };

void
task_1()
{
  siren_command("START_TIME: task\n");
  siren_command("PRINTF: running task 1\n");
  int t1_out;
  t1_out = get_sample();
  g_task_1 = t1_out;
  var_struct_task_1.version_array[var_struct_task_1.write_index] = g_task_1;
  var_struct_task_1.write_index = (var_struct_task_1.write_index + 1) % (var_struct_task_1.versions_count + 1);
  if(var_struct_task_1.is_full) {
    var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1);
  } else if(var_struct_task_1.write_index == 0) {
    var_struct_task_1.is_full = 1;
    var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1);
  }
  siren_command("GET_TIME: task- %u\n", &delta_time);
  siren_command("TEST_EXECUTION: %u\n", delta_time);
  extern task_struct_t task_struct_task_2;
  if(!(task_struct_task_2.isEnabled) && (app_struct_app_1.isActive)) {
    task_struct_task_2.isEnabled |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_task_2;
    enabled_task_count++;
    if(app_struct_app_1.isActive) {
      task_struct_task_2.deadline = 1000000;
    }
  }
  extern task_struct_t task_struct_task_3;
  if(!(task_struct_task_3.isEnabled) && (app_struct_app_2.isActive)) {
    task_struct_task_3.isEnabled |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_task_3;
    enabled_task_count++;
    if(app_struct_app_2.isActive) {
      task_struct_task_3.deadline = 333333;
    }
  }
  if(app_struct_app_2.isActive) {
    task_struct_task_1.deadline = 333333;
  } else if(app_struct_app_1.isActive) {
    task_struct_task_1.deadline = 1000000;
  }
}
void
task_2()
{
  int task_1 = g_task_1;
  siren_command("START_TIME: task\n");
  siren_command("PRINTF: running task 2\n");
  int t2_output;
  t2_output = task_1 + 10;
  siren_command("LOG_EVENT: end app1\n");
  g_task_2 = t2_output;
  var_struct_task_2.version_array[var_struct_task_2.write_index] = g_task_2;
  var_struct_task_2.write_index = (var_struct_task_2.write_index + 1) % (var_struct_task_2.versions_count + 1);
  if(var_struct_task_2.is_full) {
    var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % (var_struct_task_2.versions_count + 1);
  } else if(var_struct_task_2.write_index == 0) {
    var_struct_task_2.is_full = 1;
    var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % (var_struct_task_2.versions_count + 1);
  }
  siren_command("GET_TIME: task- %u\n", &delta_time);
  siren_command("TEST_EXECUTION: %u\n", delta_time);
  unsigned long int value = 1000000 - task_struct_task_2.deadline - delta_time;
  siren_command("PRINTF: updating tput aftrer task_2\n");
  if(value < 0) {
    siren_command("PRINTF: underperforming\n");
    app_struct_app_1.x_ok = -1;
  } else if(value > 0) {
    siren_command("PRINTF: overperforming\n");
    app_struct_app_1.x_ok = 1;
  } else {
    siren_command("PRINTF: performance ok\n");
    app_struct_app_1.x_ok = 0;
  } if(app_struct_app_1.isActive) {
    task_struct_task_2.deadline = 1000000;
  }
}
void
task_3()
{
  int task_1 = g_task_1;
  siren_command("START_TIME: task\n");
  siren_command("PRINTF: running task 3\n");
  int t3_output;
  t3_output = task_1 * 10;
  siren_command("LOG_EVENT: end app2\n");
  g_task_3 = t3_output;
  var_struct_task_3.version_array[var_struct_task_3.write_index] = g_task_3;
  var_struct_task_3.write_index = (var_struct_task_3.write_index + 1) % (var_struct_task_3.versions_count + 1);
  if(var_struct_task_3.is_full) {
    var_struct_task_3.window_begin_index = (var_struct_task_3.window_begin_index + 1) % (var_struct_task_3.versions_count + 1);
  } else if(var_struct_task_3.write_index == 0) {
    var_struct_task_3.is_full = 1;
    var_struct_task_3.window_begin_index = (var_struct_task_3.window_begin_index + 1) % (var_struct_task_3.versions_count + 1);
  }
  siren_command("GET_TIME: task- %u\n", &delta_time);
  siren_command("TEST_EXECUTION: %u\n", delta_time);
  unsigned long int value = 333333 - task_struct_task_3.deadline - delta_time;
  siren_command("PRINTF: updating tput aftrer task_3\n");
  if(value < 0) {
    siren_command("PRINTF: underperforming\n");
    app_struct_app_2.x_ok = -1;
  } else if(value > 0) {
    siren_command("PRINTF: overperforming\n");
    app_struct_app_2.x_ok = 1;
  } else {
    siren_command("PRINTF: performance ok\n");
    app_struct_app_2.x_ok = 0;
  } if(app_struct_app_2.isActive) {
    task_struct_task_3.deadline = 333333;
  }
}
task_struct_t __attribute__ ((persistent)) task_struct_task_1 = { .e_wc = 450, .in_set = {}, .in_set_count = 0, .function_pointer = &task_1, .isEnabled = 0x0 };
task_struct_t __attribute__ ((persistent)) task_struct_task_3 = { .e_wc = 250, .in_set = { &task_struct_task_1 }, .in_set_count = 1, .function_pointer = &task_3, .isEnabled = 0x0 };
task_struct_t __attribute__ ((persistent)) task_struct_task_2 = { .e_wc = 150, .in_set = { &task_struct_task_1 }, .in_set_count = 1, .function_pointer = &task_2, .isEnabled = 0x0 };
task_struct_t *__attribute__ ((persistent)) task_array[3] = { &task_struct_task_1, &task_struct_task_2, &task_struct_task_3 };
task_struct_t *__attribute__ ((persistent)) active_task_array[3] = {};
int __attribute__ ((persistent)) active_task_count = 0;
task_struct_t *__attribute__ ((persistent)) enabled_task_array[3] = {};
int __attribute__ ((persistent)) enabled_task_count = 0;
app_struct_t __attribute__ ((persistent)) app_struct_app_1 = { .x_min = 1000000, .x_ok = 0, .tasks_count = 2, .app_tasks = { &task_struct_task_1, &task_struct_task_2 }, .initial_task = &task_struct_task_1, .final_task = &task_struct_task_2, .isActive = 0x0 };
app_struct_t __attribute__ ((persistent)) app_struct_app_2 = { .x_min = 333333, .x_ok = 0, .tasks_count = 2, .app_tasks = { &task_struct_task_1, &task_struct_task_3 }, .initial_task = &task_struct_task_1, .final_task = &task_struct_task_3, .isActive = 0x0 };
app_struct_t *__attribute__ ((persistent)) app_array[2] = { &app_struct_app_1, &app_struct_app_2 };
app_struct_t *__attribute__ ((persistent)) active_app_array[2] = {};
int __attribute__ ((persistent)) active_app_count = 0;

int
main()
{
  task_1();
  return 0;
}
