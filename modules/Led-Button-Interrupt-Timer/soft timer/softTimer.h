#ifndef SOFT_TIMER_H
#define SOFT_TIMER_H

#define TIMER_COUNT			2		// istenilen soft counter sayisi
//
#define TIMER_BUTTON		0
#define TIMER_LED			1

//
// soft timers array
//
typedef struct{
	bool			IsRunning;		// timer calisma durumu
	volatile bool	Timeout;		// timer tamamlanma durumu
	uint32_t 		SetTime;		// timer suresi
	uint32_t		Time;			// aktif sure
}STimerType;

extern STimerType SoftTimers[TIMER_COUNT];

#define INIT_SOFTTIMER	{					\
						false, false, 0, 0	\
						}					\

#define INIT_SOFTTIMERS	{				\
						INIT_SOFTTIMER,	\
						INIT_SOFTTIMER	\
						}				\

void SoftTimer_Init(void);
void SoftTimer_ISR(void); 
void SoftTimer_SetTimer(uint8_t TimerNo, uint32_t SetTimeMs);
bool SoftTimer_GetTimerStatus(uint8_t TimerNo);
void SoftTimer_ResetTimer(uint8_t TimerNo);

#endif
