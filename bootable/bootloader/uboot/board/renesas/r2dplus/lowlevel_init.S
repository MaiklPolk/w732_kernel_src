/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
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

/*
 * modified from SH-IPL+g (init-r0p751rlc0011rl.S)
 * Initial Register Data for R0P751RLC0011RL (SH7751R 240MHz/120MHz/60MHz)
 * Coyright (c) 2007,2008 Nobuhiro Iwamatsu <iwamatsu@nigauri.org>
*/

#include <config.h>
#include <version.h>

#include <asm/processor.h>
#include <asm/macro.h>

	.global lowlevel_init
	.text
	.align	2

lowlevel_init:

	write32	CCR_A, CCR_D_D

	write32	MMUCR_A, MMUCR_D

	write32	BCR1_A, BCR1_D

	write16	BCR2_A, BCR2_D

	write16	BCR3_A, BCR3_D

	write32	BCR4_A, BCR4_D

	write32	WCR1_A, WCR1_D

	write32	WCR2_A, WCR2_D

	write32	WCR3_A, WCR3_D

	write16	PCR_A, PCR_D

	write16	LED_A, LED_D

	write32	MCR_A, MCR_D1

	write16	RTCNT_A, RTCNT_D

	write16	RTCOR_A, RTCOR_D

	write16	RFCR_A, RFCR_D

	write16	RTCSR_A, RTCSR_D

	write8	SDMR3_A, SDMR3_D0

	/* Wait DRAM refresh 30 times */
	mov.l	RFCR_A, r1
	mov	#30, r3
1:
	mov.w	@r1, r0
	extu.w	r0, r2
	cmp/hi	r3, r2
	bf	1b

	write32	MCR_A, MCR_D2

	write8	SDMR3_A, SDMR3_D1

	write32	IRLMASK_A, IRLMASK_D

	write32	CCR_A, CCR_D_E

	rts
	nop

	.align	2
CCR_A:		.long	CCR		/* Cache Control Register */
CCR_D_D:	.long	0x0808		/* Flush the cache, disable */
CCR_D_E:	.long	0x8000090B

FRQCR_A:	.long	FRQCR		/* FRQCR Address */
FRQCR_D:	.long	0x00000e0a	/* 03/07/15 modify */
BCR1_A:		.long	BCR1		/* BCR1 Address */
BCR1_D:		.long	0x00180008
BCR2_A:		.long	BCR2		/* BCR2 Address */
BCR2_D:		.long	0xabe8
BCR3_A:		.long	BCR3		/* BCR3 Address */
BCR3_D:		.long	0x0000
BCR4_A:		.long	BCR4		/* BCR4 Address */
BCR4_D:		.long	0x00000010
WCR1_A:		.long	WCR1		/* WCR1 Address */
WCR1_D:		.long	0x33343333
WCR2_A:		.long	WCR2		/* WCR2 Address */
WCR2_D:		.long	0xcff86fbf
WCR3_A:		.long	WCR3		/* WCR3 Address */
WCR3_D:		.long	0x07777707
LED_A:		.long	0x04000036	/* LED Address */
LED_D:		.long	0xFF		/* LED Data */
RTCNT_A:	.long	RTCNT		/* RTCNT Address */
RTCNT_D:	.long	0xA500		/* RTCNT Write Code A5h Data 00h */
RTCOR_A:	.long	RTCOR		/* RTCOR Address */
RTCOR_D:	.long	0xA534		/* RTCOR Write Code */
RTCSR_A:	.long	RTCSR		/* RTCSR Address */
RTCSR_D:	.long	0xA510		/* RTCSR Write Code */
SDMR3_A:	.long	0xFF9400CC	/* SDMR3 Address */
SDMR3_D0:	.long	0x55
SDMR3_D1:	.long	0x00
MCR_A:		.long	MCR		/* MCR Address */
MCR_D1:		.long	0x081901F4	/* MRSET:'0' */
MCR_D2:		.long	0x481901F4	/* MRSET:'1' */
RFCR_A:		.long	RFCR		/* RFCR Address */
RFCR_D:		.long	0xA400		/* RFCR Write Code A4h Data 00h */
PCR_A:		.long	PCR		/* PCR Address */
PCR_D:		.long	0x0000
MMUCR_A:	.long	MMUCR		/* MMUCCR Address */
MMUCR_D:	.long	0x00000000	/* MMUCCR Data */
IRLMASK_A:	.long	0xA4000000	/* IRLMASK Address */
IRLMASK_D:	.long	0x00000000	/* IRLMASK Data */
