/*
 *  (C) 2009 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef __DARSHAN_H
#define __DARSHAN_H

#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <mpi.h>
#include "darshan-log-format.h"

#define DARSHAN_MPI_CALL(func) func

typedef uint64_t darshan_file_id;

struct darshan_module_funcs
{
    void (*prepare_for_shutdown)(void);
    void (*get_output_data)(void **, int);
};

void darshan_core_register_module(
    char *name,
    struct darshan_module_funcs *funcs,
    int *runtime_mem_limit);

void darshan_core_lookup_id(
    void *name,
    int len,
    int printable_flag,
    darshan_file_id *id);

double darshan_core_wtime(void);

char* darshan_clean_file_path(const char* path);

double darshan_wtime(void);

#endif /* __DARSHAN_H */
