#include <stdlib.h> /* for malloc, free */

/**
 * _realloc - reallocates a block of memory.
 * 
 * @ptr: pointer to the previously allocated block of memory.
 * @old_size: size in bytes of the previously allocated block of memory.
 * @new_size: size in bytes of the new block of memory.
 *
 * Return: On success, a pointer to the newly allocated block of memory.
 *         On failure, NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
  void *new_ptr;

  /* If new_size is 0, free memory and return NULL */
  if (new_size == 0)
  {
    free(ptr);
    return NULL;
  }

  /* If ptr is NULL, allocate new memory */
  if (ptr == NULL)
  {
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
      return NULL;
    return new_ptr;
  }

  /* If old_size and new_size are the same, return ptr */
  if (old_size == new_size)
    return ptr;

  /* Allocate new memory and copy contents from old memory */
  new_ptr = malloc(new_size);
  if (new_ptr == NULL)
    return NULL;

  unsigned int i;
  char *src = ptr;
  char *dest = new_ptr;

  for (i = 0; i < old_size && i < new_size; i++)
    dest[i] = src[i];

  /* Free the old memory */
  free(ptr);

  return new_ptr;
}
