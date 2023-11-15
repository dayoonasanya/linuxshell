#include "shell.h"

/**
 * free_resources - frees all allocated memory passed
 * @command: pointer to command buffer
 * @runtime: pointer to malloc'ed runtime_t struct
 */
void free_resources(runtime_t *runtime)
{

	if (runtime->error_msg)
		free(runtime->error_msg);

	free(runtime);

}
