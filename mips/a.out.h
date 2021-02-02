//#include "filehdr.h"

/* Represent a target address.  Also used as a generic unsigned type
   which is guaranteed to be big enough to hold any arithmetic types
   we need to deal with.  */
typedef unsigned long bfd_vma;

/* Why isn't this in coff/sym.h?  */
#define ST_RFDESCAPE 0xfff

#ifdef __mips
/* --------------------------------------------------------- */
/* | Copyright (c) 1986, 1989 MIPS Computer Systems, Inc.  | */
/* | All Rights Reserved.                                  | */
/* --------------------------------------------------------- */
/* $Header: filehdr.h,v 2010.8.1.5 89/11/29 22:41:05 bettina Exp $ */
#ifndef __FILEHDR_H
#define __FILEHDR_H
/*	Copyright (c) 1984 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#if __mips 
/*
 * The field f_symptr now is a file pointer to the symbolic header which was
 * the file pointer to symtab.  The field f_nsyms is now the size of the
 * symbolic header which was number of symtab entries.
 */
#endif

#ifdef __LANGUAGE_C
struct filehdr {
	unsigned short	f_magic;	/* magic number */
	unsigned short	f_nscns;	/* number of sections */
	long		f_timdat;	/* time & date stamp */
	long		f_symptr;	/* file pointer to symbolic header */
	long		f_nsyms;	/* sizeof(symbolic hdr) */
	unsigned short	f_opthdr;	/* sizeof(optional hdr) */
	unsigned short	f_flags;	/* flags */
	};
#endif /* __LANGUAGE_C */

#ifdef LANGUAGE_PASCAL
type
  filehdr = packed record
      f_magic : ushort; 		/* magic number 		     */
      f_nscns : ushort; 		/* number of sections		     */
      f_timdat : long;			/* time & date stamp		     */
      f_symptr : long;			/* file pointer to symbolic header   */
      f_nsyms : long;			/* sizeof(symbolic hdr) 	     */
      f_opthdr : ushort;		/* sizeof(optional hdr) 	     */
      f_flags : ushort; 		/* flags			     */
    end {record};
#endif /* LANGUAGE_PASCAL */

/*
 *   Bits for f_flags:
 *
 *	F_RELFLG	relocation info stripped from file
 *	F_EXEC		file is executable  (i.e. no unresolved
 *				externel references)
 *	F_LNNO		line nunbers stripped from file
 *	F_LSYMS		local symbols stripped from file
 *	F_MINMAL	this is a minimal object file (".m") output of fextract
 *	F_UPDATE	this is a fully bound update file, output of ogen
 *	F_SWABD		this file has had its bytes swabbed (in names)
 *	F_AR16WR	this file has the byte ordering of an AR16WR (e.g. 11/70) machine
 *				(it was created there, or was produced by conv)
 *	F_AR32WR	this file has the byte ordering of an AR32WR machine(e.g. vax)
 *	F_AR32W		this file has the byte ordering of an AR32W machine (e.g. 3b,maxi,MC68000)
 *	F_PATCH		file contains "patch" list in optional header
 *	F_NODF		(minimal file only) no decision functions for
 *				replaced functions
 */

#ifdef __LANGUAGE_C
#define  F_RELFLG	0000001
#define  F_EXEC		0000002
#define  F_LNNO		0000004
#define  F_LSYMS	0000010
#define  F_MINMAL	0000020
#define  F_UPDATE	0000040
#define  F_SWABD	0000100
#define  F_AR16WR	0000200
#define  F_AR32WR	0000400
#define  F_AR32W	0001000
#define  F_PATCH	0002000
#define  F_NODF		0002000
#endif /* __LANGUAGE_C */

#ifdef LANGUAGE_PASCAL
#define  F_RELFLG	16#0001
#define  F_EXEC		16#0002
#define  F_LNNO		16#0004
#define  F_LSYMS	16#0008
#define  F_MINMAL	16#0010
#define  F_UPDATE	16#0020
#define  F_SWABD	16#0040
#define  F_AR16WR	16#0080
#define  F_AR32WR	16#0100
#define  F_AR32W	16#0200
#define  F_PATCH	16#0400
#define  F_NODF		16#0400
#endif /* LANGUAGE_PASCAL */

/*
 *	BELLMAC-32	Identification field
 *	F_BM32B		file contains BM32B code (as opposed to strictly BM32A)
 *	F_BM32MAU	file requires MAU (math arith unit) to execute
 */

#define	F_BM32ID	0160000
#define	F_BM32MAU	0040000
#define F_BM32B         0020000

/*	F_BM32RST	file has RESTORE work-around	*/
#define F_BM32RST	0010000

/*
 *	Flags for the INTEL chips.  If the magic number of the object file
 *	is IAPX16 or IAPX16TV or IAPX20 or IAPX20TV then if F_80186
 *	is set, there are some 80186 instructions in the code, and hence
 *	and 80186 or 80286 chip must be used to run the code.
 *	If F_80286 is set, then the code has to be run on an 80286 chip.
 *	And if neither are set, then the code can run on an 8086, 80186, or
 *	80286 chip.
 *	
 */

#define F_80186		010000
#define F_80286		020000

/*
 *   Magic Numbers
 */

	/* iAPX - the stack frame and return registers differ from
	 * 	  Basic-16 and x86 C compilers, hence new magic numbers
	 *	  are required.  These are cross compilers.
	 */

	/* Intel */
#define  IAPX16		0504
#define  IAPX16TV	0505
#define  IAPX20		0506
#define  IAPX20TV	0507
/* 0514, 0516 and 0517 reserved for Intel */

	/* mips */
#define	 MAGIC_MIPS1	6
#define	 MAGIC_MIPS2	5
#define	 MAGIC_MIPS3	4
#ifdef __LANGUAGE_C
#define	 MAGIC_ARCH_MASK		0x00F0
#define	 MAGIC_ARCH_SHFT		4
#define	 MAGIC_S_ARCH_MASK		0xF000
#define	 MAGIC_S_ARCH_SHFT		12
#define  MIPSEBMAGIC	0x0160
#define  MIPSELMAGIC	0x0162
#define  SMIPSEBMAGIC	0x6001
#define  SMIPSELMAGIC	0x6201
#define  MIPSEBUMAGIC	0x0180
#define  MIPSELUMAGIC	0x0182
#endif /* __LANGUAGE_C */
#ifdef LANGUAGE_PASCAL
#define	 MAGIC_ARCH_MASK		16#00F0
#define	 MAGIC_ARCH_SHFT		4
#define	 MAGIC_S_ARCH_MASK		16#F000
#define	 MAGIC_S_ARCH_SHFT		12
#define  MIPSEBMAGIC	16#0160
#define  MIPSELMAGIC	16#0162
#define  SMIPSEBMAGIC	16#6001
#define  SMIPSELMAGIC	16#6201
#define  MIPSEBUMAGIC	16#0180
#define  MIPSELUMAGIC	16#0182
#endif
#ifdef __LANGUAGE_C
#define  MIPSEBMAGIC_2	0x0150
#define  MIPSELMAGIC_2	0x0152
#define  SMIPSEBMAGIC_2	0x5001
#define  SMIPSELMAGIC_2	0x5201
#endif /* __LANGUAGE_C */
#ifdef LANGUAGE_PASCAL
#define  MIPSEBMAGIC_2	16#0150
#define  MIPSELMAGIC_2	16#0152
#define  SMIPSEBMAGIC_2	16#5001
#define  SMIPSELMAGIC_2	16#5201
#endif
#ifdef __LANGUAGE_C
#define  MIPSEBMAGIC_3	0x0140
#define  MIPSELMAGIC_3	0x0142
#define  SMIPSEBMAGIC_3	0x4001
#define  SMIPSELMAGIC_3	0x4201
#endif /* __LANGUAGE_C */
#ifdef LANGUAGE_PASCAL
#define  MIPSEBMAGIC_3	16#0140
#define  MIPSELMAGIC_3	16#0142
#define  SMIPSEBMAGIC_3	16#4001
#define  SMIPSELMAGIC_3	16#4201
#endif

	/* Basic-16 */
#define  B16MAGIC	0502
#define  BTVMAGIC	0503

	/* x86 */
#define  X86MAGIC	0510
#define  XTVMAGIC	0511

	/* Intel 286 */
#define I286SMAGIC	0512
#define I286LMAGIC	0522	/* used by mc68000 (UNIX PC) and iAPX 286 */

	/* n3b */
/*
 *   NOTE:   For New 3B, the old values of magic numbers
 *		will be in the optional header in the structure
 *		"aouthdr" (identical to old 3B aouthdr).
 */
#define  N3BMAGIC	0550	/* 3B20 executable, no TV */
#define  NTVMAGIC	0551	/* 3B20 executable with TV */

	/*  XL  */
#define	 XLMAGIC	0540

	/*  MAC-32, 3B15, 3B5  */
#define  WE32MAGIC	0560	/* WE 32000, no TV */
#define  FBOMAGIC	0560	/* WE 32000, no TV */
#define  RBOMAGIC	0562	/* reserved for WE 32000 */
#define  MTVMAGIC	0561	/* WE 32000 with TV */

	/* VAX 11/780 and VAX 11/750 */

			/* writeable text segments */
#define VAXWRMAGIC	0570
			/* readonly sharable text segments */
#define VAXROMAGIC	0575

	/* pdp11 */
/*			0401	UNIX-rt ldp */
/*			0405	pdp11 overlay */
/*			0407	pdp11/pre System V vax executable */
/*			0410	pdp11/pre System V vax pure executable */
/*			0411	pdp11 seperate I&D */
/*			0437	pdp11 kernel overlay */


	/* Motorola 68000/68008/68010/68020 */
#define	MC68MAGIC	0520
#define MC68KWRMAGIC	0520	/* writeable text segments */
#define	MC68TVMAGIC	0521
#define MC68KROMAGIC	0521	/* readonly shareable text segments */
#define MC68KPGMAGIC	0522	/* demand paged text segments */
#define	M68MAGIC	0210
#define	M68TVMAGIC	0211


	/* IBM 370 */
#define	U370WRMAGIC	0530	/* writeble text segments	*/
#define	U370ROMAGIC	0535	/* readonly sharable text segments	*/
/* 0532 and 0533 reserved for u370 */

	/* Amdahl 470/580 */
#define AMDWRMAGIC	0531	/* writable text segments */
#define AMDROMAGIC	0534	/* readonly sharable text segments */

	/* NSC */
/* 0524 and 0525 reserved for NSC */

	/* Zilog */
/* 0544 and 0545 reserved for Zilog */

#define	FILHDR	struct filehdr
#define	FILHSZ	sizeof(FILHDR)

#define ISCOFF(x) \
		(((x)==B16MAGIC) || ((x)==BTVMAGIC) || ((x)==X86MAGIC) \
		|| ((x)==XTVMAGIC) || ((x)==N3BMAGIC) || ((x)==NTVMAGIC) \
		|| ((x)==FBOMAGIC) || ((x)==VAXROMAGIC) || ((x)==VAXWRMAGIC) \
		|| ((x)==RBOMAGIC) || ((x)==MC68TVMAGIC) \
		|| ((x)==MC68MAGIC) || ((x)==M68MAGIC) || ((x)==M68TVMAGIC) \
		|| ((x)==IAPX16) || ((x)==IAPX16TV) \
		|| ((x)==IAPX20) || ((x)==IAPX20TV) \
		|| ((x)==MIPSEBMAGIC) || ((x)==MIPSELMAGIC) \
		|| ((x)==SMIPSEBMAGIC) || ((x)==SMIPSELMAGIC) \
		|| ((x)==MIPSEBUMAGIC) || ((x)==MIPSELUMAGIC) \
		|| ((x)==U370WRMAGIC) || ((x)==U370ROMAGIC) || ((x)==MTVMAGIC) \
		|| ((x)==I286SMAGIC) || ((x)==I286LMAGIC) \
		|| ((x)==MC68KWRMAGIC) || ((x)==MC68KROMAGIC) \
		|| ((x)==MC68KPGMAGIC))
/* $Log:	filehdr.h,v $
 * Revision 2010.8.1.5  89/11/29  22:41:05  bettina
 * 2.10 BETA2
 * 
 * Revision 2010.4  89/10/04  10:53:22  chan
 * defined mips1..3 
 * 
 * Revision 2010.3  89/10/04  09:55:28  chan
 * add architecture type mask and shift for ld to do checking
 * 
 * Revision 2010.2  89/10/03  18:30:43  chan
 * insert mips2, mips3 magic numbers
 * 
 * 
 * Revision 2010.1  89/09/26  20:47:48  lai
 * updated to 2.10
 * 
 * Revision 2010.1  89/09/26  20:05:53  lai
 * 2.10, added wrapper adn $LOG
 * 
*/
#endif
#endif /* __mips */


/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 1994 Sean Eric Fagan
 * Copyright (c) 1994 Søren Schmidt
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer
 *    in this position and unchanged.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD$
 */

#ifndef _COFF_H
#define _COFF_H

struct filehdr {
  	unsigned short	f_magic;	/* magic number */
  	unsigned short	f_nscns;	/* # of sections */
  	long		f_timdat;	/* time stamp */
  	long		f_symptr;	/* symbol table offset */
  	long		f_nsyms;	/* # of symbols */
  	unsigned short	f_opthdr;	/* size of system header */
  	unsigned short	f_flags;	/* flags, see below */
};

enum filehdr_flags {
  	F_RELFLG = 0x01,		/* relocs have been stripped */
  	F_EXEC = 0x02,			/* executable file (or shlib) */
  	F_LNNO = 0x04,			/* line numbers have been stripped */
  	F_LSYMS = 0x08,			/* symbols have been stripped */
  	F_SWABD = 0x40,			/* swabbed byte names */
  	F_AR16WR = 0x80,		/* 16-bit, byte reversed words */
  	F_AR32WR = 0x100		/* 32-bit, byte reversed words */
};

struct aouthdr {
  	short magic;			/* magic number -- see below */
  	short vstamp;			/* artifacts from a by-gone day */
  	long tsize;			/* */
  	long dsize;			/* */
  	long bsize;			/* */
  	long entry;			/* Entry point -- offset into file */
  	long tstart;			/* artifacts from a by-gone day */
  	long dstart;			/* */
};

#define I386_COFF	0x14c

#define COFF_OMAGIC	0407		/* impure format */
#define COFF_NMAGIC	0410		/* read-only text */
#define COFF_ZMAGIC	0413		/* pagable from disk */
#define COFF_SHLIB	0443		/* a shared library */

struct scnhdr {
  	char		s_name[8];	/* name of section (e.g., ".text") */
  	long		s_paddr;	/* physical addr, used for standalone */
  	long		s_vaddr;	/* virtual address */
  	long		s_size;		/* size of section */
  	long		s_scnptr;	/* file offset of section */
  	long		s_relptr;	/* points to relocs for section */
  	long		s_lnnoptr;	/* points to line numbers for section */
  	unsigned short	s_nreloc;	/* # of relocs */
  	unsigned short	s_nlnno;	/* # of line no's */
  	long		s_flags;	/* section flags -- see below */
};

