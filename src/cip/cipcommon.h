/*******************************************************************************
 * Copyright (c) 2009, Rockwell Automation, Inc.
 * All rights reserved. 
 *
 ******************************************************************************/
#ifndef CIPCOMMON_H_
#define CIPCOMMON_H_

#include "typedefs.h"
#include "ciptypes.h"

/*! A buffer for holding the replay generated by explicit message requests 
 *  or producing I/O connections. These will use this buffer in the following
 *  ways:
 *    1. Explicit messages will use this buffer to store the data generated by the request
 *    2. I/O Connections will use this buffer for the produced data
 */
extern EIP_UINT8 g_acMessageDataReplyBuffer[];

/** \brief  Check if requested service present in class/instance and call appropriate service.
 *
 * @param pt2Class class receiving the message
 * @param pa_MRRequest request message
 * @param pa_MRResponse reply message
 * @return
 *     - EIP_OK_SEND    ... success
 *     - EIP_OK  ... no reply to send back
 *     - EIP_ERROR ... error
 */
EIP_STATUS notifyClass(S_CIP_Class *pt2Class, S_CIP_MR_Request *pa_MRRequest, S_CIP_MR_Response *pa_MRResponse);

/*! \brief generic implementation of the GetAttributeSingle CIP service
 *  Check from classID which Object requests an attribute, search if object has
 *  the appropriate attribute implemented.
 * @param pa_pstInstance pointer to instance.
 * @param pa_pstMRRequest pointer to request.
 * @param pa_pstMRResponse pointer to response.
 * @param pa_acMsg pointer to memory where response should be written
 * @return status  >0 .. success
 *          -1 .. requested attribute not available
 */
EIP_STATUS getAttributeSingle(S_CIP_Instance *pa_pstInstance,
    S_CIP_MR_Request *pa_pstMRRequest, S_CIP_MR_Response *pa_pstMRResponse);

/* \brief Generic implementation of the GetAttributeAll CIP service
 * Copy all attributes from Object into the global message buffer.
 * @param pa_pstObjectInstance pointer to object instance with data.
 * @param pa_stMRRequest pointer to MR request.
 * @param pa_stMRResponse pointer for MR response.
 * @param pa_msg pointer to global message buffer for response.
 * @return length of data stream >0 .. success
 *              0 .. no reply to send
 */
EIP_STATUS getAttributeAll(S_CIP_Instance *pa_pstObjectInstance,
    S_CIP_MR_Request *pa_stMRRequest, S_CIP_MR_Response *pa_stMRResponse);

#endif /*CIPCOMMON_H_*/
