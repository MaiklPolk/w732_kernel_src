/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef _MT6575_GPT_H_
#define _MT6575_GPT_H_

#include <mach/mt6575_typedefs.h>

//The operation mode of GPTn
typedef enum
{
    GPT_ONE_SHOT = 0x0000,
    GPT_REPEAT   = 0x0010,
    GPT_KEEP_GO  = 0x0020,
    GPT_FREE_RUN = 0x0030
} GPT_CON_MODE;

//GPTn input clock frequency divider
typedef enum
{
    GPT_CLK_DIV_1     = 0x0000,
    GPT_CLK_DIV_2     = 0x0001,
    GPT_CLK_DIV_3     = 0x0002,
    GPT_CLK_DIV_4     = 0x0003,
    GPT_CLK_DIV_5     = 0x0004,
    GPT_CLK_DIV_6     = 0x0005,
    GPT_CLK_DIV_7     = 0x0006,
    GPT_CLK_DIV_8     = 0x0007,
    GPT_CLK_DIV_9     = 0x0008,
    GPT_CLK_DIV_10    = 0x0009,
    GPT_CLK_DIV_11    = 0x000a,
    GPT_CLK_DIV_12    = 0x000b,
    GPT_CLK_DIV_13    = 0x000c,
    GPT_CLK_DIV_16    = 0x000d,
    GPT_CLK_DIV_32    = 0x000e,
    GPT_CLK_DIV_64    = 0x000f,
    GPT_TOTAL_CLK_DIV = 0x0010
} GPT_CLK_DIV;

//The clock source of GPTn
typedef enum
{
    GPT_CLK_SRC_SYS      = 0,   /* 13MHz */
    GPT_CLK_SRC_RTC      = 1,   /* 32.768KHz */
    GPT_CLK_SRC_RESERVED = 2,   /* reserved */
} GPT_CLK_SRC;

typedef enum
{
    GPT1 = 0,           /* 32-bit */
    GPT2,               /* 32-bit */
    GPT3,               /* 32-bit */
    GPT4,               /* 32-bit */
    GPT5,               /* 32-bit */
    GPT6,               /* 64-bit */
    GPT_TOTAL_COUNT,
 //   GPT_NONE = -1,
} GPT_NUM;

typedef struct 
{
    void (*gpt3_func)(UINT16);
    void (*gpt4_func)(UINT16);
    void (*gpt5_func)(UINT16);
    void (*gpt6_func)(UINT16);
} GPT_Func;

typedef struct
{
    GPT_NUM num;
    GPT_CON_MODE mode;
    GPT_CLK_SRC clkSrc;
    GPT_CLK_DIV clkDiv;
    BOOL bIrqEnable;
    UINT32 u4CompareL;
    UINT32 u4CompareH;
} GPT_CONFIG;

/* for GPT */
extern void GPT_EnableIRQ(GPT_NUM numGPT);
extern void GPT_DisableIRQ(GPT_NUM numGPT);
extern BOOL GPT_IsIRQEnable(GPT_NUM numGPT);

extern void GPT_Start(GPT_NUM numGPT);
extern void GPT_Restart(GPT_NUM numGPT);
extern void GPT_Stop(GPT_NUM numGPT);
extern BOOL GPT_IsStart(GPT_NUM numGPT);
extern void GPT_ClearCount(GPT_NUM numGPT);
extern void GPT_SetOpMode(GPT_NUM numGPT, GPT_CON_MODE mode);
extern GPT_CON_MODE GPT_GetOpMode(GPT_NUM numGPT);

extern void GPT_SetClkDivisor(GPT_NUM numGPT, GPT_CLK_DIV clkDiv);
extern GPT_CLK_DIV GPT_GetClkDivisor(GPT_NUM numGPT);
extern void GPT_SetClkSource(GPT_NUM numGPT, GPT_CLK_SRC clkSrc);
extern GPT_CLK_SRC GPT_GetClkSource(GPT_NUM numGPT);

extern UINT32 GPT_GetCounter(GPT_NUM numGPT);
extern void GPT_GetCounter64(UINT32 *cntL32, UINT32 *cntH32);   /* for GPT6 */
extern void GPT_SetCompare(GPT_NUM numGPT, UINT32 u4Compare);
extern void GPT_SetCompare64(UINT32 *cmpL32, UINT32 *cmpH32);   /* for GPT6 */
extern UINT32 GPT_GetCompare(GPT_NUM numGPT);
extern void GPT_GetCompare64(UINT32 *cmpL32, UINT32 *cmpH32);   /* for GPT6 */

extern void GPT_Reset(GPT_NUM numGPT);
extern void GPT_Init(GPT_NUM timerNum, void (*GPT_Callback)(UINT16));
extern BOOL GPT_Config(GPT_CONFIG config);

extern GPT_NUM GPT_Request(void);
extern void GPT_Free(GPT_NUM);

extern int gpt_set_next_compare(unsigned long cycles);

#endif