enum scnhdr_flags {
  	STYP_REG = 0x00,	/* regular (alloc'ed, reloc'ed, loaded) */
  	STYP_DSECT = 0x01,	/* dummy   (reloc'd) */
  	STYP_NOLOAD = 0x02,	/* no-load (reloc'd) */
  	STYP_GROUP = 0x04,	/* grouped */
  	STYP_PAD = 0x08,	/* padding (loaded) */
  	STYP_COPY = 0x10,	/* ??? */
  	STYP_TEXT = 0x20,	/* text */
  	STYP_DATA = 0x40,	/* data */
  	STYP_BSS = 0x80,	/* bss */
  	STYP_INFO = 0x200,	/* comment (!loaded, !alloc'ed, !reloc'd) */
  	STYP_OVER = 0x400,	/* overlay (!allocated, reloc'd, !loaded) */
  	STYP_LIB = 0x800	/* lists shared library files */
};

struct slhdr {
	long	entry_length;
	long	path_index;
	char	*shlib_name;
};
#endif /* _COFF_H */

/* Declarations of constants for internal format of MIPS ECOFF symbols.
   Originally contributed by MIPS Computer Systems and Third Eye Software.
   Changes contributed by Cygnus Support are in the public domain.

   This file is just aggregated with the files that make up the GNU
   release; it is not considered part of GAS, GDB, or other GNU
   programs.  */

/*
 * |-----------------------------------------------------------|
 * | Copyright (c) 1992, 1991, 1990 MIPS Computer Systems, Inc.|
 * | MIPS Computer Systems, Inc. grants reproduction and use   |
 * | rights to all parties, PROVIDED that this comment is      |
 * | maintained in the copy.                                   |
 * |-----------------------------------------------------------|
 */

/* (C) Copyright 1984 by Third Eye Software, Inc.
 *
 * Third Eye Software, Inc. grants reproduction and use rights to
 * all parties, PROVIDED that this comment is maintained in the copy.
 *
 * Third Eye makes no claims about the applicability of this
 * symbol table to a particular use.
 */

/* glevels for field in FDR */
#define GLEVEL_0	2
#define GLEVEL_1	1
#define GLEVEL_2	0	/* for upward compat reasons. */
#define GLEVEL_3	3

/* magic number fo symheader */
#define magicSym	0x7009
/* The Alpha uses this value instead, for some reason.  */
#define magicSym2	0x1992

/* Language codes */
#define langC		0	
#define langPascal	1
#define langFortran	2
#define	langAssembler	3	/* one Assembley inst might map to many mach */
#define langMachine	4
#define langNil		5
#define langAda		6
#define langPl1		7
#define langCobol	8
#define langStdc	9	/* FIXME: Collides with SGI langCplusplus */
#define langCplusplus	9	/* FIXME: Collides with langStdc */
#define langCplusplusV2	10	/* SGI addition */
#define langMax		11	/* maximum allowed 32 -- 5 bits */

/* The following are value definitions for the fields in the SYMR */

/*
 * Storage Classes
 */

#define scNil		0
#define scText		1	/* text symbol */
#define scData		2	/* initialized data symbol */
#define scBss		3	/* un-initialized data symbol */
#define scRegister	4	/* value of symbol is register number */
#define scAbs		5	/* value of symbol is absolute */
#define scUndefined	6	/* who knows? */
#define scCdbLocal	7	/* variable's value is IN se->va.?? */
#define scBits		8	/* this is a bit field */
#define scCdbSystem	9	/* variable's value is IN CDB's address space */
#define scDbx		9	/* overlap dbx internal use */
#define scRegImage	10	/* register value saved on stack */
#define scInfo		11	/* symbol contains debugger information */
#define scUserStruct	12	/* address in struct user for current process */
#define scSData		13	/* load time only small data */
#define scSBss		14	/* load time only small common */
#define scRData		15	/* load time only read only data */
#define scVar		16	/* Var parameter (fortran,pascal) */
#define scCommon	17	/* common variable */
#define scSCommon	18	/* small common */
#define scVarRegister	19	/* Var parameter in a register */
#define scVariant	20	/* Variant record */
#define scSUndefined	21	/* small undefined(external) data */
#define scInit		22	/* .init section symbol */
#define scBasedVar	23	/* Fortran or PL/1 ptr based var */ 
#define scXData         24      /* exception handling data */
#define scPData         25      /* Procedure section */
#define scFini          26      /* .fini section */
#define scRConst	27	/* .rconst section */
#define scMax		32


/*
 *   Symbol Types
 */

#define stNil		0	/* Nuthin' special */
#define stGlobal	1	/* external symbol */
#define stStatic	2	/* static */
#define stParam		3	/* procedure argument */
#define stLocal		4	/* local variable */
#define stLabel		5	/* label */
#define stProc		6	/*     "      "	 Procedure */
#define stBlock		7	/* beginnning of block */
#define stEnd		8	/* end (of anything) */
#define stMember	9	/* member (of anything	- struct/union/enum */
#define stTypedef	10	/* type definition */
#define stFile		11	/* file name */
#define stRegReloc	12	/* register relocation */
#define stForward	13	/* forwarding address */
#define stStaticProc	14	/* load time only static procs */
#define stConstant	15	/* const */
#define stStaParam	16	/* Fortran static parameters */
    /* These new symbol types have been recently added to SGI machines. */
#define stStruct	26	/* Beginning of block defining a struct type */
#define stUnion		27	/* Beginning of block defining a union type */
#define stEnum		28	/* Beginning of block defining an enum type */
#define stIndirect	34	/* Indirect type specification */
    /* Pseudo-symbols - internal to debugger */
