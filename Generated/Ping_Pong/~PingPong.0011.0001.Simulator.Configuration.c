
#include "~PingPong.0000.0000.Header.h"


/* Simulator System Configuration */

/* Domain Map */

adm_sim_domain_typ adm_sim_domain[] = {
    {"Pinger"},
    {SNULL}
};

/* Entity Map */

adm_sim_entity_typ adm_sim_entity[] = {
    {ADM_SIM_INDEX_DOMAIN_PINGER, "Ping", TRUE, adm_sim_display_entity_ping},
    {ADM_SIM_INDEX_DOMAIN_PINGER, "Pong", TRUE, adm_sim_display_entity_pong},
    {null, SNULL, null, NULL}
};

/* Event Map */

adm_sim_event_typ adm_sim_event[] = {
    {
        ADM_SIM_INDEX_DOMAIN_PINGER,
        ADM_SIM_INDEX_ENTITY_PINGER_PING,
        "Go",
        FALSE,
        adm_sim_acquire_identity_event_ping_go
    },
    {
        ADM_SIM_INDEX_DOMAIN_PINGER,
        ADM_SIM_INDEX_ENTITY_PINGER_PING,
        "Wait",
        FALSE,
        adm_sim_acquire_identity_event_ping_wait
    },
    {
        ADM_SIM_INDEX_DOMAIN_PINGER,
        ADM_SIM_INDEX_ENTITY_PINGER_PING,
        "Die",
        FALSE,
        adm_sim_acquire_identity_event_ping_die
    },
    {
        ADM_SIM_INDEX_DOMAIN_PINGER,
        ADM_SIM_INDEX_ENTITY_PINGER_PONG,
        "Go",
        FALSE,
        adm_sim_acquire_identity_event_pong_go
    },
    {
        ADM_SIM_INDEX_DOMAIN_PINGER,
        ADM_SIM_INDEX_ENTITY_PINGER_PONG,
        "Wait",
        FALSE,
        adm_sim_acquire_identity_event_pong_wait
    },
    {
        ADM_SIM_INDEX_DOMAIN_PINGER,
        ADM_SIM_INDEX_ENTITY_PINGER_PONG,
        "Die",
        FALSE,
        adm_sim_acquire_identity_event_pong_die
    },
    {
        null,
        null,
        SNULL,
        null,
        NULL
    }
};

/* Identifier Map */

adm_sim_identifier_typ adm_sim_identifier[] = {
    {
        null,
        null,
        null,
        SNULL,
        NULL
    }
};


/* Find Event Name From Event Index */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    index = 0;

    event_not_found = TRUE;

    while (event_not_found) {

        if (adm_sim_event[index].entity == entity_index) {

            index += entity_event_index;

            event_not_found = FALSE;

        } else {

            ++index;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    return (adm_sim_event[index].name);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */