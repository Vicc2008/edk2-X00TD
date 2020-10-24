#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 64

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, MaxMem } DeviceMemoryAddHob;

typedef struct {
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
  DeviceMemoryAddHob           HobOption;
  EFI_MEMORY_TYPE              MemoryType;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Address,	  Length,     ResourceType, Resource Attribute, ARM MMU
       Attribute,                  HobOption, EFI Memory Type */
    /*  DDR  */

    /*  Kernel  */
    {0x80000000, 0x05800000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesCode},
    /*  Reserved  */
    {0x85800000, 0x00800000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  SMEM  */
    {0x86000000, 0x00200000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  PIL Reserved  */
    {0x94800000, 0x0BD00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddMem, EfiReservedMemoryType},
    /*  DXE Heap  */    
    {0x94000000, 0x09400000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},
    /*  Display Reserved  */
    {0x94A00000, 0x02400000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH,
     AddMem, EfiMaxMemoryType},
    /*  FV Region  */
    {0x9F800000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  ABOOT FV  */
    {0x9FA00000, 0x00200000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  UEFI FD  */
    {0x9FC00000, 0x00300000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  SEC Heap  */
    {0x9FF00000, 0x0008C000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},    
    /*  CPU Vectors  */
    {0x9FF8C000, 0x00001000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  MMU PageTables  */
    {0x9FF8D000, 0x00003000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  UEFI Stack  */
    {0x9FF90000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  DBI Dump  */
    {0x9FFD0000, 0x00027000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  Log Buffer  */
    {0x9FFF7000, 0x00008000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  Info Blk  */
    {0x9FFFF000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  LASTLOG  */
    {0xA0000000, 0x00400000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},

    /*  HLOS  */
    {0xA0400000, 0x90000000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},

    /* OTHER MEMORY REGIONS */
    /* IMEM Base */
    {0x14680000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     NoHob, EfiConventionalMemory},
    /* IMEM Cookie Base */
    {0x146BF000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiConventionalMemory},
    /* QDSS_STM */
    {0x16000000, 0x01000000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiConventionalMemory},

    /*  REGISTERS  */
    /* UFS_RUMI */
    {0x00620000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* BOOT_CONFIG */
    {0x00070000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* GCC CLK CTL */
    {0x00100000, 0x000B0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* RPM MSG RAM */
    {0x00778000, 0x00008000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* SECURITY CONTROL */
    {0x00780000, 0x00007000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PRNG_CFG_PRNG */
    {0x00790000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MPM2_SLP_CNTR */
    {0x010A3000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MPM2_TSENS0 */
    {0x010AA000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MPM2_TSENS0_TM */
    {0x010AB000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MPM2_PSHOLD */
    {0x010AC000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MPM2_TSENS1 */
    {0x010AD000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MPM2_TSENS1_TM */
    {0x010AE000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PCIE WRAPPER AHB */
    {0x01C00000, 0x00007000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* UFS UFS REGS */
    {0x01DA0000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* CRYPTO0 CRYPTO */
    {0x01DC0000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TCSR_TCSR_REGS */
    {0x01FC0000, 0x00026000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TLMM CSR */
    {0x03100000, 0x00C00000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PMIC ARB SPMI */
    {0x08000000, 0x02800000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* GPUCC */
    {0x05065000, 0x00009000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* QDSS_QDSS */
    {0x06000000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* HMSS_QLL */
    {0x06400000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* USB30_PRIM */
    {0x0A800000, 0x0011B000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* USB_RUMI */
    {0x0A920000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PERIPH_SS */
    {0x0C000000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MMSS */
    {0x0C800000, 0x00800000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* QTIMER */
    {0x17900000, 0x00030000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APCS_GIC500_GICD */
    {0x17A00000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APCS_GIC500_GICR */
    {0x17B00000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APCS_CC */
    {0x17800000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* QDSS */
    {0x15060000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},

    /* Terminator for MMU*/
    {0},
    /* Terminator for LibMem */
    { 0xFFFFFFFF, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO, 
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, 
     AddDev, EfiMemoryMappedIO}

};

#endif
