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
 * (C) Copyright 2009
 * Stefan Roese, DENX Software Engineering, sr@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 */

#include <common.h>
#include <asm/ppc4xx_config.h>

struct ppc4xx_config ppc4xx_config_val[] = {
	{
		"333-133-nor", "NOR  CPU: 333 PLB: 133 OPB:  66 EBC:  66",
		{
			0x84, 0x70, 0xa2, 0xa6, 0x05, 0x57, 0xa0, 0x10,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"333-166-nor", "NOR  CPU: 333 PLB: 166 OPB:  83 EBC:  55",
		{
			0xc7, 0x78, 0xf3, 0x4e, 0x05, 0xd7, 0xa0, 0x30,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"333-166-nand", "NAND CPU: 333 PLB: 166 OPB:  83 EBC:  55",
		{
			0xc7, 0x78, 0xf3, 0x4e, 0x05, 0xd7, 0xd0, 0x30,
			0xa0, 0x68, 0x23, 0x58, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"400-133-nor", "NOR  CPU: 400 PLB: 133 OPB:  66 EBC:  66",
		{
			0x86, 0x78, 0xc2, 0xc6, 0x05, 0x57, 0xa0, 0x30,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"400-160-nor", "NOR  CPU: 400 PLB: 160 OPB:  80 EBC:  53",
		{
			0x86, 0x78, 0xc2, 0xa6, 0x05, 0xd7, 0xa0, 0x10,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"416-166-nor", "NOR  CPU: 416 PLB: 166 OPB:  83 EBC:  55",
		{
			0xc6, 0x78, 0x52, 0xa6, 0x05, 0xd7, 0xa0, 0x10,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"416-166-nand", "NAND CPU: 416 PLB: 166 OPB:  83 EBC:  55",
		{
			0xc6, 0x78, 0x52, 0xa6, 0x05, 0xd7, 0xd0, 0x10,
			0xa0, 0x68, 0x23, 0x58, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"500-166-nor", "NOR  CPU: 500 PLB: 166 OPB:  83 EBC:  55",
		{
			0xc7, 0x78, 0x52, 0xc6, 0x05, 0xd7, 0xa0, 0x30,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"500-166-nand", "NAND CPU: 500 PLB: 166 OPB:  83 EBC:  55",
		{
			0xc7, 0x78, 0x52, 0xc6, 0x05, 0xd7, 0xd0, 0x30,
			0xa0, 0x68, 0x23, 0x58, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"533-133-nor", "NOR  CPU: 533 PLB: 133 OPB:  66 EBC:  66",
		{
			0x87, 0x78, 0x82, 0x52, 0x09, 0x57, 0xa0, 0x30,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"667-133-nor", "NOR  CPU: 667 PLB: 133 OPB:  66 EBC:  66",
		{
			0x87, 0x78, 0xa2, 0x56, 0x09, 0x57, 0xa0, 0x30,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"667-166-nor", "NOR  CPU: 667 PLB: 166 OPB:  83 EBC:  55",
		{
			0x87, 0x78, 0xa2, 0x52, 0x09, 0xd7, 0xa0, 0x30,
			0x40, 0x08, 0x23, 0x50, 0x0d, 0x05, 0x00, 0x00
		}
	},
	{
		"667-166-nand", "NAND CPU: 667 PLB: 166 OPB:  83 EBC:  55",
		{
			0x87, 0x78, 0xa2, 0x52, 0x09, 0xd7, 0xd0, 0x30,
			0xa0, 0x68, 0x23, 0x58, 0x0d, 0x05, 0x00, 0x00
		}
	},
};

int ppc4xx_config_count = ARRAY_SIZE(ppc4xx_config_val);
