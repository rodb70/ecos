#ifndef CYGONCE_HAL_VAR_IO_USART_H
#define CYGONCE_HAL_VAR_IO_USART_H
//=============================================================================
//
//      var_io_usart.h
//
//      USART-specific variant definitions
//
//=============================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2008, 2009, 2011 Free Software Foundation, Inc.            
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
// Author(s):   nickg, jlarmour
// Date:        2008-07-30
// Purpose:     STM32 variant USART specific registers
// Description: 
// Usage:       Do not include this header file directly. Instead:
//              #include <cyg/hal/var_io.h>
//
//####DESCRIPTIONEND####
//
//=============================================================================

#ifndef CYGONCE_HAL_VAR_IO_H
# error Do not include var_io_usart.h directly, use var_io.h
#endif

//=============================================================================
// UARTs

#ifdef CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_CR1               0x00
#define CYGHWR_HAL_STM32_UART_CR2               0x04
#define CYGHWR_HAL_STM32_UART_CR3               0x08
#define CYGHWR_HAL_STM32_UART_BRR               0x0C
#define CYGHWR_HAL_STM32_UART_GTPR              0x10
#define CYGHWR_HAL_STM32_UART_RTOR              0x14
#define CYGHWR_HAL_STM32_UART_RQR               0x18
#define CYGHWR_HAL_STM32_UART_ISR               0x1C
#define CYGHWR_HAL_STM32_UART_ICR               0x20
#define CYGHWR_HAL_STM32_UART_RDR               0x24
#define CYGHWR_HAL_STM32_UART_TDR               0x28

#else // CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_SR                0x00
#define CYGHWR_HAL_STM32_UART_DR                0x04
#define CYGHWR_HAL_STM32_UART_BRR               0x08
#define CYGHWR_HAL_STM32_UART_CR1               0x0C
#define CYGHWR_HAL_STM32_UART_CR2               0x10
#define CYGHWR_HAL_STM32_UART_CR3               0x14
#define CYGHWR_HAL_STM32_UART_GTPR              0x18
#endif //else CYGHWR_HAL_CORTEXM_M7

// SR/ISR Bits

#define CYGHWR_HAL_STM32_UART_SR_PE             BIT_(0)
#define CYGHWR_HAL_STM32_UART_SR_FE             BIT_(1)
#define CYGHWR_HAL_STM32_UART_SR_NE             BIT_(2)
#define CYGHWR_HAL_STM32_UART_SR_NF             BIT_(2)
#define CYGHWR_HAL_STM32_UART_SR_ORE            BIT_(3)
#define CYGHWR_HAL_STM32_UART_SR_IDLE           BIT_(4)
#define CYGHWR_HAL_STM32_UART_SR_RXNE           BIT_(5)
#define CYGHWR_HAL_STM32_UART_SR_TC             BIT_(6)
#define CYGHWR_HAL_STM32_UART_SR_TXE            BIT_(7)
#define CYGHWR_HAL_STM32_UART_SR_LBD            BIT_(8)
#ifndef CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_SR_CTS            BIT_(9)
#else
#define CYGHWR_HAL_STM32_UART_ISR_CTSIF         BIT_(9)
#define CYGHWR_HAL_STM32_UART_ISR_CTS           BIT_(10)
#define CYGHWR_HAL_STM32_UART_ISR_RTOF          BIT_(11)
#define CYGHWR_HAL_STM32_UART_ISR_EOBF          BIT_(12)
#define CYGHWR_HAL_STM32_UART_ISR_ABRE          BIT_(14)
#define CYGHWR_HAL_STM32_UART_ISR_ABRF          BIT_(15)
#define CYGHWR_HAL_STM32_UART_ISR_BUSY          BIT_(16)
#define CYGHWR_HAL_STM32_UART_ISR_CMF           BIT_(17)
#define CYGHWR_HAL_STM32_UART_ISR_SBKF          BIT_(18)
#define CYGHWR_HAL_STM32_UART_ISR_TEACK         BIT_(21)
#endif


#ifdef CYGHWR_HAL_CORTEXM_M7
// ICR Bits (only STM32F7)
#define CYGHWR_HAL_STM32_UART_ICR_PECF          BIT_(0)
#define CYGHWR_HAL_STM32_UART_ICR_FECF          BIT_(1)
#define CYGHWR_HAL_STM32_UART_ICR_NCF           BIT_(2)
#define CYGHWR_HAL_STM32_UART_ICR_ORECF         BIT_(3)
#define CYGHWR_HAL_STM32_UART_ICR_IDLECF        BIT_(4)
#define CYGHWR_HAL_STM32_UART_ICR_TCCF          BIT_(6)
#define CYGHWR_HAL_STM32_UART_ICR_LBDCF         BIT_(8)
#define CYGHWR_HAL_STM32_UART_ICR_CTSCF         BIT_(9)
#define CYGHWR_HAL_STM32_UART_ICR_RTOCF         BIT_(11)
#define CYGHWR_HAL_STM32_UART_ICR_EOBCF         BIT_(12)
#define CYGHWR_HAL_STM32_UART_ICR_CMCF          BIT_(17)
#endif

// BRR bits

#ifdef CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_BRR_DIVF(__f)      VALUE_(0,__f)
#define CYGHWR_HAL_STM32_UART_BRR_DIVM(__m)      VALUE_(4,__m)
#else //CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_DR_DIVF(__f)      VALUE_(0,__f)
#define CYGHWR_HAL_STM32_UART_DR_DIVM(__m)      VALUE_(4,__m)
#endif // else CYGHWR_HAL_CORTEXM_M7

// CR1 bits

#ifdef CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_CR1_UE            BIT_(0)
#define CYGHWR_HAL_STM32_UART_CR1_RE            BIT_(2)
#define CYGHWR_HAL_STM32_UART_CR1_TE            BIT_(3)
#define CYGHWR_HAL_STM32_UART_CR1_IDLEIE        BIT_(4)
#define CYGHWR_HAL_STM32_UART_CR1_RXNEIE        BIT_(5)
#define CYGHWR_HAL_STM32_UART_CR1_TCIE          BIT_(6)
#define CYGHWR_HAL_STM32_UART_CR1_TXEIE         BIT_(7)
#define CYGHWR_HAL_STM32_UART_CR1_PEIE          BIT_(8)
#define CYGHWR_HAL_STM32_UART_CR1_PS_EVEN       0
#define CYGHWR_HAL_STM32_UART_CR1_PS_ODD        BIT_(9)
#define CYGHWR_HAL_STM32_UART_CR1_PCE           BIT_(10)
#define CYGHWR_HAL_STM32_UART_CR1_WAKE          BIT_(11)
#define CYGHWR_HAL_STM32_UART_CR1_M_8           0
#define CYGHWR_HAL_STM32_UART_CR1_M_9           BIT_(12)
#define CYGHWR_HAL_STM32_UART_CR1_MME           BIT_(13)
#define CYGHWR_HAL_STM32_UART_CR1_CMIE          BIT_(14)
#define CYGHWR_HAL_STM32_UART_CR1_OVER8         BIT_(15)
#define CYGHWR_HAL_STM32_UART_CR1_RTOIE         BIT_(26)
#define CYGHWR_HAL_STM32_UART_CR1_EOBIE         BIT_(27)
#define CYGHWR_HAL_STM32_UART_CR1_M1            BIT_(28)
#else // CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_CR1_SBK           BIT_(0)
#define CYGHWR_HAL_STM32_UART_CR1_RWU           BIT_(1)
#define CYGHWR_HAL_STM32_UART_CR1_RE            BIT_(2)
#define CYGHWR_HAL_STM32_UART_CR1_TE            BIT_(3)
#define CYGHWR_HAL_STM32_UART_CR1_IDLEIE        BIT_(4)
#define CYGHWR_HAL_STM32_UART_CR1_RXNEIE        BIT_(5)
#define CYGHWR_HAL_STM32_UART_CR1_TCIE          BIT_(6)
#define CYGHWR_HAL_STM32_UART_CR1_TXEIE         BIT_(7)
#define CYGHWR_HAL_STM32_UART_CR1_PEIE          BIT_(8)
#define CYGHWR_HAL_STM32_UART_CR1_PS_EVEN       0
#define CYGHWR_HAL_STM32_UART_CR1_PS_ODD        BIT_(9)
#define CYGHWR_HAL_STM32_UART_CR1_PCE           BIT_(10)
#define CYGHWR_HAL_STM32_UART_CR1_WAKE          BIT_(11)
#define CYGHWR_HAL_STM32_UART_CR1_M_8           0
#define CYGHWR_HAL_STM32_UART_CR1_M_9           BIT_(12)
#define CYGHWR_HAL_STM32_UART_CR1_UE            BIT_(13)
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_HIPERFORMANCE)
#define CYGHWR_HAL_STM32_UART_CR1_OVER8         BIT_(15)
#endif
#endif // else CYGHWR_HAL_CORTEXM_M7

