/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009, 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief FreeOSEK Os Generated Internal Configuration Implementation File
 **
 ** \file Os_Internal_Cfg.c
 **
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_Os
 ** @{ */
/** \addtogroup FreeOSEK_Os_Internal
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 * JuCe         Juan Cecconi
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20150619 v0.1.4 MaCe fix issue #279
 * 20141125 v0.1.3 JuCe additional stack for x86 ARCH
 * 20090719 v0.1.2 MaCe rename file to Os_
 * 20090128 v0.1.1 MaCe add OSEK_MEMMAP check
 * 20080713 v0.1.0 MaCe initial version
 */

/*==================[inclusions]=============================================*/
#include "Os_Internal.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/
/** \brief InitTask stack */
#if ( x86 == ARCH )
uint8 StackTaskInitTask[512 + TASK_STACK_ADDITIONAL_SIZE];
#else
uint8 StackTaskInitTask[512];
#endif
/** \brief MatrizTask stack */
#if ( x86 == ARCH )
uint8 StackTaskMatrizTask[512 + TASK_STACK_ADDITIONAL_SIZE];
#else
uint8 StackTaskMatrizTask[512];
#endif
/** \brief SwitchesTask stack */
#if ( x86 == ARCH )
uint8 StackTaskSwitchesTask[512 + TASK_STACK_ADDITIONAL_SIZE];
#else
uint8 StackTaskSwitchesTask[512];
#endif
/** \brief RegistrosTask stack */
#if ( x86 == ARCH )
uint8 StackTaskRegistrosTask[512 + TASK_STACK_ADDITIONAL_SIZE];
#else
uint8 StackTaskRegistrosTask[512];
#endif

/** \brief InitTask context */
TaskContextType ContextTaskInitTask;
/** \brief MatrizTask context */
TaskContextType ContextTaskMatrizTask;
/** \brief SwitchesTask context */
TaskContextType ContextTaskSwitchesTask;
/** \brief RegistrosTask context */
TaskContextType ContextTaskRegistrosTask;

/** \brief Ready List for Priority 3 */
TaskType ReadyList3[1];

/** \brief Ready List for Priority 2 */
TaskType ReadyList2[1];

/** \brief Ready List for Priority 1 */
TaskType ReadyList1[1];

/** \brief Ready List for Priority 0 */
TaskType ReadyList0[1];

const AlarmType OSEK_ALARMLIST_HardwareCounter[3] = {
   ActivateMatrizTask, /* this alarm has to be incremented with this counter */
   ActivateSwitchesTask, /* this alarm has to be incremented with this counter */
   ActivateRegistrosTask, /* this alarm has to be incremented with this counter */
};


/*==================[external data definition]===============================*/
/* FreeOSEK to configured priority table
 *
 * This table show the relationship between the user selected
 * priorities and the OpenOSE priorities:
 *
 * User P.         Osek P.
 * 4               3
 * 3               2
 * 2               1
 * 1               0
 */

const TaskConstType TasksConst[TASKS_COUNT] = {
   /* Task InitTask */
   {
       OSEK_TASK_InitTask,   /* task entry point */
       &ContextTaskInitTask, /* pointer to task context */
       StackTaskInitTask, /* pointer stack memory */
       sizeof(StackTaskInitTask), /* stack size */
       0, /* task priority */
       1, /* task max activations */
       {
         1, /* extended task */
         0, /* non preemtive task */
         0
      }, /* task const flags */
      0 | POSIXE , /* events mask */
      0 | ( 1 << POSIXR ) /* resources mask */
   },
   /* Task MatrizTask */
   {
       OSEK_TASK_MatrizTask,   /* task entry point */
       &ContextTaskMatrizTask, /* pointer to task context */
       StackTaskMatrizTask, /* pointer stack memory */
       sizeof(StackTaskMatrizTask), /* stack size */
       2, /* task priority */
       1, /* task max activations */
       {
         1, /* extended task */
         0, /* non preemtive task */
         0
      }, /* task const flags */
      0 | POSIXE , /* events mask */
      0 | ( 1 << POSIXR ) /* resources mask */
   },
   /* Task SwitchesTask */
   {
       OSEK_TASK_SwitchesTask,   /* task entry point */
       &ContextTaskSwitchesTask, /* pointer to task context */
       StackTaskSwitchesTask, /* pointer stack memory */
       sizeof(StackTaskSwitchesTask), /* stack size */
       3, /* task priority */
       1, /* task max activations */
       {
         1, /* extended task */
         0, /* non preemtive task */
         0
      }, /* task const flags */
      0 | POSIXE , /* events mask */
      0 | ( 1 << POSIXR ) /* resources mask */
   },
   /* Task RegistrosTask */
   {
       OSEK_TASK_RegistrosTask,   /* task entry point */
       &ContextTaskRegistrosTask, /* pointer to task context */
       StackTaskRegistrosTask, /* pointer stack memory */
       sizeof(StackTaskRegistrosTask), /* stack size */
       1, /* task priority */
       1, /* task max activations */
       {
         1, /* extended task */
         0, /* non preemtive task */
         0
      }, /* task const flags */
      0 | POSIXE , /* events mask */
      0 | ( 1 << POSIXR ) /* resources mask */
   }
};

/** \brief TaskVar Array */
TaskVariableType TasksVar[TASKS_COUNT];

/** \brief List of Auto Start Tasks in Application Mode AppMode1 */
const TaskType TasksAppModeAppMode1[1]  = {
   InitTask
};
/** \brief AutoStart Array */
const AutoStartType AutoStart[1]  = {
   /* Application Mode AppMode1 */
   {
      1, /* Total Auto Start Tasks in this Application Mode */
      (TaskRefType)TasksAppModeAppMode1 /* Pointer to the list of Auto Start Stacks on this Application Mode */
   }
};

const ReadyConstType ReadyConst[4] = { 
   {
      1, /* Length of this ready list */
      ReadyList3 /* Pointer to the Ready List */
   },
   {
      1, /* Length of this ready list */
      ReadyList2 /* Pointer to the Ready List */
   },
   {
      1, /* Length of this ready list */
      ReadyList1 /* Pointer to the Ready List */
   },
   {
      1, /* Length of this ready list */
      ReadyList0 /* Pointer to the Ready List */
   }
};

/** TODO replace next line with: 
 ** ReadyVarType ReadyVar[4] ; */
ReadyVarType ReadyVar[4];

/** \brief Resources Priorities */
const TaskPriorityType ResourcesPriority[1]  = {
   3
};
/** TODO replace next line with: 
 ** AlarmVarType AlarmsVar[3]; */
AlarmVarType AlarmsVar[3];

const AlarmConstType AlarmsConst[3]  = {
   {
      OSEK_COUNTER_HardwareCounter, /* Counter */
      ACTIVATETASK, /* Alarm action */
      {
         NULL, /* no callback */
         MatrizTask, /* TaskID */
         0, /* no event */
         0 /* no counter */
      },
   },
   {
      OSEK_COUNTER_HardwareCounter, /* Counter */
      ACTIVATETASK, /* Alarm action */
      {
         NULL, /* no callback */
         SwitchesTask, /* TaskID */
         0, /* no event */
         0 /* no counter */
      },
   },
   {
      OSEK_COUNTER_HardwareCounter, /* Counter */
      ACTIVATETASK, /* Alarm action */
      {
         NULL, /* no callback */
         RegistrosTask, /* TaskID */
         0, /* no event */
         0 /* no counter */
      },
   }
};

const AutoStartAlarmType AutoStartAlarm[ALARM_AUTOSTART_COUNT] = {

};

CounterVarType CountersVar[1];

const CounterConstType CountersConst[1] = {
   {
      3, /* quantity of alarms for this counter */
      (AlarmType*)OSEK_ALARMLIST_HardwareCounter, /* alarms list */
      1000, /* max allowed value */
      1, /* min cycle */
      1 /* ticks per base */
   }
};


/** TODO replace the next line with
 ** uint8 ApplicationMode; */
uint8 ApplicationMode;

/** TODO replace the next line with
 ** uint8 ErrorHookRunning; */
uint8 ErrorHookRunning;

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

