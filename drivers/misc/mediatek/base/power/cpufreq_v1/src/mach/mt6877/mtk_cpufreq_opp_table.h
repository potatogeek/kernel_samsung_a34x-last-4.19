/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#include "mtk_cpufreq_struct.h"
// #include "mtk_cpufreq_config.h" // This line is usually in the .c file that includes this header.

/* FY */
/* for DVFS OPP table L (Little cores) */
#define CPU_DVFS_FREQ0_LL_FY		2200000		/* KHz */ /* MODIFIED from 2000000 */
#define CPU_DVFS_FREQ1_LL_FY		1950000		/* KHz */ /* Adjusted for smooth transition */
#define CPU_DVFS_FREQ2_LL_FY		1800000		/* KHz */
#define CPU_DVFS_FREQ3_LL_FY		1703000		/* KHz */
#define CPU_DVFS_FREQ4_LL_FY		1600000		/* KHz */
#define CPU_DVFS_FREQ5_LL_FY		1503000		/* KHz */
#define CPU_DVFS_FREQ6_LL_FY		1407000		/* KHz */
#define CPU_DVFS_FREQ7_LL_FY		1310000		/* KHz */
#define CPU_DVFS_FREQ8_LL_FY		1260000		/* KHz */
#define CPU_DVFS_FREQ9_LL_FY		1150000		/* KHz */
#define CPU_DVFS_FREQ10_LL_FY		1053000		/* KHz */
#define CPU_DVFS_FREQ11_LL_FY		980000		/* KHz */
#define CPU_DVFS_FREQ12_LL_FY		900000		/* KHz */
#define CPU_DVFS_FREQ13_LL_FY		740000		/* KHz */
#define CPU_DVFS_FREQ14_LL_FY		650000		/* KHz */
#define CPU_DVFS_FREQ15_LL_FY		500000		/* KHz */

/* for DVFS OPP table B (Big cores) */
#define CPU_DVFS_FREQ0_L_FY		2800000		/* KHz */ /* MODIFIED from 2600000 */
#define CPU_DVFS_FREQ1_L_FY		2500000		/* KHz */ /* Adjusted for smooth transition */
#define CPU_DVFS_FREQ2_L_FY		2350000		/* KHz */ /* Adjusted for smooth transition */
#define CPU_DVFS_FREQ3_L_FY		2200000		/* KHz */ /* Adjusted for smooth transition */
#define CPU_DVFS_FREQ4_L_FY		2000000		/* KHz */
#define CPU_DVFS_FREQ5_L_FY		1900000		/* KHz */
#define CPU_DVFS_FREQ6_L_FY		1800000		/* KHz */
#define CPU_DVFS_FREQ7_L_FY		1660000		/* KHz */
#define CPU_DVFS_FREQ8_L_FY		1540000		/* KHz */
#define CPU_DVFS_FREQ9_L_FY		1430000		/* KHz */
#define CPU_DVFS_FREQ10_L_FY		1300000		/* KHz */
#define CPU_DVFS_FREQ11_L_FY		1140000		/* KHz */
#define CPU_DVFS_FREQ12_L_FY		1040000		/* KHz */
#define CPU_DVFS_FREQ13_L_FY		910000		/* KHz */
#define CPU_DVFS_FREQ14_L_FY		740000		/* KHz */
#define CPU_DVFS_FREQ15_L_FY		650000		/* KHz */

/* for DVFS OPP table CCI */
#define CPU_DVFS_FREQ0_CCI_FY		1700000		/* KHz */
#define CPU_DVFS_FREQ1_CCI_FY		1621000		/* KHz */
#define CPU_DVFS_FREQ2_CCI_FY		1542000		/* KHz */
#define CPU_DVFS_FREQ3_CCI_FY		1440000		/* KHz */
#define CPU_DVFS_FREQ4_CCI_FY		1350000		/* KHz */
#define CPU_DVFS_FREQ5_CCI_FY		1271000		/* KHz */
#define CPU_DVFS_FREQ6_CCI_FY		1120000		/* KHz */
#define CPU_DVFS_FREQ7_CCI_FY		1041000		/* KHz */
#define CPU_DVFS_FREQ8_CCI_FY		962000		/* KHz */
#define CPU_DVFS_FREQ9_CCI_FY		900000		/* KHz */
#define CPU_DVFS_FREQ10_CCI_FY		840000		/* KHz */
#define CPU_DVFS_FREQ11_CCI_FY		740000		/* KHz */
#define CPU_DVFS_FREQ12_CCI_FY		661000		/* KHz */
#define CPU_DVFS_FREQ13_CCI_FY		600000		/* KHz */
#define CPU_DVFS_FREQ14_CCI_FY		560000		/* KHz */
#define CPU_DVFS_FREQ15_CCI_FY		520000		/* KHz */

/* Voltages for VPROC1 (Little cores - FY Segment) - Ajustadas para Undervolt */
#define CPU_DVFS_VOLT0_VPROC1_FY	105625		/* 10uV */ /* 1.05625V (-31.25mV do seu valor anterior) Reduzido para undervolt */
#define CPU_DVFS_VOLT1_VPROC1_FY	98750		/* 10uV */ /* 0.98750V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT2_VPROC1_FY	92500		/* 10uV */ /* 0.92500V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT3_VPROC1_FY	89375		/* 10uV */ /* 0.89375V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT4_VPROC1_FY	85000		/* 10uV */ /* 0.85000V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT5_VPROC1_FY	82500		/* 10uV */ /* 0.82500V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT6_VPROC1_FY	80000		/* 10uV */ /* 0.80000V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT7_VPROC1_FY	78125		/* 10uV */ /* 0.78125V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT8_VPROC1_FY	76875		/* 10uV */ /* 0.76875V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT9_VPROC1_FY	74375		/* 10uV */ /* 0.74375V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT10_VPROC1_FY	72500		/* 10uV */ /* 0.72500V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT11_VPROC1_FY	71250		/* 10uV */ /* 0.71250V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT12_VPROC1_FY	69375		/* 10uV */ /* 0.69375V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT13_VPROC1_FY	67500		/* 10uV */ /* 0.67500V (-12.5mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT14_VPROC1_FY	65625		/* 10uV */ /* 0.65625V (-6.25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT15_VPROC1_FY	64375		/* 10uV */ /* 0.64375V (-6.25mV) Mínimo, pequena redução */

/* Voltages for VPROC2 (Big cores - FY Segment) - Ajustadas para Undervolt */
#define CPU_DVFS_VOLT0_VPROC2_FY	111250		/* 10uV	*/ /* 1.11250V (-37.5mV do seu valor anterior) Reduzido para undervolt */
#define CPU_DVFS_VOLT1_VPROC2_FY	104375		/* 10uV	*/ /* 1.04375V (-31.25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT2_VPROC2_FY	99375		/* 10uV	*/ /* 0.99375V (-31.25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT3_VPROC2_FY	94375		/* 10uV	*/ /* 0.94375V (-31.25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT4_VPROC2_FY	90625		/* 10uV	*/ /* 0.90625V (-31.25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT5_VPROC2_FY	88125		/* 10uV	*/ /* 0.88125V (-31.25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT6_VPROC2_FY	85625		/* 10uV	*/ /* 0.85625V (-31.25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT7_VPROC2_FY	83750		/* 10uV	*/ /* 0.83750V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT8_VPROC2_FY	81875		/* 10uV	*/ /* 0.81875V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT9_VPROC2_FY	79375		/* 10uV	*/ /* 0.79375V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT10_VPROC2_FY	76875		/* 10uV	*/ /* 0.76875V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT11_VPROC2_FY	73750		/* 10uV	*/ /* 0.73750V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT12_VPROC2_FY	71875		/* 10uV	*/ /* 0.71875V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT13_VPROC2_FY	69375		/* 10uV	*/ /* 0.69375V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT14_VPROC2_FY	66875		/* 10uV	*/ /* 0.66875V (-12.5mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT15_VPROC2_FY	65625		/* 10uV	*/ /* 0.65625V (-6.25mV) Reduzido para undervolt */

/* Voltages for VPROC3 (CCI - FY Segment) - Ajustadas para Undervolt */
#define CPU_DVFS_VOLT0_VPROC3_FY	100625		/* 10uV */ /* 1.00625V (-31.25mV do seu valor anterior) Reduzido para undervolt */
#define CPU_DVFS_VOLT1_VPROC3_FY	97500		/* 10uV */ /* 0.97500V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT2_VPROC3_FY	94375		/* 10uV */ /* 0.94375V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT3_VPROC3_FY	90000		/* 10uV */ /* 0.90000V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT4_VPROC3_FY	85625		/* 10uV */ /* 0.85625V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT5_VPROC3_FY	83125		/* 10uV */ /* 0.83125V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT6_VPROC3_FY	80000		/* 10uV */ /* 0.80000V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT7_VPROC3_FY	77500		/* 10uV */ /* 0.77500V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT8_VPROC3_FY	75625		/* 10uV */ /* 0.75625V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT9_VPROC3_FY	73750		/* 10uV */ /* 0.73750V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT10_VPROC3_FY	71875		/* 10uV */ /* 0.71875V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT11_VPROC3_FY	70000		/* 10uV */ /* 0.70000V (-25mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT12_VPROC3_FY	68750		/* 10uV */ /* 0.68750V (-18.75mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT13_VPROC3_FY	67500		/* 10uV */ /* 0.67500V (-12.5mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT14_VPROC3_FY	66250		/* 10uV */ /* 0.66250V (-12.5mV) Reduzido para undervolt */
#define CPU_DVFS_VOLT15_VPROC3_FY	65625		/* 10uV */ /* 0.65625V (-6.25mV) Mínimo, pequena redução */

/* B25G */
/* for DVFS OPP table L */
#define CPU_DVFS_FREQ0_LL_B25G		2200000		/* KHz - Corrected to 2200MHz */
#define CPU_DVFS_FREQ1_LL_B25G		1903000		/* KHz */
#define CPU_DVFS_FREQ2_LL_B25G		1800000		/* KHz */
#define CPU_DVFS_FREQ3_LL_B25G		1703000		/* KHz */
#define CPU_DVFS_FREQ4_LL_B25G		1600000		/* KHz */
#define CPU_DVFS_FREQ5_LL_B25G		1503000		/* KHz */
#define CPU_DVFS_FREQ6_LL_B25G		1407000		/* KHz */
#define CPU_DVFS_FREQ7_LL_B25G		1310000		/* KHz */
#define CPU_DVFS_FREQ8_LL_B25G		1260000		/* KHz */
#define CPU_DVFS_FREQ9_LL_B25G		1150000		/* KHz */
#define CPU_DVFS_FREQ10_LL_B25G		1053000		/* KHz */
#define CPU_DVFS_FREQ11_LL_B25G		980000		/* KHz */
#define CPU_DVFS_FREQ12_LL_B25G		900000		/* KHz */
#define CPU_DVFS_FREQ13_LL_B25G		740000		/* KHz */
#define CPU_DVFS_FREQ14_LL_B25G		650000		/* KHz */
#define CPU_DVFS_FREQ15_LL_B25G		500000		/* KHz */

/* for DVFS OPP table B */
#define CPU_DVFS_FREQ0_L_B25G		2800000		/* KHz - Corrected to 2800MHz */
#define CPU_DVFS_FREQ1_L_B25G		2400000		/* KHz */
#define CPU_DVFS_FREQ2_L_B25G		2275000		/* KHz */
#define CPU_DVFS_FREQ3_L_B25G		2150000		/* KHz */
#define CPU_DVFS_FREQ4_L_B25G		2000000		/* KHz */
#define CPU_DVFS_FREQ5_L_B25G		1900000		/* KHz */
#define CPU_DVFS_FREQ6_L_B25G		1800000		/* KHz */
#define CPU_DVFS_FREQ7_L_B25G		1660000		/* KHz */
#define CPU_DVFS_FREQ8_L_B25G		1540000		/* KHz */
#define CPU_DVFS_FREQ9_L_B25G		1430000		/* KHz */
#define CPU_DVFS_FREQ10_L_B25G		1300000		/* KHz */
#define CPU_DVFS_FREQ11_L_B25G		1140000		/* KHz */
#define CPU_DVFS_FREQ12_L_B25G		1040000		/* KHz */
#define CPU_DVFS_FREQ13_L_B25G		910000		/* KHz */
#define CPU_DVFS_FREQ14_L_B25G		740000		/* KHz */
#define CPU_DVFS_FREQ15_L_B25G		650000		/* KHz */

/* for DVFS OPP table CCI */
#define CPU_DVFS_FREQ0_CCI_B25G		1700000		/* KHz */
#define CPU_DVFS_FREQ1_CCI_B25G		1621000		/* KHz */
#define CPU_DVFS_FREQ2_CCI_B25G		1542000		/* KHz */
#define CPU_DVFS_FREQ3_CCI_B25G		1440000		/* KHz */
#define CPU_DVFS_FREQ4_CCI_B25G		1350000		/* KHz */
#define CPU_DVFS_FREQ5_CCI_B25G		1271000		/* KHz */
#define CPU_DVFS_FREQ6_CCI_B25G		1120000		/* KHz */
#define CPU_DVFS_FREQ7_CCI_B25G		1041000		/* KHz */
#define CPU_DVFS_FREQ8_CCI_B25G		962000		/* KHz */
#define CPU_DVFS_FREQ9_CCI_B25G		900000		/* KHz */
#define CPU_DVFS_FREQ10_CCI_B25G	840000		/* KHz */
#define CPU_DVFS_FREQ11_CCI_B25G	740000		/* KHz */
#define CPU_DVFS_FREQ12_CCI_B25G	661000		/* KHz */
#define CPU_DVFS_FREQ13_CCI_B25G	600000		/* KHz */
#define CPU_DVFS_FREQ14_CCI_B25G	560000		/* KHz */
#define CPU_DVFS_FREQ15_CCI_B25G	520000		/* KHz */

/* Voltages for VPROC1 (Little cores - B25G Segment) */
#define CPU_DVFS_VOLT0_VPROC1_B25G	102500		/* 10uV - Adjusted for 2200MHz */
#define CPU_DVFS_VOLT1_VPROC1_B25G	96875		/* 10uV */
#define CPU_DVFS_VOLT2_VPROC1_B25G	92500		/* 10uV */
#define CPU_DVFS_VOLT3_VPROC1_B25G	89375		/* 10uV */
#define CPU_DVFS_VOLT4_VPROC1_B25G	85000		/* 10uV */
#define CPU_DVFS_VOLT5_VPROC1_B25G	83125		/* 10uV */
#define CPU_DVFS_VOLT6_VPROC1_B25G	81250		/* 10uV */
#define CPU_DVFS_VOLT7_VPROC1_B25G	79375		/* 10uV */
#define CPU_DVFS_VOLT8_VPROC1_B25G	78125		/* 10uV */
#define CPU_DVFS_VOLT9_VPROC1_B25G	75625		/* 10uV */
#define CPU_DVFS_VOLT10_VPROC1_B25G	73750		/* 10uV */
#define CPU_DVFS_VOLT11_VPROC1_B25G	72500		/* 10uV */
#define CPU_DVFS_VOLT12_VPROC1_B25G	70625		/* 10uV */
#define CPU_DVFS_VOLT13_VPROC1_B25G	67500		/* 10uV */
#define CPU_DVFS_VOLT14_VPROC1_B25G	65000		/* 10uV */
#define CPU_DVFS_VOLT15_VPROC1_B25G	65000		/* 10uV */

/* Voltages for VPROC2 (Big cores - B25G Segment) */
#define CPU_DVFS_VOLT0_VPROC2_B25G	112500		/* 10uV - Adjusted for 2800MHz */
#define CPU_DVFS_VOLT1_VPROC2_B25G	100000		/* 10uV	*/
#define CPU_DVFS_VOLT2_VPROC2_B25G	95000		/* 10uV	*/
#define CPU_DVFS_VOLT3_VPROC2_B25G	90000		/* 10uV	*/
#define CPU_DVFS_VOLT4_VPROC2_B25G	88750		/* 10uV	*/
#define CPU_DVFS_VOLT5_VPROC2_B25G	87500		/* 10uV	*/
#define CPU_DVFS_VOLT6_VPROC2_B25G	86875		/* 10uV	*/
#define CPU_DVFS_VOLT7_VPROC2_B25G	85000		/* 10uV	*/
#define CPU_DVFS_VOLT8_VPROC2_B25G	83125		/* 10uV	*/
#define CPU_DVFS_VOLT9_VPROC2_B25G	80625		/* 10uV	*/
#define CPU_DVFS_VOLT10_VPROC2_B25G	78125		/* 10uV	*/
#define CPU_DVFS_VOLT11_VPROC2_B25G	75000		/* 10uV	*/
#define CPU_DVFS_VOLT12_VPROC2_B25G	73125		/* 10uV	*/
#define CPU_DVFS_VOLT13_VPROC2_B25G	70625		/* 10uV	*/
#define CPU_DVFS_VOLT14_VPROC2_B25G	66875		/* 10uV	*/
#define CPU_DVFS_VOLT15_VPROC2_B25G	65000		/* 10uV	*/

