set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
cmake_minimum_required(VERSION 3.20)

# 工具链设置
set(TOOLPATH C:/tools/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-)

if(WIN32)
    MESSAGE(STATUS "Now is windows!")
    set(CMAKE_C_COMPILER ${TOOLPATH}gcc.exe)
    set(CMAKE_CXX_COMPILER ${TOOLPATH}g++.exe)
    set(CMAKE_ASM_COMPILER ${TOOLPATH}gcc.exe)
    set(CMAKE_AR ${TOOLPATH}ar.exe)
    set(CMAKE_OBJCOPY ${TOOLPATH}objcopy.exe)
    set(CMAKE_OBJDUMP ${TOOLPATH}objdump.exe)
    set(SIZE ${TOOLPATH}size.exe)
elseif(UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS!")
    set(CMAKE_C_COMPILER ${TOOLPATH}gcc)
    set(CMAKE_CXX_COMPILER ${TOOLPATH}g++)
    set(CMAKE_ASM_COMPILER ${TOOLPATH}gcc)
    set(CMAKE_AR ${TOOLPATH}ar)
    set(CMAKE_OBJCOPY ${TOOLPATH}objcopy)
    set(CMAKE_OBJDUMP ${TOOLPATH}objdump)
    set(SIZE ${TOOLPATH}size)
else()
    MESSAGE(STATUS "Unsupported system!")
endif()

# 项目设置
project(air001-cmake C CXX ASM)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

# 头文件路径
include_directories(
    "luatos-soc-air001/Libraries/CMSIS/Device/AIR001xx/Include"
    "luatos-soc-air001/Libraries/CMSIS/Include"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Inc"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Inc/Legacy"
    "app"
)

# 宏定义
# add_definitions(-DDEBUG=1)

# 源码文件
file(GLOB_RECURSE SOURCES
    "luatos-soc-air001/Libraries/CMSIS/Device/AIR001xx/Source/gcc/startup_air001xx.s"
    "luatos-soc-air001/Libraries/CMSIS/Device/AIR001xx/Source/*.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/*.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_adc.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_adc_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_can.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_cec.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_comp.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_cortex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_crc.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_crc_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_dac.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_dac_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_dma.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_exti.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_flash.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_gpio.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_i2c.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_i2c_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_i2s.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_irda.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_iwdg.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_led.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_lptim.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_msp_template.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_pcd.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_pcd_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_pwr.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_pwr_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_rcc.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_rcc_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_rtc.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_rtc_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_smartcard.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_smartcard_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_smbus.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_spi.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_spi_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_tim.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_timebase_rtc_alarm_template.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_timebase_rtc_wakeup_template.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_timebase_tim_template.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_tim_ex.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_tsc.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_uart.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_usart.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_hal_wwdg.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_adc.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_comp.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_crc.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_crs.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_dac.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_dma.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_exti.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_gpio.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_i2c.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_led.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_lptim.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_pwr.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_rcc.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_rtc.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_spi.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_tim.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_usart.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_usb.c"
    # "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/air001xx_ll_utils.c"
    "luatos-soc-air001/Libraries/AIR001xx_HAL_Driver/Src/Legacy/*.c"
    "app/*.c"
)

# 链接参数
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/air001.ld")

# define CPU OPTIONS
set(CPU_OPTIONS -mthumb -mcpu=cortex-m0)

# optimizations (-O0 -O1 -O2 -O3 -Os -Ofast -Og -flto)
set(CMAKE_C_FLAGS_DEBUG "-Og -g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_C_FLAGS_RELEASE "-Os -flto")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -flto")

add_link_options(-T ${LINKER_SCRIPT})

# 编译参数 一般不用改
add_compile_options(
    ${CPU_OPTIONS}
    $<$<COMPILE_LANGUAGE:C>:-std=c99>
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
    $<$<COMPILE_LANGUAGE:CXX>:-fms-extensions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
    -fstrict-volatile-bitfields
    -ffunction-sections
    # -fno-threadsafe-statics

    -Werror
    # -Wall
    # -Wextra
    # -Wcast-align
    # -Wconversion
    # -Wsign-conversion
    # -Wold-style-cast
    # -Wshadow
    # -Wlogical-op
    # -Wsuggest-override
    # -Wsuggest-final-types
    # -Wsuggest-final-methods
    -pedantic
)

# 编译可执行文件
add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

# 链接静态库
# target_link_libraries(${PROJECT_NAME}.elf printfloat)

# 输出hex和bin
set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)
set(LST_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.lst)
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
    COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
    COMMAND ${CMAKE_OBJDUMP} --all-headers --demangle --disassemble $<TARGET_FILE:${PROJECT_NAME}.elf> > ${LST_FILE}
    COMMAND ${SIZE} --format=berkeley $<TARGET_FILE:${PROJECT_NAME}.elf>
)
