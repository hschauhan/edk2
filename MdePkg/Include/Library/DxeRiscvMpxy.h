/** @file
  This module implements functions to be used by MPXY client

  Copyright (c) 2024, Ventana Micro Systems, Inc.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef SBI_MPXY_H_
#define SBI_MPXY_H_

/**
  Open specified MPXY channel for communication. It will allocate the shared
  memory or resize the previous one if required.

  @param[in] ChannelId  The channel to be initialized
  @retval EFI_SUCCESS   If the allocation or resize of shared memory was
                        successfully done.
**/
EFI_STATUS
EFIAPI
SbiMpxyChannelOpen(
  IN UINTN ChannelId
  );

/**
  Close the specified MPXY channel.

  @param[in] ChannelId  The channel to be uninitialized
  @retval EFI_SUCCESS   If the allocation or resize of shared memory was
                        successfully done.
**/
EFI_STATUS
EFIAPI
SbiMpxyChannelClose(
  IN UINTN ChannelId
  );

/**
  Send a message with response over Mpxy.

  @param[in] ChannelId       The Channel on which message would be sent
  @param[in] MessageId       Message protocol specific message identification
  @param[in] MessageDataLen  Length of the message to be sent
  @param[in] Message         Pointer to buffer containing message
  @param[in] Response        Pointer to buffer to which response should be written
  @param[in] ResponseLen     Pointer where the size of response should be written

  @retval EFI_SUCCESS    The shared memory was disabled
  @retval Other          Some error occured during the operation
**/
EFI_STATUS
EFIAPI
SbiMpxySendMessage(
  IN UINTN ChannelId,
  IN UINTN MessageId,
  IN VOID *Message,
  IN UINTN MessageDataLen,
  OUT VOID *Response,
  OUT UINTN *ResponseLen
  );

#endif