/* Voltages for VPROC3 (CCI - B25G Segment) */
#define CPU_DVFS_VOLT0_VPROC3_B25G	100000		/* 10uV */
#define CPU_DVFS_VOLT1_VPROC3_B25G	96875		/* 10uV */
#define CPU_DVFS_VOLT2_VPROC3_B25G	93750		/* 10uV */
#define CPU_DVFS_VOLT3_VPROC3_B25G	89375		/* 10uV */
#define CPU_DVFS_VOLT4_VPROC3_B25G	85000		/* 10uV */
#define CPU_DVFS_VOLT5_VPROC3_B25G	83125		/* 10uV */
#define CPU_DVFS_VOLT6_VPROC3_B25G	80000		/* 10uV */
#define CPU_DVFS_VOLT7_VPROC3_B25G	78125		/* 10uV */
#define CPU_DVFS_VOLT8_VPROC3_B25G	76250		/* 10uV */
#define CPU_DVFS_VOLT9_VPROC3_B25G	74375		/* 10uV */
#define CPU_DVFS_VOLT10_VPROC3_B25G	73125		/* 10uV */
#define CPU_DVFS_VOLT11_VPROC3_B25G	70625		/* 10uV */
#define CPU_DVFS_VOLT12_VPROC3_B25G	68750		/* 10uV */
#define CPU_DVFS_VOLT13_VPROC3_B25G	67500		/* 10uV */
#define CPU_DVFS_VOLT14_VPROC3_B25G	66250		/* 10uV */
#define CPU_DVFS_VOLT15_VPROC3_B25G	65000		/* 10uV */

/* B24G */
/* for DVFS OPP table L (Little cores) */
#define CPU_DVFS_FREQ0_LL_B24G		2200000		/* KHz */
#define CPU_DVFS_FREQ1_LL_B24G		2100000		/* KHz */
#define CPU_DVFS_FREQ2_LL_B24G		2000000		/* KHz */
#define CPU_DVFS_FREQ3_LL_B24G		1900000		/* KHz */
#define CPU_DVFS_FREQ4_LL_B24G		1800000		/* KHz */
#define CPU_DVFS_FREQ5_LL_B24G		1700000		/* KHz */
#define CPU_DVFS_FREQ6_LL_B24G		1600000		/* KHz */
#define CPU_DVFS_FREQ7_LL_B24G		1500000		/* KHz */
#define CPU_DVFS_FREQ8_LL_B24G		1400000		/* KHz */
#define CPU_DVFS_FREQ9_LL_B24G		1300000		/* KHz */
#define CPU_DVFS_FREQ10_LL_B24G		1200000		/* KHz */
#define CPU_DVFS_FREQ11_LL_B24G		1100000		/* KHz */
#define CPU_DVFS_FREQ12_LL_B24G		1000000		/* KHz */
#define CPU_DVFS_FREQ13_LL_B24G		900000		/* KHz */
#define CPU_DVFS_FREQ14_LL_B24G		800000		/* KHz */
#define CPU_DVFS_FREQ15_LL_B24G		700000		/* KHz */

/* for DVFS OPP table B (Big cores) */
#define CPU_DVFS_FREQ0_L_B24G		2800000		/* KHz */
#define CPU_DVFS_FREQ1_L_B24G		2700000		/* KHz */
#define CPU_DVFS_FREQ2_L_B24G		2600000		/* KHz */
#define CPU_DVFS_FREQ3_L_B24G		2500000		/* KHz */
#define CPU_DVFS_FREQ4_L_B24G		2400000		/* KHz */
#define CPU_DVFS_FREQ5_L_B24G		2300000		/* KHz */
#define CPU_DVFS_FREQ6_L_B24G		2200000		/* KHz */
#define CPU_DVFS_FREQ7_L_B24G		2100000		/* KHz */
#define CPU_DVFS_FREQ8_L_B24G		2000000		/* KHz */
#define CPU_DVFS_FREQ9_L_B24G		1900000		/* KHz */
#define CPU_DVFS_FREQ10_L_B24G		1800000		/* KHz */
#define CPU_DVFS_FREQ11_L_B24G		1700000		/* KHz */
#define CPU_DVFS_FREQ12_L_B24G		1600000		/* KHz */
#define CPU_DVFS_FREQ13_L_B24G		1500000		/* KHz */
#define CPU_DVFS_FREQ14_L_B24G		1400000		/* KHz */
#define CPU_DVFS_FREQ15_L_B24G		1300000		/* KHz */

/* for DVFS OPP table CCI */
#define CPU_DVFS_FREQ0_CCI_B24G		1700000		/* KHz */
#define CPU_DVFS_FREQ1_CCI_B24G		1621000		/* KHz */
#define CPU_DVFS_FREQ2_CCI_B24G		1542000		/* KHz */
#define CPU_DVFS_FREQ3_CCI_B24G		1440000		/* KHz */
#define CPU_DVFS_FREQ4_CCI_B24G		1350000		/* KHz */
#define CPU_DVFS_FREQ5_CCI_B24G		1271000		/* KHz */
#define CPU_DVFS_FREQ6_CCI_B24G		1120000		/* KHz */
#define CPU_DVFS_FREQ7_CCI_B24G		1041000		/* KHz */
#define CPU_DVFS_FREQ8_CCI_B24G		962000		/* KHz */
#define CPU_DVFS_FREQ9_CCI_B24G		900000		/* KHz */
#define CPU_DVFS_FREQ10_CCI_B24G	840000		/* KHz */
#define CPU_DVFS_FREQ11_CCI_B24G	740000		/* KHz */
#define CPU_DVFS_FREQ12_CCI_B24G	661000		/* KHz */
#define CPU_DVFS_FREQ13_CCI_B24G	600000		/* KHz */
#define CPU_DVFS_FREQ14_CCI_B24G	560000		/* KHz */
#define CPU_DVFS_FREQ15_CCI_B24G	520000		/* KHz */

/* Voltages for VPROC1 (Little cores - B24G Segment) - Adjusted for 2200MHz max */
#define CPU_DVFS_VOLT0_VPROC1_B24G	103750		/* 10uV */
#define CPU_DVFS_VOLT1_VPROC1_B24G	100000		/* 10uV */
#define CPU_DVFS_VOLT2_VPROC1_B24G	96875		/* 10uV */
#define CPU_DVFS_VOLT3_VPROC1_B24G	93750		/* 10uV */
#define CPU_DVFS_VOLT4_VPROC1_B24G	90625		/* 10uV */
#define CPU_DVFS_VOLT5_VPROC1_B24G	87500		/* 10uV */
#define CPU_DVFS_VOLT6_VPROC1_B24G	84375		/* 10uV */
#define CPU_DVFS_VOLT7_VPROC1_B24G	81250		/* 10uV */
#define CPU_DVFS_VOLT8_VPROC1_B24G	78125		/* 10uV */
#define CPU_DVFS_VOLT9_VPROC1_B24G	75000		/* 10uV */
#define CPU_DVFS_VOLT10_VPROC1_B24G	72500		/* 10uV */
#define CPU_DVFS_VOLT11_VPROC1_B24G	70000		/* 10uV */
#define CPU_DVFS_VOLT12_VPROC1_B24G	67500		/* 10uV */
#define CPU_DVFS_VOLT13_VPROC1_B24G	65625		/* 10uV */
#define CPU_DVFS_VOLT14_VPROC1_B24G	63750		/* 10uV */
#define CPU_DVFS_VOLT15_VPROC1_B24G	62500		/* 10uV */

/* Voltages for VPROC2 (Big cores - B24G Segment) - Adjusted for 2800MHz max */
#define CPU_DVFS_VOLT0_VPROC2_B24G	112500		/* 10uV	*/
#define CPU_DVFS_VOLT1_VPROC2_B24G	108750		/* 10uV	*/
#define CPU_DVFS_VOLT2_VPROC2_B24G	105000		/* 10uV	*/
#define CPU_DVFS_VOLT3_VPROC2_B24G	101250		/* 10uV	*/
#define CPU_DVFS_VOLT4_VPROC2_B24G	97500		/* 10uV	*/
#define CPU_DVFS_VOLT5_VPROC2_B24G	93750		/* 10uV	*/
#define CPU_DVFS_VOLT6_VPROC2_B24G	90000		/* 10uV	*/
#define CPU_DVFS_VOLT7_VPROC2_B24G	86875		/* 10uV	*/
#define CPU_DVFS_VOLT8_VPROC2_B24G	83750		/* 10uV	*/
#define CPU_DVFS_VOLT9_VPROC2_B24G	80625		/* 10uV	*/
#define CPU_DVFS_VOLT10_VPROC2_B24G	77500		/* 10uV	*/
#define CPU_DVFS_VOLT11_VPROC2_B24G	74375		/* 10uV	*/
#define CPU_DVFS_VOLT12_VPROC2_B24G	71250		/* 10uV	*/
#define CPU_DVFS_VOLT13_VPROC2_B24G	68750		/* 10uV	*/
#define CPU_DVFS_VOLT14_VPROC2_B24G	66250		/* 10uV	*/
#define CPU_DVFS_VOLT15_VPROC2_B24G	63750		/* 10uV	*/

/* Voltages for VPROC3 (CCI - B24G Segment) */
#define CPU_DVFS_VOLT0_VPROC3_B24G	100000		/* 10uV */
#define CPU_DVFS_VOLT1_VPROC3_B24G	96875		/* 10uV */
#define CPU_DVFS_VOLT2_VPROC3_B24G	93750		/* 10uV */
#define CPU_DVFS_VOLT3_VPROC3_B24G	89375		/* 10uV */
#define CPU_DVFS_VOLT4_VPROC3_B24G	85000		/* 10uV */
#define CPU_DVFS_VOLT5_VPROC3_B24G	83125		/* 10uV */
#define CPU_DVFS_VOLT6_VPROC3_B24G	80000		/* 10uV */
#define CPU_DVFS_VOLT7_VPROC3_B24G	78125		/* 10uV */
#define CPU_DVFS_VOLT8_VPROC3_B24G	76250		/* 10uV */
#define CPU_DVFS_VOLT9_VPROC3_B24G	74375		/* 10uV */
#define CPU_DVFS_VOLT10_VPROC3_B24G	73125		/* 10uV */
#define CPU_DVFS_VOLT11_VPROC3_B24G	70625		/* 10uV */
#define CPU_DVFS_VOLT12_VPROC3_B24G	68750		/* 10uV */
#define CPU_DVFS_VOLT13_VPROC3_B24G	67500		/* 10uV */
#define CPU_DVFS_VOLT14_VPROC3_B24G	66250		/* 10uV */
#define CPU_DVFS_VOLT15_VPROC3_B24G	65000		/* 10uV */