#define stStr		60	/* string */
#define stNumber	61	/* pure number (ie. 4 NOR 2+2) */
#define stExpr		62	/* 2+2 vs. 4 */
#define stType		63	/* post-coersion SER */
#define stMax		64

/* definitions for fields in TIR */

/* type qualifiers for ti.tq0 -> ti.(itqMax-1) */
#define tqNil	0	/* bt is what you see */
#define tqPtr	1	/* pointer */
#define tqProc	2	/* procedure */
#define tqArray 3	/* duh */
#define tqFar	4	/* longer addressing - 8086/8 land */
#define tqVol	5	/* volatile */
#define tqConst 6	/* const */
#define tqMax	8

/* basic types as seen in ti.bt */
#define btNil		0	/* undefined (also, enum members) */
#define btAdr		1	/* address - integer same size as pointer */
#define btChar		2	/* character */
#define btUChar		3	/* unsigned character */
#define btShort		4	/* short */
#define btUShort	5	/* unsigned short */
#define btInt		6	/* int */
#define btUInt		7	/* unsigned int */
#define btLong		8	/* long */
#define btULong		9	/* unsigned long */
#define btFloat		10	/* float (real) */
#define btDouble	11	/* Double (real) */
#define btStruct	12	/* Structure (Record) */
#define btUnion		13	/* Union (variant) */
#define btEnum		14	/* Enumerated */
#define btTypedef	15	/* defined via a typedef, isymRef points */
#define btRange		16	/* subrange of int */
#define btSet		17	/* pascal sets */
#define btComplex	18	/* fortran complex */
#define btDComplex	19	/* fortran double complex */
#define btIndirect	20	/* forward or unnamed typedef */
#define btFixedDec	21	/* Fixed Decimal */
#define btFloatDec	22	/* Float Decimal */
#define btString	23	/* Varying Length Character String */
#define btBit		24	/* Aligned Bit String */
#define btPicture	25	/* Picture */
#define btVoid		26	/* void */
#define btLongLong	27	/* long long */
#define btULongLong	28	/* unsigned long long */
#define btMax		64

#if (_MFG == _MIPS)
/* optimization type codes */
#define otNil		0
#define otReg		1	/* move var to reg */
#define otBlock		2	/* begin basic block */
#define	otProc		3	/* procedure */
#define otInline	4	/* inline procedure */
#define otEnd		5	/* whatever you started */
#define otMax		6	/* KEEP UP TO DATE */
#endif /* (_MFG == _MIPS) */

/* Declarations of internal format of MIPS ECOFF symbols.
   Originally contributed by MIPS Computer Systems and Third Eye Software.
   Changes contributed by Cygnus Support are in the public domain.  

   This file is just aggregated with the files that make up the GNU
   release; it is not considered part of GAS, GDB, or other GNU
   programs.  */

/*
 * |-----------------------------------------------------------|
 * | Copyright (c) 1992, 1991, 1990 MIPS Computer Systems, Inc.|
 * | MIPS Computer Systems, Inc. grants reproduction and use   |
 * | rights to all parties, PROVIDED that this comment is      |
 * | maintained in the copy.                                   |
 * |-----------------------------------------------------------|
 */
#ifndef _SYM_H
#define _SYM_H

/* (C) Copyright 1984 by Third Eye Software, Inc.
 *
 * Third Eye Software, Inc. grants reproduction and use rights to
 * all parties, PROVIDED that this comment is maintained in the copy.
 *
 * Third Eye makes no claims about the applicability of this
 * symbol table to a particular use.
 */

/* 
 * This file contains the definition of the Third Eye Symbol Table.
 *
 * Symbols are assumed to be in 'encounter order' - i.e. the order that
 * the things they represent were encountered by the compiler/assembler/loader.
 * EXCEPT for globals!	These are assumed to be bunched together,
 * probably right after the last 'normal' symbol.  Globals ARE sorted
 * in ascending order.
 *
 * -----------------------------------------------------------------------
 * A brief word about Third Eye naming/use conventions:
 *
 * All arrays and index's are 0 based.
 * All "ifooMax" values are the highest legal value PLUS ONE. This makes
 * them good for allocating arrays, etc. All checks are "ifoo < ifooMax".
 *
 * "isym"	Index into the SYMbol table.
 * "ipd"	Index into the Procedure Descriptor array.
 * "ifd"	Index into the File Descriptor array.
 * "iss"	Index into String Space.
 * "cb"		Count of Bytes.
 * "rgPd"	array whose domain is "0..ipdMax-1" and RanGe is PDR.
 * "rgFd"	array whose domain is "0..ifdMax-1" and RanGe is FDR.
 */


/* 
 * Symbolic Header (HDR) structure.
 * As long as all the pointers are set correctly,
 * we don't care WHAT order the various sections come out in!
 *
 * A file produced solely for the use of CDB will probably NOT have
 * any instructions or data areas in it, as these are available
 * in the original.
 */

