
#include "~PingPong.0000.0000.Header.h"


/* Simulator Ping Acquire Identity Event */

void adm_sim_acquire_identity_event_ping_go(
    void)
{
    adm_ent_ping_typ * ent_ping;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_ping_go");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_ping = adm_entity_system.ent_ping.live_list_head;

    while (
        entity_not_found &&
        ent_ping != NULL) {

        if (ent_ping->identity == identity) {

            adm_send_event_ping_go(
                NULL,
                ent_ping,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_ping = ent_ping->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_ping_go");
    #endif
}

void adm_sim_acquire_identity_event_ping_wait(
    void)
{
    adm_ent_ping_typ * ent_ping;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_ping_wait");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_ping = adm_entity_system.ent_ping.live_list_head;

    while (
        entity_not_found &&
        ent_ping != NULL) {

        if (ent_ping->identity == identity) {

            adm_send_event_ping_wait(
                NULL,
                ent_ping,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_ping = ent_ping->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_ping_wait");
    #endif
}

void adm_sim_acquire_identity_event_ping_die(
    void)
{
    adm_ent_ping_typ * ent_ping;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_ping_die");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_ping = adm_entity_system.ent_ping.live_list_head;

    while (
        entity_not_found &&
        ent_ping != NULL) {

        if (ent_ping->identity == identity) {

            adm_send_event_ping_die(
                NULL,
                ent_ping,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_ping = ent_ping->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_ping_die");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */