
#include "~PingPong.0000.0000.Header.h"


/* Simulator Ping Display State */

void adm_sim_display_state_ping_sending(
    adm_pool_target_ping_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_ping_sending");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:36:42) - Ping[");
        printf("%d", (pool_target->ent_ping)->identity);
        printf("] ");
        printf("Sending");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PINGER_PING, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_ping[(pool_target->ent_ping)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_ping_sending");
    #endif
}

void adm_sim_display_state_ping_waiting(
    adm_pool_target_ping_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_ping_waiting");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:69:42) - Ping[");
        printf("%d", (pool_target->ent_ping)->identity);
        printf("] ");
        printf("Waiting");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PINGER_PING, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_ping[(pool_target->ent_ping)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_ping_waiting");
    #endif
}

void adm_sim_display_state_ping_terminated(
    adm_pool_target_ping_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_ping_terminated");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:76:43) - Ping[");
        printf("%d", (pool_target->ent_ping)->identity);
        printf("] ");
        printf("Terminated");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PINGER_PING, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_ping[(pool_target->ent_ping)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_ping_terminated");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */