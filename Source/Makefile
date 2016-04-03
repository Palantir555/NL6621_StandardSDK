################################################################################
# SDK Folders:
SDK_SRCDIR=.
LIB_DIR   =$(SDK_SRCDIR)/Lib
SYS_DIR   =$(SDK_SRCDIR)/Sys
BSP_DIR   =$(SDK_SRCDIR)/BSP
LWIP_DIR  =$(SDK_SRCDIR)/LwIP
BOOT_DIR  =$(SDK_SRCDIR)/BOOT
UCOS_DIR  =$(SDK_SRCDIR)/uCOS-II
PORTS_DIR =$(SDK_SRCDIR)/Ports/Cortex-M3
SDK_INCDIR=$(SDK_SRCDIR)/Include
APP_DIR   =$(SDK_SRCDIR)/App

LWIP_SRCDIR =$(LWIP_DIR)/src
LWIP_PORTDIR=$(LWIP_DIR)/port

################################################################################
# Toolchain:
TOOLCHAIN_ROOT?=/Users/palantir/Tech/Toolchains/gcc-arm-none-eabi-5_2-2015q4
TOOL_PREFIX=$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-

CC=$(TOOL_PREFIX)gcc
AS=$(TOOL_PREFIX)as
LD=$(TOOL_PREFIX)ld
AR=$(TOOL_PREFIX)ar

################################################################################
# Output folders:
OUTPUT_DIR=./output
OUTPUT_OBJDIR=$(OUTPUT_DIR)/objdir

################################################################################
# Include folders:
LWIP_INCDIRS:=                      \
    $(LWIP_DIR)/src/include         \
    $(LWIP_DIR)/src/include/lwip    \
    $(LWIP_DIR)/src/include/ipv4    \
    $(LWIP_DIR)/src/include/ipv6    \
    $(LWIP_DIR)/port/include/netif  \
    $(LWIP_DIR)/port/include

INCDIRS:=           \
    $(SDK_INCDIR)   \
    $(SYS_DIR)      \
    $(UCOS_DIR)     \
    $(BSP_DIR)      \
    $(PORTS_DIR)    \
    $(TOOL_INCDIRS) \
    $(GCC_LIB)      \
    $(LWIP_INCDIRS)

################################################################################
# Object folders (containing pre-compiled libraries and objects for the linker):
TOOL_LIBDIR:=                                               \
    $(TOOLCHAIN_ROOT)/arm-none-eabi/lib/armv7-m             \
    $(TOOLCHAIN_ROOT)/lib/gcc/arm-none-eabi/5.2.1/armv7-m

SDK_LIBDIR:=     \
    $(LIB_DIR)

ALL_LIBDIRS:= $(TOOL_LIBDIR) $(SDK_LIBDIR)

################################################################################
# Headers:
SDK_HEADERS:=                    \
    $(SDK_INCDIR)/airkiss.h      \
    $(SDK_INCDIR)/app_cfg.h      \
    $(SDK_INCDIR)/global.h       \
    $(SDK_INCDIR)/includes.h     \
    $(SDK_INCDIR)/param.h        \
    $(SDK_INCDIR)/rom_hook_tbl.h \
    $(SDK_INCDIR)/task_util.h    \
    $(SDK_INCDIR)/types_def.h    \
    $(SDK_INCDIR)/util.h      

UCOS_HEADERS:=                  \
    $(UCOS_DIR)/os_app_cfg.h    \
    $(UCOS_DIR)/os_cfg.h        \
    $(UCOS_DIR)/ucos_ii.h 

BSP_HEADERS:=                   \
    $(BSP_DIR)/I2C.h            \
    $(BSP_DIR)/I2S.h            \
    $(BSP_DIR)/board.h          \
    $(BSP_DIR)/bsp.h            \
    $(BSP_DIR)/dma.h            \
    $(BSP_DIR)/flash.h          \
    $(BSP_DIR)/gpio.h           \
    $(BSP_DIR)/mpu.h            \
    $(BSP_DIR)/nvic.h           \
    $(BSP_DIR)/qspi.h           \
    $(BSP_DIR)/reg.h            \
    $(BSP_DIR)/sdio.h           \
    $(BSP_DIR)/spi.h            \
    $(BSP_DIR)/timer.h          \
    $(BSP_DIR)/uart.h           \
    $(BSP_DIR)/wdg.h

PORTS_HEADERS:=                 \
    $(PORTS_DIR)/os_cpu.h       \
    $(PORTS_DIR)/os_dmem.h

APP_HEADERS:=                           \
    $(APP_DIR)/DhcpServer/dhcp_server.h \
    $(APP_DIR)/DnsServer/dns_server.h

#ALL_HEADERS :=$(SDK_HEADERS) $(UCOS_HEADERS) $(BSP_HEADERS) $(PORTS_HEADERS) \
#              $(APP_SOURCES)

################################################################################
# Sources:
SYS_SOURCES:=                   \
    $(SYS_DIR)/app_main.c       \
    $(SYS_DIR)/main.c           \
    $(SYS_DIR)/param.c          \
    $(SYS_DIR)/rom_hook_tbl.c   \
    $(SYS_DIR)/sys_mgmt.c       \
    $(SYS_DIR)/util.c

UCOS_SOURCES:=                  \
    $(UCOS_DIR)/os_core.c       \
    $(UCOS_DIR)/os_dbg.c        \
    $(UCOS_DIR)/os_flag.c       \
    $(UCOS_DIR)/os_mbox.c       \
    $(UCOS_DIR)/os_mem.c        \
    $(UCOS_DIR)/os_mutex.c      \
    $(UCOS_DIR)/os_q.c          \
    $(UCOS_DIR)/os_sem.c        \
    $(UCOS_DIR)/os_task.c       \
    $(UCOS_DIR)/os_time.c       \
    $(UCOS_DIR)/os_tmr.c 

BSP_SOURCES:=                   \
    $(BSP_DIR)/cortexm3_macro.s \
    $(BSP_DIR)/I2C.c            \
    $(BSP_DIR)/I2S.c            \
    $(BSP_DIR)/bsp.c            \
    $(BSP_DIR)/dma.c            \
    $(BSP_DIR)/flash.c          \
    $(BSP_DIR)/gpio.c           \
    $(BSP_DIR)/mpu.c            \
    $(BSP_DIR)/nvic.c           \
    $(BSP_DIR)/printf.c         \
    $(BSP_DIR)/qspi.c           \
    $(BSP_DIR)/sdio.c           \
    $(BSP_DIR)/spi.c            \
    $(BSP_DIR)/timer.c          \
    $(BSP_DIR)/uart.c           \
    $(BSP_DIR)/wdg.c            \
    $(BSP_DIR)/cortexM3_it.c

LWIP_SOURCES:=                      \
    $(LWIP_PORTDIR)/lwIP.c          \
    $(LWIP_PORTDIR)/sys_arch.c      \
    $(LWIP_SRCDIR)/core/def.c       \
    $(LWIP_SRCDIR)/core/dhcp.c      \
    $(LWIP_SRCDIR)/core/dns.c       \
    $(LWIP_SRCDIR)/core/lwip_init.c \
    $(LWIP_SRCDIR)/core/mem.c       \
    $(LWIP_SRCDIR)/core/memp.c      \
    $(LWIP_SRCDIR)/core/netif.c     \
    $(LWIP_SRCDIR)/core/pbuf.c      \
    $(LWIP_SRCDIR)/core/raw.c       \
    $(LWIP_SRCDIR)/core/stats.c     \
    $(LWIP_SRCDIR)/core/sys.c       \
    $(LWIP_SRCDIR)/core/tcp.c       \
    $(LWIP_SRCDIR)/core/tcp_in.c    \
    $(LWIP_SRCDIR)/core/tcp_out.c   \
    $(LWIP_SRCDIR)/core/timers.c    \
    $(LWIP_SRCDIR)/core/udp.c

PORTS_SOURCES:=               \
    $(PORTS_DIR)/os_cpu_c.c   \
    $(PORTS_DIR)/os_dmem.c

PORTS_ASM_SOURCES:=           \
    $(PORTS_DIR)/cpu_a.asm    \
    $(PORTS_DIR)/os_cpu_a.asm

BOOT_SOURCES:=                     \
    $(BOOT_DIR)/CortexM3_startup.s \

APP_SOURCES:=                           \
    $(APP_DIR)/DhcpServer/dhcp_server.c \
    $(APP_DIR)/DnsServer/dns_server.c

#ALL_SOURCES:= $(SDK_SOURCES) $(UCOS_SOURCES) $(BSP_SOURCES) $(PORTS_SOURCES) \
#              $(BOOT_SOURCES) $(LWIP_SOURCES) $(PORTS_ASM_SOURCES) \
#              $(APP_SOURCES)

################################################################################
# Compiler and linker options (flags and defines):
CC_FLAGS:= -mthumb -mcpu=cortex-m3 -fno-builtin -std=gnu99 -Os -flto -nostdlib  \
           -fdata-sections --specs=nosys.specs -msoft-float -mfix-cortex-m3-ldrd
AS_FLAGS:= 
LD_FLAGS:= --gc-sections -nostartfiles -Map=GCC_TODO_map?.map -T TODO_linkerscript.ld
#GCC_TODO: Does -nostartfiles mean we don't need to compile the startup assembly file?
#LDSCRIPTS=-L. -L$(BASE)/ldscripts -T gcc.ld #From the arm-none-eabi samples

SDK_DEFINES:=               \
    GCC                     \
    LWIP_TIMEVAL_PRIVATE=0  \
    USE_CORTEX_M3           \
    DEBUG_ON=0

TOOL_DEFINES:=          \
    TOOLCHAIN_GCC_ARM   \
    __CORTEX_M3         \
    TOOLCHAIN_GCC

ALL_DEFINES_RAW:=$(SDK_DEFINES) $(TOOL_DEFINES)

################################################################################
# Prepare arguments for GCC. Prepend -L, -I, -D, etc.:
CC_LIBS     := $(patsubst %, -L%, $(ALL_LIBDIRS))
CC_INCLUDES := $(patsubst %, -I%, $(INCDIRS))
CC_DEFINES  := $(patsubst %, -D%, $(ALL_DEFINES_RAW))
AS_DEFINES  :=

################################################################################
# Build list of targets (The .o files invoked by the File Creation Rules):
#patsubst(from, to, text): Replaces occurences of `from` in `text` with `to`
APP_OBJ      :=$(patsubst $(APP_DIR)%.c,     $(OUTPUT_OBJDIR)%.o, $(APP_SOURCES))
SYS_OBJ      :=$(patsubst $(SYS_DIR)%.c,     $(OUTPUT_OBJDIR)%.o, $(SYS_SOURCES))
BSP_OBJ      :=$(patsubst $(BSP_DIR)%.c,     $(OUTPUT_OBJDIR)%.o, $(BSP_SOURCES))
BSP_ASM_OBJ  :=$(patsubst $(BSP_DIR)%.s,     $(OUTPUT_OBJDIR)%.o, $(BSP_SOURCES))
UCOS_OBJ     :=$(patsubst $(UCOS_DIR)%.c,    $(OUTPUT_OBJDIR)%.o, $(UCOS_SOURCES))
BOOT_OBJ     :=$(patsubst $(BOOT_DIR)%.s,    $(OUTPUT_OBJDIR)%.o, $(BOOT_SOURCES))
LWIP_OBJ     :=$(patsubst $(LWIP_DIR)%.c,    $(OUTPUT_OBJDIR)%.o, $(LWIP_SOURCES))
PORTS_OBJ    :=$(patsubst $(PORTS_DIR)%.c,   $(OUTPUT_OBJDIR)%.o, $(PORTS_SOURCES))
PORTS_ASM_OBJ:=$(patsubst $(PORTS_DIR)%.asm, $(OUTPUT_OBJDIR)%.o, $(PORTS_ASM_SOURCES))

################################################################################
# OS Commands:
RMRF  := rm -rf
MKDIR := mkdir -p

################################################################################
# Make Targets - The first target in the Makefile will be used as the default:
all: $(SYS_OBJ) $(BOOT_OBJ) $(PORTS_OBJ) $(UCOS_OBJ) $(LWIP_OBJ) $(BSP_OBJ) $(APP_OBJ)
#$(PORTS_ASM_OBJ)

print:
	@echo $(PORTS_OBJ) $(SYS_OBJ) $(BSP_OBJ) $(UCOS_OBJ)

clean:
	@echo "$(RMRF) $(OUTPUT_DIR)"
	@$(RMRF) $(OUTPUT_DIR)

.PHONY: all clean print

################################################################################
# File Creation Rules:
$(OUTPUT_OBJDIR)%.o: $(PORTS_DIR)%.c
	@echo "(CC) $<"
	@echo "$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@"
	@$(MKDIR) $(dir $@)
	@$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(APP_DIR)%.c
	@echo "(CC) $<"
	@echo "$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@"
	@$(MKDIR) $(dir $@)
	@$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(UCOS_DIR)%.c
	@echo "(CC) $<"
	@echo "$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@"
	@$(MKDIR) $(dir $@)
	@$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(LWIP_DIR)%.c
	@echo "(CC) $<"
	@echo "$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@"
	@$(MKDIR) $(dir $@)
	@$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(BSP_DIR)%.c
	@echo "(CC) $<"
	@echo "$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@"
	@$(MKDIR) $(dir $@)
	@$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(SYS_DIR)%.c
	@echo "(CC) $<"
	@echo "$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@"
	@$(MKDIR) $(dir $@)
	@$(CC) -c $(CC_INCLUDES) $(CC_DEFINES) $(CC_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(BSP_DIR)%.s
	#@echo "(CC) $<"
	#@echo "$(AS) -c $(CC_INCLUDES) $(AS_DEFINES) $(AS_FLAGS) $< -o $@"
	#@$(MKDIR) $(dir $@)
	#@$(AS) -c $(CC_INCLUDES) $(AS_DEFINES) $(AS_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(BOOT_DIR)%.s
	#@echo "(CC) $<"
	#@echo "$(AS) -c $(CC_INCLUDES) $(AS_DEFINES) $(AS_FLAGS) $< -o $@"
	#@$(MKDIR) $(dir $@)
	#@$(AS) -c $(CC_INCLUDES) $(AS_DEFINES) $(AS_FLAGS) $< -o $@

$(OUTPUT_OBJDIR)%.o: $(PORTS_DIR)%.asm
	#@echo "(CC) $<"
	#@echo "$(AS) -c $(CC_INCLUDES) $(AS_DEFINES) $(AS_FLAGS) $< -o $@"
	#@$(MKDIR) $(dir $@)
	#@$(AS) -c $(CC_INCLUDES) $(AS_DEFINES) $(AS_FLAGS) $< -o $@