/* DVFS OPP table Definition Macro */
#define OPP_TBL(cluster, seg, lv, vol_idx) \
static struct mt_cpu_freq_info opp_tbl_##cluster##_e##lv##_0[] = { \
	OP(CPU_DVFS_FREQ0_##cluster##_##seg, CPU_DVFS_VOLT0_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ1_##cluster##_##seg, CPU_DVFS_VOLT1_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ2_##cluster##_##seg, CPU_DVFS_VOLT2_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ3_##cluster##_##seg, CPU_DVFS_VOLT3_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ4_##cluster##_##seg, CPU_DVFS_VOLT4_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ5_##cluster##_##seg, CPU_DVFS_VOLT5_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ6_##cluster##_##seg, CPU_DVFS_VOLT6_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ7_##cluster##_##seg, CPU_DVFS_VOLT7_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ8_##cluster##_##seg, CPU_DVFS_VOLT8_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ9_##cluster##_##seg, CPU_DVFS_VOLT9_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ10_##cluster##_##seg, CPU_DVFS_VOLT10_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ11_##cluster##_##seg, CPU_DVFS_VOLT11_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ12_##cluster##_##seg, CPU_DVFS_VOLT12_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ13_##cluster##_##seg, CPU_DVFS_VOLT13_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ14_##cluster##_##seg, CPU_DVFS_VOLT14_VPROC##vol_idx##_##seg), \
	OP(CPU_DVFS_FREQ15_##cluster##_##seg, CPU_DVFS_VOLT15_VPROC##vol_idx##_##seg), \
}

/* Instantiate OPP tables for FY segment (level 0) */
OPP_TBL(LL,    FY, 0, 1); /* Defines opp_tbl_LL_e0_0   */
OPP_TBL(L,     FY, 0, 2); /* Defines opp_tbl_L_e0_0    */
OPP_TBL(CCI,   FY, 0, 3); /* Defines opp_tbl_CCI_e0_0  */

/* Instantiate OPP tables for B24G segment (level 1) */
OPP_TBL(LL,    B24G, 1, 1); /* Defines opp_tbl_LL_e1_0   */
OPP_TBL(L,     B24G, 1, 2); /* Defines opp_tbl_L_e1_0    */
OPP_TBL(CCI,   B24G, 1, 3); /* Defines opp_tbl_CCI_e1_0  */

/* Instantiate OPP tables for B25G segment (level 2) */
OPP_TBL(LL,    B25G, 2, 1); /* Defines opp_tbl_LL_e2_0   */
OPP_TBL(L,     B25G, 2, 2); /* Defines opp_tbl_L_e2_0    */
OPP_TBL(CCI,   B25G, 2, 3); /* Defines opp_tbl_CCI_e2_0  */


/* v1.3 - Main OPP table structure */
static struct opp_tbl_info opp_tbls[NR_MT_CPU_DVFS][NUM_CPU_LEVEL] = {
	/* LL Cluster */
	{
		[CPU_LEVEL_0] = { opp_tbl_LL_e0_0, /* FY Segment */
			ARRAY_SIZE(opp_tbl_LL_e0_0) },
		[CPU_LEVEL_1] = { opp_tbl_LL_e1_0, /* B24G Segment */
			ARRAY_SIZE(opp_tbl_LL_e1_0) },
		[CPU_LEVEL_2] = { opp_tbl_LL_e2_0, /* B25G Segment */
			ARRAY_SIZE(opp_tbl_LL_e2_0) },
	},
	/* L Cluster */
	{
		[CPU_LEVEL_0] = { opp_tbl_L_e0_0,  /* FY Segment */
			ARRAY_SIZE(opp_tbl_L_e0_0) },
		[CPU_LEVEL_1] = { opp_tbl_L_e1_0,  /* B24G Segment */
			ARRAY_SIZE(opp_tbl_L_e1_0) },
		[CPU_LEVEL_2] = { opp_tbl_L_e2_0,  /* B25G Segment */
			ARRAY_SIZE(opp_tbl_L_e2_0) },
	},
	/* CCI Cluster */
	{
		[CPU_LEVEL_0] = { opp_tbl_CCI_e0_0, /* FY Segment */
			ARRAY_SIZE(opp_tbl_CCI_e0_0) },
		[CPU_LEVEL_1] = { opp_tbl_CCI_e1_0, /* B24G Segment */
			ARRAY_SIZE(opp_tbl_CCI_e1_0) },
		[CPU_LEVEL_2] = { opp_tbl_CCI_e2_0, /* B25G Segment */
			ARRAY_SIZE(opp_tbl_CCI_e2_0) },
	},
};

/* 16 steps OPP table methods */
static struct mt_cpu_freq_method opp_tbl_method_LL_FY[] = {
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(1,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(4,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_L_FY[] = {
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_CCI_FY[] = {
	FP(1,1), FP(1,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(4,1),
	FP(4,1), FP(4,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_LL_B25G[] = {
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(1,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(4,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_L_B25G[] = {
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_CCI_B25G[] = {
	FP(1,1), FP(1,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(4,1),
	FP(4,1), FP(4,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_LL_B24G[] = {
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(1,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(4,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_L_B24G[] = {
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(1,1), FP(1,1), FP(1,1), FP(1,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(4,1), FP(4,1),
};

static struct mt_cpu_freq_method opp_tbl_method_CCI_B24G[] = {
	FP(1,1), FP(1,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(2,1),
	FP(2,1), FP(2,1), FP(2,1), FP(4,1),
	FP(4,1), FP(4,1), FP(4,1), FP(4,1),
};

/* Main OPP table methods structure */
struct opp_tbl_m_info opp_tbls_m[NR_MT_CPU_DVFS][NUM_CPU_LEVEL] = {
	/* LL Cluster */
	{
		[CPU_LEVEL_0] = { opp_tbl_method_LL_FY },    /* FY Segment */
		[CPU_LEVEL_1] = { opp_tbl_method_LL_B24G },  /* B24G Segment */
		[CPU_LEVEL_2] = { opp_tbl_method_LL_B25G },  /* B25G Segment */
	},
	/* L Cluster */
	{
		[CPU_LEVEL_0] = { opp_tbl_method_L_FY },     /* FY Segment */
		[CPU_LEVEL_1] = { opp_tbl_method_L_B24G },   /* B24G Segment */
		[CPU_LEVEL_2] = { opp_tbl_method_L_B25G },   /* B25G Segment */
	},
	/* CCI Cluster */
	{
		[CPU_LEVEL_0] = { opp_tbl_method_CCI_FY },   /* FY Segment */
		[CPU_LEVEL_1] = { opp_tbl_method_CCI_B24G }, /* B24G Segment */
		[CPU_LEVEL_2] = { opp_tbl_method_CCI_B25G }, /* B25G Segment */
	},
};

// Helper macro definitions (assuming they are defined elsewhere, like mtk_cpufreq_struct.h)
// For this code to be self-contained for review, I'll add dummy definitions.
// In a real build, these would come from included headers.
#ifndef OP
#define OP(freq, volt) { .cpufreq_khz = freq, .cpufreq_volt = volt }
#endif

#ifndef FP
#define FP(freq_idx, volt_idx) { .pos_freq = freq_idx, .pos_volt = volt_idx }
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

/*
// Dummy enum/defines for context, actual values would be in other headers
// REMOVED TO PREVENT REDEFINITION ERRORS
enum {
	CPU_LITTLE_LITTLE, // LL
	CPU_LITTLE,        // L
	CPU_CCI,
	NR_MT_CPU_DVFS
};

enum {
	CPU_LEVEL_0, // FY
	CPU_LEVEL_1, // B24G
	CPU_LEVEL_2, // B25G
	NUM_CPU_LEVEL
};
*/
