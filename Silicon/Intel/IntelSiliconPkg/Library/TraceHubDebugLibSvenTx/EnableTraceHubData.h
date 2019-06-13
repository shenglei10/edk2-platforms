/** @file
  BIOS Debug Message Tracing Catalog

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __ENABLE_TRACE_HUB_DATA_H__
#define __ENABLE_TRACE_HUB_DATA_H__

#include <Library/TraceHubDebugLib.h>

typedef enum {
  TraceHubRoutingDisable = 0,
  TraceHubRoutingEnable,
  TraceHubRoutingMax
} TRACE_HUB_ROUTING;

typedef enum {
  TraceHubDebugLevelError = 0,
  TraceHubDebugLevelErrorWarning,
  TraceHubDebugLevelErrorWarningInfo,
  TraceHubDebugLevelErrorWarningInfoVerbose,
  TraceHubDebugLevelMax
} TRACE_HUB_DEBUG_LEVEL;

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
  );

#endif // __TRACE_HUB_DISCARD_DATA_H__
