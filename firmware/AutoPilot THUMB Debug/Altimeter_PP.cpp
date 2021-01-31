# 1 "C:/projects/flight/firmware/src/Altimeter.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/projects/flight/firmware/src/Altimeter.cpp"
# 1 "include/Altimeter.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 11 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 1 3 4
# 14 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__crossworks.h" 1 3 4
# 39 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__crossworks.h" 3 4
typedef __builtin_va_list __va_list;
# 89 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__crossworks.h" 3 4
struct __mbstate_s {
  int __state;
  long __wchar;
};

typedef int (__RAL_mb_encode_t)(char *s, unsigned wc, struct __mbstate_s *codec);
typedef int (__RAL_mb_decode_t)(unsigned *pwc, const char *s, unsigned len, struct __mbstate_s *codec);

typedef struct {

  const char *decimal_point;
  const char *thousands_sep;
  const char *grouping;

  const char *int_curr_symbol;
  const char *currency_symbol;
  const char *mon_decimal_point;
  const char *mon_thousands_sep;
  const char *mon_grouping;
  const char *positive_sign;
  const char *negative_sign;

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




  const char *day_names;
  const char *abbrev_day_names;
  const char *month_names;
  const char *abbrev_month_names;
  const char *am_pm_indicator;
  const char *date_format;
  const char *time_format;
  const char *date_time_format;
} __RAL_locale_data_t;

enum {
  __RAL_WC_ALNUM = 1,
  __RAL_WC_ALPHA,
  __RAL_WC_CNTRL,
  __RAL_WC_DIGIT,
  __RAL_WC_GRAPH,
  __RAL_WC_LOWER,
  __RAL_WC_UPPER,
  __RAL_WC_SPACE,
  __RAL_WC_PRINT,
  __RAL_WC_PUNCT,
  __RAL_WC_BLANK,
  __RAL_WC_XDIGIT
};

enum {
  __RAL_WT_TOLOWER = 1,
  __RAL_WT_TOUPPER
};

typedef struct {

  int (*__isctype)(int, int);
  int (*__toupper)(int);
  int (*__tolower)(int);


  int (*__iswctype)(long, int);
  long (*__towupper)(long);
  long (*__towlower)(long);


  int (*__wctomb)(char *s, unsigned wc, struct __mbstate_s *state);
  int (*__mbtowc)(unsigned *pwc, const char *s, unsigned len, struct __mbstate_s *state);
} __RAL_locale_codeset_t;

typedef struct {
  const char *name;
  const __RAL_locale_data_t *data;
  const __RAL_locale_codeset_t *codeset;
} __RAL_locale_t;



typedef struct __locale_s {
  const __RAL_locale_t *__category[5];
} *__locale_t;


const __RAL_locale_t *__user_find_locale(const char *locale);
# 202 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__crossworks.h" 3 4
const __RAL_locale_t *__RAL_find_locale(const char *locale);







const __RAL_locale_t *__RAL_global_locale_category(int __category);







const __RAL_locale_t *__RAL_locale_category(__locale_t __locale, int __category);






extern struct __locale_s __RAL_global_locale;






extern const __RAL_locale_t __RAL_c_locale;


extern const __RAL_locale_codeset_t __RAL_codeset_ascii;
extern const __RAL_locale_codeset_t __RAL_codeset_utf8;

extern const unsigned char __RAL_ascii_ctype_map[128];

extern const char __RAL_c_locale_day_names[];
extern const char __RAL_c_locale_abbrev_day_names[];
extern const char __RAL_c_locale_month_names[];
extern const char __RAL_c_locale_abbrev_month_names[];

extern const char __RAL_data_utf8_period[];
extern const char __RAL_data_utf8_comma[];
extern const char __RAL_data_utf8_space[];
extern const char __RAL_data_utf8_plus[];
extern const char __RAL_data_utf8_minus[];
extern const char __RAL_data_empty_string[];

const char *__RAL_string_list_decode(const char *str, int index);
int __RAL_string_list_encode(const char *list, const char *str);


void __RAL_init_mbstate(struct __mbstate_s *state);

int __RAL_ascii_wctomb(char *s, unsigned wc, struct __mbstate_s *state);
int __RAL_ascii_mbtowc(unsigned *pwc, const char *s, unsigned len, struct __mbstate_s *state);

int __RAL_utf8_wctomb(char *s, unsigned wc, struct __mbstate_s *state);
int __RAL_utf8_mbtowc(unsigned *pwc, const char *s, unsigned len, struct __mbstate_s *state);

int __RAL_mb_max(const struct __locale_s *loc);

struct timeval;


int __RAL_compare_locale_name(const char *str0, const char *str1);


extern int (*__user_set_time_of_day)(const struct timeval *tp);
extern int (*__user_get_time_of_day)(struct timeval *tp);


typedef struct { unsigned short min, max, map; } __RAL_unicode_map_bmp_range_t;
typedef struct { unsigned short cp, map; } __RAL_unicode_map_bmp_singleton_t;


typedef struct { unsigned short min, max; } __RAL_unicode_set_bmp_range_t;
typedef struct { long min, max; } __RAL_unicode_set_nonbmp_range_t;


int __RAL_unicode_iswctype(long ch, int ty);
long __RAL_unicode_towupper(long ch);
long __RAL_unicode_towlower(long ch);


int __RAL_unicode_map_range_search(const void *k0, const void *k1);
int __RAL_unicode_map_singleton_search(const void *k0, const void *k1);


int __RAL_unicode_set_bmp_range_search(const void *k0, const void *k1);
int __RAL_unicode_set_nonbmp_range_search(const void *k0, const void *k1);

typedef const char * (*__RAL_error_decoder_fn_t)(int error);

typedef struct __RAL_error_decoder_s
{
  __RAL_error_decoder_fn_t decode;
  struct __RAL_error_decoder_s *next;
} __RAL_error_decoder_t;

void __RAL_register_error_decoder(__RAL_error_decoder_t *decoder);

extern __RAL_error_decoder_t *__RAL_error_decoder_head;

const char *__RAL_decode_error(int num);
# 15 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 2 3 4


extern "C" {
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
void *debug_fopen(const char *filename, const char *mode);
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fflush(void *stream);
# 69 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fclose(void *stream);
# 88 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fprintf(void *stream, const char *format, ...);
# 107 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_printf(const char *format, ...);
# 126 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fscanf(void *stream, const char *format, ...);
# 145 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_scanf(const char *format, ...);
# 156 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getchar(void);
# 166 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
char *debug_gets(char *s);
# 180 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_geti(int *i);
# 194 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getu(unsigned *u);
# 208 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getl(long *l);
# 222 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getul(unsigned long *ul);
# 232 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getf(float *f);
# 242 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getd(double *);
# 256 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getll(long long *ll);
# 270 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getull(unsigned long long *ull);






int debug_fgetc(void *stream);
# 288 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
char *debug_fgets(char *s, int n, void *stream);
# 297 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fputc(int c, void *stream);
# 307 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fputs(const char *s, void *stream);
# 316 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_putchar(int c);
# 325 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_puts(const char *);
# 336 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fread(void *ptr, int size, int nobj, void *stream);
# 347 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fwrite(void *ptr, int size, int nobj, void *stream);
# 364 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_fseek(void *stream, long offset, int origin);
# 373 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
long debug_ftell(void *stream);







void debug_rewind(void *stream);
# 390 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_filesize(void *stream);






void debug_clearerr(void *stream);






int debug_feof(void *stream);






int debug_ferror(void *stream);







int debug_kbhit(void);







int debug_getch(void);
# 436 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
void debug_runtime_error(const char *error);







void debug_break(void);





void debug_exit(int result);





void debug_abort(void);






long debug_time(long *ptr);
# 505 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_vfprintf(void *stream, const char *format, __va_list);







int debug_vprintf(const char *format, __va_list);







int debug_vfscanf(void *stream, const char *format, __va_list);







int debug_vscanf(const char *format, __va_list);







int debug_ungetc(int c, void *stream);






int debug_fgetpos(void *stream, long *pos);






int debug_fsetpos(void *stream, const long *pos);







void *debug_freopen(const char *filename, const char *mode, void *stream);







void debug_perror(const char *s);
# 576 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_remove(const char *filename);
# 586 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_rename(const char *oldfilename, const char *newfilename);







void *debug_tmpfile(void);
# 603 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
char *debug_tmpnam(char *str);







char *debug_getenv(char *name);







int debug_system(char *command);
# 628 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
int debug_getargs(unsigned bufsize, unsigned char *buf);
# 640 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
void debug_loadsymbols(const char *filename, const void *address, const char *breaksymbol);
# 649 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cross_studio_io.h" 3 4
void debug_unloadsymbols(const char *filename);







int debug_enabled(void);



}
# 11 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 2 3 4
# 5 "include/Altimeter.h" 2
# 1 "include/core/stm32f4xx.h" 1
# 57 "include/core/stm32f4xx.h"
 extern "C" {
# 171 "include/core/stm32f4xx.h"
typedef enum IRQn
{

  NonMaskableInt_IRQn = -14,
  MemoryManagement_IRQn = -12,
  BusFault_IRQn = -11,
  UsageFault_IRQn = -10,
  SVCall_IRQn = -5,
  DebugMonitor_IRQn = -4,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,

  WWDG_IRQn = 0,
  PVD_IRQn = 1,
  TAMP_STAMP_IRQn = 2,
  RTC_WKUP_IRQn = 3,
  FLASH_IRQn = 4,
  RCC_IRQn = 5,
  EXTI0_IRQn = 6,
  EXTI1_IRQn = 7,
  EXTI2_IRQn = 8,
  EXTI3_IRQn = 9,
  EXTI4_IRQn = 10,
  DMA1_Stream0_IRQn = 11,
  DMA1_Stream1_IRQn = 12,
  DMA1_Stream2_IRQn = 13,
  DMA1_Stream3_IRQn = 14,
  DMA1_Stream4_IRQn = 15,
  DMA1_Stream5_IRQn = 16,
  DMA1_Stream6_IRQn = 17,
  ADC_IRQn = 18,
# 270 "include/core/stm32f4xx.h"
  CAN1_TX_IRQn = 19,
  CAN1_RX0_IRQn = 20,
  CAN1_RX1_IRQn = 21,
  CAN1_SCE_IRQn = 22,
  EXTI9_5_IRQn = 23,
  TIM1_BRK_TIM9_IRQn = 24,
  TIM1_UP_TIM10_IRQn = 25,
  TIM1_TRG_COM_TIM11_IRQn = 26,
  TIM1_CC_IRQn = 27,
  TIM2_IRQn = 28,
  TIM3_IRQn = 29,
  TIM4_IRQn = 30,
  I2C1_EV_IRQn = 31,
  I2C1_ER_IRQn = 32,
  I2C2_EV_IRQn = 33,
  I2C2_ER_IRQn = 34,
  SPI1_IRQn = 35,
  SPI2_IRQn = 36,
  USART1_IRQn = 37,
  USART2_IRQn = 38,
  USART3_IRQn = 39,
  EXTI15_10_IRQn = 40,
  RTC_Alarm_IRQn = 41,
  OTG_FS_WKUP_IRQn = 42,
  TIM8_BRK_TIM12_IRQn = 43,
  TIM8_UP_TIM13_IRQn = 44,
  TIM8_TRG_COM_TIM14_IRQn = 45,
  TIM8_CC_IRQn = 46,
  DMA1_Stream7_IRQn = 47,
  FMC_IRQn = 48,
  SDIO_IRQn = 49,
  TIM5_IRQn = 50,
  SPI3_IRQn = 51,
  UART4_IRQn = 52,
  UART5_IRQn = 53,
  TIM6_DAC_IRQn = 54,
  TIM7_IRQn = 55,
  DMA2_Stream0_IRQn = 56,
  DMA2_Stream1_IRQn = 57,
  DMA2_Stream2_IRQn = 58,
  DMA2_Stream3_IRQn = 59,
  DMA2_Stream4_IRQn = 60,
  ETH_IRQn = 61,
  ETH_WKUP_IRQn = 62,
  CAN2_TX_IRQn = 63,
  CAN2_RX0_IRQn = 64,
  CAN2_RX1_IRQn = 65,
  CAN2_SCE_IRQn = 66,
  OTG_FS_IRQn = 67,
  DMA2_Stream5_IRQn = 68,
  DMA2_Stream6_IRQn = 69,
  DMA2_Stream7_IRQn = 70,
  USART6_IRQn = 71,
  I2C3_EV_IRQn = 72,
  I2C3_ER_IRQn = 73,
  OTG_HS_EP1_OUT_IRQn = 74,
  OTG_HS_EP1_IN_IRQn = 75,
  OTG_HS_WKUP_IRQn = 76,
  OTG_HS_IRQn = 77,
  DCMI_IRQn = 78,
  CRYP_IRQn = 79,
  HASH_RNG_IRQn = 80,
  FPU_IRQn = 81,
  UART7_IRQn = 82,
  UART8_IRQn = 83,
  SPI4_IRQn = 84,
  SPI5_IRQn = 85,
  SPI6_IRQn = 86,
  SAI1_IRQn = 87,
  DMA2D_IRQn = 90
# 457 "include/core/stm32f4xx.h"
} IRQn_Type;





# 1 "include/core/core_cm4.h" 1
# 43 "include/core/core_cm4.h"
 extern "C" {
# 168 "include/core/core_cm4.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdint.h" 1 3 4
# 14 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdint.h" 3 4
typedef signed char int8_t;
typedef unsigned char uint8_t;




typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
# 35 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdint.h" 3 4
typedef signed long long int64_t;
typedef unsigned long long uint64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int32_t int_fast8_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef uint32_t uint_fast8_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef int32_t intptr_t;
typedef uint32_t uintptr_t;
# 85 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdint.h" 3 4
typedef int64_t intmax_t;
typedef uint64_t uintmax_t;
# 169 "include/core/core_cm4.h" 2
# 1 "include/core/core_cmInstr.h" 1
# 325 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline void __NOP(void)
{
  __asm volatile ("nop");
}







__attribute__( ( always_inline ) ) static inline void __WFI(void)
{
  __asm volatile ("wfi");
}







__attribute__( ( always_inline ) ) static inline void __WFE(void)
{
  __asm volatile ("wfe");
}






__attribute__( ( always_inline ) ) static inline void __SEV(void)
{
  __asm volatile ("sev");
}
# 369 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline void __ISB(void)
{
  __asm volatile ("isb");
}







__attribute__( ( always_inline ) ) static inline void __DSB(void)
{
  __asm volatile ("dsb");
}







__attribute__( ( always_inline ) ) static inline void __DMB(void)
{
  __asm volatile ("dmb");
}
# 404 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __REV(uint32_t value)
{

  return __builtin_bswap32(value);






}
# 424 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 440 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline int32_t __REVSH(int32_t value)
{

  return (short)__builtin_bswap16(value);






}
# 461 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  return (op1 >> op2) | (op1 << (32 - op2));
}
# 487 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;

   __asm volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
   return(result);
}
# 503 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexb %0, %1" : "=r" (result) : "Q" (*addr) );






   return(result);
}
# 526 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexh %0, %1" : "=r" (result) : "Q" (*addr) );






   return(result);
}
# 549 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;

   __asm volatile ("ldrex %0, %1" : "=r" (result) : "Q" (*addr) );
   return(result);
}
# 567 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
   uint32_t result;

   __asm volatile ("strexb %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
   return(result);
}
# 585 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
   uint32_t result;

   __asm volatile ("strexh %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
   return(result);
}
# 603 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
   uint32_t result;

   __asm volatile ("strex %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
   return(result);
}







__attribute__( ( always_inline ) ) static inline void __CLREX(void)
{
  __asm volatile ("clrex" ::: "memory");
}
# 662 "include/core/core_cmInstr.h"
__attribute__( ( always_inline ) ) static inline uint8_t __CLZ(uint32_t value)
{
   uint32_t result;

  __asm volatile ("clz %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}
# 170 "include/core/core_cm4.h" 2
# 1 "include/core/core_cmFunc.h" 1
# 329 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}







__attribute__( ( always_inline ) ) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}
# 352 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 367 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}
# 379 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}
# 394 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}
# 409 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}
# 424 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_PSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, psp\n" : "=r" (result) );
  return(result);
}
# 439 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0\n" : : "r" (topOfProcStack) : "sp");
}
# 451 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_MSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, msp\n" : "=r" (result) );
  return(result);
}
# 466 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0\n" : : "r" (topOfMainStack) : "sp");
}
# 478 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
# 493 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 506 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __enable_fault_irq(void)
{
  __asm volatile ("cpsie f" : : : "memory");
}







__attribute__( ( always_inline ) ) static inline void __disable_fault_irq(void)
{
  __asm volatile ("cpsid f" : : : "memory");
}
# 529 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_BASEPRI(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, basepri_max" : "=r" (result) );
  return(result);
}
# 544 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __set_BASEPRI(uint32_t value)
{
  __asm volatile ("MSR basepri, %0" : : "r" (value) : "memory");
}
# 556 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_FAULTMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}
# 571 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 587 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_FPSCR(void)
{

  uint32_t result;


  __asm volatile ("");
  __asm volatile ("VMRS %0, fpscr" : "=r" (result) );
  __asm volatile ("");
  return(result);



}
# 609 "include/core/core_cmFunc.h"
__attribute__( ( always_inline ) ) static inline void __set_FPSCR(uint32_t fpscr)
{


  __asm volatile ("");
  __asm volatile ("VMSR fpscr, %0" : : "r" (fpscr) : "vfpcc");
  __asm volatile ("");

}
# 171 "include/core/core_cm4.h" 2
# 1 "include/core/core_cm4_simd.h" 1
# 39 "include/core/core_cm4_simd.h"
 extern "C" {
# 158 "include/core/core_cm4_simd.h"
__attribute__( ( always_inline ) ) static inline uint32_t __SADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SHADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UQADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UHADD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhadd8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}


