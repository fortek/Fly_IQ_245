/* Copyright Statement:
 * 
 * This software/firmware and related documentation ("MediaTek Software") are 
 * protected under relevant copyright laws. The information contained herein is 
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without 
 * the prior written permission of MediaTek inc. and/or its licensors, any 
 * reproduction, modification, use or disclosure of MediaTek Software, and 
 * information contained herein, in whole or in part, shall be strictly 
 * prohibited.  
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") 
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON 
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER 
 * DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF 
 * ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE 
 * MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR 
 * ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT 
 * IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER 
 * LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE 
 * RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S 
 * SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. 
 * RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE 
 * LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, 
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO 
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */
/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _ASM_GENERIC_PGTABLE_H
#define _ASM_GENERIC_PGTABLE_H

#ifndef __HAVE_ARCH_PTEP_ESTABLISH

#ifndef __HAVE_ARCH_SET_PTE_ATOMIC
#define ptep_establish(__vma, __address, __ptep, __entry)  do {   set_pte_at((__vma)->vm_mm, (__address), __ptep, __entry);   flush_tlb_page(__vma, __address);  } while (0)
#else
#define ptep_establish(__vma, __address, __ptep, __entry)  do {   set_pte_atomic(__ptep, __entry);   flush_tlb_page(__vma, __address);  } while (0)
#endif
#endif

#ifndef __HAVE_ARCH_PTEP_SET_ACCESS_FLAGS

#define ptep_set_access_flags(__vma, __address, __ptep, __entry, __dirty)  do {   set_pte_at((__vma)->vm_mm, (__address), __ptep, __entry);   flush_tlb_page(__vma, __address);  } while (0)
#endif

#ifndef __HAVE_ARCH_PTEP_TEST_AND_CLEAR_YOUNG
#define ptep_test_and_clear_young(__vma, __address, __ptep)  ({   pte_t __pte = *(__ptep);   int r = 1;   if (!pte_young(__pte))   r = 0;   else   set_pte_at((__vma)->vm_mm, (__address),   (__ptep), pte_mkold(__pte));   r;  })
#endif

#ifndef __HAVE_ARCH_PTEP_CLEAR_YOUNG_FLUSH
#define ptep_clear_flush_young(__vma, __address, __ptep)  ({   int __young;   __young = ptep_test_and_clear_young(__vma, __address, __ptep);   if (__young)   flush_tlb_page(__vma, __address);   __young;  })
#endif

#ifndef __HAVE_ARCH_PTEP_TEST_AND_CLEAR_DIRTY
#define ptep_test_and_clear_dirty(__vma, __address, __ptep)  ({   pte_t __pte = *__ptep;   int r = 1;   if (!pte_dirty(__pte))   r = 0;   else   set_pte_at((__vma)->vm_mm, (__address), (__ptep),   pte_mkclean(__pte));   r;  })
#endif

#ifndef __HAVE_ARCH_PTEP_CLEAR_DIRTY_FLUSH
#define ptep_clear_flush_dirty(__vma, __address, __ptep)  ({   int __dirty;   __dirty = ptep_test_and_clear_dirty(__vma, __address, __ptep);   if (__dirty)   flush_tlb_page(__vma, __address);   __dirty;  })
#endif

#ifndef __HAVE_ARCH_PTEP_GET_AND_CLEAR
#define ptep_get_and_clear(__mm, __address, __ptep)  ({   pte_t __pte = *(__ptep);   pte_clear((__mm), (__address), (__ptep));   __pte;  })
#endif

#ifndef __HAVE_ARCH_PTEP_GET_AND_CLEAR_FULL
#define ptep_get_and_clear_full(__mm, __address, __ptep, __full)  ({   pte_t __pte;   __pte = ptep_get_and_clear((__mm), (__address), (__ptep));   __pte;  })
#endif

#ifndef __HAVE_ARCH_PTE_CLEAR_FULL
#define pte_clear_full(__mm, __address, __ptep, __full)  do {   pte_clear((__mm), (__address), (__ptep));  } while (0)
#endif

#ifndef __HAVE_ARCH_PTEP_CLEAR_FLUSH
#define ptep_clear_flush(__vma, __address, __ptep)  ({   pte_t __pte;   __pte = ptep_get_and_clear((__vma)->vm_mm, __address, __ptep);   flush_tlb_page(__vma, __address);   __pte;  })
#endif

#ifndef __HAVE_ARCH_PTEP_SET_WRPROTECT
struct mm_struct;
#endif
#ifndef __HAVE_ARCH_PTE_SAME
#define pte_same(A,B) (pte_val(A) == pte_val(B))
#endif
#ifndef __HAVE_ARCH_PAGE_TEST_AND_CLEAR_DIRTY
#define page_test_and_clear_dirty(page) (0)
#define pte_maybe_dirty(pte) pte_dirty(pte)
#else
#define pte_maybe_dirty(pte) (1)
#endif
#ifndef __HAVE_ARCH_PAGE_TEST_AND_CLEAR_YOUNG
#define page_test_and_clear_young(page) (0)
#endif
#ifndef __HAVE_ARCH_PGD_OFFSET_GATE
#define pgd_offset_gate(mm, addr) pgd_offset(mm, addr)
#endif
#ifndef __HAVE_ARCH_LAZY_MMU_PROT_UPDATE
#define lazy_mmu_prot_update(pte) do { } while (0)
#endif
#ifndef __HAVE_ARCH_MOVE_PTE
#define move_pte(pte, prot, old_addr, new_addr) (pte)
#endif
#define pgd_addr_end(addr, end)  ({ unsigned long __boundary = ((addr) + PGDIR_SIZE) & PGDIR_MASK;   (__boundary - 1 < (end) - 1)? __boundary: (end);  })
#ifndef pud_addr_end
#define pud_addr_end(addr, end)  ({ unsigned long __boundary = ((addr) + PUD_SIZE) & PUD_MASK;   (__boundary - 1 < (end) - 1)? __boundary: (end);  })
#endif
#ifndef pmd_addr_end
#define pmd_addr_end(addr, end)  ({ unsigned long __boundary = ((addr) + PMD_SIZE) & PMD_MASK;   (__boundary - 1 < (end) - 1)? __boundary: (end);  })
#endif
#ifndef __ASSEMBLY__

#endif
#endif
