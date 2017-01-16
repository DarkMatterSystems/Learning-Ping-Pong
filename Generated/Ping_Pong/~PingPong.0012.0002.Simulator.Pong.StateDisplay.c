
#include "~PingPong.0000.0000.Header.h"


/* Simulator Pong Display State */

void adm_sim_display_state_pong_sending(
    adm_pool_target_pong_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pong_sending");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:103:42) - Pong[");
        printf("%d", (pool_target->ent_pong)->identity);
        printf("] ");
        printf("Sending");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PINGER_PONG, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pong[(pool_target->ent_pong)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pong_sending");
    #endif
}

void adm_sim_display_state_pong_waiting(
    adm_pool_target_pong_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pong_waiting");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:120:42) - Pong[");
        printf("%d", (pool_target->ent_pong)->identity);
        printf("] ");
        printf("Waiting");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PINGER_PONG, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pong[(pool_target->ent_pong)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pong_waiting");
    #endif
}

void adm_sim_display_state_pong_terminated(
    adm_pool_target_pong_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pong_terminated");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:127:43) - Pong[");
        printf("%d", (pool_target->ent_pong)->identity);
        printf("] ");
        printf("Terminated");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_PINGER_PONG, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_pong[(pool_target->ent_pong)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_pong_terminated");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */