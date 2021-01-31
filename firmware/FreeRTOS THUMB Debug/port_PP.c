# 1 "c:\\projects\\freertos\\src\\portable\\port.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
# 71 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
# 1 "c:\\projects\\freertos\\src\\include\\freertos.h" 1
# 72 "c:\\projects\\freertos\\src\\include\\freertos.h"
# 1 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stddef.h" 1 3 4
# 14 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stddef.h" 3 4
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
# 15 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stddef.h" 2 3 4







typedef unsigned size_t;






typedef int ptrdiff_t;
# 45 "C:/Program Files (x86)/Rowley Associates Limited/CrossWorks for ARM 3.3/include/stddef.h" 3 4
typedef unsigned wchar_t;
# 73 "c:\\projects\\freertos\\src\\include\\freertos.h" 2
# 87 "c:\\projects\\freertos\\src\\include\\freertos.h"
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
# 88 "c:\\projects\\freertos\\src\\include\\freertos.h" 2






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
# 322 "c:\\projects\\freertos\\src\\include\\portable.h" 2
# 352 "c:\\projects\\freertos\\src\\include\\portable.h"
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
# 107 "c:\\projects\\freertos\\src\\include\\freertos.h" 2
# 72 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c" 2
# 1 "c:\\projects\\freertos\\src\\include\\task.h" 1
# 74 "c:\\projects\\freertos\\src\\include\\task.h"
# 1 "c:\\projects\\freertos\\src\\include\\list.h" 1
# 136 "c:\\projects\\freertos\\src\\include\\list.h"
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
# 75 "c:\\projects\\freertos\\src\\include\\task.h" 2
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
# 73 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c" 2
# 140 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
static UBaseType_t uxCriticalNesting = 0xaaaaaaaa;






void vPortSetupTimerInterrupt( void );




void PendSV_Handler( void ) __attribute__ (( naked ));
void SysTick_Handler( void );
void SVC_Handler( void ) __attribute__ (( naked ));




static void prvPortStartFirstTask( void ) __attribute__ (( naked ));




 static void vPortEnableVFP( void ) __attribute__ (( naked ));




static void prvTaskExitError( void );
# 202 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
  static uint8_t ucMaxSysCallPriority = 0;
  static uint32_t ulMaxPRIGROUPValue = 0;
  static const volatile uint8_t * const pcInterruptPriorityRegisters = ( const volatile uint8_t * const ) ( 0xE000E3F0 );







StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
{





 pxTopOfStack--;

 *pxTopOfStack = ( 0x01000000 );
 pxTopOfStack--;
 *pxTopOfStack = ( StackType_t ) pxCode;
 pxTopOfStack--;
 *pxTopOfStack = ( StackType_t ) prvTaskExitError;


 pxTopOfStack -= 5;
 *pxTopOfStack = ( StackType_t ) pvParameters;



 pxTopOfStack--;
 *pxTopOfStack = ( 0xfffffffd );

 pxTopOfStack -= 8;

 return pxTopOfStack;
}


static void prvTaskExitError( void )
{






 if( ( uxCriticalNesting == ~0UL ) == 0 ) { ulPortSetInterruptMask(); for( ;; ); };
 ulPortSetInterruptMask();
 for( ;; );
}


void SVC_Handler( void )
{
 __asm volatile (
     "	ldr	r3, pxCurrentTCBConst2		\n"
     "	ldr r1, [r3]					\n"
     "	ldr r0, [r1]					\n"
     "	ldmia r0!, {r4-r11, r14}		\n"
     "	msr psp, r0						\n"
     "	isb								\n"
     "	mov r0, #0 						\n"
     "	msr	basepri, r0					\n"
     "	bx r14							\n"
     "									\n"
     "	.align 2						\n"
     "pxCurrentTCBConst2: .word pxCurrentTCB				\n"
    );
}


static void prvPortStartFirstTask( void )
{
 __asm volatile(
     " ldr r0, =0xE000ED08 	\n"
     " ldr r0, [r0] 			\n"
     " ldr r0, [r0] 			\n"
     " msr msp, r0			\n"
     " cpsie i				\n"
     " dsb					\n"
     " isb					\n"
     " svc 0					\n"
     " nop					\n"
    );
}





BaseType_t xPortStartScheduler( void )
{


 if( ( ( 5 << (8 - 6) ) ) == 0 ) { ulPortSetInterruptMask(); for( ;; ); };


 {
  volatile uint32_t ulOriginalPriority;
  volatile uint8_t * const pucFirstUserPriorityRegister = ( volatile uint8_t * const ) ( ( 0xE000E3F0 ) + ( 16 ) );
  volatile uint8_t ucMaxPriorityValue;







  ulOriginalPriority = *pucFirstUserPriorityRegister;



  *pucFirstUserPriorityRegister = ( ( uint8_t ) 0xff );


  ucMaxPriorityValue = *pucFirstUserPriorityRegister;


  ucMaxSysCallPriority = ( 5 << (8 - 6) ) & ucMaxPriorityValue;



  ulMaxPRIGROUPValue = ( ( uint8_t ) 7 );
  while( ( ucMaxPriorityValue & ( ( uint8_t ) 0x80 ) ) == ( ( uint8_t ) 0x80 ) )
  {
   ulMaxPRIGROUPValue--;
   ucMaxPriorityValue <<= ( uint8_t ) 0x01;
  }



  ulMaxPRIGROUPValue <<= ( 8UL );
  ulMaxPRIGROUPValue &= ( 0x07UL << 8UL );



  *pucFirstUserPriorityRegister = ulOriginalPriority;
 }



 ( * ( ( volatile uint32_t * ) 0xe000ed20 ) ) |= ( ( ( uint32_t ) ( 0x3f << (8 - 6) ) ) << 16UL );
 ( * ( ( volatile uint32_t * ) 0xe000ed20 ) ) |= ( ( ( uint32_t ) ( 0x3f << (8 - 6) ) ) << 24UL );



 vPortSetupTimerInterrupt();


 uxCriticalNesting = 0;


 vPortEnableVFP();


 *( ( ( volatile uint32_t * ) 0xe000ef34 ) ) |= ( 0x3UL << 30UL );


 prvPortStartFirstTask();





 prvTaskExitError();


 return 0;
}


void vPortEndScheduler( void )
{


 if( ( uxCriticalNesting == 1000UL ) == 0 ) { ulPortSetInterruptMask(); for( ;; ); };
}


void vPortYield( void )
{

 ( * ( ( volatile uint32_t * ) 0xe000ed04 ) ) = ( 1UL << 28UL );



 __asm volatile( "dsb" );
 __asm volatile( "isb" );
}


void vPortEnterCritical( void )
{
 ulPortSetInterruptMask();
 uxCriticalNesting++;
 __asm volatile( "dsb" );
 __asm volatile( "isb" );
}


void vPortExitCritical( void )
{
 if( ( uxCriticalNesting ) == 0 ) { ulPortSetInterruptMask(); for( ;; ); };
 uxCriticalNesting--;
 if( uxCriticalNesting == 0 )
 {
  vPortClearInterruptMask(0);
 }
}


__attribute__(( naked )) uint32_t ulPortSetInterruptMask( void )
{
 __asm volatile
 (
  "	mrs r0, basepri											\n"
  "	mov r1, %0												\n"
  "	msr basepri, r1											\n"
  "	bx lr													\n"
  :: "i" ( ( 5 << (8 - 6) ) ) : "r0", "r1"
 );



 return 0;
}


__attribute__(( naked )) void vPortClearInterruptMask( uint32_t ulNewMaskValue )
{
 __asm volatile
 (
  "	msr basepri, r0										\n"
  "	bx lr												\n"
  :::"r0"
 );


 ( void ) ulNewMaskValue;
}


void PendSV_Handler( void )
{


 __asm volatile
 (
 "	mrs r0, psp							\n"
 "	isb									\n"
 "										\n"
 "	ldr	r3, pxCurrentTCBConst			\n"
 "	ldr	r2, [r3]						\n"
 "										\n"
 "	tst r14, #0x10						\n"
 "	it eq								\n"
 "	vstmdbeq r0!, {s16-s31}				\n"
 "										\n"
 "	stmdb r0!, {r4-r11, r14}			\n"
 "										\n"
 "	str r0, [r2]						\n"
 "										\n"
 "	stmdb sp!, {r3}						\n"
 "	mov r0, %0 							\n"
 "	msr basepri, r0						\n"
 "	bl vTaskSwitchContext				\n"
 "	mov r0, #0							\n"
 "	msr basepri, r0						\n"
 "	ldmia sp!, {r3}						\n"
 "										\n"
 "	ldr r1, [r3]						\n"
 "	ldr r0, [r1]						\n"
 "										\n"
 "	ldmia r0!, {r4-r11, r14}			\n"
 "										\n"
 "	tst r14, #0x10						\n"
 "	it eq								\n"
 "	vldmiaeq r0!, {s16-s31}				\n"
 "										\n"
 "	msr psp, r0							\n"
 "	isb									\n"
 "										\n"






 "										\n"
 "	bx r14								\n"
 "										\n"
 "	.align 2							\n"
 "pxCurrentTCBConst: .word pxCurrentTCB	\n"
 ::"i"(( 5 << (8 - 6) ))
 );
}


void SysTick_Handler( void )
{




 ( void ) ulPortSetInterruptMask();
 {

  if( xTaskIncrementTick() != ( ( BaseType_t ) 0 ) )
  {


   ( * ( ( volatile uint32_t * ) 0xe000ed04 ) ) = ( 1UL << 28UL );
  }
 }
 vPortClearInterruptMask(0);
}
# 678 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
__attribute__(( weak )) void vPortSetupTimerInterrupt( void )
{
# 690 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
 ( * ( ( volatile uint32_t * ) 0xe000e014 ) ) = ( ( SystemCoreClock ) / ( ( TickType_t ) 1000 ) ) - 1UL;
 ( * ( ( volatile uint32_t * ) 0xe000e010 ) ) = ( ( 1UL << 2UL ) | ( 1UL << 1UL ) | ( 1UL << 0UL ) );
}



static void vPortEnableVFP( void )
{
 __asm volatile
 (
  "	ldr.w r0, =0xE000ED88		\n"
  "	ldr r1, [r0]				\n"
  "								\n"
  "	orr r1, r1, #( 0xf << 20 )	\n"
  "	str r1, [r0]				\n"
  "	bx r14						"
 );
}




 void vPortValidateInterruptPriority( void )
 {
 uint32_t ulCurrentInterrupt;
 uint8_t ucCurrentPriority;


  __asm volatile( "mrs %0, ipsr" : "=r"( ulCurrentInterrupt ) );


  if( ulCurrentInterrupt >= ( 16 ) )
  {

   ucCurrentPriority = pcInterruptPriorityRegisters[ ulCurrentInterrupt ];
# 749 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
   if( ( ucCurrentPriority >= ucMaxSysCallPriority ) == 0 ) { ulPortSetInterruptMask(); for( ;; ); };
  }
# 765 "C:/projects/flight/firmware/../../freeRtos/src/portable/port.c"
  if( ( ( ( * ( ( volatile uint32_t * ) 0xE000ED0C ) ) & ( 0x07UL << 8UL ) ) <= ulMaxPRIGROUPValue ) == 0 ) { ulPortSetInterruptMask(); for( ;; ); };
 }