typedef struct {
	short	magic;		/* to verify validity of the table */
	short	vstamp;		/* version stamp */
	long	ilineMax;	/* number of line number entries */
	bfd_vma	cbLine;		/* number of bytes for line number entries */
	bfd_vma	cbLineOffset;	/* offset to start of line number entries*/
	long	idnMax;		/* max index into dense number table */
	bfd_vma	cbDnOffset;	/* offset to start dense number table */
	long	ipdMax;		/* number of procedures */
	bfd_vma	cbPdOffset;	/* offset to procedure descriptor table */
	long	isymMax;	/* number of local symbols */
	bfd_vma	cbSymOffset;	/* offset to start of local symbols*/
	long	ioptMax;	/* max index into optimization symbol entries */
	bfd_vma	cbOptOffset;	/* offset to optimization symbol entries */
	long	iauxMax;	/* number of auxillary symbol entries */
	bfd_vma	cbAuxOffset;	/* offset to start of auxillary symbol entries*/
	long	issMax;		/* max index into local strings */
	bfd_vma	cbSsOffset;	/* offset to start of local strings */
	long	issExtMax;	/* max index into external strings */
	bfd_vma	cbSsExtOffset;	/* offset to start of external strings */
	long	ifdMax;		/* number of file descriptor entries */
	bfd_vma	cbFdOffset;	/* offset to file descriptor table */
	long	crfd;		/* number of relative file descriptor entries */
	bfd_vma	cbRfdOffset;	/* offset to relative file descriptor table */
	long	iextMax;	/* max index into external symbols */
	bfd_vma	cbExtOffset;	/* offset to start of external symbol entries*/
	/* If you add machine dependent fields, add them here */
	} HDRR, *pHDRR; 
#define cbHDRR sizeof(HDRR)
#define hdrNil ((pHDRR)0)

/*
 * The FDR and PDR structures speed mapping of address <-> name.
 * They are sorted in ascending memory order and are kept in
 * memory by CDB at runtime.
 */

/* 
 * File Descriptor
 *
 * There is one of these for EVERY FILE, whether compiled with
 * full debugging symbols or not.  The name of a file should be
 * the path name given to the compiler.	 This allows the user
 * to simply specify the names of the directories where the COMPILES
 * were done, and we will be able to find their files.
 * A field whose comment starts with "R - " indicates that it will be
 * setup at runtime.
 */
typedef struct fdr {
	bfd_vma	adr;		/* memory address of beginning of file */
	long	rss;		/* file name (of source, if known) */
	long	issBase;	/* file's string space */
	bfd_vma	cbSs;		/* number of bytes in the ss */
	long	isymBase;	/* beginning of symbols */
	long	csym;		/* count file's of symbols */
	long	ilineBase;	/* file's line symbols */
	long	cline;		/* count of file's line symbols */
	long	ioptBase;	/* file's optimization entries */
	long	copt;		/* count of file's optimization entries */
	unsigned short ipdFirst;/* start of procedures for this file */
	short	cpd;		/* count of procedures for this file */
	long	iauxBase;	/* file's auxiliary entries */
	long	caux;		/* count of file's auxiliary entries */
	long	rfdBase;	/* index into the file indirect table */
	long	crfd;		/* count file indirect entries */
	unsigned lang: 5;	/* language for this file */
	unsigned fMerge : 1;	/* whether this file can be merged */
	unsigned fReadin : 1;	/* true if it was read in (not just created) */
	unsigned fBigendian : 1;/* if set, was compiled on big endian machine */
				/*	aux's will be in compile host's sex */
	unsigned glevel : 2;	/* level this file was compiled with */
	unsigned reserved : 22;  /* reserved for future use */
	bfd_vma	cbLineOffset;	/* byte offset from header for this file ln's */
	bfd_vma	cbLine;		/* size of lines for this file */
	} FDR, *pFDR;
#define cbFDR sizeof(FDR)
#define fdNil ((pFDR)0)
#define ifdNil -1
#define ifdTemp 0
#define ilnNil -1


/* 
 * Procedure Descriptor
 *
 * There is one of these for EVERY TEXT LABEL.
 * If a procedure is in a file with full symbols, then isym
 * will point to the PROC symbols, else it will point to the
 * global symbol for the label.
 */

typedef struct pdr {
	bfd_vma	adr;		/* memory address of start of procedure */
	long	isym;		/* start of local symbol entries */
	long	iline;		/* start of line number entries*/
	long	regmask;	/* save register mask */
	long	regoffset;	/* save register offset */
	long	iopt;		/* start of optimization symbol entries*/
	long	fregmask;	/* save floating point register mask */
	long	fregoffset;	/* save floating point register offset */
	long	frameoffset;	/* frame size */
	short	framereg;	/* frame pointer register */
	short	pcreg;		/* offset or reg of return pc */
	long	lnLow;		/* lowest line in the procedure */
	long	lnHigh;		/* highest line in the procedure */
	bfd_vma	cbLineOffset;	/* byte offset for this procedure from the fd base */
	/* These fields are new for 64 bit ECOFF.  */
	unsigned gp_prologue : 8; /* byte size of GP prologue */
	unsigned gp_used : 1;	/* true if the procedure uses GP */
	unsigned reg_frame : 1;	/* true if register frame procedure */
	unsigned prof : 1;	/* true if compiled with -pg */
	unsigned reserved : 13;	/* reserved: must be zero */
	unsigned localoff : 8;	/* offset of local variables from vfp */
	} PDR, *pPDR;
