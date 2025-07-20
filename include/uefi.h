#pragma once

#include <stdint.h>

typedef enum {
	UEFI_LOADER_DATA = 2,
} uefi_memory_type;

typedef struct {
	uintptr_t value;
} uefi_key;

typedef struct {
	uintptr_t value;
} uefi_status;

typedef struct {
	uintptr_t value;
} uefi_handle;

struct uefi_table_header {
	uint64_t signature;
	uint32_t revision;
	uint32_t size;
	uint32_t checksum;
	uint32_t reserved;
};

typedef uefi_status (*uefi_get_memory_map)(uintptr_t size,
                                           void*     buf,
                                           uefi_key  key,
                                           uintptr_t descriptor_size,
                                           uint32_t  descriptor_version);

typedef uefi_status (*uefi_allocate_pool)(uefi_memory_type type,
                                          uintptr_t        size,
                                          void**           buf);

typedef uefi_status (*uefi_exit_boot_services)(uefi_handle handle,
                                               uefi_key    key);

struct uefi_boot_services {
	struct uefi_table_header header;
	void*                    unimplemented0[4];
	uefi_get_memory_map      get_memory_map;
	uefi_allocate_pool       allocate_pool;
	void*                    unimplemented1[20];
	uefi_exit_boot_services  exit_boot_services;
};

struct uefi_system_table {
	struct uefi_table_header   header;
	uint16_t*                  firmware_vendor;
	uint32_t                   firmware_revision;
	uefi_handle                console_in_handle;
	void*                      console_in;
	uefi_handle                console_out_handle;
	void*                      console_out;
	uefi_handle                console_err_handle;
	void*                      console_err;
	void*                      runtime_services;
	struct uefi_boot_services* boot_services;
	uintptr_t                  vendor_table_count;
	void*                      vendor_tables;
};