// CR2 bits

#ifdef CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_CR2_ADD(__a)      VALUE_(28,__a)
#else // CYGHWR_HAL_CORTEXM_M7
#define CYGHWR_HAL_STM32_UART_CR2_ADD(__a)      VALUE_(0,__a)
#endif // else CYGHWR_HAL_CORTEXM_M7

#define CYGHWR_HAL_STM32_UART_CR2_LBDL          BIT_(5)
#define CYGHWR_HAL_STM32_UART_CR2_LBDIE         BIT_(6)
#define CYGHWR_HAL_STM32_UART_CR2_LBCL          BIT_(8)
#define CYGHWR_HAL_STM32_UART_CR2_CPHA          BIT_(9)
#define CYGHWR_HAL_STM32_UART_CR2_CPOL          BIT_(10)
#define CYGHWR_HAL_STM32_UART_CR2_CLKEN         BIT_(11)
#define CYGHWR_HAL_STM32_UART_CR2_STOP_1        VALUE_(12,0)
#define CYGHWR_HAL_STM32_UART_CR2_STOP_0_5      VALUE_(12,1)
#define CYGHWR_HAL_STM32_UART_CR2_STOP_2        VALUE_(12,2)
#define CYGHWR_HAL_STM32_UART_CR2_STOP_1_5      VALUE_(12,3)
#define CYGHWR_HAL_STM32_UART_CR2_LINEN         BIT_(14)

// CR3 bits

#define CYGHWR_HAL_STM32_UART_CR3_EIE           BIT_(0)
#define CYGHWR_HAL_STM32_UART_CR3_IREN          BIT_(1)
#define CYGHWR_HAL_STM32_UART_CR3_IRLP          BIT_(2)
#define CYGHWR_HAL_STM32_UART_CR3_HDSEL         BIT_(3)
#define CYGHWR_HAL_STM32_UART_CR3_NACK          BIT_(4)
#define CYGHWR_HAL_STM32_UART_CR3_SCEN          BIT_(5)
#define CYGHWR_HAL_STM32_UART_CR3_DMAR          BIT_(6)
#define CYGHWR_HAL_STM32_UART_CR3_DMAT          BIT_(7)
#define CYGHWR_HAL_STM32_UART_CR3_RTSE          BIT_(8)
#define CYGHWR_HAL_STM32_UART_CR3_CTSE          BIT_(9)
#define CYGHWR_HAL_STM32_UART_CR3_CTSIE         BIT_(10)

// GTPR fields

#define CYGHWR_HAL_STM32_UART_GTPR_PSC(__p)     VALUE_(0,__p)
#define CYGHWR_HAL_STM32_UART_GTPR_GT(__g)      VALUE_(8,__g)

// UART GPIO pins


// NOTE: For those UARTS providing a RTS pin the driver uses HW CTS control but
// manually controls the RTS as a GPIO.

// Macros for remaps
#define stm32_serial_pin_in( __port_pin, __af )    CYGHWR_HAL_STM32_PIN_ALTFN_IN( __port_pin ,  __af, NA,       FLOATING )
#define stm32_serial_pin_out( __port_pin, __af )    CYGHWR_HAL_STM32_PIN_ALTFN_OUT( __port_pin ,  __af, PUSHPULL, NONE,    50MHZ )
#define stm32_serial_pin_rts_out( __port_pin )    CYGHWR_HAL_STM32_PIN_OUT( __port_pin , PUSHPULL, NONE, 50MHZ )

#ifndef CYGHWR_HAL_STM32_UART0_REMAP
#define CYGHWR_HAL_STM32_UART1_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN(  A, 10,  7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART1_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( A,  9,  7, PUSHPULL, NONE,    50MHZ )
#define CYGHWR_HAL_STM32_UART1_CTS              CYGHWR_HAL_STM32_PIN_ALTFN_IN(  A, 11,  7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART1_RTS              CYGHWR_HAL_STM32_PIN_OUT( A, 12, PUSHPULL, NONE, 50MHZ )
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#define CYGHWR_HAL_STM32_UART1_REMAP_CONFIG     0
#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1
#else // CYGHWR_HAL_STM32_UART0_REMAP
#define CYGHWR_HAL_STM32_UART1_RX               stm32_serial_pin_in( CYGHWR_HAL_STM32_UART0_PIN_RX,  7)
#define CYGHWR_HAL_STM32_UART1_TX               stm32_serial_pin_out( CYGHWR_HAL_STM32_UART0_PIN_TX,  7)
#define CYGHWR_HAL_STM32_UART1_CTS              stm32_serial_pin_in( CYGHWR_HAL_STM32_UART0_PIN_CTS,  7)
#define CYGHWR_HAL_STM32_UART1_RTS              stm32_serial_pin_rts_out( CYGHWR_HAL_STM32_UART0_PIN_RTS )
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#define CYGHWR_HAL_STM32_UART1_REMAP_CONFIG     CYGHWR_HAL_STM32_AFIO_MAPR_URT1_RMP
#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1
#endif // else CYGHWR_HAL_STM32_UART0_REMAP

#define CYGHWR_HAL_STM32_UART1_CLOCK            CYGHWR_HAL_STM32_CLOCK( APB2, UART1 )

#ifndef CYGHWR_HAL_STM32_UART1_REMAP
#define CYGHWR_HAL_STM32_UART2_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN( A,  3, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART2_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( A,  2, 7, PUSHPULL, NONE, 50MHZ )
#define CYGHWR_HAL_STM32_UART2_CTS              CYGHWR_HAL_STM32_PIN_ALTFN_IN( A,  0, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART2_RTS              CYGHWR_HAL_STM32_PIN_OUT( A, 1, PUSHPULL, NONE, 50MHZ )
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#define CYGHWR_HAL_STM32_UART2_REMAP_CONFIG     0
#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1
#else
#define CYGHWR_HAL_STM32_UART2_RX               stm32_serial_pin_in( CYGHWR_HAL_STM32_UART1_PIN_RX,  7)
#define CYGHWR_HAL_STM32_UART2_TX               stm32_serial_pin_out( CYGHWR_HAL_STM32_UART1_PIN_TX,  7)
#define CYGHWR_HAL_STM32_UART2_CTS              stm32_serial_pin_in( CYGHWR_HAL_STM32_UART1_PIN_CTS,  7)
#define CYGHWR_HAL_STM32_UART2_RTS              stm32_serial_pin_rts_out( CYGHWR_HAL_STM32_UART1_PIN_RTS )
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#define CYGHWR_HAL_STM32_UART2_REMAP_CONFIG     CYGHWR_HAL_STM32_AFIO_MAPR_URT2_RMP
#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1
#endif

#define CYGHWR_HAL_STM32_UART2_CLOCK            CYGHWR_HAL_STM32_CLOCK( APB1, UART2 )


#ifndef CYGHWR_HAL_STM32_UART2_REMAP_N
#define CYGHWR_HAL_STM32_UART3_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN(  B, 11, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART3_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( B, 10, 7, PUSHPULL, NONE, 50MHZ )
#define CYGHWR_HAL_STM32_UART3_CTS              CYGHWR_HAL_STM32_PIN_ALTFN_IN(  B, 13, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART3_RTS              CYGHWR_HAL_STM32_PIN_OUT( B, 14, PUSHPULL, NONE, 50MHZ )
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#define CYGHWR_HAL_STM32_UART3_REMAP_CONFIG     CYGHWR_HAL_STM32_AFIO_MAPR_URT3_NO_RMP
#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1

#else //CYGHWR_HAL_STM32_UART2_REMAP
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#if defined(CYGHWR_HAL_STM32_UART2_REMAP_PARTIAL)

#define CYGHWR_HAL_STM32_UART3_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN(  C, 11, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART3_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( C, 10, 7, PUSHPULL, NONE, 50MHZ )
#define CYGHWR_HAL_STM32_UART3_CTS              CYGHWR_HAL_STM32_PIN_ALTFN_IN(  B, 13, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART3_RTS              CYGHWR_HAL_STM32_PIN_OUT( B, 14, PUSHPULL, NONE, 50MHZ )
#define CYGHWR_HAL_STM32_UART3_REMAP_CONFIG     CYGHWR_HAL_STM32_AFIO_MAPR_URT3_P1_RMP

#elif defined(CYGHWR_HAL_STM32_UART2_REMAP_FULL)

#define CYGHWR_HAL_STM32_UART3_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN(  D,  9, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART3_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( D,  8, 7, PUSHPULL, NONE, 50MHZ )
#define CYGHWR_HAL_STM32_UART3_CTS              CYGHWR_HAL_STM32_PIN_ALTFN_IN(  D, 11, 7, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART3_RTS              CYGHWR_HAL_STM32_PIN_OUT( D, 12, PUSHPULL, NONE, 50MHZ )
#define CYGHWR_HAL_STM32_UART3_REMAP_CONFIG     CYGHWR_HAL_STM32_AFIO_MAPR_URT3_FL_RMP

#endif // REMAP PARTIAL/FULL
#else // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1

#define CYGHWR_HAL_STM32_UART3_RX               stm32_serial_pin_in( CYGHWR_HAL_STM32_UART2_PIN_RX,  7)
#define CYGHWR_HAL_STM32_UART3_TX               stm32_serial_pin_out( CYGHWR_HAL_STM32_UART2_PIN_TX,  7)
#define CYGHWR_HAL_STM32_UART3_CTS              stm32_serial_pin_in( CYGHWR_HAL_STM32_UART2_PIN_CTS,  7)
#define CYGHWR_HAL_STM32_UART3_RTS              stm32_serial_pin_rts_out( CYGHWR_HAL_STM32_UART2_PIN_RTS )

#endif
#endif // CYGHWR_HAL_STM32_UART2_REMAP

#define CYGHWR_HAL_STM32_UART3_CLOCK            CYGHWR_HAL_STM32_CLOCK( APB1, UART3 )

#ifndef CYGHWR_HAL_STM32_UART3_REMAP
#define CYGHWR_HAL_STM32_UART4_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN(  C, 11, 8, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART4_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( C, 10, 8, PUSHPULL, NONE, 50MHZ )
#else
#define CYGHWR_HAL_STM32_UART4_RX               stm32_serial_pin_in( CYGHWR_HAL_STM32_UART3_PIN_RX,  8)
#define CYGHWR_HAL_STM32_UART4_TX               stm32_serial_pin_out( CYGHWR_HAL_STM32_UART3_PIN_TX,  8)
#endif // CYGHWR_HAL_STM32_UART3_REMAP

#define CYGHWR_HAL_STM32_UART4_CTS              CYGHWR_HAL_STM32_GPIO_NONE
#define CYGHWR_HAL_STM32_UART4_RTS              CYGHWR_HAL_STM32_GPIO_NONE

#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#define CYGHWR_HAL_STM32_UART4_REMAP_CONFIG     0
#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1

#define CYGHWR_HAL_STM32_UART4_CLOCK            CYGHWR_HAL_STM32_CLOCK( APB1, UART4 )

#ifndef CYGHWR_HAL_STM32_UART4_REMAP
#define CYGHWR_HAL_STM32_UART5_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN(  D,  2, 8, NA,       FLOATING )
#define CYGHWR_HAL_STM32_UART5_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( C, 12, 8, PUSHPULL, NONE, 50MHZ )
#else
#define CYGHWR_HAL_STM32_UART5_RX               stm32_serial_pin_in( CYGHWR_HAL_STM32_UART4_PIN_RX,  8)
#define CYGHWR_HAL_STM32_UART5_TX               stm32_serial_pin_out( CYGHWR_HAL_STM32_UART4_PIN_TX,  8)
#endif //CYGHWR_HAL_STM32_UART4_REMAP

#define CYGHWR_HAL_STM32_UART5_CTS              CYGHWR_HAL_STM32_GPIO_NONE
#define CYGHWR_HAL_STM32_UART5_RTS              CYGHWR_HAL_STM32_GPIO_NONE
#if defined (CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1)
#define CYGHWR_HAL_STM32_UART5_REMAP_CONFIG     0
#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_F1

#define CYGHWR_HAL_STM32_UART5_CLOCK            CYGHWR_HAL_STM32_CLOCK( APB1, UART5 )

#if defined(CYGHWR_HAL_CORTEXM_STM32_FAMILY_HIPERFORMANCE)
#ifndef CYGHWR_HAL_STM32_UART5_REMAP
#define CYGHWR_HAL_STM32_UART6_RX               CYGHWR_HAL_STM32_PIN_ALTFN_IN(  C,  7, 8, NA,       NONE )
#define CYGHWR_HAL_STM32_UART6_TX               CYGHWR_HAL_STM32_PIN_ALTFN_OUT( C,  6, 8, PUSHPULL, NONE, 50MHZ )
#define CYGHWR_HAL_STM32_UART6_CTS              CYGHWR_HAL_STM32_PIN_ALTFN_IN(  G, 15, 8, NA,       NONE )
#define CYGHWR_HAL_STM32_UART6_RTS              CYGHWR_HAL_STM32_PIN_ALTFN_OUT( G,  8, 8, PUSHPULL, NONE, 50MHZ )
#else
#define CYGHWR_HAL_STM32_UART6_RX               stm32_serial_pin_in( CYGHWR_HAL_STM32_UART5_PIN_RX,  8)
#define CYGHWR_HAL_STM32_UART6_TX               stm32_serial_pin_out( CYGHWR_HAL_STM32_UART5_PIN_TX,  8)
#define CYGHWR_HAL_STM32_UART6_CTS              stm32_serial_pin_in( CYGHWR_HAL_STM32_UART5_PIN_CTS,  8)
#define CYGHWR_HAL_STM32_UART6_RTS              stm32_serial_pin_out( CYGHWR_HAL_STM32_UART2_PIN_RTS, 8 )
#endif // CYGHWR_HAL_STM32_UART5_REMAP

#define CYGHWR_HAL_STM32_UART6_CLOCK            CYGHWR_HAL_STM32_CLOCK( APB2, UART6 )

#endif // CYGHWR_HAL_CORTEXM_STM32_FAMILY_HIPERFORMANCE


#ifndef __ASSEMBLER__

__externC void hal_stm32_uart_setbaud( CYG_ADDRESS uart, cyg_uint32 baud );

#endif

#endif // CYGONCE_HAL_VAR_IO_USART_H
//-----------------------------------------------------------------------------
// end of var_io_usart.h
