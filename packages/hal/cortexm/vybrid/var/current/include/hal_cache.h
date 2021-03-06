#ifndef CYGONCE_HAL_CACHE_H
#define CYGONCE_HAL_CACHE_H
//=============================================================================
//
//      hal_cache.h
//
//      HAL cache control API
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2012 Free Software Foundation, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//=============================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    Antmicro Ltd <contact@antmicro.com>
// Based on:	 {...}/hal/packages/cortexm/kinetis/var/current/include/hal_cache.h
// Date:         2014-03-28
// Purpose:      Cache control API
// Description:  The macros defined here provide the HAL APIs for handling
//               cache control operations.
//
// Usage:
//               #include <cyg/hal/hal_cache.h>
//               ...
//
//
//####DESCRIPTIONEND####
//
//=============================================================================

#include <cyg/infra/cyg_type.h>

//-----------------------------------------------------------------------------
// Cache dimensions
#ifdef CYGINT_HAL_CACHE

// Data cache
#define HAL_DCACHE_SIZE                 (1024 * 16)    // Size of data cache in bytes
#define HAL_DCACHE_LINE_SIZE            32      // Size of a data cache line
#define HAL_DCACHE_WAYS                 2       // Associativity of the cache

// Instruction cache
#define HAL_ICACHE_SIZE                 (1024 * 16)    // Size of cache in bytes
#define HAL_ICACHE_LINE_SIZE            32      // Size of a cache line
#define HAL_ICACHE_WAYS                 2       // Associativity of the cache

#define HAL_DCACHE_SETS (HAL_DCACHE_SIZE/(HAL_DCACHE_LINE_SIZE*HAL_DCACHE_WAYS))
#define HAL_ICACHE_SETS (HAL_ICACHE_SIZE/(HAL_ICACHE_LINE_SIZE*HAL_ICACHE_WAYS))

#include <cyg/hal/var_io.h>
#include <cyg/hal/var_io_lmem.h>

//-----------------------------------------------------------------------------
// Global control of data cache

// Enable the data cache
#define HAL_DCACHE_ENABLE() HAL_CORTEXM_VYBRID_CACHE_PS_ENABLE()

// Disable the data cache
#define HAL_DCACHE_DISABLE() HAL_CORTEXM_VYBRID_CACHE_PS_DISABLE()

// Invalidate the entire cache
#define HAL_DCACHE_INVALIDATE_ALL() HAL_CORTEXM_VYBRID_CACHE_PS_INVALL()

// Synchronize the contents of the cache with memory.
#define HAL_DCACHE_SYNC() HAL_CORTEXM_VYBRID_CACHE_PS_SYNC()

// Purge contents of data cache
#define HAL_DCACHE_PURGE_ALL() HAL_CORTEXM_VYBRID_CACHE_PS_CLEAR()

// Query the state of the data cache (does not affect the caching)
#define HAL_DCACHE_IS_ENABLED(_state_)                         \
    CYG_MACRO_START                                            \
        (_state_) = HAL_CORTEXM_VYBRID_CACHE_PS_IS_ENABLED(); \
    CYG_MACRO_END

// Invalidate cache lines in the given range without writing to memory.
#define HAL_DCACHE_INVALIDATE( _base_ , _size_ )                  \
            HAL_CORTEXM_VYBRID_CACHE_PS_INVALIDATE(_base_, _size_)

// Write dirty cache lines to memory and invalidate the cache entries
#define HAL_DCACHE_FLUSH( _base_ , _size_ )                  \
            HAL_CORTEXM_VYBRID_CACHE_PS_CLR(_base_, _size_)

//-----------------------------------------------------------------------------
// Global control of Instruction cache

// Enable the instruction cache
#define HAL_ICACHE_ENABLE() HAL_CORTEXM_VYBRID_CACHE_PC_ENABLE()

// Disable the instruction cache
#define HAL_ICACHE_DISABLE() HAL_CORTEXM_VYBRID_CACHE_PC_DISABLE()

// Invalidate the entire cache
#define HAL_ICACHE_INVALIDATE_ALL() HAL_CORTEXM_VYBRID_CACHE_PC_INVALL()

// Synchronize the contents of the cache with memory.
#define HAL_ICACHE_SYNC() HAL_CORTEXM_VYBRID_CACHE_PC_SYNC()

// Purge contents of data cache
#define HAL_ICACHE_PURGE_ALL() HAL_CORTEXM_VYBRID_CACHE_PC_CLEAR()

// Query the state of the instruction cache (does not affect the caching)
#define HAL_ICACHE_IS_ENABLED(_state_)                        \
    CYG_MACRO_START                                           \
        (_state_) = HAL_CORTEXM_VYBRID_CACHE_PC_IS_ENABLED(); \
    CYG_MACRO_END


//-----------------------------------------------------------------------------
// Instruction cache line control

// Invalidate cache lines in the given range without writing to memory.
#define HAL_ICACHE_INVALIDATE( _base_ , _size_ )                  \
            HAL_CORTEXM_VYBRID_CACHE_PC_INVALIDATE(_base_, _size_)

#else // CYGINT_HAL_CACHE


// Enable the data cache
#define HAL_DCACHE_ENABLE()

// Disable the data cache
#define HAL_DCACHE_DISABLE()

// Invalidate the entire cache
#define HAL_DCACHE_INVALIDATE_ALL()

// Synchronize the contents of the cache with memory.
#define HAL_DCACHE_SYNC()

// Purge contents of data cache
#define HAL_DCACHE_PURGE_ALL()

// Query the state of the data cache (does not affect the caching)
#define HAL_DCACHE_IS_ENABLED(_state_) \
    CYG_MACRO_START                    \
    (_state_) = 0;                     \
    CYG_MACRO_END


//-----------------------------------------------------------------------------
// Data cache line control

// Write dirty cache lines to memory and invalidate the cache entries
// for the given address range.
#define HAL_DCACHE_FLUSH( _base_ , _size_ )

// Invalidate cache lines in the given range without writing to memory.
#define HAL_DCACHE_INVALIDATE( _base_ , _size_ )

//-----------------------------------------------------------------------------
// Global control of Instruction cache

// Enable the instruction cache
#define HAL_ICACHE_ENABLE()

// Disable the instruction cache
#define HAL_ICACHE_DISABLE()

// Invalidate the entire cache
#define HAL_ICACHE_INVALIDATE_ALL()

// Synchronize the contents of the cache with memory.
#define HAL_ICACHE_SYNC()

// Query the state of the instruction cache (does not affect the caching)
#define HAL_ICACHE_IS_ENABLED(_state_) \
    CYG_MACRO_START                    \
        (_state_) = 0;                 \
    CYG_MACRO_END

//-----------------------------------------------------------------------------
// Instruction cache line control

// Invalidate cache lines in the given range without writing to memory.
#define HAL_ICACHE_INVALIDATE( _base_ , _size_ )

#endif // CYGINT_HAL_CACHE

// End of hal_cache.h
#endif // CYGONCE_HAL_CACHE_H
