#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <sys/types.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void cp(char *file_from, char *file_to);
void cls(int file);
#endif
