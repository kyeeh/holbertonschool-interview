#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int left_slider(int *line, size_t size);
int right_slider(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
