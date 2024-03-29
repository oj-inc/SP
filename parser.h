
#ifndef SP_PARSER_H
#define SP_PARSER_H
#include "command.h"

/**
 * parser accepts the string from game, and creates a command (which could be invalid) to be sent to
 * commandValidator
 */

/**
 *
 * @param input string from user
 * @return command type == invalid iff:
 * command does not use filepath and a non integer value was given to integer commands
 * input length > 256 chars
 * command name not valid
 *
 *
 * exits on memory failure. all else is given to command validator
 *
 */
void parse_input(char *input, Command *out);
#endif
