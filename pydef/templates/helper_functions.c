#define RESTORE(global_var, struct_address, version) global_var = struct_address.version_array[(struct_address.window_begin_index + version) % (struct_address.versions_count + 1)]