#define cbPDR sizeof(PDR)
#define pdNil ((pPDR) 0)
#define ipdNil	-1

/*
 * The structure of the runtime procedure descriptor created by the loader
 * for use by the static exception system.
 */
/*
 * If 0'd out because exception_info chokes Visual C++ and because there
 * don't seem to be any references to this structure elsewhere in gdb.
 */
#if 0
typedef struct runtime_pdr {
	bfd_vma	adr;		/* memory address of start of procedure */
	long	regmask;	/* save register mask */
	long	regoffset;	/* save register offset */
	long	fregmask;	/* save floating point register mask */
	long	fregoffset;	/* save floating point register offset */
	long	frameoffset;	/* frame size */
	short	framereg;	/* frame pointer register */
	short	pcreg;		/* offset or reg of return pc */
	long	irpss;		/* index into the runtime string table */
	long	reserved;
	struct exception_info *exception_info;/* pointer to exception array */
} RPDR, *pRPDR;
#define cbRPDR sizeof(RPDR)
#define rpdNil ((pRPDR) 0)
#endif

/*
 * Line Numbers
 *
 * Line Numbers are segregated from the normal symbols because they
 * are [1] smaller , [2] are of no interest to your
 * average loader, and [3] are never needed in the middle of normal
 * scanning and therefore slow things down.
 *
 * By definition, the first LINER for any given procedure will have
 * the first line of a procedure and represent the first address.
 */

typedef	long LINER, *pLINER;
#define lineNil ((pLINER)0)
#define cbLINER sizeof(LINER)
#define ilineNil	-1



/*
 * The Symbol Structure		(GFW, to those who Know!)
 */

typedef struct {
	long	iss;		/* index into String Space of name */
	bfd_vma	value;		/* value of symbol */
	unsigned st : 6;	/* symbol type */
	unsigned sc  : 5;	/* storage class - text, data, etc */
	unsigned reserved : 1;	/* reserved */
	unsigned index : 20;	/* index into sym/aux table */
	} SYMR, *pSYMR;
#define symNil ((pSYMR)0)
#define cbSYMR sizeof(SYMR)
#define isymNil -1
#define indexNil 0xfffff
#define issNil -1
#define issNull 0


/* The following converts a memory resident string to an iss.
 * This hack is recognized in SbFIss, in sym.c of the debugger.
 */
#define IssFSb(sb) (0x80000000 | ((unsigned long)(sb)))

/* E X T E R N A L   S Y M B O L  R E C O R D
 *
 *	Same as the SYMR except it contains file context to determine where
 *	the index is.
 */
typedef struct ecoff_extr {
	unsigned jmptbl:1;	/* symbol is a jump table entry for shlibs */
	unsigned cobol_main:1;	/* symbol is a cobol main procedure */
	unsigned weakext:1;	/* symbol is weak external */
	unsigned reserved:13;	/* reserved for future use */
	int	ifd;		/* where the iss and index fields point into */
	SYMR	asym;		/* symbol for the external */
	} EXTR, *pEXTR;
#define extNil ((pEXTR)0)
#define cbEXTR sizeof(EXTR)


/* A U X I L L A R Y   T Y P E	 I N F O R M A T I O N */

/*
 * Type Information Record
 */
typedef struct {
	unsigned fBitfield : 1; /* set if bit width is specified */
	unsigned continued : 1; /* indicates additional TQ info in next AUX */
	unsigned bt  : 6;	/* basic type */
	unsigned tq4 : 4;
	unsigned tq5 : 4;
	/* ---- 16 bit boundary ---- */
	unsigned tq0 : 4;
	unsigned tq1 : 4;	/* 6 type qualifiers - tqPtr, etc. */
	unsigned tq2 : 4;
	unsigned tq3 : 4;
	} TIR, *pTIR;
#define cbTIR sizeof(TIR)
#define tiNil ((pTIR)0)
#define itqMax 6

/*
 * Relative symbol record
 *
 * If the rfd field is 4095, the index field indexes into the global symbol
 *	table.
 */

typedef struct {
	unsigned	rfd : 12;    /* index into the file indirect table */
	unsigned	index : 20; /* index int sym/aux/iss tables */
	} RNDXR, *pRNDXR;
#define cbRNDXR sizeof(RNDXR)
#define rndxNil ((pRNDXR)0)

/* dense numbers or sometimes called block numbers are stored in this type,
 *	a rfd of 0xffffffff is an index into the global table.
 */
typedef struct {
	unsigned long	rfd;    /* index into the file table */
	unsigned long	index; 	/* index int sym/aux/iss tables */
	} DNR, *pDNR;
#define cbDNR sizeof(DNR)
#define dnNil ((pDNR)0)



/*
 * Auxillary information occurs only if needed.
 * It ALWAYS occurs in this order when present.

	    isymMac		used by stProc only
	    TIR			type info
	    TIR			additional TQ info (if first TIR was not enough)
	    rndx		if (bt == btStruct,btUnion,btEnum,btSet,btRange,
				    btTypedef):
				    rsym.index == iaux for btSet or btRange
				    else rsym.index == isym
	    dimLow		btRange, btSet
	    dimMac		btRange, btSet
	    rndx0		As many as there are tq arrays
	    dimLow0
	    dimHigh0
	    ...
	    rndxMax-1
	    dimLowMax-1
	    dimHighMax-1
	    width in bits	if (bit field), width in bits.
 */
