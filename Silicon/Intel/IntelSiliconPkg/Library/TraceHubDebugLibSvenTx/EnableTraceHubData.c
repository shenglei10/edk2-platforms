/** @file
  Implementation of TraceHub Filter.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Base.h>
#include <Library/DebugLib.h>
#include <Library/TraceHubHookLib.h>
#include "EnableTraceHubData.h"

/**
  Determine whether to enable BIOS Debug Message tracing to Trace Hub.

  @param  SeverityType    The severity level of data.

  @retval TRUE            Enable trace hub data.
  @retval FALSE           Disable trace hub data.

**/
BOOLEAN
EFIAPI
EnableTraceHubData (
  IN TRACE_HUB_SEVERITY_TYPE    SeverityType
  )
{
  UINT8         RegValue;
  RETURN_STATUS Status;
  UINT8         Routing;
  UINT8         DebugLevel;
  BOOLEAN       Enable;

  //
  // ScratchPad2 Register is not found. The message will always be enabled.
  //
  RegValue = 0;
  Status   = TraceHubScratchPad2RegValue (&RegValue);
  if (RETURN_ERROR (Status)) {
    return TRUE;
  }

  Routing = RegValue & BIT0;
  if (Routing == TraceHubRoutingDisable) {
    return FALSE;
  }

  Enable = FALSE;
  DebugLevel = (RegValue & (BIT1 | BIT2)) >> 1;
  if (DebugLevel == TraceHubDebugLevelError) {
    if ((SeverityType == SeverityFatal || SeverityType == SeverityError)) {
      Enable = TRUE;
    }
  } else if (DebugLevel == TraceHubDebugLevelErrorWarning) {
    if ((SeverityType == SeverityFatal ||
          SeverityType == SeverityError ||
          SeverityType == SeverityWarning)) {
      Enable = TRUE;
    }
  } else if (DebugLevel == TraceHubDebugLevelErrorWarningInfo) {
    if ((SeverityType == SeverityFatal ||
          SeverityType == SeverityError ||
          SeverityType == SeverityWarning ||
          SeverityType == SeverityNormal)) {
      Enable = TRUE;
    }
  } else if (DebugLevel == TraceHubDebugLevelErrorWarningInfoVerbose) {
    Enable = TRUE;
  }

  return Enable;
}
