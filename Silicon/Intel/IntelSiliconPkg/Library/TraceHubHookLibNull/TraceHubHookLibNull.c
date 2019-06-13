/** @file
  Null instance of TraceHub Hook Lib.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Base.h>

/**
  Calculate TraceHub Trace Address.
  Dummy function call, should be implemented by Platform

  @param  Master         Master is being used.
  @param  Channel        Channel is being used.
  @param  TraceAddress   TraceHub Address for the Master/Channel is being used.

  @retval                RETURN_UNSUPPORTED  Not implemented.

**/
RETURN_STATUS
EFIAPI
TraceHubMmioTraceAddress (
  IN  UINT16    Master,
  IN  UINT16    Channel,
  OUT UINT32    *TraceAddress
  )
{
  return RETURN_UNSUPPORTED;
}

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
  )
{
  return RETURN_UNSUPPORTED;
}