#define cAuxMax (6 + (idimMax*3))

/* a union of all possible info in the AUX universe */
typedef union {
	TIR	ti;		/* type information record */
	RNDXR	rndx;		/* relative index into symbol table */
	long	dnLow;		/* low dimension */
	long	dnHigh;		/* high dimension */
	long	isym;		/* symbol table index (end of proc) */
	long	iss;		/* index into string space (not used) */
	long	width;		/* width for non-default sized struc fields */
	long	count;		/* count of ranges for variant arm */
	} AUXU, *pAUXU;
#define cbAUXU sizeof(AUXU)
#define auxNil ((pAUXU)0)
#define iauxNil -1


/*
 * Optimization symbols
 *
 * Optimization symbols contain some overlap information with the normal
 * symbol table. In particular, the proc information
 * is somewhat redundant but necessary to easily find the other information
 * present. 
 *
 * All of the offsets are relative to the beginning of the last otProc
 */

typedef struct {
	unsigned ot: 8;		/* optimization type */
	unsigned value: 24;	/* address where we are moving it to */
	RNDXR	rndx;		/* points to a symbol or opt entry */
	unsigned long	offset;	/* relative offset this occured */
	} OPTR, *pOPTR;
#define optNil	((pOPTR) 0)
#define cbOPTR sizeof(OPTR)
#define ioptNil -1

/*
 * File Indirect
 *
 * When a symbol is referenced across files the following procedure is used:
 *	1) use the file index to get the File indirect entry.
 *	2) use the file indirect entry to get the File descriptor.
 *	3) add the sym index to the base of that file's sym table
 *
 */

typedef long RFDT, *pRFDT;
#define cbRFDT sizeof(RFDT)
#define rfdNil	-1

/*
 * The file indirect table in the mips loader is known as an array of FITs.
 * This is done to keep the code in the loader readable in the area where
 * these tables are merged.  Note this is only a name change.
 */
typedef long FIT, *pFIT;
#define cbFIT	sizeof(FIT)
#define ifiNil	-1
#define fiNil	((pFIT) 0)

#ifdef _LANGUAGE_PASCAL
#define ifdNil -1
#define ilnNil -1
#define ipdNil -1
#define ilineNil -1
#define isymNil -1
#define indexNil 16#fffff
#define issNil -1
#define issNull 0
#define itqMax 6
#define iauxNil -1
#define ioptNil -1
#define rfdNil -1
#define ifiNil -1
#endif	/* _LANGUAGE_PASCAL */


/* Dense numbers
 *
 * Rather than use file index, symbol index pairs to represent symbols
 *	and globals, we use dense number so that they can be easily embeded
 *	in intermediate code and the programs that process them can
 *	use direct access tabls instead of hash table (which would be
 *	necesary otherwise because of the sparse name space caused by
 *	file index, symbol index pairs. Dense number are represented
 *	by RNDXRs.
 */

/*
 * The following table defines the meaning of each SYM field as
 * a function of the "st". (scD/B == scData OR scBss)
 *
 * Note: the value "isymMac" is used by symbols that have the concept
 * of enclosing a block of related information.	 This value is the
 * isym of the first symbol AFTER the end associated with the primary
 * symbol. For example if a procedure was at isym==90 and had an
 * isymMac==155, the associated end would be at isym==154, and the
 * symbol at 155 would probably (although not necessarily) be the
 * symbol for the next procedure.  This allows rapid skipping over
 * internal information of various sorts. "stEnd"s ALWAYS have the
 * isym of the primary symbol that started the block.
 * 

ST		SC	VALUE		INDEX
--------	------	--------	------
stFile		scText	address		isymMac
stLabel		scText	address		---
stGlobal	scD/B	address		iaux
stStatic	scD/B	address		iaux
stParam		scAbs	offset		iaux
stLocal		scAbs	offset		iaux
stProc		scText	address		iaux	(isymMac is first AUX)
stStaticProc	scText	address		iaux	(isymMac is first AUX)

stMember	scNil	ordinal		---	(if member of enum)
	(mipsread thinks the case below has a bit, not byte, offset.)
stMember	scNil	byte offset	iaux	(if member of struct/union)
stMember	scBits	bit offset	iaux	(bit field spec)

stBlock		scText	address		isymMac (text block)
	(the code seems to think that rather than scNil, we see scInfo for
	 the two cases below.)
stBlock		scNil	cb		isymMac (struct/union member define)
stBlock		scNil	cMembers	isymMac (enum member define)

	(New types added by SGI to simplify things:)
stStruct	scInfo	cb		isymMac (struct type define)
stUnion		scInfo	cb		isymMac (union  type define)
stEnum		scInfo	cMembers	isymMac (enum   type define)

stEnd		scText	address		isymStart
stEnd		scNil	-------		isymStart (struct/union/enum)

stTypedef	scNil	-------		iaux
stRegReloc	sc???	value		old register number
stForward	sc???	new address	isym to original symbol

stConstant	scInfo	value		--- (scalar)
stConstant	scInfo	iss		--- (complex, e.g. string)

 *
 */
#endif