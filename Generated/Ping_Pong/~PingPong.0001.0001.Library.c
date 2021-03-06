
#include "~PingPong.0000.0000.Header.h"


/* System Library */

/* Allocate Memory */

void * adm_allocate_memory(
    adm_base_integer_typ amount)
{
    void * memory;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_allocate_memory");
    #endif

    memory = malloc(amount);

    if (memory == NULL) {

        adm_error_report(
            ADM_ERROR_OUT_OF_MEMORY,
            0, 0, 0, NULL, null, NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_allocate_memory");
    #endif

    return (memory);
}


/* Dellocate Memory */

void adm_deallocate_memory(
    void * memory)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_deallocate_memory");
    #endif

    free(memory);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_deallocate_memory");
    #endif
}


/* Open Stream File */

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    errno_t file_error;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_open_stream_file");
    #endif

    if (adm_stream.streaming) {

        adm_close_stream_file(
            error_file,
            error_line,
            error_rank);
    }

    file_error = fopen_s(&adm_stream.channel, adm_stream.pathname, "w");

    if (file_error) {

        adm_error_report(
            ADM_ERROR_CREATE_STREAM_FILE_FAILED,
            error_file, error_line, error_rank,
            adm_stream.pathname,
            null, NULL, NULL);

    } else {

        adm_stream.active    = TRUE;
        adm_stream.streaming = TRUE;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_open_stream_file");
    #endif
}


/* Close Stream File */

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_close_stream_file");
    #endif

    if (adm_stream.streaming) {

        if (fclose(adm_stream.channel) == EOF) {

            adm_error_report(
                ADM_ERROR_CLOSE_STREAM_FILE_FAILED,
                error_file, error_line, error_rank,
                adm_stream.pathname,
                null, NULL, NULL);

        } else {

            adm_stream.streaming = FALSE;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_close_stream_file");
    #endif
}


/* Write Integer */

void adm_write_int(
    adm_base_integer_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_int");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%d", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%d", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_int");
    #endif
}


/* Write Boolean */

void adm_write_bln(
    adm_base_boolean_typ value)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_bln");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%s", adm_indent.tab, adm_boolean[value]) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%s", adm_indent.tab, adm_boolean[value]);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_bln");
    #endif
}


/* Write Fixed */

void adm_write_fxd(
    adm_base_fixed_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_fxd");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%f", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%f", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_fxd");
    #endif
}


/* Write Float */

void adm_write_flt(
    adm_base_float_typ number)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_flt");
    #endif

    if (adm_stream.active) {

        if (adm_stream.streaming) {

            if (fprintf(adm_stream.channel, "%s%E", adm_indent.tab, number) < 0) {

                adm_error_report(
                    ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                    0, 0, 0,
                    adm_stream.pathname,
                    null, NULL, NULL);
            }

        } else {

            printf("%s%E", adm_indent.tab, number);
        }

        INIT_STR(adm_indent.tab);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_flt");
    #endif
}


/* Write String */

void adm_write_str(
    adm_base_string_typ * string)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_str");
    #endif

    if (adm_stream.active) {

        if (!NULL_STR(string)) {

            if (adm_stream.streaming) {

                if (fprintf(adm_stream.channel, "%s%s", adm_indent.tab, string) < 0) {

                    adm_error_report(
                        ADM_ERROR_FILE_STREAM_WRITE_FAILED,
                        0, 0, 0,
                        adm_stream.pathname,
                        null, NULL, NULL);
                }

            } else {

                printf("%s%s", adm_indent.tab, string);
            }

            INIT_STR(adm_indent.tab);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_str");
    #endif
}


/* Write Newline */

void adm_write_newline(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_write_newline");
    #endif

    if (adm_stream.active) {

        INIT_STR(adm_indent.tab);

        adm_write_str(NEWLINE);

        memset(adm_indent.tab, ' ', adm_indent.width);

        adm_indent.tab[adm_indent.width] = '\0';
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_write_newline");
    #endif
}


/* Set Template Tab In */

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_in");
    #endif

    if (adm_stream.active) {

        adm_indent.width += ADM_INDENT_TAB_TEMPLATE_INDENT_SIZE;

        if (adm_indent.width > ADM_INDENT_TEMPLATE_MAXIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_TEMPLATE_MAXIMUM_TAB_INDENT_EXCEEDED,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_in");
    #endif
}


/* Set Template Tab Out */

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_out");
    #endif

    if (adm_stream.active) {

        adm_indent.width -= ADM_INDENT_TAB_TEMPLATE_INDENT_SIZE;

        if (adm_indent.width < ADM_INDENT_TEMPLATE_MINIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_TEMPLATE_MINIMUM_TAB_INDENT_OFFPAGE,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_template_tab_out");
    #endif
}


/* Set Display Tab In */

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_in");
    #endif

    if (adm_stream.active) {

        adm_indent.width += ADM_INDENT_TAB_DISPLAY_INDENT_SIZE;

        if (adm_indent.width > ADM_INDENT_DISPLAY_MAXIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_DISPLAY_MAXIMUM_TAB_INDENT_EXCEEDED,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_in");
    #endif
}


/* Set Display Tab Out */

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_out");
    #endif

    if (adm_stream.active) {

        adm_indent.width -= ADM_INDENT_TAB_DISPLAY_INDENT_SIZE;

        if (adm_indent.width < ADM_INDENT_DISPLAY_MINIMUM_INDENT) {

            adm_error_report(
                ADM_ERROR_DISPLAY_MINIMUM_TAB_INDENT_OFFPAGE,
                error_file, error_line, error_rank,
                NULL, null, NULL, NULL);
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_display_tab_out");
    #endif
}


/* String - Convert Upper Case */

void adm_convert_string_upper_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_upper_case");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        target_string[index] = toupper(source_string[index]);

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_upper_case");
    #endif
}


/* String - Convert Lower Case */

void adm_convert_string_lower_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_lower_case");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        target_string[index] = tolower(source_string[index]);

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_lower_case");
    #endif
}


/* String - Convert Sentence Case */

void adm_convert_string_sentence_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_sentence_case");
    #endif

    adm_convert_string_lower_case(
        source_string,
        target_string);

    target_string[0] = toupper(target_string[0]);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_sentence_case");
    #endif
}


/* Convert Capital Case */

void adm_convert_string_capital_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ capitalise;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_capital_case");
    #endif

    capitalise = TRUE;

    index = 0;

    while (source_string[index] != '\0') {

        if (
            source_string[index] == ' ' ||
            source_string[index] == '_') {

            capitalise = TRUE;

            target_string[index] = source_string[index];

        } else {

            if (capitalise) {

                capitalise = FALSE;

                target_string[index] = toupper(source_string[index]);

            } else {

                target_string[index] = tolower(source_string[index]);
            }
        }

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_capital_case");
    #endif
}


/* String - Convert Remove Spaces */

void adm_convert_string_remove_spaces(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ source_index;
    adm_base_integer_typ target_index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_remove_spaces");
    #endif

    source_index = 0;
    target_index = 0;

    while (source_string[source_index] != '\0') {

        if (source_string[source_index] != ' ') {

            target_string[target_index] = source_string[source_index];

            ++target_index;
        }

        ++source_index;
    }

    target_string[target_index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_remove_spaces");
    #endif
}


/* String - Convert Underlines */

void adm_convert_string_convert_underlines(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string)
{
    adm_base_integer_typ index;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_convert_underlines");
    #endif

    index = 0;

    while (source_string[index] != '\0') {

        if (source_string[index] == '_') {

            target_string[index] = ' ';

        } else {

            target_string[index] = source_string[index];
        }

        ++index;
    }

    target_string[index] = '\0';

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_convert_string_convert_underlines");
    #endif
}


/* Integrity Check */

void adm_integrity_check(
    void)
{
    adm_ent_ping_typ * ent_ping;
    adm_ent_pong_typ * ent_pong;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_LIBRARY, "adm_integrity_check");
    #endif

    ent_ping = adm_entity_system.ent_ping.live_list_head;

    while (ent_ping != NULL) {

        if (ent_ping->rel_signals_pong_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 26, 29,
                "Ping",
                ent_ping->identity,
                "Signals",
                "Pong");
        }

        if (
            ent_ping->rel_signals_pong_head != 
            ent_ping->rel_signals_pong_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 26, 29,
                "Ping",
                ent_ping->identity,
                "Signals",
                "Pong");
        }

        ent_ping = ent_ping->next;
    }

    ent_pong = adm_entity_system.ent_pong.live_list_head;

    while (ent_pong != NULL) {

        if (ent_pong->rel_replies_ping_head == NULL) {

            adm_error_report(
                ADM_ERROR_CONDITIONALITY_INTEGRITY_VIOLATION,
                1, 94, 29,
                "Pong",
                ent_pong->identity,
                "Replies",
                "Ping");
        }

        if (
            ent_pong->rel_replies_ping_head != 
            ent_pong->rel_replies_ping_tail) {

            adm_error_report(
                ADM_ERROR_MULTIPLICITY_INTEGRITY_VIOLATION,
                1, 94, 29,
                "Pong",
                ent_pong->identity,
                "Replies",
                "Ping");
        }

        ent_pong = ent_pong->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_LIBRARY, "adm_integrity_check");
    #endif
}


#if ADM_PROBE

/* Probe Enter */

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name)
{
    adm_base_string_typ probe_message [ADM_PROBE_MESSAGE_SIZE];

    if (
        !adm_probe_display.none &&
        (adm_probe_display.all                                                        ||
        (adm_probe_display.main_program   && group == ADM_PROBE_GROUP_MAIN_PROGRAM)   ||
        (adm_probe_display.initialisation && group == ADM_PROBE_GROUP_INITIALISATION) ||
        (adm_probe_display.scheduler      && group == ADM_PROBE_GROUP_SCHEDULER)      ||
        (adm_probe_display.dispatcher     && group == ADM_PROBE_GROUP_DISPATCHER)     ||
        (adm_probe_display.state_action   && group == ADM_PROBE_GROUP_STATE_ACTION)   ||
        (adm_probe_display.data_access    && group == ADM_PROBE_GROUP_DATA_ACCESS)    ||
        (adm_probe_display.event_sender   && group == ADM_PROBE_GROUP_EVENT_SENDER)   ||
        (adm_probe_display.enumeration    && group == ADM_PROBE_GROUP_ENUMERATION)    ||
        (adm_probe_display.library        && group == ADM_PROBE_GROUP_LIBRARY)        ||
        (adm_probe_display.identifier     && group == ADM_PROBE_GROUP_IDENTIFIER)     ||
        (adm_probe_display.error          && group == ADM_PROBE_GROUP_ERROR)          ||
        (adm_probe_display.simulator      && group == ADM_PROBE_GROUP_SIMULATOR))) {

        INIT_STR(probe_message);

        adm_add_spaces(probe_message, adm_probe_display.level);

        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, "ENTER: ");
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, procedure_name);
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, NEWLINE);

        printf(probe_message);

        fprintf(adm_file_channel, probe_message);

        adm_probe_display.level += ADM_PROBE_INDENT;
    }
}


/* Probe Leave */

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name)
{
    adm_base_string_typ probe_message [ADM_PROBE_MESSAGE_SIZE];

    if (
        !adm_probe_display.none &&
        (adm_probe_display.all                                                        ||
        (adm_probe_display.main_program   && group == ADM_PROBE_GROUP_MAIN_PROGRAM)   ||
        (adm_probe_display.initialisation && group == ADM_PROBE_GROUP_INITIALISATION) ||
        (adm_probe_display.scheduler      && group == ADM_PROBE_GROUP_SCHEDULER)      ||
        (adm_probe_display.dispatcher     && group == ADM_PROBE_GROUP_DISPATCHER)     ||
        (adm_probe_display.state_action   && group == ADM_PROBE_GROUP_STATE_ACTION)   ||
        (adm_probe_display.data_access    && group == ADM_PROBE_GROUP_DATA_ACCESS)    ||
        (adm_probe_display.event_sender   && group == ADM_PROBE_GROUP_EVENT_SENDER)   ||
        (adm_probe_display.enumeration    && group == ADM_PROBE_GROUP_ENUMERATION)    ||
        (adm_probe_display.library        && group == ADM_PROBE_GROUP_LIBRARY)        ||
        (adm_probe_display.identifier     && group == ADM_PROBE_GROUP_IDENTIFIER)     ||
        (adm_probe_display.error          && group == ADM_PROBE_GROUP_ERROR)          ||
        (adm_probe_display.simulator      && group == ADM_PROBE_GROUP_SIMULATOR))) {

        adm_probe_display.level -= ADM_PROBE_INDENT;

        INIT_STR(probe_message);

        adm_add_spaces(probe_message, adm_probe_display.level);

        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, "LEAVE: ");
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, procedure_name);
        strcat_s(probe_message, ADM_PROBE_MESSAGE_SIZE, NEWLINE);

        printf(probe_message);

        fprintf(adm_file_channel, probe_message);
    }
}


/* Add Spaces */

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number)
{
    adm_base_integer_typ index;

    for (index=0; index<space_number; ++index) {

        strcat_s(space_string, ADM_PROBE_MESSAGE_SIZE, " ");
    }
}

#endif

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */