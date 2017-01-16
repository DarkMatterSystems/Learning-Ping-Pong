
/* Simulator System Entity Type Defines Header */

/* Domain Enumerations */

typedef enum {
    ADM_SIM_INDEX_DOMAIN_PINGER
} adm_sim_index_domain_typ;

/* Entity Enumerations */

typedef enum {
    ADM_SIM_INDEX_ENTITY_PINGER_PING,
    ADM_SIM_INDEX_ENTITY_PINGER_PONG
} adm_sim_index_entity_typ;

/* Event Enumerations */

typedef enum {
    ADM_SIM_INDEX_EVENT_PINGER_PING_GO,
    ADM_SIM_INDEX_EVENT_PINGER_PING_WAIT,
    ADM_SIM_INDEX_EVENT_PINGER_PING_DIE,
    ADM_SIM_INDEX_EVENT_PINGER_PONG_GO,
    ADM_SIM_INDEX_EVENT_PINGER_PONG_WAIT,
    ADM_SIM_INDEX_EVENT_PINGER_PONG_DIE
} adm_sim_index_event_typ;

/* Entity Display Widths */

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_count;
    adm_base_integer_typ atb_limit;
} adm_sim_width_ping_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_pong_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */