/** @file
  Definitions for the TraceHubHook Lib.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __TRACE_HUB_HOOK_LIB_H__
#define __TRACE_HUB_HOOK_LIB_H__

/**
  Return TraceHub Trace Address.

  @param [in] Thread          Master is being used.
  @param [in] Channel         Channel is being used.
  @param [out] TraceAddress   TraceHub Address for the Master/Channel
                              is being used.

  @retval RETURN_SUCCESS      Retrieve correct Address.
  @retval RETURN_UNSUPPORTED  Not implemented.
  @retval Other               Fail to Retrieve correct TraceHub Address.

**/
RETURN_STATUS
EFIAPI
TraceHubMmioTraceAddress (
  IN  UINT32    Master,
  IN  UINT32    Channel,
  OUT UINT32    *TraceAddress
  );

/**
  Return Scratch Pad2 Register Value.

  @param [out] ScratchPad2RegValue Scratch Pad2 Register Value.

  @retval RETURN_SUCCESS      Retrieve Scratch Pad2 Register Value.
  @retval RETURN_UNSUPPORTED  Not implemented.
  @retval Other               Fail to Retrieve Scratch Pad2 Register Value.

**/
RETURN_STATUS
EFIAPI
TraceHubScratchPad2RegValue (
  OUT UINT8    *ScratchPad2RegValue
  );

#endif // _TRACE_HUB_LIB_H_
