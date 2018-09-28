#ifndef __UT_UTILS_H__
#define __UT_UTILS_H__

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Macros to convert back and forward between ticks and real time.
//
//*****************************************************************************

  //*************** clock frequency 80Mhz   ******************//
#define MAP_SysCtlClockGet 80000000
extern unsigned long g_ulClockRate;
#define MILLISECONDS_TO_TICKS(ms) ((g_ulClockRate / 1000) * (ms))
#define MICROSECONDS_TO_TICKS(us) ((g_ulClockRate / 1000000) * (us))
#define TICKS_TO_MILLISECONDS(ticks)                                          \
    (((ticks) / g_ulClockRate) * 1000 +                                       \
     ((((ticks)%g_ulClockRate) * 1000) / g_ulClockRate))

//*****************************************************************************
//
// The largest value of ulTicks%g_ulClockRate that can be converted to
// milliseconds using the macro above. Values larger than this will cause
// overflow and result in incorrect results. This value is (2^32)/1000.
//
//*****************************************************************************
#define MAX_TICKS_FOR_MS_CONVERSION 4294967

//*****************************************************************************
//
// Test result. This enum is used to pass the final  result from each
// case to the framework which will then report the result to the host.
// TEST_SKIPPED may be used by the testcase if it is not possible to run the
// test given the parameters provided, for example a test which requires
// user interaction and has no automatic alternative may report TEST_SKIPPED
// if passed tTestParams->bInteractive set to FALSE.
//
//*****************************************************************************
typedef enum
{
    TEST_PASSED,
    TEST_FAILED,
    TEST_SKIPPED
}
tTestResult;

//*****************************************************************************
//
// Function prototypes
//
//*****************************************************************************
extern tBoolean SysTickInit(void);

extern unsigned long UTUtilsGetSysTime(void);

extern tBoolean UTUtilsWaitForCount(volatile unsigned long *pulCount,
                                    unsigned long ulTarget,
                                    unsigned long ulTimeoutMs);
extern void SysCtlDelay(unsigned long ulCount);
extern void UTUtilsDelay(unsigned long ulTimeoutMicroS);
extern void UTUtilsDelayCycles(unsigned long ulTimeoutCycles);
extern unsigned long UTUtilsSysTickValueGet(void);

#ifdef __cplusplus
}
#endif

#endif // __UT_UTILS_H__
