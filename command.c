/**

 Created by lenovo on ${DTE}
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "command.h"


char* commands[] = {"invalid","solve","edit","mark_errors","print_board","set", "validate",
                    "guess","generate","undo","redo","save","hint","guess","num_solutions","autofill","reset","exit"};

Command *alloc_command(char *name, int *parameters, char *filepath) {
    Command *command = (Command *) calloc(1, sizeof(Command));
    if (command == NULL) {
        error("command", "alloc_command", 1);
        return NULL;
    }

    if (name == NULL) {
        command->type = INVALID;
        error("command", "alloc_command", 5);
        return command;
    }
    set_type(command, name);
    command->int_parameters = parameters;
    command->string_parameters = filepath;
    return command;
}

int *get_parameters(Command *command) {
    return command->int_parameters;
}

/**
 *
 * @param command != NULL
 * @param name != null
 */
void set_type(Command *command, char *name) {
    if (strcmp(name, "solve") == 0 || strcmp(name, "solve\n") == 0) {
        command->type = SOLVE;
        return;
    }
    if ((strcmp(name, "edit") == 0) ||(strcmp(name, "edit\n") == 0) ) {
        command->type = EDIT;
        return;
    }
    if (strcmp(name, "mark_errors") == 0 || strcmp(name, "mark_errors\n") == 0) {
        command->type = MARK_ERRORS;
        return;
    }
    if (strcmp(name, "print_board") == 0 || strcmp(name, "print_board\n") == 0) {
        command->type = PRINT_BOARD;
        return;
    }
    if (strcmp(name, "set") == 0 || strcmp(name, "set\n") == 0) {
        command->type = SET;
        return;
    }
    if (strcmp(name, "validate") == 0 || strcmp(name, "validate\n")==0) {
        command->type = VALIDATE;
        return;
    }
    if (strcmp(name, "guess") == 0 || strcmp(name, "guess\n") == 0) {
        command->type = GUESS;
        return;
    }
    if (strcmp(name, "generate") == 0 || strcmp(name, "generate\n") == 0) {
        command->type = GENERATE;
        return;
    }
    if (strcmp(name, "undo") == 0 || strcmp(name, "undo\n") == 0) {
        command->type = UNDO;
        return;
    }
    if (strcmp(name, "redo") == 0 || strcmp(name, "redo\n") == 0) {
        command->type = REDO;
        return;
    }
    if (strcmp(name, "save") == 0 || strcmp(name, "save\n") == 0) {
        command->type = SAVE;
        return;
    }
    if (strcmp(name, "hint") == 0 || strcmp(name, "hint\n") == 0) {
        command->type = HINT;
        return;
    }
    if (strcmp(name, "guess_hint") == 0 || strcmp(name, "guess_hint\n") == 0) {
        command->type = GUESS_HINT;
        return;
    }
    if (strcmp(name, "num_solutions") == 0 || strcmp(name, "num_solutions\n") == 0) {
        command->type = NUM_SOLUTIONS;
        return;
    }
    if (strcmp(name, "autofill") == 0 || strcmp(name, "autofill\n") == 0) {
        command->type = AUTOFILL;
        return;
    }
    if (strcmp(name, "reset") == 0 || strcmp(name, "reset\n") == 0) {
        command->type = RESET;
        return;
    }
    if (strcmp(name, "exit") == 0 || strcmp(name, "exit\n") == 0) {
        command->type = EXIT;
        return;
    } else {
        command->type = INVALID;
    }


}

command_type get_type(Command *command) {
    return command->type;
}

char *get_filepath(Command *command) {
    return command->string_parameters;
}

void set_filepath(Command *command, char *filepath) {
    command->string_parameters = filepath;
}

void set_parameter(Command *command, int *parameters) {
    command->int_parameters = parameters;

}

int get_num_parameters(Command *command) {
    return command->num_parameters;
}

void set_num_parameters(Command *command, int num_parameters) {
    command->num_parameters = num_parameters;

}




void free_command(Command *command) {
    if(command != NULL) {
        free(command->int_parameters);
        free(command->string_parameters);
    }
    free(command);
}

float get_threshold(Command *command) {
    return command->threshold;
}

char * command_name(Command *command) {
    return commands[(int)command->type];
}

void set_threshold(Command *commnad, float threshold) {
    commnad->threshold = threshold;
}
void print_input_parameters(Command *pCommand) {
    int i;
    if (get_parameters(pCommand) == NULL) {
        return;
    }
    for (i = 0; i < pCommand->num_parameters; i++) {
        printf("paramter %d: %d ", i, pCommand->int_parameters[i]);
    }

}