# 1 "C:/projects/flight/firmware/test/ControlTask_test.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/projects/flight/firmware/test/ControlTask_test.cpp"
# 1 "c:\\projects\\embunit\\embunit\\embunit.h" 1
# 38 "c:\\projects\\embunit\\embunit\\embunit.h"
# 1 "c:\\projects\\embunit\\embunit\\test.h" 1
# 38 "c:\\projects\\embunit\\embunit\\test.h"
typedef struct __TestResult TestResult;
typedef struct __TestResult* TestResultRef;

typedef struct __TestImplement TestImplement;
typedef struct __TestImplement* TestImplementRef;

typedef char*(*TestNameFunction)(void*);
typedef void(*TestRunFunction)(void*,TestResult*);
typedef int(*TestCountTestCasesFunction)(void*);

struct __TestImplement {
 TestNameFunction name;
 TestRunFunction run;
 TestCountTestCasesFunction countTestCases;
};

typedef struct __Test Test;
typedef struct __Test* TestRef;

struct __Test {
 TestImplement* isa;
};
# 39 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\testcase.h" 1
# 38 "c:\\projects\\embunit\\embunit\\testcase.h"
typedef struct __TestCase TestCase;
typedef struct __TestCase* TestCaseRef;

struct __TestCase {
 TestImplement* isa;
 char *name;
 void(*setUp)(void);
 void(*tearDown)(void);
 void(*runTest)(void);
};

extern const TestImplement TestCaseImplement;
# 40 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\testlistener.h" 1
# 38 "c:\\projects\\embunit\\embunit\\testlistener.h"
typedef struct __TestListnerImplement TestListnerImplement;
typedef struct __TestListnerImplement* TestListnerImplementRef;

typedef void(*TestListnerStartTestCallBack)(void*,void*);
typedef void(*TestListnerEndTestCallBack)(void*,void*);
typedef void(*TestListnerAddFailureCallBack)(void*,void*,const char*,int,const char*);

struct __TestListnerImplement {
 TestListnerStartTestCallBack startTest;
 TestListnerEndTestCallBack endTest;
 TestListnerAddFailureCallBack addFailure;
};




struct __TestListner {
 TestListnerImplement* isa;
};
# 41 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\testresult.h" 1
# 39 "c:\\projects\\embunit\\embunit\\testresult.h"
extern "C" {





typedef struct __TestListner TestListner;
typedef struct __TestListner* TestListnerRef;

struct __TestResult {
 unsigned short runCount;
 unsigned short failureCount;
 TestListner* listener;
};
# 61 "c:\\projects\\embunit\\embunit\\testresult.h"
void TestResult_init(TestResult* self,TestListner* listner);
void TestResult_startTest(TestResult* self,Test* test);
void TestResult_endTest(TestResult* self,Test* test);
void TestResult_addFailure(TestResult* self,Test* test,const char* msg,int line,const char* file);


}
# 42 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\testsuite.h" 1
# 38 "c:\\projects\\embunit\\embunit\\testsuite.h"
typedef struct __TestSuite TestSuite;
typedef struct __TestSuite* TestSuiteRef;

struct __TestSuite {
 TestImplement* isa;
 char *name;
 int numberOfTests;
 Test** tests;
};

extern const TestImplement TestSuiteImplement;
# 43 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\testrunner.h" 1
# 39 "c:\\projects\\embunit\\embunit\\testrunner.h"
extern "C" {


void TestRunner_start(void);
void TestRunner_runTest(Test* test);
void TestRunner_end(void);
TestResult TestRunner_getResult(void);


}
# 44 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\testcaller.h" 1
# 38 "c:\\projects\\embunit\\embunit\\testcaller.h"
typedef struct __TestFixture TestFixture;
typedef struct __TestFixture* TestFixtureRef;

struct __TestFixture {
 char *name;
 void(*test)(void);
};







typedef struct __TestCaller TestCaller;
typedef struct __TestCaller* TestCallerRef;

struct __TestCaller {
 TestImplement* isa;
 char *name;
 void(*setUp)(void);
 void(*tearDown)(void);
 int numberOfFixtuers;
 TestFixture *fixtuers;
};

extern const TestImplement TestCallerImplement;
# 45 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\repeatedtest.h" 1
# 38 "c:\\projects\\embunit\\embunit\\repeatedtest.h"
typedef struct __RepeatedTest RepeatedTest;
typedef struct __RepeatedTest* RepeatedTestRef;

struct __RepeatedTest {
 TestImplement* isa;
 Test* test;
 int timesRepeat;
};

extern const TestImplement RepeatedTestImplement;
# 46 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\stdimpl.h" 1
# 39 "c:\\projects\\embunit\\embunit\\stdimpl.h"
extern "C" {






char* stdimpl_strcpy(char *s1, const char *s2);
char* stdimpl_strcat(char *dst, const char *src);
char* stdimpl_strncat(char *dst, const char *src,unsigned int count);
int stdimpl_strlen(const char *str);
int stdimpl_strcmp(const char *s1, const char *s2);
char* stdimpl_itoa(int v,char *string,int r);


}
# 47 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\assertimpl.h" 1
# 39 "c:\\projects\\embunit\\embunit\\assertimpl.h"
extern "C" {


void addFailure(const char *msg, long line, const char *file);

void assertImplementationInt(int expected,int actual, long line, const char *file);
void assertImplementationCStr(const char *expected,const char *actual, long line, const char *file);
# 69 "c:\\projects\\embunit\\embunit\\assertimpl.h"
}
# 48 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 1 "c:\\projects\\embunit\\embunit\\helpermacro.h" 1
# 49 "c:\\projects\\embunit\\embunit\\embunit.h" 2
# 2 "C:/projects/flight/firmware/test/ControlTask_test.cpp" 2
# 1 "include/ControlTask.h" 1



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
# 5 "include/ControlTask.h" 2
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
# 6 "include/ControlTask.h" 2
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
# 7 "include/ControlTask.h" 2
# 1 "c:\\projects\\freertos\\src\\include\\freertos.h" 1
# 72 "c:\\projects\\freertos\\src\\include\\freertos.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stddef.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stddef.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 1
# 42 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stlport_version.h" 1
# 43 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 2
# 63 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/user_config.h" 1
# 64 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 2
# 88 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/compat.h" 1
# 89 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 2


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/host.h" 1
# 92 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 2


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/_system.h" 1
# 164 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/_system.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/_crossworks.h" 1
# 165 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/_system.h" 2
# 95 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 2
# 103 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/stl_confix.h" 1
# 104 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 2
# 218 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/_native_headers.h" 1
# 219 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h" 2
# 415 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
namespace std { }
namespace __std_alias = std;
# 494 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
namespace stlpmtx_std { }
# 536 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/config/features.h"
namespace stlport = stlpmtx_std;



namespace _STL = stlpmtx_std;
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 2
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stddef.h" 2
# 34 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stddef.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stddef.h" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stddef.h" 3 4
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\__crossworks.h" 1 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stddef.h" 2 3 4







typedef unsigned size_t;






typedef int ptrdiff_t;
# 45 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stddef.h" 3 4
typedef unsigned wchar_t;
# 35 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stddef.h" 2




# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 40 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stddef.h" 2
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
# 8 "include/ControlTask.h" 2
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
# 9 "include/ControlTask.h" 2
# 1 "c:\\projects\\freertos\\src\\include\\queue.h" 1
# 10 "include/ControlTask.h" 2
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
# 11 "include/ControlTask.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 2
# 32 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 1 3 4
# 23 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
extern "C" {



extern const float __float32_infinity;
extern const double __float64_infinity;
extern const float __float32_nan;
extern const double __float64_nan;
# 109 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
typedef float float_t;
typedef double double_t;
# 122 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float cosf(float __x);
# 134 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double cos(double __x);
# 146 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float sinf(float __x);
# 158 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double sin(double __x);
# 170 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float tanf(float __x);
# 182 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double tan(double __x);
# 195 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float acosf(float __x);
# 208 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double acos(double __x);
# 222 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float asinf(float __x);
# 236 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double asin(double __x);
# 245 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float atanf(float __x);







double atan(double __x);
# 276 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float atan2f(float __y, float __x);
# 299 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double atan2(double __x, double __y);
# 317 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float frexpf(float __x, int *__exp);
# 335 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double frexp(double __x, int *__exp);
# 350 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float ldexpf(float __x, int __exp);
# 364 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double ldexp(double __x, int __exp);
# 385 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float scalbnf(float __x, int __exp);
# 405 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double scalbn(double __x, int __exp);
# 420 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float logf(float __x);
# 435 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double log(double __x);
# 450 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float log10f(float __x);
# 465 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double log10(double __x);
# 483 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float fmodf(float __x, float __y);
# 501 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double fmod(double __x, double __y);
# 513 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float modff(float __x, float *__iptr);
# 525 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double modf(double __x, double *__iptr);
# 556 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float powf(float, float);
# 587 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double pow(double __x, double __y);
# 602 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float sqrtf(float __x);
# 617 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double sqrt(double __x);






float cbrtf(float __x);






double cbrt(double __x);
# 641 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float ceilf(float __x);
# 651 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double ceil(double __x);






float fabsf(float __x);






double fabs(double __x);
# 675 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float fminf(float __x, float __y);
# 685 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double fmin(double __x, double __y);
# 695 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float fmaxf(float __x, float __y);
# 705 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double fmax(double __x, double __y);
# 715 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float floorf(float);
# 725 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double floor(double);
# 738 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float hypotf(float __x, float __y);
# 751 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double hypot(double __x, double __y);
# 764 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float coshf(float __x);
# 777 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double cosh(double __x);
# 789 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float sinhf(float __x);
# 801 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double sinh(double __x);
# 811 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float tanhf(float __x);
# 820 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double tanh(double __x);
# 833 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float expf(float __x);
# 846 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double exp(double __x);
# 860 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float acoshf(float __x);
# 874 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double acosh(double __x);
# 886 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float asinhf(float __x);
# 898 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
double asinh(double __x);
# 910 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
float atanhf(float __x);
# 924 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\math.h" 3 4
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
# 33 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 2
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 2
# 12 "include/ControlTask.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 1
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 2
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 1 3 4
# 17 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
extern "C" {
# 73 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
typedef struct
{
  int quot;
  int rem;
} div_t;





typedef struct
{
  long quot;
  long rem;
} ldiv_t;






typedef struct
{
  long long quot;
  long rem;
} lldiv_t;






int abs(int __j);






long int labs(long int __j);






long long int llabs(long long int __j);
# 135 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
div_t div(int __numer, int __denom);
# 151 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
ldiv_t ldiv(long int __numer, long int __denom);
# 168 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
lldiv_t lldiv(long long int __numer, long long int __denom);
# 180 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
void *malloc(size_t __size);
# 192 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
void *calloc(size_t __nobj, size_t __size);
# 215 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
void *realloc(void *p, size_t __size);
# 228 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
void free(void *__p);
# 246 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
double atof(const char *__nptr);
# 286 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
double strtod(const char *__nptr, char **__endptr);
# 326 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
float strtof(const char *__nptr, char **__endptr);
# 344 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
int atoi(const char *__nptr);
# 362 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
long int atol(const char *__nptr);
# 381 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
long long int atoll(const char *__nptr);
# 439 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
long int strtol(const char *__nptr, char **__endptr, int __base);
# 497 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
long long int strtoll(const char *__nptr, char **__endptr, int __base);
# 555 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
unsigned long int strtoul(const char *__nptr, char **__endptr, int __base);
# 613 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
unsigned long long int strtoull(const char *__nptr, char **__endptr, int __base);
# 623 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
int rand(void);
# 639 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
void srand(unsigned int __seed);
# 653 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
void *bsearch(const void *__key,
              const void *__buf,
              size_t __num,
              size_t __size,
              int (*__compare)(const void *, const void *));
# 668 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
void qsort(void *__buf,
           size_t __num,
           size_t __size,
           int (*__compare)(const void *, const void *));

void abort(void);






void exit(int __exit_code);
# 690 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
int atexit(void (*__func)(void));

char *getenv(const char *__name);
int system(const char *__command);
# 712 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
char *itoa(int __val, char *__buf, int __radix);
# 726 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
char *utoa(unsigned val, char *buf, int radix);
# 744 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
char *ltoa(long __val, char *__buf, int __radix);
# 758 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
char *ultoa(unsigned long __val, char *__buf, int __radix);
# 776 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
char *lltoa(long long __val, char *__buf, int __radix);
# 790 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
char *ulltoa(unsigned long long __val, char *__buf, int __radix);
# 818 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
int mblen(const char *__s, size_t __n);
# 846 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
int mblen_l(const char *__s, size_t __n, struct __locale_s *__loc);
# 871 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
size_t mbstowcs(wchar_t *__pwcs, const char *__s, size_t __n);
# 882 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
size_t mbstowcs_l(wchar_t *__pwcs, const char *__s, size_t __n, struct __locale_s *__loc);
# 906 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
int mbtowc(wchar_t *__pwc, const char *__s, size_t __n);
# 931 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdlib.h" 3 4
int mbtowc_l(wchar_t *__pwc, const char *__s, size_t __n, struct __locale_s *__loc);


int wctomb(char *__s, wchar_t __wc);
int wctomb_l(char *__s, wchar_t __wc, struct __locale_s *__loc);

size_t wcstombs(char *__s, const wchar_t *__pwcs, size_t __n);
size_t wcstombs_l(char *__s, const wchar_t *__pwcs, size_t __n, struct __locale_s *__loc);


}
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 2
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 61 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 2
# 13 "include/ControlTask.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string" 1
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 1






# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 8 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 2
# 17 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/debug/_debug.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 2
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string" 2





# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 1
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 1
# 31 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstddef.h" 1
# 31 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstddef.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstddef" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstddef" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stddef.h" 1 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstddef" 2 3 4

namespace std
{
  using ::ptrdiff_t;
  using ::size_t;
}
# 32 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstddef.h" 2






namespace stlpmtx_std {
using std::ptrdiff_t;
using std::size_t;
}
# 32 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h" 1
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstdlib" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstdlib" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 1 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstdlib" 2 3 4

namespace std
{
using ::size_t;
using ::div_t;
using ::ldiv_t;
using ::lldiv_t;

using ::abs;
using ::labs;
using ::llabs;

using ::div;
using ::ldiv;
using ::lldiv;

using ::calloc;
using ::malloc;
using ::realloc;
using ::free;

using ::atof;
using ::atoi;
using ::atol;
using ::atoll;

using ::strtod;
using ::strtol;
using ::strtoll;
using ::strtoul;
using ::strtoull;

using ::rand;
using ::srand;

using ::bsearch;
using ::qsort;

using ::abort;
using ::exit;
using ::atexit;

using ::getenv;
using ::system;

using ::itoa;
using ::utoa;
using ::ltoa;
using ::ultoa;
using ::lltoa;
using ::ulltoa;

using ::mblen;
using ::mbtowc;
using ::mbstowcs;

using ::wcstombs;
using ::wctomb;

}

typedef long off_t;
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h" 2
# 55 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h"
namespace stlpmtx_std {
using std::div_t;
using std::ldiv_t;
using std::size_t;




using std::abort;
using std::getenv;
using std::mblen;
using std::mbtowc;
using std::system;
using std::bsearch;

using std::atexit;
using std::exit;
using std::calloc;
using std::free;
using std::malloc;
using std::realloc;
using std::atof;
using std::atoi;
using std::atol;
using std::mbstowcs;
using std::strtod;
using std::strtol;
using std::strtoul;


using std::wcstombs;

using std::wctomb;


using std::qsort;
using std::labs;
using std::ldiv;


using std::llabs;
using std::lldiv_t;
using std::lldiv;






using std::rand;
using std::srand;

}
# 131 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h"
inline long abs(long __x) { return std::labs(__x); }





inline std::ldiv_t div(long __x, long __y) { return std::ldiv(__x, __y); }
# 151 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h"
inline long long abs(long long __x) { return std::llabs(__x); }
inline lldiv_t div(long long __x, long long __y) { return std::lldiv(__x, __y); }
# 169 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cmath.h" 1
# 38 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cmath.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cmath" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cmath" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 1 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cmath" 2 3 4

namespace std {


  using ::acos;
  using ::acosf;


  using ::asin;
  using ::asinf;


  using ::atan;
  using ::atanf;


  using ::atan2;
  using ::atan2f;


  using ::cos;
  using ::cosf;


  using ::sin;
  using ::sinf;


  using ::tan;
  using ::tanf;


  using ::cosh;
  using ::coshf;


  using ::sinh;
  using ::sinhf;


  using ::tanh;
  using ::tanhf;


  using ::exp;
  using ::expf;


  using ::frexp;
  using ::frexpf;


  using ::ldexp;
  using ::ldexpf;


  using ::scalbn;
  using ::scalbnf;


  using ::log;
  using ::logf;


  using ::log10;
  using ::log10f;


  using ::fmod;
  using ::fmodf;


  using ::modf;
  using ::modff;


  using ::pow;
  using ::powf;


  using ::sqrt;
  using ::sqrtf;


  using ::ceil;
  using ::ceilf;


  using ::fabs;
  using ::fabsf;


  using ::fmin;
  using ::fminf;


  using ::fmax;
  using ::fmaxf;


  using ::floor;
  using ::floorf;


  using ::hypot;
  using ::hypotf;


  using ::acosh;
  using ::acoshf;


  using ::asinh;
  using ::asinhf;


  using ::atanh;
  using ::atanhf;
}
# 39 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cmath.h" 2
# 424 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cmath.h"
inline double abs(double __x)
{ return ::fabs(__x); }

inline float abs (float x) { return ::fabsf(x); }




inline float acos (float x) { return ::acosf(x); }
inline float asin (float x) { return ::asinf(x); }
inline float atan (float x) { return ::atanf(x); }
inline float atan2 (float x, float y) { return ::atan2f(x, y); }
inline float ceil (float x) { return ::ceilf(x); }
inline float cos (float x) { return ::cosf(x); }
inline float cosh (float x) { return ::coshf(x); }
inline float exp (float x) { return ::expf(x); }
inline float fabs (float x) { return ::fabsf(x); }
inline float floor (float x) { return ::floorf(x); }
inline float fmod (float x, float y) { return ::fmodf(x, y); }
inline float frexp (float x, int * y) { return ::frexpf(x, y); }
inline float ldexp (float x, int y) { return ::ldexpf(x, y); }
inline float log (float x) { return ::logf(x); }
inline float log10 (float x) { return ::log10f(x); }
inline float modf (float x, float * y) { return ::modff(x, y); }
inline float sin (float x) { return ::sinf(x); }
inline float sinh (float x) { return ::sinhf(x); }
inline float sqrt (float x) { return ::sqrtf(x); }
inline float tan (float x) { return ::tanf(x); }
inline float tanh (float x) { return ::tanhf(x); }
inline float pow (float x, float y) { return ::powf(x, y); }




inline float pow(float __x, int __y) { return ::powf(__x, static_cast<float>(__y)); }






inline double pow(double __x, int __y) { return ::pow(__x, static_cast<double>(__y)); }
# 534 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cmath.h"
namespace stlpmtx_std {
using ::abs;
using ::acos;
using ::asin;
using ::atan;
using ::atan2;
using ::ceil;
using ::cos;
using ::cosh;
using ::exp;
using ::fabs;
using ::floor;
using ::fmod;
using ::frexp;
# 556 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cmath.h"
using ::hypot;

using ::ldexp;
using ::log;
using ::log10;
using ::modf;
using ::pow;
using ::sin;
using ::sinh;
using ::sqrt;
using ::tan;
using ::tanh;
}
# 170 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdlib.h" 2




namespace stlpmtx_std {
using ::abs;
using ::div;
}
# 36 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstring.h" 1
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstring.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstring" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstring" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 1 3 4
# 39 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 3 4
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 1 3 4
# 17 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
extern "C" {
# 57 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
void *memcpy(void *__s1, const void *__s2, size_t __n);
# 75 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
void *memccpy(void *__s1, const void *__s2, int __c, size_t __n);
# 89 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
void *mempcpy(void *__s1, const void *__s2, size_t __n);
# 104 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
void *memmove(void *__s1, const void *__s2, size_t __n);
# 115 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
int memcmp(const void *__s1, const void *__s2, size_t __n);
# 129 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
void *memchr(const void *__s, int __c, size_t __n);
# 139 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
void *memset(void *__s, int __c, size_t __n);
# 150 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strcpy(char *__s1, const char *__s2);
# 170 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strncpy(char *__s1, const char *__s2, size_t __n);
# 187 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
size_t strlcpy(char *__s1, const char *__s2, size_t __n);
# 200 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strcat(char *__s1, const char *__s2);
# 214 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strncat(char *__s1, const char *__s2, size_t __n);
# 235 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
size_t strlcat(char *__s1, const char *__s2, size_t __n);
# 245 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
int strcmp(const char *__s1, const char *__s2);
# 258 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
int strncmp(const char *__s1, const char *__s2, size_t __n);
# 270 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
int strcasecmp(const char *__s1, const char *__s2);
# 285 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
int strncasecmp(const char *__s1, const char *__s2, size_t __n);
# 297 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strchr(const char *__s, int __c);
# 309 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strnchr(const char *__str, size_t __n, int __ch);
# 320 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
size_t strcspn(const char *__s1, const char *__s2);
# 331 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strpbrk(const char *__s1, const char *__s2);
# 343 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strrchr(const char *__s, int __c);
# 354 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
size_t strspn(const char *__s1, const char *__s2);
# 367 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strstr(const char *__s1, const char *__s2);
# 382 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strnstr(const char *__s1, const char *__s2, size_t __n);
# 397 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strcasestr(const char *__s1, const char *__s2);
# 413 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strncasestr(const char *__s1, const char *__s2, size_t __n);







size_t strlen(const char *__s);
# 432 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
size_t strnlen(const char *__s, size_t __n);
# 466 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strtok(char *__s1, const char *__s2);
# 485 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strsep(char **__stringp, const char *__delim);
# 498 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strtok_r(char *__s1, const char *__s2, char **__s3);
# 512 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strdup(const char *__s1);
# 530 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strndup(const char *__s1, size_t __n);
# 543 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\string.h" 3 4
char *strerror(int __num);



int strcoll(const char *__str1, const char *__str2);
size_t strxfrm( char *__str1, const char *__str2, size_t __num);



}
# 40 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstring" 2 3 4

namespace std
{
using ::memcpy;
using ::memmove;
using ::memcmp;
using ::memchr;
using ::memset;

using ::size_t;

using ::strcpy;
using ::strncpy;
using ::strcat;
using ::strncat;
using ::strcmp;
using ::strncmp;
using ::strchr;
using ::strcspn;
using ::strpbrk;
using ::strrchr;
using ::strspn;
using ::strstr;
using ::strlen;
using ::strtok;

using ::strcoll;
using ::strerror;
using ::strxfrm;
}
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstring.h" 2






namespace stlpmtx_std {
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/using/cstring" 1
using std::size_t;
# 12 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/using/cstring"
using std::memmove;
using std::memcpy;




using std::strcoll;
using std::strerror;
using std::strxfrm;





using std::memchr;
using std::strchr;
using std::strpbrk;
using std::strrchr;
using std::strstr;




using std::memcmp;
using std::memset;

using std::strcat;


using std::strcmp;





using std::strcpy;



using std::strcspn;
using std::strlen;
using std::strncat;
using std::strncmp;

using std::strncpy;
using std::strspn;

using std::strtok;
# 32 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstring.h" 2
}
# 40 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h" 1
# 42 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/climits" 1
# 30 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/climits"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\climits" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\climits" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/limits.h" 1 3 4
# 30 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/limits.h" 3 4
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\limits.h" 1 3 4
# 31 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/limits.h" 2 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\climits" 2 3 4
# 31 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/climits" 2
# 43 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h" 2







# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_pair.h" 1
# 36 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_pair.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h" 1
# 63 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_manips.h" 1
# 21 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_manips.h"
namespace stlpmtx_std {

struct __true_type {};
struct __false_type {};


namespace priv {
using ::stlpmtx_std::__true_type;
using ::stlpmtx_std::__false_type;
}



template <int _Is>
struct __bool2type
{ typedef __true_type _Ret; };

template<>
struct __bool2type<1> { typedef __true_type _Ret; };

template<>
struct __bool2type<0> { typedef __false_type _Ret; };


template <class __bool_type>
struct __type2bool { enum {_Ret = 1}; };

template<>
struct __type2bool<__true_type> { enum {_Ret = 1}; };

template<>
struct __type2bool<__false_type> { enum {_Ret = 0}; };


template <class _BoolType>
struct _Not { typedef __false_type _Ret; };

template<>
struct _Not<__false_type> { typedef __true_type _Ret; };


template <class _P1, class _P2>
struct _Land2 { typedef __false_type _Ret; };

template<>
struct _Land2<__true_type, __true_type> { typedef __true_type _Ret; };


template <class _P1, class _P2, class _P3>
struct _Land3 { typedef __false_type _Ret; };

template<>
struct _Land3<__true_type, __true_type, __true_type> { typedef __true_type _Ret; };


template <class _P1, class _P2>
struct _Lor2 { typedef __true_type _Ret; };

template<>
struct _Lor2<__false_type, __false_type> { typedef __false_type _Ret; };


template <class _P1, class _P2, class _P3>
struct _Lor3 { typedef __true_type _Ret; };

template<>
struct _Lor3<__false_type, __false_type, __false_type> { typedef __false_type _Ret; };
# 112 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_manips.h"
template <bool _Cond, class _Tp1, class _Tp2>
struct __select { typedef _Tp1 _Ret; };

template <class _Tp1, class _Tp2>
struct __select<false, _Tp1, _Tp2> { typedef _Tp2 _Ret; };
# 164 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_manips.h"
struct _NoVolatilePointerShim { _NoVolatilePointerShim(const void*); };
template <class _Tp>
char _IsCopyableFun(bool, _NoVolatilePointerShim, _Tp const*, _Tp*);
char* _IsCopyableFun(bool, ...);

template <class _Src, class _Dst>
struct _Copyable {
  static _Src* __null_src();
  static _Dst* __null_dst();
  enum { _Ret = (sizeof(_IsCopyableFun(false, __null_src(), __null_src(), __null_dst())) == sizeof(char)) };
  typedef typename __bool2type<_Ret>::_Ret _RetT;
};
# 202 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_manips.h"
template <class _Src, class _Dst>
struct _AreCopyable {
  enum { _Same = _Copyable<_Src, _Dst>::_Ret };
  typedef typename _Copyable<_Src, _Dst>::_RetT _Ret;
};

template <class _Tp1, class _Tp2>
struct _AreSameTypes {
  enum { _Same = 0 };
  typedef __false_type _Ret;
};


template <class _Tp>
struct _AreSameTypes<_Tp, _Tp> {
  enum { _Same = 1 };
  typedef __true_type _Ret;
};



template <class _Src, class _Dst>
struct _ConversionHelper {
  static char _Test(bool, _Dst);
  static char* _Test(bool, ...);
  static _Src _MakeSource();
};

template <class _Src, class _Dst>
struct _IsConvertible {
  typedef _ConversionHelper<_Src*, const volatile _Dst*> _H;
  enum { value = (sizeof(char) == sizeof(_H::_Test(false, _H::_MakeSource()))) };
  typedef typename __bool2type<value>::_Ret _Ret;
};
# 292 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_manips.h"
template <class _Src, class _Dst>
struct _IsCVConvertible {

  typedef _ConversionHelper<_Src, _Dst> _H;
  enum { value = (sizeof(char) == sizeof(_H::_Test(false, _H::_MakeSource()))) };





  typedef typename __bool2type<value>::_Ret _Ret;
};
# 319 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_manips.h"
}
# 64 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h" 2
# 72 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
namespace stlpmtx_std {






template <class _Tp> struct _IsIntegral
{ typedef __false_type _Ret; };


template<> struct _IsIntegral<bool>
{ typedef __true_type _Ret; };


template<> struct _IsIntegral<char>
{ typedef __true_type _Ret; };


template<> struct _IsIntegral<signed char>
{ typedef __true_type _Ret; };


template<> struct _IsIntegral<unsigned char>
{ typedef __true_type _Ret; };


template<> struct _IsIntegral<wchar_t>
{ typedef __true_type _Ret; };


template<> struct _IsIntegral<short>
{ typedef __true_type _Ret; };

template<> struct _IsIntegral<unsigned short>
{ typedef __true_type _Ret; };

template<> struct _IsIntegral<int>
{ typedef __true_type _Ret; };

template<> struct _IsIntegral<unsigned int>
{ typedef __true_type _Ret; };

template<> struct _IsIntegral<long>
{ typedef __true_type _Ret; };

template<> struct _IsIntegral<unsigned long>
{ typedef __true_type _Ret; };


template<> struct _IsIntegral<long long>
{ typedef __true_type _Ret; };

template<> struct _IsIntegral<unsigned long long>
{ typedef __true_type _Ret; };


template <class _Tp> struct _IsRational
{ typedef __false_type _Ret; };

template<> struct _IsRational<float>
{ typedef __true_type _Ret; };

template<> struct _IsRational<double>
{ typedef __true_type _Ret; };







template <class _Tp> struct __type_traits;
template <class _IsPOD> struct __type_traits_aux {
   typedef __false_type has_trivial_default_constructor;
   typedef __false_type has_trivial_copy_constructor;
   typedef __false_type has_trivial_assignment_operator;
   typedef __false_type has_trivial_destructor;
   typedef __false_type is_POD_type;
};

template<>
struct __type_traits_aux<__false_type> {
   typedef __false_type has_trivial_default_constructor;
   typedef __false_type has_trivial_copy_constructor;
   typedef __false_type has_trivial_assignment_operator;
   typedef __false_type has_trivial_destructor;
   typedef __false_type is_POD_type;
};

template<>
struct __type_traits_aux<__true_type> {
  typedef __true_type has_trivial_default_constructor;
  typedef __true_type has_trivial_copy_constructor;
  typedef __true_type has_trivial_assignment_operator;
  typedef __true_type has_trivial_destructor;
  typedef __true_type is_POD_type;
};

template <class _Tp>
struct _IsRef {
  typedef __false_type _Ret;
};
# 219 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
template <class _Tp> struct _IsPtr {
  typedef __false_type _Ret;
};

template <class _Tp>
struct __type_traits {
   typedef __true_type this_dummy_member_must_be_first;
# 243 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
   typedef __false_type has_trivial_default_constructor;
   typedef __false_type has_trivial_copy_constructor;
   typedef __false_type has_trivial_assignment_operator;
   typedef __false_type has_trivial_destructor;
   typedef __false_type is_POD_type;







};


template <class _Tp> struct _IsPtr<_Tp*>
{ typedef __true_type _Ret; };
template <class _Tp> struct _IsRef<_Tp&>
{ typedef __true_type _Ret; };

template <class _Tp> struct __type_traits<_Tp*> : __type_traits_aux<__true_type>
{};
# 284 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
template<> struct __type_traits< bool > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const bool > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile bool > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile bool > : __type_traits_aux<__true_type> {};

template<> struct __type_traits< char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile char > : __type_traits_aux<__true_type> {};

template<> struct __type_traits< signed char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const signed char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile signed char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile signed char > : __type_traits_aux<__true_type> {};

template<> struct __type_traits< unsigned char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const unsigned char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile unsigned char > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile unsigned char > : __type_traits_aux<__true_type> {};

template<> struct __type_traits< wchar_t > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const wchar_t > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile wchar_t > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile wchar_t > : __type_traits_aux<__true_type> {};


template<> struct __type_traits< short > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const short > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile short > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile short > : __type_traits_aux<__true_type> {};
template<> struct __type_traits< unsigned short > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const unsigned short > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile unsigned short > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile unsigned short > : __type_traits_aux<__true_type> {};
template<> struct __type_traits< int > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const int > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile int > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile int > : __type_traits_aux<__true_type> {};
template<> struct __type_traits< unsigned int > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const unsigned int > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile unsigned int > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile unsigned int > : __type_traits_aux<__true_type> {};
template<> struct __type_traits< long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile long > : __type_traits_aux<__true_type> {};
template<> struct __type_traits< unsigned long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const unsigned long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile unsigned long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile unsigned long > : __type_traits_aux<__true_type> {};


template<> struct __type_traits< long long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const long long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile long long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile long long > : __type_traits_aux<__true_type> {};
template<> struct __type_traits< unsigned long long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const unsigned long long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile unsigned long long > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile unsigned long long > : __type_traits_aux<__true_type> {};


template<> struct __type_traits< float > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const float > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile float > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile float > : __type_traits_aux<__true_type> {};
template<> struct __type_traits< double > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const double > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< volatile double > : __type_traits_aux<__true_type> {}; template<> struct __type_traits< const volatile double > : __type_traits_aux<__true_type> {};






template <class _ArePtrs, class _Src, class _Dst>
struct _IsCVConvertibleIf
{ typedef typename _IsCVConvertible<_Src, _Dst>::_Ret _Ret; };

template <class _Src, class _Dst>
struct _IsCVConvertibleIf<__false_type, _Src, _Dst>
{ typedef __false_type _Ret; };
# 352 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
template <class _Src, class _Dst>
struct _TrivialNativeTypeCopy {
  typedef typename _IsPtr<_Src>::_Ret _Ptr1;
  typedef typename _IsPtr<_Dst>::_Ret _Ptr2;
  typedef typename _Land2<_Ptr1, _Ptr2>::_Ret _BothPtrs;
  typedef typename _IsCVConvertibleIf<_BothPtrs, _Src, _Dst>::_Ret _Convertible;
  typedef typename _Land2<_BothPtrs, _Convertible>::_Ret _Trivial1;

  typedef typename __bool2type<(sizeof(_Src) == sizeof(_Dst))>::_Ret _SameSize;


  typedef typename _IsIntegral<_Src>::_Ret _Int1;




  typedef typename _IsIntegral<_Dst>::_Ret _Int2;
  typedef typename _Land2<_Int1, _Int2>::_Ret _BothInts;

  typedef typename _IsRational<_Src>::_Ret _Rat1;
  typedef typename _IsRational<_Dst>::_Ret _Rat2;
  typedef typename _Land2<_Rat1, _Rat2>::_Ret _BothRats;

  typedef typename _Lor2<_BothInts, _BothRats>::_Ret _BothNatives;

  typedef typename _Land2<_BothNatives, _SameSize>::_Ret _Trivial2;




  typedef typename _Lor2<_Trivial1, _Trivial2>::_Ret _Ret;
};

template <class _Src, class _Dst>
struct _TrivialCopy {
  typedef typename _TrivialNativeTypeCopy<_Src, _Dst>::_Ret _NativeRet;

  typedef typename __type_traits<_Src>::has_trivial_assignment_operator _Tr1;




  typedef typename _AreCopyable<_Src, _Dst>::_Ret _Tr2;
  typedef typename _Land2<_Tr1, _Tr2>::_Ret _UserRet;
  typedef typename _Lor2<_NativeRet, _UserRet>::_Ret _Ret;
  static _Ret _Answer() { return _Ret(); }
};

template <class _Src, class _Dst>
struct _TrivialUCopy {
  typedef typename _TrivialNativeTypeCopy<_Src, _Dst>::_Ret _NativeRet;

  typedef typename __type_traits<_Src>::has_trivial_copy_constructor _Tr1;




  typedef typename _AreCopyable<_Src, _Dst>::_Ret _Tr2;
  typedef typename _Land2<_Tr1, _Tr2>::_Ret _UserRet;
  typedef typename _Lor2<_NativeRet, _UserRet>::_Ret _Ret;
  static _Ret _Answer() { return _Ret(); }
};

template <class _Tp>
struct _DefaultZeroValue {
  typedef typename _IsIntegral<_Tp>::_Ret _Tr1;
  typedef typename _IsRational<_Tp>::_Ret _Tr2;
  typedef typename _IsPtr<_Tp>::_Ret _Tr3;
  typedef typename _Lor3<_Tr1, _Tr2, _Tr3>::_Ret _Ret;
};

template <class _Tp>
struct _TrivialInit {

  typedef typename __type_traits<_Tp>::has_trivial_default_constructor _Tr1;




  typedef typename _DefaultZeroValue<_Tp>::_Ret _Tr2;
  typedef typename _Not<_Tr2>::_Ret _Tr3;
  typedef typename _Land2<_Tr1, _Tr3>::_Ret _Ret;
  static _Ret _Answer() { return _Ret(); }
};



template <class _Tp>
struct _IsPtrType {
  typedef typename _IsPtr<_Tp>::_Ret _Type;
  static _Type _Ret() { return _Type(); }
};

template <class _Tp>
struct _IsRefType {
  typedef typename _IsRef<_Tp>::_Ret _Type;
  static _Type _Ret() { return _Type();}
};

template <class _Tp>
struct __call_traits {
# 461 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
  typedef const _Tp& const_param_type;
  typedef _Tp& param_type;

};


template <class _Tp>
struct __call_traits<_Tp&> {
  typedef _Tp& param_type;
  typedef const _Tp& const_param_type;
};
template <class _Tp>
struct __call_traits<const _Tp&> {
  typedef _Tp& param_type;
  typedef const _Tp& const_param_type;
};


template <class _Tp1, class _Tp2>
struct _BothPtrType {
  typedef typename _IsPtr<_Tp1>::_Ret _IsPtr1;
  typedef typename _IsPtr<_Tp2>::_Ret _IsPtr2;

  typedef typename _Land2<_IsPtr1, _IsPtr2>::_Ret _Ret;
  static _Ret _Answer() { return _Ret(); }
};

template <class _Tp1, class _Tp2, class _IsRef1, class _IsRef2>
struct _OKToSwap {
  typedef typename _AreSameTypes<_Tp1, _Tp2>::_Ret _Same;
  typedef typename _Land3<_Same, _IsRef1, _IsRef2>::_Ret _Type;
  static _Type _Answer() { return _Type(); }
};

template <class _Tp1, class _Tp2, class _IsRef1, class _IsRef2>
inline _OKToSwap<_Tp1, _Tp2, _IsRef1, _IsRef2>
_IsOKToSwap(_Tp1*, _Tp2*, const _IsRef1&, const _IsRef2&)
{ return _OKToSwap<_Tp1, _Tp2, _IsRef1, _IsRef2>(); }

template <class _Src, class _Dst>
inline _TrivialCopy<_Src, _Dst> _UseTrivialCopy(_Src*, _Dst*)
{ return _TrivialCopy<_Src, _Dst>(); }

template <class _Src, class _Dst>
inline _TrivialUCopy<_Src, _Dst> _UseTrivialUCopy(_Src*, _Dst*)
{ return _TrivialUCopy<_Src, _Dst>(); }



struct _NegativeAnswer {
  typedef __false_type _Ret;
  static _Ret _Answer() { return _Ret(); }
};

template <class _Src, class _Dst>
inline _NegativeAnswer _UseTrivialCopy(_Src*, const _Dst*)
{ return _NegativeAnswer(); }

template <class _Src, class _Dst>
inline _NegativeAnswer _UseTrivialCopy(_Src*, volatile _Dst*)
{ return _NegativeAnswer(); }

template <class _Src, class _Dst>
inline _NegativeAnswer _UseTrivialCopy(_Src*, const volatile _Dst*)
{ return _NegativeAnswer(); }

template <class _Src, class _Dst>
inline _NegativeAnswer _UseTrivialUCopy(_Src*, const _Dst*)
{ return _NegativeAnswer(); }

template <class _Src, class _Dst>
inline _NegativeAnswer _UseTrivialUCopy(_Src*, volatile _Dst*)
{ return _NegativeAnswer(); }

template <class _Src, class _Dst>
inline _NegativeAnswer _UseTrivialUCopy(_Src*, const volatile _Dst*)
{ return _NegativeAnswer(); }


template <class _Tp>
inline _TrivialInit<_Tp> _UseTrivialInit(_Tp*)
{ return _TrivialInit<_Tp>(); }

template <class _Tp>
struct _IsPOD {
  typedef typename __type_traits<_Tp>::is_POD_type _Type;
  static _Type _Answer() { return _Type(); }
};

template <class _Tp>
inline _IsPOD<_Tp> _Is_POD(_Tp*)
{ return _IsPOD<_Tp>(); }

template <class _Tp>
struct _DefaultZeroValueQuestion {
  typedef typename _DefaultZeroValue<_Tp>::_Ret _Ret;
  static _Ret _Answer() { return _Ret(); }
};

template <class _Tp>
inline _DefaultZeroValueQuestion<_Tp> _HasDefaultZeroValue(_Tp*)
{ return _DefaultZeroValueQuestion<_Tp>(); }







template <class _Tp>
struct __stlport_class
{ typedef _Tp _Type; };

template <class _Tp>
struct _IsSTLportClass {
  typedef typename _IsConvertible<_Tp, __stlport_class<_Tp> >::_Ret _Ret;



};
# 592 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/type_traits.h"
template <class _Tp>
class _TpWithState : private _Tp {
  _TpWithState();
  int _state;
};



template <class _Tp>
struct _IsStateless {
  enum { _Is = sizeof(_TpWithState<_Tp>) == sizeof(int) };
  typedef typename __bool2type<_Is>::_Ret _Ret;
};

}
# 37 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_pair.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_move_construct_fwk.h" 1
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_move_construct_fwk.h"
namespace stlpmtx_std {
# 34 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_move_construct_fwk.h"
template <class _Tp>
class __move_source {
public:
  explicit __move_source (_Tp &_src) : _M_data(_src)
  {}

  _Tp& get() const
  { return _M_data; }
private:
  _Tp &_M_data;


  typedef __move_source<_Tp> _Self;
  _Self& operator = (_Self const&);
};


template <class _Tp>
struct __move_traits {
# 63 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_move_construct_fwk.h"
  typedef __false_type implemented;
# 73 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_move_construct_fwk.h"
  typedef typename __type_traits<_Tp>::has_trivial_destructor complete;

};

namespace priv {







template <class _Tp>
struct _MoveSourceTraits {
  typedef typename __move_traits<_Tp>::implemented _MvImpRet;



  enum {_MvImp = __type2bool<_MvImpRet>::_Ret};
  typedef typename __select<_MvImp,

                            __move_source<_Tp>,
                            _Tp const&>::_Ret _Type;
};


template <class _Tp>
inline typename _MoveSourceTraits<_Tp>::_Type
_AsMoveSource (_Tp &src) {
  typedef typename _MoveSourceTraits<_Tp>::_Type _SrcType;
  return _SrcType(src);
}


template <class _Tp>
struct __move_traits_aux {
  typedef typename __move_traits<_Tp>::implemented implemented;
  typedef typename __move_traits<_Tp>::complete complete;
};

template <class _Tp1, class _Tp2>
struct __move_traits_aux2 {
  typedef __move_traits<_Tp1> _MoveTraits1;
  typedef __move_traits<_Tp2> _MoveTraits2;

  typedef typename _Lor2<typename _MoveTraits1::implemented,
                         typename _MoveTraits2::implemented>::_Ret implemented;
  typedef typename _Land2<typename _MoveTraits1::complete,
                          typename _MoveTraits2::complete>::_Ret complete;
};





template <class _Tp>
struct __move_traits_help {
  typedef __true_type implemented;
  typedef typename __move_traits<_Tp>::complete complete;
};

template <class _Tp1, class _Tp2>
struct __move_traits_help1 {
  typedef __move_traits<_Tp1> _MoveTraits1;
  typedef __move_traits<_Tp2> _MoveTraits2;

  typedef typename _Lor2<typename _MoveTraits1::implemented,
                         typename _MoveTraits2::implemented>::_Ret implemented;
  typedef typename _Land2<typename _MoveTraits1::complete,
                          typename _MoveTraits2::complete>::_Ret complete;
};

template <class _Tp1, class _Tp2>
struct __move_traits_help2 {
  typedef __move_traits<_Tp1> _MoveTraits1;
  typedef __move_traits<_Tp2> _MoveTraits2;

  typedef __true_type implemented;
  typedef typename _Land2<typename _MoveTraits1::complete,
                          typename _MoveTraits2::complete>::_Ret complete;
};

}

}
# 41 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_pair.h" 2



namespace stlpmtx_std {

template <class _T1, class _T2>
struct pair {
  typedef _T1 first_type;
  typedef _T2 second_type;

  _T1 first;
  _T2 second;



  pair() : first(_T1()), second(_T2()) {}

  pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) {}


  template <class _U1, class _U2>
  pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}

  pair(const pair<_T1,_T2>& __o) : first(__o.first), second(__o.second) {}



  pair(__move_source<pair<_T1, _T2> > src) : first(::stlpmtx_std::priv:: _AsMoveSource(src.get().first)),
                                             second(::stlpmtx_std::priv:: _AsMoveSource(src.get().second))
  {}


 
};

template <class _T1, class _T2>
inline bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return __x.first == __y.first && __x.second == __y.second; }

template <class _T1, class _T2>
inline bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return __x.first < __y.first ||
         (!(__y.first < __x.first) && __x.second < __y.second);
}


template <class _T1, class _T2>
inline bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return !(__x == __y); }

template <class _T1, class _T2>
inline bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return __y < __x; }

template <class _T1, class _T2>
inline bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return !(__y < __x); }

template <class _T1, class _T2>
inline bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ return !(__x < __y); }



template <class _T1, class _T2, int _Sz>
inline pair<_T1, _T2 const*> make_pair(_T1 const& __x,
                                       _T2 const (&__y)[_Sz])
{ return pair<_T1, _T2 const*>(__x, static_cast<_T2 const*>(__y)); }

template <class _T1, class _T2, int _Sz>
inline pair<_T1 const*, _T2> make_pair(_T1 const (&__x)[_Sz],
                                       _T2 const& __y)
{ return pair<_T1 const*, _T2>(static_cast<_T1 const*>(__x), __y); }

template <class _T1, class _T2, int _Sz1, int _Sz2>
inline pair<_T1 const*, _T2 const*> make_pair(_T1 const (&__x)[_Sz1],
                                              _T2 const (&__y)[_Sz2]) {
  return pair<_T1 const*, _T2 const*>(static_cast<_T1 const*>(__x),
                                      static_cast<_T2 const*>(__y));
}


template <class _T1, class _T2>
inline pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)
{ return pair<_T1, _T2>(__x, __y); }

}


namespace stlpmtx_std { namespace rel_ops {

template <class _Tp>
inline bool operator!=(const _Tp& __x, const _Tp& __y)
{ return !(__x == __y); }

template <class _Tp>
inline bool operator>(const _Tp& __x, const _Tp& __y)
{ return __y < __x; }

template <class _Tp>
inline bool operator<=(const _Tp& __x, const _Tp& __y)
{ return !(__y < __x); }

template <class _Tp>
inline bool operator>=(const _Tp& __x, const _Tp& __y)
{ return !(__x < __y); }

} }



namespace stlpmtx_std {

template <class _T1, class _T2>
struct __type_traits<pair<_T1, _T2> > {
  typedef __type_traits<_T1> _T1Traits;
  typedef __type_traits<_T2> _T2Traits;
  typedef typename _Land2<typename _T1Traits::has_trivial_default_constructor,
                          typename _T2Traits::has_trivial_default_constructor>::_Ret has_trivial_default_constructor;
  typedef typename _Land2<typename _T1Traits::has_trivial_copy_constructor,
                          typename _T2Traits::has_trivial_copy_constructor>::_Ret has_trivial_copy_constructor;
  typedef typename _Land2<typename _T1Traits::has_trivial_assignment_operator,
                          typename _T2Traits::has_trivial_assignment_operator>::_Ret has_trivial_assignment_operator;
  typedef typename _Land2<typename _T1Traits::has_trivial_destructor,
                          typename _T2Traits::has_trivial_destructor>::_Ret has_trivial_destructor;
  typedef __false_type is_POD_type;
};


template <class _T1, class _T2>
struct __move_traits<pair<_T1, _T2> >
  : ::stlpmtx_std::priv:: __move_traits_help1<_T1, _T2> {};


}
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h" 1
# 49 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
namespace stlpmtx_std {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class _Category, class _Tp, class _Distance = ptrdiff_t,
          class _Pointer = _Tp*, class _Reference = _Tp& >
struct iterator {
  typedef _Category iterator_category;
  typedef _Tp value_type;
  typedef _Distance difference_type;
  typedef _Pointer pointer;
  typedef _Reference reference;
};
template<>
struct iterator<output_iterator_tag, void, void, void, void> {
  typedef output_iterator_tag iterator_category;

  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

};
# 146 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
template <class _Iterator>
struct iterator_traits {
  typedef typename _Iterator::iterator_category iterator_category;

  typedef typename _Iterator::value_type value_type;
  typedef typename _Iterator::difference_type difference_type;
  typedef typename _Iterator::pointer pointer;
  typedef typename _Iterator::reference reference;
};
# 165 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
template <class _Tp>
struct iterator_traits<const _Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef ptrdiff_t difference_type;
  typedef const _Tp* pointer;
  typedef const _Tp& reference;
};

template <class _Tp>
struct iterator_traits<_Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef ptrdiff_t difference_type;
  typedef _Tp* pointer;
  typedef _Tp& reference;
};
# 196 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
}
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_ptrs_specialize.h" 1
# 198 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h" 2
namespace stlpmtx_std {
# 267 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
template <class _Tp, class _Distance> struct input_iterator :
  public iterator <input_iterator_tag, _Tp, _Distance, _Tp*, _Tp&> {};
struct output_iterator : public iterator <output_iterator_tag, void, void, void, void> {};
template <class _Tp, class _Distance> struct forward_iterator :
  public iterator<forward_iterator_tag, _Tp, _Distance, _Tp*, _Tp&> {};
template <class _Tp, class _Distance> struct bidirectional_iterator :
  public iterator<bidirectional_iterator_tag, _Tp, _Distance, _Tp*, _Tp&> {};
template <class _Tp, class _Distance> struct random_access_iterator :
  public iterator<random_access_iterator_tag, _Tp, _Distance, _Tp*, _Tp&> {};
# 311 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
namespace priv {

template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
__distance(const _InputIterator& __first, const _InputIterator& __last,
           const input_iterator_tag &) {
  typename iterator_traits<_InputIterator>::difference_type __n = 0;
  _InputIterator __it(__first);
  while (__it != __last) {
    ++__it; ++__n;
  }
  return __n;
}
# 351 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
template <class _RandomAccessIterator>
inline typename iterator_traits<_RandomAccessIterator>::difference_type
__distance(const _RandomAccessIterator& __first, const _RandomAccessIterator& __last,
           const random_access_iterator_tag &)
{ return __last - __first; }

}

template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
distance(_InputIterator __first, _InputIterator __last)
{ return ::stlpmtx_std::priv:: __distance(__first, __last, typename ::stlpmtx_std::iterator_traits< _InputIterator >::iterator_category()); }


template <class _InputIterator, class _Distance>
inline void distance(const _InputIterator& __first,
                                const _InputIterator& __last, _Distance& __n)
{ __n += ::stlpmtx_std::distance(__first, __last); }
# 380 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
template <class _Tp>
struct _Nonconst_traits;

template <class _Tp>
struct _Const_traits {
  typedef _Tp value_type;
  typedef const _Tp& reference;
  typedef const _Tp* pointer;
  typedef _Const_traits<_Tp> _ConstTraits;
  typedef _Nonconst_traits<_Tp> _NonConstTraits;
};

template <class _Tp>
struct _Nonconst_traits {
  typedef _Tp value_type;
  typedef _Tp& reference;
  typedef _Tp* pointer;
  typedef _Const_traits<_Tp> _ConstTraits;
  typedef _Nonconst_traits<_Tp> _NonConstTraits;
};





template <class _Tp>
struct _Nonconst_Const_traits;

template <class _Tp>
struct _Const_Const_traits {
  typedef _Tp value_type;
  typedef const _Tp& reference;
  typedef const _Tp* pointer;
  typedef _Const_Const_traits<_Tp> _ConstTraits;
  typedef _Nonconst_Const_traits<_Tp> _NonConstTraits;
};

template <class _Tp>
struct _Nonconst_Const_traits {
  typedef _Tp value_type;
  typedef const _Tp& reference;
  typedef const _Tp* pointer;
  typedef _Const_Const_traits<_Tp> _ConstTraits;
  typedef _Nonconst_Const_traits<_Tp> _NonConstTraits;
};
# 476 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
namespace priv {

template <class _InputIter, class _Distance>
inline void
__advance(_InputIter& __i, _Distance __n, const input_iterator_tag &)
{ while (__n--) ++__i; }


template <class _InputIter, class _Distance>
inline void
__advance(_InputIter& __i, _Distance __n, const output_iterator_tag &)
{ while (__n--) ++__i; }
# 496 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator_base.h"
template <class _BidirectionalIterator, class _Distance>
inline void
__advance(_BidirectionalIterator& __i, _Distance __n,
          const bidirectional_iterator_tag &) {
  if (__n > 0)
    while (__n--) ++__i;
  else
    while (__n++) --__i;
}

template <class _RandomAccessIterator, class _Distance>
inline void
__advance(_RandomAccessIterator& __i, _Distance __n,
          const random_access_iterator_tag &)
{ __i += __n; }

}

template <class _InputIterator, class _Distance>
inline void advance(_InputIterator& __i, _Distance __n)
{ ::stlpmtx_std::priv:: __advance(__i, __n, typename ::stlpmtx_std::iterator_traits< _InputIterator >::iterator_category()); }

}
# 55 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h" 2






namespace stlpmtx_std {
# 80 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
template <class _Tp>
inline void swap(_Tp& __a, _Tp& __b) {
# 91 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
  _Tp __tmp = __a;
  __a = __b;
  __b = __tmp;

}

namespace priv {

template <class _ForwardIter1, class _ForwardIter2, class _Value>
inline void __iter_swap_aux_aux(_ForwardIter1& __i1, _ForwardIter2& __i2, _Value *) {
  _Value tmp = *__i1;
  *__i1 = *__i2;
  *__i2 = tmp;
}

template <class _ForwardIter1, class _ForwardIter2>
inline void __iter_swap_aux(_ForwardIter1& __i1, _ForwardIter2& __i2, const __true_type& ) {

                  swap(*__i1, *__i2);
}

template <class _ForwardIter1, class _ForwardIter2>
inline void __iter_swap_aux(_ForwardIter1& __i1, _ForwardIter2& __i2, const __false_type& ) {
  ::stlpmtx_std::priv:: __iter_swap_aux_aux( __i1, __i2, (typename ::stlpmtx_std::iterator_traits< _ForwardIter1 >::value_type*)0 );
}

}

template <class _ForwardIter1, class _ForwardIter2>
inline void iter_swap(_ForwardIter1 __i1, _ForwardIter2 __i2) {
  ::stlpmtx_std::priv:: __iter_swap_aux( __i1, __i2, _IsOKToSwap((typename ::stlpmtx_std::iterator_traits< _ForwardIter1 >::value_type*)0, (typename ::stlpmtx_std::iterator_traits< _ForwardIter2 >::value_type*)0,
                                                      ::stlpmtx_std::_IsRefType< typename ::stlpmtx_std::iterator_traits< _ForwardIter1 >::reference >::_Ret(),
                                                      ::stlpmtx_std::_IsRefType< typename ::stlpmtx_std::iterator_traits< _ForwardIter2 >::reference >::_Ret())._Answer());
}
# 138 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
template <class _Tp>
inline const _Tp& (min)(const _Tp& __a, const _Tp& __b) { return __b < __a ? __b : __a; }
template <class _Tp>
inline const _Tp& (max)(const _Tp& __a, const _Tp& __b) { return __a < __b ? __b : __a; }
# 151 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
template <class _Tp, class _Compare>
inline const _Tp& (min)(const _Tp& __a, const _Tp& __b, _Compare __comp) {
  return __comp(__b, __a) ? __b : __a;
}

template <class _Tp, class _Compare>
inline const _Tp& (max)(const _Tp& __a, const _Tp& __b, _Compare __comp) {
  return __comp(__a, __b) ? __b : __a;
}
# 181 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
namespace priv {

template <class _InputIter, class _OutputIter, class _Distance>
inline _OutputIter __copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result, const input_iterator_tag &, _Distance*) {
  for ( ; __first != __last; ++__result, ++__first)
    *__result = *__first;
  return __result;
}
# 209 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
template <class _RandomAccessIter, class _OutputIter, class _Distance>
inline _OutputIter
__copy(_RandomAccessIter __first, _RandomAccessIter __last,
       _OutputIter __result, const random_access_iterator_tag &, _Distance*) {
  for (_Distance __n = __last - __first; __n > 0; --__n) {
    *__result = *__first;
    ++__first;
    ++__result;
  }
  return __result;
}

inline void*
__copy_trivial(const void* __first, const void* __last, void* __result) {
  size_t __n = (const char*)__last - (const char*)__first;
  return __n ? (void *)((char*)memmove(__result, __first, __n) + __n) : __result;
}




template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _Distance>
inline _BidirectionalIter2 __copy_backward(_BidirectionalIter1 __first,
                                           _BidirectionalIter1 __last,
                                           _BidirectionalIter2 __result,
                                           const bidirectional_iterator_tag &,
                                           _Distance*) {
  while (__first != __last)
    *--__result = *--__last;
  return __result;
}

template <class _RandomAccessIter, class _BidirectionalIter, class _Distance>
inline _BidirectionalIter __copy_backward(_RandomAccessIter __first,
                                          _RandomAccessIter __last,
                                          _BidirectionalIter __result,
                                          const random_access_iterator_tag &,
                                          _Distance*) {
  for (_Distance __n = __last - __first; __n > 0; --__n)
    *--__result = *--__last;
  return __result;
}

inline void*
__copy_trivial_backward(const void* __first, const void* __last, void* __result) {
  const ptrdiff_t _Num = (const char*)__last - (const char*)__first;
  return (_Num > 0) ? memmove((char*)__result - _Num, __first, _Num) : __result ;
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_ptrs(_InputIter __first, _InputIter __last, _OutputIter __result,
                               const __false_type& ) {
  return ::stlpmtx_std::priv:: __copy(__first, __last, __result, random_access_iterator_tag(), (ptrdiff_t*)0);
}
template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_ptrs(_InputIter __first, _InputIter __last, _OutputIter __result,
                               const __true_type& ) {


  return (_OutputIter)::stlpmtx_std::priv:: __copy_trivial(__first, __last, __result);
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_aux(_InputIter __first, _InputIter __last, _OutputIter __result,
                              const __true_type& ) {
  return ::stlpmtx_std::priv:: __copy_ptrs(__first, __last, __result,
                                _UseTrivialCopy((typename ::stlpmtx_std::iterator_traits< _InputIter >::value_type*)0,
                                                (typename ::stlpmtx_std::iterator_traits< _OutputIter >::value_type*)0)._Answer());
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_aux(_InputIter __first, _InputIter __last, _OutputIter __result,
                              const __false_type& ) {
  return ::stlpmtx_std::priv:: __copy(__first, __last, __result,
                           typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category(),
                           (typename ::stlpmtx_std::iterator_traits< _InputIter >::difference_type*)0);
}

}

template <class _InputIter, class _OutputIter>
inline _OutputIter copy(_InputIter __first, _InputIter __last, _OutputIter __result) {
 
  return ::stlpmtx_std::priv:: __copy_aux(__first, __last, __result, _BothPtrType< _InputIter, _OutputIter>::_Answer());
}

namespace priv {

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_backward_ptrs(_InputIter __first, _InputIter __last,
                                        _OutputIter __result, const __false_type& ) {
  return ::stlpmtx_std::priv:: __copy_backward(__first, __last, __result,
                                    typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category(),
                                    (typename ::stlpmtx_std::iterator_traits< _InputIter >::difference_type*)0);
}
template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_backward_ptrs(_InputIter __first, _InputIter __last,
                                        _OutputIter __result, const __true_type& ) {
  return (_OutputIter)::stlpmtx_std::priv:: __copy_trivial_backward(__first, __last, __result);
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_backward_aux(_InputIter __first, _InputIter __last, _OutputIter __result, const __false_type&) {
  return ::stlpmtx_std::priv:: __copy_backward(__first, __last, __result,
                                    typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category(),
                                    (typename ::stlpmtx_std::iterator_traits< _InputIter >::difference_type*)0);
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_backward_aux(_InputIter __first, _InputIter __last, _OutputIter __result, const __true_type&) {
  return ::stlpmtx_std::priv:: __copy_backward_ptrs(__first, __last, __result,
                                         _UseTrivialCopy((typename ::stlpmtx_std::iterator_traits< _InputIter >::value_type*)0,
                                                         (typename ::stlpmtx_std::iterator_traits< _OutputIter >::value_type*)0)._Answer());
}

}

template <class _InputIter, class _OutputIter>
inline _OutputIter copy_backward(_InputIter __first, _InputIter __last, _OutputIter __result) {
 
  return ::stlpmtx_std::priv:: __copy_backward_aux(__first, __last, __result, _BothPtrType< _InputIter, _OutputIter>::_Answer() );
}
# 373 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
namespace priv {

template <class _InputIter, class _Size, class _OutputIter>
inline ::stlpmtx_std::pair<_InputIter, _OutputIter>
__copy_n(_InputIter __first, _Size __count, _OutputIter __result,
         const input_iterator_tag &) {
  for ( ; __count > 0; --__count) {
    *__result = *__first;
    ++__first;
    ++__result;
  }
  return ::stlpmtx_std::pair<_InputIter, _OutputIter>(__first, __result);
}

template <class _RAIter, class _Size, class _OutputIter>
inline ::stlpmtx_std::pair<_RAIter, _OutputIter>
__copy_n(_RAIter __first, _Size __count, _OutputIter __result,
         const random_access_iterator_tag &) {
  _RAIter __last = __first + __count;
  return ::stlpmtx_std::pair<_RAIter, _OutputIter>(__last, ::stlpmtx_std::copy(__first, __last, __result));
}

}

template <class _InputIter, class _Size, class _OutputIter>
inline pair<_InputIter, _OutputIter>
copy_n(_InputIter __first, _Size __count, _OutputIter __result) {
 
  return ::stlpmtx_std::priv:: __copy_n(__first, __count, __result, typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category());
}




namespace priv {

template <class _ForwardIter, class _Tp>
inline
void __fill_fwd(_ForwardIter __first, _ForwardIter __last, const _Tp& __val) {
  for ( ; __first != __last; ++__first)
    *__first = __val;
}

template <class _ForwardIter, class _Tp, class _Distance>
inline void __fill(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
                   const input_iterator_tag &, _Distance*) {
  ::stlpmtx_std::priv:: __fill_fwd(__first, __last, __val);
}
# 438 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h"
template <class _RandomAccessIter, class _Tp, class _Distance>
inline
void __fill(_RandomAccessIter __first, _RandomAccessIter __last, const _Tp& __val,
            const random_access_iterator_tag &, _Distance*) {
  for (_Distance __n = __last - __first ; __n > 0; ++__first, --__n)
    *__first = __val;
}

}

template <class _ForwardIter, class _Tp>
inline void fill(_ForwardIter __first, _ForwardIter __last, const _Tp& __val) {
 
  ::stlpmtx_std::priv:: __fill(__first, __last, __val,
                    typename ::stlpmtx_std::iterator_traits< _ForwardIter >::iterator_category(),
                    (typename ::stlpmtx_std::iterator_traits< _ForwardIter >::difference_type*)0);
}


inline void fill(unsigned char* __first, unsigned char* __last,
                 const unsigned char& __val) {
  unsigned char __tmp = __val;
  memset(__first, __tmp, __last - __first);
}

inline void fill(signed char* __first, signed char* __last,
                 const signed char& __val) {
  signed char __tmp = __val;
  memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

inline void fill(char* __first, char* __last, const char& __val) {
  char __tmp = __val;
  memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

namespace priv {

template <class _OutputIter, class _Size, class _Tp>
inline
_OutputIter __fill_n(_OutputIter __first, _Size __n, const _Tp& __val) {
 
  for ( ; __n > 0; --__n, ++__first)
    *__first = __val;
  return __first;
}


template <class _Size>
inline unsigned char* __fill_n(unsigned char* __first, _Size __n,
                               const unsigned char& __val) {
  ::stlpmtx_std::fill(__first, __first + __n, __val);
  return __first + __n;
}

template <class _Size>
inline signed char* __fill_n(signed char* __first, _Size __n,
                             const signed char& __val) {
  ::stlpmtx_std::fill(__first, __first + __n, __val);
  return __first + __n;
}

template <class _Size>
inline char* __fill_n(char* __first, _Size __n,
                      const char& __val) {
  ::stlpmtx_std::fill(__first, __first + __n, __val);
  return __first + __n;
}


}

template <class _OutputIter, class _Size, class _Tp>
inline void fill_n(_OutputIter __first, _Size __n, const _Tp& __val) {
 
  ::stlpmtx_std::priv:: __fill_n(__first, __n, __val);
}





template <class _InputIter1, class _InputIter2>
inline
::stlpmtx_std::pair<_InputIter1, _InputIter2> mismatch(_InputIter1 __first1,
                                                   _InputIter1 __last1,
                                                   _InputIter2 __first2) {
 
 
  while (__first1 != __last1 && *__first1 == *__first2) {
    ++__first1;
    ++__first2;
  }
  return ::stlpmtx_std::pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
inline
::stlpmtx_std::pair<_InputIter1, _InputIter2> mismatch(_InputIter1 __first1,
                                                   _InputIter1 __last1,
                                                   _InputIter2 __first2,
                                                   _BinaryPredicate __binary_pred) {
 
 
  while (__first1 != __last1 && __binary_pred(*__first1, *__first2)) {
    ++__first1;
    ++__first2;
  }
  return ::stlpmtx_std::pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2>
inline
bool equal(_InputIter1 __first1, _InputIter1 __last1,
           _InputIter2 __first2) {
 
 
  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (!(*__first1 == *__first2))
      return false;
  return true;
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
inline
bool equal(_InputIter1 __first1, _InputIter1 __last1,
           _InputIter2 __first2, _BinaryPredicate __binary_pred) {
 
 
  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (!__binary_pred(*__first1, *__first2))
      return false;
  return true;
}





template <class _InputIter1, class _InputIter2>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2);

template <class _InputIter1, class _InputIter2, class _Compare>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _Compare __comp);

inline bool
lexicographical_compare(const unsigned char* __first1,
                        const unsigned char* __last1,
                        const unsigned char* __first2,
                        const unsigned char* __last2) {
  const size_t __len1 = __last1 - __first1;
  const size_t __len2 = __last2 - __first2;
 
 

  const int __result = memcmp(__first1, __first2, (min) (__len1, __len2));
  return __result != 0 ? (__result < 0) : (__len1 < __len2);
}



inline bool lexicographical_compare(const char* __first1, const char* __last1,
                                    const char* __first2, const char* __last2) {
 
 

  return lexicographical_compare((const unsigned char*) __first1,
                                 (const unsigned char*) __last1,
                                 (const unsigned char*) __first2,
                                 (const unsigned char*) __last2);
}


namespace priv {

template <class _InputIter1, class _InputIter2>
int __lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                   _InputIter2 __first2, _InputIter2 __last2);

inline int
__lexicographical_compare_3way(const unsigned char* __first1,
                               const unsigned char* __last1,
                               const unsigned char* __first2,
                               const unsigned char* __last2) {
  const ptrdiff_t __len1 = __last1 - __first1;
  const ptrdiff_t __len2 = __last2 - __first2;
  const int __result = memcmp(__first1, __first2, (min) (__len1, __len2));
  return __result != 0 ? __result
                       : (__len1 == __len2 ? 0 : (__len1 < __len2 ? -1 : 1));
}



inline int
__lexicographical_compare_3way(const char* __first1, const char* __last1,
                               const char* __first2, const char* __last2) {
  return __lexicographical_compare_3way((const unsigned char*) __first1,
                                        (const unsigned char*) __last1,
                                        (const unsigned char*) __first2,
                                        (const unsigned char*) __last2);
}


}


template <class _InputIter1, class _InputIter2>
int lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                 _InputIter2 __first2, _InputIter2 __last2);




template <class _InputIter, class _Tp>
inline typename iterator_traits<_InputIter>::difference_type
count(_InputIter __first, _InputIter __last, const _Tp& __val) {
 
  typename iterator_traits<_InputIter>::difference_type __n = 0;
  for ( ; __first != __last; ++__first)
    if (*__first == __val)
      ++__n;
  return __n;
}


template <class _InputIter, class _Tp>
_InputIter find(_InputIter __first, _InputIter __last, const _Tp& __val);

template <class _InputIter, class _Predicate>
_InputIter find_if(_InputIter __first, _InputIter __last, _Predicate __pred);


template <class _ForwardIter1, class _ForwardIter2, class _BinaryPred>
_ForwardIter1 search(_ForwardIter1 __first1, _ForwardIter1 __last1,
                     _ForwardIter2 __first2, _ForwardIter2 __last2, _BinaryPred __predicate);

namespace priv {


template <class _InputIter, class _ForwardIter>
_InputIter __find_first_of(_InputIter __first1, _InputIter __last1,
                           _ForwardIter __first2, _ForwardIter __last2);

template <class _InputIter, class _ForwardIter, class _BinaryPredicate>
_InputIter __find_first_of(_InputIter __first1, _InputIter __last1,
                           _ForwardIter __first2, _ForwardIter __last2,
                           _BinaryPredicate __comp);

}

template <class _ForwardIter1, class _ForwardIter2,
          class _BinaryPredicate>
_ForwardIter1
find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
         _ForwardIter2 __first2, _ForwardIter2 __last2,
         _BinaryPredicate __comp);


template <class _ForwardIter, class _Tp>
inline void
replace(_ForwardIter __first, _ForwardIter __last,
        const _Tp& __old_value, const _Tp& __new_value) {
 
  for ( ; __first != __last; ++__first)
    if (*__first == __old_value)
      *__first = __new_value;
}

namespace priv {

template <class _ForwardIter, class _Tp, class _Compare1, class _Compare2, class _Distance>
_ForwardIter __lower_bound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val, _Compare1 __comp1, _Compare2 __comp2, _Distance*);

}

}


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.c" 1
# 33 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.c"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function_base.h" 1
# 37 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function_base.h"
namespace stlpmtx_std {

template <class _Arg, class _Result>
struct unary_function {
  typedef _Arg argument_type;
  typedef _Result result_type;

protected:



  ~unary_function() {}

};

template <class _Arg1, class _Arg2, class _Result>
struct binary_function {
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;

protected:

  ~binary_function() {}

};

template <class _Tp>
struct equal_to : public binary_function<_Tp, _Tp, bool> {
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x == __y; }
};

template <class _Tp>
struct less : public binary_function<_Tp,_Tp,bool>





              , public __stlport_class<less<_Tp> >

{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x < __y; }




};


template <class _Tp>
struct __type_traits<less<_Tp> > {

  typedef typename _IsSTLportClass<less<_Tp> >::_Ret _STLportLess;




  typedef _STLportLess has_trivial_default_constructor;
  typedef _STLportLess has_trivial_copy_constructor;
  typedef _STLportLess has_trivial_assignment_operator;
  typedef _STLportLess has_trivial_destructor;
  typedef _STLportLess is_POD_type;
};


namespace priv {

template <class _Tp>
less<_Tp> __less(_Tp* ) { return less<_Tp>(); }

template <class _Tp>
equal_to<_Tp> __equal_to(_Tp* ) { return equal_to<_Tp>(); }

}

template <class _Tp>
struct plus : public binary_function<_Tp, _Tp, _Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x + __y; }
};

template <class _Tp>
struct minus : public binary_function<_Tp, _Tp, _Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x - __y; }
};

namespace priv {

template <class _Tp>
plus<_Tp> __plus(_Tp* ) { return plus<_Tp>(); }

template <class _Tp>
minus<_Tp> __minus(_Tp* ) { return minus<_Tp>(); }

}

template <class _Tp>
struct multiplies : public binary_function<_Tp, _Tp, _Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x * __y; }
};

namespace priv {

template <class _Pair>
struct _Select1st : public unary_function<_Pair, typename _Pair::first_type> {
  const typename _Pair::first_type& operator()(const _Pair& __x) const {
    return __x.first;
  }
};

template <class _Pair>
struct _Select2nd : public unary_function<_Pair, typename _Pair::second_type> {
  const typename _Pair::second_type& operator()(const _Pair& __x) const {
    return __x.second;
  }
};


template <class _Arg1, class _Arg2>
struct _Project1st : public binary_function<_Arg1, _Arg2, _Arg1> {
  _Arg1 operator()(const _Arg1& __x, const _Arg2&) const { return __x; }
};

template <class _Arg1, class _Arg2>
struct _Project2nd : public binary_function<_Arg1, _Arg2, _Arg2> {
  _Arg2 operator()(const _Arg1&, const _Arg2& __y) const { return __y; }
};
# 177 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function_base.h"
template <class _Tp>
struct _Identity : public unary_function<_Tp,_Tp> {
  const _Tp& operator()(const _Tp& __x) const { return __x; }
};

template <class _Result, class _Argument>
struct _Constant_unary_fun {
  typedef _Argument argument_type;
  typedef _Result result_type;
  result_type _M_val;

  _Constant_unary_fun(const result_type& __v) : _M_val(__v) {}
  const result_type& operator()(const _Argument&) const { return _M_val; }
};

template <class _Result, class _Arg1, class _Arg2>
struct _Constant_binary_fun {
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;
  _Result _M_val;

  _Constant_binary_fun(const _Result& __v) : _M_val(__v) {}
  const result_type& operator()(const _Arg1&, const _Arg2&) const {
    return _M_val;
  }
};


template <class _Tp> inline _Tp __identity_element(plus<_Tp>) { return _Tp(0); }
template <class _Tp> inline _Tp __identity_element(multiplies<_Tp>) { return _Tp(1); }

}

}
# 34 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.c" 2


namespace stlpmtx_std {

template <class _InputIter1, class _InputIter2>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2) {
 
 
  for ( ; __first1 != __last1 && __first2 != __last2
        ; ++__first1, ++__first2) {
    if (*__first1 < *__first2) {
     
      return true;
    }
    if (*__first2 < *__first1)
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}

template <class _InputIter1, class _InputIter2, class _Compare>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _Compare __comp) {
 
 
  for ( ; __first1 != __last1 && __first2 != __last2
        ; ++__first1, ++__first2) {
    if (__comp(*__first1, *__first2)) {
     

      return true;
    }
    if (__comp(*__first2, *__first1))
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}


namespace priv {

template <class _InputIter1, class _InputIter2>
int __lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                   _InputIter2 __first2, _InputIter2 __last2) {
  while (__first1 != __last1 && __first2 != __last2) {
    if (*__first1 < *__first2) {
     
      return -1;
    }
    if (*__first2 < *__first1)
      return 1;
    ++__first1;
    ++__first2;
  }
  if (__first2 == __last2) {
    return !(__first1 == __last1);
  }
  else {
    return -1;
  }
}

}

template <class _InputIter1, class _InputIter2>
int lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                 _InputIter2 __first2, _InputIter2 __last2) {
 
 
  return ::stlpmtx_std::priv:: __lexicographical_compare_3way(__first1, __last1, __first2, __last2);
}


namespace priv {

template <class _RandomAccessIter, class _Tp>
inline _RandomAccessIter __find(_RandomAccessIter __first, _RandomAccessIter __last,
                                           const _Tp& __val,
                                           const random_access_iterator_tag &) {
  typename iterator_traits<_RandomAccessIter>::difference_type __trip_count = (__last - __first) >> 2;

  for ( ; __trip_count > 0 ; --__trip_count) {
    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;
  }

  switch (__last - __first) {
  case 3:
    if (*__first == __val) return __first;
    ++__first;
  case 2:
    if (*__first == __val) return __first;
    ++__first;
  case 1:
    if (*__first == __val) return __first;

  case 0:
  default:
    return __last;
  }
}

inline char*
__find(char* __first, char* __last, char __val, const random_access_iterator_tag &) {
  void *res = memchr(__first, __val, __last - __first);
  return res != 0 ? static_cast<char*>(res) : __last;
}
inline const char*
__find(const char* __first, const char* __last, char __val, const random_access_iterator_tag &) {
  const void *res = memchr(__first, __val, __last - __first);
  return res != 0 ? static_cast<const char*>(res) : __last;
}

template <class _RandomAccessIter, class _Predicate>
inline _RandomAccessIter __find_if(_RandomAccessIter __first, _RandomAccessIter __last,
                                              _Predicate __pred,
                                              const random_access_iterator_tag &) {
  typename iterator_traits<_RandomAccessIter>::difference_type __trip_count = (__last - __first) >> 2;

  for ( ; __trip_count > 0 ; --__trip_count) {
    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;
  }

  switch(__last - __first) {
  case 3:
    if (__pred(*__first)) return __first;
    ++__first;
  case 2:
    if (__pred(*__first)) return __first;
    ++__first;
  case 1:
    if (__pred(*__first)) return __first;

  case 0:
  default:
    return __last;
  }
}

template <class _InputIter, class _Tp>
inline _InputIter __find(_InputIter __first, _InputIter __last,
                                    const _Tp& __val,
                                    const input_iterator_tag &) {
  while (__first != __last && !(*__first == __val)) ++__first;
  return __first;
}

template <class _InputIter, class _Predicate>
inline _InputIter __find_if(_InputIter __first, _InputIter __last,
                                       _Predicate __pred,
                                       const input_iterator_tag &) {
  while (__first != __last && !__pred(*__first))
    ++__first;
  return __first;
}

}

template <class _InputIter, class _Predicate>
_InputIter find_if(_InputIter __first, _InputIter __last,
                   _Predicate __pred) {
 
  return ::stlpmtx_std::priv:: __find_if(__first, __last, __pred, typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category());
}

template <class _InputIter, class _Tp>
_InputIter find(_InputIter __first, _InputIter __last, const _Tp& __val) {
 
  return ::stlpmtx_std::priv:: __find(__first, __last, __val, typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category());
}

template <class _ForwardIter1, class _ForwardIter2, class _BinaryPred>
_ForwardIter1 search(_ForwardIter1 __first1, _ForwardIter1 __last1,
                     _ForwardIter2 __first2, _ForwardIter2 __last2,
                     _BinaryPred __pred) {
 
 

  if (__first1 == __last1 || __first2 == __last2)
    return __first1;


  _ForwardIter2 __p1(__first2);

  if ( ++__p1 == __last2 ) {
    while (__first1 != __last1 && !__pred(*__first1, *__first2)) {
      ++__first1;
    }
    return __first1;
  }



  for ( ; ; ) {
    while (__first1 != __last1 && !__pred(*__first1, *__first2)) {
      ++__first1;
    }
    if (__first1 == __last1) {
      return __last1;
    }
    _ForwardIter2 __p = __p1;
    _ForwardIter1 __current = __first1;
    if (++__current == __last1) return __last1;

    while (__pred(*__current, *__p)) {
      if (++__p == __last2)
        return __first1;
      if (++__current == __last1)
        return __last1;
    }
    ++__first1;
  }
  return __first1;
}

namespace priv {
template <class _Tp>
struct _IsCharLikeType
{ typedef __false_type _Ret; };

template<> struct _IsCharLikeType<char>
{ typedef __true_type _Ret; };

template<> struct _IsCharLikeType<unsigned char>
{ typedef __true_type _Ret; };


template<> struct _IsCharLikeType<signed char>
{ typedef __true_type _Ret; };


template <class _Tp1, class _Tp2>
inline bool __stlp_eq(_Tp1 __val1, _Tp2 __val2)
{ return __val1 == __val2; }


template <class _Tp>
inline bool __stlp_eq(_Tp, _Tp)
{ return true; }


template <class _InputIter, class _ForwardIter, class _Tp2, class _Predicate>
inline _InputIter __find_first_of_aux2(_InputIter __first1, _InputIter __last1,
                                       _ForwardIter __first2, _ForwardIter __last2,
                                       _Tp2*, _Predicate __pred,
                                       const __true_type& ) {
  unsigned char __hints[(255 + 1) / 8];
  memset(__hints, 0, sizeof(__hints) / sizeof(unsigned char));
  for (; __first2 != __last2; ++__first2) {
    unsigned char __tmp = (unsigned char)*__first2;
    __hints[__tmp / 8] |= (1 << (__tmp % 8));
  }

  for (; __first1 != __last1; ++__first1) {
    _Tp2 __tmp = (_Tp2)*__first1;
    if (__stlp_eq(*__first1, __tmp) &&
        __pred((__hints[(unsigned char)__tmp / 8] & (1 << ((unsigned char)__tmp % 8))) != 0))
      break;
  }
  return __first1;
}

template <class _InputIter, class _ForwardIter, class _Tp2, class _Predicate>
inline _InputIter __find_first_of_aux2(_InputIter __first1, _InputIter __last1,
                                       _ForwardIter __first2, _ForwardIter __last2,
                                       _Tp2* , _Predicate ,
                                       const __false_type& ) {
  return ::stlpmtx_std::priv:: __find_first_of(__first1, __last1, __first2, __last2,
                                    ::stlpmtx_std::priv:: __equal_to((typename ::stlpmtx_std::iterator_traits< _InputIter >::value_type*)0));
}

template <class _InputIter, class _ForwardIter, class _Tp1, class _Tp2>
inline _InputIter __find_first_of_aux1(_InputIter __first1, _InputIter __last1,
                                       _ForwardIter __first2, _ForwardIter __last2,
                                       _Tp1* __pt1, _Tp2* __pt2) {
  typedef typename ::stlpmtx_std::_IsIntegral<_Tp1>::_Ret _IsIntegral;
  typedef typename ::stlpmtx_std::priv:: _IsCharLikeType<_Tp2>::_Ret _IsCharLike;
  typedef typename ::stlpmtx_std::_Land2<_IsIntegral, _IsCharLike>::_Ret _UseStrcspnLikeAlgo;
  return ::stlpmtx_std::priv:: __find_first_of_aux2(__first1, __last1,
                                         __first2, __last2,
                                         __pt2, _Identity<bool>(), _UseStrcspnLikeAlgo());
}

template <class _InputIter, class _ForwardIter>
inline _InputIter __find_first_of(_InputIter __first1, _InputIter __last1,
                                  _ForwardIter __first2, _ForwardIter __last2) {
  return ::stlpmtx_std::priv:: __find_first_of_aux1(__first1, __last1, __first2, __last2,
                                         (typename ::stlpmtx_std::iterator_traits< _InputIter >::value_type*)0,
                                         (typename ::stlpmtx_std::iterator_traits< _ForwardIter >::value_type*)0);
}


template <class _InputIter, class _ForwardIter, class _BinaryPredicate>
_InputIter __find_first_of(_InputIter __first1, _InputIter __last1,
                           _ForwardIter __first2, _ForwardIter __last2,
                           _BinaryPredicate __comp) {
  for ( ; __first1 != __last1; ++__first1) {
    for (_ForwardIter __iter = __first2; __iter != __last2; ++__iter) {
      if (__comp(*__first1, *__iter)) {
        return __first1;
      }
    }
  }
  return __last1;
}







template <class _ForwardIter1, class _ForwardIter2,
  class _BinaryPredicate>
_ForwardIter1 __find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
                         _ForwardIter2 __first2, _ForwardIter2 __last2,
                         const forward_iterator_tag &, const forward_iterator_tag &,
                         _BinaryPredicate __comp) {
  if (__first2 == __last2)
    return __last1;
  else {
    _ForwardIter1 __result = __last1;
    for (;;) {
      _ForwardIter1 __new_result = ::stlpmtx_std::search(__first1, __last1, __first2, __last2, __comp);
      if (__new_result == __last1)
        return __result;
      else {
        __result = __new_result;
        __first1 = __new_result;
        ++__first1;
      }
    }
  }
}

}





}
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator.h" 1
# 37 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator.h"
namespace stlpmtx_std {
# 46 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iterator.h"
template <class _Iterator>
class reverse_iterator :
  public iterator<typename iterator_traits<_Iterator>::iterator_category,
                  typename iterator_traits<_Iterator>::value_type,
                  typename iterator_traits<_Iterator>::difference_type,
                  typename iterator_traits<_Iterator>::pointer,
                  typename iterator_traits<_Iterator>::reference> {
protected:
  _Iterator current;
  typedef reverse_iterator<_Iterator> _Self;
public:
  typedef typename iterator_traits<_Iterator>::difference_type difference_type;

  typedef typename iterator_traits<_Iterator>::pointer pointer;
  typedef typename iterator_traits<_Iterator>::reference reference;
  typedef _Iterator iterator_type;
public:
  reverse_iterator() {}
  explicit reverse_iterator(iterator_type __x) : current(__x) {}
  reverse_iterator(const _Self& __x) : current(__x.current) {}
  _Self& operator = (const _Self& __x) { current = __x.base(); return *this; }

  template <class _Iter>
  reverse_iterator(const reverse_iterator<_Iter>& __x) : current(__x.base()) {}
  template <class _Iter>
  _Self& operator = (const reverse_iterator<_Iter>& __x) { current = __x.base(); return *this; }


  iterator_type base() const { return current; }
  reference operator*() const {
    _Iterator __tmp = current;
    return *--__tmp;
  }
  pointer operator->() const { return &(operator*()); }
  _Self& operator++() {
    --current;
    return *this;
  }
  _Self operator++(int) {
    _Self __tmp = *this;
    --current;
    return __tmp;
  }
  _Self& operator--() {
    ++current;
    return *this;
  }
  _Self operator--(int) {
    _Self __tmp = *this;
    ++current;
    return __tmp;
  }

  _Self operator+(difference_type __n) const { return _Self(current - __n); }
  _Self& operator+=(difference_type __n) {
    current -= __n;
    return *this;
  }
  _Self operator-(difference_type __n) const { return _Self(current + __n); }
  _Self& operator-=(difference_type __n) {
    current += __n;
    return *this;
  }
  reference operator[](difference_type __n) const { return *(*this + __n); }
};

template <class _Iterator>
inline bool operator==(const reverse_iterator<_Iterator>& __x,
                                   const reverse_iterator<_Iterator>& __y)
{ return __x.base() == __y.base(); }

template <class _Iterator>
inline bool operator<(const reverse_iterator<_Iterator>& __x,
                                 const reverse_iterator<_Iterator>& __y)
{ return __y.base() < __x.base(); }


template <class _Iterator>
inline bool operator!=(const reverse_iterator<_Iterator>& __x,
                                  const reverse_iterator<_Iterator>& __y)
{ return !(__x == __y); }

template <class _Iterator>
inline bool operator>(const reverse_iterator<_Iterator>& __x,
                                 const reverse_iterator<_Iterator>& __y)
{ return __y < __x; }

template <class _Iterator>
inline bool operator<=(const reverse_iterator<_Iterator>& __x,
                                  const reverse_iterator<_Iterator>& __y)
{ return !(__y < __x); }

template <class _Iterator>
inline bool operator>=(const reverse_iterator<_Iterator>& __x,
                                  const reverse_iterator<_Iterator>& __y)
{ return !(__x < __y); }


template <class _Iterator>



inline typename reverse_iterator<_Iterator>::difference_type

operator-(const reverse_iterator<_Iterator>& __x,
          const reverse_iterator<_Iterator>& __y)
{ return __y.base() - __x.base(); }

template <class _Iterator, class _DifferenceType>
inline reverse_iterator<_Iterator>
operator+(_DifferenceType n,const reverse_iterator<_Iterator>& x)
{ return x.operator+(n); }


template <class _Container>
class back_insert_iterator
  : public iterator<output_iterator_tag, void, void, void, void> {
  typedef back_insert_iterator<_Container> _Self;
protected:

  _Container *container;
public:
  typedef _Container container_type;
  typedef output_iterator_tag iterator_category;

  explicit back_insert_iterator(_Container& __x) : container(&__x) {}

  _Self& operator=(const _Self& __other) {
    container = __other.container;
    return *this;
  }
  _Self& operator=(const typename _Container::value_type& __val) {
    container->push_back(__val);
    return *this;
  }
  _Self& operator*() { return *this; }
  _Self& operator++() { return *this; }
  _Self operator++(int) { return *this; }
};

template <class _Container>
inline back_insert_iterator<_Container> back_inserter(_Container& __x)
{ return back_insert_iterator<_Container>(__x); }

template <class _Container>
class front_insert_iterator
  : public iterator<output_iterator_tag, void, void, void, void> {
  typedef front_insert_iterator<_Container> _Self;
protected:

  _Container *container;
public:
  typedef _Container container_type;
  typedef output_iterator_tag iterator_category;
  explicit front_insert_iterator(_Container& __x) : container(&__x) {}

  _Self& operator=(const _Self& __other) {
    container = __other.container;
    return *this;
  }
  _Self& operator=(const typename _Container::value_type& __val) {
    container->push_front(__val);
    return *this;
  }
  _Self& operator*() { return *this; }
  _Self& operator++() { return *this; }
  _Self operator++(int) { return *this; }
};

template <class _Container>
inline front_insert_iterator<_Container> front_inserter(_Container& __x)
{ return front_insert_iterator<_Container>(__x); }

template <class _Container>
class insert_iterator
  : public iterator<output_iterator_tag, void, void, void, void> {
  typedef insert_iterator<_Container> _Self;
protected:

  _Container *container;
  typename _Container::iterator _M_iter;
public:
  typedef _Container container_type;
  typedef output_iterator_tag iterator_category;
  insert_iterator(_Container& __x, typename _Container::iterator __i)
    : container(&__x), _M_iter(__i) {}

  _Self& operator=(_Self const& __other) {
    container = __other.container;
    _M_iter = __other._M_iter;
    return *this;
  }
  _Self& operator=(const typename _Container::value_type& __val) {
    _M_iter = container->insert(_M_iter, __val);
    ++_M_iter;
    return *this;
  }
  _Self& operator*() { return *this; }
  _Self& operator++() { return *this; }
  _Self& operator++(int) { return *this; }
};

template <class _Container, class _Iterator>
inline insert_iterator<_Container>
inserter(_Container& __x, _Iterator __i) {
  typedef typename _Container::iterator __iter;
  return insert_iterator<_Container>(__x, __iter(__i));
}

}
# 398 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.c" 2
namespace stlpmtx_std {


namespace priv {

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BinaryPredicate>
_BidirectionalIter1
__find_end(_BidirectionalIter1 __first1, _BidirectionalIter1 __last1,
           _BidirectionalIter2 __first2, _BidirectionalIter2 __last2,
           const bidirectional_iterator_tag &, const bidirectional_iterator_tag &,
           _BinaryPredicate __comp) {
  typedef ::stlpmtx_std::reverse_iterator<_BidirectionalIter1> _RevIter1;
  typedef ::stlpmtx_std::reverse_iterator<_BidirectionalIter2> _RevIter2;

  _RevIter1 __rlast1(__first1);
  _RevIter2 __rlast2(__first2);
  _RevIter1 __rresult = ::stlpmtx_std::search(_RevIter1(__last1), __rlast1,
                                          _RevIter2(__last2), __rlast2,
                                          __comp);

  if (__rresult == __rlast1)
    return __last1;
  else {
    _BidirectionalIter1 __result = __rresult.base();
    ::stlpmtx_std::advance(__result, -::stlpmtx_std::distance(__first2, __last2));
    return __result;
  }
}

}


template <class _ForwardIter1, class _ForwardIter2,
          class _BinaryPredicate>
_ForwardIter1
find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
         _ForwardIter2 __first2, _ForwardIter2 __last2,
         _BinaryPredicate __comp) {
 
 
  return ::stlpmtx_std::priv:: __find_end(__first1, __last1, __first2, __last2,

                               typename ::stlpmtx_std::iterator_traits< _ForwardIter1 >::iterator_category(),
                               typename ::stlpmtx_std::iterator_traits< _ForwardIter2 >::iterator_category(),




                               __comp);
}

namespace priv {

template <class _ForwardIter, class _Tp, class _Compare1, class _Compare2, class _Distance>
_ForwardIter __lower_bound(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
                           _Compare1 __comp1, _Compare2 __comp2, _Distance*) {
  _Distance __len = ::stlpmtx_std::distance(__first, __last);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    ::stlpmtx_std::advance(__middle, __half);
    if (__comp1(*__middle, __val)) {
     
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else
      __len = __half;
  }
  return __first;
}

}

}
# 721 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_algobase.h" 2
# 44 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_new.h" 1
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_new.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\new" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\new" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/cstdlib" 1 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\new" 2 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 1 3 4
# 49 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 3 4
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\exception" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\exception" 3 4
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
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 2 3 4
# 16 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\new" 2 3 4

namespace std
{

typedef void (*new_handler)();
new_handler set_new_handler(new_handler) throw();

struct nothrow_t { };
extern const nothrow_t nothrow;

class bad_alloc : public exception
{
public:
  bad_alloc() throw() { }
  virtual ~bad_alloc() throw();
  const char* what() const throw();
};

}
# 51 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\new" 3 4
inline void* operator new(std::size_t, void* __p) throw() { return __p; }
inline void* operator new[](std::size_t, void* __p) throw() { return __p; }
inline void operator delete(void* ptr, void* voidptr2) throw() { }
inline void operator delete[](void*, void*) throw() { }
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_new.h" 2
# 90 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_new.h"
namespace stlpmtx_std {


using std::bad_alloc;



using std::nothrow_t;
using std::nothrow;




using std::new_handler;
using std::set_new_handler;



}
# 128 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_new.h"
namespace stlpmtx_std {





inline void* __stl_new(size_t __n) { return ::operator new(__n); }
inline void __stl_delete(void* __p) { ::operator delete(__p); }

}
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_construct.h" 1
# 53 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_construct.h"
namespace stlpmtx_std {

template <class _Tp>
inline void __destroy_aux(_Tp* __pointer, const __false_type& )
{ __pointer->~_Tp(); }

template <class _Tp>
inline void __destroy_aux(_Tp*, const __true_type& ) {}

template <class _Tp>
inline void _Destroy(_Tp* __pointer) {
  typedef typename __type_traits<_Tp>::has_trivial_destructor _Trivial_destructor;
  __destroy_aux(__pointer, _Trivial_destructor());



}

template <class _Tp>
inline void _Destroy_Moved(_Tp* __pointer) {

  typedef typename __move_traits<_Tp>::complete _Trivial_destructor;
  __destroy_aux(__pointer, _Trivial_destructor());






}






template <class _T1>
inline void _Construct_aux (_T1* __p, const __false_type&) {
  new(__p) _T1();
}

template <class _T1>
inline void _Construct_aux (_T1* __p, const __true_type&) {





  *__p = _T1();

}

template <class _T1>
inline void _Construct(_T1* __p) {






  _Construct_aux (__p, _Is_POD(__p)._Answer());

}

template <class _Tp>
inline void _Copy_Construct_aux(_Tp* __p, const _Tp& __val, const __false_type&) {
  new(__p) _Tp(__val);
}

template <class _Tp>
inline void _Copy_Construct_aux(_Tp* __p, const _Tp& __val, const __true_type&) {


  *__p = __val;
}

template <class _Tp>
inline void _Copy_Construct(_Tp* __p, const _Tp& __val) {



  _Copy_Construct_aux(__p, __val, _Is_POD(__p)._Answer());
}

template <class _T1, class _T2>
inline void _Param_Construct_aux(_T1* __p, const _T2& __val, const __false_type&) {
  new(__p) _T1(__val);
}

template <class _T1, class _T2>
inline void _Param_Construct_aux(_T1* __p, const _T2& __val, const __true_type&) {


  *__p = _T1(__val);
}

template <class _T1, class _T2>
inline void _Param_Construct(_T1* __p, const _T2& __val) {



  _Param_Construct_aux(__p, __val, _Is_POD(__p)._Answer());
}

template <class _T1, class _T2>
inline void _Move_Construct_Aux(_T1* __p, _T2& __val, const __false_type& ) {

  new(__p) _T1(::stlpmtx_std::priv:: _AsMoveSource(__val));



}

template <class _T1, class _T2>
inline void _Move_Construct_Aux(_T1* __p, _T2& __val, const __true_type& ) {


  *__p = _T1(__val);
}

template <class _T1, class _T2>
inline void _Move_Construct(_T1* __p, _T2& __val) {



  _Move_Construct_Aux(__p, __val, _Is_POD(__p)._Answer());
}
# 188 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_construct.h"
template <class _ForwardIterator, class _Tp>
inline void
__destroy_range_aux(_ForwardIterator __first, _ForwardIterator __last, _Tp*, const __false_type& ) {
  for ( ; __first != __last; ++__first) {
    __destroy_aux(&(*__first), __false_type());



  }
}

template <class _ForwardIterator, class _Tp>







inline void
__destroy_range_aux(_ForwardIterator, _ForwardIterator, _Tp*, const __true_type& ) {}


template <class _ForwardIterator, class _Tp>
inline void
__destroy_range(_ForwardIterator __first, _ForwardIterator __last, _Tp *__ptr) {
  typedef typename __type_traits<_Tp>::has_trivial_destructor _Trivial_destructor;
  __destroy_range_aux(__first, __last, __ptr, _Trivial_destructor());
}

template <class _ForwardIterator>
inline void _Destroy_Range(_ForwardIterator __first, _ForwardIterator __last) {
  __destroy_range(__first, __last, (typename ::stlpmtx_std::iterator_traits< _ForwardIterator >::value_type*)0);
}

inline void _Destroy_Range(char*, char*) {}

inline void _Destroy_Range(wchar_t*, wchar_t*) {}
inline void _Destroy_Range(const wchar_t*, const wchar_t*) {}



template <class _ForwardIterator, class _Tp>
inline void
__destroy_mv_srcs(_ForwardIterator __first, _ForwardIterator __last, _Tp *__ptr) {
  typedef typename __move_traits<_Tp>::complete _CompleteMove;
  __destroy_range_aux(__first, __last, __ptr, _CompleteMove());
}


template <class _ForwardIterator>
inline void _Destroy_Moved_Range(_ForwardIterator __first, _ForwardIterator __last)

{ __destroy_mv_srcs(__first, __last, (typename ::stlpmtx_std::iterator_traits< _ForwardIterator >::value_type*)0); }
# 273 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_construct.h"
template <class _T1, class _T2>
inline void construct(_T1* __p, const _T2& __val) {_Param_Construct(__p, __val); }
template <class _T1>
inline void construct(_T1* __p) { ::stlpmtx_std::_Construct(__p); }
template <class _Tp>
inline void destroy(_Tp* __pointer) { ::stlpmtx_std::_Destroy(__pointer); }
template <class _ForwardIterator>
inline void destroy(_ForwardIterator __first, _ForwardIterator __last) { ::stlpmtx_std::_Destroy_Range(__first, __last); }


}
# 52 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 2


namespace stlpmtx_std {
# 63 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
class __malloc_alloc {
public:

  typedef char value_type;
  static void* allocate(size_t __n)



  {
    void *__result = malloc(__n);
    if (__result == 0) {
      throw ::stlpmtx_std::bad_alloc();
    }
    return __result;
  }


  static void deallocate(void* __p, size_t ) { free((char*)__p); }



};



class __new_alloc {
public:

  typedef char value_type;
  static void* allocate(size_t __n) { return __stl_new(__n); }
  static void deallocate(void* __p, size_t) { __stl_delete(__p); }
};
# 103 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
template <class _Alloc>
class __debug_alloc : public _Alloc {
public:
  typedef _Alloc __allocator_type;
  typedef typename _Alloc::value_type value_type;
private:
  struct __alloc_header {
    size_t __magic: 16;
    size_t __type_size:16;
    unsigned long _M_size;
  };

  enum { __pad = 8, __magic = 0xdeba, __deleted_magic = 0xdebd,
         __shred_byte = 0xA3 };

  enum { __extra_before = 16, __extra_after = 8 };



  static size_t __extra_before_chunk() {
    return (long)__extra_before / sizeof(value_type) +
      (size_t)((long)__extra_before % sizeof(value_type) > 0);
  }
  static size_t __extra_after_chunk() {
    return (long)__extra_after / sizeof(value_type) +
      (size_t)((long)__extra_after % sizeof(value_type) > 0);
  }
public:
  __debug_alloc() {}
  ~__debug_alloc() {}
  static void* allocate(size_t);
  static void deallocate(void *, size_t);
};





enum { _MAX_BYTES = 32 * sizeof(void*) };
# 196 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
template <class _Tp, class _Allocator>
struct _Alloc_traits {
  typedef _Allocator _Orig;

  typedef typename _Allocator::template rebind<_Tp> _Rebind_type;
  typedef typename _Rebind_type::other allocator_type;
  static allocator_type create_allocator(const _Orig& __a)
  { return allocator_type(__a); }





};
# 220 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
typedef __new_alloc __alloc_type;
# 230 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
typedef __alloc_type __sgi_alloc;



typedef __sgi_alloc __single_client_alloc;
typedef __sgi_alloc __multithreaded_alloc;
# 269 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
template <class _Tp>
class allocator



                : public __stlport_class<allocator<_Tp> >
{
public:
  typedef _Tp value_type;
  typedef _Tp* pointer;
  typedef const _Tp* const_pointer;
  typedef _Tp& reference;
  typedef const _Tp& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };

  allocator() throw() {}

  template <class _Tp1> allocator(const allocator<_Tp1>&) throw() {}

  allocator(const allocator<_Tp>&) throw() {}

  allocator(__move_source<allocator<_Tp> > src) throw() {}

  ~allocator() throw() {}
  pointer address(reference __x) const {return &__x;}
  const_pointer address(const_reference __x) const { return &__x; }

  _Tp* allocate(size_type __n, const void* = 0) {
    if (__n > max_size()) {
      throw ::stlpmtx_std::bad_alloc();
    }
    if (__n != 0) {
      size_type __buf_size = __n * sizeof(value_type);
      _Tp* __ret = reinterpret_cast<_Tp*>(__sgi_alloc::allocate(__buf_size));



      return __ret;
    }

    return 0;
  }

  void deallocate(pointer __p, size_type __n) {
   
    if (__p != 0) {



      __sgi_alloc::deallocate((void*)__p, __n * sizeof(value_type));
    }
  }


  void deallocate(pointer __p) const { if (__p != 0) __sgi_alloc::deallocate((void*)__p, sizeof(value_type)); }

  size_type max_size() const throw() { return size_t(-1) / sizeof(value_type); }
  void construct(pointer __p, const_reference __val) { ::stlpmtx_std::_Copy_Construct(__p, __val); }
  void destroy(pointer __p) { ::stlpmtx_std::_Destroy(__p); }
# 341 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
  _Tp* _M_allocate(size_type __n, size_type& __allocated_n) {
    if (__n > max_size()) {
      throw ::stlpmtx_std::bad_alloc();
    }

    if (__n != 0) {
      size_type __buf_size = __n * sizeof(value_type);
      _Tp* __ret = reinterpret_cast<_Tp*>(__sgi_alloc::allocate(__buf_size));



      __allocated_n = __buf_size / sizeof(value_type);
      return __ret;
    }

    return 0;
  }



};

template<>
class allocator<void> {
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef void* pointer;
  typedef const void* const_pointer;

  typedef void value_type;


  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };

};

template <class _T1, class _T2>
inline bool operator==(const allocator<_T1>&, const allocator<_T2>&) throw()
{ return true; }
template <class _T1, class _T2>
inline bool operator!=(const allocator<_T1>&, const allocator<_T2>&) throw()
{ return false; }
# 397 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
namespace priv {

template <class _Tp>
struct __alloc_type_traits {

  typedef typename _IsSTLportClass<allocator<_Tp> >::_Ret _STLportAlloc;






  typedef _STLportAlloc has_trivial_default_constructor;
  typedef _STLportAlloc has_trivial_copy_constructor;
  typedef _STLportAlloc has_trivial_assignment_operator;
  typedef _STLportAlloc has_trivial_destructor;
  typedef _STLportAlloc is_POD_type;
};

}


template <class _Tp>
struct __type_traits<allocator<_Tp> > : ::stlpmtx_std::priv:: __alloc_type_traits<_Tp> {};
# 451 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
template <class _Tp, class _Alloc>
inline typename _Alloc_traits<_Tp, _Alloc>::allocator_type
__stl_alloc_create(const _Alloc& __a, const _Tp*) {
  typedef typename _Alloc::template rebind<_Tp>::other _Rebound_type;
  return _Rebound_type(__a);
}
# 468 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
namespace priv {


template <class _Value, class _Tp, class _MaybeReboundAlloc>
class _STLP_alloc_proxy : public _MaybeReboundAlloc {
private:
  typedef _MaybeReboundAlloc _Base;
  typedef typename _Base::size_type size_type;
  typedef _STLP_alloc_proxy<_Value, _Tp, _MaybeReboundAlloc> _Self;
public:
  _Value _M_data;

  _STLP_alloc_proxy (const _MaybeReboundAlloc& __a, _Value __p) :
    _MaybeReboundAlloc(__a), _M_data(__p) {}


  _STLP_alloc_proxy (__move_source<_Self> src) :
    _Base(::stlpmtx_std::priv:: _AsMoveSource(src.get()._M_base())),
    _M_data(::stlpmtx_std::priv:: _AsMoveSource(src.get()._M_data)) {}

  _Base& _M_base()
  { return *this; }


private:




  void _M_swap_alloc(_Self&, const __true_type& )
  {}

  void _M_swap_alloc(_Self& __x, const __false_type& ) {
    _MaybeReboundAlloc &__base_this = *this;
    _MaybeReboundAlloc &__base_x = __x;
    ::stlpmtx_std::swap(__base_this, __base_x);
  }

public:
  void _M_swap_alloc(_Self& __x) {

    typedef typename _IsStateless<_MaybeReboundAlloc>::_Ret _StatelessAlloc;



    _M_swap_alloc(__x, _StatelessAlloc());
  }





  void swap(_Self& __x) {
    _M_swap_alloc(__x);
    ::stlpmtx_std::swap(_M_data, __x._M_data);
  }

  _Tp* allocate(size_type __n, size_type& __allocated_n) {

    typedef typename _IsSTLportClass<_MaybeReboundAlloc>::_Ret _STLportAlloc;



    return allocate(__n, __allocated_n, _STLportAlloc());
  }
# 547 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
  _Tp* allocate(size_type __n)
  { return _Base::allocate(__n); }
private:
  _Tp* allocate(size_type __n, size_type& __allocated_n, const __true_type& )
  { return _Base::_M_allocate(__n, __allocated_n); }


  _Tp* allocate(size_type __n, size_type& __allocated_n, const __false_type& )
  { __allocated_n = __n; return allocate(__n); }
};
# 568 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h"
}
}


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.c" 1
# 35 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.c"
namespace stlpmtx_std {

template <class _Alloc>
void * __debug_alloc<_Alloc>::allocate(size_t __n) {
  size_t __total_extra = __extra_before_chunk() + __extra_after_chunk();
  size_t __real_n = __n + __total_extra;
  if (__real_n < __n) {

    throw ::stlpmtx_std::bad_alloc();
  }
  __alloc_header *__result = (__alloc_header *)__allocator_type::allocate(__real_n);
  memset((char*)__result, __shred_byte, __real_n * sizeof(value_type));
  __result->__magic = __magic;
  __result->__type_size = sizeof(value_type);
  __result->_M_size = (unsigned long)__n;
  return ((char*)__result) + (long)__extra_before;
}

template <class _Alloc>
void
__debug_alloc<_Alloc>::deallocate(void *__p, size_t __n) {
  __alloc_header * __real_p = (__alloc_header*)((char *)__p -(long)__extra_before);

 
 
 
 

  unsigned char* __tmp;
  for (__tmp = (unsigned char*)(__real_p + 1); __tmp < (unsigned char*)__p; ++__tmp) {
   
  }

  size_t __real_n = __n + __extra_before_chunk() + __extra_after_chunk();

  for (__tmp= ((unsigned char*)__p) + __n * sizeof(value_type);
       __tmp < ((unsigned char*)__real_p) + __real_n ; ++__tmp) {
   
  }


  __real_p->__magic = __deleted_magic;
  memset((char*)__p, __shred_byte, __n * sizeof(value_type));
  __allocator_type::deallocate(__real_p, __real_n);
}

}
# 573 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_alloc.h" 2
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_fwd.h" 1
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_fwd.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iosfwd.h" 1
# 22 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iosfwd.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/char_traits.h" 1
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/char_traits.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cwchar.h" 1
# 36 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cwchar.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cwchar" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cwchar" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/wchar.h" 1 3 4
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/wchar.h" 3 4
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 1 3 4
# 17 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
extern "C" {







struct tm;
# 34 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
typedef struct __locale_s *locale_t;
# 43 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
typedef struct __RAL_FILE FILE;
# 76 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
typedef struct __mbstate_s mbstate_t;
# 107 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
typedef long wint_t;
# 120 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wmemcpy(wchar_t *__s1, const wchar_t *__s2, size_t __n);
# 138 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wmemccpy(wchar_t *__s1, const wchar_t *__s2, wchar_t __c, size_t __n);
# 152 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wmempcpy(wchar_t *__s1, const wchar_t *__s2, size_t __n);
# 167 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wmemmove(wchar_t *__s1, const wchar_t *__s2, size_t __n);
# 178 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
int wmemcmp(const wchar_t *__s1, const wchar_t *__s2, size_t __n);
# 191 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wmemchr(const wchar_t *__s, wchar_t __c, size_t __n);
# 201 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wmemset(wchar_t *__s, wchar_t __c, size_t __n);
# 212 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcscpy(wchar_t *__s1, const wchar_t *__s2);
# 227 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcsncpy(wchar_t *__s1, const wchar_t *__s2, size_t __n);
# 240 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcscat(wchar_t *__s1, const wchar_t *__s2);
# 254 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcsncat(wchar_t *__s1, const wchar_t *__s2, size_t __n);
# 264 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
int wcscmp(const wchar_t *__s1, const wchar_t *__s2);
# 277 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
int wcsncmp(const wchar_t *__s1, const wchar_t *__s2, size_t __n);
# 289 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcschr(const wchar_t *__s, wchar_t __c);
# 301 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcsnchr(const wchar_t *__str, size_t __n, wchar_t __ch);
# 312 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t wcscspn(const wchar_t *__s1, const wchar_t *__s2);
# 323 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcspbrk(const wchar_t *__s1, const wchar_t *__s2);
# 334 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcsrchr(const wchar_t *__s, wchar_t __c);
# 345 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t wcsspn(const wchar_t *__s1, const wchar_t *__s2);
# 358 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcsstr(const wchar_t *__s1, const wchar_t *__s2);
# 373 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcsnstr(const wchar_t *__s1, const wchar_t *__s2, size_t __n);







size_t wcslen(const wchar_t *__s);
# 392 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t wcsnlen(const wchar_t *__s, size_t __n);
# 424 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcstok(wchar_t *__s1, const wchar_t *__s2);
# 443 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wstrsep(wchar_t **__stringp, const wchar_t *__delim);
# 455 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcstok_r(wchar_t *__s1, const wchar_t *__s2, wchar_t **__s3);
# 470 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wchar_t *wcsdup(const wchar_t *__s1);
# 480 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
int msbinit(const mbstate_t *__ps);
# 495 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
int wctob(wint_t __c);
# 510 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
int wctob_l(wint_t c, locale_t __loc);
# 523 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t mbrlen(const char *__s, size_t __n, mbstate_t *__ps);
# 536 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t mbrlen_l(const char *__s, size_t __n, mbstate_t *__ps, locale_t __loc);
# 566 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t mbsrtowcs(wchar_t *__dst, const char **__src, size_t __len, mbstate_t *__ps);
# 596 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t mbsrtowcs_l(wchar_t *__dst, const char **__src, size_t __len, mbstate_t *__ps, locale_t __loc);
# 611 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wint_t btowc(int __c);
# 626 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
wint_t btowc_l(int __c, locale_t __loc);
# 654 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t mbrtowc(wchar_t *__pwc, const char *__s, size_t __n, mbstate_t *__ps);
# 682 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t mbrtowc_l(wchar_t *__pwc, const char *__s, size_t __n, mbstate_t *__ps, locale_t __loc);
# 703 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t wcrtomb(char *__s, wchar_t __wc, mbstate_t *__ps);
# 724 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
size_t wcrtomb_l(char *__s, wchar_t __wc, mbstate_t *__ps, locale_t __loc);


size_t mbsrtowcs(wchar_t *__dst, const char **__src, size_t __len, mbstate_t *__ps);
size_t mbsrtowcs_l(wchar_t *__dst, const char **__src, size_t __len, mbstate_t *__ps, locale_t __loc);

size_t wcsrtombs(char *__dst, const wchar_t **__src, size_t __len, mbstate_t *__ps);
size_t wcsrtombs_l(char *__dst, const wchar_t **__src, size_t __len, mbstate_t *__ps, locale_t __loc);



wint_t fgetwc(FILE *stream);
wchar_t *fgetws(wchar_t *ws, int num, FILE *stream);
wint_t fputwc(wchar_t wc, FILE *stream);
int fputws(const wchar_t *ws, FILE *stream);
int fwide(FILE *stream, int mode);
int fwprintf(FILE *stream, const wchar_t *format, ...);
int fwscanf(FILE *stream, const wchar_t *format, ...);
wint_t getwc(FILE *stream);
wint_t getwchar(void);
wint_t putwc(wchar_t wc, FILE *stream);
wint_t putwchar(wchar_t wc);
int swprintf(wchar_t *ws, size_t len, const wchar_t *format, ...);
int swscanf(const wchar_t *ws, const wchar_t *format, ...);
wint_t ungetwc(wint_t wc, FILE *stream);
int wcscoll(const wchar_t *wcs1, const wchar_t *wcs2);
int vswprintf(wchar_t *ws, size_t len, const wchar_t *format, __va_list arg);
int vcwscanf(const wchar_t *ws, const wchar_t *format, __va_list arg);
int vfwprintf(FILE *stream, const wchar_t *format, __va_list arg);
int vfwscanf(FILE *stream, const wchar_t *format, __va_list arg);
int vwprintf(const wchar_t *format, __va_list arg);
int vwscanf(const wchar_t *format, __va_list arg);
size_t wcsftime(wchar_t *ptr, size_t maxsize, const wchar_t *format,
                  const struct tm *timeptr);
size_t wcsxfrm(wchar_t *destination, const wchar_t *source, size_t num);
double wcstod(const wchar_t *str, wchar_t **endptr);
long int wcstol(const wchar_t *str, wchar_t **endptr, int base);
int wprintf(const wchar_t *format, ...);
int wscanf(const wchar_t *format, ...);
# 789 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\wchar.h" 3 4
}
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/wchar.h" 2 3 4





# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_mbstate_t.h" 1 3 4
# 54 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/wchar.h" 2 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cwchar" 2 3 4

namespace std
{
using ::mbstate_t;
using ::fgetwc;
using ::fgetws;
using ::fputwc;
using ::fputws;
using ::fwide;
using ::fwprintf;
using ::fwscanf;
using ::getwchar;
using ::getwc;
using ::ungetwc;
using ::putwc;
using ::putwchar;
using ::swprintf;
using ::vswprintf;
using ::swscanf;
using ::vfwprintf;
using ::vwprintf;
using ::wcsftime;
using ::wcstok;
using ::wcscoll;
using ::wcsxfrm;
using ::wcscat;
using ::wcsrchr;
using ::wcscmp;
using ::wcscpy;
using ::wcscspn;
using ::wcslen;
using ::wcsncat;
using ::wcsncmp;
using ::wcsncpy;
using ::wcspbrk;
using ::wcschr;
using ::wcsspn;
using ::wcstod;
using ::wcstol;
using ::wcsstr;
using ::wmemchr;
using ::wctob;
using ::wmemcmp;
using ::wmemmove;
using ::wprintf;
using ::wscanf;
using ::wmemcpy;
using ::wmemset;
}
# 37 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cwchar.h" 2
# 170 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cwchar.h"
namespace stlpmtx_std {







using ::wint_t;





using std::size_t;


using std::mbstate_t;
# 213 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cwchar.h"
using std::fgetwc;
using std::fgetws;
using std::fputwc;
using std::fputws;





using std::fwide;

using std::fwprintf;
using std::fwscanf;
using std::getwchar;




using std::getwc;

using std::ungetwc;

using std::putwc;

using std::putwchar;
# 251 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cwchar.h"
using std::swprintf;
using std::vswprintf;

using std::swscanf;
using std::vfwprintf;
using std::vwprintf;




using std::wcsftime;

using std::wcstok;




using std::wcscoll;
using std::wcsxfrm;

using std::wcscat;
using std::wcsrchr;
using std::wcscmp;

using std::wcscpy;
using std::wcscspn;

using std::wcslen;
using std::wcsncat;
using std::wcsncmp;
using std::wcsncpy;
using std::wcspbrk;
using std::wcschr;

using std::wcsspn;


using std::wcstod;
using std::wcstol;



using std::wcsstr;
using std::wmemchr;



using std::wctob;


using std::wmemcmp;
using std::wmemmove;

using std::wprintf;
using std::wscanf;
# 327 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cwchar.h"
using std::wmemcpy;
using std::wmemset;




}
# 49 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/char_traits.h" 2


namespace stlpmtx_std {

template <class _Tp> class allocator;
# 74 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/char_traits.h"
typedef off_t streamoff;






typedef ptrdiff_t streamsize;





template <class _StateT> class fpos {
public:
  fpos(streamoff __pos) : _M_pos(__pos), _M_st(_StateT()) {}
  fpos() : _M_pos(0), _M_st(_StateT()) {}

  operator streamoff() const { return _M_pos; }

  bool operator==(const fpos& __y) const
  { return _M_pos == __y._M_pos; }
  bool operator!=(const fpos& __y) const
  { return _M_pos != __y._M_pos; }

  fpos& operator+=(streamoff __off) {
    _M_pos += __off;
    return *this;
  }
  fpos& operator-=(streamoff __off) {
    _M_pos -= __off;
    return *this;
  }

  fpos operator+(streamoff __off) {
    fpos __tmp(*this);
    __tmp += __off;
    return __tmp;
  }
  fpos operator-(streamoff __off) {
    fpos __tmp(*this);
    __tmp -= __off;
    return __tmp;
  }

public:
  _StateT state() const { return _M_st; }
  void state(_StateT __st) { _M_st = __st; }
private:
  streamoff _M_pos;
  _StateT _M_st;
};

typedef fpos<mbstate_t> streampos;
typedef fpos<mbstate_t> wstreampos;


template <class _CharT, class _IntT>
class __char_traits_base {
public:
  typedef _CharT char_type;
  typedef _IntT int_type;
  typedef streamoff off_type;
  typedef streampos pos_type;
  typedef mbstate_t state_type;

  static void assign(char_type& __c1, const char_type& __c2) { __c1 = __c2; }
  static bool eq(const char_type& __c1, const char_type& __c2)
  { return __c1 == __c2; }
  static bool lt(const char_type& __c1, const char_type& __c2)
  { return __c1 < __c2; }

  static int compare(const char_type* __s1, const char_type* __s2, size_t __n) {
    for (size_t __i = 0; __i < __n; ++__i)
      if (!eq(__s1[__i], __s2[__i]))
        return __s1[__i] < __s2[__i] ? -1 : 1;
    return 0;
  }

  static size_t length(const char_type* __s) {
    const char_type _NullChar = char_type();
    size_t __i(0);
    for (; !eq(__s[__i], _NullChar); ++__i) {}
    return __i;
  }

  static const char_type* find(const char_type* __s, size_t __n, const char_type& __c) {
    for ( ; __n > 0 ; ++__s, --__n)
      if (eq(*__s, __c))
        return __s;
    return 0;
  }

  static char_type* move(char_type* __s1, const char_type* __s2, size_t _Sz)
  { return (_Sz == 0 ? __s1 : (char_type*)memmove(__s1, __s2, _Sz * sizeof(char_type))); }

  static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) {
    return (__n == 0 ? __s1 :
      (char_type*)memcpy(__s1, __s2, __n * sizeof(char_type)));
  }

  static char_type* assign(char_type* __s, size_t __n, char_type __c) {
    for (size_t __i = 0; __i < __n; ++__i)
      __s[__i] = __c;
    return __s;
  }

  static int_type not_eof(const int_type& __c)
  { return !eq_int_type(__c, eof()) ? __c : static_cast<int_type>(0); }

  static char_type to_char_type(const int_type& __c)
  { return (char_type)__c; }

  static int_type to_int_type(const char_type& __c)
  { return (int_type)__c; }

  static bool eq_int_type(const int_type& __c1, const int_type& __c2)
  { return __c1 == __c2; }

  static int_type eof()
  { return (int_type)-1; }
};






template <class _CharT>
class char_traits
  : public __char_traits_base<_CharT, _CharT> {};



template<>
class char_traits<char>
  : public __char_traits_base<char, int>,
    public __stlport_class<char_traits<char> > {
public:
  typedef char char_type;
  typedef int int_type;
  typedef streamoff off_type;
  typedef streampos pos_type;
  typedef mbstate_t state_type;

  static char to_char_type(const int& __c)
  { return (char)(unsigned char)__c; }

  static int to_int_type(const char& __c)
  { return (unsigned char)__c; }

  static int compare(const char* __s1, const char* __s2, size_t __n)
  { return memcmp(__s1, __s2, __n); }

  static size_t length(const char* __s)
  { return strlen(__s); }

  static void assign(char& __c1, const char& __c2)
  { __c1 = __c2; }

  static char* assign(char* __s, size_t __n, char __c) {
    memset(__s, __c, __n);
    return __s;
  }
};



template<>
class char_traits<wchar_t>
  : public __char_traits_base<wchar_t, wint_t> {

public:

  static wchar_t* move(wchar_t* __dest, const wchar_t* __src, size_t __n)
  { return wmemmove(__dest, __src, __n); }


  static wchar_t* copy(wchar_t* __dest, const wchar_t* __src, size_t __n)
  { return wmemcpy(__dest, __src, __n); }


  static int compare(const wchar_t* __s1, const wchar_t* __s2, size_t __n)
  { return wmemcmp(__s1, __s2, __n); }


  static wchar_t* assign(wchar_t* __s, size_t __n, wchar_t __c)
  { return wmemset(__s, __c, __n); }

  static size_t length(const wchar_t* __s)
  { return wcslen(__s); }

  static void assign(wchar_t& __c1, const wchar_t& __c2)
  { __c1 = __c2; }

};


}
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iosfwd.h" 2


namespace stlpmtx_std {

class ios_base;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ios;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_streambuf;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_istream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ostream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_iostream;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_stringbuf;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_istringstream;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_ostringstream;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_stringstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_filebuf;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ifstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ofstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_fstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class istreambuf_iterator;

template <class _CharT, class _Traits = char_traits<_CharT> >
class ostreambuf_iterator;

typedef basic_ios<char, char_traits<char> > ios;


typedef basic_ios<wchar_t, char_traits<wchar_t> > wios;



class locale;
template <class _Facet>
# 95 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_iosfwd.h"
inline const _Facet& use_facet(const locale&);


template <class _CharT> class ctype;
template <class _CharT> class ctype_byname;
template <class _CharT> class collate;
template <class _CharT> class collate_byname;

template<> class ctype<char>;
template<> class ctype_byname<char>;
template<> class collate<char>;
template<> class collate_byname<char>;


template<> class ctype<wchar_t>;
template<> class ctype_byname<wchar_t>;
template<> class collate<wchar_t>;
template<> class collate_byname<wchar_t>;







typedef basic_istream<char, char_traits<char> > istream;
typedef basic_ostream<char, char_traits<char> > ostream;
typedef basic_iostream<char, char_traits<char> > iostream;
typedef basic_streambuf<char,char_traits<char> > streambuf;

typedef basic_stringbuf<char, char_traits<char>, allocator<char> > stringbuf;
typedef basic_istringstream<char, char_traits<char>, allocator<char> > istringstream;
typedef basic_ostringstream<char, char_traits<char>, allocator<char> > ostringstream;
typedef basic_stringstream<char, char_traits<char>, allocator<char> > stringstream;

typedef basic_filebuf<char, char_traits<char> > filebuf;
typedef basic_ifstream<char, char_traits<char> > ifstream;
typedef basic_ofstream<char, char_traits<char> > ofstream;
typedef basic_fstream<char, char_traits<char> > fstream;



typedef basic_streambuf<wchar_t, char_traits<wchar_t> > wstreambuf;
typedef basic_istream<wchar_t, char_traits<wchar_t> > wistream;
typedef basic_ostream<wchar_t, char_traits<wchar_t> > wostream;
typedef basic_iostream<wchar_t, char_traits<wchar_t> > wiostream;

typedef basic_stringbuf<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstringbuf;
typedef basic_istringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wistringstream;
typedef basic_ostringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wostringstream;
typedef basic_stringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstringstream;

typedef basic_filebuf<wchar_t, char_traits<wchar_t> > wfilebuf;
typedef basic_ifstream<wchar_t, char_traits<wchar_t> > wifstream;
typedef basic_ofstream<wchar_t, char_traits<wchar_t> > wofstream;
typedef basic_fstream<wchar_t, char_traits<wchar_t> > wfstream;


}
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_fwd.h" 2


namespace stlpmtx_std {


template <class _CharT,
          class _Traits = char_traits<_CharT>,
          class _Alloc = allocator<_CharT> >
class basic_string;







typedef basic_string<char, char_traits<char>, allocator<char> > string;


typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstring;


namespace priv {



const char* __get_c_string(const string& __str);

}

}
# 28 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 2
# 43 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_uninitialized.h" 1
# 45 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_uninitialized.h"
namespace stlpmtx_std {

namespace priv {



template <class _InputIter, class _OutputIter, class _Distance>
inline _OutputIter __ucopy(_InputIter __first, _InputIter __last,
                           _OutputIter __result, _Distance*) {
  _OutputIter __cur = __result;
  try {
    for ( ; __first != __last; ++__first, ++__cur)
      _Param_Construct(&*__cur, *__first);
    return __cur;
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__result, __cur); throw; }
 
}

template <class _InputIter, class _OutputIter, class _Distance>
inline _OutputIter __ucopy(_InputIter __first, _InputIter __last,
                           _OutputIter __result, const input_iterator_tag &, _Distance* __d)
{ return __ucopy(__first, __last, __result, __d); }
# 81 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_uninitialized.h"
template <class _RandomAccessIter, class _OutputIter, class _Distance>
inline _OutputIter __ucopy(_RandomAccessIter __first, _RandomAccessIter __last,
                           _OutputIter __result, const random_access_iterator_tag &, _Distance*) {
  _OutputIter __cur = __result;
  try {
    for (_Distance __n = __last - __first; __n > 0; --__n) {
      _Param_Construct(&*__cur, *__first);
      ++__first;
      ++__cur;
    }
    return __cur;
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__result, __cur); throw; }
 
}


template <class _RandomAccessIter, class _OutputIter>
inline _OutputIter __ucopy(_RandomAccessIter __first, _RandomAccessIter __last, _OutputIter __result)
{ return __ucopy(__first, __last, __result, random_access_iterator_tag(), (ptrdiff_t*)0); }

inline void*
__ucopy_trivial(const void* __first, const void* __last, void* __result) {

  return (__last == __first) ? __result :
    ((char*)memcpy(__result, __first, ((const char*)__last - (const char*)__first))) +
    ((const char*)__last - (const char*)__first);
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __ucopy_ptrs(_InputIter __first, _InputIter __last, _OutputIter __result,
                                const __false_type& )
{ return __ucopy(__first, __last, __result, random_access_iterator_tag(), (ptrdiff_t*)0); }

template <class _InputIter, class _OutputIter>
inline _OutputIter __ucopy_ptrs(_InputIter __first, _InputIter __last, _OutputIter __result,
                                const __true_type& ) {


  return (_OutputIter)__ucopy_trivial(__first, __last, __result);
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __ucopy_aux(_InputIter __first, _InputIter __last, _OutputIter __result,
                               const __true_type& ) {
  return __ucopy_ptrs(__first, __last, __result,
                      _UseTrivialUCopy((typename ::stlpmtx_std::iterator_traits< _InputIter >::value_type*)0,
                                       (typename ::stlpmtx_std::iterator_traits< _OutputIter >::value_type*)0)._Answer());
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __ucopy_aux(_InputIter __first, _InputIter __last, _OutputIter __result,
                               const __false_type& ) {
  return __ucopy(__first, __last, __result,
                 typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category(),
                 (typename ::stlpmtx_std::iterator_traits< _InputIter >::difference_type*)0);
}

}

template <class _InputIter, class _ForwardIter>
inline _ForwardIter
uninitialized_copy(_InputIter __first, _InputIter __last, _ForwardIter __result)
{ return ::stlpmtx_std::priv:: __ucopy_aux(__first, __last, __result, _BothPtrType< _InputIter, _ForwardIter>::_Answer()); }

inline char*
uninitialized_copy(const char* __first, const char* __last, char* __result)
{ return (char*)::stlpmtx_std::priv:: __ucopy_trivial(__first, __last, __result); }


inline wchar_t*
uninitialized_copy(const wchar_t* __first, const wchar_t* __last, wchar_t* __result)
{ return (wchar_t*)::stlpmtx_std::priv:: __ucopy_trivial (__first, __last, __result); }



namespace priv {

template <class _InputIter, class _Size, class _ForwardIter>
inline
pair<_InputIter, _ForwardIter>
__ucopy_n(_InputIter __first, _Size __count, _ForwardIter __result,
          const input_iterator_tag &) {
  _ForwardIter __cur = __result;
  try {
    for ( ; __count > 0 ; --__count, ++__first, ++__cur)
      _Param_Construct(&*__cur, *__first);
    return pair<_InputIter, _ForwardIter>(__first, __cur);
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__result, __cur); throw; }
 
}
# 190 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_uninitialized.h"
template <class _RandomAccessIter, class _Size, class _ForwardIter>
inline pair<_RandomAccessIter, _ForwardIter>
__ucopy_n(_RandomAccessIter __first, _Size __count, _ForwardIter __result,
                       const random_access_iterator_tag &) {
  _RandomAccessIter __last = __first + __count;
  return pair<_RandomAccessIter, _ForwardIter>(__last, uninitialized_copy(__first, __last, __result));
}


template <class _InputIter, class _Size, class _ForwardIter>
inline pair<_InputIter, _ForwardIter>
__ucopy_n(_InputIter __first, _Size __count, _ForwardIter __result)
{ return ::stlpmtx_std::priv:: __ucopy_n(__first, __count, __result, typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category()); }



}

template <class _InputIter, class _Size, class _ForwardIter>
inline pair<_InputIter, _ForwardIter>
uninitialized_copy_n(_InputIter __first, _Size __count, _ForwardIter __result)
{ return ::stlpmtx_std::priv:: __ucopy_n(__first, __count, __result); }

namespace priv {



template <class _ForwardIter, class _Tp, class _Distance>
inline void __ufill(_ForwardIter __first, _ForwardIter __last, const _Tp& __x, _Distance*) {
  _ForwardIter __cur = __first;
  try {
    for ( ; __cur != __last; ++__cur)
      _Param_Construct(&*__cur, __x);
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__first, __cur); throw; }
}

template <class _ForwardIter, class _Tp, class _Distance>
inline void __ufill(_ForwardIter __first, _ForwardIter __last,
                    const _Tp& __x, const input_iterator_tag &, _Distance* __d)
{ __ufill(__first, __last, __x, __d); }
# 244 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_uninitialized.h"
template <class _ForwardIter, class _Tp, class _Distance>
inline void __ufill(_ForwardIter __first, _ForwardIter __last,
                    const _Tp& __x, const random_access_iterator_tag &, _Distance*) {
  _ForwardIter __cur = __first;
  try {
    for (_Distance __n = __last - __first; __n > 0; --__n, ++__cur)
      _Param_Construct(&*__cur, __x);
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__first, __cur); throw; }
}

}

template <class _ForwardIter, class _Tp>
inline void uninitialized_fill(_ForwardIter __first, _ForwardIter __last, const _Tp& __x) {
  ::stlpmtx_std::priv:: __ufill(__first, __last, __x,
                     typename ::stlpmtx_std::iterator_traits< _ForwardIter >::iterator_category(),
                     (typename ::stlpmtx_std::iterator_traits< _ForwardIter >::difference_type*)0);
}


inline void uninitialized_fill(unsigned char* __first, unsigned char* __last,
                               const unsigned char& __val) {
  unsigned char __tmp = __val;
  memset(__first, __tmp, __last - __first);
}

inline void uninitialized_fill(signed char* __first, signed char* __last,
                               const signed char& __val) {
  signed char __tmp = __val;
  memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

inline void uninitialized_fill(char* __first, char* __last, const char& __val) {
  char __tmp = __val;
  memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

namespace priv {

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __ufill_n(_ForwardIter __first, _Size __n, const _Tp& __x) {
  _ForwardIter __cur = __first;
  try {
    for ( ; __n > 0; --__n, ++__cur)
      _Param_Construct(&*__cur, __x);
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__first, __cur); throw; }
  return __cur;
}

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __ufill_n(_ForwardIter __first, _Size __n, const _Tp& __x,
                              const input_iterator_tag &)
{ return __ufill_n(__first, __n, __x); }
# 312 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_uninitialized.h"
template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __uninitialized_fill_n(_ForwardIter __first, _Size __n, const _Tp& __x) {
  _ForwardIter __last = __first + __n;
  __ufill(__first, __last, __x, random_access_iterator_tag(), (ptrdiff_t*)0);
  return __last;
}

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __ufill_n(_ForwardIter __first, _Size __n, const _Tp& __x,
                              const random_access_iterator_tag &)
{ return __uninitialized_fill_n(__first, __n, __x); }





template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __uinit_aux_aux(_ForwardIter __first, _Size __n, const _Tp& __val,
                                    const __false_type& )
{ return __uninitialized_fill_n(__first, __n, __val); }

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __uinit_aux_aux(_ForwardIter __first, _Size __n, const _Tp& ,
                                    const __true_type& ) {
  memset((unsigned char*)__first, 0, __n * sizeof(_Tp));
  return __first + __n;
}

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __uinit_aux(_ForwardIter __first, _Size __n, const _Tp&,
                                const __true_type& )
{ return __first + __n; }

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __uinit_aux(_ForwardIter __first, _Size __n, const _Tp& __val,
                                const __false_type& )
{ return __uinit_aux_aux(__first, __n, __val, _HasDefaultZeroValue(__first)._Answer()); }

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter __uninitialized_init(_ForwardIter __first, _Size __n, const _Tp& __val)
{ return __uinit_aux(__first, __n, __val, _UseTrivialInit(__first)._Answer()); }

}

template <class _ForwardIter, class _Size, class _Tp>
inline void
uninitialized_fill_n(_ForwardIter __first, _Size __n, const _Tp& __x)
{ ::stlpmtx_std::priv:: __ufill_n(__first, __n, __x, typename ::stlpmtx_std::iterator_traits< _ForwardIter >::iterator_category()); }
# 369 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_uninitialized.h"
namespace priv {

template <class _InputIter1, class _InputIter2, class _ForwardIter>
inline _ForwardIter
__uninitialized_copy_copy(_InputIter1 __first1, _InputIter1 __last1,
                          _InputIter2 __first2, _InputIter2 __last2,
                          _ForwardIter __result) {
  _ForwardIter __new_result = uninitialized_copy(__first1, __last1, __result);
  try {
    return uninitialized_copy(__first2, __last2, __new_result);
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__result, __new_result); throw; }
 
}




template <class _ForwardIter, class _Tp, class _InputIter>
inline _ForwardIter
__uninitialized_fill_copy(_ForwardIter __result, _ForwardIter __mid, const _Tp& __x,
                          _InputIter __first, _InputIter __last) {
  uninitialized_fill(__result, __mid, __x);
  try {
    return uninitialized_copy(__first, __last, __mid);
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__result, __mid); throw; }
 
}




template <class _Iter, class _Tp>
inline void
__uninitialized_copy_fill(_Iter __first1, _Iter __last1, _Iter __first2, _Iter __last2,
                          const _Tp& __x) {
  _Iter __mid2 = uninitialized_copy(__first1, __last1, __first2);
  try {
    uninitialized_fill(__mid2, __last2, __x);
  }
  catch(...) { ::stlpmtx_std::_Destroy_Range(__first2, __mid2); throw; }
}




template <class _InputIter, class _ForwardIter, class _TrivialUCpy>
inline _ForwardIter
__uninitialized_move(_InputIter __first, _InputIter __last, _ForwardIter __result,
                     _TrivialUCpy __trivial_ucpy, const __false_type& )
{ return __ucopy_ptrs(__first, __last, __result, __trivial_ucpy); }

template <class _InputIter, class _ForwardIter, class _TrivialUCpy>
inline
_ForwardIter
__uninitialized_move(_InputIter __first, _InputIter __last, _ForwardIter __result,
                     _TrivialUCpy , const __true_type& ) {

  for (ptrdiff_t __n = __last - __first ; __n > 0; --__n) {
    _Move_Construct(&*__result, *__first);
    ++__first; ++__result;
  }
  return __result;
}

}

}
# 44 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 2
# 78 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_base.h" 1
# 36 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_base.h"
namespace stlpmtx_std {

namespace priv {

template <class _Tp, class _Alloc>
class _String_base {
    typedef _String_base<_Tp, _Alloc> _Self;
protected:
 
public:

  enum {_DEFAULT_SIZE = 4 * sizeof( void * )};

  typedef _Alloc allocator_type;
  typedef _STLP_alloc_proxy<_Tp*, _Tp, allocator_type> _AllocProxy;
  typedef size_t size_type;
private:

  union _Buffers {
    _Tp* _M_end_of_storage;
    _Tp _M_static_buf[_DEFAULT_SIZE];
  } _M_buffers;



protected:

  bool _M_using_static_buf() const
  { return (_M_start_of_storage._M_data == _M_buffers._M_static_buf); }
  _Tp const* _M_Start() const { return _M_start_of_storage._M_data; }
  _Tp* _M_Start() { return _M_start_of_storage._M_data; }
  _Tp const* _M_End() const
  { return _M_using_static_buf() ? _M_buffers._M_static_buf + _DEFAULT_SIZE : _M_buffers._M_end_of_storage; }
  _Tp* _M_End()
  { return _M_using_static_buf() ? _M_buffers._M_static_buf + _DEFAULT_SIZE : _M_buffers._M_end_of_storage; }
  size_type _M_capacity() const
  { return _M_using_static_buf() ? _DEFAULT_SIZE : _M_buffers._M_end_of_storage - _M_start_of_storage._M_data; }
  size_type _M_rest() const
  { return _M_using_static_buf() ? _DEFAULT_SIZE - (_M_finish - _M_buffers._M_static_buf) : _M_buffers._M_end_of_storage - _M_finish; }
# 86 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_base.h"
  _Tp* _M_finish;
  _AllocProxy _M_start_of_storage;

  _Tp const* _M_Finish() const {return _M_finish;}
  _Tp* _M_Finish() {return _M_finish;}


  void _M_allocate_block(size_t __n = _DEFAULT_SIZE);
  void _M_deallocate_block() {

    if (!_M_using_static_buf() && (_M_start_of_storage._M_data != 0))
      _M_start_of_storage.deallocate(_M_start_of_storage._M_data, _M_buffers._M_end_of_storage - _M_start_of_storage._M_data);




  }

  size_t max_size() const {
    const size_type __string_max_size = size_type(-1) / sizeof(_Tp);
    typename allocator_type::size_type __alloc_max_size = _M_start_of_storage.max_size();
    return (min)(__alloc_max_size, __string_max_size) - 1;
  }

  _String_base(const allocator_type& __a)

    : _M_finish(_M_buffers._M_static_buf), _M_start_of_storage(__a, _M_buffers._M_static_buf)



    {}

  _String_base(const allocator_type& __a, size_t __n)

    : _M_finish(_M_buffers._M_static_buf), _M_start_of_storage(__a, _M_buffers._M_static_buf) {



      _M_allocate_block(__n);
    }


  void _M_move_src (_Self &src) {
    if (src._M_using_static_buf()) {
      _M_buffers = src._M_buffers;
      _M_finish = _M_buffers._M_static_buf + (src._M_finish - src._M_start_of_storage._M_data);
      _M_start_of_storage._M_data = _M_buffers._M_static_buf;
    }
    else {
      _M_start_of_storage._M_data = src._M_start_of_storage._M_data;
      _M_finish = src._M_finish;
      _M_buffers._M_end_of_storage = src._M_buffers._M_end_of_storage;
      src._M_start_of_storage._M_data = 0;
    }
  }



  _String_base(__move_source<_Self> src)

    : _M_start_of_storage(__move_source<_AllocProxy>(src.get()._M_start_of_storage)) {
      _M_move_src(src.get());





    }


  ~_String_base() { _M_deallocate_block(); }

  void _M_reset(_Tp *__start, _Tp *__finish, _Tp *__end_of_storage) {

    _M_buffers._M_end_of_storage = __end_of_storage;



    _M_finish = __finish;
    _M_start_of_storage._M_data = __start;
  }

  void _M_swap(_Self &__s) {

    if (_M_using_static_buf()) {
      if (__s._M_using_static_buf()) {
        ::stlpmtx_std::swap(_M_buffers, __s._M_buffers);
        _Tp *__tmp = _M_finish;
        _M_finish = _M_start_of_storage._M_data + (__s._M_finish - __s._M_start_of_storage._M_data);
        __s._M_finish = __s._M_buffers._M_static_buf + (__tmp - _M_start_of_storage._M_data);

        _M_start_of_storage.swap(__s._M_start_of_storage);
        _M_start_of_storage._M_data = _M_buffers._M_static_buf;
        __s._M_start_of_storage._M_data = __s._M_buffers._M_static_buf;
      } else {
        __s._M_swap(*this);
        return;
      }
    }
    else if (__s._M_using_static_buf()) {
      _Tp *__tmp = _M_start_of_storage._M_data;
      _Tp *__tmp_finish = _M_finish;
      _Tp *__tmp_end_data = _M_buffers._M_end_of_storage;
      _M_buffers = __s._M_buffers;

      _M_start_of_storage.swap(__s._M_start_of_storage);
      _M_start_of_storage._M_data = _M_buffers._M_static_buf;
      _M_finish = _M_buffers._M_static_buf + (__s._M_finish - __s._M_buffers._M_static_buf);
      __s._M_buffers._M_end_of_storage = __tmp_end_data;
      __s._M_start_of_storage._M_data = __tmp;
      __s._M_finish = __tmp_finish;
    }
    else {
      ::stlpmtx_std::swap(_M_buffers._M_end_of_storage, __s._M_buffers._M_end_of_storage);
      _M_start_of_storage.swap(__s._M_start_of_storage);
      ::stlpmtx_std::swap(_M_finish, __s._M_finish);
    }





  }

  void _M_throw_length_error() const;
  void _M_throw_out_of_range() const;
};
# 221 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_base.h"
}

}
# 79 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 2

namespace stlpmtx_std {
# 98 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
namespace priv {
struct _String_reserve_t {};
}
# 120 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
template <class _CharT, class _Traits, class _Alloc>
class basic_string : private ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>



{
private:
  typedef ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc> _Base;
  typedef basic_string<_CharT, _Traits, _Alloc> _Self;

public:
  typedef _CharT value_type;
  typedef _Traits traits_type;

  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename _Base::size_type size_type;
  typedef ptrdiff_t difference_type;
  typedef random_access_iterator_tag _Iterator_category;

  typedef const value_type* const_iterator;
  typedef value_type* iterator;

  typedef ::stlpmtx_std::reverse_iterator<const_iterator> const_reverse_iterator; typedef ::stlpmtx_std::reverse_iterator<iterator> reverse_iterator;

# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_npos.h" 1
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_npos.h"
  static const size_t npos = ~(size_t)0;
# 148 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 2

  typedef ::stlpmtx_std::priv:: _String_reserve_t _Reserve_t;

public:
  typedef typename _Base::allocator_type allocator_type;

  allocator_type get_allocator() const
  { return (const allocator_type&)this->_M_start_of_storage; }


  explicit basic_string(const allocator_type& __a = allocator_type())






      : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__a, _Base::_DEFAULT_SIZE)
  { _M_terminate_string(); }


  basic_string(_Reserve_t, size_t __n,
               const allocator_type& __a = allocator_type())






    : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__a, __n + 1)
  { _M_terminate_string(); }

  basic_string(const _Self&);


  basic_string(const _Self& __s, size_type __pos, size_type __n = npos,
               const allocator_type& __a = allocator_type())
# 204 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
    : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__a) {
    if (__pos > __s.size())
      this->_M_throw_out_of_range();
    else
      _M_range_initialize(__s._M_Start() + __pos,
                          __s._M_Start() + __pos + (min) (__n, __s.size() - __pos));
  }


  basic_string(const _CharT* __s, size_type __n,
               const allocator_type& __a = allocator_type())
# 223 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
    : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__a) {
     
      _M_range_initialize(__s, __s + __n);
    }


  basic_string(const _CharT* __s,
               const allocator_type& __a = allocator_type());






  basic_string(size_type __n, _CharT __c,
               const allocator_type& __a = allocator_type())
# 247 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
    : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__a, __n + 1) {
    this->_M_finish = ::stlpmtx_std::priv:: __uninitialized_fill_n(this->_M_Start(), __n, __c);
    _M_terminate_string();
  }


  basic_string(__move_source<_Self> src)
    : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__move_source<_Base>(src.get())) {}





  template <class _InputIterator>
  basic_string(_InputIterator __f, _InputIterator __l,
               const allocator_type & __a = allocator_type())
    : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__a) {
    typedef typename _IsIntegral<_InputIterator>::_Ret _Integral;
    _M_initialize_dispatch(__f, __l, _Integral());
  }
# 301 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
private:
  size_type _M_compute_next_size(size_type __n) {
    const size_type __size = size();
    if (__n > max_size() - __size)
      this->_M_throw_length_error();
    size_type __len = __size + (max)(__n, __size) + 1;
    if (__len > max_size() || __len < __size)
      __len = max_size();
    return __len;
  }

  template <class _InputIter>
  void _M_range_initialize(_InputIter __f, _InputIter __l,
                           const input_iterator_tag &__tag) {
    this->_M_allocate_block();
    _M_construct_null(this->_M_Finish());
    _M_appendT(__f, __l, __tag);
  }

  template <class _ForwardIter>
  void _M_range_initialize(_ForwardIter __f, _ForwardIter __l,
                           const forward_iterator_tag &) {
    difference_type __n = ::stlpmtx_std::distance(__f, __l);
    this->_M_allocate_block(__n + 1);
    this->_M_finish = uninitialized_copy(__f, __l, this->_M_Start());
    this->_M_terminate_string();
  }

  template <class _InputIter>
  void _M_range_initializeT(_InputIter __f, _InputIter __l) {
    _M_range_initialize(__f, __l, typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category());
  }

  template <class _Integer>
  void _M_initialize_dispatch(_Integer __n, _Integer __x, const __true_type& ) {
    this->_M_allocate_block(__n + 1);
    this->_M_finish = ::stlpmtx_std::priv:: __uninitialized_fill_n(this->_M_Start(), __n, __x);
    this->_M_terminate_string();
  }

  template <class _InputIter>
  void _M_initialize_dispatch(_InputIter __f, _InputIter __l, const __false_type& ) {
    _M_range_initializeT(__f, __l);
  }

public:
  _Self& operator=(const _Self& __s) {
    if (&__s != this)
      _M_assign(__s._M_Start(), __s._M_Finish());
    return *this;
  }

  _Self& operator=(const _CharT* __s) {
   
    return _M_assign(__s, __s + traits_type::length(__s));
  }

  _Self& operator=(_CharT __c)
  { return assign(static_cast<size_type>(1), __c); }

private:
  static _CharT _M_null()
  { return _CharT(); }

private:

  void _M_construct_null(_CharT* __p) const
  { ::stlpmtx_std::_Construct(__p); }
  void _M_terminate_string()
  { _M_construct_null(this->_M_Finish()); }
  bool _M_inside(const _CharT* __s) const {
   
    return (__s >= this->_M_Start()) && (__s < this->_M_Finish());
  }

  void _M_range_initialize(const _CharT* __f, const _CharT* __l) {
   
    ptrdiff_t __n = __l - __f;
    this->_M_allocate_block(__n + 1);
    this->_M_finish = uninitialized_copy(__f, __l, this->_M_Start());
    _M_terminate_string();
  }

public:
  iterator begin() { return this->_M_Start(); }
  iterator end() { return this->_M_Finish(); }
  const_iterator begin() const { return this->_M_Start(); }
  const_iterator end() const { return this->_M_Finish(); }

  reverse_iterator rbegin()
  { return reverse_iterator(this->_M_Finish()); }
  reverse_iterator rend()
  { return reverse_iterator(this->_M_Start()); }
  const_reverse_iterator rbegin() const
  { return const_reverse_iterator(this->_M_Finish()); }
  const_reverse_iterator rend() const
  { return const_reverse_iterator(this->_M_Start()); }

public:
  size_type size() const { return this->_M_Finish() - this->_M_Start(); }
  size_type length() const { return size(); }
  size_type max_size() const { return _Base::max_size(); }

  void resize(size_type __n, _CharT __c) {
    if (__n <= size())
      erase(begin() + __n, end());
    else
      append(__n - size(), __c);
  }

  void resize(size_type __n) { resize(__n, _M_null()); }

private:
  void _M_reserve(size_type);
public:
  void reserve(size_type = 0);

  size_type capacity() const
  { return this->_M_capacity() - 1; }

  void clear() {
    if (!empty()) {
      _Traits::assign(*(this->_M_Start()), _M_null());
      this->_M_finish = this->_M_Start();
    }
  }

  bool empty() const { return this->_M_Start() == this->_M_Finish(); }

public:

  const_reference operator[](size_type __n) const
  { return *(this->_M_Start() + __n); }
  reference operator[](size_type __n)
  { return *(this->_M_Start() + __n); }

  const_reference at(size_type __n) const {
    if (__n >= size())
      this->_M_throw_out_of_range();
    return *(this->_M_Start() + __n);
  }

  reference at(size_type __n) {
    if (__n >= size())
      this->_M_throw_out_of_range();
    return *(this->_M_Start() + __n);
  }

public:

  _Self& operator+=(const _Self& __s) { return append(__s); }
  _Self& operator+=(const _CharT* __s) { return append(__s); }
  _Self& operator+=(_CharT __c) { push_back(__c); return *this; }

private:
  _Self& _M_append(const _CharT* __first, const _CharT* __last);


  template <class _InputIter>
  _Self& _M_appendT(_InputIter __first, _InputIter __last,
                    const input_iterator_tag &) {
    for ( ; __first != __last ; ++__first)
      push_back(*__first);
    return *this;
  }

  template <class _ForwardIter>
  _Self& _M_appendT(_ForwardIter __first, _ForwardIter __last,
                    const forward_iterator_tag &) {
    if (__first != __last) {
      size_type __n = static_cast<size_type>(::stlpmtx_std::distance(__first, __last));
      if (__n >= this->_M_rest()) {
        size_type __len = _M_compute_next_size(__n);
        pointer __new_start = this->_M_start_of_storage.allocate(__len, __len);
        pointer __new_finish = uninitialized_copy(this->_M_Start(), this->_M_Finish(), __new_start);
        __new_finish = uninitialized_copy(__first, __last, __new_finish);
        _M_construct_null(__new_finish);
        this->_M_deallocate_block();
        this->_M_reset(__new_start, __new_finish, __new_start + __len);
      }
      else {
        _Traits::assign(*this->_M_finish, *__first++);
        uninitialized_copy(__first, __last, this->_M_Finish() + 1);
        _M_construct_null(this->_M_Finish() + __n);
        this->_M_finish += __n;
      }
    }
    return *this;
  }

  template <class _Integer>
  _Self& _M_append_dispatch(_Integer __n, _Integer __x, const __true_type& )
  { return append((size_type) __n, (_CharT) __x); }

  template <class _InputIter>
  _Self& _M_append_dispatch(_InputIter __f, _InputIter __l, const __false_type& )
  { return _M_appendT(__f, __l, typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category()); }

public:


  template <class _InputIter>
  _Self& append(_InputIter __first, _InputIter __last) {
    typedef typename _IsIntegral<_InputIter>::_Ret _Integral;
    return _M_append_dispatch(__first, __last, _Integral());
  }
# 515 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
public:
  _Self& append(const _Self& __s)
  { return _M_append(__s._M_Start(), __s._M_Finish()); }

  _Self& append(const _Self& __s,
                size_type __pos, size_type __n) {
    if (__pos > __s.size())
      this->_M_throw_out_of_range();
    return _M_append(__s._M_Start() + __pos,
                     __s._M_Start() + __pos + (min) (__n, __s.size() - __pos));
  }

  _Self& append(const _CharT* __s, size_type __n)
  { return _M_append(__s, __s+__n); }
  _Self& append(const _CharT* __s)
  { return _M_append(__s, __s + traits_type::length(__s)); }
  _Self& append(size_type __n, _CharT __c);

public:
  void push_back(_CharT __c) {
    if (this->_M_rest() == 1 )
      _M_reserve(_M_compute_next_size(1));
    _M_construct_null(this->_M_Finish() + 1);
    _Traits::assign(*(this->_M_Finish()), __c);
    ++this->_M_finish;
  }

  void pop_back() {
    _Traits::assign(*(this->_M_Finish() - 1), _M_null());
    --this->_M_finish;
  }

public:
  _Self& assign(const _Self& __s)
  { return _M_assign(__s._M_Start(), __s._M_Finish()); }

  _Self& assign(const _Self& __s,
                size_type __pos, size_type __n) {
    if (__pos > __s.size())
      this->_M_throw_out_of_range();
    return _M_assign(__s._M_Start() + __pos,
                     __s._M_Start() + __pos + (min) (__n, __s.size() - __pos));
  }

  _Self& assign(const _CharT* __s, size_type __n)
  { return _M_assign(__s, __s + __n); }

  _Self& assign(const _CharT* __s)
  { return _M_assign(__s, __s + _Traits::length(__s)); }

  _Self& assign(size_type __n, _CharT __c);

private:
  _Self& _M_assign(const _CharT* __f, const _CharT* __l);



  template <class _Integer>
  _Self& _M_assign_dispatch(_Integer __n, _Integer __x, const __true_type& )
  { return assign((size_type) __n, (_CharT) __x); }

  template <class _InputIter>
  _Self& _M_assign_dispatch(_InputIter __f, _InputIter __l, const __false_type& ) {
    pointer __cur = this->_M_Start();
    while (__f != __l && __cur != this->_M_Finish()) {
      _Traits::assign(*__cur, *__f);
      ++__f;
      ++__cur;
    }
    if (__f == __l)
      erase(__cur, this->end());
    else
      _M_appendT(__f, __l, typename ::stlpmtx_std::iterator_traits< _InputIter >::iterator_category());
    return *this;
  }

public:


  template <class _InputIter>
  _Self& assign(_InputIter __first, _InputIter __last) {
    typedef typename _IsIntegral<_InputIter>::_Ret _Integral;
    return _M_assign_dispatch(__first, __last, _Integral());
  }
# 607 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
public:
  _Self& insert(size_type __pos, const _Self& __s) {
    if (__pos > size())
      this->_M_throw_out_of_range();
    if (__s.size() > max_size() - size())
      this->_M_throw_length_error();
    _M_insert(begin() + __pos, __s._M_Start(), __s._M_Finish(), &__s == this);
    return *this;
  }

  _Self& insert(size_type __pos, const _Self& __s,
                size_type __beg, size_type __n) {
    if (__pos > size() || __beg > __s.size())
      this->_M_throw_out_of_range();
    size_type __len = (min) (__n, __s.size() - __beg);
    if (__len > max_size() - size())
      this->_M_throw_length_error();
    _M_insert(begin() + __pos,
              __s._M_Start() + __beg, __s._M_Start() + __beg + __len, &__s == this);
    return *this;
  }
  _Self& insert(size_type __pos, const _CharT* __s, size_type __n) {
   
    if (__pos > size())
      this->_M_throw_out_of_range();
    if (__n > max_size() - size())
      this->_M_throw_length_error();
    _M_insert(begin() + __pos, __s, __s + __n, _M_inside(__s));
    return *this;
  }

  _Self& insert(size_type __pos, const _CharT* __s) {
   
    if (__pos > size())
      this->_M_throw_out_of_range();
    size_type __len = _Traits::length(__s);
    if (__len > max_size() - size())
      this->_M_throw_length_error();
    _M_insert(this->_M_Start() + __pos, __s, __s + __len, _M_inside(__s));
    return *this;
  }

  _Self& insert(size_type __pos, size_type __n, _CharT __c) {
    if (__pos > size())
      this->_M_throw_out_of_range();
    if (__n > max_size() - size())
      this->_M_throw_length_error();
    insert(begin() + __pos, __n, __c);
    return *this;
  }

  iterator insert(iterator __p, _CharT __c) {
   
    if (__p == end()) {
      push_back(__c);
      return this->_M_Finish() - 1;
    }
    else
      return _M_insert_aux(__p, __c);
  }

  void insert(iterator __p, size_t __n, _CharT __c);

private:
  void _M_insert(iterator __p, const _CharT* __first, const _CharT* __last, bool __self_ref);

  pointer _M_insert_aux(pointer, _CharT);

  void _M_copy(const _CharT* __f, const _CharT* __l, _CharT* __res) {
   
   
    _Traits::copy(__res, __f, __l - __f);
  }

  void _M_move(const _CharT* __f, const _CharT* __l, _CharT* __res) {
   
    _Traits::move(__res, __f, __l - __f);
  }



  template <class _ForwardIter>
  void _M_insert_overflow(iterator __pos, _ForwardIter __first, _ForwardIter __last,
                          size_type __n) {
    size_type __len = _M_compute_next_size(__n);
    pointer __new_start = this->_M_start_of_storage.allocate(__len, __len);
    pointer __new_finish = uninitialized_copy(this->_M_Start(), __pos, __new_start);
    __new_finish = uninitialized_copy(__first, __last, __new_finish);
    __new_finish = uninitialized_copy(__pos, this->_M_Finish(), __new_finish);
    _M_construct_null(__new_finish);
    this->_M_deallocate_block();
    this->_M_reset(__new_start, __new_finish, __new_start + __len);
  }

  template <class _InputIter>
  void _M_insertT(iterator __p, _InputIter __first, _InputIter __last,
                  const input_iterator_tag &) {
    for ( ; __first != __last; ++__first) {
      __p = insert(__p, *__first);
      ++__p;
    }
  }

  template <class _ForwardIter>
  void _M_insertT(iterator __pos, _ForwardIter __first, _ForwardIter __last,
                  const forward_iterator_tag &) {
    if (__first != __last) {
      size_type __n = ::stlpmtx_std::distance(__first, __last);
      if (__n < this->_M_rest()) {
        const size_type __elems_after = this->_M_finish - __pos;
        if (__elems_after >= __n) {
          uninitialized_copy((this->_M_Finish() - __n) + 1, this->_M_Finish() + 1, this->_M_Finish() + 1);
          this->_M_finish += __n;
          _Traits::move(__pos + __n, __pos, (__elems_after - __n) + 1);
          _M_copyT(__first, __last, __pos);
        }
        else {
          pointer __old_finish = this->_M_Finish();
          _ForwardIter __mid = __first;
          ::stlpmtx_std::advance(__mid, __elems_after + 1);
          ::stlpmtx_std::uninitialized_copy(__mid, __last, this->_M_Finish() + 1);
          this->_M_finish += __n - __elems_after;
          uninitialized_copy(__pos, __old_finish + 1, this->_M_Finish());
          this->_M_finish += __elems_after;
          _M_copyT(__first, __mid, __pos);
        }
      }
      else {
        _M_insert_overflow(__pos, __first, __last, __n);
      }
    }
  }

  template <class _Integer>
  void _M_insert_dispatch(iterator __p, _Integer __n, _Integer __x,
                          const __true_type& )
  { insert(__p, (size_type) __n, (_CharT) __x); }

  template <class _InputIter>
  void _M_insert_dispatch(iterator __p, _InputIter __first, _InputIter __last,
                          const __false_type& ) {
   

    const _Self __self(__first, __last, get_allocator());
    _M_insertT(__p, __self.begin(), __self.end(), forward_iterator_tag());
  }

  template <class _InputIterator>
  void _M_copyT(_InputIterator __first, _InputIterator __last, pointer __result) {
   
    for ( ; __first != __last; ++__first, ++__result)
      _Traits::assign(*__result, *__first);
  }


  void _M_copyT(const _CharT* __f, const _CharT* __l, _CharT* __res) {
   
   
    _Traits::copy(__res, __f, __l - __f);
  }

public:


  template <class _InputIter>
  void insert(iterator __p, _InputIter __first, _InputIter __last) {
    typedef typename _IsIntegral<_InputIter>::_Ret _Integral;
    _M_insert_dispatch(__p, __first, __last, _Integral());
  }




public:
  void insert(iterator __p, const _CharT* __f, const _CharT* __l) {
   
    _M_insert(__p, __f, __l, _M_inside(__f));
  }


public:
  _Self& erase(size_type __pos = 0, size_type __n = npos) {
    if (__pos > size())
      this->_M_throw_out_of_range();
    erase(begin() + __pos, begin() + __pos + (min) (__n, size() - __pos));
    return *this;
  }

  iterator erase(iterator __pos) {

    _Traits::move(__pos, __pos + 1, this->_M_Finish() - __pos);
    --this->_M_finish;
    return __pos;
  }

  iterator erase(iterator __first, iterator __last) {
    if (__first != __last) {

      traits_type::move(__first, __last, (this->_M_Finish() - __last) + 1);
      this->_M_finish = this->_M_Finish() - (__last - __first);
    }
    return __first;
  }

public:

  _Self& replace(size_type __pos, size_type __n, const _Self& __s) {
    const size_type __size = size();
    if (__pos > __size)
      this->_M_throw_out_of_range();
    const size_type __len = (min) (__n, __size - __pos);
    if (__s.size() > max_size() - (__size - __len))
      this->_M_throw_length_error();
    return _M_replace(begin() + __pos, begin() + __pos + __len,
                      __s._M_Start(), __s._M_Finish(), &__s == this);
  }

  _Self& replace(size_type __pos1, size_type __n1, const _Self& __s,
                 size_type __pos2, size_type __n2) {
    const size_type __size1 = size();
    const size_type __size2 = __s.size();
    if (__pos1 > __size1 || __pos2 > __size2)
      this->_M_throw_out_of_range();
    const size_type __len1 = (min) (__n1, __size1 - __pos1);
    const size_type __len2 = (min) (__n2, __size2 - __pos2);
    if (__len2 > max_size() - (__size1 - __len1))
      this->_M_throw_length_error();
    return _M_replace(begin() + __pos1, begin() + __pos1 + __len1,
                      __s._M_Start() + __pos2, __s._M_Start() + __pos2 + __len2, &__s == this);
  }

  _Self& replace(size_type __pos, size_type __n1,
                 const _CharT* __s, size_type __n2) {
   
    const size_type __size = size();
    if (__pos > __size)
      this->_M_throw_out_of_range();
    const size_type __len = (min) (__n1, __size - __pos);
    if (__n2 > max_size() - (__size - __len))
      this->_M_throw_length_error();
    return _M_replace(begin() + __pos, begin() + __pos + __len,
                      __s, __s + __n2, _M_inside(__s));
  }

  _Self& replace(size_type __pos, size_type __n1, const _CharT* __s) {
   
    return replace(__pos, __n1, __s, _Traits::length(__s));
  }

  _Self& replace(size_type __pos, size_type __n1,
                 size_type __n2, _CharT __c) {
    const size_type __size = size();
    if (__pos > __size)
      this->_M_throw_out_of_range();
    const size_type __len = (min) (__n1, __size - __pos);
    if (__n2 > max_size() - (__size - __len))
      this->_M_throw_length_error();
    return replace(begin() + __pos, begin() + __pos + __len, __n2, __c);
  }

  _Self& replace(iterator __first, iterator __last, const _Self& __s) {
   
    return _M_replace(__first, __last, __s._M_Start(), __s._M_Finish(), &__s == this);
  }

  _Self& replace(iterator __first, iterator __last,
                 const _CharT* __s, size_type __n) {
   
   
    return _M_replace(__first, __last, __s, __s + __n, _M_inside(__s));
  }

  _Self& replace(iterator __first, iterator __last,
                 const _CharT* __s) {
   
   
    return _M_replace(__first, __last, __s, __s + _Traits::length(__s), _M_inside(__s));
  }

  _Self& replace(iterator __first, iterator __last, size_type __n, _CharT __c);

private:
  _Self& _M_replace(iterator __first, iterator __last,
                    const _CharT* __f, const _CharT* __l, bool __self_ref);


  template <class _Integer>
  _Self& _M_replace_dispatch(iterator __first, iterator __last,
                             _Integer __n, _Integer __x, const __true_type& ) {
   
    return replace(__first, __last, (size_type) __n, (_CharT) __x);
  }

  template <class _InputIter>
  _Self& _M_replace_dispatch(iterator __first, iterator __last,
                             _InputIter __f, _InputIter __l, const __false_type& ) {
   

    const _Self __self(__f, __l, get_allocator());
    return _M_replace(__first, __last, __self._M_Start(), __self._M_Finish(), false);
  }

public:


  template <class _InputIter>
  _Self& replace(iterator __first, iterator __last,
                 _InputIter __f, _InputIter __l) {
   
    typedef typename _IsIntegral<_InputIter>::_Ret _Integral;
    return _M_replace_dispatch(__first, __last, __f, __l, _Integral());
  }



public:
  _Self& replace(iterator __first, iterator __last,
                 const _CharT* __f, const _CharT* __l) {
   
   
    return _M_replace(__first, __last, __f, __l, _M_inside(__f));
  }


public:

  size_type copy(_CharT* __s, size_type __n, size_type __pos = 0) const {
   
    if (__pos > size())
      this->_M_throw_out_of_range();
    const size_type __len = (min) (__n, size() - __pos);
    _Traits::copy(__s, this->_M_Start() + __pos, __len);
    return __len;
  }

  void swap(_Self& __s) { this->_M_swap(__s); }




public:

  const _CharT* c_str() const { return this->_M_Start(); }
  const _CharT* data() const { return this->_M_Start(); }

public:
  size_type find(const _Self& __s, size_type __pos = 0) const
  { return find(__s._M_Start(), __pos, __s.size()); }

  size_type find(const _CharT* __s, size_type __pos = 0) const
  { return find(__s, __pos, _Traits::length(__s)); }

  size_type find(const _CharT* __s, size_type __pos, size_type __n) const;


  size_type find(_CharT __c) const { return find(__c, 0); }
  size_type find(_CharT __c, size_type __pos ) const;

public:
  size_type rfind(const _Self& __s, size_type __pos = npos) const
  { return rfind(__s._M_Start(), __pos, __s.size()); }

  size_type rfind(const _CharT* __s, size_type __pos = npos) const
  { return rfind(__s, __pos, _Traits::length(__s)); }

  size_type rfind(const _CharT* __s, size_type __pos, size_type __n) const;
  size_type rfind(_CharT __c, size_type __pos = npos) const;

public:
  size_type find_first_of(const _Self& __s, size_type __pos = 0) const
  { return find_first_of(__s._M_Start(), __pos, __s.size()); }

  size_type find_first_of(const _CharT* __s, size_type __pos = 0) const
  { return find_first_of(__s, __pos, _Traits::length(__s)); }

  size_type find_first_of(const _CharT* __s, size_type __pos, size_type __n) const;

  size_type find_first_of(_CharT __c, size_type __pos = 0) const
  { return find(__c, __pos); }

public:
  size_type find_last_of(const _Self& __s, size_type __pos = npos) const
  { return find_last_of(__s._M_Start(), __pos, __s.size()); }

  size_type find_last_of(const _CharT* __s, size_type __pos = npos) const
  { return find_last_of(__s, __pos, _Traits::length(__s)); }

  size_type find_last_of(const _CharT* __s, size_type __pos, size_type __n) const;

  size_type find_last_of(_CharT __c, size_type __pos = npos) const
  { return rfind(__c, __pos); }

public:
  size_type find_first_not_of(const _Self& __s, size_type __pos = 0) const
  { return find_first_not_of(__s._M_Start(), __pos, __s.size()); }

  size_type find_first_not_of(const _CharT* __s, size_type __pos = 0) const
  { return find_first_not_of(__s, __pos, _Traits::length(__s)); }

  size_type find_first_not_of(const _CharT* __s, size_type __pos, size_type __n) const;

  size_type find_first_not_of(_CharT __c, size_type __pos = 0) const;

public:
  size_type find_last_not_of(const _Self& __s, size_type __pos = npos) const
  { return find_last_not_of(__s._M_Start(), __pos, __s.size()); }

  size_type find_last_not_of(const _CharT* __s, size_type __pos = npos) const
  { return find_last_not_of(__s, __pos, _Traits::length(__s)); }

  size_type find_last_not_of(const _CharT* __s, size_type __pos, size_type __n) const;

  size_type find_last_not_of(_CharT __c, size_type __pos = npos) const;

public:
  _Self substr(size_type __pos = 0, size_type __n = npos) const
  { return _Self(*this, __pos, __n, get_allocator()); }

public:
  int compare(const _Self& __s) const
  { return _M_compare(this->_M_Start(), this->_M_Finish(), __s._M_Start(), __s._M_Finish()); }

  int compare(size_type __pos1, size_type __n1, const _Self& __s) const {
    if (__pos1 > size())
      this->_M_throw_out_of_range();
    return _M_compare(this->_M_Start() + __pos1,
                      this->_M_Start() + __pos1 + (min) (__n1, size() - __pos1),
                      __s._M_Start(), __s._M_Finish());
  }

  int compare(size_type __pos1, size_type __n1, const _Self& __s,
              size_type __pos2, size_type __n2) const {
    if (__pos1 > size() || __pos2 > __s.size())
      this->_M_throw_out_of_range();
    return _M_compare(this->_M_Start() + __pos1,
                      this->_M_Start() + __pos1 + (min) (__n1, size() - __pos1),
                      __s._M_Start() + __pos2,
                      __s._M_Start() + __pos2 + (min) (__n2, __s.size() - __pos2));
  }

  int compare(const _CharT* __s) const {
   
    return _M_compare(this->_M_Start(), this->_M_Finish(), __s, __s + _Traits::length(__s));
  }

  int compare(size_type __pos1, size_type __n1, const _CharT* __s) const {
   
    if (__pos1 > size())
      this->_M_throw_out_of_range();
    return _M_compare(this->_M_Start() + __pos1,
                      this->_M_Start() + __pos1 + (min) (__n1, size() - __pos1),
                      __s, __s + _Traits::length(__s));
  }

  int compare(size_type __pos1, size_type __n1, const _CharT* __s, size_type __n2) const {
   
    if (__pos1 > size())
      this->_M_throw_out_of_range();
    return _M_compare(this->_M_Start() + __pos1,
                      this->_M_Start() + __pos1 + (min) (__n1, size() - __pos1),
                      __s, __s + __n2);
  }

public:
  static int _M_compare(const _CharT* __f1, const _CharT* __l1,
                                   const _CharT* __f2, const _CharT* __l2) {
    const ptrdiff_t __n1 = __l1 - __f1;
    const ptrdiff_t __n2 = __l2 - __f2;
    const int cmp = _Traits::compare(__f1, __f2, (min) (__n1, __n2));
    return cmp != 0 ? cmp : (__n1 < __n2 ? -1 : (__n1 > __n2 ? 1 : 0));
  }





};
# 1104 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
}
# 1114 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
namespace stlpmtx_std {





template <class _CharT, class _Traits, class _Alloc>
inline void
swap(basic_string<_CharT,_Traits,_Alloc>& __x,
     basic_string<_CharT,_Traits,_Alloc>& __y)
{ __x.swap(__y); }
# 1135 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
template <class _CharT, class _Traits, class _Alloc>
struct __move_traits<basic_string<_CharT, _Traits, _Alloc> > {
  typedef __true_type implemented;

  typedef typename __move_traits<_Alloc>::complete complete;
};
# 1150 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h"
namespace priv {

template <class _CharT, class _Traits, class _Alloc>
void _S_string_copy(const basic_string<_CharT,_Traits,_Alloc>& __s,
                               _CharT* __buf, size_t __n);







inline const char*
__get_c_string(const string& __str) { return __str.c_str(); }

}

}

# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
namespace stlpmtx_std {







template <class _CharT, class _Traits, class _Alloc>
inline basic_string<_CharT,_Traits,_Alloc>
operator+(const basic_string<_CharT,_Traits,_Alloc>& __s,
          const basic_string<_CharT,_Traits,_Alloc>& __y) {
  typedef basic_string<_CharT,_Traits,_Alloc> _Str;
  typedef typename _Str::_Reserve_t _Reserve_t;


  _Str __result = _Str(_Reserve_t(), __s.size() + __y.size(), __s.get_allocator());



  __result.append(__s);
  __result.append(__y);
  return __result;
}

template <class _CharT, class _Traits, class _Alloc>
inline basic_string<_CharT,_Traits,_Alloc>
operator+(const _CharT* __s,
          const basic_string<_CharT,_Traits,_Alloc>& __y) {
 
  typedef basic_string<_CharT,_Traits,_Alloc> _Str;
  typedef typename _Str::_Reserve_t _Reserve_t;
  const size_t __n = _Traits::length(__s);

  _Str __result = _Str(_Reserve_t(), __n + __y.size(), __y.get_allocator());



  __result.append(__s, __s + __n);
  __result.append(__y);
  return __result;
}

template <class _CharT, class _Traits, class _Alloc>
inline basic_string<_CharT,_Traits,_Alloc>
operator+(_CharT __c,
          const basic_string<_CharT,_Traits,_Alloc>& __y) {
  typedef basic_string<_CharT,_Traits,_Alloc> _Str;
  typedef typename _Str::_Reserve_t _Reserve_t;

  _Str __result = _Str(_Reserve_t(), 1 + __y.size(), __y.get_allocator());



  __result.push_back(__c);
  __result.append(__y);
  return __result;
}

template <class _CharT, class _Traits, class _Alloc>
inline basic_string<_CharT,_Traits,_Alloc>
operator+(const basic_string<_CharT,_Traits,_Alloc>& __x,
          const _CharT* __s) {
 
  typedef basic_string<_CharT,_Traits,_Alloc> _Str;
  typedef typename _Str::_Reserve_t _Reserve_t;
  const size_t __n = _Traits::length(__s);

  _Str __result = _Str(_Reserve_t(), __x.size() + __n, __x.get_allocator());



  __result.append(__x);
  __result.append(__s, __s + __n);
  return __result;
}

template <class _CharT, class _Traits, class _Alloc>
inline basic_string<_CharT,_Traits,_Alloc>
operator+(const basic_string<_CharT,_Traits,_Alloc>& __x,
          const _CharT __c) {
  typedef basic_string<_CharT,_Traits,_Alloc> _Str;
  typedef typename _Str::_Reserve_t _Reserve_t;

  _Str __result = _Str(_Reserve_t(), __x.size() + 1, __x.get_allocator());



  __result.append(__x);
  __result.push_back(__c);
  return __result;
}
# 285 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator==(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const basic_string<_CharT,_Traits,_Alloc>& __y) {
  return __x.size() == __y.size() && _Traits::compare(__x.data(), __y.data(), __x.size()) == 0;
}
# 309 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator==(const _CharT* __s,
           const basic_string<_CharT,_Traits,_Alloc>& __y) {
 
  size_t __n = _Traits::length(__s);
  return __n == __y.size() && _Traits::compare(__s, __y.data(), __n) == 0;
}

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator==(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const _CharT* __s) {
 
  size_t __n = _Traits::length(__s);
  return __x.size() == __n && _Traits::compare(__x.data(), __s, __n) == 0;
}
# 349 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator<(const basic_string<_CharT,_Traits,_Alloc>& __x,
          const basic_string<_CharT,_Traits,_Alloc>& __y) {
  return basic_string<_CharT,_Traits,_Alloc> ::_M_compare(__x.begin(), __x.end(),
                                                          __y.begin(), __y.end()) < 0;
}
# 375 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator<(const _CharT* __s,
          const basic_string<_CharT,_Traits,_Alloc>& __y) {
 
  size_t __n = _Traits::length(__s);
  return basic_string<_CharT,_Traits,_Alloc> ::_M_compare(__s, __s + __n,
                                                          __y.begin(), __y.end()) < 0;
}

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator<(const basic_string<_CharT,_Traits,_Alloc>& __x,
          const _CharT* __s) {
 
  size_t __n = _Traits::length(__s);
  return basic_string<_CharT,_Traits,_Alloc> ::_M_compare(__x.begin(), __x.end(),
                                                          __s, __s + __n) < 0;
}
# 423 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator!=(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const basic_string<_CharT,_Traits,_Alloc>& __y)
{ return !(__x == __y); }

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator>(const basic_string<_CharT,_Traits,_Alloc>& __x,
          const basic_string<_CharT,_Traits,_Alloc>& __y)
{ return __y < __x; }

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator<=(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const basic_string<_CharT,_Traits,_Alloc>& __y)
{ return !(__y < __x); }

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator>=(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const basic_string<_CharT,_Traits,_Alloc>& __y)
{ return !(__x < __y); }
# 463 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator!=(const _CharT* __s,
           const basic_string<_CharT,_Traits,_Alloc>& __y) {
 
  return !(__s == __y);
}

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator!=(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const _CharT* __s) {
 
  return !(__x == __s);
}
# 497 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator>(const _CharT* __s,
          const basic_string<_CharT,_Traits,_Alloc>& __y) {
 
  return __y < __s;
}

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator>(const basic_string<_CharT,_Traits,_Alloc>& __x,
          const _CharT* __s) {
 
  return __s < __x;
}
# 531 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator<=(const _CharT* __s,
           const basic_string<_CharT,_Traits,_Alloc>& __y) {
 
  return !(__y < __s);
}

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator<=(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const _CharT* __s) {
 
  return !(__s < __x);
}
# 565 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
template <class _CharT, class _Traits, class _Alloc>
inline bool
operator>=(const _CharT* __s,
           const basic_string<_CharT,_Traits,_Alloc>& __y) {
 
  return !(__s < __y);
}

template <class _CharT, class _Traits, class _Alloc>
inline bool
operator>=(const basic_string<_CharT,_Traits,_Alloc>& __x,
           const _CharT* __s) {
 
  return !(__x < __s);
}
# 599 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_operators.h"
}
# 1170 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.c" 1
# 32 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.c"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_ctraits_fns.h" 1
# 28 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_ctraits_fns.h"
namespace stlpmtx_std {

namespace priv {

template <class _Traits>
struct _Eq_traits
  : public binary_function<typename _Traits::char_type,
                           typename _Traits::char_type,
                           bool> {
  bool operator()(const typename _Traits::char_type& __x,
                  const typename _Traits::char_type& __y) const
  { return _Traits::eq(__x, __y); }
};

template <class _Traits>
struct _Eq_char_bound
  : public unary_function<typename _Traits::char_type, bool> {
  typename _Traits::char_type __val;
  _Eq_char_bound(typename _Traits::char_type __c) : __val(__c) {}
  bool operator()(const typename _Traits::char_type& __x) const
  { return _Traits::eq(__x, __val); }
};

template <class _Traits>
struct _Neq_char_bound
  : public unary_function<typename _Traits::char_type, bool>
{
  typename _Traits::char_type __val;
  _Neq_char_bound(typename _Traits::char_type __c) : __val(__c) {}
  bool operator()(const typename _Traits::char_type& __x) const
  { return !_Traits::eq(__x, __val); }
};

template <class _Traits>
struct _Eq_int_bound
  : public unary_function<typename _Traits::char_type, bool> {
  typename _Traits::int_type __val;

  _Eq_int_bound(typename _Traits::int_type __c) : __val(__c) {}
  bool operator()(const typename _Traits::char_type& __x) const
  { return _Traits::eq_int_type(_Traits::to_int_type(__x), __val); }
};
# 83 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_ctraits_fns.h"
}

}
# 33 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.c" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function.h" 1
# 41 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function.h"
namespace stlpmtx_std {

template <class _Tp>
struct not_equal_to : public binary_function<_Tp, _Tp, bool> {
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x != __y; }
};

template <class _Tp>
struct greater : public binary_function<_Tp, _Tp, bool> {
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x > __y; }
};

template <class _Tp>
struct greater_equal : public binary_function<_Tp, _Tp, bool> {
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x >= __y; }
};

template <class _Tp>
struct less_equal : public binary_function<_Tp, _Tp, bool> {
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x <= __y; }
};

template <class _Tp>
struct divides : public binary_function<_Tp, _Tp, _Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x / __y; }
};

template <class _Tp>
struct modulus : public binary_function<_Tp, _Tp, _Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x % __y; }
};

template <class _Tp>
struct negate : public unary_function<_Tp, _Tp> {
  _Tp operator()(const _Tp& __x) const { return -__x; }
};

template <class _Tp>
struct logical_and : public binary_function<_Tp, _Tp, bool> {
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x && __y; }
};

template <class _Tp>
struct logical_or : public binary_function<_Tp, _Tp,bool> {
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x || __y; }
};

template <class _Tp>
struct logical_not : public unary_function<_Tp, bool> {
  bool operator()(const _Tp& __x) const { return !__x; }
};



template <class _Tp> inline _Tp identity_element(plus<_Tp>) { return _Tp(0); }
template <class _Tp> inline _Tp identity_element(multiplies<_Tp>) { return _Tp(1); }
# 135 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function.h"
template <class _Predicate>
class unary_negate
    : public unary_function<typename _Predicate::argument_type, bool> {
  typedef unary_function<typename _Predicate::argument_type, bool> _Base;
public:
  typedef typename _Base::argument_type argument_type;
private:
  typedef typename __call_traits<argument_type>::const_param_type _ArgParamType;
protected:
  _Predicate _M_pred;
public:
  explicit unary_negate(const _Predicate& __x) : _M_pred(__x) {}
  bool operator()(_ArgParamType __x) const {
    return !_M_pred(__x);
  }
};

template <class _Predicate>
inline unary_negate<_Predicate>
not1(const _Predicate& __pred) {
  return unary_negate<_Predicate>(__pred);
}

template <class _Predicate>
class binary_negate
    : public binary_function<typename _Predicate::first_argument_type,
                             typename _Predicate::second_argument_type,
                             bool> {
  typedef binary_function<typename _Predicate::first_argument_type,
                          typename _Predicate::second_argument_type,
                          bool> _Base;
public:
  typedef typename _Base::first_argument_type first_argument_type;
  typedef typename _Base::second_argument_type second_argument_type;
private:
  typedef typename __call_traits<first_argument_type>::const_param_type _FstArgParamType;
  typedef typename __call_traits<second_argument_type>::const_param_type _SndArgParamType;
protected:
  _Predicate _M_pred;
public:
  explicit binary_negate(const _Predicate& __x) : _M_pred(__x) {}
  bool operator()(_FstArgParamType __x, _SndArgParamType __y) const {
    return !_M_pred(__x, __y);
  }
};

template <class _Predicate>
inline binary_negate<_Predicate>
not2(const _Predicate& __pred) {
  return binary_negate<_Predicate>(__pred);
}

template <class _Operation>
class binder1st :
    public unary_function<typename _Operation::second_argument_type,
                          typename _Operation::result_type > {
  typedef unary_function<typename _Operation::second_argument_type,
                         typename _Operation::result_type > _Base;
public:
  typedef typename _Base::argument_type argument_type;
  typedef typename _Base::result_type result_type;
private:
  typedef typename __call_traits<argument_type>::param_type _ArgParamType;
  typedef typename __call_traits<argument_type>::const_param_type _ConstArgParamType;
  typedef typename __call_traits<typename _Operation::first_argument_type>::const_param_type _ValueParamType;
protected:

  _Operation op;
  typename _Operation::first_argument_type _M_value;
public:
  binder1st(const _Operation& __x, _ValueParamType __y)
    : op(__x), _M_value(__y) {}

  result_type operator()(_ConstArgParamType __x) const
  { return op(_M_value, __x); }

  result_type operator()(_ArgParamType __x) const
  { return op(_M_value, __x); }
};

template <class _Operation, class _Tp>
inline binder1st<_Operation>
bind1st(const _Operation& __fn, const _Tp& __x) {
  typedef typename _Operation::first_argument_type _Arg1_type;
  return binder1st<_Operation>(__fn, _Arg1_type(__x));
}

template <class _Operation>
class binder2nd
  : public unary_function<typename _Operation::first_argument_type,
                          typename _Operation::result_type> {
  typedef unary_function<typename _Operation::first_argument_type,
                         typename _Operation::result_type> _Base;
public:
  typedef typename _Base::argument_type argument_type;
  typedef typename _Base::result_type result_type;
private:
  typedef typename __call_traits<argument_type>::param_type _ArgParamType;
  typedef typename __call_traits<argument_type>::const_param_type _ConstArgParamType;
  typedef typename __call_traits<typename _Operation::second_argument_type>::const_param_type _ValueParamType;
protected:

  _Operation op;
  typename _Operation::second_argument_type value;
public:
  binder2nd(const _Operation& __x, _ValueParamType __y)
      : op(__x), value(__y) {}

  result_type operator()(_ConstArgParamType __x) const
  { return op(__x, value); }

  result_type operator()(_ArgParamType __x) const
  { return op(__x, value); }
};

template <class _Operation, class _Tp>
inline binder2nd<_Operation>
bind2nd(const _Operation& __fn, const _Tp& __x) {
  typedef typename _Operation::second_argument_type _Arg2_type;
  return binder2nd<_Operation>(__fn, _Arg2_type(__x));
}




template <class _Operation1, class _Operation2>
class unary_compose :
  public unary_function<typename _Operation2::argument_type,
                        typename _Operation1::result_type> {
  typedef unary_function<typename _Operation2::argument_type,
                         typename _Operation1::result_type> _Base;
public:
  typedef typename _Base::argument_type argument_type;
  typedef typename _Base::result_type result_type;
private:
  typedef typename __call_traits<argument_type>::const_param_type _ArgParamType;
protected:
  _Operation1 _M_fn1;
  _Operation2 _M_fn2;
public:
  unary_compose(const _Operation1& __x, const _Operation2& __y)
    : _M_fn1(__x), _M_fn2(__y) {}

  result_type operator()(_ArgParamType __x) const {
    return _M_fn1(_M_fn2(__x));
  }
};

template <class _Operation1, class _Operation2>
inline unary_compose<_Operation1,_Operation2>
compose1(const _Operation1& __fn1, const _Operation2& __fn2) {
  return unary_compose<_Operation1,_Operation2>(__fn1, __fn2);
}

template <class _Operation1, class _Operation2, class _Operation3>
class binary_compose :
    public unary_function<typename _Operation2::argument_type,
                          typename _Operation1::result_type> {
  typedef unary_function<typename _Operation2::argument_type,
                         typename _Operation1::result_type> _Base;
public:
  typedef typename _Base::argument_type argument_type;
  typedef typename _Base::result_type result_type;
private:
  typedef typename __call_traits<argument_type>::const_param_type _ArgParamType;
protected:
  _Operation1 _M_fn1;
  _Operation2 _M_fn2;
  _Operation3 _M_fn3;
public:
  binary_compose(const _Operation1& __x, const _Operation2& __y,
                 const _Operation3& __z)
    : _M_fn1(__x), _M_fn2(__y), _M_fn3(__z) { }

  result_type operator()(_ArgParamType __x) const {
    return _M_fn1(_M_fn2(__x), _M_fn3(__x));
  }
};

template <class _Operation1, class _Operation2, class _Operation3>
inline binary_compose<_Operation1, _Operation2, _Operation3>
compose2(const _Operation1& __fn1, const _Operation2& __fn2,
         const _Operation3& __fn3) {
  return binary_compose<_Operation1,_Operation2,_Operation3>(__fn1, __fn2, __fn3);
}


template <class _Tp> struct identity : public ::stlpmtx_std::priv:: _Identity<_Tp> {};

template <class _Pair> struct select1st : public ::stlpmtx_std::priv:: _Select1st<_Pair> {};
template <class _Pair> struct select2nd : public ::stlpmtx_std::priv:: _Select2nd<_Pair> {};

template <class _Arg1, class _Arg2>
struct project1st : public ::stlpmtx_std::priv:: _Project1st<_Arg1, _Arg2> {};

template <class _Arg1, class _Arg2>
struct project2nd : public ::stlpmtx_std::priv:: _Project2nd<_Arg1, _Arg2> {};






namespace priv {

template <class _Result>
struct _Constant_void_fun {
  typedef _Result result_type;
  result_type _M_val;

  _Constant_void_fun(const result_type& __v) : _M_val(__v) {}
  const result_type& operator()() const { return _M_val; }
};

}

template <class _Result>
struct constant_void_fun : public ::stlpmtx_std::priv:: _Constant_void_fun<_Result> {
  constant_void_fun(const _Result& __v)
    : ::stlpmtx_std::priv:: _Constant_void_fun<_Result>(__v) {}
};

template <class _Result, class _Argument = _Result >
struct constant_unary_fun : public ::stlpmtx_std::priv:: _Constant_unary_fun<_Result, _Argument> {
  constant_unary_fun(const _Result& __v)
    : ::stlpmtx_std::priv:: _Constant_unary_fun<_Result, _Argument>(__v) {}
};

template <class _Result, class _Arg1 = _Result, class _Arg2 = _Arg1 >
struct constant_binary_fun
  : public ::stlpmtx_std::priv:: _Constant_binary_fun<_Result, _Arg1, _Arg2> {
  constant_binary_fun(const _Result& __v)
    : ::stlpmtx_std::priv:: _Constant_binary_fun<_Result, _Arg1, _Arg2>(__v) {}
};

template <class _Result>
inline constant_void_fun<_Result> constant0(const _Result& __val) {
  return constant_void_fun<_Result>(__val);
}

template <class _Result>
inline constant_unary_fun<_Result,_Result> constant1(const _Result& __val) {
  return constant_unary_fun<_Result,_Result>(__val);
}

template <class _Result>
inline constant_binary_fun<_Result,_Result,_Result>
constant2(const _Result& __val) {
  return constant_binary_fun<_Result,_Result,_Result>(__val);
}



class subtractive_rng : public unary_function<unsigned long, unsigned long> {
private:
  unsigned long _M_table[55];
  unsigned long _M_index1;
  unsigned long _M_index2;
public:
  unsigned long operator()(unsigned long __limit) {
    _M_index1 = (_M_index1 + 1) % 55;
    _M_index2 = (_M_index2 + 1) % 55;
    _M_table[_M_index1] = _M_table[_M_index1] - _M_table[_M_index2];
    return _M_table[_M_index1] % __limit;
  }

  void _M_initialize(unsigned long __seed) {
    unsigned long __k = 1;
    _M_table[54] = __seed;
    unsigned long __i;
    for (__i = 0; __i < 54; __i++) {
        unsigned long __ii = (21 * (__i + 1) % 55) - 1;
        _M_table[__ii] = __k;
        __k = __seed - __k;
        __seed = _M_table[__ii];
    }
    for (int __loop = 0; __loop < 4; __loop++) {
        for (__i = 0; __i < 55; __i++)
            _M_table[__i] = _M_table[__i] - _M_table[(1 + __i + 30) % 55];
    }
    _M_index1 = 0;
    _M_index2 = 31;
  }

  subtractive_rng(unsigned int __seed) { _M_initialize(__seed); }
  subtractive_rng() { _M_initialize(161803398ul); }
};



}

# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function_adaptors.h" 1
# 58 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function_adaptors.h"
namespace stlpmtx_std {
# 498 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function_adaptors.h"
template <class _Ret, class _Tp>
class mem_fun_t : public unary_function<_Tp*,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(void);
public:
  explicit mem_fun_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(_Tp* __p) const { return (__p->*_M_f)(); }
private:
  __fun_type _M_f;
};

template <class _Ret, class _Tp>
class const_mem_fun_t : public unary_function<const _Tp*,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(void) const;
public:
  explicit const_mem_fun_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(const _Tp* __p) const { return (__p->*_M_f)(); }
private:
  __fun_type _M_f;
};

template <class _Ret, class _Tp>
class mem_fun_ref_t : public unary_function<_Tp,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(void);
public:
  explicit mem_fun_ref_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(_Tp& __r) const { return (__r.*_M_f)(); }
private:
  __fun_type _M_f;
};

template <class _Ret, class _Tp>
class const_mem_fun_ref_t : public unary_function<_Tp,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(void) const;
public:
  explicit const_mem_fun_ref_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(const _Tp& __r) const { return (__r.*_M_f)(); }
private:
  __fun_type _M_f;
};

template <class _Ret, class _Tp, class _Arg>
class mem_fun1_t : public binary_function<_Tp*,_Arg,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(_Arg);
public:
  explicit mem_fun1_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(_Tp* __p, _Arg __x) const { return (__p->*_M_f)(__x); }
private:
  __fun_type _M_f;
};

template <class _Ret, class _Tp, class _Arg>
class const_mem_fun1_t : public binary_function<const _Tp*,_Arg,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(_Arg) const;
public:
  explicit const_mem_fun1_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(const _Tp* __p, _Arg __x) const
    { return (__p->*_M_f)(__x); }
private:
  __fun_type _M_f;
};

template <class _Ret, class _Tp, class _Arg>
class mem_fun1_ref_t : public binary_function<_Tp,_Arg,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(_Arg);
public:
  explicit mem_fun1_ref_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(_Tp& __r, _Arg __x) const { return (__r.*_M_f)(__x); }
private:
  __fun_type _M_f;
};

template <class _Ret, class _Tp, class _Arg>
class const_mem_fun1_ref_t : public binary_function<_Tp,_Arg,_Ret> {
  typedef _Ret (_Tp::*__fun_type)(_Arg) const;
public:
  explicit const_mem_fun1_ref_t(__fun_type __pf) : _M_f(__pf) {}
  _Ret operator()(const _Tp& __r, _Arg __x) const { return (__r.*_M_f)(__x); }
private:
  __fun_type _M_f;
};

template <class _Arg, class _Result>
class pointer_to_unary_function : public unary_function<_Arg, _Result> {
protected:
  _Result (*_M_ptr)(_Arg);
public:
  pointer_to_unary_function() {}
  explicit pointer_to_unary_function(_Result (*__x)(_Arg)) : _M_ptr(__x) {}
  _Result operator()(_Arg __x) const { return _M_ptr(__x); }
};

template <class _Arg1, class _Arg2, class _Result>
class pointer_to_binary_function :
  public binary_function<_Arg1,_Arg2,_Result> {
protected:
    _Result (*_M_ptr)(_Arg1, _Arg2);
public:
    pointer_to_binary_function() {}
    explicit pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2))
      : _M_ptr(__x) {}
    _Result operator()(_Arg1 __x, _Arg2 __y) const {
      return _M_ptr(__x, __y);
    }
};
# 718 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function_adaptors.h"
template <class _Result, class _Tp>
inline mem_fun_t<_Result,_Tp>
mem_fun(_Result (_Tp::*__f)()) { return mem_fun_t<_Result,_Tp>(__f); }

template <class _Result, class _Tp>
inline const_mem_fun_t<_Result,_Tp>
mem_fun(_Result (_Tp::*__f)() const) { return const_mem_fun_t<_Result,_Tp>(__f); }

template <class _Result, class _Tp>
inline mem_fun_ref_t<_Result,_Tp>
mem_fun_ref(_Result (_Tp::*__f)()) { return mem_fun_ref_t<_Result,_Tp>(__f); }

template <class _Result, class _Tp>
inline const_mem_fun_ref_t<_Result,_Tp>
mem_fun_ref(_Result (_Tp::*__f)() const) { return const_mem_fun_ref_t<_Result,_Tp>(__f); }

template <class _Result, class _Tp, class _Arg>
inline mem_fun1_t<_Result,_Tp,_Arg>
mem_fun(_Result (_Tp::*__f)(_Arg)) { return mem_fun1_t<_Result,_Tp,_Arg>(__f); }

template <class _Result, class _Tp, class _Arg>
inline const_mem_fun1_t<_Result,_Tp,_Arg>
mem_fun(_Result (_Tp::*__f)(_Arg) const) { return const_mem_fun1_t<_Result,_Tp,_Arg>(__f); }

template <class _Result, class _Tp, class _Arg>
inline mem_fun1_ref_t<_Result,_Tp,_Arg>
mem_fun_ref(_Result (_Tp::*__f)(_Arg)) { return mem_fun1_ref_t<_Result,_Tp,_Arg>(__f); }

template <class _Result, class _Tp, class _Arg>
inline const_mem_fun1_ref_t<_Result,_Tp,_Arg>
mem_fun_ref(_Result (_Tp::*__f)(_Arg) const) { return const_mem_fun1_ref_t<_Result,_Tp,_Arg>(__f); }




template <class _Result, class _Tp, class _Arg>
inline mem_fun1_t<_Result,_Tp,_Arg>
mem_fun1(_Result (_Tp::*__f)(_Arg)) { return mem_fun1_t<_Result,_Tp,_Arg>(__f); }

template <class _Result, class _Tp, class _Arg>
inline const_mem_fun1_t<_Result,_Tp,_Arg>
mem_fun1(_Result (_Tp::*__f)(_Arg) const) { return const_mem_fun1_t<_Result,_Tp,_Arg>(__f); }

template <class _Result, class _Tp, class _Arg>
inline mem_fun1_ref_t<_Result,_Tp,_Arg>
mem_fun1_ref(_Result (_Tp::*__f)(_Arg)) { return mem_fun1_ref_t<_Result,_Tp,_Arg>(__f); }

template <class _Result, class _Tp, class _Arg>
inline const_mem_fun1_ref_t<_Result,_Tp,_Arg>
mem_fun1_ref(_Result (_Tp::*__f)(_Arg) const) { return const_mem_fun1_ref_t<_Result,_Tp,_Arg>(__f); }





template <class _Arg, class _Result>
inline pointer_to_unary_function<_Arg, _Result>
ptr_fun(_Result (*__f)(_Arg))
{ return pointer_to_unary_function<_Arg, _Result>(__f); }

template <class _Arg1, class _Arg2, class _Result>
inline pointer_to_binary_function<_Arg1,_Arg2,_Result>
ptr_fun(_Result (*__f)(_Arg1, _Arg2))
{ return pointer_to_binary_function<_Arg1,_Arg2,_Result>(__f); }

}
# 428 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_function.h" 2
# 37 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.c" 2
# 53 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.c"
namespace stlpmtx_std {

namespace priv {


template <class _Traits>
struct _Not_within_traits : public unary_function<typename _Traits::char_type, bool> {
  typedef typename _Traits::char_type _CharT;
  const _CharT* _M_first;
  const _CharT* _M_last;

  _Not_within_traits(const _CharT* __f, const _CharT* __l)
    : _M_first(__f), _M_last(__l) {}

  bool operator()(const _CharT& __x) const {
    return find_if(_M_first, _M_last,
                   ::stlpmtx_std::priv:: _Eq_char_bound<_Traits>(__x)) == _M_last;
  }
};

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_of_aux(_InputIter __first1, _InputIter __last1,
                                          const _CharT* __first2, const _CharT* __last2,
                                          _Traits*, const __true_type& )
{ return __find_first_of(__first1, __last1, __first2, __last2); }

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_of_aux(_InputIter __first1, _InputIter __last1,
                                          const _CharT* __first2, const _CharT* __last2,
                                          _Traits*, const __false_type& )
{ return __find_first_of(__first1, __last1, __first2, __last2, ::stlpmtx_std::priv:: _Eq_traits<_Traits>()); }

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_of(_InputIter __first1, _InputIter __last1,
                                      const _CharT* __first2, const _CharT* __last2,
                                      _Traits* __traits) {

  typedef typename _IsSTLportClass<_Traits>::_Ret _STLportTraits;




  return __str_find_first_of_aux(__first1, __last1, __first2, __last2, __traits, _STLportTraits());
}

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_not_of_aux3(_InputIter __first1, _InputIter __last1,
                                               const _CharT* __first2, const _CharT* __last2,
                                               _Traits* , const __true_type& __useStrcspnLikeAlgo)
{ return __find_first_of_aux2(__first1, __last1, __first2, __last2, __first2, not1(_Identity<bool>()), __useStrcspnLikeAlgo); }

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_not_of_aux3(_InputIter __first1, _InputIter __last1,
                                               const _CharT* __first2, const _CharT* __last2,
                                               _Traits* , const __false_type& )
{ return ::stlpmtx_std::find_if(__first1, __last1, ::stlpmtx_std::priv:: _Not_within_traits<_Traits>(__first2, __last2)); }

template <class _InputIter, class _CharT, class _Tp, class _Traits>
inline _InputIter __str_find_first_not_of_aux2(_InputIter __first1, _InputIter __last1,
                                               const _CharT* __first2, const _CharT* __last2,
                                               _Tp* __pt, _Traits* __traits) {
  typedef typename _IsIntegral<_Tp>::_Ret _IsIntegral;
  typedef typename _IsCharLikeType<_CharT>::_Ret _IsCharLike;
  typedef typename _Land2<_IsIntegral, _IsCharLike>::_Ret _UseStrcspnLikeAlgo;
  return __str_find_first_not_of_aux3(__first1, __last1, __first2, __last2, __traits, _UseStrcspnLikeAlgo());
}

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_not_of_aux1(_InputIter __first1, _InputIter __last1,
                                               const _CharT* __first2, const _CharT* __last2,
                                               _Traits* __traits, const __true_type& )
{ return __str_find_first_not_of_aux2(__first1, __last1, __first2, __last2,
                                      (typename ::stlpmtx_std::iterator_traits< _InputIter >::value_type*)0, __traits); }

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_not_of_aux1(_InputIter __first1, _InputIter __last1,
                                               const _CharT* __first2, const _CharT* __last2,
                                               _Traits*, const __false_type& )
{ return ::stlpmtx_std::find_if(__first1, __last1, ::stlpmtx_std::priv:: _Not_within_traits<_Traits>(__first2, __last2)); }

template <class _InputIter, class _CharT, class _Traits>
inline _InputIter __str_find_first_not_of(_InputIter __first1, _InputIter __last1,
                                          const _CharT* __first2, const _CharT* __last2,
                                          _Traits* __traits) {

  typedef typename _IsSTLportClass<_Traits>::_Ret _STLportTraits;




  return __str_find_first_not_of_aux1(__first1, __last1, __first2, __last2, __traits, _STLportTraits());
}





}






template <class _CharT, class _Traits, class _Alloc>
void basic_string<_CharT,_Traits,_Alloc>::reserve(size_type __res_arg) {
  if (__res_arg > max_size())
    this->_M_throw_length_error();

  size_type __n = (max)(__res_arg, size()) + 1;
  if (__n < this->_M_capacity())
    return;

  _M_reserve(__n);
}

template <class _CharT, class _Traits, class _Alloc>
void basic_string<_CharT,_Traits,_Alloc>::_M_reserve(size_type __n) {
  pointer __new_start = this->_M_start_of_storage.allocate(__n, __n);
  pointer __new_finish = ::stlpmtx_std::priv:: __ucopy(this->_M_Start(), this->_M_Finish(), __new_start);
  _M_construct_null(__new_finish);
  this->_M_deallocate_block();
  this->_M_reset(__new_start, __new_finish, __new_start + __n);
}

template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT,_Traits,_Alloc>&
basic_string<_CharT,_Traits,_Alloc>::append(size_type __n, _CharT __c) {
  if (__n > 0) {
    if (__n > max_size() - size())
      this->_M_throw_length_error();
    if (__n >= this->_M_rest())
      _M_reserve(_M_compute_next_size(__n));
    ::stlpmtx_std::priv:: __uninitialized_fill_n(this->_M_finish + 1, __n - 1, __c);
    _M_construct_null(this->_M_finish + __n);
    _Traits::assign(*end(), __c);
    this->_M_finish += __n;
  }
  return *this;
}

template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>&
basic_string<_CharT, _Traits, _Alloc>::_M_append(const _CharT* __first, const _CharT* __last) {
  if (__first != __last) {
    size_type __n = static_cast<size_type>(__last - __first);
    if (__n >= this->_M_rest()) {
      size_type __len = _M_compute_next_size(__n);
      pointer __new_start = this->_M_start_of_storage.allocate(__len, __len);
      pointer __new_finish = ::stlpmtx_std::priv:: __ucopy(this->_M_Start(), this->_M_Finish(), __new_start);
      __new_finish = ::stlpmtx_std::priv:: __ucopy(__first, __last, __new_finish);
      _M_construct_null(__new_finish);
      this->_M_deallocate_block();
      this->_M_reset(__new_start, __new_finish, __new_start + __len);
    }
    else {
      const _CharT* __f1 = __first;
      ++__f1;
      ::stlpmtx_std::priv:: __ucopy(__f1, __last, this->_M_finish + 1);
      _M_construct_null(this->_M_finish + __n);
      _Traits::assign(*end(), *__first);
      this->_M_finish += __n;
    }
  }
  return *this;
}

template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT,_Traits,_Alloc>&
basic_string<_CharT,_Traits,_Alloc>::assign(size_type __n, _CharT __c) {
  if (__n <= size()) {
    _Traits::assign(this->_M_Start(), __n, __c);
    erase(begin() + __n, end());
  }
  else {
    if (__n < capacity()) {
      _Traits::assign(this->_M_Start(), size(), __c);
      append(__n - size(), __c);
    }
    else {
      _Self __str(__n, __c);
      this->swap(__str);
    }
  }
  return *this;
}

template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT,_Traits,_Alloc>&
basic_string<_CharT,_Traits,_Alloc>::_M_assign(const _CharT* __f, const _CharT* __l) {
  ptrdiff_t __n = __l - __f;
  if (static_cast<size_type>(__n) <= size()) {
    _Traits::copy(this->_M_Start(), __f, __n);
    erase(begin() + __n, end());
  }
  else {
    _Traits::copy(this->_M_Start(), __f, size());
    _M_append(__f + size(), __l);
  }
  return *this;
}

template <class _CharT, class _Traits, class _Alloc>
_CharT* basic_string<_CharT,_Traits,_Alloc> ::_M_insert_aux(_CharT* __p,
                                                            _CharT __c) {
  pointer __new_pos = __p;
  if (this->_M_rest() > 1 ) {
    _M_construct_null(this->_M_finish + 1);
    _Traits::move(__p + 1, __p, this->_M_finish - __p);
    _Traits::assign(*__p, __c);
    ++this->_M_finish;
  }
  else {
    size_type __len = _M_compute_next_size(1);
    pointer __new_start = this->_M_start_of_storage.allocate(__len, __len);
    __new_pos = ::stlpmtx_std::priv:: __ucopy(this->_M_Start(), __p, __new_start);
    _Traits::assign(*__new_pos, __c);
    pointer __new_finish = __new_pos + 1;
    __new_finish = ::stlpmtx_std::priv:: __ucopy(__p, this->_M_finish, __new_finish);
    _M_construct_null(__new_finish);
    this->_M_deallocate_block();
    this->_M_reset(__new_start, __new_finish, __new_start + __len);
  }
  return __new_pos;
}

template <class _CharT, class _Traits, class _Alloc>
void basic_string<_CharT,_Traits,_Alloc>::insert(iterator __pos,
                                                 size_t __n, _CharT __c) {
  if (__n != 0) {
    if (this->_M_rest() > __n) {
      const size_type __elems_after = this->_M_finish - __pos;
      pointer __old_finish = this->_M_finish;
      if (__elems_after >= __n) {
        ::stlpmtx_std::priv:: __ucopy((this->_M_finish - __n) + 1, this->_M_finish + 1, this->_M_finish + 1);
        this->_M_finish += __n;
        _Traits::move(__pos + __n, __pos, (__elems_after - __n) + 1);
        _Traits::assign(__pos, __n, __c);
      }
      else {
        ::stlpmtx_std::priv:: __uninitialized_fill_n(this->_M_finish + 1, __n - __elems_after - 1, __c);
        this->_M_finish += __n - __elems_after;
        ::stlpmtx_std::priv:: __ucopy(__pos, __old_finish + 1, this->_M_finish);
        this->_M_finish += __elems_after;
        _Traits::assign(__pos, __elems_after + 1, __c);
      }
    }
    else {
      size_type __len = _M_compute_next_size(__n);
      pointer __new_start = this->_M_start_of_storage.allocate(__len, __len);
      pointer __new_finish = ::stlpmtx_std::priv:: __ucopy(this->_M_Start(), __pos, __new_start);
      __new_finish = ::stlpmtx_std::priv:: __uninitialized_fill_n(__new_finish, __n, __c);
      __new_finish = ::stlpmtx_std::priv:: __ucopy(__pos, this->_M_finish, __new_finish);
      _M_construct_null(__new_finish);
      this->_M_deallocate_block();
      this->_M_reset(__new_start, __new_finish, __new_start + __len);
    }
  }
}

template <class _CharT, class _Traits, class _Alloc>
void basic_string<_CharT,_Traits,_Alloc>::_M_insert(iterator __pos,
                                                    const _CharT* __first, const _CharT* __last,
                                                    bool __self_ref) {

  if (__first != __last) {
    const size_t __n = __last - __first;
    if (this->_M_rest() > __n) {
      const size_t __elems_after = this->_M_finish - __pos;
      pointer __old_finish = this->_M_finish;
      if (__elems_after >= __n) {
        ::stlpmtx_std::priv:: __ucopy((this->_M_finish - __n) + 1, this->_M_finish + 1, this->_M_finish + 1);
        this->_M_finish += __n;
        _Traits::move(__pos + __n, __pos, (__elems_after - __n) + 1);
        if (!__self_ref || __last < __pos) {
          _M_copy(__first, __last, __pos);
        }
        else {

          if (__first >= __pos) {

            __first += __n;
            __last += __n;
            _M_copy(__first, __last, __pos);
          }
          else {

            _M_move(__first, __last, __pos);
          }
        }
      }
      else {
        const_iterator __mid = __first;
        __mid += __elems_after + 1;
        ::stlpmtx_std::priv:: __ucopy(__mid, __last, this->_M_finish + 1);
        this->_M_finish += __n - __elems_after;
        ::stlpmtx_std::priv:: __ucopy(__pos, __old_finish + 1, this->_M_finish);
        this->_M_finish += __elems_after;
        if (!__self_ref)
          _M_copy(__first, __mid, __pos);
        else
          _M_move(__first, __mid, __pos);
      }
    }
    else {
      size_type __len = _M_compute_next_size(__n);
      pointer __new_start = this->_M_start_of_storage.allocate(__len, __len);
      pointer __new_finish = ::stlpmtx_std::priv:: __ucopy(this->_M_Start(), __pos, __new_start);
      __new_finish = ::stlpmtx_std::priv:: __ucopy(__first, __last, __new_finish);
      __new_finish = ::stlpmtx_std::priv:: __ucopy(__pos, this->_M_finish, __new_finish);
      _M_construct_null(__new_finish);
      this->_M_deallocate_block();
      this->_M_reset(__new_start, __new_finish, __new_start + __len);
    }
  }
}

template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT,_Traits,_Alloc>&
basic_string<_CharT,_Traits,_Alloc> ::replace(iterator __first, iterator __last,
                                              size_type __n, _CharT __c) {
  size_type __len = (size_type)(__last - __first);

  if (__len >= __n) {
    _Traits::assign(__first, __n, __c);
    erase(__first + __n, __last);
  }
  else {
    _Traits::assign(__first, __len, __c);
    insert(__last, __n - __len, __c);
  }
  return *this;
}

template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT,_Traits,_Alloc>&
basic_string<_CharT,_Traits,_Alloc> ::_M_replace(iterator __first, iterator __last,
                                                 const _CharT* __f, const _CharT* __l,
                                                 bool __self_ref) {
  const ptrdiff_t __n = __l - __f;
  const difference_type __len = __last - __first;
  if (__len >= __n) {
    if (!__self_ref || __l < __first || __f >= __last)
      _M_copy(__f, __l, __first);
    else
      _M_move(__f, __l, __first);
    erase(__first + __n, __last);
  } else if (!__self_ref || (__f >= __last) || (__l <= __first)) {
    const_iterator __m = __f + __len;
    _M_copy(__f, __m, __first);
    _M_insert(__last, __m, __l, __self_ref );
  } else if (__f < __first) {
    const_iterator __m = __f + __len;

    const difference_type __off_dest = __first - this->begin();
    const difference_type __off_src = __f - this->begin();
    _M_insert(__last, __m, __l, true);
    _Traits::move(begin() + __off_dest, begin() + __off_src, __len);
  } else {
    const_iterator __m = __f + __len;
    _Traits::move(__first, __f, __len);
    _M_insert(__last, __m, __l, true);
  }
  return *this;
}

template <class _CharT, class _Traits, class _Alloc>
typename basic_string<_CharT,_Traits,_Alloc>::size_type basic_string<_CharT,_Traits,_Alloc>::find( const _CharT* __s, size_type __pos,
                                                         size_type __n) const
{
  const size_t __len = size();
  if (__pos >= __len || __pos + __n > __len) {
    if ( __n == 0 && __pos <= __len ) {
      return __pos;
    }
    return npos;
  }

  const_pointer __result =
    ::stlpmtx_std::search(this->_M_Start() + __pos, this->_M_Finish(),
                      __s, __s + __n, ::stlpmtx_std::priv:: _Eq_traits<_Traits>());
  return __result != this->_M_Finish() ? __result - this->_M_Start() : npos;
}

template <class _CharT, class _Traits, class _Alloc>
typename basic_string<_CharT,_Traits,_Alloc>::size_type basic_string<_CharT,_Traits,_Alloc>::find(_CharT __c, size_type __pos) const
{
  if (__pos >= size()) {
    return npos;
  }

  const_pointer __result =
    ::stlpmtx_std::find_if(this->_M_Start() + __pos, this->_M_Finish(),
                       ::stlpmtx_std::priv:: _Eq_char_bound<_Traits>(__c));
  return __result != this->_M_Finish() ? __result - this->_M_Start() : npos;
}

template <class _CharT, class _Traits, class _Alloc>
typename basic_string<_CharT,_Traits,_Alloc>::size_type basic_string<_CharT,_Traits,_Alloc>::rfind(const _CharT* __s, size_type __pos,
                                                         size_type __n) const
{
  const size_type __len = size();
  if ( __len < __n ) {
    return npos;
  }
  const_pointer __last = this->_M_Start() + (min)( __len - __n, __pos) + __n;
  if ( __n == 0 ) {
    return __last - this->_M_Start();
  }
  const_pointer __result = ::stlpmtx_std::find_end(this->_M_Start(), __last,
                                               __s, __s + __n, ::stlpmtx_std::priv:: _Eq_traits<_Traits>());
  return __result != __last ? __result - this->_M_Start() : npos;
}

template <class _CharT, class _Traits, class _Alloc>
typename basic_string<_CharT,_Traits,_Alloc>::size_type basic_string<_CharT,_Traits,_Alloc>::rfind(_CharT __c, size_type __pos) const
{
  const size_type __len = size();
  if ( __len < 1 ) {
    return npos;
  }
  const_iterator __last = begin() + (min)(__len - 1, __pos) + 1;
  const_reverse_iterator __rresult =
    ::stlpmtx_std::find_if(const_reverse_iterator(__last), rend(),
                       ::stlpmtx_std::priv:: _Eq_char_bound<_Traits>(__c));
  return __rresult != rend() ? (__rresult.base() - 1) - begin() : npos;
}

template <class _CharT, class _Traits, class _Alloc> typename basic_string<_CharT,_Traits,_Alloc>::size_type
basic_string<_CharT,_Traits,_Alloc> ::find_first_of(const _CharT* __s, size_type __pos,
                                                    size_type __n) const {
  if (__pos >= size())
    return npos;
  else {
    const_iterator __result = ::stlpmtx_std::priv:: __str_find_first_of(begin() + __pos, end(),
                                                             __s, __s + __n,
                                                             static_cast<_Traits*>(0));
    return __result != end() ? __result - begin() : npos;
  }
}

template <class _CharT, class _Traits, class _Alloc>
 typename basic_string<_CharT,_Traits,_Alloc>::size_type
basic_string<_CharT,_Traits,_Alloc> ::find_last_of(const _CharT* __s, size_type __pos,
                                                   size_type __n) const
{
  const size_type __len = size();
  if ( __len < 1 ) {
    return npos;
  }
  const const_iterator __last = begin() + (min)(__len - 1, __pos) + 1;
  const const_reverse_iterator __rresult =
    ::stlpmtx_std::priv:: __str_find_first_of(const_reverse_iterator(__last), rend(),
                                   __s, __s + __n,
                                   static_cast<_Traits*>(0));
  return __rresult != rend() ? (__rresult.base() - 1) - begin() : npos;
}


template <class _CharT, class _Traits, class _Alloc> typename basic_string<_CharT,_Traits,_Alloc>::size_type
basic_string<_CharT,_Traits,_Alloc> ::find_first_not_of(const _CharT* __s, size_type __pos,
                                                        size_type __n) const {
  typedef typename _Traits::char_type _CharType;
  if (__pos >= size())
    return npos;
  else {
    const_pointer __result = ::stlpmtx_std::priv:: __str_find_first_not_of(this->_M_Start() + __pos, this->_M_Finish(),
                                                                static_cast<const _CharType*>(__s),
                                                                static_cast<const _CharType*>(__s) + __n,
                                                                static_cast<_Traits*>(0));
    return __result != this->_M_finish ? __result - this->_M_Start() : npos;
  }
}

template <class _CharT, class _Traits, class _Alloc> typename basic_string<_CharT,_Traits,_Alloc>::size_type
basic_string<_CharT,_Traits,_Alloc> ::find_first_not_of(_CharT __c, size_type __pos) const {
  if (1 > size())
    return npos;
  else {
    const_pointer __result = ::stlpmtx_std::find_if(this->_M_Start() + __pos, this->_M_Finish(),
                                                ::stlpmtx_std::priv:: _Neq_char_bound<_Traits>(__c));
    return __result != this->_M_finish ? __result - this->_M_Start() : npos;
  }
}

template <class _CharT, class _Traits, class _Alloc>
typename basic_string<_CharT,_Traits,_Alloc>::size_type
basic_string<_CharT,_Traits,_Alloc>::find_last_not_of(const _CharT* __s, size_type __pos, size_type __n) const
{
  typedef typename _Traits::char_type _CharType;
  const size_type __len = size();
  if ( __len < 1 ) {
    return npos;
  }
  const_iterator __last = begin() + (min)(__len - 1, __pos) + 1;
  const_reverse_iterator __rlast = const_reverse_iterator(__last);
  const_reverse_iterator __rresult =
    ::stlpmtx_std::priv:: __str_find_first_not_of(__rlast, rend(),
                                       static_cast<const _CharType*>(__s),
                                       static_cast<const _CharType*>(__s) + __n,
                                       static_cast<_Traits*>(0));
  return __rresult != rend() ? (__rresult.base() - 1) - begin() : npos;
}

template <class _CharT, class _Traits, class _Alloc>
typename basic_string<_CharT,_Traits,_Alloc>::size_type
basic_string<_CharT, _Traits, _Alloc>::find_last_not_of(_CharT __c, size_type __pos) const
{
  const size_type __len = size();
  if ( __len < 1 ) {
    return npos;
  }
  const_iterator __last = begin() + (min)(__len - 1, __pos) + 1;
  const_reverse_iterator __rlast = const_reverse_iterator(__last);
  const_reverse_iterator __rresult =
    ::stlpmtx_std::find_if(__rlast, rend(),
                       ::stlpmtx_std::priv:: _Neq_char_bound<_Traits>(__c));
  return __rresult != rend() ? (__rresult.base() - 1) - begin() : npos;
}


namespace priv {


template <class _CharT, class _Traits, class _Alloc>
void _S_string_copy(const basic_string<_CharT,_Traits,_Alloc>& __s,
                               _CharT* __buf, size_t __n) {
  if (__n > 0) {
    __n = (min) (__n - 1, __s.size());
    ::stlpmtx_std::copy(__s.begin(), __s.begin() + __n, __buf);
    __buf[__n] = _CharT();
  }
}

}

}

# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.h" 1
# 34 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.h"
namespace stlpmtx_std {
void __stl_throw_runtime_error(const char* __msg);
void __stl_throw_range_error(const char* __msg);
void __stl_throw_out_of_range(const char* __msg);
void __stl_throw_length_error(const char* __msg);
void __stl_throw_invalid_argument(const char* __msg);
void __stl_throw_overflow_error(const char* __msg);
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.h"
}


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.c" 1
# 29 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.c"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept.h" 1
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.h" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_exception.h" 1
# 72 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_exception.h"
namespace stlpmtx_std {


using std::exception;



using std::bad_exception;
# 122 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_exception.h"
using std::terminate;
using std::terminate_handler;
using std::set_terminate;





}
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.h" 2
# 43 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.h"
namespace stlpmtx_std {
# 63 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.h"
using std::exception;




class __Named_exception : public exception {
public:
  __Named_exception(const string& __str);
  __Named_exception(const __Named_exception&);
  __Named_exception& operator = (const __Named_exception&);

  const char* what() const throw();
  ~__Named_exception() throw();

private:
  enum { _S_bufsize = 256 };
  char _M_static_name[_S_bufsize];
  char *_M_name;
};



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.c" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.c"
inline __Named_exception::__Named_exception(const string& __str) {
  size_t __size = strlen(::stlpmtx_std::priv:: __get_c_string(__str)) + 1;
  if (__size > _S_bufsize) {
    _M_name = static_cast<char*>(malloc(__size * sizeof(char)));
    if (!_M_name) {
      __size = _S_bufsize;
      _M_name = _M_static_name;
    }
    else {
      *(reinterpret_cast<size_t*>(&_M_static_name[0])) = __size * sizeof(char);
    }
  }
  else {
    _M_name = _M_static_name;
  }

  strncpy(_M_name, ::stlpmtx_std::priv:: __get_c_string(__str), __size - 1);
  _M_name[__size - 1] = '\0';



}

inline __Named_exception::__Named_exception(const __Named_exception& __x) {
  size_t __size = strlen(__x._M_name) + 1;
  if (__size > _S_bufsize) {
    _M_name = static_cast<char*>(malloc(__size * sizeof(char)));
    if (!_M_name) {
      __size = _S_bufsize;
      _M_name = _M_static_name;
    }
    else {
      *(reinterpret_cast<size_t*>(&_M_static_name[0])) = __size * sizeof(char);
    }
  }
  else {
    _M_name = _M_static_name;
  }

  strncpy(_M_name, __x._M_name, __size - 1);
  _M_name[__size - 1] = '\0';



}

inline __Named_exception& __Named_exception::operator = (const __Named_exception& __x) {
  size_t __size = strlen(__x._M_name) + 1;
  size_t __buf_size = _M_name != _M_static_name ? *(reinterpret_cast<size_t*>(&_M_static_name[0])) : _S_bufsize;
  if (__size > __buf_size) {

    if (_M_name != _M_static_name) free(_M_name);
    _M_name = static_cast<char*>(malloc(__size * sizeof(char)));
    if (!_M_name) {
      __size = _S_bufsize;
      _M_name = _M_static_name;
    }
    else {
      *(reinterpret_cast<size_t*>(&_M_static_name[0])) = __size * sizeof(char);
    }
  }

  strncpy(_M_name, __x._M_name, __size - 1);
  _M_name[__size - 1] = '\0';



  return *this;
}

inline __Named_exception::~__Named_exception() throw() {
  if (_M_name != _M_static_name)
    free(_M_name);
}

inline const char* __Named_exception::what() const throw()
{ return _M_name; }
# 86 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept_base.h" 2







}
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_stdexcept.h" 2







namespace stlpmtx_std {

class logic_error : public __Named_exception {
public:
  logic_error(const string& __s) : __Named_exception(__s) {}



};

class runtime_error : public __Named_exception {
public:
  runtime_error(const string& __s) : __Named_exception(__s) {}



};

class domain_error : public logic_error {
public:
  domain_error(const string& __arg) : logic_error(__arg) {}



};

class invalid_argument : public logic_error {
public:
  invalid_argument(const string& __arg) : logic_error(__arg) {}



};

class length_error : public logic_error {
public:
  length_error(const string& __arg) : logic_error(__arg) {}



};

class out_of_range : public logic_error {
public:
  out_of_range(const string& __arg) : logic_error(__arg) {}



};

class range_error : public runtime_error {
public:
  range_error(const string& __arg) : runtime_error(__arg) {}



};

class overflow_error : public runtime_error {
public:
  overflow_error(const string& __arg) : runtime_error(__arg) {}



};

class underflow_error : public runtime_error {
public:
  underflow_error(const string& __arg) : runtime_error(__arg) {}



};

}
# 30 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.c" 2
# 61 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.c"
namespace stlpmtx_std {

inline void __stl_throw_runtime_error(const char* __msg)
{ throw runtime_error(__msg); }

inline void __stl_throw_range_error(const char* __msg)
{ throw range_error(__msg); }

inline void __stl_throw_out_of_range(const char* __msg)
{ throw out_of_range(__msg); }

inline void __stl_throw_length_error(const char* __msg)
{ throw length_error(__msg); }

inline void __stl_throw_invalid_argument(const char* __msg)
{ throw invalid_argument(__msg); }

inline void __stl_throw_overflow_error(const char* __msg)
{ throw overflow_error(__msg); }

}
# 54 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_range_errors.h" 2
# 592 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.c" 2

namespace stlpmtx_std {

namespace priv {


template <class _Tp, class _Alloc>
void _String_base<_Tp,_Alloc>::_M_throw_length_error() const
{ __stl_throw_length_error("basic_string"); }

template <class _Tp, class _Alloc>
void _String_base<_Tp, _Alloc>::_M_throw_out_of_range() const
{ __stl_throw_out_of_range("basic_string"); }

template <class _Tp, class _Alloc>
void _String_base<_Tp, _Alloc>::_M_allocate_block(size_t __n) {
  if ((__n <= (max_size() + 1)) && (__n > 0)) {

    if (__n > _DEFAULT_SIZE) {
      this->_M_start_of_storage._M_data = _M_start_of_storage.allocate(__n, __n);
      this->_M_finish = this->_M_start_of_storage._M_data;
      this->_M_buffers._M_end_of_storage = this->_M_start_of_storage._M_data + __n;
    }





  } else {
    this->_M_throw_length_error();
  }
}


}
# 638 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.c"
template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::basic_string(const _CharT* __s,
                                                    const allocator_type& __a)
  : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__a) {
 
  _M_range_initialize(__s, __s + traits_type::length(__s));
}

template <class _CharT, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::basic_string(const basic_string<_CharT, _Traits, _Alloc> & __s)
  : ::stlpmtx_std::priv:: _String_base<_CharT,_Alloc>(__s.get_allocator())
{ _M_range_initialize(__s._M_Start(), __s._M_Finish()); }







template <class _CharT, class _Traits, class _Alloc>
const size_t basic_string<_CharT, _Traits, _Alloc>::npos;


}
# 1174 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string.h" 2
# 30 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string" 2



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_hash.h" 1
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_hash.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_hash_fun.h" 1
# 38 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_hash_fun.h"
namespace stlpmtx_std {

template <class _Key> struct hash { };

namespace priv {

inline size_t __stl_hash_string(const char* __s) {
 
  unsigned long __h = 0;
  for ( ; *__s; ++__s)
    __h = 5*__h + *__s;

  return size_t(__h);
}

}

template<>
struct hash<char*> {
  size_t operator()(const char* __s) const {
   
    return ::stlpmtx_std::priv:: __stl_hash_string(__s);
  }
};

template<>
struct hash<const char*> {
  size_t operator()(const char* __s) const {
   
    return ::stlpmtx_std::priv:: __stl_hash_string(__s);
  }
};

template<> struct hash<char> {
  size_t operator()(char __x) const { return __x; }
};
template<> struct hash<unsigned char> {
  size_t operator()(unsigned char __x) const { return __x; }
};

template<> struct hash<signed char> {
  size_t operator()(unsigned char __x) const { return __x; }
};

template<> struct hash<short> {
  size_t operator()(short __x) const { return __x; }
};
template<> struct hash<unsigned short> {
  size_t operator()(unsigned short __x) const { return __x; }
};
template<> struct hash<int> {
  size_t operator()(int __x) const { return __x; }
};


template<> struct hash<unsigned int> {
  size_t operator()(unsigned int __x) const { return __x; }
};
# 108 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_hash_fun.h"
template<> struct hash<long> {
  size_t operator()(long __x) const { return __x; }
};
template<> struct hash<unsigned long> {
  size_t operator()(unsigned long __x) const { return __x; }
};


template<> struct hash<long long> {
  size_t operator()(long long x) const { return (size_t)x; }
};
template<> struct hash<unsigned long long> {
  size_t operator()(unsigned long long x) const { return (size_t)x; }
};


template<>
struct hash<void *>
{
    union __vp {
        size_t s;
        void *p;
    };

    size_t operator()(void *__x) const
      {
        __vp vp;
        vp.p = __x;
        return vp.s;
      }
};

}
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_hash.h" 2






namespace stlpmtx_std {

template <class _CharT, class _Traits, class _Alloc>
inline size_t
__stl_string_hash(const basic_string<_CharT,_Traits,_Alloc>& __s) {
  unsigned long __h = 0;
  size_t __len = __s.size();
  const _CharT* __data = __s.data();
  for ( size_t __i = 0; __i < __len; ++__i)
    __h = (__h << 2) + __h + __data[__i];
  return size_t(__h);
}



template <class _CharT, class _Traits, class _Alloc>
struct hash<basic_string<_CharT,_Traits,_Alloc> > {
  size_t operator()(const basic_string<_CharT,_Traits,_Alloc>& __s) const
    { return __stl_string_hash(__s); }
};
# 69 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_string_hash.h"
}
# 34 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string" 2
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string" 2
# 14 "include/ControlTask.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 1






# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 8 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 2
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 2
# 56 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 57 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 2
# 15 "include/ControlTask.h" 2
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
# 16 "include/ControlTask.h" 2
# 1 "include/SensorTask.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 5 "include/SensorTask.h" 2






# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 2
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 2
# 12 "include/SensorTask.h" 2

# 1 "include/Kinematics.h" 1



# 1 "include/Vector.h" 1



class Vector {
    private:

    protected:

    public:
        Vector();
        Vector(const Vector& v);
        Vector(float x, float y, float z);
        float x, y, z;
        Vector operator*(const float& rhs) const;
        Vector operator+(const Vector& rhs) const;
        Vector operator-(const Vector& rhs) const;
};
# 5 "include/Kinematics.h" 2
# 1 "include/Quaternion.h" 1



class Quaternion {
    private:

    protected:

    public:
        Quaternion();
        Quaternion(const Quaternion& q);
        Quaternion(const float real, const float x, const float y, const float z);
        Quaternion(const float real, const Vector& imaginary);
        Quaternion(const float eulerX, const float eulerY, const float eulerZ);
        float r, x, y, z;
        Vector* getNewEuler() const;
        Quaternion operator*(const Quaternion& rhs);
        Quaternion operator*(const float& rhs);
        Quaternion operator/(const float& rhs);
        Quaternion conj();
        float norm();
        void normalize();
        void getMatrix(float matrix[3][3]);
        Vector* getNewSandwich(const Vector* v);
        Quaternion* getNewSlerp(const Quaternion* q2, float t);
};
# 6 "include/Kinematics.h" 2
# 1 "include/Logger.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 5 "include/Logger.h" 2


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 1
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 27 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 59 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 8 "include/Logger.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 9 "include/Logger.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 1
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 35 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 1 3 4
# 20 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
extern "C" {
# 45 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int putchar(int __c);
# 54 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int getchar(void);
# 66 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int puts(const char *__s);
# 83 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
char *gets(char *__s);
# 102 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int sprintf(char *__s, const char *__format, ...);
# 130 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int snprintf(char *__s, size_t __n, const char *__format, ...);
# 166 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int vsnprintf(char *__s, size_t __n, const char *__format, __va_list __arg);
# 412 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int printf(const char *__format, ...);
# 432 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int vprintf(const char *__format, __va_list __arg);
# 461 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int vsprintf(char *__s, const char *__format, __va_list __arg);
# 662 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int scanf(const char *__format, ...);
# 682 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int sscanf(const char *__s, const char *__format, ...);
# 708 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int vscanf(const char *__format, __va_list __arg);
# 732 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
int vsscanf(const char *__s, const char *__format, __va_list __arg);
# 754 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdio.h" 3 4
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
# 36 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
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
# 7 "include/Kinematics.h" 2
# 1 "include/Gps.h" 1





# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 1
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 7 "include/Gps.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 1
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 27 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 59 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 8 "include/Gps.h" 2
# 1 "include/arm_math.h" 1
# 270 "include/arm_math.h"
# 1 "include/core/core_cm4.h" 1
# 43 "include/core/core_cm4.h"
 extern "C" {
# 1771 "include/core/core_cm4.h"
}
# 271 "include/arm_math.h" 2
# 285 "include/arm_math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 1
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 27 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 59 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 286 "include/arm_math.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 287 "include/arm_math.h" 2

extern "C"
{
# 336 "include/arm_math.h"
  typedef enum
  {
    ARM_MATH_SUCCESS = 0,
    ARM_MATH_ARGUMENT_ERROR = -1,
    ARM_MATH_LENGTH_ERROR = -2,
    ARM_MATH_SIZE_MISMATCH = -3,
    ARM_MATH_NANINF = -4,
    ARM_MATH_SINGULAR = -5,
    ARM_MATH_TEST_FAILURE = -6
  } arm_status;




  typedef int8_t q7_t;




  typedef int16_t q15_t;




  typedef int32_t q31_t;




  typedef int64_t q63_t;




  typedef float float32_t;




  typedef double float64_t;
# 434 "include/arm_math.h"
  static inline q31_t clip_q63_to_q31(
  q63_t x)
  {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFFFFFF ^ ((q31_t) (x >> 63)))) : (q31_t) x;
  }




  static inline q15_t clip_q63_to_q15(
  q63_t x)
  {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFF ^ ((q15_t) (x >> 63)))) : (q15_t) (x >> 15);
  }




  static inline q7_t clip_q31_to_q7(
  q31_t x)
  {
    return ((q31_t) (x >> 24) != ((q31_t) x >> 23)) ?
      ((0x7F ^ ((q7_t) (x >> 31)))) : (q7_t) x;
  }




  static inline q15_t clip_q31_to_q15(
  q31_t x)
  {
    return ((q31_t) (x >> 16) != ((q31_t) x >> 15)) ?
      ((0x7FFF ^ ((q15_t) (x >> 31)))) : (q15_t) x;
  }





  static inline q63_t mult32x64(
  q63_t x,
  q31_t y)
  {
    return ((((q63_t) (x & 0x00000000FFFFFFFF) * y) >> 32) +
            (((q63_t) (x >> 32) * y)));
  }
# 516 "include/arm_math.h"
  static inline uint32_t arm_recip_q31(
  q31_t in,
  q31_t * dst,
  q31_t * pRecipTable)
  {

    uint32_t out, tempVal;
    uint32_t index, i;
    uint32_t signBits;

    if(in > 0)
    {
      signBits = __CLZ(in) - 1;
    }
    else
    {
      signBits = __CLZ(-in) - 1;
    }


    in = in << signBits;


    index = (uint32_t) (in >> 24u);
    index = (index & 0x0000003F);


    out = pRecipTable[index];



    for (i = 0u; i < 2u; i++)
    {
      tempVal = (q31_t) (((q63_t) in * out) >> 31u);
      tempVal = 0x7FFFFFFF - tempVal;


      out = (q31_t) clip_q63_to_q31(((q63_t) out * tempVal) >> 30u);
    }


    *dst = out;


    return (signBits + 1u);

  }




  static inline uint32_t arm_recip_q15(
  q15_t in,
  q15_t * dst,
  q15_t * pRecipTable)
  {

    uint32_t out = 0, tempVal = 0;
    uint32_t index = 0, i = 0;
    uint32_t signBits = 0;

    if(in > 0)
    {
      signBits = __CLZ(in) - 17;
    }
    else
    {
      signBits = __CLZ(-in) - 17;
    }


    in = in << signBits;


    index = in >> 8;
    index = (index & 0x0000003F);


    out = pRecipTable[index];



    for (i = 0; i < 2; i++)
    {
      tempVal = (q15_t) (((q31_t) in * out) >> 15);
      tempVal = 0x7FFF - tempVal;

      out = (q15_t) (((q31_t) out * tempVal) >> 14);
    }


    *dst = out;


    return (signBits + 1);

  }
# 1045 "include/arm_math.h"
  typedef struct
  {
    uint16_t numTaps;
    q7_t *pState;
    q7_t *pCoeffs;
  } arm_fir_instance_q7;




  typedef struct
  {
    uint16_t numTaps;
    q15_t *pState;
    q15_t *pCoeffs;
  } arm_fir_instance_q15;




  typedef struct
  {
    uint16_t numTaps;
    q31_t *pState;
    q31_t *pCoeffs;
  } arm_fir_instance_q31;




  typedef struct
  {
    uint16_t numTaps;
    float32_t *pState;
    float32_t *pCoeffs;
  } arm_fir_instance_f32;
# 1091 "include/arm_math.h"
  void arm_fir_q7(
  const arm_fir_instance_q7 * S,
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);
# 1107 "include/arm_math.h"
  void arm_fir_init_q7(
  arm_fir_instance_q7 * S,
  uint16_t numTaps,
  q7_t * pCoeffs,
  q7_t * pState,
  uint32_t blockSize);
# 1123 "include/arm_math.h"
  void arm_fir_q15(
  const arm_fir_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 1137 "include/arm_math.h"
  void arm_fir_fast_q15(
  const arm_fir_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 1154 "include/arm_math.h"
  arm_status arm_fir_init_q15(
  arm_fir_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  uint32_t blockSize);
# 1169 "include/arm_math.h"
  void arm_fir_q31(
  const arm_fir_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 1183 "include/arm_math.h"
  void arm_fir_fast_q31(
  const arm_fir_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 1198 "include/arm_math.h"
  void arm_fir_init_q31(
  arm_fir_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  uint32_t blockSize);
# 1213 "include/arm_math.h"
  void arm_fir_f32(
  const arm_fir_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 1228 "include/arm_math.h"
  void arm_fir_init_f32(
  arm_fir_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  uint32_t blockSize);





  typedef struct
  {
    int8_t numStages;
    q15_t *pState;
    q15_t *pCoeffs;
    int8_t postShift;

  } arm_biquad_casd_df1_inst_q15;





  typedef struct
  {
    uint32_t numStages;
    q31_t *pState;
    q31_t *pCoeffs;
    uint8_t postShift;

  } arm_biquad_casd_df1_inst_q31;




  typedef struct
  {
    uint32_t numStages;
    float32_t *pState;
    float32_t *pCoeffs;


  } arm_biquad_casd_df1_inst_f32;
# 1284 "include/arm_math.h"
  void arm_biquad_cascade_df1_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 1300 "include/arm_math.h"
  void arm_biquad_cascade_df1_init_q15(
  arm_biquad_casd_df1_inst_q15 * S,
  uint8_t numStages,
  q15_t * pCoeffs,
  q15_t * pState,
  int8_t postShift);
# 1317 "include/arm_math.h"
  void arm_biquad_cascade_df1_fast_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 1333 "include/arm_math.h"
  void arm_biquad_cascade_df1_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 1348 "include/arm_math.h"
  void arm_biquad_cascade_df1_fast_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 1364 "include/arm_math.h"
  void arm_biquad_cascade_df1_init_q31(
  arm_biquad_casd_df1_inst_q31 * S,
  uint8_t numStages,
  q31_t * pCoeffs,
  q31_t * pState,
  int8_t postShift);
# 1380 "include/arm_math.h"
  void arm_biquad_cascade_df1_f32(
  const arm_biquad_casd_df1_inst_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 1395 "include/arm_math.h"
  void arm_biquad_cascade_df1_init_f32(
  arm_biquad_casd_df1_inst_f32 * S,
  uint8_t numStages,
  float32_t * pCoeffs,
  float32_t * pState);






  typedef struct
  {
    uint16_t numRows;
    uint16_t numCols;
    float32_t *pData;
  } arm_matrix_instance_f32;





  typedef struct
  {
    uint16_t numRows;
    uint16_t numCols;
    q15_t *pData;

  } arm_matrix_instance_q15;





  typedef struct
  {
    uint16_t numRows;
    uint16_t numCols;
    q31_t *pData;

  } arm_matrix_instance_q31;
# 1448 "include/arm_math.h"
  arm_status arm_mat_add_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst);
# 1462 "include/arm_math.h"
  arm_status arm_mat_add_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst);
# 1476 "include/arm_math.h"
  arm_status arm_mat_add_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);
# 1490 "include/arm_math.h"
  arm_status arm_mat_trans_f32(
  const arm_matrix_instance_f32 * pSrc,
  arm_matrix_instance_f32 * pDst);
# 1503 "include/arm_math.h"
  arm_status arm_mat_trans_q15(
  const arm_matrix_instance_q15 * pSrc,
  arm_matrix_instance_q15 * pDst);
# 1515 "include/arm_math.h"
  arm_status arm_mat_trans_q31(
  const arm_matrix_instance_q31 * pSrc,
  arm_matrix_instance_q31 * pDst);
# 1529 "include/arm_math.h"
  arm_status arm_mat_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst);
# 1544 "include/arm_math.h"
  arm_status arm_mat_mult_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst,
  q15_t * pState);
# 1560 "include/arm_math.h"
  arm_status arm_mat_mult_fast_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst,
  q15_t * pState);
# 1575 "include/arm_math.h"
  arm_status arm_mat_mult_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);
# 1589 "include/arm_math.h"
  arm_status arm_mat_mult_fast_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);
# 1604 "include/arm_math.h"
  arm_status arm_mat_sub_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst);
# 1618 "include/arm_math.h"
  arm_status arm_mat_sub_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
  arm_matrix_instance_q15 * pDst);
# 1632 "include/arm_math.h"
  arm_status arm_mat_sub_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
  arm_matrix_instance_q31 * pDst);
# 1646 "include/arm_math.h"
  arm_status arm_mat_scale_f32(
  const arm_matrix_instance_f32 * pSrc,
  float32_t scale,
  arm_matrix_instance_f32 * pDst);
# 1661 "include/arm_math.h"
  arm_status arm_mat_scale_q15(
  const arm_matrix_instance_q15 * pSrc,
  q15_t scaleFract,
  int32_t shift,
  arm_matrix_instance_q15 * pDst);
# 1677 "include/arm_math.h"
  arm_status arm_mat_scale_q31(
  const arm_matrix_instance_q31 * pSrc,
  q31_t scaleFract,
  int32_t shift,
  arm_matrix_instance_q31 * pDst);
# 1693 "include/arm_math.h"
  void arm_mat_init_q31(
  arm_matrix_instance_q31 * S,
  uint16_t nRows,
  uint16_t nColumns,
  q31_t * pData);
# 1708 "include/arm_math.h"
  void arm_mat_init_q15(
  arm_matrix_instance_q15 * S,
  uint16_t nRows,
  uint16_t nColumns,
  q15_t * pData);
# 1723 "include/arm_math.h"
  void arm_mat_init_f32(
  arm_matrix_instance_f32 * S,
  uint16_t nRows,
  uint16_t nColumns,
  float32_t * pData);






  typedef struct
  {
    q15_t A0;




    q31_t A1;

    q15_t state[3];
    q15_t Kp;
    q15_t Ki;
    q15_t Kd;
  } arm_pid_instance_q15;




  typedef struct
  {
    q31_t A0;
    q31_t A1;
    q31_t A2;
    q31_t state[3];
    q31_t Kp;
    q31_t Ki;
    q31_t Kd;

  } arm_pid_instance_q31;




  typedef struct
  {
    float32_t A0;
    float32_t A1;
    float32_t A2;
    float32_t state[3];
    float32_t Kp;
    float32_t Ki;
    float32_t Kd;
  } arm_pid_instance_f32;
# 1786 "include/arm_math.h"
  void arm_pid_init_f32(
  arm_pid_instance_f32 * S,
  int32_t resetStateFlag);






  void arm_pid_reset_f32(
  arm_pid_instance_f32 * S);
# 1805 "include/arm_math.h"
  void arm_pid_init_q31(
  arm_pid_instance_q31 * S,
  int32_t resetStateFlag);
# 1816 "include/arm_math.h"
  void arm_pid_reset_q31(
  arm_pid_instance_q31 * S);







  void arm_pid_init_q15(
  arm_pid_instance_q15 * S,
  int32_t resetStateFlag);






  void arm_pid_reset_q15(
  arm_pid_instance_q15 * S);





  typedef struct
  {
    uint32_t nValues;
    float32_t x1;
    float32_t xSpacing;
    float32_t *pYData;
  } arm_linear_interp_instance_f32;





  typedef struct
  {
    uint16_t numRows;
    uint16_t numCols;
    float32_t *pData;
  } arm_bilinear_interp_instance_f32;





  typedef struct
  {
    uint16_t numRows;
    uint16_t numCols;
    q31_t *pData;
  } arm_bilinear_interp_instance_q31;





  typedef struct
  {
    uint16_t numRows;
    uint16_t numCols;
    q15_t *pData;
  } arm_bilinear_interp_instance_q15;





  typedef struct
  {
    uint16_t numRows;
    uint16_t numCols;
    q7_t *pData;
  } arm_bilinear_interp_instance_q7;
# 1903 "include/arm_math.h"
  void arm_mult_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  uint32_t blockSize);
# 1918 "include/arm_math.h"
  void arm_mult_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t blockSize);
# 1933 "include/arm_math.h"
  void arm_mult_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t blockSize);
# 1948 "include/arm_math.h"
  void arm_mult_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t blockSize);
# 1963 "include/arm_math.h"
  typedef struct
  {
    uint16_t fftLen;
    uint8_t ifftFlag;
    uint8_t bitReverseFlag;
    q15_t *pTwiddle;
    uint16_t *pBitRevTable;
    uint16_t twidCoefModifier;
    uint16_t bitRevFactor;
  } arm_cfft_radix2_instance_q15;

  arm_status arm_cfft_radix2_init_q15(
  arm_cfft_radix2_instance_q15 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

  void arm_cfft_radix2_q15(
  const arm_cfft_radix2_instance_q15 * S,
  q15_t * pSrc);







  typedef struct
  {
    uint16_t fftLen;
    uint8_t ifftFlag;
    uint8_t bitReverseFlag;
    q15_t *pTwiddle;
    uint16_t *pBitRevTable;
    uint16_t twidCoefModifier;
    uint16_t bitRevFactor;
  } arm_cfft_radix4_instance_q15;

  arm_status arm_cfft_radix4_init_q15(
  arm_cfft_radix4_instance_q15 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

  void arm_cfft_radix4_q15(
  const arm_cfft_radix4_instance_q15 * S,
  q15_t * pSrc);





  typedef struct
  {
    uint16_t fftLen;
    uint8_t ifftFlag;
    uint8_t bitReverseFlag;
    q31_t *pTwiddle;
    uint16_t *pBitRevTable;
    uint16_t twidCoefModifier;
    uint16_t bitRevFactor;
  } arm_cfft_radix2_instance_q31;

  arm_status arm_cfft_radix2_init_q31(
  arm_cfft_radix2_instance_q31 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);

  void arm_cfft_radix2_q31(
  const arm_cfft_radix2_instance_q31 * S,
  q31_t * pSrc);





  typedef struct
  {
    uint16_t fftLen;
    uint8_t ifftFlag;
    uint8_t bitReverseFlag;
    q31_t *pTwiddle;
    uint16_t *pBitRevTable;
    uint16_t twidCoefModifier;
    uint16_t bitRevFactor;
  } arm_cfft_radix4_instance_q31;


  void arm_cfft_radix4_q31(
  const arm_cfft_radix4_instance_q31 * S,
  q31_t * pSrc);

  arm_status arm_cfft_radix4_init_q31(
  arm_cfft_radix4_instance_q31 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);





  typedef struct
  {
    uint16_t fftLen;
    uint8_t ifftFlag;
    uint8_t bitReverseFlag;
    float32_t *pTwiddle;
    uint16_t *pBitRevTable;
    uint16_t twidCoefModifier;
    uint16_t bitRevFactor;
    float32_t onebyfftLen;
  } arm_cfft_radix2_instance_f32;


  arm_status arm_cfft_radix2_init_f32(
  arm_cfft_radix2_instance_f32 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);


  void arm_cfft_radix2_f32(
  const arm_cfft_radix2_instance_f32 * S,
  float32_t * pSrc);





  typedef struct
  {
    uint16_t fftLen;
    uint8_t ifftFlag;
    uint8_t bitReverseFlag;
    float32_t *pTwiddle;
    uint16_t *pBitRevTable;
    uint16_t twidCoefModifier;
    uint16_t bitRevFactor;
    float32_t onebyfftLen;
  } arm_cfft_radix4_instance_f32;


  arm_status arm_cfft_radix4_init_f32(
  arm_cfft_radix4_instance_f32 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);


  void arm_cfft_radix4_f32(
  const arm_cfft_radix4_instance_f32 * S,
  float32_t * pSrc);





  typedef struct
  {
    uint16_t fftLen;
    const float32_t *pTwiddle;
    const uint16_t *pBitRevTable;
    uint16_t bitRevLength;
  } arm_cfft_instance_f32;

  void arm_cfft_f32(
  const arm_cfft_instance_f32 * S,
  float32_t * p1,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag);





  typedef struct
  {
    uint32_t fftLenReal;
    uint32_t fftLenBy2;
    uint8_t ifftFlagR;
    uint8_t bitReverseFlagR;
    uint32_t twidCoefRModifier;
    q15_t *pTwiddleAReal;
    q15_t *pTwiddleBReal;
    arm_cfft_radix4_instance_q15 *pCfft;
  } arm_rfft_instance_q15;

  arm_status arm_rfft_init_q15(
  arm_rfft_instance_q15 * S,
  arm_cfft_radix4_instance_q15 * S_CFFT,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag);

  void arm_rfft_q15(
  const arm_rfft_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst);





  typedef struct
  {
    uint32_t fftLenReal;
    uint32_t fftLenBy2;
    uint8_t ifftFlagR;
    uint8_t bitReverseFlagR;
    uint32_t twidCoefRModifier;
    q31_t *pTwiddleAReal;
    q31_t *pTwiddleBReal;
    arm_cfft_radix4_instance_q31 *pCfft;
  } arm_rfft_instance_q31;

  arm_status arm_rfft_init_q31(
  arm_rfft_instance_q31 * S,
  arm_cfft_radix4_instance_q31 * S_CFFT,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag);

  void arm_rfft_q31(
  const arm_rfft_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst);





  typedef struct
  {
    uint32_t fftLenReal;
    uint16_t fftLenBy2;
    uint8_t ifftFlagR;
    uint8_t bitReverseFlagR;
    uint32_t twidCoefRModifier;
    float32_t *pTwiddleAReal;
    float32_t *pTwiddleBReal;
    arm_cfft_radix4_instance_f32 *pCfft;
  } arm_rfft_instance_f32;

  arm_status arm_rfft_init_f32(
  arm_rfft_instance_f32 * S,
  arm_cfft_radix4_instance_f32 * S_CFFT,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag);

  void arm_rfft_f32(
  const arm_rfft_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst);





typedef struct
  {
    arm_cfft_instance_f32 Sint;
    uint16_t fftLenRFFT;
 float32_t * pTwiddleRFFT;
  } arm_rfft_fast_instance_f32 ;

arm_status arm_rfft_fast_init_f32 (
 arm_rfft_fast_instance_f32 * S,
 uint16_t fftLen);

void arm_rfft_fast_f32(
  arm_rfft_fast_instance_f32 * S,
  float32_t * p, float32_t * pOut,
  uint8_t ifftFlag);





  typedef struct
  {
    uint16_t N;
    uint16_t Nby2;
    float32_t normalize;
    float32_t *pTwiddle;
    float32_t *pCosFactor;
    arm_rfft_instance_f32 *pRfft;
    arm_cfft_radix4_instance_f32 *pCfft;
  } arm_dct4_instance_f32;
# 2266 "include/arm_math.h"
  arm_status arm_dct4_init_f32(
  arm_dct4_instance_f32 * S,
  arm_rfft_instance_f32 * S_RFFT,
  arm_cfft_radix4_instance_f32 * S_CFFT,
  uint16_t N,
  uint16_t Nby2,
  float32_t normalize);
# 2282 "include/arm_math.h"
  void arm_dct4_f32(
  const arm_dct4_instance_f32 * S,
  float32_t * pState,
  float32_t * pInlineBuffer);





  typedef struct
  {
    uint16_t N;
    uint16_t Nby2;
    q31_t normalize;
    q31_t *pTwiddle;
    q31_t *pCosFactor;
    arm_rfft_instance_q31 *pRfft;
    arm_cfft_radix4_instance_q31 *pCfft;
  } arm_dct4_instance_q31;
# 2313 "include/arm_math.h"
  arm_status arm_dct4_init_q31(
  arm_dct4_instance_q31 * S,
  arm_rfft_instance_q31 * S_RFFT,
  arm_cfft_radix4_instance_q31 * S_CFFT,
  uint16_t N,
  uint16_t Nby2,
  q31_t normalize);
# 2329 "include/arm_math.h"
  void arm_dct4_q31(
  const arm_dct4_instance_q31 * S,
  q31_t * pState,
  q31_t * pInlineBuffer);





  typedef struct
  {
    uint16_t N;
    uint16_t Nby2;
    q15_t normalize;
    q15_t *pTwiddle;
    q15_t *pCosFactor;
    arm_rfft_instance_q15 *pRfft;
    arm_cfft_radix4_instance_q15 *pCfft;
  } arm_dct4_instance_q15;
# 2360 "include/arm_math.h"
  arm_status arm_dct4_init_q15(
  arm_dct4_instance_q15 * S,
  arm_rfft_instance_q15 * S_RFFT,
  arm_cfft_radix4_instance_q15 * S_CFFT,
  uint16_t N,
  uint16_t Nby2,
  q15_t normalize);
# 2376 "include/arm_math.h"
  void arm_dct4_q15(
  const arm_dct4_instance_q15 * S,
  q15_t * pState,
  q15_t * pInlineBuffer);
# 2390 "include/arm_math.h"
  void arm_add_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t blockSize);
# 2405 "include/arm_math.h"
  void arm_add_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  uint32_t blockSize);
# 2420 "include/arm_math.h"
  void arm_add_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t blockSize);
# 2435 "include/arm_math.h"
  void arm_add_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t blockSize);
# 2450 "include/arm_math.h"
  void arm_sub_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t blockSize);
# 2465 "include/arm_math.h"
  void arm_sub_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  uint32_t blockSize);
# 2480 "include/arm_math.h"
  void arm_sub_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t blockSize);
# 2495 "include/arm_math.h"
  void arm_sub_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t blockSize);
# 2510 "include/arm_math.h"
  void arm_scale_f32(
  float32_t * pSrc,
  float32_t scale,
  float32_t * pDst,
  uint32_t blockSize);
# 2526 "include/arm_math.h"
  void arm_scale_q7(
  q7_t * pSrc,
  q7_t scaleFract,
  int8_t shift,
  q7_t * pDst,
  uint32_t blockSize);
# 2543 "include/arm_math.h"
  void arm_scale_q15(
  q15_t * pSrc,
  q15_t scaleFract,
  int8_t shift,
  q15_t * pDst,
  uint32_t blockSize);
# 2560 "include/arm_math.h"
  void arm_scale_q31(
  q31_t * pSrc,
  q31_t scaleFract,
  int8_t shift,
  q31_t * pDst,
  uint32_t blockSize);
# 2575 "include/arm_math.h"
  void arm_abs_q7(
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);
# 2588 "include/arm_math.h"
  void arm_abs_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 2601 "include/arm_math.h"
  void arm_abs_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 2614 "include/arm_math.h"
  void arm_abs_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 2628 "include/arm_math.h"
  void arm_dot_prod_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  uint32_t blockSize,
  float32_t * result);
# 2643 "include/arm_math.h"
  void arm_dot_prod_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  uint32_t blockSize,
  q31_t * result);
# 2658 "include/arm_math.h"
  void arm_dot_prod_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  uint32_t blockSize,
  q63_t * result);
# 2673 "include/arm_math.h"
  void arm_dot_prod_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  uint32_t blockSize,
  q63_t * result);
# 2688 "include/arm_math.h"
  void arm_shift_q7(
  q7_t * pSrc,
  int8_t shiftBits,
  q7_t * pDst,
  uint32_t blockSize);
# 2703 "include/arm_math.h"
  void arm_shift_q15(
  q15_t * pSrc,
  int8_t shiftBits,
  q15_t * pDst,
  uint32_t blockSize);
# 2718 "include/arm_math.h"
  void arm_shift_q31(
  q31_t * pSrc,
  int8_t shiftBits,
  q31_t * pDst,
  uint32_t blockSize);
# 2733 "include/arm_math.h"
  void arm_offset_f32(
  float32_t * pSrc,
  float32_t offset,
  float32_t * pDst,
  uint32_t blockSize);
# 2748 "include/arm_math.h"
  void arm_offset_q7(
  q7_t * pSrc,
  q7_t offset,
  q7_t * pDst,
  uint32_t blockSize);
# 2763 "include/arm_math.h"
  void arm_offset_q15(
  q15_t * pSrc,
  q15_t offset,
  q15_t * pDst,
  uint32_t blockSize);
# 2778 "include/arm_math.h"
  void arm_offset_q31(
  q31_t * pSrc,
  q31_t offset,
  q31_t * pDst,
  uint32_t blockSize);
# 2792 "include/arm_math.h"
  void arm_negate_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 2805 "include/arm_math.h"
  void arm_negate_q7(
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);
# 2818 "include/arm_math.h"
  void arm_negate_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 2831 "include/arm_math.h"
  void arm_negate_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);







  void arm_copy_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 2854 "include/arm_math.h"
  void arm_copy_q7(
  q7_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);
# 2866 "include/arm_math.h"
  void arm_copy_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 2878 "include/arm_math.h"
  void arm_copy_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);







  void arm_fill_f32(
  float32_t value,
  float32_t * pDst,
  uint32_t blockSize);
# 2901 "include/arm_math.h"
  void arm_fill_q7(
  q7_t value,
  q7_t * pDst,
  uint32_t blockSize);
# 2913 "include/arm_math.h"
  void arm_fill_q15(
  q15_t value,
  q15_t * pDst,
  uint32_t blockSize);
# 2925 "include/arm_math.h"
  void arm_fill_q31(
  q31_t value,
  q31_t * pDst,
  uint32_t blockSize);
# 2940 "include/arm_math.h"
  void arm_conv_f32(
  float32_t * pSrcA,
  uint32_t srcALen,
  float32_t * pSrcB,
  uint32_t srcBLen,
  float32_t * pDst);
# 2961 "include/arm_math.h"
  void arm_conv_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);
# 2981 "include/arm_math.h"
  void arm_conv_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst);
# 2998 "include/arm_math.h"
  void arm_conv_fast_q15(
     q15_t * pSrcA,
    uint32_t srcALen,
     q15_t * pSrcB,
    uint32_t srcBLen,
    q15_t * pDst);
# 3017 "include/arm_math.h"
  void arm_conv_fast_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);
# 3038 "include/arm_math.h"
  void arm_conv_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);
# 3055 "include/arm_math.h"
  void arm_conv_fast_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);
# 3075 "include/arm_math.h"
  void arm_conv_opt_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);
# 3096 "include/arm_math.h"
  void arm_conv_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst);
# 3116 "include/arm_math.h"
  arm_status arm_conv_partial_f32(
  float32_t * pSrcA,
  uint32_t srcALen,
  float32_t * pSrcB,
  uint32_t srcBLen,
  float32_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);
# 3139 "include/arm_math.h"
  arm_status arm_conv_partial_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints,
  q15_t * pScratch1,
  q15_t * pScratch2);
# 3163 "include/arm_math.h"
  arm_status arm_conv_partial_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);
# 3184 "include/arm_math.h"
  arm_status arm_conv_partial_fast_q15(
            q15_t * pSrcA,
           uint32_t srcALen,
            q15_t * pSrcB,
           uint32_t srcBLen,
           q15_t * pDst,
           uint32_t firstIndex,
           uint32_t numPoints);
# 3208 "include/arm_math.h"
  arm_status arm_conv_partial_fast_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints,
  q15_t * pScratch1,
  q15_t * pScratch2);
# 3232 "include/arm_math.h"
  arm_status arm_conv_partial_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);
# 3254 "include/arm_math.h"
  arm_status arm_conv_partial_fast_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);
# 3278 "include/arm_math.h"
  arm_status arm_conv_partial_opt_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints,
  q15_t * pScratch1,
  q15_t * pScratch2);
# 3302 "include/arm_math.h"
  arm_status arm_conv_partial_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  uint32_t firstIndex,
  uint32_t numPoints);







  typedef struct
  {
    uint8_t M;
    uint16_t numTaps;
    q15_t *pCoeffs;
    q15_t *pState;
  } arm_fir_decimate_instance_q15;





  typedef struct
  {
    uint8_t M;
    uint16_t numTaps;
    q31_t *pCoeffs;
    q31_t *pState;

  } arm_fir_decimate_instance_q31;





  typedef struct
  {
    uint8_t M;
    uint16_t numTaps;
    float32_t *pCoeffs;
    float32_t *pState;

  } arm_fir_decimate_instance_f32;
# 3362 "include/arm_math.h"
  void arm_fir_decimate_f32(
  const arm_fir_decimate_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 3381 "include/arm_math.h"
  arm_status arm_fir_decimate_init_f32(
  arm_fir_decimate_instance_f32 * S,
  uint16_t numTaps,
  uint8_t M,
  float32_t * pCoeffs,
  float32_t * pState,
  uint32_t blockSize);
# 3398 "include/arm_math.h"
  void arm_fir_decimate_q15(
  const arm_fir_decimate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 3413 "include/arm_math.h"
  void arm_fir_decimate_fast_q15(
  const arm_fir_decimate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 3433 "include/arm_math.h"
  arm_status arm_fir_decimate_init_q15(
  arm_fir_decimate_instance_q15 * S,
  uint16_t numTaps,
  uint8_t M,
  q15_t * pCoeffs,
  q15_t * pState,
  uint32_t blockSize);
# 3450 "include/arm_math.h"
  void arm_fir_decimate_q31(
  const arm_fir_decimate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 3465 "include/arm_math.h"
  void arm_fir_decimate_fast_q31(
  arm_fir_decimate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 3484 "include/arm_math.h"
  arm_status arm_fir_decimate_init_q31(
  arm_fir_decimate_instance_q31 * S,
  uint16_t numTaps,
  uint8_t M,
  q31_t * pCoeffs,
  q31_t * pState,
  uint32_t blockSize);







  typedef struct
  {
    uint8_t L;
    uint16_t phaseLength;
    q15_t *pCoeffs;
    q15_t *pState;
  } arm_fir_interpolate_instance_q15;





  typedef struct
  {
    uint8_t L;
    uint16_t phaseLength;
    q31_t *pCoeffs;
    q31_t *pState;
  } arm_fir_interpolate_instance_q31;





  typedef struct
  {
    uint8_t L;
    uint16_t phaseLength;
    float32_t *pCoeffs;
    float32_t *pState;
  } arm_fir_interpolate_instance_f32;
# 3540 "include/arm_math.h"
  void arm_fir_interpolate_q15(
  const arm_fir_interpolate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 3559 "include/arm_math.h"
  arm_status arm_fir_interpolate_init_q15(
  arm_fir_interpolate_instance_q15 * S,
  uint8_t L,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  uint32_t blockSize);
# 3576 "include/arm_math.h"
  void arm_fir_interpolate_q31(
  const arm_fir_interpolate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 3594 "include/arm_math.h"
  arm_status arm_fir_interpolate_init_q31(
  arm_fir_interpolate_instance_q31 * S,
  uint8_t L,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  uint32_t blockSize);
# 3612 "include/arm_math.h"
  void arm_fir_interpolate_f32(
  const arm_fir_interpolate_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 3630 "include/arm_math.h"
  arm_status arm_fir_interpolate_init_f32(
  arm_fir_interpolate_instance_f32 * S,
  uint8_t L,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  uint32_t blockSize);





  typedef struct
  {
    uint8_t numStages;
    q63_t *pState;
    q31_t *pCoeffs;
    uint8_t postShift;

  } arm_biquad_cas_df1_32x64_ins_q31;
# 3660 "include/arm_math.h"
  void arm_biquad_cas_df1_32x64_q31(
  const arm_biquad_cas_df1_32x64_ins_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 3676 "include/arm_math.h"
  void arm_biquad_cas_df1_32x64_init_q31(
  arm_biquad_cas_df1_32x64_ins_q31 * S,
  uint8_t numStages,
  q31_t * pCoeffs,
  q63_t * pState,
  uint8_t postShift);







  typedef struct
  {
    uint8_t numStages;
    float32_t *pState;
    float32_t *pCoeffs;
  } arm_biquad_cascade_df2T_instance_f32;
# 3706 "include/arm_math.h"
  void arm_biquad_cascade_df2T_f32(
  const arm_biquad_cascade_df2T_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 3722 "include/arm_math.h"
  void arm_biquad_cascade_df2T_init_f32(
  arm_biquad_cascade_df2T_instance_f32 * S,
  uint8_t numStages,
  float32_t * pCoeffs,
  float32_t * pState);







  typedef struct
  {
    uint16_t numStages;
    q15_t *pState;
    q15_t *pCoeffs;
  } arm_fir_lattice_instance_q15;





  typedef struct
  {
    uint16_t numStages;
    q31_t *pState;
    q31_t *pCoeffs;
  } arm_fir_lattice_instance_q31;





  typedef struct
  {
    uint16_t numStages;
    float32_t *pState;
    float32_t *pCoeffs;
  } arm_fir_lattice_instance_f32;
# 3772 "include/arm_math.h"
  void arm_fir_lattice_init_q15(
  arm_fir_lattice_instance_q15 * S,
  uint16_t numStages,
  q15_t * pCoeffs,
  q15_t * pState);
# 3787 "include/arm_math.h"
  void arm_fir_lattice_q15(
  const arm_fir_lattice_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 3802 "include/arm_math.h"
  void arm_fir_lattice_init_q31(
  arm_fir_lattice_instance_q31 * S,
  uint16_t numStages,
  q31_t * pCoeffs,
  q31_t * pState);
# 3818 "include/arm_math.h"
  void arm_fir_lattice_q31(
  const arm_fir_lattice_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 3833 "include/arm_math.h"
  void arm_fir_lattice_init_f32(
  arm_fir_lattice_instance_f32 * S,
  uint16_t numStages,
  float32_t * pCoeffs,
  float32_t * pState);
# 3848 "include/arm_math.h"
  void arm_fir_lattice_f32(
  const arm_fir_lattice_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);




  typedef struct
  {
    uint16_t numStages;
    q15_t *pState;
    q15_t *pkCoeffs;
    q15_t *pvCoeffs;
  } arm_iir_lattice_instance_q15;




  typedef struct
  {
    uint16_t numStages;
    q31_t *pState;
    q31_t *pkCoeffs;
    q31_t *pvCoeffs;
  } arm_iir_lattice_instance_q31;




  typedef struct
  {
    uint16_t numStages;
    float32_t *pState;
    float32_t *pkCoeffs;
    float32_t *pvCoeffs;
  } arm_iir_lattice_instance_f32;
# 3896 "include/arm_math.h"
  void arm_iir_lattice_f32(
  const arm_iir_lattice_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 3913 "include/arm_math.h"
  void arm_iir_lattice_init_f32(
  arm_iir_lattice_instance_f32 * S,
  uint16_t numStages,
  float32_t * pkCoeffs,
  float32_t * pvCoeffs,
  float32_t * pState,
  uint32_t blockSize);
# 3931 "include/arm_math.h"
  void arm_iir_lattice_q31(
  const arm_iir_lattice_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 3949 "include/arm_math.h"
  void arm_iir_lattice_init_q31(
  arm_iir_lattice_instance_q31 * S,
  uint16_t numStages,
  q31_t * pkCoeffs,
  q31_t * pvCoeffs,
  q31_t * pState,
  uint32_t blockSize);
# 3967 "include/arm_math.h"
  void arm_iir_lattice_q15(
  const arm_iir_lattice_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 3985 "include/arm_math.h"
  void arm_iir_lattice_init_q15(
  arm_iir_lattice_instance_q15 * S,
  uint16_t numStages,
  q15_t * pkCoeffs,
  q15_t * pvCoeffs,
  q15_t * pState,
  uint32_t blockSize);





  typedef struct
  {
    uint16_t numTaps;
    float32_t *pState;
    float32_t *pCoeffs;
    float32_t mu;
  } arm_lms_instance_f32;
# 4016 "include/arm_math.h"
  void arm_lms_f32(
  const arm_lms_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pRef,
  float32_t * pOut,
  float32_t * pErr,
  uint32_t blockSize);
# 4035 "include/arm_math.h"
  void arm_lms_init_f32(
  arm_lms_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  float32_t mu,
  uint32_t blockSize);





  typedef struct
  {
    uint16_t numTaps;
    q15_t *pState;
    q15_t *pCoeffs;
    q15_t mu;
    uint32_t postShift;
  } arm_lms_instance_q15;
# 4069 "include/arm_math.h"
  void arm_lms_init_q15(
  arm_lms_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  q15_t mu,
  uint32_t blockSize,
  uint32_t postShift);
# 4089 "include/arm_math.h"
  void arm_lms_q15(
  const arm_lms_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pRef,
  q15_t * pOut,
  q15_t * pErr,
  uint32_t blockSize);






  typedef struct
  {
    uint16_t numTaps;
    q31_t *pState;
    q31_t *pCoeffs;
    q31_t mu;
    uint32_t postShift;

  } arm_lms_instance_q31;
# 4123 "include/arm_math.h"
  void arm_lms_q31(
  const arm_lms_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pRef,
  q31_t * pOut,
  q31_t * pErr,
  uint32_t blockSize);
# 4143 "include/arm_math.h"
  void arm_lms_init_q31(
  arm_lms_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  q31_t mu,
  uint32_t blockSize,
  uint32_t postShift);





  typedef struct
  {
    uint16_t numTaps;
    float32_t *pState;
    float32_t *pCoeffs;
    float32_t mu;
    float32_t energy;
    float32_t x0;
  } arm_lms_norm_instance_f32;
# 4177 "include/arm_math.h"
  void arm_lms_norm_f32(
  arm_lms_norm_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pRef,
  float32_t * pOut,
  float32_t * pErr,
  uint32_t blockSize);
# 4196 "include/arm_math.h"
  void arm_lms_norm_init_f32(
  arm_lms_norm_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  float32_t mu,
  uint32_t blockSize);





  typedef struct
  {
    uint16_t numTaps;
    q31_t *pState;
    q31_t *pCoeffs;
    q31_t mu;
    uint8_t postShift;
    q31_t *recipTable;
    q31_t energy;
    q31_t x0;
  } arm_lms_norm_instance_q31;
# 4231 "include/arm_math.h"
  void arm_lms_norm_q31(
  arm_lms_norm_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pRef,
  q31_t * pOut,
  q31_t * pErr,
  uint32_t blockSize);
# 4251 "include/arm_math.h"
  void arm_lms_norm_init_q31(
  arm_lms_norm_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  q31_t mu,
  uint32_t blockSize,
  uint8_t postShift);





  typedef struct
  {
    uint16_t numTaps;
    q15_t *pState;
    q15_t *pCoeffs;
    q15_t mu;
    uint8_t postShift;
    q15_t *recipTable;
    q15_t energy;
    q15_t x0;
  } arm_lms_norm_instance_q15;
# 4287 "include/arm_math.h"
  void arm_lms_norm_q15(
  arm_lms_norm_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pRef,
  q15_t * pOut,
  q15_t * pErr,
  uint32_t blockSize);
# 4308 "include/arm_math.h"
  void arm_lms_norm_init_q15(
  arm_lms_norm_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  q15_t mu,
  uint32_t blockSize,
  uint8_t postShift);
# 4327 "include/arm_math.h"
  void arm_correlate_f32(
  float32_t * pSrcA,
  uint32_t srcALen,
  float32_t * pSrcB,
  uint32_t srcBLen,
  float32_t * pDst);
# 4345 "include/arm_math.h"
  void arm_correlate_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch);
# 4364 "include/arm_math.h"
  void arm_correlate_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst);
# 4381 "include/arm_math.h"
  void arm_correlate_fast_q15(
          q15_t * pSrcA,
         uint32_t srcALen,
          q15_t * pSrcB,
         uint32_t srcBLen,
         q15_t * pDst);
# 4401 "include/arm_math.h"
  void arm_correlate_fast_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch);
# 4419 "include/arm_math.h"
  void arm_correlate_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);
# 4436 "include/arm_math.h"
  void arm_correlate_fast_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst);
# 4457 "include/arm_math.h"
  void arm_correlate_opt_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst,
  q15_t * pScratch1,
  q15_t * pScratch2);
# 4477 "include/arm_math.h"
  void arm_correlate_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst);





  typedef struct
  {
    uint16_t numTaps;
    uint16_t stateIndex;
    float32_t *pState;
    float32_t *pCoeffs;
    uint16_t maxDelay;
    int32_t *pTapDelay;
  } arm_fir_sparse_instance_f32;





  typedef struct
  {
    uint16_t numTaps;
    uint16_t stateIndex;
    q31_t *pState;
    q31_t *pCoeffs;
    uint16_t maxDelay;
    int32_t *pTapDelay;
  } arm_fir_sparse_instance_q31;





  typedef struct
  {
    uint16_t numTaps;
    uint16_t stateIndex;
    q15_t *pState;
    q15_t *pCoeffs;
    uint16_t maxDelay;
    int32_t *pTapDelay;
  } arm_fir_sparse_instance_q15;





  typedef struct
  {
    uint16_t numTaps;
    uint16_t stateIndex;
    q7_t *pState;
    q7_t *pCoeffs;
    uint16_t maxDelay;
    int32_t *pTapDelay;
  } arm_fir_sparse_instance_q7;
# 4550 "include/arm_math.h"
  void arm_fir_sparse_f32(
  arm_fir_sparse_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  float32_t * pScratchIn,
  uint32_t blockSize);
# 4569 "include/arm_math.h"
  void arm_fir_sparse_init_f32(
  arm_fir_sparse_instance_f32 * S,
  uint16_t numTaps,
  float32_t * pCoeffs,
  float32_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);
# 4588 "include/arm_math.h"
  void arm_fir_sparse_q31(
  arm_fir_sparse_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  q31_t * pScratchIn,
  uint32_t blockSize);
# 4607 "include/arm_math.h"
  void arm_fir_sparse_init_q31(
  arm_fir_sparse_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);
# 4627 "include/arm_math.h"
  void arm_fir_sparse_q15(
  arm_fir_sparse_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  q15_t * pScratchIn,
  q31_t * pScratchOut,
  uint32_t blockSize);
# 4648 "include/arm_math.h"
  void arm_fir_sparse_init_q15(
  arm_fir_sparse_instance_q15 * S,
  uint16_t numTaps,
  q15_t * pCoeffs,
  q15_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);
# 4668 "include/arm_math.h"
  void arm_fir_sparse_q7(
  arm_fir_sparse_instance_q7 * S,
  q7_t * pSrc,
  q7_t * pDst,
  q7_t * pScratchIn,
  q31_t * pScratchOut,
  uint32_t blockSize);
# 4688 "include/arm_math.h"
  void arm_fir_sparse_init_q7(
  arm_fir_sparse_instance_q7 * S,
  uint16_t numTaps,
  q7_t * pCoeffs,
  q7_t * pState,
  int32_t * pTapDelay,
  uint16_t maxDelay,
  uint32_t blockSize);
# 4706 "include/arm_math.h"
  void arm_sin_cos_f32(
  float32_t theta,
  float32_t * pSinVal,
  float32_t * pCcosVal);
# 4719 "include/arm_math.h"
  void arm_sin_cos_q31(
  q31_t theta,
  q31_t * pSinVal,
  q31_t * pCosVal);
# 4733 "include/arm_math.h"
  void arm_cmplx_conj_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t numSamples);
# 4746 "include/arm_math.h"
  void arm_cmplx_conj_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t numSamples);
# 4759 "include/arm_math.h"
  void arm_cmplx_conj_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t numSamples);
# 4774 "include/arm_math.h"
  void arm_cmplx_mag_squared_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t numSamples);
# 4787 "include/arm_math.h"
  void arm_cmplx_mag_squared_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t numSamples);
# 4800 "include/arm_math.h"
  void arm_cmplx_mag_squared_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t numSamples);
# 4880 "include/arm_math.h"
  static inline float32_t arm_pid_f32(
  arm_pid_instance_f32 * S,
  float32_t in)
  {
    float32_t out;


    out = (S->A0 * in) +
      (S->A1 * S->state[0]) + (S->A2 * S->state[1]) + (S->state[2]);


    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;


    return (out);

  }
# 4915 "include/arm_math.h"
  static inline q31_t arm_pid_q31(
  arm_pid_instance_q31 * S,
  q31_t in)
  {
    q63_t acc;
    q31_t out;


    acc = (q63_t) S->A0 * in;


    acc += (q63_t) S->A1 * S->state[0];


    acc += (q63_t) S->A2 * S->state[1];


    out = (q31_t) (acc >> 31u);


    out += S->state[2];


    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;


    return (out);

  }
# 4963 "include/arm_math.h"
  static inline q15_t arm_pid_q15(
  arm_pid_instance_q15 * S,
  q15_t in)
  {
    q63_t acc;
    q15_t out;


    int32_t *vstate;




    acc = (q31_t) __SMUAD(S->A0, in);


    vstate = ((int32_t *)(S->state));
    acc = ({ uint32_t __ARG1 = (S->A1), __ARG2 = ((q31_t) *vstate), __ARG3_H = (uint32_t)((uint64_t)(acc) >> 32), __ARG3_L = (uint32_t)((uint64_t)(acc) & 0xFFFFFFFFUL); __asm volatile ("smlald %0, %1, %2, %3" : "=r" (__ARG3_L), "=r" (__ARG3_H) : "r" (__ARG1), "r" (__ARG2), "0" (__ARG3_L), "1" (__ARG3_H) ); (uint64_t)(((uint64_t)__ARG3_H << 32) | __ARG3_L); });
# 4993 "include/arm_math.h"
    acc += (q31_t) S->state[2] << 15;


    out = (q15_t) (({ uint32_t __RES, __ARG1 = ((acc >> 15)); __asm ("ssat %0, %1, %2" : "=r" (__RES) : "I" (16), "r" (__ARG1) ); __RES; }));


    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;


    return (out);

  }
# 5021 "include/arm_math.h"
  arm_status arm_mat_inverse_f32(
  const arm_matrix_instance_f32 * src,
  arm_matrix_instance_f32 * dst);
# 5069 "include/arm_math.h"
  static inline void arm_clarke_f32(
  float32_t Ia,
  float32_t Ib,
  float32_t * pIalpha,
  float32_t * pIbeta)
  {

    *pIalpha = Ia;


    *pIbeta =
      ((float32_t) 0.57735026919 * Ia + (float32_t) 1.15470053838 * Ib);

  }
# 5099 "include/arm_math.h"
  static inline void arm_clarke_q31(
  q31_t Ia,
  q31_t Ib,
  q31_t * pIalpha,
  q31_t * pIbeta)
  {
    q31_t product1, product2;


    *pIalpha = Ia;


    product1 = (q31_t) (((q63_t) Ia * 0x24F34E8B) >> 30);


    product2 = (q31_t) (((q63_t) Ib * 0x49E69D16) >> 30);


    *pIbeta = __QADD(product1, product2);
  }
# 5131 "include/arm_math.h"
  void arm_q7_to_q31(
  q7_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 5174 "include/arm_math.h"
  static inline void arm_inv_clarke_f32(
  float32_t Ialpha,
  float32_t Ibeta,
  float32_t * pIa,
  float32_t * pIb)
  {

    *pIa = Ialpha;


    *pIb = -0.5f * Ialpha + (float32_t) 0.8660254039f *Ibeta;

  }
# 5203 "include/arm_math.h"
  static inline void arm_inv_clarke_q31(
  q31_t Ialpha,
  q31_t Ibeta,
  q31_t * pIa,
  q31_t * pIb)
  {
    q31_t product1, product2;


    *pIa = Ialpha;


    product1 = (q31_t) (((q63_t) (Ialpha) * (0x40000000)) >> 31);


    product2 = (q31_t) (((q63_t) (Ibeta) * (0x6ED9EBA1)) >> 31);


    *pIb = __QSUB(product2, product1);

  }
# 5236 "include/arm_math.h"
  void arm_q7_to_q15(
  q7_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 5290 "include/arm_math.h"
  static inline void arm_park_f32(
  float32_t Ialpha,
  float32_t Ibeta,
  float32_t * pId,
  float32_t * pIq,
  float32_t sinVal,
  float32_t cosVal)
  {

    *pId = Ialpha * cosVal + Ibeta * sinVal;


    *pIq = -Ialpha * sinVal + Ibeta * cosVal;

  }
# 5324 "include/arm_math.h"
  static inline void arm_park_q31(
  q31_t Ialpha,
  q31_t Ibeta,
  q31_t * pId,
  q31_t * pIq,
  q31_t sinVal,
  q31_t cosVal)
  {
    q31_t product1, product2;
    q31_t product3, product4;


    product1 = (q31_t) (((q63_t) (Ialpha) * (cosVal)) >> 31);


    product2 = (q31_t) (((q63_t) (Ibeta) * (sinVal)) >> 31);



    product3 = (q31_t) (((q63_t) (Ialpha) * (sinVal)) >> 31);


    product4 = (q31_t) (((q63_t) (Ibeta) * (cosVal)) >> 31);


    *pId = __QADD(product1, product2);


    *pIq = __QSUB(product4, product3);
  }
# 5366 "include/arm_math.h"
  void arm_q7_to_float(
  q7_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 5409 "include/arm_math.h"
  static inline void arm_inv_park_f32(
  float32_t Id,
  float32_t Iq,
  float32_t * pIalpha,
  float32_t * pIbeta,
  float32_t sinVal,
  float32_t cosVal)
  {

    *pIalpha = Id * cosVal - Iq * sinVal;


    *pIbeta = Id * sinVal + Iq * cosVal;

  }
# 5444 "include/arm_math.h"
  static inline void arm_inv_park_q31(
  q31_t Id,
  q31_t Iq,
  q31_t * pIalpha,
  q31_t * pIbeta,
  q31_t sinVal,
  q31_t cosVal)
  {
    q31_t product1, product2;
    q31_t product3, product4;


    product1 = (q31_t) (((q63_t) (Id) * (cosVal)) >> 31);


    product2 = (q31_t) (((q63_t) (Iq) * (sinVal)) >> 31);



    product3 = (q31_t) (((q63_t) (Id) * (sinVal)) >> 31);


    product4 = (q31_t) (((q63_t) (Iq) * (cosVal)) >> 31);


    *pIalpha = __QSUB(product1, product2);


    *pIbeta = __QADD(product4, product3);

  }
# 5488 "include/arm_math.h"
  void arm_q31_to_float(
  q31_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 5542 "include/arm_math.h"
  static inline float32_t arm_linear_interp_f32(
  arm_linear_interp_instance_f32 * S,
  float32_t x)
  {

    float32_t y;
    float32_t x0, x1;
    float32_t y0, y1;
    float32_t xSpacing = S->xSpacing;
    int32_t i;
    float32_t *pYData = S->pYData;


    i = (int32_t) ((x - S->x1) / xSpacing);

    if(i < 0)
    {

      y = pYData[0];
    }
    else if((uint32_t)i >= S->nValues)
    {

      y = pYData[S->nValues - 1];
    }
    else
    {

      x0 = S->x1 + i * xSpacing;
      x1 = S->x1 + (i + 1) * xSpacing;


      y0 = pYData[i];
      y1 = pYData[i + 1];


      y = y0 + (x - x0) * ((y1 - y0) / (x1 - x0));

    }


    return (y);
  }
# 5601 "include/arm_math.h"
  static inline q31_t arm_linear_interp_q31(
  q31_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q31_t y;
    q31_t y0, y1;
    q31_t fract;
    int32_t index;




    index = ((x & 0xFFF00000) >> 20);

    if(index >= (int32_t)(nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else if(index < 0)
    {
      return (pYData[0]);
    }
    else
    {



      fract = (x & 0x000FFFFF) << 11;


      y0 = pYData[index];
      y1 = pYData[index + 1u];


      y = ((q31_t) ((q63_t) y0 * (0x7FFFFFFF - fract) >> 32));


      y += ((q31_t) (((q63_t) y1 * fract) >> 32));


      return (y << 1u);

    }

  }
# 5663 "include/arm_math.h"
  static inline q15_t arm_linear_interp_q15(
  q15_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q63_t y;
    q15_t y0, y1;
    q31_t fract;
    int32_t index;




    index = ((x & 0xFFF00000) >> 20u);

    if(index >= (int32_t)(nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else if(index < 0)
    {
      return (pYData[0]);
    }
    else
    {


      fract = (x & 0x000FFFFF);


      y0 = pYData[index];
      y1 = pYData[index + 1u];


      y = ((q63_t) y0 * (0xFFFFF - fract));


      y += ((q63_t) y1 * (fract));


      return (y >> 20);
    }


  }
# 5723 "include/arm_math.h"
  static inline q7_t arm_linear_interp_q7(
  q7_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q31_t y;
    q7_t y0, y1;
    q31_t fract;
    uint32_t index;




    if (x < 0)
    {
      return (pYData[0]);
    }
    index = (x >> 20) & 0xfff;


    if(index >= (nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else
    {



      fract = (x & 0x000FFFFF);


      y0 = pYData[index];
      y1 = pYData[index + 1u];


      y = ((y0 * (0xFFFFF - fract)));


      y += (y1 * fract);


      return (y >> 20u);

    }

  }
# 5780 "include/arm_math.h"
  float32_t arm_sin_f32(
  float32_t x);







  q31_t arm_sin_q31(
  q31_t x);







  q15_t arm_sin_q15(
  q15_t x);







  float32_t arm_cos_f32(
  float32_t x);







  q31_t arm_cos_q31(
  q31_t x);







  q15_t arm_cos_q15(
  q15_t x);
# 5868 "include/arm_math.h"
  static inline arm_status arm_sqrt_f32(
  float32_t in,
  float32_t * pOut)
  {
    if(in > 0)
    {





      *pOut = sqrtf(in);


      return (ARM_MATH_SUCCESS);
    }
    else
    {
      *pOut = 0.0f;
      return (ARM_MATH_ARGUMENT_ERROR);
    }

  }
# 5900 "include/arm_math.h"
  arm_status arm_sqrt_q31(
  q31_t in,
  q31_t * pOut);
# 5911 "include/arm_math.h"
  arm_status arm_sqrt_q15(
  q15_t in,
  q15_t * pOut);
# 5928 "include/arm_math.h"
  static inline void arm_circularWrite_f32(
  int32_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const int32_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t wOffset;



    wOffset = *writeOffset;


    i = blockSize;

    while(i > 0u)
    {

      circBuffer[wOffset] = *src;


      src += srcInc;


      wOffset += bufferInc;
      if(wOffset >= L)
        wOffset -= L;


      i--;
    }


    *writeOffset = wOffset;
  }






  static inline void arm_circularRead_f32(
  int32_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  int32_t * dst,
  int32_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t rOffset, dst_end;



    rOffset = *readOffset;
    dst_end = (int32_t) (dst_base + dst_length);


    i = blockSize;

    while(i > 0u)
    {

      *dst = circBuffer[rOffset];


      dst += dstInc;

      if(dst == (int32_t *) dst_end)
      {
        dst = dst_base;
      }


      rOffset += bufferInc;

      if(rOffset >= L)
      {
        rOffset -= L;
      }


      i--;
    }


    *readOffset = rOffset;
  }





  static inline void arm_circularWrite_q15(
  q15_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const q15_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t wOffset;



    wOffset = *writeOffset;


    i = blockSize;

    while(i > 0u)
    {

      circBuffer[wOffset] = *src;


      src += srcInc;


      wOffset += bufferInc;
      if(wOffset >= L)
        wOffset -= L;


      i--;
    }


    *writeOffset = wOffset;
  }






  static inline void arm_circularRead_q15(
  q15_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  q15_t * dst,
  q15_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0;
    int32_t rOffset, dst_end;



    rOffset = *readOffset;

    dst_end = (int32_t) (dst_base + dst_length);


    i = blockSize;

    while(i > 0u)
    {

      *dst = circBuffer[rOffset];


      dst += dstInc;

      if(dst == (q15_t *) dst_end)
      {
        dst = dst_base;
      }


      rOffset += bufferInc;

      if(rOffset >= L)
      {
        rOffset -= L;
      }


      i--;
    }


    *readOffset = rOffset;
  }






  static inline void arm_circularWrite_q7(
  q7_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const q7_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0u;
    int32_t wOffset;



    wOffset = *writeOffset;


    i = blockSize;

    while(i > 0u)
    {

      circBuffer[wOffset] = *src;


      src += srcInc;


      wOffset += bufferInc;
      if(wOffset >= L)
        wOffset -= L;


      i--;
    }


    *writeOffset = wOffset;
  }






  static inline void arm_circularRead_q7(
  q7_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  q7_t * dst,
  q7_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0;
    int32_t rOffset, dst_end;



    rOffset = *readOffset;

    dst_end = (int32_t) (dst_base + dst_length);


    i = blockSize;

    while(i > 0u)
    {

      *dst = circBuffer[rOffset];


      dst += dstInc;

      if(dst == (q7_t *) dst_end)
      {
        dst = dst_base;
      }


      rOffset += bufferInc;

      if(rOffset >= L)
      {
        rOffset -= L;
      }


      i--;
    }


    *readOffset = rOffset;
  }
# 6236 "include/arm_math.h"
  void arm_power_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q63_t * pResult);
# 6249 "include/arm_math.h"
  void arm_power_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);
# 6262 "include/arm_math.h"
  void arm_power_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q63_t * pResult);
# 6275 "include/arm_math.h"
  void arm_power_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);
# 6288 "include/arm_math.h"
  void arm_mean_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q7_t * pResult);
# 6300 "include/arm_math.h"
  void arm_mean_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult);
# 6312 "include/arm_math.h"
  void arm_mean_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);
# 6324 "include/arm_math.h"
  void arm_mean_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);
# 6337 "include/arm_math.h"
  void arm_var_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);
# 6350 "include/arm_math.h"
  void arm_var_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q63_t * pResult);
# 6363 "include/arm_math.h"
  void arm_var_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);
# 6376 "include/arm_math.h"
  void arm_rms_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);
# 6389 "include/arm_math.h"
  void arm_rms_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);
# 6402 "include/arm_math.h"
  void arm_rms_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult);
# 6415 "include/arm_math.h"
  void arm_std_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult);
# 6428 "include/arm_math.h"
  void arm_std_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult);
# 6441 "include/arm_math.h"
  void arm_std_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult);
# 6454 "include/arm_math.h"
  void arm_cmplx_mag_f32(
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t numSamples);
# 6467 "include/arm_math.h"
  void arm_cmplx_mag_q31(
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t numSamples);
# 6480 "include/arm_math.h"
  void arm_cmplx_mag_q15(
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t numSamples);
# 6495 "include/arm_math.h"
  void arm_cmplx_dot_prod_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  uint32_t numSamples,
  q31_t * realResult,
  q31_t * imagResult);
# 6512 "include/arm_math.h"
  void arm_cmplx_dot_prod_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  uint32_t numSamples,
  q63_t * realResult,
  q63_t * imagResult);
# 6529 "include/arm_math.h"
  void arm_cmplx_dot_prod_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  uint32_t numSamples,
  float32_t * realResult,
  float32_t * imagResult);
# 6545 "include/arm_math.h"
  void arm_cmplx_mult_real_q15(
  q15_t * pSrcCmplx,
  q15_t * pSrcReal,
  q15_t * pCmplxDst,
  uint32_t numSamples);
# 6560 "include/arm_math.h"
  void arm_cmplx_mult_real_q31(
  q31_t * pSrcCmplx,
  q31_t * pSrcReal,
  q31_t * pCmplxDst,
  uint32_t numSamples);
# 6575 "include/arm_math.h"
  void arm_cmplx_mult_real_f32(
  float32_t * pSrcCmplx,
  float32_t * pSrcReal,
  float32_t * pCmplxDst,
  uint32_t numSamples);
# 6590 "include/arm_math.h"
  void arm_min_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q7_t * result,
  uint32_t * index);
# 6605 "include/arm_math.h"
  void arm_min_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult,
  uint32_t * pIndex);
# 6619 "include/arm_math.h"
  void arm_min_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult,
  uint32_t * pIndex);
# 6634 "include/arm_math.h"
  void arm_min_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult,
  uint32_t * pIndex);
# 6649 "include/arm_math.h"
  void arm_max_q7(
  q7_t * pSrc,
  uint32_t blockSize,
  q7_t * pResult,
  uint32_t * pIndex);
# 6664 "include/arm_math.h"
  void arm_max_q15(
  q15_t * pSrc,
  uint32_t blockSize,
  q15_t * pResult,
  uint32_t * pIndex);
# 6679 "include/arm_math.h"
  void arm_max_q31(
  q31_t * pSrc,
  uint32_t blockSize,
  q31_t * pResult,
  uint32_t * pIndex);
# 6694 "include/arm_math.h"
  void arm_max_f32(
  float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult,
  uint32_t * pIndex);
# 6709 "include/arm_math.h"
  void arm_cmplx_mult_cmplx_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  uint32_t numSamples);
# 6724 "include/arm_math.h"
  void arm_cmplx_mult_cmplx_q31(
  q31_t * pSrcA,
  q31_t * pSrcB,
  q31_t * pDst,
  uint32_t numSamples);
# 6739 "include/arm_math.h"
  void arm_cmplx_mult_cmplx_f32(
  float32_t * pSrcA,
  float32_t * pSrcB,
  float32_t * pDst,
  uint32_t numSamples);
# 6752 "include/arm_math.h"
  void arm_float_to_q31(
  float32_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 6764 "include/arm_math.h"
  void arm_float_to_q15(
  float32_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 6776 "include/arm_math.h"
  void arm_float_to_q7(
  float32_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);
# 6789 "include/arm_math.h"
  void arm_q31_to_q15(
  q31_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize);
# 6801 "include/arm_math.h"
  void arm_q31_to_q7(
  q31_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);
# 6813 "include/arm_math.h"
  void arm_q15_to_float(
  q15_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize);
# 6826 "include/arm_math.h"
  void arm_q15_to_q31(
  q15_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize);
# 6839 "include/arm_math.h"
  void arm_q15_to_q7(
  q15_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize);
# 6916 "include/arm_math.h"
  static inline float32_t arm_bilinear_interp_f32(
  const arm_bilinear_interp_instance_f32 * S,
  float32_t X,
  float32_t Y)
  {
    float32_t out;
    float32_t f00, f01, f10, f11;
    float32_t *pData = S->pData;
    int32_t xIndex, yIndex, index;
    float32_t xdiff, ydiff;
    float32_t b1, b2, b3, b4;

    xIndex = (int32_t) X;
    yIndex = (int32_t) Y;



    if(xIndex < 0 || xIndex > (S->numRows - 1) || yIndex < 0
       || yIndex > (S->numCols - 1))
    {
      return (0);
    }


    index = (xIndex - 1) + (yIndex - 1) * S->numCols;



    f00 = pData[index];
    f01 = pData[index + 1];


    index = (xIndex - 1) + (yIndex) * S->numCols;



    f10 = pData[index];
    f11 = pData[index + 1];


    b1 = f00;
    b2 = f01 - f00;
    b3 = f10 - f00;
    b4 = f00 - f01 - f10 + f11;


    xdiff = X - xIndex;


    ydiff = Y - yIndex;


    out = b1 + b2 * xdiff + b3 * ydiff + b4 * xdiff * ydiff;


    return (out);

  }
# 6984 "include/arm_math.h"
  static inline q31_t arm_bilinear_interp_q31(
  arm_bilinear_interp_instance_q31 * S,
  q31_t X,
  q31_t Y)
  {
    q31_t out;
    q31_t acc = 0;
    q31_t xfract, yfract;
    q31_t x1, x2, y1, y2;
    int32_t rI, cI;
    q31_t *pYData = S->pData;
    uint32_t nCols = S->numCols;





    rI = ((X & 0xFFF00000) >> 20u);




    cI = ((Y & 0xFFF00000) >> 20u);



    if(rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }



    xfract = (X & 0x000FFFFF) << 11u;


    x1 = pYData[(rI) + nCols * (cI)];
    x2 = pYData[(rI) + nCols * (cI) + 1u];



    yfract = (Y & 0x000FFFFF) << 11u;


    y1 = pYData[(rI) + nCols * (cI + 1)];
    y2 = pYData[(rI) + nCols * (cI + 1) + 1u];


    out = ((q31_t) (((q63_t) x1 * (0x7FFFFFFF - xfract)) >> 32));
    acc = ((q31_t) (((q63_t) out * (0x7FFFFFFF - yfract)) >> 32));


    out = ((q31_t) ((q63_t) x2 * (0x7FFFFFFF - yfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (xfract) >> 32));


    out = ((q31_t) ((q63_t) y1 * (0x7FFFFFFF - xfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (yfract) >> 32));


    out = ((q31_t) ((q63_t) y2 * (xfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (yfract) >> 32));


    return (acc << 2u);

  }
# 7060 "include/arm_math.h"
  static inline q15_t arm_bilinear_interp_q15(
  arm_bilinear_interp_instance_q15 * S,
  q31_t X,
  q31_t Y)
  {
    q63_t acc = 0;
    q31_t out;
    q15_t x1, x2, y1, y2;
    q31_t xfract, yfract;
    int32_t rI, cI;
    q15_t *pYData = S->pData;
    uint32_t nCols = S->numCols;




    rI = ((X & 0xFFF00000) >> 20);




    cI = ((Y & 0xFFF00000) >> 20);



    if(rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }



    xfract = (X & 0x000FFFFF);


    x1 = pYData[(rI) + nCols * (cI)];
    x2 = pYData[(rI) + nCols * (cI) + 1u];




    yfract = (Y & 0x000FFFFF);


    y1 = pYData[(rI) + nCols * (cI + 1)];
    y2 = pYData[(rI) + nCols * (cI + 1) + 1u];





    out = (q31_t) (((q63_t) x1 * (0xFFFFF - xfract)) >> 4u);
    acc = ((q63_t) out * (0xFFFFF - yfract));


    out = (q31_t) (((q63_t) x2 * (0xFFFFF - yfract)) >> 4u);
    acc += ((q63_t) out * (xfract));


    out = (q31_t) (((q63_t) y1 * (0xFFFFF - xfract)) >> 4u);
    acc += ((q63_t) out * (yfract));


    out = (q31_t) (((q63_t) y2 * (xfract)) >> 4u);
    acc += ((q63_t) out * (yfract));



    return (acc >> 36);

  }
# 7140 "include/arm_math.h"
  static inline q7_t arm_bilinear_interp_q7(
  arm_bilinear_interp_instance_q7 * S,
  q31_t X,
  q31_t Y)
  {
    q63_t acc = 0;
    q31_t out;
    q31_t xfract, yfract;
    q7_t x1, x2, y1, y2;
    int32_t rI, cI;
    q7_t *pYData = S->pData;
    uint32_t nCols = S->numCols;




    rI = ((X & 0xFFF00000) >> 20);




    cI = ((Y & 0xFFF00000) >> 20);



    if(rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }



    xfract = (X & 0x000FFFFF);


    x1 = pYData[(rI) + nCols * (cI)];
    x2 = pYData[(rI) + nCols * (cI) + 1u];




    yfract = (Y & 0x000FFFFF);


    y1 = pYData[(rI) + nCols * (cI + 1)];
    y2 = pYData[(rI) + nCols * (cI + 1) + 1u];


    out = ((x1 * (0xFFFFF - xfract)));
    acc = (((q63_t) out * (0xFFFFF - yfract)));


    out = ((x2 * (0xFFFFF - yfract)));
    acc += (((q63_t) out * (xfract)));


    out = ((y1 * (0xFFFFF - xfract)));
    acc += (((q63_t) out * (yfract)));


    out = ((y2 * (yfract)));
    acc += (((q63_t) out * (xfract)));


    return (acc >> 40);

  }
# 7296 "include/arm_math.h"
}
# 9 "include/Gps.h" 2






class GpsSample {
    private:
        Vector position, velocity;
        TickType_t timestamp;

    public:
        GpsSample(Vector position, Vector velocity, TickType_t timestamp);
        Vector* getNewPosition();
        Vector* getNewVelocity();
        TickType_t getTimestamp();
};

class Gps {
    private:
        char gpsBuffer[200];
        void initGpsUsart();
        void initGps();
        void sendChar(const char c);
        void sendStr(const char* buffer, uint32_t length);
        uint8_t calcChecksum(const char* buffer, uint32_t length);
        double utcTime, latitude, longitude;
        float speed, course;
        int date;
        char status, latInd, lonInd;
        double originLatitude, originLongitude;
        void calculateSampleData();
        GpsSample* gpsSample;

    public:
        Gps();
        void init();
        void irqHandler();
        void markOrigin();
        void parsePacket(const char* buffer);
        bool isLocked();
        GpsSample* getSample();
};
# 8 "include/Kinematics.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 1






# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 8 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 2
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 2
# 56 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 57 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 2
# 9 "include/Kinematics.h" 2
# 18 "include/Kinematics.h"
class Kinematics {
    private:
        Quaternion* attitudePtr = 0;
        Vector* velocityPtr = 0;
        Vector* positionPtr = 0;
        const float g = 9.81;
        SemaphoreHandle_t sampleMutex = 0;
        Vector* aSamplePtr = 0;
        Vector* gSamplePtr = 0;
        float altimeterSample;
        float dtSample;
        void takeMutex();
        void giveMutex();

    protected:

    public:
        Kinematics();
        Kinematics(const Quaternion* attitudeArg, const Vector* velocityArg, const Vector* positionArg);
        ~Kinematics();

        void setDtSample(const float dtSample);
        void setLinearAccelerationSample(const Vector* aSample);
        void setAngularVelocitySample(const Vector* gSample);
        void setAltimeterSample(const float altimeterSample);
        float getDtSample();
        Vector* getNewLinearAccelerationSample();
        Vector* getNewAngularVelocitySample();
        float getAltimeterSample();
        void processSample();

        Quaternion* getNewAttitude();
        Vector* getNewVelocity();
        Vector* getNewPosition();
        float getAccelerationDueToGravity();

        void markOrigin();


        void setAltitude(float altitude);
        void setGpsSample(GpsSample* gpsSample);
        void initialSetBearingRadiansCwN(const float angle);
        void updateBearingRadiansCwN(const float angle);
        void updateAttitudeFromFeedback(Quaternion* estimatedAttitude);
};

class KinematicsEstimateMessage : public LogMessage {
  private:
    float dt;
    Quaternion attitude;
    Vector velocity;
    Vector position;
    char* _toString(char* buffer, uint16_t length, const char* formatStr);

  public:
    KinematicsEstimateMessage(float dt, Quaternion attitude, Vector velocity, Vector position);
    char* toString(char* buffer, uint16_t length);
    char* toDataString(char* buffer, uint16_t length);
    uint16_t getSize();
    char* getShortType();
};
# 14 "include/SensorTask.h" 2
# 1 "include/IMU.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 5 "include/IMU.h" 2

# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 1
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 27 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 59 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 7 "include/IMU.h" 2



# 1 "include/I2C.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 5 "include/I2C.h" 2


# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 1






# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 8 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 2
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 2
# 56 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 57 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/exception" 2
# 8 "include/I2C.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/cstdarg" 1
# 21 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/cstdarg"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 1






# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 8 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_prolog.h" 2
# 22 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/cstdarg" 2




# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdarg.h" 1
# 22 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdarg.h"
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstdarg" 1 3 4
# 14 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstdarg" 3 4
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdarg.h" 1 3 4
# 36 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdarg.h" 3 4
# 1 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdarg.h" 1 3 4
# 36 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\stdarg.h" 3 4
typedef __va_list va_list;
# 37 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdarg.h" 2 3 4
# 15 "c:\\program files (x86)\\rowley associates limited\\crossworks for arm 3.3\\include\\cstdarg" 2 3 4

namespace std
{
using ::va_list;
}
# 23 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cstdarg.h" 2






namespace stlpmtx_std {
using std::va_list;
}
# 27 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/cstdarg" 2
# 39 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/cstdarg"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 40 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/cstdarg" 2
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

class I2cTimeoutException : public stlpmtx_std::exception {
    public:
      virtual const char* what() const throw() {
        return "I2C timeout exception thrown";
    }
};
# 11 "include/IMU.h" 2


# 1 "include/Config.h" 1




# 1 "include/core/stm32f4xx_flash.h" 1
# 6 "include/Config.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 1
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 7 "include/Config.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 1
# 26 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 27 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 59 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/string.h" 2
# 8 "include/Config.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 1
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 2
# 60 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 61 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdlib.h" 2
# 9 "include/Config.h" 2




enum class AircraftType {QUADCOPTER, HELICOPTER, AIRPLANE};

class PidConfig {
    public:
        PidConfig();
        float p, i, d;
};

class Config {
    public:
        static Config& getInstance();
        void copy(Config& configSrc);
        AircraftType aircraftType;
        float dt;
        PidConfig pitchPid;
        PidConfig rollPid;
        PidConfig yawPid;
        float magXOffset, magXRange;
        float magYOffset, magYRange;
        float magDeclination;

        float tailMax, tailMin;
        bool tailReverse;

        void getConfig(Config& config);
        void setConfig(Config& config);
        void loadDefaults();
        bool loadConfigFromFlash();
        void loadLatest();
        void saveConfigToFlash();
        void printConfig();

        void processGetSet(char* command, char* axisStr, char* propertyStr, char* valueStr);

    private:
        Config();
        const char* getAircraftTypeName(AircraftType aircraftType);

        uint32_t flashSector;
        uint32_t baseFlashAddress;


        void setUseTestFlashBank(bool useTestBank);
        friend void test_CliReadWrite();
};
# 14 "include/IMU.h" 2



class ImuSample {
  public:
    ImuSample(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz, float altAmsl);
    ImuSample(ImuSample *imuSample);
    ImuSample();
    Vector* getNewLinearAccelerationMps();
    Vector* getNewAngularVelocityRps();
    float getCompassAngleRadiansCwN();
    void convertToReferenceFrame(Quaternion* referenceFrame);

    float ax, ay, az;
    float gx, gy, gz;
    float mx, my, mz;
    float altAmsl;
};
# 43 "include/IMU.h"
class IMU {
  public:
    IMU(QueueHandle_t sampleQueue);
    void init();
    void irqHandler();

  private:
    I2C *imuI2C;
    I2C *compassI2C;
    uint8_t imuAddress;
    uint8_t compassAddress;
    uint8_t magCal[3];
    ImuSample imuSample;
    volatile bool sampleReadyFlag;
    ImuSample* cal;
    QueueHandle_t sampleQueue = 0;

    void configureImuComm();
    void initImu();
    void initInterrupt();
    void calibrate();
    bool isSampleReady();
    ImuSample* getSample();
};


class ImuMessage : public LogMessage {
  private:
    ImuSample imuSample;
    char* _toString(char* buffer, uint16_t length, const char* formatStr);

  public:
    ImuMessage(ImuSample *imuSample);
    char* toString(char* buffer, uint16_t length);
    char* toDataString(char* buffer, uint16_t length);
    uint16_t getSize();
    char* getShortType();
};
# 15 "include/SensorTask.h" 2

# 1 "include/AltimeterTask.h" 1



# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/__cross_studio_io.h" 1 3 4
# 5 "include/AltimeterTask.h" 2







# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 2
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/Math.h" 2
# 13 "include/AltimeterTask.h" 2



class AltimeterTask : public TaskClass {
  public:
    AltimeterTask(SemaphoreHandle_t semaphore);
    void init();
    void task();
    long getAltimeterSample(float* sampleData);


  private:
    uint8_t altAddress;
    I2C *altI2C;
    uint16_t ac4, ac5, ac6;
    int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
    void initIO();
    void readCalData();
    float measureAltitude();

    SemaphoreHandle_t semaphore;
    QueueHandle_t queue;

};
# 17 "include/SensorTask.h" 2




class SensorTask : public TaskClass {
  public:
    SensorTask(AltimeterTask* altimeter, SemaphoreHandle_t altimeterSemaphore);
    ~SensorTask();
    void init();
    void task();
    Kinematics* getKinematics();
    bool isGpsLocked();
    void markOrigin();

  private:
    Kinematics* kinematics;
    IMU* imu;
    Quaternion* imuReferenceFrame;
    Gps* gps;
    AltimeterTask* altimeter;
    SemaphoreHandle_t altimeterSemaphore;
    QueueHandle_t imuSampleQueue;
    void convertImuSampleToAircraftReferenceFrame(ImuSample* imuSample, Quaternion* referenceFrame);


};
# 17 "include/ControlTask.h" 2
# 1 "include/PwmCapture.h" 1





# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 1
# 24 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 25 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 50 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 51 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stdio.h" 2
# 7 "include/PwmCapture.h" 2
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 8 "include/PwmCapture.h" 2
# 1 "include/PwmGen.h" 1





# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 1
# 18 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_cprolog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 47 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 1
# 19 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_config_compat_post.h" 1
# 20 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/stl/_epilog.h" 2
# 48 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stlport/math.h" 2
# 7 "include/PwmGen.h" 2

class ChannelEnum {
    public:
        static const uint8_t CHANNEL1 = 0;
        static const uint8_t CHANNEL2 = 1;
        static const uint8_t CHANNEL3 = 2;
        static const uint8_t CHANNEL4 = 3;
        static const uint8_t CHANNEL5 = 4;
        static const uint8_t CHANNEL6 = 5;
        static const uint8_t CHANNEL7 = 6;
        static const uint8_t CHANNEL8 = 7;
        uint8_t value;
        ChannelEnum(uint8_t value);
        uint8_t getValue();
};

class PwmGen {

    public:
        PwmGen();
        void init();
        void setChannelValueZeroToOne(ChannelEnum channel, float value);


        bool testMode;
        float testChannelValues[8];
        float getChannelValueZeroToOne(ChannelEnum channel);
};
# 9 "include/PwmCapture.h" 2



enum CaptureTimerIndex { TIMER3=0, TIMER4=1 };

class PwmCapture {
    public:
        PwmCapture();
        void init();
        float getChannelValueZeroToOne(ChannelEnum channel);
        void irqHandler(CaptureTimerIndex timerIndex);
        void irqChannelHandler(CaptureTimerIndex timerIndex, int channel);
        bool isReceiverSignalOK();

    private:
        uint32_t chanRisingCount[2][4];
        uint32_t chanPulseWidth[2][4];
        long timeOfLastCapture;


        bool testMode;
        float testChannelValues[8];
        friend void test_PwmCapture1();
        friend void test_tailServoReactionToYaw();
        friend void test_tailServoReactionToYaw2();
        void TEST_ONLY_setChannelValueZeroToOne(ChannelEnum channel, float value);
};
# 18 "include/ControlTask.h" 2


# 1 "include/Aircraft.h" 1






# 1 "include/Pid.h" 1





class Pid {
    private:
        float totalError;
        float previousError;
        PidConfig* config;

    public:
        float p,i,d;
        Pid(PidConfig* pidCOnfig);
        float calculate(float error);
};
# 8 "include/Aircraft.h" 2


class Aircraft {
    public:
        Aircraft(SensorTask* sensorTask, PwmCapture* pwmCapture, PwmGen* pwmGen);
        virtual void init() = 0;
        virtual void updatePassThroughOpenLoopControl() = 0;
        virtual void updateGyroOnlyClosedLoopControl() = 0;
        virtual void updateFullClosedLoopControl() = 0;
        virtual void updateSemiAutonomousClosedLoopControl() = 0;
        virtual Quaternion* getNewAttitudeForGyroFeedback() = 0;

    protected:
        SensorTask* sensorTask;
        PwmCapture* pwmCapture;
        PwmGen* pwmGen;

    private:

};
# 21 "include/ControlTask.h" 2
# 1 "include/Helicopter.h" 1





namespace ReceiverChannel {
    enum RC {
        COLLECTIVE=ChannelEnum::CHANNEL1,
        ROLL=ChannelEnum::CHANNEL2,
        PITCH=ChannelEnum::CHANNEL3,
        YAW=ChannelEnum::CHANNEL4,
        THROTTLE=ChannelEnum::CHANNEL6,
        MODE=ChannelEnum::CHANNEL7,
        PID_ADJUST=ChannelEnum::CHANNEL8
   };
}
namespace ServoChannel {
    enum SC {
        CCPM_30=ChannelEnum::CHANNEL2,
        CCPM_150=ChannelEnum::CHANNEL3,
        CCPM_270=ChannelEnum::CHANNEL1,
        THROTTLE=ChannelEnum::CHANNEL6,
        TAIL_ROTOR=ChannelEnum::CHANNEL4
   };
}

class Helicopter : public Aircraft {
    public:
        Helicopter(SensorTask* sensorTask, PwmCapture* pwmCapture, PwmGen* pwmGen);
        ~Helicopter();
        void init();
        void updatePassThroughOpenLoopControl();
        void updateGyroOnlyClosedLoopControl();
        void updateFullClosedLoopControl();
        void updateSemiAutonomousClosedLoopControl();
        Quaternion* getNewAttitudeForGyroFeedback();

    private:
        Pid* pitchPid = 0;
        Pid* rollPid = 0;
        Pid* yawPid = 0;
        void ccpmPwmGenerate(PwmGen* pwmGen, float collective0to1, float pitch0to1, float roll0to1);
        bool isHovering();
        bool isInCoordinatedFlight();
};
# 22 "include/ControlTask.h" 2



enum class ControlState {
    CONTROL_PASS_THROUGH_OPEN_LOOP=0,
    GYRO_ONLY_CLOSED_LOOP=1,
    FULL_CLOSED_LOOP=2,
    SEMI_AUTONOMOUS_CLOSED_LOOP=3,
};


class ControlTask : public TaskClass {
  public:
    ControlTask(SensorTask* sensorTask);
    void init();
    void task();
    stlpmtx_std::string getControlStateLabel(ControlState controlState);
    void controlGyroDrift();
    ControlState getControlState();

  private:
    SensorTask* sensorTask;
    PwmCapture* pwmCapture;
    PwmGen* pwmGen;
    Aircraft* aircraft;
    ControlState controlState;

    bool isStartingControlledFlight(ControlState controlState, ControlState requestedControlState, bool isGpsLocked, bool isReceiverActive);
    ControlState getNextState(ControlState controlState, ControlState requestedControlState, bool isGpsLocked, bool isReceiverActive);
    void processState(ControlState controlState);

    ControlState getRequestedControlState();
    Aircraft* instantiateAircraft();
    bool isReceiverSignalOK();

    void updatePassThroughOpenLoopControl();
    void updateGyroOnlyClosedLoopControl();
    void updateFullClosedLoopControl();
    void updateSemiAutonomousClosedLoopControl();


    friend void test_isStartingControlledFlight();
    friend void test_getNextState();
};
# 3 "C:/projects/flight/firmware/test/ControlTask_test.cpp" 2


static void setUp(void) {
}

static void tearDown(void) {
}

static void test_ControlStateLabels() {
    ControlTask ct = ControlTask(0);
    if (ct.getControlStateLabel(ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP).find("pass-through", 20) >= 0) {} else {if (0) {} else {addFailure("ct.getControlStateLabel(ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP).find(\"pass-through\", 20) >= 0",13,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};}
    if (ct.getControlStateLabel(ControlState::GYRO_ONLY_CLOSED_LOOP).find("Gyro", 10) >= 0) {} else {if (0) {} else {addFailure("ct.getControlStateLabel(ControlState::GYRO_ONLY_CLOSED_LOOP).find(\"Gyro\", 10) >= 0",14,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};}
    if (ct.getControlStateLabel(ControlState::FULL_CLOSED_LOOP).find("Full", 10) >= 0) {} else {if (0) {} else {addFailure("ct.getControlStateLabel(ControlState::FULL_CLOSED_LOOP).find(\"Full\", 10) >= 0",15,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};}
    if (ct.getControlStateLabel(ControlState::SEMI_AUTONOMOUS_CLOSED_LOOP).find("Semi-autonomous", 20) >= 0) {} else {if (0) {} else {addFailure("ct.getControlStateLabel(ControlState::SEMI_AUTONOMOUS_CLOSED_LOOP).find(\"Semi-autonomous\", 20) >= 0",16,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};}
}

void test_isStartingControlledFlight() {
    ControlTask controlTask = ControlTask(0);
    ControlState currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    ControlState requestedState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    bool isGpsLocked = false;
    bool isReceiverActive = false;
    if (false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)",25,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = false;
    isReceiverActive = true;;
    if (false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)",31,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = true;
    if (false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("false == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)",36,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = true;
    if (true == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("true == controlTask.isStartingControlledFlight(currentState, requestedState, isGpsLocked, isReceiverActive)",41,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};
}

void test_getNextState() {
    ControlTask controlTask = ControlTask(0);
    ControlState currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    ControlState requestedState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    bool isGpsLocked = false;
    bool isReceiverActive = false;
    if (ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",50,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    requestedState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    isGpsLocked = false;
    if (ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",55,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    requestedState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    isGpsLocked = false;
    if (ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",60,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::CONTROL_PASS_THROUGH_OPEN_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = false;
    if (ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",65,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = true;
    if (ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",70,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isReceiverActive = true;
    isGpsLocked = true;
    if (ControlState::FULL_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::FULL_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",76,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::FULL_CLOSED_LOOP;
    isGpsLocked = false;
    if (ControlState::FULL_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::FULL_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",81,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};

    currentState = ControlState::FULL_CLOSED_LOOP;
    requestedState = ControlState::GYRO_ONLY_CLOSED_LOOP;
    isGpsLocked = true;
    if (ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)) {} else {if (0) {} else {addFailure("ControlState::GYRO_ONLY_CLOSED_LOOP == controlTask.getNextState(currentState, requestedState, isGpsLocked, isReceiverActive)",86,"C:/projects/flight/firmware/test/ControlTask_test.cpp");return;};};
}

TestRef ControlTask_tests(void) {
    static const TestFixture fixtures[] = {
        { "test_ControlStateLabels", test_ControlStateLabels, },
        { "test_isStartingControlledFlight", test_isStartingControlledFlight, },
        { "test_getNextState", test_getNextState, }
    };

    static const TestCaller ControlTask_tests = { (TestImplement*)&TestCallerImplement, "ControlTask_tests", setUp, tearDown, sizeof(fixtures)/sizeof(fixtures[0]), (TestFixture*)fixtures, };
    return (TestRef)&ControlTask_tests;
}
