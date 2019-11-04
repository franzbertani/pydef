#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define AVG_OVERHEAD 0
#define RESTORE_OVERHEAD 1.0
#define RESTORE(global_var, struct_address, version) global_var = struct_address.version_array[(struct_address.window_begin_index + version) % (struct_address.versions_count + 1)]