__attribute__( ( always_inline ) ) static inline uint32_t __SSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SHSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __USUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UQSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UHSUB8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhsub8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}


__attribute__( ( always_inline ) ) static inline uint32_t __SADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SHADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UQADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UHADD16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhadd16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SHSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __USUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UQSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UHSUB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhsub16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SHASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UQASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UHASX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhasx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("ssax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SHSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("shsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __USAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UQSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uqsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UHSAX(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uhsax %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __USAD8(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("usad8 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __USADA8(uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("usada8 %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}
# 478 "include/core/core_cm4_simd.h"
__attribute__( ( always_inline ) ) static inline uint32_t __UXTB16(uint32_t op1)
{
  uint32_t result;

  __asm volatile ("uxtb16 %0, %1" : "=r" (result) : "r" (op1));
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __UXTAB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("uxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SXTB16(uint32_t op1)
{
  uint32_t result;

  __asm volatile ("sxtb16 %0, %1" : "=r" (result) : "r" (op1));
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SXTAB16(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sxtab16 %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SMUAD (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smuad %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SMUADX (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smuadx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SMLAD (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlad %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SMLADX (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smladx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}
# 556 "include/core/core_cm4_simd.h"
__attribute__( ( always_inline ) ) static inline uint32_t __SMUSD (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smusd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SMUSDX (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("smusdx %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SMLSD (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlsd %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __SMLSDX (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;

  __asm volatile ("smlsdx %0, %1, %2, %3" : "=r" (result) : "r" (op1), "r" (op2), "r" (op3) );
  return(result);
}
# 602 "include/core/core_cm4_simd.h"
__attribute__( ( always_inline ) ) static inline uint32_t __SEL (uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("sel %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QADD(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qadd %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}

__attribute__( ( always_inline ) ) static inline uint32_t __QSUB(uint32_t op1, uint32_t op2)
{
  uint32_t result;

  __asm volatile ("qsub %0, %1, %2" : "=r" (result) : "r" (op1), "r" (op2) );
  return(result);
}
# 643 "include/core/core_cm4_simd.h"
__attribute__( ( always_inline ) ) static inline uint32_t __SMMLA (int32_t op1, int32_t op2, int32_t op3)
{
 int32_t result;

 __asm volatile ("smmla %0, %1, %2, %3" : "=r" (result): "r" (op1), "r" (op2), "r" (op3) );
 return(result);
}
# 672 "include/core/core_cm4_simd.h"
}
# 172 "include/core/core_cm4.h" 2
# 251 "include/core/core_cm4.h"
typedef union
{
  struct
  {



    uint32_t _reserved0:16;
    uint32_t GE:4;
    uint32_t _reserved1:7;

    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} APSR_Type;




typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:23;
  } b;
  uint32_t w;
} IPSR_Type;




typedef union
{
  struct
  {
    uint32_t ISR:9;



    uint32_t _reserved0:7;
    uint32_t GE:4;
    uint32_t _reserved1:4;

    uint32_t T:1;
    uint32_t IT:2;
    uint32_t Q:1;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} xPSR_Type;




typedef union
{
  struct
  {
    uint32_t nPRIV:1;
    uint32_t SPSEL:1;
    uint32_t FPCA:1;
    uint32_t _reserved0:29;
  } b;
  uint32_t w;
} CONTROL_Type;
# 336 "include/core/core_cm4.h"
typedef struct
{
  volatile uint32_t ISER[8];
       uint32_t RESERVED0[24];
  volatile uint32_t ICER[8];
       uint32_t RSERVED1[24];
  volatile uint32_t ISPR[8];
       uint32_t RESERVED2[24];
  volatile uint32_t ICPR[8];
       uint32_t RESERVED3[24];
  volatile uint32_t IABR[8];
       uint32_t RESERVED4[56];
  volatile uint8_t IP[240];
       uint32_t RESERVED5[644];
  volatile uint32_t STIR;
} NVIC_Type;
# 368 "include/core/core_cm4.h"
typedef struct
{
  volatile uint32_t CPUID;
  volatile uint32_t ICSR;
  volatile uint32_t VTOR;
  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
  volatile uint8_t SHP[12];
  volatile uint32_t SHCSR;
  volatile uint32_t CFSR;
  volatile uint32_t HFSR;
  volatile uint32_t DFSR;
  volatile uint32_t MMFAR;
  volatile uint32_t BFAR;
  volatile uint32_t AFSR;
  volatile uint32_t PFR[2];
  volatile uint32_t DFR;
  volatile uint32_t ADR;
  volatile uint32_t MMFR[4];
  volatile uint32_t ISAR[5];
       uint32_t RESERVED0[5];
  volatile uint32_t CPACR;
} SCB_Type;
# 585 "include/core/core_cm4.h"
typedef struct
{
       uint32_t RESERVED0[1];
  volatile uint32_t ICTR;
  volatile uint32_t ACTLR;
} SCnSCB_Type;
# 623 "include/core/core_cm4.h"
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile uint32_t CALIB;
} SysTick_Type;
# 673 "include/core/core_cm4.h"
typedef struct
{
  volatile union
  {
    volatile uint8_t u8;
    volatile uint16_t u16;
    volatile uint32_t u32;
  } PORT [32];
       uint32_t RESERVED0[864];
  volatile uint32_t TER;
       uint32_t RESERVED1[15];
  volatile uint32_t TPR;
       uint32_t RESERVED2[15];
  volatile uint32_t TCR;
       uint32_t RESERVED3[29];
  volatile uint32_t IWR;
  volatile uint32_t IRR;
  volatile uint32_t IMCR;
       uint32_t RESERVED4[43];
  volatile uint32_t LAR;
  volatile uint32_t LSR;
       uint32_t RESERVED5[6];
  volatile uint32_t PID4;
  volatile uint32_t PID5;
  volatile uint32_t PID6;
  volatile uint32_t PID7;
  volatile uint32_t PID0;
  volatile uint32_t PID1;
  volatile uint32_t PID2;
  volatile uint32_t PID3;
  volatile uint32_t CID0;
  volatile uint32_t CID1;
  volatile uint32_t CID2;
  volatile uint32_t CID3;
} ITM_Type;
# 774 "include/core/core_cm4.h"
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t CYCCNT;
  volatile uint32_t CPICNT;
  volatile uint32_t EXCCNT;
  volatile uint32_t SLEEPCNT;
  volatile uint32_t LSUCNT;
  volatile uint32_t FOLDCNT;
  volatile uint32_t PCSR;
  volatile uint32_t COMP0;
  volatile uint32_t MASK0;
  volatile uint32_t FUNCTION0;
       uint32_t RESERVED0[1];
  volatile uint32_t COMP1;
  volatile uint32_t MASK1;
  volatile uint32_t FUNCTION1;
       uint32_t RESERVED1[1];
  volatile uint32_t COMP2;
  volatile uint32_t MASK2;
  volatile uint32_t FUNCTION2;
       uint32_t RESERVED2[1];
  volatile uint32_t COMP3;
  volatile uint32_t MASK3;
  volatile uint32_t FUNCTION3;
} DWT_Type;
# 919 "include/core/core_cm4.h"
typedef struct
{
  volatile uint32_t SSPSR;
  volatile uint32_t CSPSR;
       uint32_t RESERVED0[2];
  volatile uint32_t ACPR;
       uint32_t RESERVED1[55];
  volatile uint32_t SPPR;
       uint32_t RESERVED2[131];
  volatile uint32_t FFSR;
  volatile uint32_t FFCR;
  volatile uint32_t FSCR;
       uint32_t RESERVED3[759];
  volatile uint32_t TRIGGER;
  volatile uint32_t FIFO0;
  volatile uint32_t ITATBCTR2;
       uint32_t RESERVED4[1];
  volatile uint32_t ITATBCTR0;
  volatile uint32_t FIFO1;
  volatile uint32_t ITCTRL;
       uint32_t RESERVED5[39];
  volatile uint32_t CLAIMSET;
  volatile uint32_t CLAIMCLR;
       uint32_t RESERVED7[8];
  volatile uint32_t DEVID;
  volatile uint32_t DEVTYPE;
} TPI_Type;
# 1073 "include/core/core_cm4.h"
typedef struct
{
  volatile uint32_t TYPE;
  volatile uint32_t CTRL;
  volatile uint32_t RNR;
  volatile uint32_t RBAR;
  volatile uint32_t RASR;
  volatile uint32_t RBAR_A1;
  volatile uint32_t RASR_A1;
  volatile uint32_t RBAR_A2;
  volatile uint32_t RASR_A2;
  volatile uint32_t RBAR_A3;
  volatile uint32_t RASR_A3;
} MPU_Type;
# 1166 "include/core/core_cm4.h"
typedef struct
{
       uint32_t RESERVED0[1];
  volatile uint32_t FPCCR;
  volatile uint32_t FPCAR;
  volatile uint32_t FPDSCR;
  volatile uint32_t MVFR0;
  volatile uint32_t MVFR1;
} FPU_Type;
# 1271 "include/core/core_cm4.h"
typedef struct
{
  volatile uint32_t DHCSR;
  volatile uint32_t DCRSR;
  volatile uint32_t DCRDR;
  volatile uint32_t DEMCR;
} CoreDebug_Type;
# 1435 "include/core/core_cm4.h"
static inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07);

  reg_value = ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;
  reg_value &= ~((0xFFFFUL << 16) | (7UL << 8));
  reg_value = (reg_value |
                ((uint32_t)0x5FA << 16) |
                (PriorityGroupTmp << 8));
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = reg_value;
}
# 1455 "include/core/core_cm4.h"
static inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8)) >> 8);
}
# 1467 "include/core/core_cm4.h"
static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{

  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(uint32_t)((int32_t)IRQn) >> 5] = (uint32_t)(1 << ((uint32_t)((int32_t)IRQn) & (uint32_t)0x1F));
}
# 1480 "include/core/core_cm4.h"
static inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}
# 1496 "include/core/core_cm4.h"
static inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));
}
# 1508 "include/core/core_cm4.h"
static inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}
# 1520 "include/core/core_cm4.h"
static inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));
}
# 1535 "include/core/core_cm4.h"
static inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));
}
# 1550 "include/core/core_cm4.h"
static inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4)) & 0xff); }
  else {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4)) & 0xff); }
}
# 1570 "include/core/core_cm4.h"
static inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4))); }
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[(uint32_t)(IRQn)] >> (8 - 4))); }
}
# 1592 "include/core/core_cm4.h"
static inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;

  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority & ((1 << (SubPriorityBits )) - 1)))
         );
}
# 1620 "include/core/core_cm4.h"
static inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;

  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority = (Priority ) & ((1 << (SubPriorityBits )) - 1);
}






static inline void NVIC_SystemReset(void)
{
  __DSB();

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = ((0x5FA << 16) |
                 (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8)) |
                 (1UL << 2));
  __DSB();
  while(1);
}
# 1677 "include/core/core_cm4.h"
static inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1) > (0xFFFFFFUL << 0)) return (1);

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = ticks - 1;
  NVIC_SetPriority (SysTick_IRQn, (1<<4) - 1);
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL = 0;
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2) |
                   (1UL << 1) |
                   (1UL << 0);
  return (0);
}
# 1703 "include/core/core_cm4.h"
extern volatile int32_t ITM_RxBuffer;
# 1717 "include/core/core_cm4.h"
static inline uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL << 0)) &&
      (((ITM_Type *) (0xE0000000UL) )->TER & (1UL << 0) ) )
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000UL) )->PORT[0].u8 = (uint8_t) ch;
  }
  return (ch);
}
# 1736 "include/core/core_cm4.h"
static inline int32_t ITM_ReceiveChar (void) {
  int32_t ch = -1;

  if (ITM_RxBuffer != 0x5AA55AA5) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5;
  }

  return (ch);
}
# 1755 "include/core/core_cm4.h"
static inline int32_t ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5) {
    return (0);
  } else {
    return (1);
  }
}
# 1771 "include/core/core_cm4.h"
}
# 464 "include/core/stm32f4xx.h" 2
# 1 "C:/Users/johnz/AppData/Local/Rowley Associates Limited/CrossWorks for ARM/v3/packages/targets/STM32/include/system_stm32f4xx.h" 1
# 53 "C:/Users/johnz/AppData/Local/Rowley Associates Limited/CrossWorks for ARM/v3/packages/targets/STM32/include/system_stm32f4xx.h"
 extern "C" {
# 76 "C:/Users/johnz/AppData/Local/Rowley Associates Limited/CrossWorks for ARM/v3/packages/targets/STM32/include/system_stm32f4xx.h"
extern uint32_t SystemCoreClock;
# 103 "C:/Users/johnz/AppData/Local/Rowley Associates Limited/CrossWorks for ARM/v3/packages/targets/STM32/include/system_stm32f4xx.h"
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);





}
# 465 "include/core/stm32f4xx.h" 2






typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;

typedef const int32_t sc32;
typedef const int16_t sc16;
typedef const int8_t sc8;

typedef volatile int32_t vs32;
typedef volatile int16_t vs16;
typedef volatile int8_t vs8;

typedef volatile int32_t vsc32;
typedef volatile int16_t vsc16;
typedef volatile int8_t vsc8;

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef const uint32_t uc32;
typedef const uint16_t uc16;
typedef const uint8_t uc8;

typedef volatile uint32_t vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t vu8;

typedef volatile uint32_t vuc32;
typedef volatile uint16_t vuc16;
typedef volatile uint8_t vuc8;

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;
# 522 "include/core/stm32f4xx.h"
typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CCR;
  volatile uint32_t CDR;

} ADC_Common_TypeDef;






typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;





typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;





typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;





typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t RESERVED2;
  volatile uint32_t FS1R;
  uint32_t RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t RESERVED4;
  volatile uint32_t FA1R;
  uint32_t RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[28];
} CAN_TypeDef;





typedef struct
{
  volatile uint32_t DR;
  volatile uint8_t IDR;
  uint8_t RESERVED0;
  uint16_t RESERVED1;
  volatile uint32_t CR;
} CRC_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;
  volatile uint32_t SR;
} DAC_TypeDef;





typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
  volatile uint32_t APB1FZ;
  volatile uint32_t APB2FZ;
}DBGMCU_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t RISR;
  volatile uint32_t IER;
  volatile uint32_t MISR;
  volatile uint32_t ICR;
  volatile uint32_t ESCR;
  volatile uint32_t ESUR;
  volatile uint32_t CWSTRTR;
  volatile uint32_t CWSIZER;
  volatile uint32_t DR;
} DCMI_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t NDTR;
  volatile uint32_t PAR;
  volatile uint32_t M0AR;
  volatile uint32_t M1AR;
  volatile uint32_t FCR;
} DMA_Stream_TypeDef;

typedef struct
{
  volatile uint32_t LISR;
  volatile uint32_t HISR;
  volatile uint32_t LIFCR;
  volatile uint32_t HIFCR;
} DMA_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
  volatile uint32_t FGMAR;
  volatile uint32_t FGOR;
  volatile uint32_t BGMAR;
  volatile uint32_t BGOR;
  volatile uint32_t FGPFCCR;
  volatile uint32_t FGCOLR;
  volatile uint32_t BGPFCCR;
  volatile uint32_t BGCOLR;
  volatile uint32_t FGCMAR;
  volatile uint32_t BGCMAR;
  volatile uint32_t OPFCCR;
  volatile uint32_t OCOLR;
  volatile uint32_t OMAR;
  volatile uint32_t OOR;
  volatile uint32_t NLR;
  volatile uint32_t LWR;
  volatile uint32_t AMTCR;
  uint32_t RESERVED[236];
  volatile uint32_t FGCLUT[256];
  volatile uint32_t BGCLUT[256];
} DMA2D_TypeDef;





typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;
  uint32_t RESERVED0[2];
  volatile uint32_t MACRWUFFR;
  volatile uint32_t MACPMTCSR;
  uint32_t RESERVED1[2];
  volatile uint32_t MACSR;
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;
  uint32_t RESERVED2[40];
  volatile uint32_t MMCCR;
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;
  uint32_t RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;
  volatile uint32_t MMCTGFMSCCR;
  uint32_t RESERVED4[5];
  volatile uint32_t MMCTGFCR;
  uint32_t RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
  uint32_t RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
  uint32_t RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
  volatile uint32_t RESERVED8;
  volatile uint32_t PTPTSSR;
  uint32_t RESERVED9[565];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
  volatile uint32_t DMARSWTR;
  uint32_t RESERVED10[8];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;





typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;





typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t OPTCR;
  volatile uint32_t OPTCR1;
} FLASH_TypeDef;
# 907 "include/core/stm32f4xx.h"
typedef struct
{
  volatile uint32_t BTCR[8];
} FMC_Bank1_TypeDef;





typedef struct
{
  volatile uint32_t BWTR[7];
} FMC_Bank1E_TypeDef;





typedef struct
{
  volatile uint32_t PCR2;
  volatile uint32_t SR2;
  volatile uint32_t PMEM2;
  volatile uint32_t PATT2;
  uint32_t RESERVED0;
  volatile uint32_t ECCR2;
} FMC_Bank2_TypeDef;





typedef struct
{
  volatile uint32_t PCR3;
  volatile uint32_t SR3;
  volatile uint32_t PMEM3;
  volatile uint32_t PATT3;
  uint32_t RESERVED0;
  volatile uint32_t ECCR3;
} FMC_Bank3_TypeDef;





typedef struct
{
  volatile uint32_t PCR4;
  volatile uint32_t SR4;
  volatile uint32_t PMEM4;
  volatile uint32_t PATT4;
  volatile uint32_t PIO4;
} FMC_Bank4_TypeDef;





typedef struct
{
  volatile uint32_t SDCR[2];
  volatile uint32_t SDTR[2];
  volatile uint32_t SDCMR;
  volatile uint32_t SDRTR;
  volatile uint32_t SDSR;
} FMC_Bank5_6_TypeDef;






typedef struct
{
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint16_t BSRRL;
  volatile uint16_t BSRRH;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
} GPIO_TypeDef;





typedef struct
{
  volatile uint32_t MEMRMP;
  volatile uint32_t PMC;
  volatile uint32_t EXTICR[4];
  uint32_t RESERVED[2];
  volatile uint32_t CMPCR;
} SYSCFG_TypeDef;





typedef struct
{
  volatile uint16_t CR1;
  uint16_t RESERVED0;
  volatile uint16_t CR2;
  uint16_t RESERVED1;
  volatile uint16_t OAR1;
  uint16_t RESERVED2;
  volatile uint16_t OAR2;
  uint16_t RESERVED3;
  volatile uint16_t DR;
  uint16_t RESERVED4;
  volatile uint16_t SR1;
  uint16_t RESERVED5;
  volatile uint16_t SR2;
  uint16_t RESERVED6;
  volatile uint16_t CCR;
  uint16_t RESERVED7;
  volatile uint16_t TRISE;
  uint16_t RESERVED8;
  volatile uint16_t FLTR;
  uint16_t RESERVED9;
} I2C_TypeDef;





typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_TypeDef;





typedef struct
{
  uint32_t RESERVED0[2];
  volatile uint32_t SSCR;
  volatile uint32_t BPCR;
  volatile uint32_t AWCR;
  volatile uint32_t TWCR;
  volatile uint32_t GCR;
  uint32_t RESERVED1[2];
  volatile uint32_t SRCR;
  uint32_t RESERVED2[1];
  volatile uint32_t BCCR;
  uint32_t RESERVED3[1];
  volatile uint32_t IER;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t LIPCR;
  volatile uint32_t CPSR;
  volatile uint32_t CDSR;
} LTDC_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t WHPCR;
  volatile uint32_t WVPCR;
  volatile uint32_t CKCR;
  volatile uint32_t PFCR;
  volatile uint32_t CACR;
  volatile uint32_t DCCR;
  volatile uint32_t BFCR;
  uint32_t RESERVED0[2];
  volatile uint32_t CFBAR;
  volatile uint32_t CFBLR;
  volatile uint32_t CFBLNR;
  uint32_t RESERVED1[3];
  volatile uint32_t CLUTWR;

} LTDC_Layer_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t AHB1RSTR;
  volatile uint32_t AHB2RSTR;
  volatile uint32_t AHB3RSTR;
  uint32_t RESERVED0;
  volatile uint32_t APB1RSTR;
  volatile uint32_t APB2RSTR;
  uint32_t RESERVED1[2];
  volatile uint32_t AHB1ENR;
  volatile uint32_t AHB2ENR;
  volatile uint32_t AHB3ENR;
  uint32_t RESERVED2;
  volatile uint32_t APB1ENR;
  volatile uint32_t APB2ENR;
  uint32_t RESERVED3[2];
  volatile uint32_t AHB1LPENR;
  volatile uint32_t AHB2LPENR;
  volatile uint32_t AHB3LPENR;
  uint32_t RESERVED4;
  volatile uint32_t APB1LPENR;
  volatile uint32_t APB2LPENR;
  uint32_t RESERVED5[2];
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
  uint32_t RESERVED6[2];
  volatile uint32_t SSCGR;
  volatile uint32_t PLLI2SCFGR;
  volatile uint32_t PLLSAICFGR;
  volatile uint32_t DCKCFGR;

} RCC_TypeDef;





typedef struct
{
  volatile uint32_t TR;
  volatile uint32_t DR;
  volatile uint32_t CR;
  volatile uint32_t ISR;
  volatile uint32_t PRER;
  volatile uint32_t WUTR;
  volatile uint32_t CALIBR;
  volatile uint32_t ALRMAR;
  volatile uint32_t ALRMBR;
  volatile uint32_t WPR;
  volatile uint32_t SSR;
  volatile uint32_t SHIFTR;
  volatile uint32_t TSTR;
  volatile uint32_t TSDR;
  volatile uint32_t TSSSR;
  volatile uint32_t CALR;
  volatile uint32_t TAFCR;
  volatile uint32_t ALRMASSR;
  volatile uint32_t ALRMBSSR;
  uint32_t RESERVED7;
  volatile uint32_t BKP0R;
  volatile uint32_t BKP1R;
  volatile uint32_t BKP2R;
  volatile uint32_t BKP3R;
  volatile uint32_t BKP4R;
  volatile uint32_t BKP5R;
  volatile uint32_t BKP6R;
  volatile uint32_t BKP7R;
  volatile uint32_t BKP8R;
  volatile uint32_t BKP9R;
  volatile uint32_t BKP10R;
  volatile uint32_t BKP11R;
  volatile uint32_t BKP12R;
  volatile uint32_t BKP13R;
  volatile uint32_t BKP14R;
  volatile uint32_t BKP15R;
  volatile uint32_t BKP16R;
  volatile uint32_t BKP17R;
  volatile uint32_t BKP18R;
  volatile uint32_t BKP19R;
} RTC_TypeDef;






typedef struct
{
  volatile uint32_t GCR;
} SAI_TypeDef;

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t FRCR;
  volatile uint32_t SLOTR;
  volatile uint32_t IMR;
  volatile uint32_t SR;
  volatile uint32_t CLRFR;
  volatile uint32_t DR;
} SAI_Block_TypeDef;





typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile uint32_t RESPCMD;
  volatile uint32_t RESP1;
  volatile uint32_t RESP2;
  volatile uint32_t RESP3;
  volatile uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile uint32_t DCOUNT;
  volatile uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  uint32_t RESERVED0[2];
  volatile uint32_t FIFOCNT;
  uint32_t RESERVED1[13];
  volatile uint32_t FIFO;
} SDIO_TypeDef;





typedef struct
{
  volatile uint16_t CR1;
  uint16_t RESERVED0;
  volatile uint16_t CR2;
  uint16_t RESERVED1;
  volatile uint16_t SR;
  uint16_t RESERVED2;
  volatile uint16_t DR;
  uint16_t RESERVED3;
  volatile uint16_t CRCPR;
  uint16_t RESERVED4;
  volatile uint16_t RXCRCR;
  uint16_t RESERVED5;
  volatile uint16_t TXCRCR;
  uint16_t RESERVED6;
  volatile uint16_t I2SCFGR;
  uint16_t RESERVED7;
  volatile uint16_t I2SPR;
  uint16_t RESERVED8;
} SPI_TypeDef;





typedef struct
{
  volatile uint16_t CR1;
  uint16_t RESERVED0;
  volatile uint16_t CR2;
  uint16_t RESERVED1;
  volatile uint16_t SMCR;
  uint16_t RESERVED2;
  volatile uint16_t DIER;
  uint16_t RESERVED3;
  volatile uint16_t SR;
  uint16_t RESERVED4;
  volatile uint16_t EGR;
  uint16_t RESERVED5;
  volatile uint16_t CCMR1;
  uint16_t RESERVED6;
  volatile uint16_t CCMR2;
  uint16_t RESERVED7;
  volatile uint16_t CCER;
  uint16_t RESERVED8;
  volatile uint32_t CNT;
  volatile uint16_t PSC;
  uint16_t RESERVED9;
  volatile uint32_t ARR;
  volatile uint16_t RCR;
  uint16_t RESERVED10;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint16_t BDTR;
  uint16_t RESERVED11;
  volatile uint16_t DCR;
  uint16_t RESERVED12;
  volatile uint16_t DMAR;
  uint16_t RESERVED13;
  volatile uint16_t OR;
  uint16_t RESERVED14;
} TIM_TypeDef;





typedef struct
{
  volatile uint16_t SR;
  uint16_t RESERVED0;
  volatile uint16_t DR;
  uint16_t RESERVED1;
  volatile uint16_t BRR;
  uint16_t RESERVED2;
  volatile uint16_t CR1;
  uint16_t RESERVED3;
  volatile uint16_t CR2;
  uint16_t RESERVED4;
  volatile uint16_t CR3;
  uint16_t RESERVED5;
  volatile uint16_t GTPR;
  uint16_t RESERVED6;
} USART_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t DOUT;
  volatile uint32_t DMACR;
  volatile uint32_t IMSCR;
  volatile uint32_t RISR;
  volatile uint32_t MISR;
  volatile uint32_t K0LR;
  volatile uint32_t K0RR;
  volatile uint32_t K1LR;
  volatile uint32_t K1RR;
  volatile uint32_t K2LR;
  volatile uint32_t K2RR;
  volatile uint32_t K3LR;
  volatile uint32_t K3RR;
  volatile uint32_t IV0LR;
  volatile uint32_t IV0RR;
  volatile uint32_t IV1LR;
  volatile uint32_t IV1RR;
  volatile uint32_t CSGCMCCM0R;
  volatile uint32_t CSGCMCCM1R;
  volatile uint32_t CSGCMCCM2R;
  volatile uint32_t CSGCMCCM3R;
  volatile uint32_t CSGCMCCM4R;
  volatile uint32_t CSGCMCCM5R;
  volatile uint32_t CSGCMCCM6R;
  volatile uint32_t CSGCMCCM7R;
  volatile uint32_t CSGCM0R;
  volatile uint32_t CSGCM1R;
  volatile uint32_t CSGCM2R;
  volatile uint32_t CSGCM3R;
  volatile uint32_t CSGCM4R;
  volatile uint32_t CSGCM5R;
  volatile uint32_t CSGCM6R;
  volatile uint32_t CSGCM7R;
} CRYP_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t DIN;
  volatile uint32_t STR;
  volatile uint32_t HR[5];
  volatile uint32_t IMR;
  volatile uint32_t SR;
       uint32_t RESERVED[52];
  volatile uint32_t CSR[54];
} HASH_TypeDef;





typedef struct
{
  volatile uint32_t HR[8];
} HASH_DIGEST_TypeDef;





typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SR;
  volatile uint32_t DR;
} RNG_TypeDef;
# 9140 "include/core/stm32f4xx.h"
}
# 6 "include/Altimeter.h" 2
# 1 "include/core/stm32f4xx_conf.h" 1
# 42 "include/core/stm32f4xx_conf.h"
# 1 "include/core/stm32f4xx_adc.h" 1
# 34 "include/core/stm32f4xx_adc.h"
 extern "C" {



# 1 "include/core/stm32f4xx.h" 1
# 39 "include/core/stm32f4xx_adc.h" 2
# 53 "include/core/stm32f4xx_adc.h"
typedef struct
{
  uint32_t ADC_Resolution;

  FunctionalState ADC_ScanConvMode;



  FunctionalState ADC_ContinuousConvMode;


  uint32_t ADC_ExternalTrigConvEdge;



  uint32_t ADC_ExternalTrigConv;



  uint32_t ADC_DataAlign;


  uint8_t ADC_NbrOfConversion;



}ADC_InitTypeDef;




typedef struct
{
  uint32_t ADC_Mode;


  uint32_t ADC_Prescaler;


  uint32_t ADC_DMAAccessMode;



  uint32_t ADC_TwoSamplingDelay;



}ADC_CommonInitTypeDef;
# 589 "include/core/stm32f4xx_adc.h"
void ADC_DeInit(void);


void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_CommonInit(ADC_CommonInitTypeDef* ADC_CommonInitStruct);
void ADC_CommonStructInit(ADC_CommonInitTypeDef* ADC_CommonInitStruct);
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);


void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold,uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);


void ADC_TempSensorVrefintCmd(FunctionalState NewState);
void ADC_VBATCmd(FunctionalState NewState);


void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_SoftwareStartConv(ADC_TypeDef* ADCx);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_EOCOnEachRegularChannelCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ContinuousModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number);
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
uint32_t ADC_GetMultiModeConversionValue(void);


void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMARequestAfterLastTransferCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_MultiModeDMARequestAfterLastTransferCmd(FunctionalState NewState);


void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, uint8_t Length);
void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvEdgeConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConvEdge);
void ADC_SoftwareStartInjectedConv(ADC_TypeDef* ADCx);
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx);
void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);


void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);


}
# 43 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_can.h" 1
# 34 "include/core/stm32f4xx_can.h"
 extern "C" {
# 56 "include/core/stm32f4xx_can.h"
typedef struct
{
  uint16_t CAN_Prescaler;


  uint8_t CAN_Mode;


  uint8_t CAN_SJW;




  uint8_t CAN_BS1;



  uint8_t CAN_BS2;


  FunctionalState CAN_TTCM;


  FunctionalState CAN_ABOM;


  FunctionalState CAN_AWUM;


  FunctionalState CAN_NART;


  FunctionalState CAN_RFLM;


  FunctionalState CAN_TXFP;

} CAN_InitTypeDef;




typedef struct
{
  uint16_t CAN_FilterIdHigh;



  uint16_t CAN_FilterIdLow;



  uint16_t CAN_FilterMaskIdHigh;




  uint16_t CAN_FilterMaskIdLow;




  uint16_t CAN_FilterFIFOAssignment;


  uint8_t CAN_FilterNumber;

  uint8_t CAN_FilterMode;


  uint8_t CAN_FilterScale;


  FunctionalState CAN_FilterActivation;

} CAN_FilterInitTypeDef;




typedef struct
{
  uint32_t StdId;


  uint32_t ExtId;


  uint8_t IDE;



  uint8_t RTR;



  uint8_t DLC;



  uint8_t Data[8];

} CanTxMsg;




typedef struct
{
  uint32_t StdId;


  uint32_t ExtId;


  uint8_t IDE;



  uint8_t RTR;



  uint8_t DLC;


  uint8_t Data[8];


  uint8_t FMI;


} CanRxMsg;
# 593 "include/core/stm32f4xx_can.h"
void CAN_DeInit(CAN_TypeDef* CANx);


uint8_t CAN_Init(CAN_TypeDef* CANx, CAN_InitTypeDef* CAN_InitStruct);
void CAN_FilterInit(CAN_FilterInitTypeDef* CAN_FilterInitStruct);
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct);
void CAN_SlaveStartBank(uint8_t CAN_BankNumber);
void CAN_DBGFreeze(CAN_TypeDef* CANx, FunctionalState NewState);
void CAN_TTComModeCmd(CAN_TypeDef* CANx, FunctionalState NewState);


uint8_t CAN_Transmit(CAN_TypeDef* CANx, CanTxMsg* TxMessage);
uint8_t CAN_TransmitStatus(CAN_TypeDef* CANx, uint8_t TransmitMailbox);
void CAN_CancelTransmit(CAN_TypeDef* CANx, uint8_t Mailbox);


void CAN_Receive(CAN_TypeDef* CANx, uint8_t FIFONumber, CanRxMsg* RxMessage);
void CAN_FIFORelease(CAN_TypeDef* CANx, uint8_t FIFONumber);
uint8_t CAN_MessagePending(CAN_TypeDef* CANx, uint8_t FIFONumber);


uint8_t CAN_OperatingModeRequest(CAN_TypeDef* CANx, uint8_t CAN_OperatingMode);
uint8_t CAN_Sleep(CAN_TypeDef* CANx);
uint8_t CAN_WakeUp(CAN_TypeDef* CANx);


uint8_t CAN_GetLastErrorCode(CAN_TypeDef* CANx);
uint8_t CAN_GetReceiveErrorCounter(CAN_TypeDef* CANx);
uint8_t CAN_GetLSBTransmitErrorCounter(CAN_TypeDef* CANx);


void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState);
FlagStatus CAN_GetFlagStatus(CAN_TypeDef* CANx, uint32_t CAN_FLAG);
void CAN_ClearFlag(CAN_TypeDef* CANx, uint32_t CAN_FLAG);
ITStatus CAN_GetITStatus(CAN_TypeDef* CANx, uint32_t CAN_IT);
void CAN_ClearITPendingBit(CAN_TypeDef* CANx, uint32_t CAN_IT);


}
# 44 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_crc.h" 1
# 34 "include/core/stm32f4xx_crc.h"
 extern "C" {
# 62 "include/core/stm32f4xx_crc.h"
void CRC_ResetDR(void);
uint32_t CRC_CalcCRC(uint32_t Data);
uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength);
uint32_t CRC_GetCRC(void);
void CRC_SetIDRegister(uint8_t IDValue);
uint8_t CRC_GetIDRegister(void);


}
# 45 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_cryp.h" 1
# 34 "include/core/stm32f4xx_cryp.h"
 extern "C" {
# 53 "include/core/stm32f4xx_cryp.h"
typedef struct
{
  uint32_t CRYP_AlgoDir;

  uint32_t CRYP_AlgoMode;


  uint32_t CRYP_DataType;

  uint32_t CRYP_KeySize;


}CRYP_InitTypeDef;




typedef struct
{
  uint32_t CRYP_Key0Left;
  uint32_t CRYP_Key0Right;
  uint32_t CRYP_Key1Left;
  uint32_t CRYP_Key1Right;
  uint32_t CRYP_Key2Left;
  uint32_t CRYP_Key2Right;
  uint32_t CRYP_Key3Left;
  uint32_t CRYP_Key3Right;
}CRYP_KeyInitTypeDef;



typedef struct
{
  uint32_t CRYP_IV0Left;
  uint32_t CRYP_IV0Right;
  uint32_t CRYP_IV1Left;
  uint32_t CRYP_IV1Right;
}CRYP_IVInitTypeDef;




typedef struct
{

  uint32_t CR_CurrentConfig;

  uint32_t CRYP_IV0LR;
  uint32_t CRYP_IV0RR;
  uint32_t CRYP_IV1LR;
  uint32_t CRYP_IV1RR;

  uint32_t CRYP_K0LR;
  uint32_t CRYP_K0RR;
  uint32_t CRYP_K1LR;
  uint32_t CRYP_K1RR;
  uint32_t CRYP_K2LR;
  uint32_t CRYP_K2RR;
  uint32_t CRYP_K3LR;
  uint32_t CRYP_K3RR;
  uint32_t CRYP_CSGCMCCMR[8];
  uint32_t CRYP_CSGCMR[8];
}CRYP_Context;
# 284 "include/core/stm32f4xx_cryp.h"
void CRYP_DeInit(void);


void CRYP_Init(CRYP_InitTypeDef* CRYP_InitStruct);
void CRYP_StructInit(CRYP_InitTypeDef* CRYP_InitStruct);
void CRYP_KeyInit(CRYP_KeyInitTypeDef* CRYP_KeyInitStruct);
void CRYP_KeyStructInit(CRYP_KeyInitTypeDef* CRYP_KeyInitStruct);
void CRYP_IVInit(CRYP_IVInitTypeDef* CRYP_IVInitStruct);
void CRYP_IVStructInit(CRYP_IVInitTypeDef* CRYP_IVInitStruct);
void CRYP_Cmd(FunctionalState NewState);
void CRYP_PhaseConfig(uint32_t CRYP_Phase);
void CRYP_FIFOFlush(void);

void CRYP_DataIn(uint32_t Data);
uint32_t CRYP_DataOut(void);


ErrorStatus CRYP_SaveContext(CRYP_Context* CRYP_ContextSave,
                             CRYP_KeyInitTypeDef* CRYP_KeyInitStruct);
void CRYP_RestoreContext(CRYP_Context* CRYP_ContextRestore);


void CRYP_DMACmd(uint8_t CRYP_DMAReq, FunctionalState NewState);


void CRYP_ITConfig(uint8_t CRYP_IT, FunctionalState NewState);
ITStatus CRYP_GetITStatus(uint8_t CRYP_IT);
FunctionalState CRYP_GetCmdStatus(void);
FlagStatus CRYP_GetFlagStatus(uint8_t CRYP_FLAG);


ErrorStatus CRYP_AES_ECB(uint8_t Mode,
                         uint8_t *Key, uint16_t Keysize,
                         uint8_t *Input, uint32_t Ilength,
                         uint8_t *Output);

ErrorStatus CRYP_AES_CBC(uint8_t Mode,
                         uint8_t InitVectors[16],
                         uint8_t *Key, uint16_t Keysize,
                         uint8_t *Input, uint32_t Ilength,
                         uint8_t *Output);

ErrorStatus CRYP_AES_CTR(uint8_t Mode,
                         uint8_t InitVectors[16],
                         uint8_t *Key, uint16_t Keysize,
                         uint8_t *Input, uint32_t Ilength,
                         uint8_t *Output);

ErrorStatus CRYP_AES_GCM(uint8_t Mode, uint8_t InitVectors[16],
                         uint8_t *Key, uint16_t Keysize,
                         uint8_t *Input, uint32_t ILength,
                         uint8_t *Header, uint32_t HLength,
                         uint8_t *Output, uint8_t *AuthTAG);

ErrorStatus CRYP_AES_CCM(uint8_t Mode,
                         uint8_t* Nonce, uint32_t NonceSize,
                         uint8_t* Key, uint16_t Keysize,
                         uint8_t* Input, uint32_t ILength,
                         uint8_t* Header, uint32_t HLength, uint8_t *HBuffer,
                         uint8_t* Output,
                         uint8_t* AuthTAG, uint32_t TAGSize);


ErrorStatus CRYP_TDES_ECB(uint8_t Mode,
                           uint8_t Key[24],
                           uint8_t *Input, uint32_t Ilength,
                           uint8_t *Output);

ErrorStatus CRYP_TDES_CBC(uint8_t Mode,
                          uint8_t Key[24],
                          uint8_t InitVectors[8],
                          uint8_t *Input, uint32_t Ilength,
                          uint8_t *Output);


ErrorStatus CRYP_DES_ECB(uint8_t Mode,
                         uint8_t Key[8],
                         uint8_t *Input, uint32_t Ilength,
                         uint8_t *Output);

ErrorStatus CRYP_DES_CBC(uint8_t Mode,
                         uint8_t Key[8],
                         uint8_t InitVectors[8],
                         uint8_t *Input,uint32_t Ilength,
                         uint8_t *Output);


}
# 46 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_dac.h" 1
# 34 "include/core/stm32f4xx_dac.h"
 extern "C" {
# 54 "include/core/stm32f4xx_dac.h"
typedef struct
{
  uint32_t DAC_Trigger;


  uint32_t DAC_WaveGeneration;



  uint32_t DAC_LFSRUnmask_TriangleAmplitude;



  uint32_t DAC_OutputBuffer;

}DAC_InitTypeDef;
# 266 "include/core/stm32f4xx_dac.h"
void DAC_DeInit(void);


void DAC_Init(uint32_t DAC_Channel, DAC_InitTypeDef* DAC_InitStruct);
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);
void DAC_Cmd(uint32_t DAC_Channel, FunctionalState NewState);
void DAC_SoftwareTriggerCmd(uint32_t DAC_Channel, FunctionalState NewState);
void DAC_DualSoftwareTriggerCmd(FunctionalState NewState);
void DAC_WaveGenerationCmd(uint32_t DAC_Channel, uint32_t DAC_Wave, FunctionalState NewState);
void DAC_SetChannel1Data(uint32_t DAC_Align, uint16_t Data);
void DAC_SetChannel2Data(uint32_t DAC_Align, uint16_t Data);
void DAC_SetDualChannelData(uint32_t DAC_Align, uint16_t Data2, uint16_t Data1);
uint16_t DAC_GetDataOutputValue(uint32_t DAC_Channel);


void DAC_DMACmd(uint32_t DAC_Channel, FunctionalState NewState);


void DAC_ITConfig(uint32_t DAC_Channel, uint32_t DAC_IT, FunctionalState NewState);
FlagStatus DAC_GetFlagStatus(uint32_t DAC_Channel, uint32_t DAC_FLAG);
void DAC_ClearFlag(uint32_t DAC_Channel, uint32_t DAC_FLAG);
ITStatus DAC_GetITStatus(uint32_t DAC_Channel, uint32_t DAC_IT);
void DAC_ClearITPendingBit(uint32_t DAC_Channel, uint32_t DAC_IT);


}
# 47 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_dbgmcu.h" 1
# 33 "include/core/stm32f4xx_dbgmcu.h"
 extern "C" {
# 89 "include/core/stm32f4xx_dbgmcu.h"
uint32_t DBGMCU_GetREVID(void);
uint32_t DBGMCU_GetDEVID(void);
void DBGMCU_Config(uint32_t DBGMCU_Periph, FunctionalState NewState);
void DBGMCU_APB1PeriphConfig(uint32_t DBGMCU_Periph, FunctionalState NewState);
void DBGMCU_APB2PeriphConfig(uint32_t DBGMCU_Periph, FunctionalState NewState);


}
# 48 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_dcmi.h" 1
# 33 "include/core/stm32f4xx_dcmi.h"
 extern "C" {
# 51 "include/core/stm32f4xx_dcmi.h"
typedef struct
{
  uint16_t DCMI_CaptureMode;


  uint16_t DCMI_SynchroMode;


  uint16_t DCMI_PCKPolarity;


  uint16_t DCMI_VSPolarity;


  uint16_t DCMI_HSPolarity;


  uint16_t DCMI_CaptureRate;


  uint16_t DCMI_ExtendedDataMode;

} DCMI_InitTypeDef;




typedef struct
{
  uint16_t DCMI_VerticalStartLine;


  uint16_t DCMI_HorizontalOffsetCount;


  uint16_t DCMI_VerticalLineCount;


  uint16_t DCMI_CaptureCount;


} DCMI_CROPInitTypeDef;




typedef struct
{
  uint8_t DCMI_FrameStartCode;
  uint8_t DCMI_LineStartCode;
  uint8_t DCMI_LineEndCode;
  uint8_t DCMI_FrameEndCode;
} DCMI_CodesInitTypeDef;
# 276 "include/core/stm32f4xx_dcmi.h"
void DCMI_DeInit(void);


void DCMI_Init(DCMI_InitTypeDef* DCMI_InitStruct);
void DCMI_StructInit(DCMI_InitTypeDef* DCMI_InitStruct);
void DCMI_CROPConfig(DCMI_CROPInitTypeDef* DCMI_CROPInitStruct);
void DCMI_CROPCmd(FunctionalState NewState);
void DCMI_SetEmbeddedSynchroCodes(DCMI_CodesInitTypeDef* DCMI_CodesInitStruct);
void DCMI_JPEGCmd(FunctionalState NewState);


void DCMI_Cmd(FunctionalState NewState);
void DCMI_CaptureCmd(FunctionalState NewState);
uint32_t DCMI_ReadData(void);


void DCMI_ITConfig(uint16_t DCMI_IT, FunctionalState NewState);
FlagStatus DCMI_GetFlagStatus(uint16_t DCMI_FLAG);
void DCMI_ClearFlag(uint16_t DCMI_FLAG);
ITStatus DCMI_GetITStatus(uint16_t DCMI_IT);
void DCMI_ClearITPendingBit(uint16_t DCMI_IT);


}
# 49 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_dma.h" 1
# 34 "include/core/stm32f4xx_dma.h"
 extern "C" {
# 54 "include/core/stm32f4xx_dma.h"
typedef struct
{
  uint32_t DMA_Channel;


  uint32_t DMA_PeripheralBaseAddr;

  uint32_t DMA_Memory0BaseAddr;



  uint32_t DMA_DIR;



  uint32_t DMA_BufferSize;



  uint32_t DMA_PeripheralInc;


  uint32_t DMA_MemoryInc;


  uint32_t DMA_PeripheralDataSize;


  uint32_t DMA_MemoryDataSize;


  uint32_t DMA_Mode;




  uint32_t DMA_Priority;


  uint32_t DMA_FIFOMode;




  uint32_t DMA_FIFOThreshold;


  uint32_t DMA_MemoryBurst;




  uint32_t DMA_PeripheralBurst;



}DMA_InitTypeDef;
# 562 "include/core/stm32f4xx_dma.h"
void DMA_DeInit(DMA_Stream_TypeDef* DMAy_Streamx);


void DMA_Init(DMA_Stream_TypeDef* DMAy_Streamx, DMA_InitTypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);
void DMA_Cmd(DMA_Stream_TypeDef* DMAy_Streamx, FunctionalState NewState);


void DMA_PeriphIncOffsetSizeConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_Pincos);
void DMA_FlowControllerConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_FlowCtrl);


void DMA_SetCurrDataCounter(DMA_Stream_TypeDef* DMAy_Streamx, uint16_t Counter);
uint16_t DMA_GetCurrDataCounter(DMA_Stream_TypeDef* DMAy_Streamx);


void DMA_DoubleBufferModeConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t Memory1BaseAddr,
                                uint32_t DMA_CurrentMemory);
void DMA_DoubleBufferModeCmd(DMA_Stream_TypeDef* DMAy_Streamx, FunctionalState NewState);
void DMA_MemoryTargetConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t MemoryBaseAddr,
                            uint32_t DMA_MemoryTarget);
uint32_t DMA_GetCurrentMemoryTarget(DMA_Stream_TypeDef* DMAy_Streamx);


FunctionalState DMA_GetCmdStatus(DMA_Stream_TypeDef* DMAy_Streamx);
uint32_t DMA_GetFIFOStatus(DMA_Stream_TypeDef* DMAy_Streamx);
FlagStatus DMA_GetFlagStatus(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_FLAG);
void DMA_ClearFlag(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_FLAG);
void DMA_ITConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_IT, FunctionalState NewState);
ITStatus DMA_GetITStatus(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_IT);
void DMA_ClearITPendingBit(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t DMA_IT);


}
# 50 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_exti.h" 1
# 34 "include/core/stm32f4xx_exti.h"
# 1 "include/core/stm32f4xx_conf.h" 1
# 35 "include/core/stm32f4xx_exti.h" 2


 extern "C" {
# 57 "include/core/stm32f4xx_exti.h"
typedef enum
{
  EXTI_Mode_Interrupt = 0x00,
  EXTI_Mode_Event = 0x04
}EXTIMode_TypeDef;







typedef enum
{
  EXTI_Trigger_Rising = 0x08,
  EXTI_Trigger_Falling = 0x0C,
  EXTI_Trigger_Rising_Falling = 0x10
}EXTITrigger_TypeDef;
# 83 "include/core/stm32f4xx_exti.h"
typedef struct
{
  uint32_t EXTI_Line;


  EXTIMode_TypeDef EXTI_Mode;


  EXTITrigger_TypeDef EXTI_Trigger;


  FunctionalState EXTI_LineCmd;

}EXTI_InitTypeDef;
# 159 "include/core/stm32f4xx_exti.h"
void EXTI_DeInit(void);


void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);


FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);
void EXTI_ClearFlag(uint32_t EXTI_Line);
ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
void EXTI_ClearITPendingBit(uint32_t EXTI_Line);


}
# 51 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_flash.h" 1
# 37 "include/core/stm32f4xx_flash.h"
 extern "C" {
# 55 "include/core/stm32f4xx_flash.h"
typedef enum
{
  FLASH_BUSY = 1,
  FLASH_ERROR_RD,
  FLASH_ERROR_PGS,
  FLASH_ERROR_PGP,
  FLASH_ERROR_PGA,
  FLASH_ERROR_WRP,
  FLASH_ERROR_PROGRAM,
  FLASH_ERROR_OPERATION,
  FLASH_COMPLETE
}FLASH_Status;
# 424 "include/core/stm32f4xx_flash.h"
void FLASH_SetLatency(uint32_t FLASH_Latency);
void FLASH_PrefetchBufferCmd(FunctionalState NewState);
void FLASH_InstructionCacheCmd(FunctionalState NewState);
void FLASH_DataCacheCmd(FunctionalState NewState);
void FLASH_InstructionCacheReset(void);
void FLASH_DataCacheReset(void);


void FLASH_Unlock(void);
void FLASH_Lock(void);
FLASH_Status FLASH_EraseSector(uint32_t FLASH_Sector, uint8_t VoltageRange);
FLASH_Status FLASH_EraseAllSectors(uint8_t VoltageRange);
FLASH_Status FLASH_EraseAllBank1Sectors(uint8_t VoltageRange);
FLASH_Status FLASH_EraseAllBank2Sectors(uint8_t VoltageRange);
FLASH_Status FLASH_ProgramDoubleWord(uint32_t Address, uint64_t Data);
FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);
FLASH_Status FLASH_ProgramByte(uint32_t Address, uint8_t Data);


void FLASH_OB_Unlock(void);
void FLASH_OB_Lock(void);
void FLASH_OB_WRPConfig(uint32_t OB_WRP, FunctionalState NewState);
void FLASH_OB_WRP1Config(uint32_t OB_WRP, FunctionalState NewState);
void FLASH_OB_PCROPSelectionConfig(uint8_t OB_PcROP);
void FLASH_OB_PCROPConfig(uint32_t OB_PCROP, FunctionalState NewState);
void FLASH_OB_PCROP1Config(uint32_t OB_PCROP, FunctionalState NewState);
void FLASH_OB_RDPConfig(uint8_t OB_RDP);
void FLASH_OB_UserConfig(uint8_t OB_IWDG, uint8_t OB_STOP, uint8_t OB_STDBY);
void FLASH_OB_BORConfig(uint8_t OB_BOR);
void FLASH_OB_BootConfig(uint8_t OB_BOOT);
FLASH_Status FLASH_OB_Launch(void);
uint8_t FLASH_OB_GetUser(void);
uint16_t FLASH_OB_GetWRP(void);
uint16_t FLASH_OB_GetWRP1(void);
uint16_t FLASH_OB_GetPCROP(void);
uint16_t FLASH_OB_GetPCROP1(void);
FlagStatus FLASH_OB_GetRDP(void);
uint8_t FLASH_OB_GetBOR(void);


void FLASH_ITConfig(uint32_t FLASH_IT, FunctionalState NewState);
FlagStatus FLASH_GetFlagStatus(uint32_t FLASH_FLAG);
void FLASH_ClearFlag(uint32_t FLASH_FLAG);
FLASH_Status FLASH_GetStatus(void);
FLASH_Status FLASH_WaitForLastOperation(void);


}
# 52 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_fmc.h" 1
# 28 "include/core/stm32f4xx_fmc.h"
 extern "C" {
# 47 "include/core/stm32f4xx_fmc.h"
typedef struct
{
  uint32_t FMC_AddressSetupTime;




  uint32_t FMC_AddressHoldTime;




  uint32_t FMC_DataSetupTime;




  uint32_t FMC_BusTurnAroundDuration;




  uint32_t FMC_CLKDivision;



  uint32_t FMC_DataLatency;







  uint32_t FMC_AccessMode;

}FMC_NORSRAMTimingInitTypeDef;




typedef struct
{
  uint32_t FMC_Bank;


  uint32_t FMC_DataAddressMux;



  uint32_t FMC_MemoryType;



  uint32_t FMC_MemoryDataWidth;


  uint32_t FMC_BurstAccessMode;



  uint32_t FMC_WaitSignalPolarity;



  uint32_t FMC_WrapMode;



  uint32_t FMC_WaitSignalActive;




  uint32_t FMC_WriteOperation;


  uint32_t FMC_WaitSignal;



  uint32_t FMC_ExtendedMode;


  uint32_t FMC_AsynchronousWait;



  uint32_t FMC_WriteBurst;


  uint32_t FMC_ContinousClock;





  FMC_NORSRAMTimingInitTypeDef* FMC_ReadWriteTimingStruct;

  FMC_NORSRAMTimingInitTypeDef* FMC_WriteTimingStruct;
}FMC_NORSRAMInitTypeDef;




typedef struct
{
  uint32_t FMC_SetupTime;





  uint32_t FMC_WaitSetupTime;





  uint32_t FMC_HoldSetupTime;






  uint32_t FMC_HiZSetupTime;




}FMC_NAND_PCCARDTimingInitTypeDef;




typedef struct
{
  uint32_t FMC_Bank;


  uint32_t FMC_Waitfeature;


  uint32_t FMC_MemoryDataWidth;


  uint32_t FMC_ECC;


  uint32_t FMC_ECCPageSize;


  uint32_t FMC_TCLRSetupTime;



  uint32_t FMC_TARSetupTime;



  FMC_NAND_PCCARDTimingInitTypeDef* FMC_CommonSpaceTimingStruct;

  FMC_NAND_PCCARDTimingInitTypeDef* FMC_AttributeSpaceTimingStruct;
}FMC_NANDInitTypeDef;





typedef struct
{
  uint32_t FMC_Waitfeature;


  uint32_t FMC_TCLRSetupTime;



  uint32_t FMC_TARSetupTime;




  FMC_NAND_PCCARDTimingInitTypeDef* FMC_CommonSpaceTimingStruct;

  FMC_NAND_PCCARDTimingInitTypeDef* FMC_AttributeSpaceTimingStruct;

  FMC_NAND_PCCARDTimingInitTypeDef* FMC_IOSpaceTimingStruct;
}FMC_PCCARDInitTypeDef;





typedef struct
{
  uint32_t FMC_LoadToActiveDelay;



  uint32_t FMC_ExitSelfRefreshDelay;



  uint32_t FMC_SelfRefreshTime;



  uint32_t FMC_RowCycleDelay;




  uint32_t FMC_WriteRecoveryTime;


  uint32_t FMC_RPDelay;



  uint32_t FMC_RCDDelay;



}FMC_SDRAMTimingInitTypeDef;






typedef struct
{
  uint32_t FMC_CommandMode;


  uint32_t FMC_CommandTarget;


  uint32_t FMC_AutoRefreshNumber;



  uint32_t FMC_ModeRegisterDefinition;

}FMC_SDRAMCommandTypeDef;





typedef struct
{
  uint32_t FMC_Bank;


  uint32_t FMC_ColumnBitsNumber;


  uint32_t FMC_RowBitsNumber;


  uint32_t FMC_SDMemoryDataWidth;


  uint32_t FMC_InternalBankNumber;


  uint32_t FMC_CASLatency;


  uint32_t FMC_WriteProtection;


  uint32_t FMC_SDClockPeriod;



  uint32_t FMC_ReadBurst;



  uint32_t FMC_ReadPipeDelay;


  FMC_SDRAMTimingInitTypeDef* FMC_SDRAMTimingStruct;

}FMC_SDRAMInitTypeDef;
# 1088 "include/core/stm32f4xx_fmc.h"
void FMC_NORSRAMDeInit(uint32_t FMC_Bank);
void FMC_NORSRAMInit(FMC_NORSRAMInitTypeDef* FMC_NORSRAMInitStruct);
void FMC_NORSRAMStructInit(FMC_NORSRAMInitTypeDef* FMC_NORSRAMInitStruct);
void FMC_NORSRAMCmd(uint32_t FMC_Bank, FunctionalState NewState);


void FMC_NANDDeInit(uint32_t FMC_Bank);
void FMC_NANDInit(FMC_NANDInitTypeDef* FMC_NANDInitStruct);
void FMC_NANDStructInit(FMC_NANDInitTypeDef* FMC_NANDInitStruct);
void FMC_NANDCmd(uint32_t FMC_Bank, FunctionalState NewState);
void FMC_NANDECCCmd(uint32_t FMC_Bank, FunctionalState NewState);
uint32_t FMC_GetECC(uint32_t FMC_Bank);


void FMC_PCCARDDeInit(void);
void FMC_PCCARDInit(FMC_PCCARDInitTypeDef* FMC_PCCARDInitStruct);
void FMC_PCCARDStructInit(FMC_PCCARDInitTypeDef* FMC_PCCARDInitStruct);
void FMC_PCCARDCmd(FunctionalState NewState);


void FMC_SDRAMDeInit(uint32_t FMC_Bank);
void FMC_SDRAMInit(FMC_SDRAMInitTypeDef* FMC_SDRAMInitStruct);
void FMC_SDRAMStructInit(FMC_SDRAMInitTypeDef* FMC_SDRAMInitStruct);
void FMC_SDRAMCmdConfig(FMC_SDRAMCommandTypeDef* FMC_SDRAMCommandStruct);
uint32_t FMC_GetModeStatus(uint32_t SDRAM_Bank);
void FMC_SetRefreshCount(uint32_t FMC_Count);
void FMC_SetAutoRefresh_Number(uint32_t FMC_Number);
void FMC_SDRAMWriteProtectionConfig(uint32_t SDRAM_Bank, FunctionalState NewState);


void FMC_ITConfig(uint32_t FMC_Bank, uint32_t FMC_IT, FunctionalState NewState);
FlagStatus FMC_GetFlagStatus(uint32_t FMC_Bank, uint32_t FMC_FLAG);
void FMC_ClearFlag(uint32_t FMC_Bank, uint32_t FMC_FLAG);
ITStatus FMC_GetITStatus(uint32_t FMC_Bank, uint32_t FMC_IT);
void FMC_ClearITPendingBit(uint32_t FMC_Bank, uint32_t FMC_IT);


}
# 53 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_hash.h" 1
# 34 "include/core/stm32f4xx_hash.h"
 extern "C" {
# 53 "include/core/stm32f4xx_hash.h"
typedef struct
{
  uint32_t HASH_AlgoSelection;

  uint32_t HASH_AlgoMode;

  uint32_t HASH_DataType;


  uint32_t HASH_HMACKeyType;

}HASH_InitTypeDef;




typedef struct
{
  uint32_t Data[8];



} HASH_MsgDigest;




typedef struct
{
  uint32_t HASH_IMR;
  uint32_t HASH_STR;
  uint32_t HASH_CR;
  uint32_t HASH_CSR[54];
}HASH_Context;
# 202 "include/core/stm32f4xx_hash.h"
void HASH_DeInit(void);


void HASH_Init(HASH_InitTypeDef* HASH_InitStruct);
void HASH_StructInit(HASH_InitTypeDef* HASH_InitStruct);
void HASH_Reset(void);


void HASH_DataIn(uint32_t Data);
uint8_t HASH_GetInFIFOWordsNbr(void);
void HASH_SetLastWordValidBitsNbr(uint16_t ValidNumber);
void HASH_StartDigest(void);
void HASH_AutoStartDigest(FunctionalState NewState);
void HASH_GetDigest(HASH_MsgDigest* HASH_MessageDigest);


void HASH_SaveContext(HASH_Context* HASH_ContextSave);
void HASH_RestoreContext(HASH_Context* HASH_ContextRestore);


void HASH_DMACmd(FunctionalState NewState);


void HASH_ITConfig(uint32_t HASH_IT, FunctionalState NewState);
FlagStatus HASH_GetFlagStatus(uint32_t HASH_FLAG);
void HASH_ClearFlag(uint32_t HASH_FLAG);
ITStatus HASH_GetITStatus(uint32_t HASH_IT);
void HASH_ClearITPendingBit(uint32_t HASH_IT);


ErrorStatus HASH_SHA1(uint8_t *Input, uint32_t Ilen, uint8_t Output[20]);
ErrorStatus HMAC_SHA1(uint8_t *Key, uint32_t Keylen,
                      uint8_t *Input, uint32_t Ilen,
                      uint8_t Output[20]);


ErrorStatus HASH_MD5(uint8_t *Input, uint32_t Ilen, uint8_t Output[16]);
ErrorStatus HMAC_MD5(uint8_t *Key, uint32_t Keylen,
                     uint8_t *Input, uint32_t Ilen,
                     uint8_t Output[16]);


}
# 54 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_gpio.h" 1
# 34 "include/core/stm32f4xx_gpio.h"
 extern "C" {
# 65 "include/core/stm32f4xx_gpio.h"
typedef enum
{
  GPIO_Mode_IN = 0x00,
  GPIO_Mode_OUT = 0x01,
  GPIO_Mode_AF = 0x02,
  GPIO_Mode_AN = 0x03
}GPIOMode_TypeDef;






typedef enum
{
  GPIO_OType_PP = 0x00,
  GPIO_OType_OD = 0x01
}GPIOOType_TypeDef;






typedef enum
{
  GPIO_Low_Speed = 0x00,
  GPIO_Medium_Speed = 0x01,
  GPIO_Fast_Speed = 0x02,
  GPIO_High_Speed = 0x03
}GPIOSpeed_TypeDef;
# 109 "include/core/stm32f4xx_gpio.h"
typedef enum
{
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP = 0x01,
  GPIO_PuPd_DOWN = 0x02
}GPIOPuPd_TypeDef;






typedef enum
{
  Bit_RESET = 0,
  Bit_SET
}BitAction;






typedef struct
{
  uint32_t GPIO_Pin;


  GPIOMode_TypeDef GPIO_Mode;


  GPIOSpeed_TypeDef GPIO_Speed;


  GPIOOType_TypeDef GPIO_OType;


  GPIOPuPd_TypeDef GPIO_PuPd;

}GPIO_InitTypeDef;
# 454 "include/core/stm32f4xx_gpio.h"
void GPIO_DeInit(GPIO_TypeDef* GPIOx);


void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF);


}
# 55 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_i2c.h" 1
# 37 "include/core/stm32f4xx_i2c.h"
 extern "C" {
# 57 "include/core/stm32f4xx_i2c.h"
typedef struct
{
  uint32_t I2C_ClockSpeed;


  uint16_t I2C_Mode;


  uint16_t I2C_DutyCycle;


  uint16_t I2C_OwnAddress1;


  uint16_t I2C_Ack;


  uint16_t I2C_AcknowledgedAddress;

}I2C_InitTypeDef;
# 551 "include/core/stm32f4xx_i2c.h"
void I2C_DeInit(I2C_TypeDef* I2Cx);


void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DigitalFilterConfig(I2C_TypeDef* I2Cx, uint16_t I2C_DigitalFilter);
void I2C_AnalogFilterCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction);
void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, uint8_t Address);
void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_FastModeDutyCycleConfig(I2C_TypeDef* I2Cx, uint16_t I2C_DutyCycle);
void I2C_NACKPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_NACKPosition);
void I2C_SMBusAlertConfig(I2C_TypeDef* I2Cx, uint16_t I2C_SMBusAlert);
void I2C_ARPCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);


void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data);
uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx);


void I2C_TransmitPEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_PECPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_PECPosition);
void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
uint8_t I2C_GetPEC(I2C_TypeDef* I2Cx);


void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);


uint16_t I2C_ReadRegister(I2C_TypeDef* I2Cx, uint8_t I2C_Register);
void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState);
# 681 "include/core/stm32f4xx_i2c.h"
ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT);





uint32_t I2C_GetLastEvent(I2C_TypeDef* I2Cx);





FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);


void I2C_ClearFlag(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
void I2C_ClearITPendingBit(I2C_TypeDef* I2Cx, uint32_t I2C_IT);


}
# 56 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_iwdg.h" 1
# 34 "include/core/stm32f4xx_iwdg.h"
 extern "C" {
# 106 "include/core/stm32f4xx_iwdg.h"
void IWDG_WriteAccessCmd(uint16_t IWDG_WriteAccess);
void IWDG_SetPrescaler(uint8_t IWDG_Prescaler);
void IWDG_SetReload(uint16_t Reload);
void IWDG_ReloadCounter(void);


void IWDG_Enable(void);


FlagStatus IWDG_GetFlagStatus(uint16_t IWDG_FLAG);


}
# 57 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_pwr.h" 1
# 34 "include/core/stm32f4xx_pwr.h"
 extern "C" {
# 165 "include/core/stm32f4xx_pwr.h"
void PWR_DeInit(void);


void PWR_BackupAccessCmd(FunctionalState NewState);


void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
void PWR_PVDCmd(FunctionalState NewState);


void PWR_WakeUpPinCmd(FunctionalState NewState);


void PWR_BackupRegulatorCmd(FunctionalState NewState);
void PWR_MainRegulatorModeConfig(uint32_t PWR_Regulator_Voltage);
void PWR_OverDriveCmd(FunctionalState NewState);
void PWR_OverDriveSWCmd(FunctionalState NewState);
void PWR_UnderDriveCmd(FunctionalState NewState);


void PWR_FlashPowerDownCmd(FunctionalState NewState);


void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterUnderDriveSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);


FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
void PWR_ClearFlag(uint32_t PWR_FLAG);


}
# 58 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_rcc.h" 1
# 37 "include/core/stm32f4xx_rcc.h"
 extern "C" {
# 52 "include/core/stm32f4xx_rcc.h"
typedef struct
{
  uint32_t SYSCLK_Frequency;
  uint32_t HCLK_Frequency;
  uint32_t PCLK1_Frequency;
  uint32_t PCLK2_Frequency;
}RCC_ClocksTypeDef;
# 533 "include/core/stm32f4xx_rcc.h"
void RCC_DeInit(void);


void RCC_HSEConfig(uint8_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_LSEConfig(uint8_t RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP, uint32_t PLLQ);
void RCC_PLLCmd(FunctionalState NewState);






void RCC_PLLI2SConfig(uint32_t PLLI2SN, uint32_t PLLI2SQ, uint32_t PLLI2SR);


void RCC_PLLI2SCmd(FunctionalState NewState);
void RCC_PLLSAIConfig(uint32_t PLLSAIN, uint32_t PLLSAIQ, uint32_t PLLSAIR);
void RCC_PLLSAICmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCO1Config(uint32_t RCC_MCO1Source, uint32_t RCC_MCO1Div);
void RCC_MCO2Config(uint32_t RCC_MCO2Source, uint32_t RCC_MCO2Div);


void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);


void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_I2SCLKConfig(uint32_t RCC_I2SCLKSource);
void RCC_SAIPLLI2SClkDivConfig(uint32_t RCC_PLLI2SDivQ);
void RCC_SAIPLLSAIClkDivConfig(uint32_t RCC_PLLSAIDivQ);
void RCC_SAIBlockACLKConfig(uint32_t RCC_SAIBlockACLKSource);
void RCC_SAIBlockBCLKConfig(uint32_t RCC_SAIBlockBCLKSource);
void RCC_LTDCCLKDivConfig(uint32_t RCC_PLLSAIDivR);
void RCC_TIMCLKPresConfig(uint32_t RCC_TIMCLKPrescaler);

void RCC_AHB1PeriphClockCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void RCC_AHB2PeriphClockCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState);
void RCC_AHB3PeriphClockCmd(uint32_t RCC_AHB3Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

void RCC_AHB1PeriphResetCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void RCC_AHB2PeriphResetCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState);
void RCC_AHB3PeriphResetCmd(uint32_t RCC_AHB3Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

void RCC_AHB1PeriphClockLPModeCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void RCC_AHB2PeriphClockLPModeCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState);
void RCC_AHB3PeriphClockLPModeCmd(uint32_t RCC_AHB3Periph, FunctionalState NewState);
void RCC_APB1PeriphClockLPModeCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_APB2PeriphClockLPModeCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);


void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(uint8_t RCC_IT);
void RCC_ClearITPendingBit(uint8_t RCC_IT);


}
# 59 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_rng.h" 1
# 34 "include/core/stm32f4xx_rng.h"
 extern "C" {
# 91 "include/core/stm32f4xx_rng.h"
void RNG_DeInit(void);


void RNG_Cmd(FunctionalState NewState);


uint32_t RNG_GetRandomNumber(void);


void RNG_ITConfig(FunctionalState NewState);
FlagStatus RNG_GetFlagStatus(uint8_t RNG_FLAG);
void RNG_ClearFlag(uint8_t RNG_FLAG);
ITStatus RNG_GetITStatus(uint8_t RNG_IT);
void RNG_ClearITPendingBit(uint8_t RNG_IT);


}
# 60 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_rtc.h" 1
# 37 "include/core/stm32f4xx_rtc.h"
 extern "C" {
# 56 "include/core/stm32f4xx_rtc.h"
typedef struct
{
  uint32_t RTC_HourFormat;


  uint32_t RTC_AsynchPrediv;


  uint32_t RTC_SynchPrediv;

}RTC_InitTypeDef;




typedef struct
{
  uint8_t RTC_Hours;




  uint8_t RTC_Minutes;


  uint8_t RTC_Seconds;


  uint8_t RTC_H12;

}RTC_TimeTypeDef;




typedef struct
{
  uint8_t RTC_WeekDay;


  uint8_t RTC_Month;


  uint8_t RTC_Date;


  uint8_t RTC_Year;

}RTC_DateTypeDef;




typedef struct
{
  RTC_TimeTypeDef RTC_AlarmTime;

  uint32_t RTC_AlarmMask;


  uint32_t RTC_AlarmDateWeekDaySel;


  uint8_t RTC_AlarmDateWeekDay;




}RTC_AlarmTypeDef;
# 784 "include/core/stm32f4xx_rtc.h"
ErrorStatus RTC_DeInit(void);


ErrorStatus RTC_Init(RTC_InitTypeDef* RTC_InitStruct);
void RTC_StructInit(RTC_InitTypeDef* RTC_InitStruct);
void RTC_WriteProtectionCmd(FunctionalState NewState);
ErrorStatus RTC_EnterInitMode(void);
void RTC_ExitInitMode(void);
ErrorStatus RTC_WaitForSynchro(void);
ErrorStatus RTC_RefClockCmd(FunctionalState NewState);
void RTC_BypassShadowCmd(FunctionalState NewState);


ErrorStatus RTC_SetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
void RTC_TimeStructInit(RTC_TimeTypeDef* RTC_TimeStruct);
void RTC_GetTime(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
uint32_t RTC_GetSubSecond(void);
ErrorStatus RTC_SetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct);
void RTC_DateStructInit(RTC_DateTypeDef* RTC_DateStruct);
void RTC_GetDate(uint32_t RTC_Format, RTC_DateTypeDef* RTC_DateStruct);


void RTC_SetAlarm(uint32_t RTC_Format, uint32_t RTC_Alarm, RTC_AlarmTypeDef* RTC_AlarmStruct);
void RTC_AlarmStructInit(RTC_AlarmTypeDef* RTC_AlarmStruct);
void RTC_GetAlarm(uint32_t RTC_Format, uint32_t RTC_Alarm, RTC_AlarmTypeDef* RTC_AlarmStruct);
ErrorStatus RTC_AlarmCmd(uint32_t RTC_Alarm, FunctionalState NewState);
void RTC_AlarmSubSecondConfig(uint32_t RTC_Alarm, uint32_t RTC_AlarmSubSecondValue, uint32_t RTC_AlarmSubSecondMask);
uint32_t RTC_GetAlarmSubSecond(uint32_t RTC_Alarm);


void RTC_WakeUpClockConfig(uint32_t RTC_WakeUpClock);
void RTC_SetWakeUpCounter(uint32_t RTC_WakeUpCounter);
uint32_t RTC_GetWakeUpCounter(void);
ErrorStatus RTC_WakeUpCmd(FunctionalState NewState);


void RTC_DayLightSavingConfig(uint32_t RTC_DayLightSaving, uint32_t RTC_StoreOperation);
uint32_t RTC_GetStoreOperation(void);


void RTC_OutputConfig(uint32_t RTC_Output, uint32_t RTC_OutputPolarity);


ErrorStatus RTC_CoarseCalibConfig(uint32_t RTC_CalibSign, uint32_t Value);
ErrorStatus RTC_CoarseCalibCmd(FunctionalState NewState);
void RTC_CalibOutputCmd(FunctionalState NewState);
void RTC_CalibOutputConfig(uint32_t RTC_CalibOutput);
ErrorStatus RTC_SmoothCalibConfig(uint32_t RTC_SmoothCalibPeriod,
                                  uint32_t RTC_SmoothCalibPlusPulses,
                                  uint32_t RTC_SmouthCalibMinusPulsesValue);


void RTC_TimeStampCmd(uint32_t RTC_TimeStampEdge, FunctionalState NewState);
void RTC_GetTimeStamp(uint32_t RTC_Format, RTC_TimeTypeDef* RTC_StampTimeStruct,
                                      RTC_DateTypeDef* RTC_StampDateStruct);
uint32_t RTC_GetTimeStampSubSecond(void);


void RTC_TamperTriggerConfig(uint32_t RTC_Tamper, uint32_t RTC_TamperTrigger);
void RTC_TamperCmd(uint32_t RTC_Tamper, FunctionalState NewState);
void RTC_TamperFilterConfig(uint32_t RTC_TamperFilter);
void RTC_TamperSamplingFreqConfig(uint32_t RTC_TamperSamplingFreq);
void RTC_TamperPinsPrechargeDuration(uint32_t RTC_TamperPrechargeDuration);
void RTC_TimeStampOnTamperDetectionCmd(FunctionalState NewState);
void RTC_TamperPullUpCmd(FunctionalState NewState);


void RTC_WriteBackupRegister(uint32_t RTC_BKP_DR, uint32_t Data);
uint32_t RTC_ReadBackupRegister(uint32_t RTC_BKP_DR);



void RTC_TamperPinSelection(uint32_t RTC_TamperPin);
void RTC_TimeStampPinSelection(uint32_t RTC_TimeStampPin);
void RTC_OutputTypeConfig(uint32_t RTC_OutputType);


ErrorStatus RTC_SynchroShiftConfig(uint32_t RTC_ShiftAdd1S, uint32_t RTC_ShiftSubFS);


void RTC_ITConfig(uint32_t RTC_IT, FunctionalState NewState);
FlagStatus RTC_GetFlagStatus(uint32_t RTC_FLAG);
void RTC_ClearFlag(uint32_t RTC_FLAG);
ITStatus RTC_GetITStatus(uint32_t RTC_IT);
void RTC_ClearITPendingBit(uint32_t RTC_IT);


}
# 61 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_sdio.h" 1
# 34 "include/core/stm32f4xx_sdio.h"
 extern "C" {
# 50 "include/core/stm32f4xx_sdio.h"
typedef struct
{
  uint32_t SDIO_ClockEdge;


  uint32_t SDIO_ClockBypass;



  uint32_t SDIO_ClockPowerSave;



  uint32_t SDIO_BusWide;


  uint32_t SDIO_HardwareFlowControl;


  uint8_t SDIO_ClockDiv;


} SDIO_InitTypeDef;

typedef struct
{
  uint32_t SDIO_Argument;




  uint32_t SDIO_CmdIndex;

  uint32_t SDIO_Response;


  uint32_t SDIO_Wait;


  uint32_t SDIO_CPSM;


} SDIO_CmdInitTypeDef;

typedef struct
{
  uint32_t SDIO_DataTimeOut;

  uint32_t SDIO_DataLength;

  uint32_t SDIO_DataBlockSize;


  uint32_t SDIO_TransferDir;



  uint32_t SDIO_TransferMode;


  uint32_t SDIO_DPSM;


} SDIO_DataInitTypeDef;
# 477 "include/core/stm32f4xx_sdio.h"
void SDIO_DeInit(void);


void SDIO_Init(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_StructInit(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_ClockCmd(FunctionalState NewState);
void SDIO_SetPowerState(uint32_t SDIO_PowerState);
uint32_t SDIO_GetPowerState(void);


void SDIO_SendCommand(SDIO_CmdInitTypeDef *SDIO_CmdInitStruct);
void SDIO_CmdStructInit(SDIO_CmdInitTypeDef* SDIO_CmdInitStruct);
uint8_t SDIO_GetCommandResponse(void);
uint32_t SDIO_GetResponse(uint32_t SDIO_RESP);


void SDIO_DataConfig(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
void SDIO_DataStructInit(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
uint32_t SDIO_GetDataCounter(void);
uint32_t SDIO_ReadData(void);
void SDIO_WriteData(uint32_t Data);
uint32_t SDIO_GetFIFOCount(void);


void SDIO_StartSDIOReadWait(FunctionalState NewState);
void SDIO_StopSDIOReadWait(FunctionalState NewState);
void SDIO_SetSDIOReadWaitMode(uint32_t SDIO_ReadWaitMode);
void SDIO_SetSDIOOperation(FunctionalState NewState);
void SDIO_SendSDIOSuspendCmd(FunctionalState NewState);


void SDIO_CommandCompletionCmd(FunctionalState NewState);
void SDIO_CEATAITCmd(FunctionalState NewState);
void SDIO_SendCEATACmd(FunctionalState NewState);


void SDIO_DMACmd(FunctionalState NewState);


void SDIO_ITConfig(uint32_t SDIO_IT, FunctionalState NewState);
FlagStatus SDIO_GetFlagStatus(uint32_t SDIO_FLAG);
void SDIO_ClearFlag(uint32_t SDIO_FLAG);
ITStatus SDIO_GetITStatus(uint32_t SDIO_IT);
void SDIO_ClearITPendingBit(uint32_t SDIO_IT);


}
# 62 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_spi.h" 1
# 34 "include/core/stm32f4xx_spi.h"
 extern "C" {
# 54 "include/core/stm32f4xx_spi.h"
typedef struct
{
  uint16_t SPI_Direction;


  uint16_t SPI_Mode;


  uint16_t SPI_DataSize;


  uint16_t SPI_CPOL;


  uint16_t SPI_CPHA;


  uint16_t SPI_NSS;



  uint16_t SPI_BaudRatePrescaler;





  uint16_t SPI_FirstBit;


  uint16_t SPI_CRCPolynomial;
}SPI_InitTypeDef;





typedef struct
{

  uint16_t I2S_Mode;


  uint16_t I2S_Standard;


  uint16_t I2S_DataFormat;


  uint16_t I2S_MCLKOutput;


  uint32_t I2S_AudioFreq;


  uint16_t I2S_CPOL;

}I2S_InitTypeDef;
# 498 "include/core/stm32f4xx_spi.h"
void SPI_I2S_DeInit(SPI_TypeDef* SPIx);


void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize);
void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction);
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft);
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_TIModeCmd(SPI_TypeDef* SPIx, FunctionalState NewState);

void I2S_FullDuplexConfig(SPI_TypeDef* I2Sxext, I2S_InitTypeDef* I2S_InitStruct);


void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data);
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);


void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_TransmitCRC(SPI_TypeDef* SPIx);
uint16_t SPI_GetCRC(SPI_TypeDef* SPIx, uint8_t SPI_CRC);
uint16_t SPI_GetCRCPolynomial(SPI_TypeDef* SPIx);


void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState);


void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState);
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);
void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);


}
# 63 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_syscfg.h" 1
# 37 "include/core/stm32f4xx_syscfg.h"
 extern "C" {
# 191 "include/core/stm32f4xx_syscfg.h"
void SYSCFG_DeInit(void);
void SYSCFG_MemoryRemapConfig(uint8_t SYSCFG_MemoryRemap);
void SYSCFG_MemorySwappingBank(FunctionalState NewState);
void SYSCFG_EXTILineConfig(uint8_t EXTI_PortSourceGPIOx, uint8_t EXTI_PinSourcex);
void SYSCFG_ETH_MediaInterfaceConfig(uint32_t SYSCFG_ETH_MediaInterface);
void SYSCFG_CompensationCellCmd(FunctionalState NewState);
FlagStatus SYSCFG_GetCompensationCellStatus(void);


}
# 64 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_tim.h" 1
# 34 "include/core/stm32f4xx_tim.h"
 extern "C" {
# 55 "include/core/stm32f4xx_tim.h"
typedef struct
{
  uint16_t TIM_Prescaler;


  uint16_t TIM_CounterMode;


  uint32_t TIM_Period;



  uint16_t TIM_ClockDivision;


  uint8_t TIM_RepetitionCounter;







} TIM_TimeBaseInitTypeDef;





typedef struct
{
  uint16_t TIM_OCMode;


  uint16_t TIM_OutputState;


  uint16_t TIM_OutputNState;



  uint32_t TIM_Pulse;


  uint16_t TIM_OCPolarity;


  uint16_t TIM_OCNPolarity;



  uint16_t TIM_OCIdleState;



  uint16_t TIM_OCNIdleState;


} TIM_OCInitTypeDef;





typedef struct
{

  uint16_t TIM_Channel;


  uint16_t TIM_ICPolarity;


  uint16_t TIM_ICSelection;


  uint16_t TIM_ICPrescaler;


  uint16_t TIM_ICFilter;

} TIM_ICInitTypeDef;






typedef struct
{

  uint16_t TIM_OSSRState;


  uint16_t TIM_OSSIState;


  uint16_t TIM_LOCKLevel;


  uint16_t TIM_DeadTime;



  uint16_t TIM_Break;


  uint16_t TIM_BreakPolarity;


  uint16_t TIM_AutomaticOutput;

} TIM_BDTRInitTypeDef;
# 1026 "include/core/stm32f4xx_tim.h"
void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, uint32_t Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint32_t Autoreload);
uint32_t TIM_GetCounter(TIM_TypeDef* TIMx);
uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, uint16_t TIM_UpdateSource);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, uint16_t TIM_OPMode);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, uint16_t TIM_CKD);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);


void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint32_t Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint32_t Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, uint32_t Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, uint32_t Compare4);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);


void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
uint32_t TIM_GetCapture1(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture2(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture3(TIM_TypeDef* TIMx);
uint32_t TIM_GetCapture4(TIM_TypeDef* TIMx);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);


void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);


void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);


void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
                                uint16_t TIM_ICPolarity, uint16_t ICFilter);
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                             uint16_t ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler,
                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);


void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_MasterSlaveMode);
void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                   uint16_t ExtTRGFilter);


void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);


void TIM_RemapConfig(TIM_TypeDef* TIMx, uint16_t TIM_Remap);


}
# 65 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_usart.h" 1
# 34 "include/core/stm32f4xx_usart.h"
 extern "C" {
# 54 "include/core/stm32f4xx_usart.h"
typedef struct
{
  uint32_t USART_BaudRate;





  uint16_t USART_WordLength;


  uint16_t USART_StopBits;


  uint16_t USART_Parity;






  uint16_t USART_Mode;


  uint16_t USART_HardwareFlowControl;


} USART_InitTypeDef;





typedef struct
{

  uint16_t USART_Clock;


  uint16_t USART_CPOL;


  uint16_t USART_CPHA;


  uint16_t USART_LastBit;


} USART_ClockInitTypeDef;
# 369 "include/core/stm32f4xx_usart.h"
void USART_DeInit(USART_TypeDef* USARTx);


void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler);
void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState);


void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint16_t USART_ReceiveData(USART_TypeDef* USARTx);


void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);


void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendBreak(USART_TypeDef* USARTx);


void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);


void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime);


void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);


void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);


void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);


}
# 66 "include/core/stm32f4xx_conf.h" 2
# 1 "include/core/stm32f4xx_wwdg.h" 1
# 34 "include/core/stm32f4xx_wwdg.h"
 extern "C" {
# 82 "include/core/stm32f4xx_wwdg.h"
void WWDG_DeInit(void);


void WWDG_SetPrescaler(uint32_t WWDG_Prescaler);
void WWDG_SetWindowValue(uint8_t WindowValue);
void WWDG_EnableIT(void);
void WWDG_SetCounter(uint8_t Counter);


void WWDG_Enable(uint8_t Counter);


FlagStatus WWDG_GetFlagStatus(void);
void WWDG_ClearFlag(void);


}
# 67 "include/core/stm32f4xx_conf.h" 2
# 1 "include/misc.h" 1
# 34 "include/misc.h"
 extern "C" {
# 54 "include/misc.h"
typedef struct
{
  uint8_t NVIC_IRQChannel;




  uint8_t NVIC_IRQChannelPreemptionPriority;




  uint8_t NVIC_IRQChannelSubPriority;




  FunctionalState NVIC_IRQChannelCmd;


} NVIC_InitTypeDef;
# 158 "include/misc.h"
void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);


}
# 68 "include/core/stm32f4xx_conf.h" 2
# 7 "include/Altimeter.h" 2
# 1 "c:\\projects\\freertos\\src\\include\\freertos.h" 1
# 72 "c:\\projects\\freertos\\src\\include\\freertos.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stddef.h" 1 3 4
# 22 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stddef.h" 3 4
typedef unsigned size_t;






typedef int ptrdiff_t;
# 45 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stddef.h" 3 4
typedef unsigned wchar_t;
# 73 "c:\\projects\\freertos\\src\\include\\freertos.h" 2
# 90 "c:\\projects\\freertos\\src\\include\\freertos.h"
extern "C" {



# 1 "c:\\projects\\freertos\\src\\include\\projdefs.h" 1
# 73 "c:\\projects\\freertos\\src\\include\\projdefs.h"
typedef void (*TaskFunction_t)( void * );
# 95 "c:\\projects\\freertos\\src\\include\\freertos.h" 2


# 1 "include/FreeRTOSConfig.h" 1
# 92 "include/FreeRTOSConfig.h"
extern uint32_t SystemCoreClock;
# 98 "c:\\projects\\freertos\\src\\include\\freertos.h" 2
# 106 "c:\\projects\\freertos\\src\\include\\freertos.h"
# 1 "c:\\projects\\freertos\\src\\include\\portable.h" 1
# 321 "c:\\projects\\freertos\\src\\include\\portable.h"
# 1 "c:\\projects\\freertos\\src\\portable\\portmacro.h" 1
# 71 "c:\\projects\\freertos\\src\\portable\\portmacro.h"
extern "C" {
# 93 "c:\\projects\\freertos\\src\\portable\\portmacro.h"
typedef uint32_t StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;





 typedef uint32_t TickType_t;
# 114 "c:\\projects\\freertos\\src\\portable\\portmacro.h"
extern void vPortYield( void );
# 123 "c:\\projects\\freertos\\src\\portable\\portmacro.h"
extern void vPortEnterCritical( void );
extern void vPortExitCritical( void );
extern uint32_t ulPortSetInterruptMask( void );
extern void vPortClearInterruptMask( uint32_t ulNewMaskValue );
# 145 "c:\\projects\\freertos\\src\\portable\\portmacro.h"
 extern void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime );
# 180 "c:\\projects\\freertos\\src\\portable\\portmacro.h"
 void vPortValidateInterruptPriority( void );







}
# 322 "c:\\projects\\freertos\\src\\include\\portable.h" 2
# 349 "c:\\projects\\freertos\\src\\include\\portable.h"
extern "C" {


# 1 "c:\\projects\\freertos\\src\\include\\mpu_wrappers.h" 1
# 353 "c:\\projects\\freertos\\src\\include\\portable.h" 2
# 363 "c:\\projects\\freertos\\src\\include\\portable.h"
 StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters ) ;





void *pvPortMalloc( size_t xSize ) ;
void vPortFree( void *pv ) ;
void vPortInitialiseBlocks( void ) ;
size_t xPortGetFreeHeapSize( void ) ;
size_t xPortGetMinimumEverFreeHeapSize( void ) ;





BaseType_t xPortStartScheduler( void ) ;






void vPortEndScheduler( void ) ;
# 401 "c:\\projects\\freertos\\src\\include\\portable.h"
}
# 107 "c:\\projects\\freertos\\src\\include\\freertos.h" 2
# 752 "c:\\projects\\freertos\\src\\include\\freertos.h"
}
# 8 "include/Altimeter.h" 2
# 1 "c:\\projects\\freertos\\src\\include\\semphr.h" 1
# 73 "c:\\projects\\freertos\\src\\include\\semphr.h"
# 1 "c:\\projects\\freertos\\src\\include\\queue.h" 1
# 75 "c:\\projects\\freertos\\src\\include\\queue.h"
extern "C" {
# 84 "c:\\projects\\freertos\\src\\include\\queue.h"
typedef void * QueueHandle_t;






typedef void * QueueSetHandle_t;






typedef void * QueueSetMemberHandle_t;
# 588 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueGenericSend( QueueHandle_t xQueue, const void * const pvItemToQueue, TickType_t xTicksToWait, const BaseType_t xCopyPosition ) ;
# 717 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueuePeekFromISR( QueueHandle_t xQueue, void * const pvBuffer ) ;
# 909 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueGenericReceive( QueueHandle_t xQueue, void * const pvBuffer, TickType_t xTicksToWait, const BaseType_t xJustPeek ) ;
# 924 "c:\\projects\\freertos\\src\\include\\queue.h"
UBaseType_t uxQueueMessagesWaiting( const QueueHandle_t xQueue ) ;
# 941 "c:\\projects\\freertos\\src\\include\\queue.h"
UBaseType_t uxQueueSpacesAvailable( const QueueHandle_t xQueue ) ;
# 955 "c:\\projects\\freertos\\src\\include\\queue.h"
void vQueueDelete( QueueHandle_t xQueue ) ;
# 1335 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueGenericSendFromISR( QueueHandle_t xQueue, const void * const pvItemToQueue, BaseType_t * const pxHigherPriorityTaskWoken, const BaseType_t xCopyPosition ) ;
# 1424 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueReceiveFromISR( QueueHandle_t xQueue, void * const pvBuffer, BaseType_t * const pxHigherPriorityTaskWoken ) ;





BaseType_t xQueueIsQueueEmptyFromISR( const QueueHandle_t xQueue ) ;
BaseType_t xQueueIsQueueFullFromISR( const QueueHandle_t xQueue ) ;
UBaseType_t uxQueueMessagesWaitingFromISR( const QueueHandle_t xQueue ) ;
# 1449 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueAltGenericSend( QueueHandle_t xQueue, const void * const pvItemToQueue, TickType_t xTicksToWait, BaseType_t xCopyPosition );
BaseType_t xQueueAltGenericReceive( QueueHandle_t xQueue, void * const pvBuffer, TickType_t xTicksToWait, BaseType_t xJustPeeking );
# 1465 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueCRSendFromISR( QueueHandle_t xQueue, const void *pvItemToQueue, BaseType_t xCoRoutinePreviouslyWoken );
BaseType_t xQueueCRReceiveFromISR( QueueHandle_t xQueue, void *pvBuffer, BaseType_t *pxTaskWoken );
BaseType_t xQueueCRSend( QueueHandle_t xQueue, const void *pvItemToQueue, TickType_t xTicksToWait );
BaseType_t xQueueCRReceive( QueueHandle_t xQueue, void *pvBuffer, TickType_t xTicksToWait );






QueueHandle_t xQueueCreateMutex( const uint8_t ucQueueType ) ;
QueueHandle_t xQueueCreateCountingSemaphore( const UBaseType_t uxMaxCount, const UBaseType_t uxInitialCount ) ;
void* xQueueGetMutexHolder( QueueHandle_t xSemaphore ) ;





BaseType_t xQueueTakeMutexRecursive( QueueHandle_t xMutex, TickType_t xTicksToWait ) ;
BaseType_t xQueueGiveMutexRecursive( QueueHandle_t pxMutex ) ;
# 1517 "c:\\projects\\freertos\\src\\include\\queue.h"
 void vQueueAddToRegistry( QueueHandle_t xQueue, const char *pcName ) ;
# 1531 "c:\\projects\\freertos\\src\\include\\queue.h"
 void vQueueUnregisterQueue( QueueHandle_t xQueue ) ;






QueueHandle_t xQueueGenericCreate( const UBaseType_t uxQueueLength, const UBaseType_t uxItemSize, const uint8_t ucQueueType ) ;
# 1588 "c:\\projects\\freertos\\src\\include\\queue.h"
QueueSetHandle_t xQueueCreateSet( const UBaseType_t uxEventQueueLength ) ;
# 1612 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueAddToSet( QueueSetMemberHandle_t xQueueOrSemaphore, QueueSetHandle_t xQueueSet ) ;
# 1631 "c:\\projects\\freertos\\src\\include\\queue.h"
BaseType_t xQueueRemoveFromSet( QueueSetMemberHandle_t xQueueOrSemaphore, QueueSetHandle_t xQueueSet ) ;
# 1667 "c:\\projects\\freertos\\src\\include\\queue.h"
QueueSetMemberHandle_t xQueueSelectFromSet( QueueSetHandle_t xQueueSet, const TickType_t xTicksToWait ) ;




QueueSetMemberHandle_t xQueueSelectFromSetFromISR( QueueSetHandle_t xQueueSet ) ;


void vQueueWaitForMessageRestricted( QueueHandle_t xQueue, TickType_t xTicksToWait ) ;
BaseType_t xQueueGenericReset( QueueHandle_t xQueue, BaseType_t xNewQueue ) ;
void vQueueSetQueueNumber( QueueHandle_t xQueue, UBaseType_t uxQueueNumber ) ;
UBaseType_t uxQueueGetQueueNumber( QueueHandle_t xQueue ) ;
uint8_t ucQueueGetQueueType( QueueHandle_t xQueue ) ;



}
# 74 "c:\\projects\\freertos\\src\\include\\semphr.h" 2

typedef QueueHandle_t SemaphoreHandle_t;
# 9 "include/Altimeter.h" 2
# 1 "c:\\projects\\freertos\\src\\include\\queue.h" 1
# 10 "include/Altimeter.h" 2
# 1 "c:\\projects\\freertos\\src\\include\\task.h" 1
# 74 "c:\\projects\\freertos\\src\\include\\task.h"
# 1 "c:\\projects\\freertos\\src\\include\\list.h" 1
# 131 "c:\\projects\\freertos\\src\\include\\list.h"
extern "C" {




struct xLIST_ITEM
{
 TickType_t xItemValue;
 struct xLIST_ITEM * pxNext;
 struct xLIST_ITEM * pxPrevious;
 void * pvOwner;
 void * pvContainer;
};
typedef struct xLIST_ITEM ListItem_t;

struct xMINI_LIST_ITEM
{
 TickType_t xItemValue;
 struct xLIST_ITEM * pxNext;
 struct xLIST_ITEM * pxPrevious;
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;




typedef struct xLIST
{
 UBaseType_t uxNumberOfItems;
 ListItem_t * pxIndex;
 MiniListItem_t xListEnd;
} List_t;
# 336 "c:\\projects\\freertos\\src\\include\\list.h"
void vListInitialise( List_t * const pxList );
# 347 "c:\\projects\\freertos\\src\\include\\list.h"
void vListInitialiseItem( ListItem_t * const pxItem );
# 360 "c:\\projects\\freertos\\src\\include\\list.h"
void vListInsert( List_t * const pxList, ListItem_t * const pxNewListItem );
# 381 "c:\\projects\\freertos\\src\\include\\list.h"
void vListInsertEnd( List_t * const pxList, ListItem_t * const pxNewListItem );
# 396 "c:\\projects\\freertos\\src\\include\\list.h"
UBaseType_t uxListRemove( ListItem_t * const pxItemToRemove );


}
# 75 "c:\\projects\\freertos\\src\\include\\task.h" 2


extern "C" {
# 99 "c:\\projects\\freertos\\src\\include\\task.h"
typedef void * TaskHandle_t;





typedef BaseType_t (*TaskHookFunction_t)( void * );


typedef enum
{
 eRunning = 0,
 eReady,
 eBlocked,
 eSuspended,
 eDeleted
} eTaskState;




typedef struct xTIME_OUT
{
 BaseType_t xOverflowCount;
 TickType_t xTimeOnEntering;
} TimeOut_t;




typedef struct xMEMORY_REGION
{
 void *pvBaseAddress;
 uint32_t ulLengthInBytes;
 uint32_t ulParameters;
} MemoryRegion_t;




typedef struct xTASK_PARAMETERS
{
 TaskFunction_t pvTaskCode;
 const char * const pcName;
 uint16_t usStackDepth;
 void *pvParameters;
 UBaseType_t uxPriority;
 StackType_t *puxStackBuffer;
 MemoryRegion_t xRegions[ 1 ];
} TaskParameters_t;



typedef struct xTASK_STATUS
{
 TaskHandle_t xHandle;
 const char *pcTaskName;
 UBaseType_t xTaskNumber;
 eTaskState eCurrentState;
 UBaseType_t uxCurrentPriority;
 UBaseType_t uxBasePriority;
 uint32_t ulRunTimeCounter;
 uint16_t usStackHighWaterMark;
} TaskStatus_t;


typedef enum
{
 eAbortSleep = 0,
 eStandardSleep,
 eNoTasksWaitingTimeout
} eSleepModeStatus;
# 447 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskAllocateMPURegions( TaskHandle_t xTask, const MemoryRegion_t * const pxRegions ) ;
# 488 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskDelete( TaskHandle_t xTaskToDelete ) ;
# 540 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskDelay( const TickType_t xTicksToDelay ) ;
# 599 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskDelayUntil( TickType_t * const pxPreviousWakeTime, const TickType_t xTimeIncrement ) ;
# 646 "c:\\projects\\freertos\\src\\include\\task.h"
UBaseType_t uxTaskPriorityGet( TaskHandle_t xTask ) ;
# 664 "c:\\projects\\freertos\\src\\include\\task.h"
eTaskState eTaskGetState( TaskHandle_t xTask ) ;
# 706 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskPrioritySet( TaskHandle_t xTask, UBaseType_t uxNewPriority ) ;
# 757 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskSuspend( TaskHandle_t xTaskToSuspend ) ;
# 806 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskResume( TaskHandle_t xTaskToResume ) ;
# 835 "c:\\projects\\freertos\\src\\include\\task.h"
BaseType_t xTaskResumeFromISR( TaskHandle_t xTaskToResume ) ;
# 868 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskStartScheduler( void ) ;
# 924 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskEndScheduler( void ) ;
# 975 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskSuspendAll( void ) ;
# 1029 "c:\\projects\\freertos\\src\\include\\task.h"
BaseType_t xTaskResumeAll( void ) ;
# 1044 "c:\\projects\\freertos\\src\\include\\task.h"
TickType_t xTaskGetTickCount( void ) ;
# 1060 "c:\\projects\\freertos\\src\\include\\task.h"
TickType_t xTaskGetTickCountFromISR( void ) ;
# 1074 "c:\\projects\\freertos\\src\\include\\task.h"
UBaseType_t uxTaskGetNumberOfTasks( void ) ;
# 1088 "c:\\projects\\freertos\\src\\include\\task.h"
char *pcTaskGetTaskName( TaskHandle_t xTaskToQuery ) ;
# 1109 "c:\\projects\\freertos\\src\\include\\task.h"
UBaseType_t uxTaskGetStackHighWaterMark( TaskHandle_t xTask ) ;
# 1150 "c:\\projects\\freertos\\src\\include\\task.h"
BaseType_t xTaskCallApplicationTaskHook( TaskHandle_t xTask, void *pvParameter ) ;
# 1159 "c:\\projects\\freertos\\src\\include\\task.h"
TaskHandle_t xTaskGetIdleTaskHandle( void );
# 1258 "c:\\projects\\freertos\\src\\include\\task.h"
UBaseType_t uxTaskGetSystemState( TaskStatus_t * const pxTaskStatusArray, const UBaseType_t uxArraySize, uint32_t * const pulTotalRunTime );
# 1305 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskList( char * pcWriteBuffer ) ;
# 1359 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskGetRunTimeStats( char *pcWriteBuffer ) ;
# 1380 "c:\\projects\\freertos\\src\\include\\task.h"
BaseType_t xTaskIncrementTick( void ) ;
# 1413 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskPlaceOnEventList( List_t * const pxEventList, const TickType_t xTicksToWait ) ;
void vTaskPlaceOnUnorderedEventList( List_t * pxEventList, const TickType_t xItemValue, const TickType_t xTicksToWait ) ;
# 1427 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskPlaceOnEventListRestricted( List_t * const pxEventList, const TickType_t xTicksToWait ) ;
# 1453 "c:\\projects\\freertos\\src\\include\\task.h"
BaseType_t xTaskRemoveFromEventList( const List_t * const pxEventList ) ;
BaseType_t xTaskRemoveFromUnorderedEventList( ListItem_t * pxEventListItem, const TickType_t xItemValue ) ;
# 1464 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskSwitchContext( void ) ;





TickType_t uxTaskResetEventItemValue( void ) ;




TaskHandle_t xTaskGetCurrentTaskHandle( void ) ;




void vTaskSetTimeOutState( TimeOut_t * const pxTimeOut ) ;





BaseType_t xTaskCheckForTimeOut( TimeOut_t * const pxTimeOut, TickType_t * const pxTicksToWait ) ;





void vTaskMissedYield( void ) ;





BaseType_t xTaskGetSchedulerState( void ) ;





void vTaskPriorityInherit( TaskHandle_t const pxMutexHolder ) ;





void vTaskPriorityDisinherit( TaskHandle_t const pxMutexHolder ) ;





BaseType_t xTaskGenericCreate( TaskFunction_t pxTaskCode, const char * const pcName, const uint16_t usStackDepth, void * const pvParameters, UBaseType_t uxPriority, TaskHandle_t * const pxCreatedTask, StackType_t * const puxStackBuffer, const MemoryRegion_t * const xRegions ) ;




UBaseType_t uxTaskGetTaskNumber( TaskHandle_t xTask ) ;





void vTaskSetTaskNumber( TaskHandle_t xTask, const UBaseType_t uxHandle ) ;
# 1537 "c:\\projects\\freertos\\src\\include\\task.h"
void vTaskStepTick( const TickType_t xTicksToJump ) ;
# 1553 "c:\\projects\\freertos\\src\\include\\task.h"
eSleepModeStatus eTaskConfirmSleepModeStatus( void ) ;


}
# 11 "include/Altimeter.h" 2
# 1 "include/I2C.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 5 "include/I2C.h" 2


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/exception" 1 3 4
# 14 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/exception" 3 4
namespace std
{

  class exception
  {
  public:
    exception() throw() { }
    virtual ~exception() throw();
    virtual const char* what() const throw();
  };

  class bad_exception : public exception
  {
  public:
    bad_exception() throw() { }
    virtual ~bad_exception() throw();
    virtual const char* what() const throw();
  };

  typedef void (*terminate_handler) ();
  typedef void (*unexpected_handler) ();
  terminate_handler set_terminate(terminate_handler) throw();
  void terminate();
  unexpected_handler set_unexpected(unexpected_handler) throw();
  void unexpected();
  bool uncaught_exception() throw();
}
# 8 "include/I2C.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cstdarg" 1 3 4
# 14 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cstdarg" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdarg.h" 1 3 4
# 36 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdarg.h" 3 4
typedef __va_list va_list;
# 15 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/cstdarg" 2 3 4

namespace std
{
using ::va_list;
}
# 9 "include/I2C.h" 2
# 1 "include/delay.h" 1





static inline void delay_us(uint32_t us) {
    us *= 13;

    asm volatile("   mov r0, %[us]          \n\t"
                 "1: subs r0, #1            \n\t"
                 "   bhi 1b                 \n\t"
                 :
                 : [us] "r" (us)
                 : "r0");
}

static inline void delay_ms(const uint32_t ms) {
    if (ms>50) {
        for (uint32_t i=0; i<ms/50UL; i++) delay_us(50*1000);
        delay_us((ms%50UL)*1000);
    } else {
        delay_us(ms*1000);
    }
}
# 10 "include/I2C.h" 2
# 1 "include/Logger.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 5 "include/Logger.h" 2


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 1 3 4
# 17 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
extern "C" {
# 57 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
void *memcpy(void *__s1, const void *__s2, size_t __n);
# 75 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
void *memccpy(void *__s1, const void *__s2, int __c, size_t __n);
# 89 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
void *mempcpy(void *__s1, const void *__s2, size_t __n);
# 104 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
void *memmove(void *__s1, const void *__s2, size_t __n);
# 115 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
int memcmp(const void *__s1, const void *__s2, size_t __n);
# 129 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
void *memchr(const void *__s, int __c, size_t __n);
# 139 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
void *memset(void *__s, int __c, size_t __n);
# 150 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strcpy(char *__s1, const char *__s2);
# 170 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strncpy(char *__s1, const char *__s2, size_t __n);
# 187 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
size_t strlcpy(char *__s1, const char *__s2, size_t __n);
# 200 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strcat(char *__s1, const char *__s2);
# 214 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strncat(char *__s1, const char *__s2, size_t __n);
# 235 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
size_t strlcat(char *__s1, const char *__s2, size_t __n);
# 245 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
int strcmp(const char *__s1, const char *__s2);
# 258 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
int strncmp(const char *__s1, const char *__s2, size_t __n);
# 270 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
int strcasecmp(const char *__s1, const char *__s2);
# 285 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
int strncasecmp(const char *__s1, const char *__s2, size_t __n);
# 297 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strchr(const char *__s, int __c);
# 309 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strnchr(const char *__str, size_t __n, int __ch);
# 320 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
size_t strcspn(const char *__s1, const char *__s2);
# 331 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strpbrk(const char *__s1, const char *__s2);
# 343 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strrchr(const char *__s, int __c);
# 354 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
size_t strspn(const char *__s1, const char *__s2);
# 367 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strstr(const char *__s1, const char *__s2);
# 382 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strnstr(const char *__s1, const char *__s2, size_t __n);
# 397 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strcasestr(const char *__s1, const char *__s2);
# 413 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strncasestr(const char *__s1, const char *__s2, size_t __n);







size_t strlen(const char *__s);
# 432 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
size_t strnlen(const char *__s, size_t __n);
# 466 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strtok(char *__s1, const char *__s2);
# 485 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strsep(char **__stringp, const char *__delim);
# 498 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strtok_r(char *__s1, const char *__s2, char **__s3);
# 512 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strdup(const char *__s1);
# 530 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strndup(const char *__s1, size_t __n);
# 543 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/string.h" 3 4
char *strerror(int __num);



int strcoll(const char *__str1, const char *__str2);
size_t strxfrm( char *__str1, const char *__str2, size_t __num);



}
# 8 "include/Logger.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 1 3 4
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
extern "C" {



extern const float __float32_infinity;
extern const double __float64_infinity;
extern const float __float32_nan;
extern const double __float64_nan;
# 109 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
typedef float float_t;
typedef double double_t;
# 122 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float cosf(float __x);
# 134 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double cos(double __x);
# 146 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float sinf(float __x);
# 158 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double sin(double __x);
# 170 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float tanf(float __x);
# 182 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double tan(double __x);
# 195 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float acosf(float __x);
# 208 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double acos(double __x);
# 222 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float asinf(float __x);
# 236 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double asin(double __x);
# 245 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float atanf(float __x);







double atan(double __x);
# 276 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float atan2f(float __y, float __x);
# 299 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double atan2(double __x, double __y);
# 317 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float frexpf(float __x, int *__exp);
# 335 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double frexp(double __x, int *__exp);
# 350 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float ldexpf(float __x, int __exp);
# 364 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double ldexp(double __x, int __exp);
# 385 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float scalbnf(float __x, int __exp);
# 405 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double scalbn(double __x, int __exp);
# 420 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float logf(float __x);
# 435 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double log(double __x);
# 450 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float log10f(float __x);
# 465 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double log10(double __x);
# 483 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float fmodf(float __x, float __y);
# 501 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double fmod(double __x, double __y);
# 513 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float modff(float __x, float *__iptr);
# 525 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double modf(double __x, double *__iptr);
# 556 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float powf(float, float);
# 587 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double pow(double __x, double __y);
# 602 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float sqrtf(float __x);
# 617 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double sqrt(double __x);






float cbrtf(float __x);






double cbrt(double __x);
# 641 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float ceilf(float __x);
# 651 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double ceil(double __x);






float fabsf(float __x);






double fabs(double __x);
# 675 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float fminf(float __x, float __y);
# 685 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double fmin(double __x, double __y);
# 695 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float fmaxf(float __x, float __y);
# 705 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double fmax(double __x, double __y);
# 715 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float floorf(float);
# 725 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double floor(double);
# 738 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float hypotf(float __x, float __y);
# 751 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double hypot(double __x, double __y);
# 764 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float coshf(float __x);
# 777 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double cosh(double __x);
# 789 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float sinhf(float __x);
# 801 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double sinh(double __x);
# 811 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float tanhf(float __x);
# 820 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double tanh(double __x);
# 833 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float expf(float __x);
# 846 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double exp(double __x);
# 860 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float acoshf(float __x);
# 874 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double acosh(double __x);
# 886 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float asinhf(float __x);
# 898 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double asinh(double __x);
# 910 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
float atanhf(float __x);
# 924 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/math.h" 3 4
double atanh(double __x);






float fmaf(float __x, float __y, float __z);






double fma(double __x, double __y, double __z);




int __float32_isinf(float);
int __float64_isinf(double);
int __float32_isnan(float);
int __float64_isnan(double);
int __float32_isfinite(float);
int __float64_isfinite(double);
int __float32_isnormal(float);
int __float64_isnormal(double);
int __float32_signbit(float);
int __float64_signbit(double);
int __float32_classify(float);
int __float64_classify(double);



}
# 9 "include/Logger.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 1 3 4
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
extern "C" {
# 45 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int putchar(int __c);
# 54 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int getchar(void);
# 66 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int puts(const char *__s);
# 83 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
char *gets(char *__s);
# 102 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int sprintf(char *__s, const char *__format, ...);
# 130 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int snprintf(char *__s, size_t __n, const char *__format, ...);
# 166 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int vsnprintf(char *__s, size_t __n, const char *__format, __va_list __arg);
# 412 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int printf(const char *__format, ...);
# 432 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int vprintf(const char *__format, __va_list __arg);
# 461 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int vsprintf(char *__s, const char *__format, __va_list __arg);
# 662 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int scanf(const char *__format, ...);
# 682 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int sscanf(const char *__s, const char *__format, ...);
# 708 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int vscanf(const char *__format, __va_list __arg);
# 732 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
int vsscanf(const char *__s, const char *__format, __va_list __arg);
# 751 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stdio.h" 3 4
typedef struct __RAL_FILE FILE;


typedef long fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE *, fpos_t *);
char *fgets(char *, int, FILE *);
FILE *fopen(const char *, const char *);
int fprintf(FILE *, const char *, ...);
int fputc(int, FILE *);
int fputs(const char *, FILE *);
size_t fread(void *, size_t, size_t, FILE *);
FILE *freopen(const char *, const char *, FILE *);
int fscanf(FILE *, const char *, ...);
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);
int getc(FILE *);
void perror(const char *);
int putc(int, FILE *);
int remove(const char *);
int rename(const char *, const char *);
void rewind(FILE *);
void setbuf(FILE *, char *);
int setvbuf(FILE *, char *, int, size_t);
FILE *tmpfile(void);
char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE *, const char *, __va_list);
int vfscanf(FILE *, const char *, __va_list);


}
# 10 "include/Logger.h" 2
# 27 "include/Logger.h"
class LogMessage {
  public:
    LogMessage();
    long time;
    virtual ~LogMessage();
    virtual char* toString(char* buffer, uint16_t length) = 0;
    virtual char* toDataString(char* buffer, uint16_t length) = 0;
    virtual uint16_t getSize() = 0;
    virtual char* getShortType() = 0;
};

class Text100LogMessage : public LogMessage {
  private:
    char textMessage[100];
  public:
    Text100LogMessage(char* msg);
    char* toString(char* buffer, uint16_t length);
    char* toDataString(char* buffer, uint16_t length);
    uint16_t getSize();
    char* getShortType();
};

class Logger {
  private:
    Logger();
    uint32_t addressOffset;
    uint32_t id;
    bool isInitted;
    void SDRAM_WriteBuffer(uint8_t* pBuffer, uint32_t uwWriteAddress, uint32_t uwBufferSize);
    void SDRAM_ReadBuffer(uint8_t* pBuffer, uint32_t uwReadAddress, uint32_t uwBufferSize);
    Logger(Logger const&);
    void operator=(Logger const&);
  public:
    static Logger& getInstance();
    void init();
    void setId(const uint32_t id);
    const uint32_t getId();
    bool testLogger();
    void logMessage(LogMessage* msg);
    void dumpLog(const char* typeStr);
    void dumpUsageStmt();
};
# 11 "include/I2C.h" 2

class I2C {
    private:
        I2C_TypeDef* i2Cx;
        uint8_t address;

        void start(uint8_t direction);
        void stop();
        void write(uint8_t data);
        uint8_t read_ack();
        uint8_t read_nack();

    public:
        I2C(I2C_TypeDef* i2Cx, uint8_t address);
        void write(uint8_t regstr, uint8_t bytes, uint8_t* buffer);
        void read(uint8_t regstr, uint8_t bytes, uint8_t* buffer);
        void write(uint8_t regstr, uint8_t value);
        uint8_t read(uint8_t regstr);
};

class I2cTimeoutException : public std::exception {
    public:
      virtual const char* what() const throw() {
        return "I2C timeout exception thrown";
    }
};
# 12 "include/Altimeter.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/Math.h" 1 3 4
# 13 "include/Altimeter.h" 2
# 1 "include/TaskWrapper.h" 1







class TaskBase {
public:
  TaskHandle_t handle;

  ~TaskBase() {



    return;
  }
};

class Task : public TaskBase {
public:
    Task(const char *name, void (*taskfun)(void *), unsigned long priority,
       unsigned short stackDepth=( ( unsigned short ) 130 )) {

    xTaskGenericCreate( ( taskfun ), ( name ), ( stackDepth ), ( this ), ( priority ), ( &handle ), ( 0 ), ( 0 ) );
  }

};

class TaskClass : public TaskBase {
public:
    TaskClass() {}
    void startTask(const char *name, unsigned long priority,
           unsigned short stackDepth=( ( unsigned short ) 130 )) {

        xTaskGenericCreate( ( &taskfun ), ( name ), ( stackDepth ), ( this ), ( priority ), ( &handle ), ( 0 ), ( 0 ) );
    }
    virtual void task() = 0;
    static void taskfun(void* param) {
        static_cast<TaskClass*>(param)->task();



        while(1)
            vTaskDelay(10000);

   }
};
# 14 "include/Altimeter.h" 2


class Altimeter : public TaskClass {
  public:
    Altimeter(SemaphoreHandle_t *semaphore, QueueHandle_t *queue);
    void init();
    void task();

  private:
    SemaphoreHandle_t *semaphore;
    QueueHandle_t *queue;
    uint8_t altAddress;
    I2C *altI2C;
    uint16_t ac4, ac5, ac6;
    int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
    void initIO();
    void readCalData();
    float measureAltitude();
};
# 2 "C:/projects/flight/firmware/src/Altimeter.cpp" 2

Altimeter::Altimeter(SemaphoreHandle_t *semaphore, QueueHandle_t *queue) {
    this->semaphore = semaphore;
    this->queue = queue;
    altAddress = 0b11101110;
    altI2C = new I2C(((I2C_TypeDef *) (((uint32_t)0x40000000) + 0x5C00)), altAddress);
}


void Altimeter::init() {
    initIO();
    readCalData();
}

void Altimeter::initIO() {
    GPIO_InitTypeDef GPIO_InitStruct;
    I2C_InitTypeDef I2C_InitStruct;

    RCC_APB1PeriphClockCmd(((uint32_t)0x00800000), ENABLE);
    RCC_AHB1PeriphClockCmd(((uint32_t)0x00000080), ENABLE);

    GPIO_InitStruct.GPIO_Pin = ((uint16_t)0x0080) | ((uint16_t)0x0100);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x00020000) + 0x1C00)), &GPIO_InitStruct);

    GPIO_PinAFConfig(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x00020000) + 0x1C00)), ((uint8_t)0x07), ((uint8_t)0x04));
    GPIO_PinAFConfig(((GPIO_TypeDef *) ((((uint32_t)0x40000000) + 0x00020000) + 0x1C00)), ((uint8_t)0x08), ((uint8_t)0x04));

    I2C_InitStruct.I2C_ClockSpeed = 400000;
    I2C_InitStruct.I2C_Mode = ((uint16_t)0x0000);
    I2C_InitStruct.I2C_DutyCycle = ((uint16_t)0xBFFF);
    I2C_InitStruct.I2C_OwnAddress1 = 0x00;
    I2C_InitStruct.I2C_Ack = ((uint16_t)0x0000);
    I2C_InitStruct.I2C_AcknowledgedAddress = ((uint16_t)0x4000);
    I2C_Init(((I2C_TypeDef *) (((uint32_t)0x40000000) + 0x5C00)), &I2C_InitStruct);

    I2C_Cmd(((I2C_TypeDef *) (((uint32_t)0x40000000) + 0x5C00)), ENABLE);
}

void Altimeter::readCalData() {
    ac1 = (altI2C->read(0xAA) << 8) | altI2C->read(0xAB);
    ac2 = (altI2C->read(0xAC) << 8) | altI2C->read(0xAD);
    ac3 = (altI2C->read(0xAE) << 8) | altI2C->read(0xAF);
    ac4 = (altI2C->read(0xB0) << 8) | altI2C->read(0xB1);
    ac5 = (altI2C->read(0xB2) << 8) | altI2C->read(0xB3);
    ac6 = (altI2C->read(0xB4) << 8) | altI2C->read(0xB5);
    b1 = (altI2C->read(0xB6) << 8) | altI2C->read(0xB7);
    b2 = (altI2C->read(0xB8) << 8) | altI2C->read(0xB9);
    mb = (altI2C->read(0xBA) << 8) | altI2C->read(0xBB);
    mc = (altI2C->read(0xBC) << 8) | altI2C->read(0xBD);
    md = (altI2C->read(0xBE) << 8) | altI2C->read(0xBF);
}

void Altimeter::task() {
    while (true) {
        if (xQueueGenericReceive( ( QueueHandle_t ) ( *semaphore ), 0, ( 0 ), ( ( BaseType_t ) 0 ) ) == ( ( BaseType_t ) 1 )) {
            float altitude = measureAltitude();

            xQueueGenericSend( ( *this->queue ), ( &altitude ), 0, ( ( BaseType_t ) 2 ) );
        }

        vTaskDelay(( ( TickType_t ) 1000 / ( ( TickType_t ) 1000 ) ) * 20);
    }
}

float Altimeter::measureAltitude() {
    try {
        altI2C->write(0xF4, 0x2E);
        vTaskDelay(( ( TickType_t ) 1000 / ( ( TickType_t ) 1000 ) ) * 5);
        long ut = (altI2C->read(0xF6) << 8) + altI2C->read(0xF7);
        uint8_t oss = 3;
        altI2C->write(0xF4, 0x34 + (oss<<6));
        vTaskDelay(( ( TickType_t ) 1000 / ( ( TickType_t ) 1000 ) ) * 26);
        int32_t up = ((altI2C->read(0xF6) << 16) + (altI2C->read(0xF7) << 8) + ((altI2C->read(0xF8)))) >> (8-oss);


        int32_t x1 = (ut-ac6) * ac5/(1<<15);
        int32_t x2 = mc * (1<<11) / (x1 + md);
        int32_t b5 = x1 + x2;
        float t = ((b5 + 8) / (1<<4))/10.0;


        uint32_t b4;
        uint32_t b7;
        int32_t p;
        int32_t b6 = b5 - 4000;
        x1 = (b2 * ((b6 * b6) >> 12)) >> 11;
        x2 = (ac2 * b6) >> 11;
        int32_t x3 = x1 + x2;
        int32_t b3 = ((((int32_t)ac1 * 4 + x3) << oss) + 2) >> 2;
        x1 = (ac3 * b6) >> 13;
        x2 = (b1 * ((b6 * b6) >> 12)) >> 16;
        x3 = (x1 + x2 + 2) >> 2;
        b4 = (ac4 * (uint32_t)(x3 + 32768)) >> 15;
        b7 = ((uint32_t)(up - b3) * (50000 >> oss));
        if (b7 < 0x80000000) {
            p = (b7 << 1) / b4;
        } else {
            p = (b7/b4) << 1;
        }
        x1 = (p >> 8) * (p >> 8);
        x1 = (x1 * 3038) >> 16;
        x2 = (-7357 * p) >> 16;
        p = p + ((x1 + x2 + 3791) >> 4);



        return (powf(1013.25 / (p/100), 1/5.255) - 1)*(t -10 + 273.15) / 0.0065;
    }
    catch (I2cTimeoutException& te) {
        LogMessage* msg = new Text100LogMessage("I2C timeout exception occured in Altimeter::measureAltitude()");
        Logger::getInstance().logMessage(msg);
        delete msg;
    }
    catch (std::exception& e) {
        LogMessage* msg = new Text100LogMessage("unknown exception occured in Altimeter::measureAltitude()");
        Logger::getInstance().logMessage(msg);
        delete msg;
    }
    return 0;
}
