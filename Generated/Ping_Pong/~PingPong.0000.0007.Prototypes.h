
/* System Prototypes Header */

/* Main Prototype */

int main(
    int,
    char * []);


/* System Library */

void * adm_allocate_memory(
    adm_base_integer_typ amount);

void adm_deallocate_memory(
    void * memory);

void adm_open_test_result_file  (void);
void adm_close_test_result_file (void);

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_write_int(
    adm_base_integer_typ number);

void adm_write_bln(
    adm_base_boolean_typ value);

void adm_write_fxd(
    adm_base_fixed_typ number);

void adm_write_flt(
    adm_base_float_typ number);

void adm_write_str(
    adm_base_string_typ * string);

void adm_write_newline(void);

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_convert_string_upper_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_lower_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_sentence_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_capital_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_remove_spaces(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_convert_underlines(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_integrity_check(void);


#if ADM_PROBE

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number);

#endif


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ     error,
    adm_err_file_typ       file,
    adm_err_line_typ       line,
    adm_err_rank_typ       rank,
    adm_err_problem_typ  * source,
    adm_base_integer_typ   identity,
    adm_err_problem_typ  * relation,
    adm_err_problem_typ  * target);


/* Initialisation Prototype */

void adm_initialisation(void);


/* Domain Initialisation Prototypes */

void adm_initialisation_pinger(void);


/* System Scheduler Prototypes */

void adm_scheduler(void);

void adm_scheduler_dom_pinger(void);


/* System Initialisation Scheduler Prototypes */

void adm_scheduler_initialisation(void);

void adm_scheduler_initialisation_pinger(void);


/* System Determine Termination Scheduler Prototypes */

adm_base_boolean_typ adm_scheduler_determine_termination(void);

adm_base_boolean_typ adm_scheduler_determine_termination_dom_pinger(void);


/* Data Access Prototypes */

adm_ent_ping_typ * adm_make_object_ping(
    adm_sta_ping_typ status);

adm_ent_pong_typ * adm_make_object_pong(
    adm_sta_pong_typ status);

void adm_bind_object_ping(
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_pong(
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_ping(
    void * source_object,
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_pong(
    void * source_object,
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_ping_signals_pong(
    adm_ent_ping_typ * ent_source_ping,
    adm_ent_pong_typ * ent_target_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_pong_replies_ping(
    adm_ent_pong_typ * ent_source_pong,
    adm_ent_ping_typ * ent_target_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_ping_signals_pong(
    adm_ent_ping_typ * ent_ping,
    adm_rel_ping_signals_pong_typ * rel_ping_signals_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_pong_replies_ping(
    adm_ent_pong_typ * ent_pong,
    adm_rel_pong_replies_ping_typ * rel_pong_replies_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_ping(
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_pong(
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Event Sender Prototypes */

void adm_send_event_ping_go(
    void * source_object,
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_ping_wait(
    void * source_object,
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_ping_die(
    void * source_object,
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_pong_go(
    void * source_object,
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_pong_wait(
    void * source_object,
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_pong_die(
    void * source_object,
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Dispatcher Prototypes */

void adm_dispatcher_ping         (void);
void adm_dispatch_home_pool_ping (void);

adm_pool_target_ping_typ * adm_find_home_target_event_ping (void);
adm_pool_target_ping_typ * adm_find_away_target_event_ping (void);

void adm_dispatch_state_action_ping(
    adm_pool_target_ping_typ * pool_target_ping);

void adm_dispatcher_pong         (void);
void adm_dispatch_home_pool_pong (void);

adm_pool_target_pong_typ * adm_find_home_target_event_pong (void);
adm_pool_target_pong_typ * adm_find_away_target_event_pong (void);

void adm_dispatch_state_action_pong(
    adm_pool_target_pong_typ * pool_target_pong);


/* State Action Prototypes */

void adm_state_action_ping_sending(
    adm_ent_ping_typ * ent_ping);

void adm_state_action_ping_terminated(
    adm_ent_ping_typ * ent_ping);

void adm_state_action_pong_sending(
    adm_ent_pong_typ * ent_pong);

void adm_state_action_pong_terminated(
    adm_ent_pong_typ * ent_pong);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */