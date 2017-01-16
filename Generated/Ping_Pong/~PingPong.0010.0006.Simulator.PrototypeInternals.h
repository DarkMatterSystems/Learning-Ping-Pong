
/* Simulator System Prototype Internals Header */

/* Display Entity Prototypes */

void adm_sim_display_entity_ping(
    void);

void adm_sim_display_entity_pong(
    void);


/* Acquire Identity Event Prototypes */

void adm_sim_acquire_identity_event_ping_go(
    void);

void adm_sim_acquire_identity_event_ping_wait(
    void);

void adm_sim_acquire_identity_event_ping_die(
    void);

void adm_sim_acquire_identity_event_pong_go(
    void);

void adm_sim_acquire_identity_event_pong_wait(
    void);

void adm_sim_acquire_identity_event_pong_die(
    void);


/* Acquire Identifier Event Prototypes */


/* Display Event Prototypes */

void adm_sim_display_event_ping_go(
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_ping_wait(
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_ping_die(
    adm_ent_ping_typ * ent_ping,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_pong_go(
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_pong_wait(
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_pong_die(
    adm_ent_pong_typ * ent_pong,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Display State Prototypes */

void adm_sim_display_state_ping_sending(
    adm_pool_target_ping_typ * pool_target);

void adm_sim_display_state_ping_waiting(
    adm_pool_target_ping_typ * pool_target);

void adm_sim_display_state_ping_terminated(
    adm_pool_target_ping_typ * pool_target);

void adm_sim_display_state_pong_sending(
    adm_pool_target_pong_typ * pool_target);

void adm_sim_display_state_pong_waiting(
    adm_pool_target_pong_typ * pool_target);

void adm_sim_display_state_pong_terminated(
    adm_pool_target_pong_typ * pool_target);


/* Find Event Name Prototype */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */