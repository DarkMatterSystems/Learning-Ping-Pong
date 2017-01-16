
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_PING_ACTIVATE,
    ADM_STATUS_PING_SENDING,
    ADM_STATUS_PING_WAITING,
    ADM_STATUS_PING_TERMINATED
} adm_sta_ping_typ;

typedef enum {
    ADM_STATUS_PONG_ACTIVATE,
    ADM_STATUS_PONG_SENDING,
    ADM_STATUS_PONG_WAITING,
    ADM_STATUS_PONG_TERMINATED
} adm_sta_pong_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_PING_GO,
    ADM_EVENT_PING_WAIT,
    ADM_EVENT_PING_DIE
} adm_evt_ping_typ;

typedef enum {
    ADM_EVENT_PONG_GO,
    ADM_EVENT_PONG_WAIT,
    ADM_EVENT_PONG_DIE
} adm_evt_pong_typ;


/* Entity Type Defines */

/* Ping */

typedef struct adm_ent_ping {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_ping_typ status;
    adm_int_index_typ atb_count;
    adm_int_bound_typ atb_limit;
    struct adm_rel_ping_signals_pong * rel_signals_pong_head;
    struct adm_rel_ping_signals_pong * rel_signals_pong_tail;
    struct adm_ent_ping * back;
    struct adm_ent_ping * next;
} adm_ent_ping_typ;

/* Pong */

typedef struct adm_ent_pong {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_pong_typ status;
    struct adm_rel_pong_replies_ping * rel_replies_ping_head;
    struct adm_rel_pong_replies_ping * rel_replies_ping_tail;
    struct adm_ent_pong * back;
    struct adm_ent_pong * next;
} adm_ent_pong_typ;


/* Relationship Type Defines */

typedef struct adm_rel_ping_signals_pong {
    adm_ent_pong_typ * ent_pong;
    struct adm_rel_ping_signals_pong * back;
    struct adm_rel_ping_signals_pong * next;
} adm_rel_ping_signals_pong_typ;

typedef struct adm_rel_pong_replies_ping {
    adm_ent_ping_typ * ent_ping;
    struct adm_rel_pong_replies_ping * back;
    struct adm_rel_pong_replies_ping * next;
} adm_rel_pong_replies_ping_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_ping {
    adm_evt_ping_typ evente;
    adm_ent_ping_typ * ent_ping;
    adm_error_location_typ error_location;
    struct adm_pool_target_ping * next;
} adm_pool_target_ping_typ;

typedef struct adm_pool_target_pong {
    adm_evt_pong_typ evente;
    adm_ent_pong_typ * ent_pong;
    adm_error_location_typ error_location;
    struct adm_pool_target_pong * next;
} adm_pool_target_pong_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_ping_typ * live_list_head;
    adm_ent_ping_typ * live_list_tail;
    adm_ent_ping_typ * dead_list_head;
    adm_ent_ping_typ * dead_list_tail;
    adm_pool_target_ping_typ * home_pool_head;
    adm_pool_target_ping_typ * home_pool_tail;
    adm_pool_target_ping_typ * away_pool_head;
    adm_pool_target_ping_typ * away_pool_tail;
} adm_entity_system_ping_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_pong_typ * live_list_head;
    adm_ent_pong_typ * live_list_tail;
    adm_ent_pong_typ * dead_list_head;
    adm_ent_pong_typ * dead_list_tail;
    adm_pool_target_pong_typ * home_pool_head;
    adm_pool_target_pong_typ * home_pool_tail;
    adm_pool_target_pong_typ * away_pool_head;
    adm_pool_target_pong_typ * away_pool_tail;
} adm_entity_system_pong_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_ping_typ ent_ping;
    adm_entity_system_pong_typ ent_pong;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */